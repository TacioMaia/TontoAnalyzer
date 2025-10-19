%{
/* Reconhecedor de uma linguagem simplificada */
#include <iostream>
#include "tokens.h"
using std::cout;

/* Variaveis globais para linha e coluna */
extern int yylineno;
int column = 1;

/* Função que atualiza a coluna */
void update_column(yyFlexLexer& scanner) {
    column += scanner.YYLeng();
}
%}

%option yylineno
%option noyywrap
%option c++


/* Definições Regulares */
delim   [ \t\n]
brancos {delim}+   
letra_maiuscula [A-Z] 
letras	[A-Za-z] 
digito	[0-9]
num	    {digito}+(\.{digito}+)?(E[+-]?{digito}+)?
/*string	{letras}({letras}|{digito})*  */

/* Nome da Classe */
className {letra_maiuscula}({letras}|_)*{letras}

/* Nome da Relação */
relationName [a-z]([A-Za-z_])*[A-Za-z]

/* Nome da Instancia */
instanceName {letras}(({letras})|_)*{digito}+


/* Nome Novos Tipos */
newType {letras}+DataType

/* Regras de Tradução */
%%
{brancos}       { update_column(*this); }

"package"       { update_column(*this); return T_PACKAGE; }
"import"        { update_column(*this); return T_IMPORT; }
"genset"        { update_column(*this); return T_GENSET; }
"disjoint"      { update_column(*this); return T_DISJOINT; }
"complete"      { update_column(*this); return T_COMPLETE; }
"general"       { update_column(*this); return T_GENERAL; }
"specifics"     { update_column(*this); return T_SPECIFICS; }
"where"         { update_column(*this); return T_WHERE; }


"event"               { update_column(*this); return T_EVENT; }
"situation"           { update_column(*this); return T_SITUATION; }
"process"             { update_column(*this); return T_PROCESS; }
"category"            { update_column(*this); return T_CATEGORY; }
"mixin"               { update_column(*this); return T_MIXIN; }
"phaseMixin"          { update_column(*this); return T_PHASEMIXIN; }
"roleMixin"           { update_column(*this); return T_ROLEMIXIN; }
"historicalRoleMixin" { update_column(*this); return T_HISTORICALROLEMIXIN; }
"kind"                { update_column(*this); return T_KIND; }
"collective"          { update_column(*this); return T_COLLECTIVE; }
"quantity"            { update_column(*this); return T_QUANTITY; }
"quality"             { update_column(*this); return T_QUALITY; }
"mode"                { update_column(*this); return T_MODE; }
"intrisicMode"        { update_column(*this); return T_INTRINSICMODE; }
"extrinsicMode"       { update_column(*this); return T_EXTRINSICMODE; }
"subkind"             { update_column(*this); return T_SUBKIND; }
"phase"               { update_column(*this); return T_PHASE; }
"role"                { update_column(*this); return T_ROLE; }
"historical Role"     { update_column(*this); return T_HISTORICALROLE; }


"material"              { update_column(*this); return T_MATERIAL; }
"derivation"            { update_column(*this); return T_DERIVATION; }
"comparative"           { update_column(*this); return T_COMPARATIVE; }
"mediation"             { update_column(*this); return T_MEDIATION; }
"characterization"      { update_column(*this); return T_CHARACTERIZATION; }
"subCollectionOf"       { update_column(*this); return T_SUBCOLLECTIONOF; }
"subQualityof"          { update_column(*this); return T_SUBQUALITYOF; }
"instantiation"         { update_column(*this); return T_INSTANTIATION; }
"externalDependence"    { update_column(*this); return T_EXTERNALDEPENDENCE; }
"componentof"           { update_column(*this); return T_COMPONENTOF; }
"memberof"              { update_column(*this); return T_MEMBEROF; }
"termination"           { update_column(*this); return T_TERMINATION; }
"participational"       { update_column(*this); return T_PARTICIPATIONAL; }
"participation"         { update_column(*this); return T_PARTICIPATION; }
"historical Dependence" { update_column(*this); return T_HISTORICALDEPENDENCE; }
"creation"              { update_column(*this); return T_CREATION; }
"manifestation"         { update_column(*this); return T_MANIFESTATION; }
"bringsAbout"           { update_column(*this); return T_BRINGSABOUT; }
"triggers"              { update_column(*this); return T_TRIGGERS; }
"composition"           { update_column(*this); return T_COMPOSITION; }
"aggregation"           { update_column(*this); return T_AGGREGATION; }
"inherence"             { update_column(*this); return T_INHERENCE; }
"value"                 { update_column(*this); return T_VALUE; }
"formal"                { update_column(*this); return T_FORMAL; }
"constitution"          { update_column(*this); return T_CONSTITUTION; }


"number"    { update_column(*this); return T_NUMBER_TYPE; }
"string"    { update_column(*this); return T_STRING_TYPE; }
"boolean"   { update_column(*this); return T_BOOLEAN_TYPE; }
"date"      { update_column(*this); return T_DATE_TYPE; }
"time"      { update_column(*this); return T_TIME_TYPE; }
"datetime"  { update_column(*this); return T_DATETIME_TYPE; }


"ordered"   { update_column(*this); return T_ORDERED; }
"const"     { update_column(*this); return T_CONST; }
"derived"   { update_column(*this); return T_DERIVED; }
"subsets"   { update_column(*this); return T_SUBSETS; }
"redefines" { update_column(*this); return T_REDEFINES; }


"{"             { update_column(*this); return T_LBRACE; }
"}"             { update_column(*this); return T_RBRACE; }
"("             { update_column(*this); return T_LPAREN; }
")"             { update_column(*this); return T_RPAREN; }
"["             { update_column(*this); return T_LBRACK; }
"]"             { update_column(*this); return T_RBRACK; }
".."            { update_column(*this); return T_DOTDOT; }
"<>--"          { update_column(*this); return T_DIAMOND_ARROW; }
"--<>"          { update_column(*this); return T_ARROW_DIAMOND; }
"*"             { update_column(*this); return T_ASTERISK; }
"@"             { update_column(*this); return T_AT; }
"."             { update_column(*this); return T_DOT; }


{newType}       { update_column(*this); return T_NEW_DATA_TYPE; }
{className}     { update_column(*this); return T_CLASS_NAME; }
{relationName}  { update_column(*this); return T_RELATION_NAME; }
{instanceName}  { update_column(*this); return T_INSTANCE_NAME; }
{num}           { update_column(*this); return T_NUMBER; }


.               {
                    // Imprime a mensagem de erro 
                    cout << "Erro na linha " << yylineno << ", coluna " << column
                         << ": Token inválido '" << YYText() << "'\n";
                    // Sugestão de tratamento
                    cout << "  Sugestão: Verifique se o caractere é permitido pela linguagem TONTO ou se há erro na formação de um nome (ex: classe iniciando com minúscula, violação de convenção de nome, caractere especial inesperado).\n";
                    update_column(*this); 
                    return T_INVALID; 
                }
%%

/* nenhuma função auxiliar é necessária */
