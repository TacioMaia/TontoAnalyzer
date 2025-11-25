%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Declarações externas do Flex
extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char *s);

// --- Estruturas para a Tabela de Síntese ---
vector<string> packages;
string current_package = "Global"; 
map<string, vector<string>> classes_by_package; 
vector<string> external_relations;
int count_datatypes = 0;
int count_enums = 0;
int count_gensets = 0;

// Funções auxiliares de registro
void register_class(string class_name) {
    classes_by_package[current_package].push_back(class_name);
}

void register_external_relation(string relation_name) {
    external_relations.push_back(relation_name);
}
%}

/* --- Tipos de Valor dos Tokens --- */
%union {
    char* sval; 
    int ival;   
}

/* --- Tokens (Vindos do Lexer) --- */
/* Keywords Estruturais */
%token T_PACKAGE T_IMPORT T_GENSET T_DISJOINT T_COMPLETE T_GENERAL T_SPECIFICS T_WHERE T_OF
%token T_DATATYPE T_ENUM T_RELATION

/* Categorias do 'of' */
%token T_FUNCTIONAL_COMPLEXES T_RELATORS T_INTRINSIC_MODES T_EXTRINSIC_MODES
%token T_QUALITIES T_MODES T_EVENTS T_SITUATIONS

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

/* Precedência */
%left T_COMMA

%%

/* --- Regras da Gramática --- */

program:
    declarations
    ;

declarations:
    declaration
    | declarations declaration
    ;

declaration:
    package_decl
    | import_decl
    | element
    ;

import_decl:
    T_IMPORT T_CLASS_NAME
    | T_IMPORT T_RELATION_NAME 
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
    | /* vazio - permite declaração de pacote sem chaves (estilo header) */
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
    class_stereotype T_CLASS_NAME opt_classification { register_class($2); } opt_specialization opt_class_body
    ;

class_stereotype:
    T_KIND | T_SUBKIND | T_ROLE | T_PHASE | T_CATEGORY | T_MIXIN | T_ROLEMIXIN | T_PHASEMIXIN
    | T_EVENT | T_SITUATION | T_PROCESS | T_COLLECTIVE | T_QUANTITY | T_QUALITY | T_MODE 
    | T_INTRINSICMODE | T_EXTRINSICMODE | T_HISTORICALROLE | T_HISTORICALROLEMIXIN
    ;

/* Suporte a "subkind ... of functional-complexes" */
opt_classification:
    T_OF T_FUNCTIONAL_COMPLEXES
    | T_OF T_RELATORS
    | T_OF T_INTRINSIC_MODES
    | T_OF T_EXTRINSIC_MODES
    | T_OF T_QUALITIES
    | T_OF T_MODES
    | T_OF T_EVENTS
    | T_OF T_SITUATIONS
    | /* vazio */
    ;

opt_specialization:
    /* vazio */
    | T_RELATION_NAME T_CLASS_NAME /* Ex: specializes Person */
    | T_RELATION_NAME T_CLASS_NAME T_COMMA T_CLASS_NAME /* Ex: specializes A, B */
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

/* Atributos - Permite usar palavras reservadas como 'number' como nome */
attribute:
    attribute_name T_COLON type_specifier opt_constraints
    | attribute_name T_COLON T_CLASS_NAME opt_constraints
    | attribute_name T_CLASS_NAME
    ;

attribute_name:
    T_RELATION_NAME
    | T_NUMBER_TYPE  
    | T_STRING_TYPE  
    | T_DATE_TYPE    
    | T_TIME_TYPE
    | T_DATETIME_TYPE
    | T_BOOLEAN_TYPE
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
    T_NEW_DATA_TYPE { count_datatypes++; }
    ;

/* 4. Classes Enumeradas */
enum_decl:
    T_ENUM T_CLASS_NAME T_LBRACE enum_list T_RBRACE { count_enums++; register_class($2); }
    ;

enum_list:
    T_CLASS_NAME
    | enum_list T_COMMA T_CLASS_NAME
    | /* vazio */
    ;

