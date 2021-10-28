/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "micko.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0; //broj promenljivih u fji
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;
  int type; //tip promenljive
  int returned=0; // da li je naredba return upotrebljena
  //int assigned=1;
    int whenId = -1;

int konstanta = 5;
int parameter_cnt=0;
int reg=-1;
int args_cnt = 0;
int arg_value = 0;

#line 100 "micko.tab.c" /* yacc.c:339  */

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
   by #include "micko.tab.h".  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
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
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _ASSIGN = 269,
    _SEMICOLON = 270,
    _AROP = 271,
    _RELOP = 272,
    _COLON = 273,
    _COMMA = 274,
    _POSTINC = 275,
    _CHECK = 276,
    _WHEN = 277,
    _DEFAULT = 278,
    _BREAK = 279,
    _LOOP = 280,
    _QMARK = 281,
    ONLY_IF = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "micko.y" /* yacc.c:355  */

  int i;
  char *s;

#line 173 "micko.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "micko.tab.c" /* yacc.c:358  */

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
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    82,    84,    88,   100,   101,   106,   105,
     132,   138,   152,   154,   158,   157,   166,   168,   172,   187,
     207,   217,   219,   221,   225,   226,   227,   228,   229,   230,
     231,   235,   239,   249,   254,   258,   289,   332,   370,   372,
     377,   376,   393,   397,   411,   410,   431,   433,   437,   439,
     458,   460,   467,   473,   476,   485,   488,   494,   493,   519,
     521,   536,   540,   546,   549,   555,   560,   554,   575,   582,
     574,   596,   606,   616
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_RELOP", "_COLON",
  "_COMMA", "_POSTINC", "_CHECK", "_WHEN", "_DEFAULT", "_BREAK", "_LOOP",
  "_QMARK", "ONLY_IF", "$accept", "program", "global_variable_list",
  "global_variable", "function_list", "function", "$@1", "parameters",
  "parameter", "body", "$@2", "variable_list", "variables", "var_row",
  "statement_list", "statement", "compound_statement",
  "assignment_statement", "postincrement_statement", "postincrement",
  "loop_statement", "break", "check_statement", "$@3", "when_list", "when",
  "$@4", "default", "num_exp", "exp", "literal", "function_call", "$@5",
  "argument", "argument_list", "if_statement", "if_part", "@6", "$@7",
  "conditional_operator", "$@8", "$@9", "rel_exp", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -84,    20,     5,   -84,    31,   -84,    40,   -84,    42,    39,
     -84,   -84,    52,   -84,    65,    67,    74,    80,   -84,    89,
      85,    77,   -84,   -84,   -84,    95,    92,   -84,    44,   -84,
      86,     0,   -84,    94,    69,    93,    41,    25,   -84,   -84,
      96,    97,   -84,   -84,   -84,   -84,    90,   -84,   -84,   -84,
     103,   -84,   -84,    -5,   -84,   -84,    69,   -84,    98,   -84,
     -84,   -84,   -84,   -84,    55,    73,   -84,    48,   102,   104,
     -84,    10,   105,    13,    69,    69,   -84,    69,    70,   101,
     -84,   -84,    99,   -84,    69,   -84,   -84,    71,   -84,    17,
     106,   -84,   -84,   108,    81,    98,   -84,    -1,    69,   109,
      87,   100,   107,   -84,    69,    98,    10,   -84,   110,    81,
     -84,   -84,    69,    81,    72,   111,   112,   -84,   115,   116,
     111,   114,   113,   -84,    81,   118,   -84,    10,   -84,   -84,
     -84,     8,    69,    10,   -84,    10,    81,   -84,   -84,   -84,
     119,    10,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     6,     8,     0,
       7,     5,     0,     8,    12,     0,    13,     0,    10,     0,
       0,     0,    16,     9,    11,    14,     0,    22,     0,    17,
      18,     0,    21,     0,     0,     0,     0,     0,    22,    15,
       0,     0,    23,    24,    25,    27,     0,    29,    30,    26,
      63,    28,    20,    51,    55,    56,     0,    54,    19,    48,
      50,    52,    65,    73,     0,     0,    35,     0,     0,     0,
      34,     0,     0,     0,     0,     0,    72,     0,     0,     0,
      31,    40,     0,    64,    59,    53,    49,     0,    66,     0,
       0,    32,    33,     0,     0,    60,    61,     0,     0,     0,
       0,     0,     0,    58,    59,    71,     0,    68,     0,     0,
      62,    67,     0,     0,    46,    38,     0,    69,     0,     0,
      38,     0,     0,    42,     0,     0,    44,     0,    43,    41,
      39,     0,     0,     0,    47,     0,     0,    70,    45,    37,
       0,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   -84,   -84,   117,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,    83,   -69,   -84,   -84,   -84,   -31,
     -84,     2,   -84,   -84,   -84,    11,   -84,   -84,   -33,   -65,
     -83,   -84,   -84,    33,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,    47,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    16,    17,    23,
      27,    25,    28,    29,    31,    42,    43,    44,    45,    57,
      47,   123,    48,    93,   114,   115,   133,   121,    95,    59,
      60,    61,    72,    96,    97,    49,    50,    75,    99,    79,
     112,   125,    88,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    58,    83,    64,    35,   -57,    36,    37,     4,    86,
     103,   102,    38,    39,    35,    66,    36,    37,   104,   135,
       3,    40,    38,    73,    85,    41,   116,   136,    85,    74,
     118,    40,    78,    74,    98,    41,    46,   111,     8,    65,
      46,   131,    87,     9,    89,    66,    13,   117,    53,    54,
      55,    56,    35,   140,    36,    37,    63,    11,   134,    32,
      38,    80,    14,    33,   138,   105,   139,   137,    15,    40,
      76,    74,   142,    41,    18,    46,    53,    54,    55,    56,
      53,    54,    55,    77,    24,    91,    74,    74,    98,    54,
      55,    20,    21,    19,   113,   119,    46,    22,    26,    30,
      34,    52,    46,    62,    46,    70,    68,    69,    71,    81,
      46,    82,   108,   107,    74,    84,    92,   100,    94,   101,
     106,    67,   128,    10,    90,   120,   109,   129,   130,     0,
     141,   124,   113,   126,   127,   122,   132,   110
};

