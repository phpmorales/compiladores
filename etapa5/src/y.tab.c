/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 11 "tool/parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>

#include "../include/gv.h"      
#include "../include/tac.h"  
#include "../include/semantic.h"           
#include "../include/ast.h"
#include "../include/hash.h"

//#define YYDEBUG 1
int yyerror( char* str );
ast_t *ast;
ast_t *root;
tac_t *tac;

extern int getLineNumber( void );
extern int isRunning( void );
extern int yylex( );
       

#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UNDEFINED = 0,
    OPERATOR_AND = 274,
    OPERATOR_OR = 275,
    KW_THEN = 262,
    KW_ELSE = 263,
    OPERATOR_LE = 270,
    OPERATOR_GE = 271,
    OPERATOR_EQ = 272,
    OPERATOR_NE = 273,
    KW_WORD = 256,
    KW_BOOL = 258,
    KW_BYTE = 259,
    KW_IF = 261,
    KW_LOOP = 264,
    KW_INPUT = 266,
    KW_RETURN = 267,
    KW_OUTPUT = 268,
    TOKEN_ERROR = 290,
    LIT_INTEGER = 1,
    LIT_FLOATING = 2,
    LIT_TRUE = 3,
    LIT_FALSE = 4,
    LIT_CHAR = 5,
    LIT_STRING = 6,
    IDENTIFIER = 7
  };
#endif
/* Tokens.  */
#define UNDEFINED 0
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define KW_THEN 262
#define KW_ELSE 263
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define KW_WORD 256
#define KW_BOOL 258
#define KW_BYTE 259
#define KW_IF 261
#define KW_LOOP 264
#define KW_INPUT 266
#define KW_RETURN 267
#define KW_OUTPUT 268
#define TOKEN_ERROR 290
#define LIT_INTEGER 1
#define LIT_FLOATING 2
#define LIT_TRUE 3
#define LIT_FALSE 4
#define LIT_CHAR 5
#define LIT_STRING 6
#define IDENTIFIER 7

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 34 "tool/parser.y" /* yacc.c:355  */

	ast_t*   ast;
	hash_t   *symbol;
	

