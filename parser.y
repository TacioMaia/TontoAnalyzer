%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Declarações externas
extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char *s);

// --- Estruturas para a Tabela de Síntese ---
vector<string> packages;
string current_package = "Global"; // Pacote padrão se nenhum for definido
map<string, vector<string>> classes_by_package; // Mapa: Pacote -> Lista de Classes
vector<string> external_relations;
int count_datatypes = 0;
int count_enums = 0;
int count_gensets = 0;

// Função auxiliar para registrar classes
void register_class(string class_name) {
    classes_by_package[current_package].push_back(class_name);
}

// Função auxiliar para registrar relações externas
void register_external_relation(string relation_info) {
    external_relations.push_back(relation_info);
}

%}

/* --- Definição da União (Tipos de dados que os tokens podem carregar) --- */
%union {
    char* sval; /* Para nomes (strings) */
    int ival;   /* Para números (inteiros) */
}

/* --- Tokens (Vindos do Lexer) --- */
/* Palavras-chave de estrutura */
%token T_PACKAGE T_IMPORT T_GENSET T_DISJOINT T_COMPLETE T_GENERAL T_SPECIFICS T_WHERE
%token T_FUNCTIONAL_COMPLEXES T_DATATYPE T_ENUM T_RELATION

/* Estereótipos de Classe */
%token T_KIND T_SUBKIND T_ROLE T_PHASE T_CATEGORY T_MIXIN T_ROLEMIXIN T_PHASEMIXIN 
%token T_HISTORICALROLE T_HISTORICALROLEMIXIN T_COLLECTIVE T_QUANTITY T_QUALITY 
%token T_MODE T_INTRINSICMODE T_EXTRINSICMODE 
%token T_EVENT T_SITUATION T_PROCESS

/* Estereótipos de Relação */
%token T_MATERIAL T_DERIVATION T_COMPARATIVE T_MEDIATION T_CHARACTERIZATION
%token T_SUBCOLLECTIONOF T_SUBQUALITYOF T_INSTANTIATION T_EXTERNALDEPENDENCE
%token T_COMPONENTOF T_MEMBEROF T_TERMINATION T_PARTICIPATIONAL T_PARTICIPATION
%token T_HISTORICALDEPENDENCE T_CREATION T_MANIFESTATION T_BRINGSABOUT T_TRIGGERS
%token T_COMPOSITION T_AGGREGATION T_INHERENCE T_VALUE T_FORMAL T_CONSTITUTION

/* Tipos Nativos */
%token T_NUMBER_TYPE T_STRING_TYPE T_BOOLEAN_TYPE T_DATE_TYPE T_TIME_TYPE T_DATETIME_TYPE

/* Símbolos e Literais */
%token T_LBRACE T_RBRACE T_LPAREN T_RPAREN T_LBRACK T_RBRACK
%token T_DOTDOT T_DIAMOND_ARROW T_ARROW_DIAMOND T_ASTERISK T_AT T_DOT T_COLON T_COMMA
%token <sval> T_CLASS_NAME T_RELATION_NAME T_INSTANCE_NAME T_NEW_DATA_TYPE
%token <ival> T_NUMBER_LITERAL

/* Definição de precedência para resolver conflitos simples */
%left T_COMMA

%%

/* --- Gramática (Regras de Produção) --- */

program:
    declarations
    ;

declarations:
    declaration
    | declarations declaration
    ;

declaration:
    package_decl
    | element
    ;

/* 1. Declaração de Pacotes */
package_decl:
    T_PACKAGE T_CLASS_NAME { 
        current_package = $2; 
        packages.push_back($2);
    } opt_body
    ;

opt_body:
    T_LBRACE element_list T_RBRACE
    | /* vazio - permite pacote sem corpo explícito imediato */
    ;

element_list:
    element
    | element_list element
    ;

element:
    class_decl
    | relation_decl
    | datatype_decl
    | enum_decl
    | genset_decl
    | simple_type_decl
    ;

/* 2. Declaração de Classes */
class_decl:
    class_stereotype T_CLASS_NAME { register_class($2); } opt_specialization opt_class_body
    ;

class_stereotype:
    T_KIND | T_SUBKIND | T_ROLE | T_PHASE | T_CATEGORY | T_MIXIN | T_ROLEMIXIN | T_PHASEMIXIN
    | T_EVENT | T_SITUATION | T_PROCESS | T_COLLECTIVE | T_QUANTITY | T_QUALITY | T_MODE 
    | T_INTRINSICMODE | T_EXTRINSICMODE | T_HISTORICALROLE | T_HISTORICALROLEMIXIN
    ;

opt_specialization:
    /* vazio */
    | T_RELATION_NAME T_CLASS_NAME /* Ex: specializes Person */
    ;

opt_class_body:
    /* vazio */
    | T_LBRACE class_members T_RBRACE
    ;

class_members:
    /* vazio */
    | class_members attribute
    | class_members internal_relation
    ;

/* Atributos: name: type */
attribute:
    T_RELATION_NAME T_COLON type_specifier opt_constraints
    | T_RELATION_NAME T_CLASS_NAME /* Ex: eyeColor EyeColor (sintaxe alternativa) */
    | T_RELATION_NAME T_COLON T_CLASS_NAME opt_constraints
    ;

