#include "parser.h"
#include "tokens.h"
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;


extern int column;

void Parser::Start()
{
    initializeTokenNames();  // Preenche o mapa dos nomes

    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        if(lookahead == T_INVALID){
            continue;
        }

        // Armazena o token para a visão analitica. 
        int tokenLength = static_cast<int>(scanner.YYLeng());
        int startColumn = column - tokenLength;
        allTokens.push_back({lookahead, scanner.YYText(), scanner.lineno(), startColumn});

        // trata o token recebido do analisador léxico
        switch(lookahead)
        {
        
            case T_PACKAGE: reservedWordCount++ ; keywordCount++; break;
            case T_IMPORT:  reservedWordCount++ ; keywordCount++; break;
            case T_GENSET:  reservedWordCount++ ; keywordCount++; break;
            case T_DISJOINT:  reservedWordCount++ ; keywordCount++; break;
            case T_COMPLETE:  reservedWordCount++ ; keywordCount++; break;
            case T_GENERAL:  reservedWordCount++ ; keywordCount++; break;
            case T_SPECIFICS:  reservedWordCount++ ; keywordCount++; break;
            case T_WHERE:  reservedWordCount++ ; keywordCount++; break;
            case T_FUNCTIONAL_COMPLEXES:  reservedWordCount++ ; keywordCount++; break;

            case T_EVENT:  keywordCount++; break;
            case T_SITUATION:  keywordCount++; break;
            case T_PROCESS:  keywordCount++; break;
            case T_CATEGORY:  keywordCount++; break;
            case T_MIXIN:  keywordCount++; break;
            case T_PHASEMIXIN:  keywordCount++; break;
            case T_ROLEMIXIN:  keywordCount++; break;
            case T_HISTORICALROLEMIXIN:  keywordCount++; break;
            case T_KIND:  keywordCount++; break;
            case T_COLLECTIVE:  keywordCount++; break;
            case T_QUANTITY:  keywordCount++; break;
            case T_QUALITY:  keywordCount++; break;
            case T_MODE:  keywordCount++; break;
            case T_INTRINSICMODE:  keywordCount++; break;
            case T_EXTRINSICMODE:  keywordCount++; break;
            case T_SUBKIND:  keywordCount++; break;
            case T_PHASE:  keywordCount++; break;
            case T_ROLE:  keywordCount++; break;
            case T_HISTORICALROLE:  keywordCount++; break;

            case T_MATERIAL:  keywordCount++; break;
            case T_DERIVATION:  keywordCount++; break;
            case T_COMPARATIVE:  keywordCount++; break;
            case T_MEDIATION:  keywordCount++; break;
            case T_CHARACTERIZATION:  keywordCount++; break;
            case T_SUBCOLLECTIONOF:  keywordCount++; break;
            case T_SUBQUALITYOF:  keywordCount++; break;
            case T_INSTANTIATION:  keywordCount++; break;
            case T_EXTERNALDEPENDENCE:  keywordCount++; break;
            case T_COMPONENTOF:  keywordCount++; break;
            case T_MEMBEROF:  keywordCount++; break;
            case T_TERMINATION:  keywordCount++; break;
            case T_PARTICIPATIONAL:  keywordCount++; break;
            case T_PARTICIPATION:  keywordCount++; break;
            case T_HISTORICALDEPENDENCE:  keywordCount++; break;
            case T_CREATION:  keywordCount++; break;
            case T_MANIFESTATION:  keywordCount++; break;
            case T_BRINGSABOUT:  keywordCount++; break;
            case T_TRIGGERS:  keywordCount++; break;
            case T_COMPOSITION:  keywordCount++; break;
            case T_AGGREGATION:  keywordCount++; break;
            case T_INHERENCE:  keywordCount++; break;
            case T_VALUE:  keywordCount++; break;
            case T_FORMAL:  keywordCount++; break;
            case T_CONSTITUTION:  keywordCount++; break;

            case T_NUMBER_TYPE:  break;
            case T_STRING_TYPE:  break;
            case T_BOOLEAN_TYPE:  break;
            case T_DATE_TYPE:  break;
            case T_TIME_TYPE:  break;
            case T_DATETIME_TYPE:  break;

            case T_ORDERED:  keywordCount++ ; metaAttributeCount++; break;
            case T_CONST:  keywordCount++ ; metaAttributeCount++; break;
            case T_DERIVED:  keywordCount++ ; metaAttributeCount++; break;
            case T_SUBSETS:  keywordCount++ ; metaAttributeCount++; break;
            case T_REDEFINES:  keywordCount++ ; metaAttributeCount++; break;

            case T_LBRACE:  break;
            case T_RBRACE:  break;
            case T_LPAREN:  break;
            case T_RPAREN:  break;
            case T_LBRACK:  break;
            case T_RBRACK:  break;
            case T_DOTDOT:  break;
            case T_DIAMOND_ARROW:  break;
            case T_ARROW_DIAMOND:  break;

            case T_ASTERISK:  break;
            case T_AT:  break;
            case T_DOT:  break;

            case T_CLASS_NAME:  classCount++; break;
            case T_RELATION_NAME:  relationCount++; break;
            case T_INSTANCE_NAME:  instanceCount++; break;
            case T_NEW_DATA_TYPE:  break;
            case T_NUMBER:  break;
            case T_STRING:  break;

            case T_INVALID:  break;
            case T_EOF:  break;
        }
    }
    printAnalyticalView();
    printSynthesisTable();  
}

