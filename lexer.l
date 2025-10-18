%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
#include "tokens.h"
using std::cout;
%}

// definições regulares
%option noyywrap
delim	[ \t\n]
brancos {delim}+
letra	[A-Za-z]
digito	[0-9]
newType {letra}+DataType
string	{letra}({letra}|{digito})*
num	    {digito}+(\.{digito}+)?(E[+-]?{digito}+)?


%%
{brancos}	; // nenhuma ação e nenhum retorno
if		    return IF; 
then		return THEN; 
else		return ELSE; 
{newType}   return NEWTYPE;
{string}	return STRING;  
{num}	    return NUM; 

"{"		    return RELOP; 
"}"		    return RELOP; 
"("		    return RELOP; 
")"		    return RELOP; 
"["		    return RELOP; 
"]"		    return RELOP;
".."		return RELOP; 
"<>--"		return RELOP;  
"--<>"		return RELOP;
"*"		    return RELOP;
"@"		    return RELOP; 
":"		    return RELOP;   
"<"		    return RELOP; 
"<="		return RELOP; 
"="		    return RELOP; 
"<>"		return RELOP; 
">"		    return RELOP;
">="		return RELOP; 
.           cout << YYText() << " é um token inválido!\n"; 
%%

// nenhuma função auxiliar é necessária