static const yytype_int16 yycheck[] =
{
      31,    34,    71,    36,     4,    10,     6,     7,     3,    74,
      11,    94,    12,    13,     4,    20,     6,     7,    19,    11,
       0,    21,    12,    56,    11,    25,   109,    19,    11,    16,
     113,    21,    65,    16,    17,    25,    67,   106,     7,    14,
      71,   124,    75,     3,    77,    20,     7,   112,     7,     8,
       9,    10,     4,   136,     6,     7,    15,    15,   127,    15,
      12,    13,    10,    19,   133,    98,   135,   132,     3,    21,
      15,    16,   141,    25,     7,   106,     7,     8,     9,    10,
       7,     8,     9,    10,     7,    15,    16,    16,    17,     8,
       9,    11,     3,    19,    22,    23,   127,    12,     3,     7,
      14,     7,   133,    10,   135,    15,    10,    10,     5,     7,
     141,     7,    12,    26,    16,    10,    15,    11,    19,    11,
      11,    38,   120,     6,    77,   114,    19,    13,    15,    -1,
      11,    19,    22,    18,    18,    24,    18,   104
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    30,     0,     3,    31,    32,    33,     7,     3,
      33,    15,    34,     7,    10,     3,    35,    36,     7,    19,
      11,     3,    12,    37,     7,    39,     3,    38,    40,    41,
       7,    42,    15,    19,    14,     4,     6,     7,    12,    13,
      21,    25,    43,    44,    45,    46,    47,    48,    50,    63,
      64,    71,     7,     7,     8,     9,    10,    47,    56,    57,
      58,    59,    10,    15,    56,    14,    20,    42,    10,    10,
      15,     5,    60,    56,    16,    65,    15,    10,    56,    67,
      13,     7,     7,    43,    10,    11,    57,    56,    70,    56,
      70,    15,    15,    51,    19,    56,    61,    62,    17,    66,
      11,    11,    58,    11,    19,    56,    11,    26,    12,    19,
      61,    43,    68,    22,    52,    53,    58,    57,    58,    23,
      53,    55,    24,    49,    19,    69,    18,    18,    49,    13,
      15,    58,    18,    54,    43,    11,    19,    57,    43,    43,
      58,    11,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    32,    32,    34,    33,
      35,    35,    36,    36,    38,    37,    39,    39,    40,    40,
      40,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    44,    45,    45,    46,    47,    48,    48,    49,    49,
      51,    50,    52,    52,    54,    53,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    58,    58,    60,    59,    61,
      61,    62,    62,    63,    63,    65,    66,    64,    68,    69,
      67,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     0,     7,
       2,     4,     0,     1,     0,     5,     0,     2,     2,     4,
       3,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     2,     2,    13,    11,     0,     2,
       0,     9,     2,     3,     0,     5,     0,     3,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     0,     5,     0,
       1,     1,     3,     1,     3,     0,     0,     7,     0,     0,
       9,     3,     3,     2
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
#line 76 "micko.y" /* yacc.c:1646  */
    {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1371 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 89 "micko.y" /* yacc.c:1646  */
    {
    if(lookup_symbol((yyvsp[-1].s), GVAR) == NO_INDEX)
      insert_symbol((yyvsp[-1].s), GVAR, (yyvsp[-2].i), NO_ATR, NO_ATR);
    else 
      err("redefinition of '%s'", (yyvsp[-1].s));
    
    code("\n%s:", (yyvsp[-1].s));
    code("\n\tWORD 1");
  }
#line 1385 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "micko.y" /* yacc.c:1646  */
    {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));

        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
        parameter_cnt = 0;
      }