// Imprime a visão analítica de todos os tokens válidos encontrados
void Parser::printAnalyticalView() {
    cout << "\n--- Visão Analítica de Tokens ---\n"; 
    cout << left 
              << setw(8) << "LINHA" 
              << setw(8) << "COLUNA" 
              << setw(25) << "TIPO" 
              << "TEXTO\n";
    cout << "--------------------------------------------------------------\n"; 

    for (const auto& token : allTokens) {
        string typeName = "DESCONHECIDO";
        // Usa o mapa para obter o nome do tipo do token (se existir)
        auto it = tokenNames.find(token.type);
        if (it != tokenNames.end()) {
            typeName = it->second;
        } else {
             typeName = "TIPO_" + to_string(token.type); 
        }

        cout << left 
                  << setw(8) << token.line 
                  << setw(8) << token.column_start 
                  << setw(25) << typeName 
                  << token.text << "\n";
    }
     cout << "--------------------------------------------------------------\n"; 
}

// Imprime a tabela de síntese com as contagens
void Parser::printSynthesisTable() {
    cout << "\n--- Tabela de Síntese ---\n"; 
    cout << left << setw(25) << "Elemento" << "Quantidade\n";
    cout << "---------------------------------------\n";
    cout << left << setw(25) << "Classes" << classCount << "\n";
    cout << left << setw(25) << "Relações" << relationCount << "\n";
    cout << left << setw(25) << "Palavras-chave (Total)" << keywordCount << "\n"; 
    cout << left << setw(25) << "Indivíduos (Instâncias)" << instanceCount << "\n";
    cout << left << setw(25) << "Palavras Reservadas" << reservedWordCount << "\n";
    cout << left << setw(25) << "Meta-atributos" << metaAttributeCount << "\n"; 
    cout << "---------------------------------------\n"; 
}

