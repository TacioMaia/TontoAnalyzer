/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_TACIOPLAYS_COMPILADORES_TONTOANALYZER_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_HOME_TACIOPLAYS_COMPILADORES_TONTOANALYZER_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_PACKAGE = 258,               /* T_PACKAGE  */
    T_IMPORT = 259,                /* T_IMPORT  */
    T_GENSET = 260,                /* T_GENSET  */
    T_DISJOINT = 261,              /* T_DISJOINT  */
    T_COMPLETE = 262,              /* T_COMPLETE  */
    T_GENERAL = 263,               /* T_GENERAL  */
    T_SPECIFICS = 264,             /* T_SPECIFICS  */
    T_WHERE = 265,                 /* T_WHERE  */
    T_FUNCTIONAL_COMPLEXES = 266,  /* T_FUNCTIONAL_COMPLEXES  */
    T_DATATYPE = 267,              /* T_DATATYPE  */
    T_ENUM = 268,                  /* T_ENUM  */
    T_RELATION = 269,              /* T_RELATION  */
    T_KIND = 270,                  /* T_KIND  */
    T_SUBKIND = 271,               /* T_SUBKIND  */
    T_ROLE = 272,                  /* T_ROLE  */
    T_PHASE = 273,                 /* T_PHASE  */
    T_CATEGORY = 274,              /* T_CATEGORY  */
    T_MIXIN = 275,                 /* T_MIXIN  */
    T_ROLEMIXIN = 276,             /* T_ROLEMIXIN  */
    T_PHASEMIXIN = 277,            /* T_PHASEMIXIN  */
    T_HISTORICALROLE = 278,        /* T_HISTORICALROLE  */
    T_HISTORICALROLEMIXIN = 279,   /* T_HISTORICALROLEMIXIN  */
    T_COLLECTIVE = 280,            /* T_COLLECTIVE  */
    T_QUANTITY = 281,              /* T_QUANTITY  */
    T_QUALITY = 282,               /* T_QUALITY  */
    T_MODE = 283,                  /* T_MODE  */
    T_INTRINSICMODE = 284,         /* T_INTRINSICMODE  */
    T_EXTRINSICMODE = 285,         /* T_EXTRINSICMODE  */
    T_EVENT = 286,                 /* T_EVENT  */
    T_SITUATION = 287,             /* T_SITUATION  */
    T_PROCESS = 288,               /* T_PROCESS  */
    T_MATERIAL = 289,              /* T_MATERIAL  */
    T_DERIVATION = 290,            /* T_DERIVATION  */
    T_COMPARATIVE = 291,           /* T_COMPARATIVE  */
    T_MEDIATION = 292,             /* T_MEDIATION  */
    T_CHARACTERIZATION = 293,      /* T_CHARACTERIZATION  */
    T_SUBCOLLECTIONOF = 294,       /* T_SUBCOLLECTIONOF  */
    T_SUBQUALITYOF = 295,          /* T_SUBQUALITYOF  */
    T_INSTANTIATION = 296,         /* T_INSTANTIATION  */
    T_EXTERNALDEPENDENCE = 297,    /* T_EXTERNALDEPENDENCE  */
    T_COMPONENTOF = 298,           /* T_COMPONENTOF  */
    T_MEMBEROF = 299,              /* T_MEMBEROF  */
    T_TERMINATION = 300,           /* T_TERMINATION  */
    T_PARTICIPATIONAL = 301,       /* T_PARTICIPATIONAL  */
    T_PARTICIPATION = 302,         /* T_PARTICIPATION  */
    T_HISTORICALDEPENDENCE = 303,  /* T_HISTORICALDEPENDENCE  */
    T_CREATION = 304,              /* T_CREATION  */
    T_MANIFESTATION = 305,         /* T_MANIFESTATION  */
    T_BRINGSABOUT = 306,           /* T_BRINGSABOUT  */
    T_TRIGGERS = 307,              /* T_TRIGGERS  */
    T_COMPOSITION = 308,           /* T_COMPOSITION  */
    T_AGGREGATION = 309,           /* T_AGGREGATION  */
    T_INHERENCE = 310,             /* T_INHERENCE  */
    T_VALUE = 311,                 /* T_VALUE  */
    T_FORMAL = 312,                /* T_FORMAL  */
    T_CONSTITUTION = 313,          /* T_CONSTITUTION  */
    T_NUMBER_TYPE = 314,           /* T_NUMBER_TYPE  */
    T_STRING_TYPE = 315,           /* T_STRING_TYPE  */
    T_BOOLEAN_TYPE = 316,          /* T_BOOLEAN_TYPE  */
    T_DATE_TYPE = 317,             /* T_DATE_TYPE  */
    T_TIME_TYPE = 318,             /* T_TIME_TYPE  */
    T_DATETIME_TYPE = 319,         /* T_DATETIME_TYPE  */
    T_LBRACE = 320,                /* T_LBRACE  */
    T_RBRACE = 321,                /* T_RBRACE  */
    T_LPAREN = 322,                /* T_LPAREN  */
    T_RPAREN = 323,                /* T_RPAREN  */
    T_LBRACK = 324,                /* T_LBRACK  */
    T_RBRACK = 325,                /* T_RBRACK  */
    T_DOTDOT = 326,                /* T_DOTDOT  */
    T_DIAMOND_ARROW = 327,         /* T_DIAMOND_ARROW  */
    T_ARROW_DIAMOND = 328,         /* T_ARROW_DIAMOND  */
    T_ASTERISK = 329,              /* T_ASTERISK  */
    T_AT = 330,                    /* T_AT  */
    T_DOT = 331,                   /* T_DOT  */
    T_COLON = 332,                 /* T_COLON  */
    T_COMMA = 333,                 /* T_COMMA  */
    T_CLASS_NAME = 334,            /* T_CLASS_NAME  */
    T_RELATION_NAME = 335,         /* T_RELATION_NAME  */
    T_INSTANCE_NAME = 336,         /* T_INSTANCE_NAME  */
    T_NEW_DATA_TYPE = 337,         /* T_NEW_DATA_TYPE  */
    T_NUMBER_LITERAL = 338         /* T_NUMBER_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.y"

    char* sval; /* Para nomes (strings) */
    int ival;   /* Para números (inteiros) */

#line 152 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_TACIOPLAYS_COMPILADORES_TONTOANALYZER_BUILD_PARSER_TAB_H_INCLUDED  */
