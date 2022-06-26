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
#line 1 "semantic.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int func_cnt = -1;
  int main_found = FALSE;
  char* func_name;

  char* arops_str[] = { "+", "-", "*", "/" };
  char* relops_str[] = { "<", ">", "<=", ">=", "==", "!=" };

#line 91 "semantic.tab.c" /* yacc.c:339  */

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
   by #include "semantic.tab.h".  */
#ifndef YY_YY_SEMANTIC_TAB_H_INCLUDED
# define YY_YY_SEMANTIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 26 "semantic.y" /* yacc.c:355  */

  typedef struct ast_node {
    char* name;
    unsigned type;
    unsigned kind;
    struct ast_node* children[256];
    int children_cnt;
    int func_ordinal;
  } AST_NODE;

  typedef struct display_node {
    AST_NODE* node;
    int depth;
    int is_last;
  } DISPLAY;

  AST_NODE* build_node(char* name, unsigned type, unsigned kind, unsigned children_cnt);
  AST_NODE* root;
  DISPLAY* build_display_node(AST_NODE* node, int depth);
  void print_tree(void);
  void do_semantic_analysis(AST_NODE* node);
  unsigned get_node_type(AST_NODE* node);
  void assign(AST_NODE* node);
  void arop_relop(AST_NODE* node);

#line 147 "semantic.tab.c" /* yacc.c:355  */

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
    ONLY_IF = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 52 "semantic.y" /* yacc.c:355  */

  int i;
  char *s;
  AST_NODE* n;

#line 184 "semantic.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "semantic.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   57

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  63

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

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
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    91,    92,   102,   115,   118,   125,   136,
     139,   159,   167,   170,   190,   191,   192,   193,   197,   204,
     215,   216,   226,   227,   231,   232,   239,   243,   250,   260,
     263,   267,   271,   282,   292,   302
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_RELOP", "ONLY_IF",
  "$accept", "program", "function_list", "function", "parameter", "body",
  "variable_list", "variable", "statement_list", "statement",
  "compound_statement", "assignment_statement", "num_exp", "exp",
  "literal", "function_call", "argument", "if_statement", "if_part",
  "rel_exp", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,     6,    25,     0,   -43,     5,   -43,   -43,    34,    31,
      28,   -43,    29,   -43,   -43,    37,    35,   -43,     4,    30,
      33,    26,    32,   -43,   -43,   -43,   -43,   -43,   -43,    39,
     -43,   -43,    26,    38,   -43,   -43,    26,   -10,   -43,   -43,
     -43,    26,    16,    20,     2,    36,    26,    -9,   -43,    26,
      15,   -43,   -43,    26,    20,    40,    41,   -43,   -43,   -43,
      40,   -43,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     6,     0,
       0,     7,     0,     9,     5,    12,     0,    10,     0,     0,
       0,     0,     0,    12,     8,    13,    14,    15,    16,    31,
      17,    11,     0,    23,    26,    27,     0,     0,    20,    22,
      24,     0,     0,     0,     0,     0,    29,     0,    35,     0,
       0,    18,    32,     0,     0,    30,     0,    25,    21,    19,
      34,    33,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -43,    46,   -43,   -43,   -43,   -43,    27,   -42,
     -43,   -43,   -32,     8,   -43,   -43,   -43,   -43,   -43,   -43,
     -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    14,    15,    17,    18,    25,
      26,    27,    37,    38,    39,    40,    56,    28,    29,    45,
      30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    52,    57,     1,    47,    48,    49,    49,    20,    50,
      21,    22,    61,     5,    55,     8,    23,    24,    49,    53,
      20,    60,    21,    22,    20,     6,    21,    22,    23,    51,
      59,    49,    23,    33,    34,    35,    36,     9,    11,    12,
      16,    13,    19,    32,    43,    31,    41,    54,    46,     7,
      42,     0,    62,     0,     0,     0,    49,    58
};