#line 1402 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "micko.y" /* yacc.c:1646  */
    {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
       	returned = 0;
      }
#line 1417 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "micko.y" /* yacc.c:1646  */
    {
     int idx = insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++parameter_cnt, NO_ATR);
        set_atr1(fun_idx, parameter_cnt);
        set_atr2(fun_idx, get_atr2(fun_idx) * 10 + (yyvsp[-1].i));
  }
#line 1427 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "micko.y" /* yacc.c:1646  */
    {
    int idx = lookup_symbol((yyvsp[0].s), PAR);
    if(idx != NO_INDEX)
      err("param alredy defined");
    
        idx = insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++parameter_cnt, NO_ATR);
   set_atr1(fun_idx, parameter_cnt);
      set_atr2(fun_idx, get_atr2(fun_idx) * 10 + (yyvsp[-1].i));
  }
#line 1441 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "micko.y" /* yacc.c:1646  */
    { set_atr1(fun_idx, 0); }
#line 1447 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "micko.y" /* yacc.c:1646  */
    {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1457 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 173 "micko.y" /* yacc.c:1646  */
    {
      
        if(lookup_symbol((yyvsp[0].s), VAR|PAR) == NO_INDEX)
           insert_symbol((yyvsp[0].s), VAR, (yyvsp[-1].i), ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[0].s));
	
	if( (yyvsp[-1].i) == VOID)
	   err("Variable type can't be void");

        type = (yyvsp[-1].i); //cuvamo tip promenljive da bismo u nekoj od sledecih promenljivih u tom redu mogli da pristupimo tom tipu

    }
#line 1475 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 188 "micko.y" /* yacc.c:1646  */
    {
	if(lookup_symbol((yyvsp[-2].s), VAR|PAR) == NO_INDEX)
           insert_symbol((yyvsp[-2].s), VAR, (yyvsp[-3].i), ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[-2].s));
	
	if( (yyvsp[-3].i) == VOID)
	   err("Variable type can't be void");
       
	if((yyvsp[-3].i)!=get_type((yyvsp[0].i)))
	  err("Incompatible variable types in assignment");

	int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR);
        gen_mov((yyvsp[0].i), idx);   //smesta literal u promenljivu,generise mov naredbu
	
        int temp = lookup_symbol((yyvsp[-2].s),VAR|PAR);
	set_atr2(temp,5);

	}
#line 1499 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 208 "micko.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].s), VAR|PAR) == NO_INDEX)
           insert_symbol((yyvsp[0].s), VAR, type, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[0].s));
      }