/* 5. Generalizações (Gensets) */
/* Permite modificadores (disjoint, complete) em ambos os formatos de genset */
genset_decl:
    genset_modifiers T_GENSET T_CLASS_NAME T_WHERE genset_details { count_gensets++; }
    | genset_modifiers T_GENSET T_CLASS_NAME T_LBRACE T_GENERAL T_CLASS_NAME T_SPECIFICS class_list T_RBRACE { count_gensets++; }
    ;

genset_modifiers:
    /* vazio */
    | T_DISJOINT
    | T_COMPLETE
    | T_DISJOINT T_COMPLETE
    | T_COMPLETE T_DISJOINT
    ;

genset_details:
    class_list T_RELATION_NAME T_CLASS_NAME
    ;

class_list:
    T_CLASS_NAME
    | class_list T_COMMA T_CLASS_NAME
    ;

/* 6. Relações */

/* Relação Externa (Top-level) */
relation_decl:
    /* Relação explícita (@mediation relation ...) */
    T_AT relation_stereotype T_RELATION T_CLASS_NAME relation_body_opt {
        register_external_relation($4);
    }
    /* Relator (com ou sem corpo {}) */
    | T_RELATION T_CLASS_NAME opt_relator_body {
        register_external_relation($2);
    }
    /* Relação implícita por nome (hasMember ...) */
    | T_RELATION_NAME T_CLASS_NAME T_LBRACE internal_relation_list T_RBRACE 
    ;

opt_relator_body:
    T_LBRACE internal_relation_list T_RBRACE
    | /* vazio - suporte para relator declarado sem chaves */
    ;

/* Corpo de relação externa */
relation_body_opt:
    /* Suporte a [1..*] -- [1] ... (com conector) */
    cardinality T_DOTDOT cardinality T_CLASS_NAME
    /* Suporte a [1..*] [1] ... (sem conector) */
    | cardinality cardinality T_CLASS_NAME
    | T_LBRACE class_members T_RBRACE 
    | /* vazio */
    ;

internal_relation_list:
    internal_relation
    | internal_relation_list internal_relation
    ;

/* Relação Interna */
internal_relation:
    /* Padrão 1: @stereotype [1] <>-- [1..*] Class */
    relation_meta cardinality relation_arrow cardinality T_CLASS_NAME
    /* Padrão 2: @stereotype -- name -- [1] Class */
    | relation_meta T_DOTDOT T_RELATION_NAME T_DOTDOT cardinality T_CLASS_NAME
    /* Padrão 3: apenas nome */
    | T_RELATION_NAME
    ;

relation_meta:
    T_AT relation_stereotype
    | /* vazio */
    ;

relation_stereotype:
    T_MEDIATION | T_COMPONENTOF | T_MEMBEROF | T_CHARACTERIZATION | T_FORMAL | T_MATERIAL 
    | T_DERIVATION | T_RELATION | T_BRINGSABOUT | T_TRIGGERS | T_PARTICIPATION | T_PARTICIPATIONAL
    | T_HISTORICALDEPENDENCE | T_CREATION | T_MANIFESTATION | T_TERMINATION | T_INSTANTIATION
    ;

relation_arrow:
    T_DIAMOND_ARROW | T_ARROW_DIAMOND | T_DOTDOT | T_RELATION_NAME
    ;

cardinality:
    T_LBRACK T_NUMBER_LITERAL T_RBRACK
    | T_LBRACK T_NUMBER_LITERAL T_DOTDOT T_NUMBER_LITERAL T_RBRACK
    | T_LBRACK T_NUMBER_LITERAL T_DOTDOT T_ASTERISK T_RBRACK
    | /* vazio */
    ;

%%

/* --- Funções Auxiliares --- */

void yyerror(const char *s) {
    cerr << "ERRO SINTÁTICO: " << s << " na linha " << yylineno << " próximo ao token '" << yytext << "'" << endl;
}

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
    cout << "  - Relações Externas: " << external_relations.size() << "\n";
    for(const auto& rel : external_relations) cout << "    * " << rel << "\n";
    
    cout << "  - Declarações de Tipos (Datatypes): " << count_datatypes << "\n";
    cout << "  - Classes Enumeradas (Enums): " << count_enums << "\n";
    cout << "  - Conjuntos de Generalização (Gensets): " << count_gensets << "\n";
    cout << "======================================================\n";
}