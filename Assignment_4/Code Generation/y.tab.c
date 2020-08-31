/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
//#include "SymbolTable.h"
#include "SymbolInfo.h"

#define YYSTYPE SymbolInfo*

using namespace std;

extern int yylex();
void yyerror(const char *s);
extern FILE *yyin;
extern int line_count;
extern int error;


int labelCount=0;
int tempCount=0;


char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}

//SymbolTable *table= new SymbolTable(31);


/* Line 371 of yacc.c  */
#line 118 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     FOR = 260,
     WHILE = 261,
     DO = 262,
     INT = 263,
     FLOAT = 264,
     DOUBLE = 265,
     CHAR = 266,
     RETURN = 267,
     VOID = 268,
     BREAK = 269,
     SWITCH = 270,
     CASE = 271,
     DEFAULT = 272,
     CONTINUE = 273,
     ADDOP = 274,
     MULOP = 275,
     ASSIGNOP = 276,
     RELOP = 277,
     LOGICOP = 278,
     SEMICOLON = 279,
     COMMA = 280,
     LPAREN = 281,
     RPAREN = 282,
     LCURL = 283,
     RCURL = 284,
     LTHIRD = 285,
     RTHIRD = 286,
     INCOP = 287,
     DECOP = 288,
     CONST_INT = 289,
     CONST_FLOAT = 290,
     ID = 291,
     NOT = 292,
     PRINTLN = 293,
     MAIN = 294,
     THEN = 295
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define INT 263
#define FLOAT 264
#define DOUBLE 265
#define CHAR 266
#define RETURN 267
#define VOID 268
#define BREAK 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define ADDOP 274
#define MULOP 275
#define ASSIGNOP 276
#define RELOP 277
#define LOGICOP 278
#define SEMICOLON 279
#define COMMA 280
#define LPAREN 281
#define RPAREN 282
#define LCURL 283
#define RCURL 284
#define LTHIRD 285
#define RTHIRD 286
#define INCOP 287
#define DECOP 288
#define CONST_INT 289
#define CONST_FLOAT 290
#define ID 291
#define NOT 292
#define PRINTLN 293
#define MAIN 294
#define THEN 295



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 264 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNRULES -- Number of states.  */
#define YYNSTATES  98

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    14,    18,    21,    26,    30,    32,
      34,    38,    45,    47,    52,    54,    57,    59,    61,    69,
      75,    83,    89,    95,    99,   101,   104,   106,   111,   113,
     117,   119,   123,   125,   129,   131,   135,   137,   141,   144,
     147,   149,   151,   155,   157,   159
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,     8,    39,    26,    27,    43,    -1,    28,
      44,    47,    29,    -1,    28,    47,    29,    -1,    28,    29,
      -1,    44,    45,    46,    24,    -1,    45,    46,    24,    -1,
       8,    -1,     9,    -1,    46,    25,    36,    -1,    46,    25,
      36,    30,    34,    31,    -1,    36,    -1,    36,    30,    34,
      31,    -1,    48,    -1,    47,    48,    -1,    49,    -1,    43,
      -1,     5,    26,    49,    49,    51,    27,    48,    -1,     3,
      26,    51,    27,    48,    -1,     3,    26,    51,    27,    48,
       4,    48,    -1,     6,    26,    51,    27,    48,    -1,    38,
      26,    36,    27,    24,    -1,    12,    51,    24,    -1,    24,
      -1,    51,    24,    -1,    36,    -1,    36,    30,    51,    31,
      -1,    52,    -1,    50,    21,    52,    -1,    53,    -1,    53,
      23,    53,    -1,    54,    -1,    54,    22,    54,    -1,    55,
      -1,    54,    19,    55,    -1,    56,    -1,    55,    20,    56,
      -1,    19,    56,    -1,    37,    56,    -1,    57,    -1,    50,
      -1,    26,    51,    27,    -1,    34,    -1,    35,    -1,    50,
      32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    73,    80,    86,    95,   103,   111,   116,
     123,   129,   135,   141,   156,   161,   171,   176,   181,   195,
     211,   217,   224,   230,   238,   244,   251,   258,   272,   277,
     299,   304,   323,   328,   361,   366,   384,   389,   412,   418,
     427,   434,   454,   459,   464,   469
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "INT", "FLOAT", "DOUBLE", "CHAR", "RETURN", "VOID", "BREAK", "SWITCH",
  "CASE", "DEFAULT", "CONTINUE", "ADDOP", "MULOP", "ASSIGNOP", "RELOP",
  "LOGICOP", "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LCURL", "RCURL",
  "LTHIRD", "RTHIRD", "INCOP", "DECOP", "CONST_INT", "CONST_FLOAT", "ID",
  "NOT", "PRINTLN", "MAIN", "THEN", "$accept", "Program",
  "compound_statement", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    44,    45,    45,
      46,    46,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     2,     4,     3,     1,     1,
       3,     6,     1,     4,     1,     2,     1,     1,     7,     5,
       7,     5,     5,     3,     1,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     2,     0,
       0,     0,     8,     9,     0,     0,    24,     0,     5,    43,
      44,    26,     0,     0,    17,     0,     0,     0,    14,    16,
      41,     0,    28,    30,    32,    34,    36,    40,     0,     0,
       0,     0,    41,    38,     0,     0,    39,     0,     0,     0,
      12,     0,     4,    15,     0,    45,    25,     0,     0,     0,
       0,     0,     0,     0,    23,    42,     0,     0,     0,     3,
       0,     7,     0,    29,    31,    35,    33,    37,     0,     0,
       0,    27,     0,     6,     0,    10,    19,     0,    21,    22,
      13,     0,     0,     0,     0,    20,    18,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    24,    25,    26,    51,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int16 yypact[] =
{
      -1,   -29,    13,    -5,   -34,    -8,    -4,    49,   -34,    -3,
       4,     5,   -34,   -34,    45,    45,   -34,    45,   -34,   -34,
     -34,     2,    45,     8,   -34,    85,     3,   112,   -34,   -34,
     -18,    17,   -34,    19,   -10,    27,   -34,   -34,    45,     1,
      45,    24,    18,   -34,    29,    45,   -34,    23,     3,   139,
      30,    -9,   -34,   -34,    45,   -34,   -34,    45,    45,    45,
      45,    35,     1,    36,   -34,   -34,    38,    43,    -7,   -34,
      40,   -34,    53,   -34,   -34,    27,    57,   -34,   166,    45,
     166,   -34,    48,   -34,    61,    65,    92,    71,   -34,   -34,
     -34,    66,   166,   166,    68,   -34,   -34,   -34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,    95,   -34,    77,    55,    80,   -27,   -33,   -14,
     -12,    52,    50,    51,    54,   -11,   -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      53,    42,    41,    54,    43,    44,    62,     1,    42,    58,
       3,    46,    59,     4,    55,    71,    72,    83,    72,     6,
      15,     5,    53,    38,     7,    16,    61,    17,    63,    79,
      39,    40,    45,    66,    47,    19,    20,    21,    22,    50,
      42,    56,    57,    42,    42,    42,    42,    60,    64,    77,
      55,    86,     9,    88,    10,    11,    65,    12,    13,    67,
      70,    14,    78,    80,    15,    95,    96,    87,    15,    81,
      82,    17,    89,    16,    84,    17,    58,     7,    18,    19,
      20,    21,    22,    19,    20,    21,    22,    23,     9,    85,
      10,    11,    90,    12,    13,    91,    92,    14,    93,    97,
      94,     8,    48,    68,    15,    49,    73,    74,     0,    16,
      76,    17,    75,     7,     0,     9,     0,    10,    11,    19,
      20,    21,    22,    23,    14,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,     0,    17,     0,
       7,    52,     9,     0,    10,    11,    19,    20,    21,    22,
      23,    14,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    16,     0,    17,     0,     7,    69,     9,
       0,    10,    11,    19,    20,    21,    22,    23,    14,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,     0,    17,     0,     7,     0,     0,     0,     0,     0,
      19,    20,    21,    22,    23
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-34)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      27,    15,    14,    21,    15,    17,    39,     8,    22,    19,
      39,    22,    22,     0,    32,    24,    25,    24,    25,    27,
      19,    26,    49,    26,    28,    24,    38,    26,    40,    62,
      26,    26,    30,    45,    26,    34,    35,    36,    37,    36,
      54,    24,    23,    57,    58,    59,    60,    20,    24,    60,
      32,    78,     3,    80,     5,     6,    27,     8,     9,    36,
      30,    12,    27,    27,    19,    92,    93,    79,    19,    31,
      27,    26,    24,    24,    34,    26,    19,    28,    29,    34,
      35,    36,    37,    34,    35,    36,    37,    38,     3,    36,
       5,     6,    31,     8,     9,    30,     4,    12,    27,    31,
      34,     6,    25,    48,    19,    25,    54,    57,    -1,    24,
      59,    26,    58,    28,    -1,     3,    -1,     5,     6,    34,
      35,    36,    37,    38,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    24,    -1,    26,    -1,
      28,    29,     3,    -1,     5,     6,    34,    35,    36,    37,
      38,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    24,    -1,    26,    -1,    28,    29,     3,
      -1,     5,     6,    34,    35,    36,    37,    38,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      24,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    42,    39,     0,    26,    27,    28,    43,     3,
       5,     6,     8,     9,    12,    19,    24,    26,    29,    34,
      35,    36,    37,    38,    43,    44,    45,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    26,    26,
      26,    51,    50,    56,    51,    30,    56,    26,    45,    47,
      36,    46,    29,    48,    21,    32,    24,    23,    19,    22,
      20,    51,    49,    51,    24,    27,    51,    36,    46,    29,
      30,    24,    25,    52,    53,    55,    54,    56,    27,    49,
      27,    31,    27,    24,    34,    36,    48,    51,    48,    24,
      31,    30,     4,    27,    34,    48,    48,    31
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    {
			cout << "\nProgram : INT MAIN LPAREN RPAREN compound_statement\n";
			// insert appropriate data segment register initialization code and others like main proc
			(yyval)=(yyvsp[(5) - (5)]);
			ofstream fout;
			fout.open("code.asm");
			fout << (yyval)->code;
			cout << endl;
			
		}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {
							cout << "\ncompound_statement : LCURL var_declaration statements RCURL\n";
							(yyval)=(yyvsp[(3) - (4)]);
							(yyval)->code=(yyvsp[(2) - (4)])->code+(yyvsp[(3) - (4)])->code;
							cout << endl;
						}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 81 "parser.y"
    {
							cout << "\ncompound_statement : LCURL statements RCURL\n";
							(yyval)=(yyvsp[(2) - (3)]);
							cout << endl;
						}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
    {
							cout << "\ncompound_statement	: LCURL RCURL\n";
							(yyval)=new SymbolInfo("compound_statement","dummy");
							cout << endl;
						}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    {
						cout << "\nvar_declaration : type_specifier declaration_list SEMICOLON\n";
						(yyval)=(yyvsp[(1) - (4)]);
						(yyval)->code+=(yyvsp[(3) - (4)])->code;
						cout << endl;
						delete (yyvsp[(2) - (4)]);
					}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    {
						cout << "\nvar_declaration : type_specifier declaration_list SEMICOLON\n";
						(yyval)=(yyvsp[(2) - (3)]);
						cout << endl;
						delete (yyvsp[(1) - (3)]);
					}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 111 "parser.y"
    {
				cout << "\ntype_specifier : INT\n";
				(yyval)= new SymbolInfo("int","type");
				cout << endl;
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    {
				cout << "\ntype_specifier : FLOAT\n";
				(yyval)= new SymbolInfo("int","type");
				cout << endl;
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {
						cout << "\ndeclaration_list : declaration_list COMMA ID\n";
						(yyval)=(yyvsp[(1) - (3)]);
						/* should be easy */
						cout << endl;
					}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 129 "parser.y"
    {
						cout << "\ndeclaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n"  ;
						(yyval)=(yyvsp[(1) - (6)]);
						/* should be easy */
						cout << endl;
					}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    {
						cout << "\ndeclaration_list : ID\n"  << (yyvsp[(1) - (1)])->getSymbol() << endl;
						(yyval)=new SymbolInfo((yyvsp[(1) - (1)]));
						(yyval)->code=string((yyvsp[(1) - (1)])->getSymbol())+" dw " + "?\n";
						cout << endl;
					}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    {
						cout << "\ndeclaration_list : ID LTHIRD CONST_INT RTHIRD\n"  << (yyvsp[(1) - (4)])->getSymbol() << endl;
						(yyval)=new SymbolInfo((yyvsp[(1) - (4)]));
						int length;
						sscanf((yyvsp[(3) - (4)])->getSymbol(),"%d",&length);
						cout << length << endl;
						(yyval)->code=string((yyvsp[(1) - (4)])->getSymbol())+" dw ";
						for(int i=0;i<length-1;i++){
							(yyval)->code += "?, " ;
						}
						(yyval)->code+="?\n";
						cout << endl;
					}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {
				cout << "\nstatements : statement\n";
				(yyval)=(yyvsp[(1) - (1)]);
				cout << endl;
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {
				cout << "\nstatements : statements statement\n";
				(yyval)=(yyvsp[(1) - (2)]);
				(yyval)->code += (yyvsp[(2) - (2)])->code;
				delete (yyvsp[(2) - (2)]);
				cout << endl;
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    {
					cout << "\nstatement : expression_statement\n";
					(yyval)=(yyvsp[(1) - (1)]);
					cout << endl;
				}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    {
					cout << "\nstatement : compound_statement\n";
					(yyval)=(yyvsp[(1) - (1)]);
					cout << endl;
				}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 181 "parser.y"
    {
					cout << "\nstatement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n";
					
					/*
						$1's code at first, which is already done by assigning $$=$1
						create two labels and append one of them in $$->code
						compare $4's symbol with 1
						if not equal jump to 2nd label
						append $7's code
						append second label in the code
					*/
					
					cout << endl;
				}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    {
					cout << "\nstatement : IF LPAREN expression RPAREN statement\n";
					
					(yyval)=(yyvsp[(3) - (5)]);
					
					char *label=newLabel();
					(yyval)->code+="mov ax, "+string((yyvsp[(3) - (5)])->getSymbol())+"\n";
					(yyval)->code+="cmp ax, 1\n";
					(yyval)->code+="jne "+string(label)+"\n";
					(yyval)->code+=(yyvsp[(5) - (5)])->code;
					(yyval)->code+=string(label)+":\n";
					
					(yyval)->setSymbol("if");//not necessary
					
					cout << endl;
				}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 211 "parser.y"
    {
					cout << "\nstatement : IF LPAREN expression RPAREN statement ELSE statement\n";
					(yyval)=(yyvsp[(1) - (7)]);
					//similar to if part
					cout << endl;
				}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    {
					cout << "\nstatement : WHILE LPAREN expression RPAREN statement\n";
					(yyval)=(yyvsp[(3) - (5)]);
					
					// should be easy given you understood or implemented for loops part
					cout << endl;
				}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    {
					cout << "\nstatement : PRINTLN LPAREN ID RPAREN SEMICOLON\n";
					// write code for printing an ID. You may assume that ID is not an integer variable.
					(yyval)=new SymbolInfo("println","nonterminal");
					cout << endl;
				}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 230 "parser.y"
    {
					cout << "\nstatement : RETURN expression SEMICOLON\n";
					// write code for dos return.
					(yyval)=(yyvsp[(1) - (3)]);
					cout << endl;
				}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 238 "parser.y"
    {
							cout << "\nexpression_statement : SEMICOLON\n";
							(yyval)=new SymbolInfo(";","SEMICOLON");
							(yyval)->code="";
							cout << endl;
						}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 244 "parser.y"
    {
							cout << "\nexpression_statement : expression SEMICOLON\n";
							(yyval)=(yyvsp[(1) - (2)]);
							cout << endl;
						}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 251 "parser.y"
    {
				cout << "\nvariable : ID\n" << (yyvsp[(1) - (1)])->getSymbol() << endl;
				
				(yyval)= new SymbolInfo((yyvsp[(1) - (1)]));
				
				cout << endl;
		}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 258 "parser.y"
    {
				
				cout << "\nvariable : ID LTHIRD expression RTHIRD\n"  << (yyvsp[(1) - (4)])->getSymbol() << endl;
				
				(yyval)= new SymbolInfo((yyvsp[(1) - (4)]));
				
				(yyval)->code=(yyvsp[(3) - (4)])->code;
				(yyval)->arrIndexHolder=string((yyvsp[(3) - (4)])->getSymbol());
				
				delete (yyvsp[(3) - (4)]);
				cout << endl;
		}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 272 "parser.y"
    {
			cout << "\nexpression : logic_expression\n";
			(yyval)= (yyvsp[(1) - (1)]);
			cout << endl;
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 277 "parser.y"
    {
				cout << "\nexpression : variable ASSIGNOP logic_expression\n";
				(yyval)=(yyvsp[(1) - (3)]);
				(yyval)->code=(yyvsp[(3) - (3)])->code+(yyvsp[(1) - (3)])->code;
				(yyval)->code+="mov ax, "+string((yyvsp[(3) - (3)])->getSymbol())+"\n";
				if((yyval)->arrIndexHolder==""){ //actualy it is more appropriate to use arrayLength to make decision
					(yyval)->code+= "mov "+string((yyvsp[(1) - (3)])->getSymbol())+", ax\n";
				}
				
				else{
					(yyval)->code+="lea di, " + string((yyvsp[(1) - (3)])->getSymbol())+"\n";
					for(int i=0;i<2;i++){
						(yyval)->code += "add di, " + (yyvsp[(1) - (3)])->arrIndexHolder +"\n";
					}
					(yyval)->code+= "mov [di], ax\n";
					(yyval)->arrIndexHolder="";
				}
				delete (yyvsp[(3) - (3)]);
				cout << endl;
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 299 "parser.y"
    {
					cout << "\nlogic_expression : rel_expression\n";
					(yyval)= (yyvsp[(1) - (1)]);
					cout << endl;			
				}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 304 "parser.y"
    {
					cout << "\nlogic_expression : rel_expression LOGICOP rel_expression\n";
					(yyval)=(yyvsp[(1) - (3)]);
					(yyval)->code+=(yyvsp[(3) - (3)])->code;
					
					if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"&&")==0){
						/* 
						Check whether both operands value is 1. If both are one set value of a temporary variable to 1
						otherwise 0
						*/
					}
					else if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"||")==0){
						
					}
					delete (yyvsp[(3) - (3)]);
					cout << endl;
				}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 323 "parser.y"
    {
				cout << "\nrel_expression : simple_expression\n";
				(yyval)= (yyvsp[(1) - (1)]);
				cout << endl;
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 328 "parser.y"
    {
				cout << "\nrel_expression : simple_expression RELOP simple_expression\n";
				(yyval)=(yyvsp[(1) - (3)]);
				(yyval)->code+=(yyvsp[(3) - (3)])->code;
				(yyval)->code+="mov ax, " + string((yyvsp[(1) - (3)])->getSymbol())+"\n";
				(yyval)->code+="cmp ax, " + string((yyvsp[(3) - (3)])->getSymbol())+"\n";
				char *temp=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"<")==0){
					(yyval)->code+="jl " + string(label1)+"\n";
				}
				else if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"<=")==0){
				}
				else if(strcmp((yyvsp[(2) - (3)])->getSymbol(),">")==0){
				}
				else if(strcmp((yyvsp[(2) - (3)])->getSymbol(),">=")==0){
				}
				else if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"==")==0){
				}
				else{
				}
				
				(yyval)->code+="mov "+string(temp) +", 0\n";
				(yyval)->code+="jmp "+string(label2) +"\n";
				(yyval)->code+=string(label1)+":\nmov "+string(temp)+", 1\n";
				(yyval)->code+=string(label2)+":\n";
				(yyval)->setSymbol(temp);
				delete (yyvsp[(3) - (3)]);
				cout << endl;
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 361 "parser.y"
    {
				cout << "\nsimple_expression : term\n";
				(yyval)= (yyvsp[(1) - (1)]);
				cout << endl;
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 366 "parser.y"
    {
				cout << "\nsimple_expression : simple_expression ADDOP term\n";
				(yyval)=(yyvsp[(1) - (3)]);
				(yyval)->code+=(yyvsp[(3) - (3)])->code;
				
				// move one of the operands to a register, perform addition or subtraction with the other operand and move the result in a temporary variable  
				
				if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"+")==0){
				
				}
				else{
				
				}
				delete (yyvsp[(3) - (3)]);
				cout << endl;
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 384 "parser.y"
    {
						cout << "\nterm : unary_expression\n";
						(yyval)= (yyvsp[(1) - (1)]);
						cout << endl;
					}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 389 "parser.y"
    {
						cout << "\nterm : term MULOP unary_expression\n";
						(yyval)=(yyvsp[(1) - (3)]);
						(yyval)->code += (yyvsp[(3) - (3)])->code;
						(yyval)->code += "mov ax, "+ string((yyvsp[(1) - (3)])->getSymbol())+"\n";
						(yyval)->code += "mov bx, "+ string((yyvsp[(3) - (3)])->getSymbol()) +"\n";
						char *temp=newTemp();
						if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"*")==0){
							(yyval)->code += "mul bx\n";
							(yyval)->code += "mov "+ string(temp) + ", ax\n";
						}
						else if(strcmp((yyvsp[(2) - (3)])->getSymbol(),"/")==0){
							// clear dx, perform 'div bx' and mov ax to temp
						}
						else{
							// clear dx, perform 'div bx' and mov dx to temp
						}
						(yyval)->setSymbol(temp);
						delete (yyvsp[(3) - (3)]);
						cout << endl;
					}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 412 "parser.y"
    {
							cout << "\nunary_expression : ADDOP unary_expression\n";
							(yyval)=(yyvsp[(2) - (2)]);
							// Perform NEG operation if the symbol of ADDOP is '-'
							cout << endl;
						}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 418 "parser.y"
    {
							cout << "\nunary_expression : NOT unary_expression\n";
							(yyval)=(yyvsp[(2) - (2)]);
							char *temp=newTemp();
							(yyval)->code="mov ax, " + string((yyvsp[(2) - (2)])->getSymbol()) + "\n";
							(yyval)->code+="not ax\n";
							(yyval)->code+="mov "+string(temp)+", ax";
							cout << endl;
						}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 427 "parser.y"
    {
							cout << "\nunary_expression : factor\n";
							(yyval)=(yyvsp[(1) - (1)]);
							cout << endl;
						}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 434 "parser.y"
    {
			cout << "\nfactor : variable\n";
			(yyval)= (yyvsp[(1) - (1)]);
			
			if((yyval)->arrIndexHolder==""){//actualy it is better use arrayLength to make decision
				
			}
			
			else{
				(yyval)->code+="lea di, " + string((yyvsp[(1) - (1)])->getSymbol())+"\n";
				for(int i=0;i<2;i++){
					(yyval)->code += "add di, " + (yyvsp[(1) - (1)])->arrIndexHolder +"\n";
				}
				char *temp= newTemp();
				(yyval)->code+= "mov " + string(temp) + ", [di]\n";
				(yyval)->setSymbol(temp);
				(yyval)->arrIndexHolder="";
			}
			cout << endl;
		}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 454 "parser.y"
    {
			cout << "\nfactor : LPAREN expression RPAREN\n";
			(yyval)= (yyvsp[(2) - (3)]);
			cout << endl;
		}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 459 "parser.y"
    {
			cout << "\nfactor : CONST_INT\n" <<  (yyvsp[(1) - (1)])->getSymbol() << endl;
			(yyval)= (yyvsp[(1) - (1)]);
			cout << endl;
		}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 464 "parser.y"
    {
			cout << "\nfactor : CONST_FLOAT\n" <<  (yyvsp[(1) - (1)])->getSymbol() <<  endl;
			(yyval)= (yyvsp[(1) - (1)]);
			cout << endl;
		}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 469 "parser.y"
    {
			cout << "\nfactor : variable INCOP\n";
			(yyval)=(yyvsp[(1) - (2)]);
			(yyval)->code += "inc " + string((yyvsp[(1) - (2)])->getSymbol()) + "\n";
			cout << endl;
		}
    break;


/* Line 1792 of yacc.c  */
#line 2154 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 478 "parser.y"



void yyerror(const char *s){
	cout << "Error at line no " << line_count << " : " << s << endl;
}

int main(int argc, char * argv[]){
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	

	yyin= fin;
	yyparse();
	cout << endl;
	cout << endl << "\t\tsymbol table: " << endl;
	//table->dump();
	
	printf("\nTotal Lines: %d\n",line_count);
	printf("\nTotal Errors: %d\n",error);
	
	printf("\n");
	return 0;
}
