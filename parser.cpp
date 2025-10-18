#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;

void Parser::Start()
{
    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch(lookahead)
        {
        
            case T_PACKAGE: cout << "T_PACKAGE: " << scanner.YYText() << "\n"; break;
            case T_IMPORT: cout << "T_IMPORT: " << scanner.YYText() << "\n"; break;
            case T_GENSET: cout << "T_GENSET: " << scanner.YYText() << "\n"; break;
            case T_DISJOINT: cout << "T_DISJOINT: " << scanner.YYText() << "\n"; break;
            case T_COMPLETE: cout << "T_COMPLETE: " << scanner.YYText() << "\n"; break;
            case T_GENERAL: cout << "T_GENERAL: " << scanner.YYText() << "\n"; break;
            case T_SPECIFICS: cout << "T_SPECIFICS: " << scanner.YYText() << "\n"; break;
            case T_WHERE: cout << "T_WHERE: " << scanner.YYText() << "\n"; break;
            case T_FUNCTIONAL_COMPLEXES: cout << "T_FUNCTIONAL_COMPLEXES: " << scanner.YYText() << "\n"; break;

            case T_EVENT: cout << "T_EVENT: " << scanner.YYText() << "\n"; break;
            case T_SITUATION: cout << "T_SITUATION: " << scanner.YYText() << "\n"; break;
            case T_PROCESS: cout << "T_PROCESS: " << scanner.YYText() << "\n"; break;
            case T_CATEGORY: cout << "T_CATEGORY: " << scanner.YYText() << "\n"; break;
            case T_MIXIN: cout << "T_MIXIN: " << scanner.YYText() << "\n"; break;
            case T_PHASEMIXIN: cout << "T_PHASEMIXIN: " << scanner.YYText() << "\n"; break;
            case T_ROLEMIXIN: cout << "T_ROLEMIXIN: " << scanner.YYText() << "\n"; break;
            case T_HISTORICALROLEMIXIN: cout << "T_HISTORICALROLEMIXIN: " << scanner.YYText() << "\n"; break;
            case T_KIND: cout << "T_KIND: " << scanner.YYText() << "\n"; break;
            case T_COLLECTIVE: cout << "T_COLLECTIVE: " << scanner.YYText() << "\n"; break;
            case T_QUANTITY: cout << "T_QUANTITY: " << scanner.YYText() << "\n"; break;
            case T_QUALITY: cout << "T_QUALITY: " << scanner.YYText() << "\n"; break;
            case T_MODE: cout << "T_MODE: " << scanner.YYText() << "\n"; break;
            case T_INTRINSICMODE: cout << "T_INTRINSICMODE: " << scanner.YYText() << "\n"; break;
            case T_EXTRINSICMODE: cout << "T_EXTRINSICMODE: " << scanner.YYText() << "\n"; break;
            case T_SUBKIND: cout << "T_SUBKIND: " << scanner.YYText() << "\n"; break;
            case T_PHASE: cout << "T_PHASE: " << scanner.YYText() << "\n"; break;
            case T_ROLE: cout << "T_ROLE: " << scanner.YYText() << "\n"; break;
            case T_HISTORICALROLE: cout << "T_HISTORICALROLE: " << scanner.YYText() << "\n"; break;

            case T_MATERIAL: cout << "T_MATERIAL: " << scanner.YYText() << "\n"; break;
            case T_DERIVATION: cout << "T_DERIVATION: " << scanner.YYText() << "\n"; break;
            case T_COMPARATIVE: cout << "T_COMPARATIVE: " << scanner.YYText() << "\n"; break;
            case T_MEDIATION: cout << "T_MEDIATION: " << scanner.YYText() << "\n"; break;
            case T_CHARACTERIZATION: cout << "T_CHARACTERIZATION: " << scanner.YYText() << "\n"; break;
            case T_SUBCOLLECTIONOF: cout << "T_SUBCOLLECTIONOF: " << scanner.YYText() << "\n"; break;
            case T_SUBQUALITYOF: cout << "T_SUBQUALITYOF: " << scanner.YYText() << "\n"; break;
            case T_INSTANTIATION: cout << "T_INSTANTIATION: " << scanner.YYText() << "\n"; break;
            case T_EXTERNALDEPENDENCE: cout << "T_EXTERNALDEPENDENCE: " << scanner.YYText() << "\n"; break;
            case T_COMPONENTOF: cout << "T_COMPONENTOF: " << scanner.YYText() << "\n"; break;
            case T_MEMBEROF: cout << "T_MEMBEROF: " << scanner.YYText() << "\n"; break;
            case T_TERMINATION: cout << "T_TERMINATION: " << scanner.YYText() << "\n"; break;
            case T_PARTICIPATIONAL: cout << "T_PARTICIPATIONAL: " << scanner.YYText() << "\n"; break;
            case T_PARTICIPATION: cout << "T_PARTICIPATION: " << scanner.YYText() << "\n"; break;
            case T_HISTORICALDEPENDENCE: cout << "T_HISTORICALDEPENDENCE: " << scanner.YYText() << "\n"; break;
            case T_CREATION: cout << "T_CREATION: " << scanner.YYText() << "\n"; break;
            case T_MANIFESTATION: cout << "T_MANIFESTATION: " << scanner.YYText() << "\n"; break;
            case T_BRINGSABOUT: cout << "T_BRINGSABOUT: " << scanner.YYText() << "\n"; break;
            case T_TRIGGERS: cout << "T_TRIGGERS: " << scanner.YYText() << "\n"; break;
            case T_COMPOSITION: cout << "T_COMPOSITION: " << scanner.YYText() << "\n"; break;
            case T_AGGREGATION: cout << "T_AGGREGATION: " << scanner.YYText() << "\n"; break;
            case T_INHERENCE: cout << "T_INHERENCE: " << scanner.YYText() << "\n"; break;
            case T_VALUE: cout << "T_VALUE: " << scanner.YYText() << "\n"; break;
            case T_FORMAL: cout << "T_FORMAL: " << scanner.YYText() << "\n"; break;
            case T_CONSTITUTION: cout << "T_CONSTITUTION: " << scanner.YYText() << "\n"; break;

            case T_NUMBER_TYPE: cout << "T_NUMBER_TYPE: " << scanner.YYText() << "\n"; break;
            case T_STRING_TYPE: cout << "T_STRING_TYPE: " << scanner.YYText() << "\n"; break;
            case T_BOOLEAN_TYPE: cout << "T_BOOLEAN_TYPE: " << scanner.YYText() << "\n"; break;
            case T_DATE_TYPE: cout << "T_DATE_TYPE: " << scanner.YYText() << "\n"; break;
            case T_TIME_TYPE: cout << "T_TIME_TYPE: " << scanner.YYText() << "\n"; break;
            case T_DATETIME_TYPE: cout << "T_DATETIME_TYPE: " << scanner.YYText() << "\n"; break;

            case T_ORDERED: cout << "T_ORDERED: " << scanner.YYText() << "\n"; break;
            case T_CONST: cout << "T_CONST: " << scanner.YYText() << "\n"; break;
            case T_DERIVED: cout << "T_DERIVED: " << scanner.YYText() << "\n"; break;
            case T_SUBSETS: cout << "T_SUBSETS: " << scanner.YYText() << "\n"; break;
            case T_REDEFINES: cout << "T_REDEFINES: " << scanner.YYText() << "\n"; break;

            case T_LBRACE: cout << "T_LBRACE: " << scanner.YYText() << "\n"; break;
            case T_RBRACE: cout << "T_RBRACE: " << scanner.YYText() << "\n"; break;
            case T_LPAREN: cout << "T_LPAREN: " << scanner.YYText() << "\n"; break;
            case T_RPAREN: cout << "T_RPAREN: " << scanner.YYText() << "\n"; break;
            case T_LBRACK: cout << "T_LBRACK: " << scanner.YYText() << "\n"; break;
            case T_RBRACK: cout << "T_RBRACK: " << scanner.YYText() << "\n"; break;
            case T_DOTDOT: cout << "T_DOTDOT: " << scanner.YYText() << "\n"; break;
            case T_DIAMOND_ARROW: cout << "T_DIAMOND_ARROW: " << scanner.YYText() << "\n"; break;
            case T_ARROW_DIAMOND: cout << "T_ARROW_DIAMOND: " << scanner.YYText() << "\n"; break;

            case T_ASTERISK: cout << "T_ASTERISK: " << scanner.YYText() << "\n"; break;
            case T_AT: cout << "T_AT: " << scanner.YYText() << "\n"; break;
            case T_DOT: cout << "T_DOT: " << scanner.YYText() << "\n"; break;

            case T_CLASS_NAME: cout << "T_CLASS_NAME: " << scanner.YYText() << "\n"; break;
            case T_RELATION_NAME: cout << "T_RELATION_NAME: " << scanner.YYText() << "\n"; break;
            case T_INSTANCE_NAME: cout << "T_INSTANCE_NAME: " << scanner.YYText() << "\n"; break;
            case T_NEW_DATA_TYPE: cout << "T_NEW_DATA_TYPE: " << scanner.YYText() << "\n"; break;
            case T_NUMBER: cout << "T_NUMBER: " << scanner.YYText() << "\n"; break;
            case T_STRING: cout << "T_STRING: " << scanner.YYText() << "\n"; break;

            case T_INVALID: cout << "T_INVALID: " << scanner.YYText() << "\n"; break;
            case T_EOF: cout << "T_EOF: " << scanner.YYText() << "\n"; break;
        }
    }
}