// Inicializa o mapa de nomes de tokens
void Parser::initializeTokenNames() {
    tokenNames[T_PACKAGE] = "PACKAGE"; tokenNames[T_IMPORT] = "IMPORT";
    tokenNames[T_GENSET] = "GENSET"; tokenNames[T_DISJOINT] = "DISJOINT";
    tokenNames[T_COMPLETE] = "COMPLETE"; tokenNames[T_GENERAL] = "GENERAL";
    tokenNames[T_SPECIFICS] = "SPECIFICS"; tokenNames[T_WHERE] = "WHERE";
    tokenNames[T_FUNCTIONAL_COMPLEXES] = "FUNC_COMPLEXES";

    tokenNames[T_EVENT] = "ST_EVENT"; tokenNames[T_SITUATION] = "ST_SITUATION";
    tokenNames[T_PROCESS] = "ST_PROCESS"; tokenNames[T_CATEGORY] = "ST_CATEGORY";
    tokenNames[T_MIXIN] = "ST_MIXIN"; tokenNames[T_PHASEMIXIN] = "ST_PHASEMIXIN";
    tokenNames[T_ROLEMIXIN] = "ST_ROLEMIXIN"; tokenNames[T_HISTORICALROLEMIXIN] = "ST_HISTROLEMIXIN";
    tokenNames[T_KIND] = "ST_KIND"; tokenNames[T_COLLECTIVE] = "ST_COLLECTIVE";
    tokenNames[T_QUANTITY] = "ST_QUANTITY"; tokenNames[T_QUALITY] = "ST_QUALITY";
    tokenNames[T_MODE] = "ST_MODE"; tokenNames[T_INTRINSICMODE] = "ST_INTRINSICMODE";
    tokenNames[T_EXTRINSICMODE] = "ST_EXTRINSICMODE"; tokenNames[T_SUBKIND] = "ST_SUBKIND";
    tokenNames[T_PHASE] = "ST_PHASE"; tokenNames[T_ROLE] = "ST_ROLE";
    tokenNames[T_HISTORICALROLE] = "ST_HISTORICALROLE";

    tokenNames[T_MATERIAL] = "ST_MATERIAL"; tokenNames[T_DERIVATION] = "ST_DERIVATION";
    tokenNames[T_COMPARATIVE] = "ST_COMPARATIVE"; tokenNames[T_MEDIATION] = "ST_MEDIATION";
    tokenNames[T_CHARACTERIZATION] = "ST_CHARACTERIZATION"; tokenNames[T_SUBCOLLECTIONOF] = "ST_SUBCOLLECTIONOF";
    tokenNames[T_SUBQUALITYOF] = "ST_SUBQUALITYOF"; tokenNames[T_INSTANTIATION] = "ST_INSTANTIATION";
    tokenNames[T_EXTERNALDEPENDENCE] = "ST_EXTDEPENDENCE"; tokenNames[T_COMPONENTOF] = "ST_COMPONENTOF";
    tokenNames[T_MEMBEROF] = "ST_MEMBEROF"; tokenNames[T_TERMINATION] = "ST_TERMINATION";
    tokenNames[T_PARTICIPATIONAL] = "ST_PARTICIPATIONAL"; tokenNames[T_PARTICIPATION] = "ST_PARTICIPATION";
    tokenNames[T_HISTORICALDEPENDENCE] = "ST_HISTDEPENDENCE"; tokenNames[T_CREATION] = "ST_CREATION";
    tokenNames[T_MANIFESTATION] = "ST_MANIFESTATION"; tokenNames[T_BRINGSABOUT] = "ST_BRINGSABOUT";
    tokenNames[T_TRIGGERS] = "ST_TRIGGERS"; tokenNames[T_COMPOSITION] = "ST_COMPOSITION";
    tokenNames[T_AGGREGATION] = "ST_AGGREGATION"; tokenNames[T_INHERENCE] = "ST_INHERENCE";
    tokenNames[T_VALUE] = "ST_VALUE"; tokenNames[T_FORMAL] = "ST_FORMAL";
    tokenNames[T_CONSTITUTION] = "ST_CONSTITUTION";

    tokenNames[T_NUMBER_TYPE] = "TYPE_NUMBER"; tokenNames[T_STRING_TYPE] = "TYPE_STRING";
    tokenNames[T_BOOLEAN_TYPE] = "TYPE_BOOLEAN"; tokenNames[T_DATE_TYPE] = "TYPE_DATE";
    tokenNames[T_TIME_TYPE] = "TYPE_TIME"; tokenNames[T_DATETIME_TYPE] = "TYPE_DATETIME";

    tokenNames[T_ORDERED] = "META_ORDERED"; tokenNames[T_CONST] = "META_CONST";
    tokenNames[T_DERIVED] = "META_DERIVED"; tokenNames[T_SUBSETS] = "META_SUBSETS";
    tokenNames[T_REDEFINES] = "META_REDEFINES";

    tokenNames[T_LBRACE] = "LBRACE"; tokenNames[T_RBRACE] = "RBRACE";
    tokenNames[T_LPAREN] = "LPAREN"; tokenNames[T_RPAREN] = "RPAREN";
    tokenNames[T_LBRACK] = "LBRACK"; tokenNames[T_RBRACK] = "RBRACK";
    tokenNames[T_DOTDOT] = "DOTDOT"; tokenNames[T_DIAMOND_ARROW] = "DIAMOND_ARROW";
    tokenNames[T_ARROW_DIAMOND] = "ARROW_DIAMOND"; tokenNames[T_ASTERISK] = "ASTERISK";
    tokenNames[T_AT] = "AT"; tokenNames[T_DOT] = "DOT";

    tokenNames[T_CLASS_NAME] = "CLASS_NAME"; tokenNames[T_RELATION_NAME] = "RELATION_NAME";
    tokenNames[T_INSTANCE_NAME] = "INSTANCE_NAME"; tokenNames[T_NEW_DATA_TYPE] = "NEW_DATA_TYPE";
    tokenNames[T_NUMBER] = "NUMBER_LITERAL";
    tokenNames[T_STRING] = "STRING_LITERAL"; // Se houver regra para string literal

    tokenNames[T_INVALID] = "INVALID"; tokenNames[T_EOF] = "EOF";
}