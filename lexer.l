%{
#include <iostream>
#include <string>
#include <cstring> // Para strdup
#include "parser.tab.h" // Tokens gerados pelo Bison

using namespace std;
%}

%option yylineno
%option noyywrap

/* --- Definições Regulares --- */
letra_maiuscula [A-Z] 
letras      [A-Za-z] 
digito      [0-9]
num         {digito}+

/* Identificadores */
/* Classe começa com maiúscula */
className {letra_maiuscula}({letras}|_|{digito})*{letras}?

/* RelationName começa com minúscula */
relationName [a-z]([A-Za-z0-9_])*

/* Novos Tipos terminam com DataType */
newType {letra_maiuscula}({letras}|{digito})*DataType

%%

[ \t\r]+        ; /* Ignora espaços em branco */
\n              ; /* O yylineno conta as linhas automaticamente */
"//".* ; /* Ignora comentários de uma linha */

"package"       { return T_PACKAGE; }
"import"        { return T_IMPORT; }
"genset"        { return T_GENSET; }
"disjoint"      { return T_DISJOINT; }
"complete"      { return T_COMPLETE; }
"general"       { return T_GENERAL; }
"specifics"     { return T_SPECIFICS; }
"where"         { return T_WHERE; }
"functional-complexes" { return T_FUNCTIONAL_COMPLEXES; }

"datatype"      { return T_DATATYPE; }
"enum"          { return T_ENUM; }
"relation"      { return T_RELATION; }
"relator"       { return T_RELATION; } 


"kind"          { return T_KIND; }
"subkind"       { return T_SUBKIND; }
"role"          { return T_ROLE; }
"phase"         { return T_PHASE; }
"category"      { return T_CATEGORY; }
"mixin"         { return T_MIXIN; }
"roleMixin"     { return T_ROLEMIXIN; }
"phaseMixin"    { return T_PHASEMIXIN; }
"collective"    { return T_COLLECTIVE; }
"quantity"      { return T_QUANTITY; }
"quality"       { return T_QUALITY; }
"mode"          { return T_MODE; }
"event"         { return T_EVENT; }
"situation"     { return T_SITUATION; }
"process"       { return T_PROCESS; }


"material"      { return T_MATERIAL; }
"mediation"     { return T_MEDIATION; }
"componentOf"   { return T_COMPONENTOF; }
"memberOf"      { return T_MEMBEROF; }
"derivation"    { return T_DERIVATION; }
"characterization" { return T_CHARACTERIZATION; }
"formal"        { return T_FORMAL; }


"number"        { return T_NUMBER_TYPE; }
"string"        { return T_STRING_TYPE; }
"boolean"       { return T_BOOLEAN_TYPE; }
"date"          { return T_DATE_TYPE; }
"int"           { return T_NUMBER_TYPE; } 


"{"             { return T_LBRACE; }
"}"             { return T_RBRACE; }
"("             { return T_LPAREN; }
")"             { return T_RPAREN; }
"["             { return T_LBRACK; }
"]"             { return T_RBRACK; }
".."            { return T_DOTDOT; }
":"             { return T_COLON; }
","             { return T_COMMA; }
"@"             { return T_AT; }
"*"             { return T_ASTERISK; }
"<>"            { return T_DIAMOND_ARROW; } 
"<>--"          { return T_DIAMOND_ARROW; }
"--<>"          { return T_ARROW_DIAMOND; }
"--"            { return T_DOTDOT; } 

{newType}       { 
    yylval.sval = strdup(yytext); 
    return T_NEW_DATA_TYPE; 
}

{className}     { 
    yylval.sval = strdup(yytext); 
    return T_CLASS_NAME; 
}

{relationName}  { 
    yylval.sval = strdup(yytext); 
    return T_RELATION_NAME; 
}

{num}           { 
    yylval.ival = atoi(yytext);
    return T_NUMBER_LITERAL; 
}

.               { 
    /* Apenas avisa no erro léxico, não para a execução imediatamente */
    cerr << "ERRO LÉXICO: Caractere inválido '" << yytext << "' na linha " << yylineno << endl;
}

%%