#line 1510 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 240 "micko.y" /* yacc.c:1646  */
    {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-3].s));
        else
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1524 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 259 "micko.y" /* yacc.c:1646  */
    {
    	  int idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|FUN);

    if(idx == NO_INDEX)
      err("operand '%s' not defined in increment", (yyvsp[-1].s));

    if(get_kind(idx) == FUN)
    {
		  err("increment can't be called on function");
    }

    int registar = take_reg();

    gen_mov(idx, registar);

    if(get_type(idx) == INT) //za int ide sufiks s
      code("\n\t\tADDS\t");
    else
      code("\n\t\tADDU\t");
    
    gen_sym_name(idx);

    code(", $1, ");
    gen_sym_name(idx);

	  (yyval.i)=registar;
  }
#line 1556 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 290 "micko.y" /* yacc.c:1646  */
    {
    int idx = lookup_symbol((yyvsp[-10].s), VAR|PAR);
      if(idx == NO_INDEX)
        err("invalid value '%s' in loop", (yyvsp[-10].s));

    
    
    if(get_type(idx) != get_type((yyvsp[-8].i)))
      err("incompatible types in loop statement ");
    
    if(get_type(idx) != get_type((yyvsp[-6].i)))
      err("incompatible types in loop statement");

   if(get_type(idx) != get_type((yyvsp[-4].i)))
      err("incompatible types in loop statement");

     if(get_type(idx) != get_type((yyvsp[-2].i)))
      err("incompatible types in loop statement");

    code("\n@loop_statement%d: ", ++lab_num);
      //$<i>$ = lab_num;
       
      gen_mov((yyvsp[-8].i), idx);   //smesta literal u promenljivu
      code("\n@loop_cmp%d: ", lab_num);
      gen_cmp(idx, (yyvsp[-6].i));
      code("\n\t\tJLES @loop_exit%d", lab_num);
      code("\n@loop_statement%d: ", lab_num);

    
    if(get_type(idx) == INT)
      code("\n\t\tSUBS\t");
    else
      code("\n\t\tSUBU\t");
    
    gen_sym_name(idx);
    code(", $%d, ", (yyvsp[-2].i));
    gen_sym_name(idx);


    code("\n\t\tJMP\t@loop_cmp%d", lab_num);
    code("\n@loop_exit%d: ", lab_num);	
  }
#line 1603 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 333 "micko.y" /* yacc.c:1646  */
    {
    int idx = lookup_symbol((yyvsp[-8].s), VAR|PAR);
      if(idx == NO_INDEX)
        err("invalid value '%s' in loop", (yyvsp[-8].s));
    
    if(get_type(idx) != get_type((yyvsp[-6].i)))
      err("incompatible types in loop statement ");
    
    if(get_type(idx) != get_type((yyvsp[-4].i)))
      err("incompatible types in loop statement");

   if(get_type(idx) != get_type((yyvsp[-2].i)))
      err("incompatible types in loop statement");

  gen_mov((yyvsp[-6].i), idx);   //smesta literal u promenljivu
      code("\n@loop_cmp%d: ", lab_num);
      gen_cmp(idx, (yyvsp[-4].i));
      code("\n\t\tJLES @loop_exit%d", lab_num);
      code("\n@loop_statement%d: ", lab_num);

    
    if(get_type(idx) == INT)
      code("\n\t\tADDS\t");
    else
      code("\n\t\tADDU\t");
    
    gen_sym_name(idx);
    code(", $%d, ", (yyvsp[-2].i));
    gen_sym_name(idx);


    code("\n\t\tJMP\t@loop_cmp%d", lab_num);
    code("\n@loop_exit%d: ", lab_num);
	
  }
#line 1643 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 377 "micko.y" /* yacc.c:1646  */
    {
    int idx = lookup_symbol((yyvsp[0].s), VAR|PAR);
    if(idx == NO_INDEX)
      err("invalid lvalue '%s' in check statement", (yyvsp[0].s));
    
    whenId = idx;
        code("\n@checkStart%d:", whenId);
  }
#line 1656 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 387 "micko.y" /* yacc.c:1646  */
    {
    code("\n@checkEnd%d:", whenId);
  }
#line 1664 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 394 "micko.y" /* yacc.c:1646  */
    {
    (yyval.i) = (yyvsp[-1].i);
  }
#line 1672 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 398 "micko.y" /* yacc.c:1646  */
    {
    int lit1 = atoi(get_name((yyvsp[-2].i)));


    int lit2 = atoi(get_name((yyvsp[-1].i)));

    if(lit1 == lit2)
      err("repeated literal in check ");
  }
