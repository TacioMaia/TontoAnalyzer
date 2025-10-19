%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
#include "tokens.h"
using std::cout;

// Variaveis globais para linha e coluna
extern int yylineno;
int column = 1;

// Função que atualiza a coluna
void update_column(){
    column += yyleng;
}
%}

%option yylineno
%option noyywrap
%option c++


// Definições Regulares
delim   [ \t\n]
brancos {delim}+
newLine [\n]    
letra_maiuscula [A-Z]
letra_minuscula [a-z]
letras	[A-Za-z] 
digito	[0-9]
num	    {digito}+(\.{digito}+)?(E[+-]?{digito}+)?
//string	{letras}({letras}|{digito})*

// Nome da Classe
className {letra_maiuscula}({letras}|_)*{letras}

// Nome da Relação
relationName {letra_minuscula}({letras|_})*{letras}

// Nome da Instancia
instanceName {letras}({letras|_})*{digito}+

// Nome Novos Tipos
newType {letras}+DataType

// Regras de Tradução
%%
{brancos}       { update_column(); }
{newLine}       { column = 1; }

"package"       { update_column(); return T_PACKAGE; }
"import"        { update_column(); return T_IMPORT; }
"genset"        { update_column(); return T_GENSET; }
"disjoint"      { update_column(); return T_DISJOINT; }
"complete"      { update_column(); return T_COMPLETE; }
"general"       { update_column(); return T_GENERAL; }
"specifics"     { update_column(); return T_SPECIFICS; }
"where"         { update_column(); return T_WHERE; }

//Estereótipos de Classe
"event"               { update_column(); return T_EVENT; }
"situation"           { update_column(); return T_SITUATION; }
"process"             { update_column(); return T_PROCESS; }
"category"            { update_column(); return T_CATEGORY; }
"mixin"               { update_column(); return T_MIXIN; }
"phaseMixin"          { update_column(); return T_PHASEMIXIN; }
"roleMixin"           { update_column(); return T_ROLEMIXIN; }
"historicalRoleMixin" { update_column(); return T_HISTORICALROLEMIXIN; }
"kind"                { update_column(); return T_KIND; }
"collective"          { update_column(); return T_COLLECTIVE; }
"quantity"            { update_column(); return T_QUANTITY; }
"quality"             { update_column(); return T_QUALITY; }
"mode"                { update_column(); return T_MODE; }
"intrisicMode"        { update_column(); return T_INTRINSICMODE; }
"extrinsicMode"       { update_column(); return T_EXTRINSICMODE; }
"subkind"             { update_column(); return T_SUBKIND; }
"phase"               { update_column(); return T_PHASE; }
"role"                { update_column(); return T_ROLE; }
"historical Role"     { update_column(); return T_HISTORICALROLE; }

// Esteriotipos de Relação
"material"              { update_column(); return T_MATERIAL; }
"derivation"            { update_column(); return T_DERIVATION; }
"comparative"           { update_column(); return T_COMPARATIVE; }
"mediation"             { update_column(); return T_MEDIATION; }
"characterization"      { update_column(); return T_CHARACTERIZATION; }
"subCollectionOf"       { update_column(); return T_SUBCOLLECTIONOF; }
"subQualityof"          { update_column(); return T_SUBQUALITYOF; }
"instantiation"         { update_column(); return T_INSTANTIATION; }
"externalDependence"    { update_column(); return T_EXTERNALDEPENDENCE; }
"componentof"           { update_column(); return T_COMPONENTOF; }
"memberof"              { update_column(); return T_MEMBEROF; }
"termination"           { update_column(); return T_TERMINATION; }
"participational"       { update_column(); return T_PARTICIPATIONAL; }
"participation"         { update_column(); return T_PARTICIPATION; }
"historical Dependence" { update_column(); return T_HISTORICALDEPENDENCE; }
"creation"              { update_column(); return T_CREATION; }
"manifestation"         { update_column(); return T_MANIFESTATION; }
"bringsAbout"           { update_column(); return T_BRINGSABOUT; }
"triggers"              { update_column(); return T_TRIGGERS; }
"composition"           { update_column(); return T_COMPOSITION; }
"aggregation"           { update_column(); return T_AGGREGATION; }
"inherence"             { update_column(); return T_INHERENCE; }
"value"                 { update_column(); return T_VALUE; }
"formal"                { update_column(); return T_FORMAL; }
"constitution"          { update_column(); return T_CONSTITUTION; }

// Tipos de Dados Nativos 
"number"    { update_column(); return T_NUMBER_TYPE; }
"string"    { update_column(); return T_STRING_TYPE; }
"boolean"   { update_column(); return T_BOOLEAN_TYPE; }
"date"      { update_column(); return T_DATE_TYPE; }
"time"      { update_column(); return T_TIME_TYPE; }
"datetime"  { update_column(); return T_DATETIME_TYPE; }

// Meta Atributos
"ordered"   { update_column(); return T_ORDERED; }
"const"     { update_column(); return T_CONST; }
"derived"   { update_column(); return T_DERIVED; }
"subsets"   { update_column(); return T_SUBSETS; }
"redefines" { update_column(); return T_REDEFINES; }

// Símbolos Especiais
"{"             { update_column(); return T_LBRACE; }
"}"             { update_column(); return T_RBRACE; }
"("             { update_column(); return T_LPAREN; }
")"             { update_column(); return T_RPAREN; }
"["             { update_column(); return T_LBRACK; }
"]"             { update_column(); return T_RBRACK; }
".."            { update_column(); return T_DOTDOT; }
"<>--"          { update_column(); return T_DIAMOND_ARROW; }
"--<>"          { update_column(); return T_ARROW_DIAMOND; }
"*"             { update_column(); return T_ASTERISK; }
"@"             { update_column(); return T_AT; }
"."             { update_column(); return T_DOT; }

// Literais e Identificadores
{className}     { update_column(); return T_CLASS_NAME; }
{relationName}  { update_column(); return T_RELATION_NAME; }
{instanceName}  { update_column(); return T_INSTANCE_NAME; }
{newType}       { update_column(); return T_NEW_DATA_TYPE; }
{num}           { update_column(); return T_NUMBER; }

//Tratamento de Erro
.               {
                    // Imprime a mensagem de erro 
                    cout << "Erro na linha " << yylineno << ", coluna " << column
                         << ": Token inválido '" << YYText() << "'\n";
                    // Sugestão de tratamento
                    cout << "  Sugestão: Verifique se o caractere é permitido pela linguagem TONTO ou se há erro na formação de um nome (ex: classe iniciando com minúscula, violação de convenção de nome, caractere especial inesperado).\n";
                    update_column(); 
                    return T_INVALID; 
                }
%%

// nenhuma função auxiliar é necessária