static const yytype_int8 yycheck[] =
{
      32,    43,    11,     3,    36,    15,    16,    16,     4,    41,
       6,     7,    54,     7,    46,    10,    12,    13,    16,    17,
       4,    53,     6,     7,     4,     0,     6,     7,    12,    13,
      15,    16,    12,     7,     8,     9,    10,     3,     7,    11,
       3,    12,     7,    10,     5,    15,    14,    11,    10,     3,
      23,    -1,    11,    -1,    -1,    -1,    16,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    22,     7,     0,    22,    10,     3,
      23,     7,    11,    12,    24,    25,     3,    26,    27,     7,
       4,     6,     7,    12,    13,    28,    29,    30,    36,    37,
      39,    15,    10,     7,     8,     9,    10,    31,    32,    33,
      34,    14,    27,     5,    31,    38,    10,    31,    15,    16,
      31,    13,    28,    17,    11,    31,    35,    11,    32,    15,
      31,    28,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    19,    20,    21,    21,    22,    23,    23,    24,    25,
      25,    26,    27,    27,    28,    28,    28,    28,    29,    30,
      31,    31,    32,    32,    32,    32,    33,    33,    34,    35,
      35,    36,    36,    37,    38,    39
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     0,     2,     4,     0,
       2,     3,     0,     2,     1,     1,     1,     1,     3,     4,
       1,     3,     1,     1,     1,     3,     1,     1,     4,     0,
       1,     1,     3,     5,     3,     3
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
#line 85 "semantic.y" /* yacc.c:1646  */
    {
      root = (yyvsp[0].n);
    }
#line 1318 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("functions", NO_TYPE, FUNCTIONS, 2);
      node -> children[0] = (yyvsp[-1].n);
      node -> children[1] = (yyvsp[0].n);
      (yyval.n) = node;
    }
#line 1329 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node((yyvsp[-4].s), (yyvsp[-5].i), FUN, 3);   
      node -> children[0] = (yyvsp[-2].n);
      node -> children[1] = (yyvsp[0].n) -> children[0];
      node -> children[2] = (yyvsp[0].n) -> children[1];
      node -> func_ordinal = ++func_cnt;
      (yyval.n) = node;
    }
#line 1342 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = NULL;
    }
#line 1350 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 119 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = build_node((yyvsp[0].s), (yyvsp[-1].i), PAR, 0);
    }
#line 1358 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("", NO_TYPE, NO_KIND, 2);
      node -> children[0] = (yyvsp[-2].n);
      node -> children[1] = (yyvsp[-1].n);
      (yyval.n) = node; 
    }
#line 1369 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = NULL;
    }
#line 1377 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 140 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("variables", NO_TYPE, VARIABLES, 1);
      AST_NODE* previous = (yyvsp[-1].n);
      if (previous == NULL) {
        node -> children[0] = (yyvsp[0].n);
      }
      else {
        int num_children = (previous -> children_cnt) + 1;
        node -> children_cnt = num_children;
        for (int i = 0; i < num_children - 1; i++) {
          (node -> children)[i] = (previous -> children)[i];
        }
        (node -> children)[num_children - 1] = (yyvsp[0].n);
      }
      (yyval.n) = node;
    }
#line 1398 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = build_node((yyvsp[-1].s), (yyvsp[-2].i), DECL, 0);
    }
#line 1406 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = NULL;
    }
#line 1414 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 171 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("statements", NO_TYPE, STATEMENTS, 1);
      AST_NODE* previous = (yyvsp[-1].n);
      if (previous == NULL) {
        node -> children[0] = (yyvsp[0].n);
      }
      else {
        int num_children = (previous -> children_cnt) + 1;
        node -> children_cnt = num_children;
        for (int i = 0; i < num_children - 1; i++) {
          (node -> children)[i] = (previous -> children)[i];
        }
        (node -> children)[num_children - 1] = (yyvsp[0].n);
      }
      (yyval.n) = node;
    }
#line 1435 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = (yyvsp[-1].n);
    }
#line 1443 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 205 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("=", NO_TYPE, ASSIGN, 2);
      AST_NODE* left = build_node((yyvsp[-3].s), NO_TYPE, VAR|PAR, 0);
      node -> children[0] = left;
      node -> children[1] = (yyvsp[-1].n);
      (yyval.n) = node;
    }
#line 1455 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 217 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node(arops_str[(yyvsp[-1].i)], NO_TYPE, AROP, 2);
      node -> children[0] = (yyvsp[-2].n);
      node -> children[1] = (yyvsp[0].n);
      (yyval.n) = node;
    }
#line 1466 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = build_node((yyvsp[0].s), NO_TYPE, VAR|PAR, 0);
    }
#line 1474 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 233 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = (yyvsp[-1].n);
    }
#line 1482 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 240 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = build_node((yyvsp[0].s), INT, LIT, 0);
    }
#line 1490 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 244 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = build_node((yyvsp[0].s), UINT, LIT, 0);
    }