#line 1686 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 411 "micko.y" /* yacc.c:1646  */
    {
    if(get_type(whenId) != get_type((yyvsp[-1].i)))
      err("invalid expresion in when");
    
    int lit1 = atoi(get_name((yyvsp[-1].i)));
    code("\n@check%d_when%d:", whenId, lit1);
    gen_cmp(whenId, (yyvsp[-1].i));
    code("\n\t\tJEQ\t@check%d_statement%d", whenId, lit1);
code("\n\t\tJMP\t@check%d_statement%d_exit", whenId, lit1);
    code("\n@check%d_statement%d:", whenId, lit1);
    
 }
#line 1703 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 422 "micko.y" /* yacc.c:1646  */
    {
	    int lit1 = atoi(get_name((yyvsp[-3].i)));

    code("\n@check%d_statement%d_exit:", whenId, lit1);
    code("\n\t\tJMP\t@checkEnd%d", whenId);
    (yyval.i) = (yyvsp[-3].i);
  }
#line 1715 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 440 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
        int t1 = get_type((yyvsp[-2].i));    
        code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 1735 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 461 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1745 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 468 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      }
#line 1754 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 474 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1760 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 477 "micko.y" /* yacc.c:1646  */
    {
    (yyval.i) = (yyvsp[0].i);
  }
#line 1768 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 486 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1774 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 489 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1780 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 494 "micko.y" /* yacc.c:1646  */
    {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1790 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 500 "micko.y" /* yacc.c:1646  */
    {
        if(get_atr1(fcall_idx) != args_cnt)
          err("wrong number of arguments");
           if(get_atr2(fcall_idx) != arg_value)
          err("wrong types of arguments");


        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
          if(args_cnt > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", args_cnt * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
         args_cnt = 0;
        arg_value = 0;
      }
#line 1810 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 519 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 1816 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 522 "micko.y" /* yacc.c:1646  */
    { 
     // if(get_atr2(fcall_idx) != get_type($1))
      //  err("incompatible type for argument");
      free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
        gen_sym_name((yyvsp[0].i));
       arg_value = arg_value * 10 + get_type((yyvsp[0].i));
      args_cnt++;
    
      (yyval.i) = 1;
    }
#line 1832 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 537 "micko.y" /* yacc.c:1646  */
    {
    (yyval.i) = (yyvsp[0].i);
  }
#line 1840 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 541 "micko.y" /* yacc.c:1646  */
    {
    (yyval.i) = (yyvsp[0].i);
  }
#line 1848 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 547 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[0].i)); }
#line 1854 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 550 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 1860 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 555 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 1869 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 560 "micko.y" /* yacc.c:1646  */
    {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
        code("\n@true%d:", (yyvsp[-1].i));
      }
#line 1878 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 565 "micko.y" /* yacc.c:1646  */
    {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 1888 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 575 "micko.y" /* yacc.c:1646  */
    {
    int label = ++lab_num;
    int reg = take_reg();
    code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[-2].i)], lab_num); 
    code("\n@true%d:", lab_num);
  }
#line 1899 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 582 "micko.y" /* yacc.c:1646  */
    {
    gen_mov((yyvsp[0].i), reg);
    code("\nJMP\t\t@exit%d",lab_num);
    code("\n@false%d:", lab_num);
  }
#line 1909 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 588 "micko.y" /* yacc.c:1646  */
    {
    gen_mov((yyvsp[0].i), reg);
    code("\n@exit%d:", lab_num);
    (yyval.i) = reg;
  }
#line 1919 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 597 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 1930 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 607 "micko.y" /* yacc.c:1646  */
    {
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
	if(get_type(fun_idx) == VOID)
      		err("function of type void should not return value");
        returned=1;
        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
#line 1944 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 617 "micko.y" /* yacc.c:1646  */
    {
	if(get_type(fun_idx)!=VOID )
      		err("function of that type must have return value");
       returned=1;
      }
#line 1954 "micko.tab.c" /* yacc.c:1646  */
    break;


#line 1958 "micko.tab.c" /* yacc.c:1646  */
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
#line 624 "micko.y" /* yacc.c:1906  */


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