#line 188 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,    27,    28,    29,    30,    31,    32,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,    36,     2,    44,     2,
      39,    40,     8,     6,    41,     7,     2,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    34,
      16,     3,    17,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,    18,     2,    19,    20,
       2,    21,    10,    11,    22,     2,    23,    24,    25,     2,
      12,    13,    14,    15,     4,     5,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   150,   151,   154,   155,   158,   159,   160,
     163,   166,   167,   170,   176,   182,   189,   190,   193,   194,
     198,   202,   205,   206,   209,   213,   219,   220,   224,   227,
     228,   231,   232,   233,   234,   235,   236,   239,   242,   243,
     247,   250,   253,   254,   257,   258,   261,   264,   265,   266,
     269,   273,   274,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   302,   303,   306,   307,
     310,   313,   314,   317,   321,   325,   328,   331,   337,   338,
     339
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "UNDEFINED", "error", "$undefined", "'='", "OPERATOR_AND",
  "OPERATOR_OR", "'+'", "'-'", "'*'", "'/'", "KW_THEN", "KW_ELSE",
  "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_NE", "'<'", "'>'",
  "KW_WORD", "KW_BOOL", "KW_BYTE", "KW_IF", "KW_LOOP", "KW_INPUT",
  "KW_RETURN", "KW_OUTPUT", "TOKEN_ERROR", "LIT_INTEGER", "LIT_FLOATING",
  "LIT_TRUE", "LIT_FALSE", "LIT_CHAR", "LIT_STRING", "IDENTIFIER", "';'",
  "':'", "'$'", "'['", "']'", "'('", "')'", "','", "'{'", "'}'", "'&'",
  "'!'", "$accept", "prg_ini", "prg", "dcl_vr", "decl_type", "decl",
  "decl_cnt", "dcl_std", "dcl_ptr", "dcl_arr", "atrr_dcl_arr", "vr_lt",
  "dcl_fn", "dcl_t_fn", "prm_lst", "prm_lst_cnt", "blck", "cmd_lst", "cmd",
  "cmd_cnt", "in", "atrr", "ot", "ot_arg", "ot_arg_cnt", "if", "if_cmd",
  "rtn", "arr", "expr", "inv", "lst_vl", "prm", "prms", "vl", "dt_tp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   291,   292,    61,   274,   275,    43,    45,    42,    47,
     262,   263,   270,   271,   272,   273,    60,    62,   256,   258,
     259,   261,   264,   266,   267,   268,   290,     1,     2,     3,
       4,     5,     6,     7,    59,    58,    36,    91,    93,    40,
      41,    44,   123,   125,    38,    33
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-46)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -67,    24,    25,   -67,    11,   -67,   -67,   -67,   -67,    20,
     -67,   -67,   -67,    21,   -30,   -67,   -67,   -67,    29,    37,
     133,   122,    11,    40,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,    26,    46,   122,    62,
     -67,   258,    60,    71,   -67,    38,   133,   122,   122,   -67,
     -67,   215,   -67,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,    78,   122,   103,    82,    81,
     -67,   273,   185,    76,   -67,   -67,    44,   306,   317,    69,
     326,   332,   338,    75,   105,   168,    -9,   108,   133,   -67,
     229,    92,   104,   122,   143,    73,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,     6,    11,   -67,    82,   -67,   122,   -67,
     -67,   133,   -67,   -67,   122,   101,   293,    28,   -67,   199,
      97,   107,   122,   -67,   -67,   -67,   -67,   244,   -67,   143,
     -67,   -67,   -67,    73,   -67,   293,    -6,   -67,   -67,   -67,
     -67,   -67,   103,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     6,     1,    21,     3,    88,    90,    89,     0,
       7,     8,     9,    12,     0,     5,    11,    10,     0,     0,
       0,     0,    23,     0,    83,    84,    85,    86,    87,    13,
      77,    56,    57,    58,    59,    60,    52,     0,     0,     0,
      76,     0,     0,     0,    22,     0,     0,     0,    79,    53,
      55,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,    39,    27,     0,
      14,     0,    82,     0,    78,    63,    74,    75,    64,    65,
      66,    67,    70,    71,    72,    73,    69,    68,     0,    15,
       0,     0,     0,     0,     0,    30,    36,    20,    31,    32,
      33,    34,    35,     0,     0,    24,    27,    51,     0,    80,
      61,    16,    18,    62,     0,    52,    50,    60,    41,    45,
       0,     0,     0,    26,    25,    81,    19,     0,    38,     0,
      42,    43,    28,    30,    29,    40,     0,    44,    37,    47,
      48,    49,    39,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,    39,    50,   -67,    13,   -66,   -67,
     -67,   -67,   -67,    15,    49,   -67,   -67,   -67,    42,   -21,
     -67,   -67,    51,   -67,   -44,   165
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     9,     5,    17,    10,    11,    12,
      89,   111,    13,    43,    44,   105,    96,   120,   121,   134,
      98,    99,   100,   118,   130,   101,   142,   102,    49,   103,
      42,    73,    74,   109,    29,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    97,    70,    18,   139,   140,    19,   -46,    64,   122,
      53,    54,    55,    56,    57,    58,   141,    51,    59,    60,
      61,    62,    63,    64,     3,    -2,    71,    72,   -45,     6,
       7,     8,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   112,    90,   -45,   -45,   -45,    54,
      55,    56,    57,    58,    15,    16,    59,    60,    61,    62,
      63,    64,   -45,    47,    20,    48,    21,   126,    22,   129,
      23,    68,   116,   119,    69,    46,   143,    57,    58,    50,
      30,    59,    60,    61,    62,    63,    64,    72,   -46,    61,
      62,    63,    64,   127,    91,    52,    92,    93,    94,    66,
      31,   135,    32,    33,    34,    35,    36,   -39,   119,    37,
      30,    67,    38,    88,   106,    95,   110,    39,    40,   -46,
      62,    63,    64,   104,    91,   -46,    92,    93,    94,    30,
      31,   114,    32,    33,    34,    35,    36,   115,    47,    37,
     132,   133,    38,   123,   137,    95,   138,    39,    40,    31,
      30,    32,    33,    34,    35,    36,   124,   128,    37,   125,
      24,    38,    25,    26,    27,    28,    39,    40,   131,    14,
      31,     0,    32,    33,    34,   117,    36,     0,     0,    37,
       0,     0,    38,   -46,    63,    64,     0,    39,    40,    53,
      54,    55,    56,    57,    58,     0,     0,    59,    60,    61,
      62,    63,    64,    53,    54,    55,    56,    57,    58,     0,
       0,    59,    60,    61,    62,    63,    64,     0,     0,    53,
      54,    55,    56,    57,    58,     0,   108,    59,    60,    61,
      62,    63,    64,    53,    54,    55,    56,    57,    58,     0,
     129,    59,    60,    61,    62,    63,    64,     0,    53,    54,
      55,    56,    57,    58,     0,    75,    59,    60,    61,    62,
      63,    64,    53,    54,    55,    56,    57,    58,     0,   113,
      59,    60,    61,    62,    63,    64,     0,    53,    54,    55,
      56,    57,    58,     0,   136,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,    65,    53,    54,    55,
      56,    57,    58,     0,     0,    59,    60,    61,    62,    63,
      64,   107,    55,    56,    57,    58,     0,     0,    59,    60,
      61,    62,    63,    64,    56,    57,    58,     0,     0,    59,
      60,    61,    62,    63,    64,    58,     0,     0,    59,    60,
      61,    62,    63,    64,    59,    60,    61,    62,    63,    64,
     -46,    60,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
      21,    67,    46,    33,    10,    11,    36,    16,    17,     3,
       4,     5,     6,     7,     8,     9,    22,    38,    12,    13,
      14,    15,    16,    17,     0,     0,    47,    48,     0,    18,
      19,    20,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    88,    66,    18,    19,    20,     5,
       6,     7,     8,     9,    34,    34,    12,    13,    14,    15,
      16,    17,    34,    37,    35,    39,    37,   111,    39,    41,
      33,    33,    93,    94,    36,    35,   142,     8,     9,    33,
       7,    12,    13,    14,    15,    16,    17,   108,    13,    14,
      15,    16,    17,   114,    21,    33,    23,    24,    25,    39,
      27,   122,    29,    30,    31,    32,    33,    34,   129,    36,
       7,    40,    39,    35,    33,    42,    40,    44,    45,    14,
      15,    16,    17,    41,    21,    17,    23,    24,    25,     7,
      27,    39,    29,    30,    31,    32,    33,    33,    37,    36,
      43,    34,    39,   104,   129,    42,   133,    44,    45,    27,
       7,    29,    30,    31,    32,    33,   106,   115,    36,   108,
      27,    39,    29,    30,    31,    32,    44,    45,   119,     4,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    36,
      -1,    -1,    39,    15,    16,    17,    -1,    44,    45,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    14,    15,    16,    17,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    41,    12,    13,    14,
      15,    16,    17,     4,     5,     6,     7,     8,     9,    -1,
      41,    12,    13,    14,    15,    16,    17,    -1,     4,     5,
       6,     7,     8,     9,    -1,    40,    12,    13,    14,    15,
      16,    17,     4,     5,     6,     7,     8,     9,    -1,    40,
      12,    13,    14,    15,    16,    17,    -1,     4,     5,     6,
       7,     8,     9,    -1,    40,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    38,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    14,    15,    16,
      17,    38,     6,     7,     8,     9,    -1,    -1,    12,    13,
      14,    15,    16,    17,     7,     8,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,     9,    -1,    -1,    12,    13,
      14,    15,    16,    17,    12,    13,    14,    15,    16,    17,
      12,    13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,    49,    51,    18,    19,    20,    50,
      53,    54,    55,    58,    81,    34,    34,    52,    33,    36,
      35,    37,    39,    33,    27,    29,    30,    31,    32,    80,
       7,    27,    29,    30,    31,    32,    33,    36,    39,    44,
      45,    75,    76,    59,    60,    81,    35,    37,    39,    74,
      33,    75,    33,     4,     5,     6,     7,     8,     9,    12,
      13,    14,    15,    16,    17,    38,    39,    40,    33,    36,
      80,    75,    75,    77,    78,    40,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    35,    56,
      75,    21,    23,    24,    25,    42,    62,    64,    66,    67,
      68,    71,    73,    75,    41,    61,    33,    38,    41,    79,
      40,    57,    80,    40,    39,    33,    75,    32,    69,    75,
      63,    64,     3,    60,    61,    78,    80,    75,    74,    41,
      70,    70,    43,    34,    65,    75,    40,    69,    63,    10,
      11,    22,    72,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      51,    52,    52,    53,    54,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    66,    66,
      67,    68,    69,    69,    70,    70,    71,    72,    72,    72,
      73,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    80,    80,    80,    81,    81,
      81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     0,     1,     1,     1,
       3,     1,     0,     4,     5,     6,     2,     0,     1,     2,
       6,     0,     1,     0,     3,     4,     2,     0,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     2,     3,     0,
       3,     2,     2,     2,     2,     0,     6,     1,     1,     1,
       2,     3,     0,     2,     2,     2,     1,     1,     1,     1,
       1,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     0,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 124 "tool/parser.y" /* yacc.c:1646  */
    {
                                                                  (yyval.ast) = astCreate(AST_PROGRAM_INI,0,(yyvsp[0].ast),0,0,0);
                                                                  root = (yyval.ast);  

                                                                  printf("\nCreating the AST...");
                                                                  //astPrintTree(root,0);
                                                                  printf("\nOk. AST was built!\n");

                                                                  printf("\n\nGenerating the copy of code...");
                                                                  decompile(root);
                                                                  printf("\nOk. Code generated!\n");

                                                                  printf("\n\nSearching for semantic erros...");
                                                                  //semanticSetDeclaration(root);
                                                                  //semanticCheckDeclaration(root);
                                                                  //semanticUtilization(root);
                                                                  printf("\nOk. No semantic errors found!\n");

                                                                  printf("\n\nGenerating the TAC: three address code...\n\n");
                                                                  tac = tacCodeGen(root);
                                                                  tacPrintList(tacReverse(tac));
                                                                  printf("\nOk. TAC generated!\n");
                                
                                                                }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PROGRAM,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 154 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_DEC,0,(yyvsp[-2].ast),(yyvsp[-1].ast),0,0); }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 155 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 158 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 159 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 163 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_DECL,0,(yyvsp[-2].ast),(yyvsp[-1].ast),0,0); }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 166 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 170 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_NDEC,(yyvsp[-2].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0,0); 
                                                                  (yyvsp[-2].symbol)->dataType = setDataType((yyvsp[-3].ast)->type);
                                                                }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 176 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_POINTER_DEC,(yyvsp[-2].symbol),(yyvsp[-4].ast),(yyvsp[0].ast),0,0); 
                                                                  (yyvsp[-2].symbol)->dataType = setDataType((yyvsp[-4].ast)->type);
                                                                }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 182 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_ARRAY_DEC,(yyvsp[-4].symbol),(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0);  
                                                                  (yyvsp[-4].symbol)->dataType = setDataType((yyvsp[-5].ast)->type);
                                                                }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 193 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_ATRR_LIT,0,(yyvsp[0].ast),0,0,0); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 194 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_ATRR_LIT,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 198 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_FUN_DEF,(yyvsp[-4].symbol),(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0); 
                                                                  (yyvsp[-4].symbol)->dataType = setDataType((yyvsp[-5].ast)->type);
                                                                }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 202 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 206 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 209 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_PARAM,(yyvsp[-1].symbol),(yyvsp[-2].ast),(yyvsp[0].ast),0,0); 
                                                                  (yyvsp[-1].symbol)->dataType = setDataType((yyvsp[-2].ast)->type);
                                                                }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 213 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_PARAM_REF,(yyvsp[-1].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0,0); 
                                                                  (yyvsp[-1].symbol)->dataType = setDataType((yyvsp[-3].ast)->type);
                                                                }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 219 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 220 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 224 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_BLOCK,0,(yyvsp[-1].ast),0,0,0); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 227 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LIST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 228 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 231 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 232 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 233 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 234 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 235 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 236 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 239 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LIST,0,(yyvsp[0].ast),0,0,0); }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 242 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_IN,(yyvsp[-1].symbol),0,(yyvsp[0].ast),0,0); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_ATRR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 250 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_OUT,0,(yyvsp[0].ast),0,0,0); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 253 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_OUT_ARG_STR,(yyvsp[-1].symbol),0,(yyvsp[0].ast),0,0); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 254 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_OUT_ARG,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 257 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_OUT_ARG,0,(yyvsp[0].ast),0,0,0); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 258 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 261 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_IF,0,(yyvsp[-3].ast),(yyvsp[-1].ast),(yyvsp[0].ast),0); }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 264 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_THEN,0,0,0,0,0); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 265 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_ELSE,0,0,0,0,0); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 266 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LOOP,0,0,0,0,0); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 269 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_RETURN,0,(yyvsp[0].ast),0,0,0); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 273 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_INDEX,0,(yyvsp[-1].ast),0,0,0); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 274 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 277 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[-1].symbol),(yyvsp[0].ast),0,0,0); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 278 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_POINTER_ADDR,(yyvsp[0].symbol),0,0,0,0); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 279 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_POINTER,(yyvsp[0].symbol),0,0,0,0); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 280 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 281 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 282 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 283 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 284 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 285 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_FUNC_CALL,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0); }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 286 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_INV_EXPR,0,(yyvsp[-3].ast),(yyvsp[-1].ast),0,0); }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 287 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PAR_EXPR,0,0,(yyvsp[-1].ast),0,0); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 288 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_ADD,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 289 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SUB,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 290 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_MUL,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 291 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_DIV,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 292 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_GREATER,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 293 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LESS,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 294 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 295 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_GE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 296 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_EQ,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 297 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_NE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 298 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_AND,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 299 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_OR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 302 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_BOOLEAN_INV,0,0,0,0,0); }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 303 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_ARIT_INV,0,0,0,0,0); }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 306 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 307 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 310 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PASS_PARAM,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 313 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PASS_PARAM,0,(yyvsp[0].ast),0,0,0); }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 314 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 317 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_LIT_INTEGER,(yyvsp[0].symbol),0,0,0,0); 
                                                                  (yyvsp[0].symbol)->dataType = DATATYPE_BYTE;
                                                                }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 321 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_LIT_TRUE,(yyvsp[0].symbol),0,0,0,0);
                                                                  (yyvsp[0].symbol)->dataType = DATATYPE_BOOL;
                                                                }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 325 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_LIT_FALSE,(yyvsp[0].symbol),0,0,0,0); 
                                                                  (yyvsp[0].symbol)->dataType = DATATYPE_BOOL;}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 328 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_LIT_CHAR,(yyvsp[0].symbol),0,0,0,0); 
                                                                  (yyvsp[0].symbol)->dataType = DATATYPE_WORD;}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 331 "tool/parser.y" /* yacc.c:1646  */
    { 
                                                                  (yyval.ast) = astCreate(AST_LIT_STRING,(yyvsp[0].symbol),0,0,0,0); 
                                                                  (yyvsp[0].symbol)->dataType = DATATYPE_WORD;
                                                                }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 337 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_WORD,0,0,0,0,0); }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 338 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_BYTE,0,0,0,0,0); }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 339 "tool/parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_BOOL,0,0,0,0,0); }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2017 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 342 "tool/parser.y" /* yacc.c:1906  */

 
 
int yyerror(char* str)
{
	fflush(stderr);
	fprintf(stderr,"ERRO: \"%s\"\t Linha: %d\n",str,getLineNumber());
	exit(3);
 
	//fprintf(stderr,"syntax error. \n");
	//exit(3);
 
}