type_specifier:
    T_NUMBER_TYPE | T_STRING_TYPE | T_BOOLEAN_TYPE | T_DATE_TYPE | T_TIME_TYPE | T_DATETIME_TYPE 
    | T_NEW_DATA_TYPE
    ;

opt_constraints:
    /* vazio */
    | T_LBRACE T_RELATION_NAME T_RBRACE /* Ex: {const} */
    ;

/* 3. Tipos de Dados */
datatype_decl:
    T_DATATYPE T_CLASS_NAME opt_class_body { count_datatypes++; }
    ;

simple_type_decl:
    T_NEW_DATA_TYPE { count_datatypes++; } /* Ex: CarDataType solto no arquivo */
    ;

/* 4. Classes Enumeradas */
enum_decl:
    T_ENUM T_CLASS_NAME T_LBRACE enum_list T_RBRACE { count_enums++; register_class($2); }
    ;

enum_list:
    T_CLASS_NAME
    | enum_list T_COMMA T_CLASS_NAME
    ;

/* 5. Generalizações (Gensets) */
genset_decl:
    genset_modifiers T_GENSET T_CLASS_NAME T_WHERE genset_details { count_gensets++; }
    | T_GENSET T_CLASS_NAME T_LBRACE T_GENERAL T_CLASS_NAME T_SPECIFICS class_list T_RBRACE { count_gensets++; }
    ;

genset_modifiers:
    /* vazio */
    | T_DISJOINT
    | T_COMPLETE
    | T_DISJOINT T_COMPLETE
    | T_COMPLETE T_DISJOINT
    ;

genset_details:
    class_list T_RELATION_NAME T_CLASS_NAME /* Ex: Child, Adult specializes Person */
    ;

class_list:
    T_CLASS_NAME
    | class_list T_COMMA T_CLASS_NAME
    ;

/* 6. Relações */

/* Relação Interna (dentro de uma classe) */
internal_relation:
    relation_meta relation_connector cardinality T_CLASS_NAME 
    /* Ex: @componentOf [1] <>-- [1..*] Department (simplificado) */
    ;

relation_meta:
    T_AT relation_stereotype
    | /* vazio */
    ;

relation_stereotype:
    T_MEDIATION | T_COMPONENTOF | T_MEMBEROF | T_CHARACTERIZATION | T_FORMAL | T_MATERIAL | T_DERIVATION | T_RELATION
    /* Adicione outros se necessário */
    ;

relation_connector:
    cardinality T_DIAMOND_ARROW cardinality /* [1] <>-- [1..*] */
    | T_ARROW_DIAMOND /* --<> */
    | T_DOTDOT /* -- */
    | T_RELATION_NAME /* hasMember */
    ;

/* Relação Externa (fora de classe) */
relation_decl:
    T_AT relation_stereotype T_RELATION T_CLASS_NAME relation_body_opt {
        register_external_relation($4);
    }
    | T_RELATION_NAME T_CLASS_NAME T_LBRACE internal_relation T_RBRACE /* Relator style */
    ;

relation_body_opt:
    /* Aceita estruturas variadas de relação externa */
    cardinality cardinality T_CLASS_NAME /* [1..*] [1] Employee */
    | T_LBRACE class_members T_RBRACE /* Corpo completo estilo relator */
    | /* vazio */
    ;

/* Cardinalidade: [1], [0..1], [1..*] */
cardinality:
    T_LBRACK T_NUMBER_LITERAL T_RBRACK
    | T_LBRACK T_NUMBER_LITERAL T_DOTDOT T_NUMBER_LITERAL T_RBRACK
    | T_LBRACK T_NUMBER_LITERAL T_DOTDOT T_ASTERISK T_RBRACK
    | /* vazio (opcional) */
    ;

%%

/* --- Código C++ Auxiliar --- */

void yyerror(const char *s) {
    cerr << "ERRO SINTÁTICO: " << s << " na linha " << yylineno << " próximo ao token '" << yytext << "'" << endl;
}

// Função chamada pelo main para imprimir a tabela
void print_synthesis_table() {
    cout << "\n======================================================\n";
    cout << "              TABELA DE SÍNTESE (SINTÁTICA)           \n";
    cout << "======================================================\n";
    
    cout << "PACOTES ENCONTRADOS: " << packages.size() << "\n";
    for(const auto& pkg : packages) {
        cout << "  > " << pkg << "\n";
    }
    
    cout << "\nCLASSES POR PACOTE:\n";
    if (classes_by_package.empty()) {
        cout << "  (Nenhuma classe encontrada)\n";
    } else {
        for(auto const& [pkg, classes] : classes_by_package) {
            cout << "  Pacote '" << pkg << "': " << classes.size() << " classes\n";
            for(const auto& cls : classes) {
                cout << "    - " << cls << "\n";
            }
        }
    }

    cout << "\nOUTROS CONSTRUTOS:\n";
    cout << "  - Relações Externas Declaradas: " << external_relations.size() << "\n";
    for(const auto& rel : external_relations) cout << "    * " << rel << "\n";
    
    cout << "  - Declarações de Tipos (Datatypes): " << count_datatypes << "\n";
    cout << "  - Classes Enumeradas (Enums): " << count_enums << "\n";
    cout << "  - Conjuntos de Generalização (Gensets): " << count_gensets << "\n";
    cout << "======================================================\n";
}