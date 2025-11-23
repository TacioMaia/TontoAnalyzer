/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char *s);

// Estruturas para a Tabela de Síntese
vector<string> packages;
string current_package = "Global"; 
map<string, vector<string>> classes_by_package; 
vector<string> external_relations;
int count_datatypes = 0;
int count_enums = 0;
int count_gensets = 0;

void register_class(string class_name) {
    classes_by_package[current_package].push_back(class_name);
}

void register_external_relation(string relation_name) {
    external_relations.push_back(relation_name);
}

#line 103 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PACKAGE = 3,                  /* T_PACKAGE  */
  YYSYMBOL_T_IMPORT = 4,                   /* T_IMPORT  */
  YYSYMBOL_T_GENSET = 5,                   /* T_GENSET  */
  YYSYMBOL_T_DISJOINT = 6,                 /* T_DISJOINT  */
  YYSYMBOL_T_COMPLETE = 7,                 /* T_COMPLETE  */
  YYSYMBOL_T_GENERAL = 8,                  /* T_GENERAL  */
  YYSYMBOL_T_SPECIFICS = 9,                /* T_SPECIFICS  */
  YYSYMBOL_T_WHERE = 10,                   /* T_WHERE  */
  YYSYMBOL_T_OF = 11,                      /* T_OF  */
  YYSYMBOL_T_DATATYPE = 12,                /* T_DATATYPE  */
  YYSYMBOL_T_ENUM = 13,                    /* T_ENUM  */
  YYSYMBOL_T_RELATION = 14,                /* T_RELATION  */
  YYSYMBOL_T_FUNCTIONAL_COMPLEXES = 15,    /* T_FUNCTIONAL_COMPLEXES  */
  YYSYMBOL_T_RELATORS = 16,                /* T_RELATORS  */
  YYSYMBOL_T_INTRINSIC_MODES = 17,         /* T_INTRINSIC_MODES  */
  YYSYMBOL_T_EXTRINSIC_MODES = 18,         /* T_EXTRINSIC_MODES  */
  YYSYMBOL_T_QUALITIES = 19,               /* T_QUALITIES  */
  YYSYMBOL_T_MODES = 20,                   /* T_MODES  */
  YYSYMBOL_T_EVENTS = 21,                  /* T_EVENTS  */
  YYSYMBOL_T_SITUATIONS = 22,              /* T_SITUATIONS  */
  YYSYMBOL_T_KIND = 23,                    /* T_KIND  */
  YYSYMBOL_T_SUBKIND = 24,                 /* T_SUBKIND  */
  YYSYMBOL_T_ROLE = 25,                    /* T_ROLE  */
  YYSYMBOL_T_PHASE = 26,                   /* T_PHASE  */
  YYSYMBOL_T_CATEGORY = 27,                /* T_CATEGORY  */
  YYSYMBOL_T_MIXIN = 28,                   /* T_MIXIN  */
  YYSYMBOL_T_ROLEMIXIN = 29,               /* T_ROLEMIXIN  */
  YYSYMBOL_T_PHASEMIXIN = 30,              /* T_PHASEMIXIN  */
  YYSYMBOL_T_HISTORICALROLE = 31,          /* T_HISTORICALROLE  */
  YYSYMBOL_T_HISTORICALROLEMIXIN = 32,     /* T_HISTORICALROLEMIXIN  */
  YYSYMBOL_T_COLLECTIVE = 33,              /* T_COLLECTIVE  */
  YYSYMBOL_T_QUANTITY = 34,                /* T_QUANTITY  */
  YYSYMBOL_T_QUALITY = 35,                 /* T_QUALITY  */
  YYSYMBOL_T_MODE = 36,                    /* T_MODE  */
  YYSYMBOL_T_INTRINSICMODE = 37,           /* T_INTRINSICMODE  */
  YYSYMBOL_T_EXTRINSICMODE = 38,           /* T_EXTRINSICMODE  */
  YYSYMBOL_T_EVENT = 39,                   /* T_EVENT  */
  YYSYMBOL_T_SITUATION = 40,               /* T_SITUATION  */
  YYSYMBOL_T_PROCESS = 41,                 /* T_PROCESS  */
  YYSYMBOL_T_MATERIAL = 42,                /* T_MATERIAL  */
  YYSYMBOL_T_DERIVATION = 43,              /* T_DERIVATION  */
  YYSYMBOL_T_COMPARATIVE = 44,             /* T_COMPARATIVE  */
  YYSYMBOL_T_MEDIATION = 45,               /* T_MEDIATION  */
  YYSYMBOL_T_CHARACTERIZATION = 46,        /* T_CHARACTERIZATION  */
  YYSYMBOL_T_SUBCOLLECTIONOF = 47,         /* T_SUBCOLLECTIONOF  */
  YYSYMBOL_T_SUBQUALITYOF = 48,            /* T_SUBQUALITYOF  */
  YYSYMBOL_T_INSTANTIATION = 49,           /* T_INSTANTIATION  */
  YYSYMBOL_T_EXTERNALDEPENDENCE = 50,      /* T_EXTERNALDEPENDENCE  */
  YYSYMBOL_T_COMPONENTOF = 51,             /* T_COMPONENTOF  */
  YYSYMBOL_T_MEMBEROF = 52,                /* T_MEMBEROF  */
  YYSYMBOL_T_TERMINATION = 53,             /* T_TERMINATION  */
  YYSYMBOL_T_PARTICIPATIONAL = 54,         /* T_PARTICIPATIONAL  */
  YYSYMBOL_T_PARTICIPATION = 55,           /* T_PARTICIPATION  */
  YYSYMBOL_T_HISTORICALDEPENDENCE = 56,    /* T_HISTORICALDEPENDENCE  */
  YYSYMBOL_T_CREATION = 57,                /* T_CREATION  */
  YYSYMBOL_T_MANIFESTATION = 58,           /* T_MANIFESTATION  */
  YYSYMBOL_T_BRINGSABOUT = 59,             /* T_BRINGSABOUT  */
  YYSYMBOL_T_TRIGGERS = 60,                /* T_TRIGGERS  */
  YYSYMBOL_T_COMPOSITION = 61,             /* T_COMPOSITION  */
  YYSYMBOL_T_AGGREGATION = 62,             /* T_AGGREGATION  */
  YYSYMBOL_T_INHERENCE = 63,               /* T_INHERENCE  */
  YYSYMBOL_T_VALUE = 64,                   /* T_VALUE  */
  YYSYMBOL_T_FORMAL = 65,                  /* T_FORMAL  */
  YYSYMBOL_T_CONSTITUTION = 66,            /* T_CONSTITUTION  */
  YYSYMBOL_T_NUMBER_TYPE = 67,             /* T_NUMBER_TYPE  */
  YYSYMBOL_T_STRING_TYPE = 68,             /* T_STRING_TYPE  */
  YYSYMBOL_T_BOOLEAN_TYPE = 69,            /* T_BOOLEAN_TYPE  */
  YYSYMBOL_T_DATE_TYPE = 70,               /* T_DATE_TYPE  */
  YYSYMBOL_T_TIME_TYPE = 71,               /* T_TIME_TYPE  */
  YYSYMBOL_T_DATETIME_TYPE = 72,           /* T_DATETIME_TYPE  */
  YYSYMBOL_T_LBRACE = 73,                  /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 74,                  /* T_RBRACE  */
  YYSYMBOL_T_LPAREN = 75,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 76,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACK = 77,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 78,                  /* T_RBRACK  */
  YYSYMBOL_T_DOTDOT = 79,                  /* T_DOTDOT  */
  YYSYMBOL_T_DIAMOND_ARROW = 80,           /* T_DIAMOND_ARROW  */
  YYSYMBOL_T_ARROW_DIAMOND = 81,           /* T_ARROW_DIAMOND  */
  YYSYMBOL_T_ASTERISK = 82,                /* T_ASTERISK  */
  YYSYMBOL_T_AT = 83,                      /* T_AT  */
  YYSYMBOL_T_DOT = 84,                     /* T_DOT  */
  YYSYMBOL_T_COLON = 85,                   /* T_COLON  */
  YYSYMBOL_T_COMMA = 86,                   /* T_COMMA  */
  YYSYMBOL_T_CLASS_NAME = 87,              /* T_CLASS_NAME  */
  YYSYMBOL_T_RELATION_NAME = 88,           /* T_RELATION_NAME  */
  YYSYMBOL_T_INSTANCE_NAME = 89,           /* T_INSTANCE_NAME  */
  YYSYMBOL_T_NEW_DATA_TYPE = 90,           /* T_NEW_DATA_TYPE  */
  YYSYMBOL_T_NUMBER_LITERAL = 91,          /* T_NUMBER_LITERAL  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_program = 93,                   /* program  */
  YYSYMBOL_declarations = 94,              /* declarations  */
  YYSYMBOL_declaration = 95,               /* declaration  */
  YYSYMBOL_import_decl = 96,               /* import_decl  */
  YYSYMBOL_package_decl = 97,              /* package_decl  */
  YYSYMBOL_98_1 = 98,                      /* $@1  */
  YYSYMBOL_opt_body = 99,                  /* opt_body  */
  YYSYMBOL_element_list = 100,             /* element_list  */
  YYSYMBOL_element = 101,                  /* element  */
  YYSYMBOL_class_decl = 102,               /* class_decl  */
  YYSYMBOL_103_2 = 103,                    /* $@2  */
  YYSYMBOL_class_stereotype = 104,         /* class_stereotype  */
  YYSYMBOL_opt_classification = 105,       /* opt_classification  */
  YYSYMBOL_opt_specialization = 106,       /* opt_specialization  */
  YYSYMBOL_opt_class_body = 107,           /* opt_class_body  */
  YYSYMBOL_class_members = 108,            /* class_members  */
  YYSYMBOL_attribute = 109,                /* attribute  */
  YYSYMBOL_type_specifier = 110,           /* type_specifier  */
  YYSYMBOL_opt_constraints = 111,          /* opt_constraints  */
  YYSYMBOL_datatype_decl = 112,            /* datatype_decl  */
  YYSYMBOL_simple_type_decl = 113,         /* simple_type_decl  */
  YYSYMBOL_enum_decl = 114,                /* enum_decl  */
  YYSYMBOL_enum_list = 115,                /* enum_list  */
  YYSYMBOL_genset_decl = 116,              /* genset_decl  */
  YYSYMBOL_genset_modifiers = 117,         /* genset_modifiers  */
  YYSYMBOL_genset_details = 118,           /* genset_details  */
  YYSYMBOL_class_list = 119,               /* class_list  */
  YYSYMBOL_relation_decl = 120,            /* relation_decl  */
  YYSYMBOL_opt_relator_body = 121,         /* opt_relator_body  */
  YYSYMBOL_relation_body_opt = 122,        /* relation_body_opt  */
  YYSYMBOL_internal_relation_list = 123,   /* internal_relation_list  */
  YYSYMBOL_internal_relation = 124,        /* internal_relation  */
  YYSYMBOL_relation_meta = 125,            /* relation_meta  */
  YYSYMBOL_relation_stereotype = 126,      /* relation_stereotype  */
  YYSYMBOL_relation_arrow = 127,           /* relation_arrow  */
  YYSYMBOL_cardinality = 128               /* cardinality  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   346


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    79,    80,    84,    85,    86,    90,    91,
      95,    95,   102,   103,   107,   108,   112,   113,   114,   115,
     116,   117,   122,   122,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   144,   146,   147,   150,   152,   155,   157,   158,
     162,   163,   164,   168,   168,   168,   168,   168,   168,   169,
     172,   174,   179,   183,   187,   191,   192,   193,   199,   200,
     203,   205,   206,   207,   208,   212,   216,   217,   223,   227,
     231,   235,   236,   240,   241,   242,   246,   247,   252,   254,
     256,   260,   261,   265,   265,   265,   265,   265,   265,   266,
     266,   266,   266,   266,   266,   267,   267,   267,   267,   267,
     271,   271,   271,   271,   275,   276,   277,   278
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_PACKAGE",
  "T_IMPORT", "T_GENSET", "T_DISJOINT", "T_COMPLETE", "T_GENERAL",
  "T_SPECIFICS", "T_WHERE", "T_OF", "T_DATATYPE", "T_ENUM", "T_RELATION",
  "T_FUNCTIONAL_COMPLEXES", "T_RELATORS", "T_INTRINSIC_MODES",
  "T_EXTRINSIC_MODES", "T_QUALITIES", "T_MODES", "T_EVENTS",
  "T_SITUATIONS", "T_KIND", "T_SUBKIND", "T_ROLE", "T_PHASE", "T_CATEGORY",
  "T_MIXIN", "T_ROLEMIXIN", "T_PHASEMIXIN", "T_HISTORICALROLE",
  "T_HISTORICALROLEMIXIN", "T_COLLECTIVE", "T_QUANTITY", "T_QUALITY",
  "T_MODE", "T_INTRINSICMODE", "T_EXTRINSICMODE", "T_EVENT", "T_SITUATION",
  "T_PROCESS", "T_MATERIAL", "T_DERIVATION", "T_COMPARATIVE",
  "T_MEDIATION", "T_CHARACTERIZATION", "T_SUBCOLLECTIONOF",
  "T_SUBQUALITYOF", "T_INSTANTIATION", "T_EXTERNALDEPENDENCE",
  "T_COMPONENTOF", "T_MEMBEROF", "T_TERMINATION", "T_PARTICIPATIONAL",
  "T_PARTICIPATION", "T_HISTORICALDEPENDENCE", "T_CREATION",
  "T_MANIFESTATION", "T_BRINGSABOUT", "T_TRIGGERS", "T_COMPOSITION",
  "T_AGGREGATION", "T_INHERENCE", "T_VALUE", "T_FORMAL", "T_CONSTITUTION",
  "T_NUMBER_TYPE", "T_STRING_TYPE", "T_BOOLEAN_TYPE", "T_DATE_TYPE",
  "T_TIME_TYPE", "T_DATETIME_TYPE", "T_LBRACE", "T_RBRACE", "T_LPAREN",
  "T_RPAREN", "T_LBRACK", "T_RBRACK", "T_DOTDOT", "T_DIAMOND_ARROW",
  "T_ARROW_DIAMOND", "T_ASTERISK", "T_AT", "T_DOT", "T_COLON", "T_COMMA",
  "T_CLASS_NAME", "T_RELATION_NAME", "T_INSTANCE_NAME", "T_NEW_DATA_TYPE",
  "T_NUMBER_LITERAL", "$accept", "program", "declarations", "declaration",
  "import_decl", "package_decl", "$@1", "opt_body", "element_list",
  "element", "class_decl", "$@2", "class_stereotype", "opt_classification",
  "opt_specialization", "opt_class_body", "class_members", "attribute",
  "type_specifier", "opt_constraints", "datatype_decl", "simple_type_decl",
  "enum_decl", "enum_list", "genset_decl", "genset_modifiers",
  "genset_details", "class_list", "relation_decl", "opt_relator_body",
  "relation_body_opt", "internal_relation_list", "internal_relation",
  "relation_meta", "relation_stereotype", "relation_arrow", "cardinality", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -74,   -41,    79,    86,   -36,     7,     8,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   149,     9,   -80,
      97,    -3,   -80,   -80,   -80,   -80,   -80,    35,   -80,   -80,
     -80,   -80,   118,   -80,   -80,   -80,   -80,   -80,   -80,    56,
      57,    58,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   120,
      63,   -80,   -80,   126,    59,    68,   -80,   -80,    60,   -71,
     -80,    61,   -71,   208,   -80,     5,   148,   -80,   -69,   -80,
     -29,   149,   -80,   -30,   -80,   -25,    48,    10,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,    65,    62,   143,    76,
     -80,   -80,   -79,   -80,   -80,   -80,    69,   -80,   -80,   -80,
      66,    77,    64,   -80,   -80,    90,   -80,    81,    56,   -80,
     -80,    -7,    82,   -80,   -80,   150,   -80,   -80,   -23,    91,
     -80,   -80,   -80,   -80,    90,    44,   106,   110,   -80,   112,
     123,   188,   -80,   -80,   -80,   -80,   -80,   -80,   138,   -80,
     138,   -80,   -75,    90,   125,   -80,   -80,   128,   -80,   -80,
      62,   144,   -80,   -80,   135,   155,   129,   -80,   -80,    54,
     160,   -80,   -80,   -80,   -80,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      80,     0,     0,    81,    82,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    41,    42,    35,    36,
      37,    38,    39,    40,    32,    33,    34,     0,     0,    73,
       0,     2,     3,     6,     5,     7,    16,     0,    18,    21,
      19,    20,     0,    17,    10,     8,     9,    83,    84,    55,
       0,    92,   110,   108,   109,   103,   106,   119,   104,   105,
     118,   114,   113,   115,   116,   117,   111,   112,   107,     0,
       0,     1,     4,    51,     0,    13,    57,    72,    77,   102,
      89,     0,   102,     0,    22,     0,    80,    11,   102,    75,
       0,     0,   100,   102,    96,   127,    95,   102,    43,    44,
      45,    46,    47,    48,    49,    50,    52,     0,     0,    80,
      14,    56,   100,    58,    59,    74,     0,   101,    91,    97,
       0,     0,     0,    57,    88,   127,    90,     0,    55,    86,
      78,     0,     0,    12,    15,     0,    62,    76,     0,     0,
     122,   120,   121,   123,   127,   102,     0,    53,    23,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    70,    69,
      70,   124,     0,   127,     0,    94,    93,     0,    87,    85,
       0,     0,    61,    60,     0,     0,     0,    98,    54,     0,
       0,   126,   125,    99,    79,    71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   204,   -80,   -80,   -80,   -80,   -80,   -68,
     -80,   -80,   -80,   -80,   -80,   111,   119,   -80,   -80,    83,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,    71,   -80,   -80,
     -80,   162,    45,   -80,   154,   -80,    -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    30,    31,    32,    33,    34,    75,    87,   109,    35,
      36,   106,    37,    84,   128,    77,    88,   113,   160,   172,
      38,    39,    40,    90,    41,    42,   130,   131,    43,    80,
     124,    93,    94,    95,    69,   144,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       1,     2,   -80,     3,     4,   111,   135,   174,   136,     5,
       6,     7,    91,    44,    91,   107,   175,    92,   110,   112,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     1,
       2,   134,     3,     4,   118,   115,    45,    46,     5,     6,
       7,    49,   120,    91,   121,   161,   162,   116,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   108,   149,
      27,   150,     3,     4,   126,    28,    47,    29,     5,     6,
       7,   125,    48,    91,    50,    51,    70,    71,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   165,    27,
     146,   123,    73,    74,    28,   120,    29,    91,   184,    76,
      78,    79,   112,   114,    81,  -127,    82,    83,   119,   164,
     149,    86,   119,   140,   141,   142,    85,    89,    96,   129,
     133,   132,   143,   127,     3,     4,   137,   138,   176,    27,
       5,     6,     7,    52,    28,   139,    29,   120,   147,   151,
     163,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     114,    53,    54,   166,    55,    56,   167,   170,    57,   168,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     169,   171,   177,   181,    68,   178,   183,   152,   153,   154,
     155,   156,   157,    98,    99,   100,   101,   102,   103,   104,
     105,    27,   180,   182,   185,    72,    28,   158,    29,   148,
     159,   179,   145,   173,    97,   117
};

static const yytype_uint8 yycheck[] =
{
       3,     4,     5,     6,     7,    74,    85,    82,    87,    12,
      13,    14,    83,    87,    83,    10,    91,    88,    86,    88,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     3,
       4,   109,     6,     7,    74,    74,    87,    88,    12,    13,
      14,    87,    77,    83,    79,    78,    79,    86,    88,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    73,    86,
      83,    88,     6,     7,    74,    88,     7,    90,    12,    13,
      14,    96,     6,    83,    87,    87,    87,     0,    88,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    74,    83,
     125,    73,    87,     5,    88,    77,    90,    83,    74,    73,
      73,    73,    88,    88,    14,    87,    73,    11,    93,   144,
      86,    73,    97,    79,    80,    81,    87,    87,    87,    87,
      74,     8,    88,    88,     6,     7,    87,    91,   163,    83,
      12,    13,    14,    14,    88,    88,    90,    77,    87,    87,
      79,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     145,    42,    43,    87,    45,    46,    86,     9,    49,    87,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      87,    73,    87,    78,    65,    87,    87,    67,    68,    69,
      70,    71,    72,    15,    16,    17,    18,    19,    20,    21,
      22,    83,    88,    78,    74,    31,    88,    87,    90,   128,
      90,   170,   123,   160,    82,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,    12,    13,    14,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    83,    88,    90,
      93,    94,    95,    96,    97,   101,   102,   104,   112,   113,
     114,   116,   117,   120,    87,    87,    88,     7,     6,    87,
      87,    87,    14,    42,    43,    45,    46,    49,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    65,   126,
      87,     0,    95,    87,     5,    98,    73,   107,    73,    73,
     121,    14,    73,    11,   105,    87,    73,    99,   108,    87,
     115,    83,    88,   123,   124,   125,    87,   123,    15,    16,
      17,    18,    19,    20,    21,    22,   103,    10,    73,   100,
     101,    74,    88,   109,   124,    74,    86,   126,    74,   124,
      77,    79,   128,    73,   122,   128,    74,    88,   106,    87,
     118,   119,     8,    74,   101,    85,    87,    87,    91,    88,
      79,    80,    81,    88,   127,   108,   128,    87,   107,    86,
      88,    87,    67,    68,    69,    70,    71,    72,    87,    90,
     110,    78,    79,    79,   128,    74,    87,    86,    87,    87,
       9,    73,   111,   111,    82,    91,   128,    87,    87,   119,
      88,    78,    78,    87,    74,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    95,    95,    96,    96,
      98,    97,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   103,   102,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   106,   107,   107,   108,   108,   108,
     109,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   112,   113,   114,   115,   115,   115,   116,   116,
     117,   117,   117,   117,   117,   118,   119,   119,   120,   120,
     120,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   128,   128,   128,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     2,
       0,     4,     3,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     0,     2,     4,     0,     3,     0,     2,     2,
       4,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     3,     1,     5,     1,     3,     0,     5,     9,
       0,     1,     1,     2,     2,     3,     1,     3,     5,     3,
       5,     3,     0,     3,     3,     0,     1,     2,     5,     6,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     5,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 10: /* $@1: %empty  */