#line 1498 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 251 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node((yyvsp[-3].s), NO_TYPE, FUN_CALL, 1);
      node -> children[0] = (yyvsp[-1].n);
      (yyval.n) = node;
    }
#line 1508 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 260 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = NULL;
    }
#line 1516 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 268 "semantic.y" /* yacc.c:1646  */
    {
      (yyval.n) = (yyvsp[0].n);
    }
#line 1524 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 272 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("if", NO_TYPE, IF, 3);
      node -> children[0] = (yyvsp[-2].n) -> children[0];
      node -> children[1] = (yyvsp[-2].n) -> children[1];
      node -> children[2] = (yyvsp[0].n);
      (yyval.n) = node;
    }
#line 1536 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 283 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("if", NO_TYPE, IF, 2);
      node -> children[0] = (yyvsp[-2].n);
      node -> children[1] = (yyvsp[0].n);
      (yyval.n) = node;
    }
#line 1547 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 293 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node(relops_str[(yyvsp[-1].i)], NO_TYPE, RELOP, 2);
      node -> children[0] = (yyvsp[-2].n);
      node -> children[1] = (yyvsp[0].n);
      (yyval.n) = node;
    }
#line 1558 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 303 "semantic.y" /* yacc.c:1646  */
    {
      AST_NODE* node = build_node("return", NO_TYPE, RETURN, 1);
      node -> children[0] = (yyvsp[-1].n);
      (yyval.n) = node;
    }
#line 1568 "semantic.tab.c" /* yacc.c:1646  */
    break;


#line 1572 "semantic.tab.c" /* yacc.c:1646  */
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
#line 310 "semantic.y" /* yacc.c:1906  */


AST_NODE* build_node(char* name, unsigned type, unsigned kind, unsigned children_cnt) {
  AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
  node -> name = name;
  node -> type = type;
  node -> kind = kind;
  node -> children_cnt = children_cnt;
  return node;
}

DISPLAY* build_display_node(AST_NODE* node, int depth) {
  DISPLAY* display_node = (DISPLAY*) malloc(sizeof(DISPLAY));
  display_node -> node = node;
  display_node -> depth = depth;
  return display_node;
}

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

// TODO: check this
unsigned get_node_type(AST_NODE* node) {
  if ((node -> type) != NO_TYPE)
    return node -> type;
  if ((node -> kind) & (VAR|PAR)) {
    int i = lookup_symbol(node -> name, VAR|PAR);
    if (i == NO_INDEX) err("Undeclared %s", node -> name);
    // if (get_atr1(i) != func_cnt) err("Undeclared %s", node -> name);
    else return get_type(i);
  }
  if ((node -> kind) & FUN_CALL) {
    int i = lookup_symbol(node -> name, FUN);
    unsigned func_type = get_type(i);
    return func_type;
  }
  if (node -> children_cnt == 0) return NO_TYPE;
  unsigned types[(node -> children_cnt) + 1];
  unsigned first_type = get_node_type((node -> children)[0]);
  for (int i = 1; i < node -> children_cnt; i++) {
    unsigned next_type = get_node_type((node -> children)[i]); 
    if (next_type != first_type) 
      err("Mismatching types! %d and %d (%s)", first_type, next_type, node -> name);
  }
  return first_type;
}

void print_node(DISPLAY* display_node, int flags[]) {
  AST_NODE* node = display_node -> node;
  int depth = display_node -> depth;
  if (node == NULL) return;
  for (int i = 1; i < depth; i++) {
    if (flags[i] == TRUE) printf("|    ");
    else printf("     ");
  } 

  if (depth == 0) {
    printf("\033[1;32m");
    printf("%s\n", node -> name);
    printf("\033[0m");
  }
  else if (display_node -> is_last) {
    printf("+--- ");
    printf("\033[1;32m");
    printf("%s\n", node -> name);
    printf("\033[0m");
    flags[depth] = FALSE;
  }

  else {
    printf("+--- ");
    printf("\033[1;32m");
    printf("%s\n", node -> name);
    printf("\033[0m");
  }

  for (int i = 0; i < node -> children_cnt; i++)
  {
    AST_NODE* next = ((node -> children)[i]);
    DISPLAY* next_display = build_display_node(next, depth + 1);
    if (i == (node -> children_cnt) - 1) next_display -> is_last = TRUE;
    else next_display -> is_last = FALSE;
    print_node(next_display, flags);
  }
  flags[depth] = TRUE;
}