#line 95 "parser.y"
                           { 
        current_package = (yyvsp[0].sval); 
        packages.push_back((yyvsp[0].sval));
    }
#line 1388 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 22: /* $@2: %empty  */
#line 122 "parser.y"
                                                     { register_class((yyvsp[-1].sval)); }
#line 1394 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 72: /* datatype_decl: T_DATATYPE T_CLASS_NAME opt_class_body  */
#line 179 "parser.y"
                                           { count_datatypes++; }
#line 1400 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 73: /* simple_type_decl: T_NEW_DATA_TYPE  */
#line 183 "parser.y"
                    { count_datatypes++; }
#line 1406 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 74: /* enum_decl: T_ENUM T_CLASS_NAME T_LBRACE enum_list T_RBRACE  */
#line 187 "parser.y"
                                                    { count_enums++; register_class((yyvsp[-3].sval)); }
#line 1412 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 78: /* genset_decl: genset_modifiers T_GENSET T_CLASS_NAME T_WHERE genset_details  */
#line 199 "parser.y"
                                                                  { count_gensets++; }
#line 1418 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 79: /* genset_decl: genset_modifiers T_GENSET T_CLASS_NAME T_LBRACE T_GENERAL T_CLASS_NAME T_SPECIFICS class_list T_RBRACE  */
#line 200 "parser.y"
                                                                                                             { count_gensets++; }
#line 1424 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 88: /* relation_decl: T_AT relation_stereotype T_RELATION T_CLASS_NAME relation_body_opt  */
#line 223 "parser.y"
                                                                       {
        register_external_relation((yyvsp[-1].sval));
    }
#line 1432 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;

  case 89: /* relation_decl: T_RELATION T_CLASS_NAME opt_relator_body  */
#line 227 "parser.y"
                                               {
        register_external_relation((yyvsp[-1].sval));
    }
#line 1440 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"
    break;


#line 1444 "/home/tacioplays/Compiladores/TontoAnalyzer/Build/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 281 "parser.y"


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