void print_tree(void) {
  DISPLAY* display_node = build_display_node(root, 0);
  display_node -> is_last = TRUE; 
  int flags[256];
  for (int i = 0; i < 100; i++) flags[i] = TRUE;
  print_node(display_node, flags);
}

void declaration(AST_NODE* node) {
  int i = lookup_symbol(node -> name, VAR);
  if (i != NO_INDEX && get_atr1(i) == func_cnt) 
    err("Variable %s redeclared!", node -> name);
  insert_symbol(node -> name, VAR, node -> type, func_cnt, NO_ATR);
}

void func_declaration(AST_NODE* node) {
  if(lookup_symbol(node -> name, FUN) != NO_INDEX) 
    err("Function %s redeclared!", node -> name);
  AST_NODE* param = (node -> children)[0];
  func_name = node -> name;
  if (strcmp(func_name, "main") == 0) main_found = TRUE;
  if (param == NULL) {
    insert_symbol(node -> name, FUN, node -> type, 0, NO_ATR);
  } else {
    insert_symbol(node -> name, FUN, node -> type, 1, param -> type);
    insert_symbol(param -> name, PAR, param -> type, ++func_cnt, NO_ATR);
  }
}

void assign(AST_NODE* node) {
  AST_NODE* left = (node -> children)[0];
  AST_NODE* right = (node -> children)[1];
  if (get_node_type(left) != get_node_type(right))
    err("Mismatching types in assign!  %s  %s", left -> name, right -> name);
  if (!((left -> kind) & VAR|PAR))
    err("Invalid left side of assignement! %d", left -> kind);
}

void arop_relop(AST_NODE* node) {
  AST_NODE* left = (node -> children)[0];
  AST_NODE* right = (node -> children)[1];
  // printf("%s %d  %s %d\n", left -> name,  left -> type, right -> name, right -> type);
  if (get_node_type(left) != get_node_type(right))
    err("Mismatching types!");
}

// TODO: ako nema return a treba
void return_stm(AST_NODE* node) {
  int i = lookup_symbol(func_name, FUN);
  unsigned func_type = get_type(i);
  unsigned return_type = get_node_type(node);
  if (func_type != return_type)
    err("Invalid return value!");
}

void variable(AST_NODE* node) {
  int i = lookup_symbol(node -> name, VAR|PAR);
  if (i == NO_INDEX)
    err("Variable %s not declared!", node -> name);
  printf("%d  %d", get_atr1(i), func_cnt);
  printf("aaaaaaa");
  if (get_atr1(i) != func_cnt)
    err("Variable %s not declared!", node -> name);
}

void func_call(AST_NODE* node) {
  int i = lookup_symbol(node -> name, FUN);
  if (i == NO_INDEX) 
    err("Function %s not declared!", node -> name);
  AST_NODE* arg = (node -> children)[0];
  int num_params = get_atr1(i);
  if (num_params == 1) {
    if (arg == NULL) err("Mismatching number of arguments!");
    unsigned param_type = get_atr2(i);
    unsigned arg_type = get_node_type(arg);
    if (arg_type != param_type)
      err("Mismatching arg types! %d  %d", arg_type, param_type);
  }
  else if (arg != NULL)
    err("Mismatching number of arguments:!");
}

void first_pass(AST_NODE* node) {
  if (node == NULL) return;
  switch (node -> kind) {
    case DECL:
    declaration(node);
    break;

    case FUN:
    func_declaration(node);
    break;
  }
  for (int i = 0; i < node -> children_cnt; i++) {
    first_pass((node -> children)[i]);
  }
}

void do_semantic_analysis(AST_NODE* node) {
  if (node == NULL) return;
  if (node -> kind == FUN) {
    func_name = node -> name;
    func_cnt = node -> func_ordinal;
  }
  for (int i = 0; i < node -> children_cnt; i++) {
    do_semantic_analysis((node -> children)[i]);
  }
  switch (node -> kind) {
    case ASSIGN:
    assign(node);
    break;

    case AROP:
    case RELOP:
    arop_relop(node);
    break;

    case VAR:
    variable(node);
    break;

    case FUN_CALL:
    func_call(node);
    break;

    case RETURN:
    return_stm(node);
    break;
  }
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();
  func_cnt = -1;
  print_tree();
  first_pass(root);
  do_semantic_analysis(root);
  if (!main_found)
    err("No main function!");

  clear_symtab();
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr)
    return -1; //syntax error
  else
    return error_count; //semantic errors
}
