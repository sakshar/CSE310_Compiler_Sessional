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
#line 1 "1305002.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "new_SymbolTable.h"
#include "1305002_SymbolTable.h"
//#include "1305002_optimizer.cpp"
#define YYSTYPE symbolInfo*
//int yydebug;
int yyparse(void);
int yylex(void);
double var[26];
//symbolTable** table = (symbolTable**)malloc(2*sizeof(symbolTable*));
symbolTable* table1 = new symbolTable(13);
symbolTable* table2 = new symbolTable(31);
extern int line_count;
extern int error_count;


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


FILE *out;
FILE *code;
symbolInfo *sm = new symbolInfo();
symbolInfo *multiple = new symbolInfo();
symbolInfo *arr_ind = new symbolInfo();
symbolInfo *name_holder = new symbolInfo();
symbolInfo *pr_id = new symbolInfo();
symbolInfo *asgn = new symbolInfo();
int scope=1;
int index=-1;

void yyerror(const char *s)
{
	fprintf(stderr,"****error at line %d: %s\n",line_count,s);
	fprintf(out,"****error at line %d: %s\n",line_count,s);
	error_count++;
	return;
}


/* Line 371 of yacc.c  */
#line 135 "y.tab.c"

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
     WHITESPACE = 258,
     NEWLINE = 259,
     IF = 260,
     ELSE = 261,
     FOR = 262,
     WHILE = 263,
     DO = 264,
     BREAK = 265,
     INT = 266,
     CHAR = 267,
     FLOAT = 268,
     DOUBLE = 269,
     MAIN = 270,
     VOID = 271,
     RETURN = 272,
     SWITCH = 273,
     CASE = 274,
     DEFAULT = 275,
     CONTINUE = 276,
     PRINTLN = 277,
     ADDOP = 278,
     MULOP = 279,
     INCOP = 280,
     DECOP = 281,
     RELOP = 282,
     ASSIGNOP = 283,
     LOGICOP = 284,
     NOT = 285,
     LPAREN = 286,
     RPAREN = 287,
     LCURL = 288,
     RCURL = 289,
     LTHIRD = 290,
     RTHIRD = 291,
     COMMA = 292,
     SEMICOLON = 293,
     CONST_INT = 294,
     CONST_FLOAT = 295,
     CONST_CHAR = 296,
     ID = 297,
     LOWER_THAN_ELSE = 298
   };
#endif
/* Tokens.  */
#define WHITESPACE 258
#define NEWLINE 259
#define IF 260
#define ELSE 261
#define FOR 262
#define WHILE 263
#define DO 264
#define BREAK 265
#define INT 266
#define CHAR 267
#define FLOAT 268
#define DOUBLE 269
#define MAIN 270
#define VOID 271
#define RETURN 272
#define SWITCH 273
#define CASE 274
#define DEFAULT 275
#define CONTINUE 276
#define PRINTLN 277
#define ADDOP 278
#define MULOP 279
#define INCOP 280
#define DECOP 281
#define RELOP 282
#define ASSIGNOP 283
#define LOGICOP 284
#define NOT 285
#define LPAREN 286
#define RPAREN 287
#define LCURL 288
#define RCURL 289
#define LTHIRD 290
#define RTHIRD 291
#define COMMA 292
#define SEMICOLON 293
#define CONST_INT 294
#define CONST_FLOAT 295
#define CONST_CHAR 296
#define ID 297
#define LOWER_THAN_ELSE 298



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
#line 287 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    17,    19,    23,    28,
      32,    39,    46,    48,    53,    58,    65,    72,    80,    88,
      92,    94,    97,   102,   108,   110,   116,   121,   125,   128,
     132,   137,   139,   141,   143,   147,   154,   156,   161,   169,
     175,   177,   180,   182,   184,   192,   201,   207,   214,   222,
     231,   237,   244,   250,   254,   258,   260,   263,   266,   268,
     273,   279,   281,   285,   287,   291,   293,   297,   299,   303,
     305,   309,   312,   315,   317,   319,   323,   325,   327,   329,
     332
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    48,    46,    51,    -1,    46,    48,    51,
      -1,    48,    51,    -1,    46,    51,    -1,    51,    -1,    54,
      47,    38,    -1,    46,    54,    47,    38,    -1,    47,    37,
      42,    -1,    47,    37,    42,    35,    39,    36,    -1,    47,
      37,    42,    35,     1,    36,    -1,    42,    -1,    42,    35,
      39,    36,    -1,    42,    35,     1,    36,    -1,    54,    42,
      31,    49,    32,    38,    -1,    16,    42,    31,    49,    32,
      38,    -1,    54,     1,    31,     1,    32,     1,    38,    -1,
      16,     1,    31,     1,    32,     1,    38,    -1,    49,    37,
      50,    -1,    50,    -1,    54,    42,    -1,    54,    42,    35,
      36,    -1,    54,     1,    35,     1,    36,    -1,    16,    -1,
      11,    15,    31,    32,    52,    -1,    33,    53,    56,    34,
      -1,    33,    56,    34,    -1,    33,    34,    -1,    54,    55,
      38,    -1,    53,    54,    55,    38,    -1,    11,    -1,    13,
      -1,    12,    -1,    55,    37,    42,    -1,    55,    37,    42,
      35,    39,    36,    -1,    42,    -1,    42,    35,    39,    36,
      -1,    55,    37,    42,     1,    35,     1,    36,    -1,    42,
       1,    35,     1,    36,    -1,    57,    -1,    56,    57,    -1,
      58,    -1,    52,    -1,     7,    31,    58,    58,    60,    32,
      57,    -1,     7,     1,    31,    58,    58,     1,    32,    57,
      -1,     5,    31,    60,    32,    57,    -1,     5,     1,    31,
       1,    32,    57,    -1,     5,    31,    60,    32,    57,     6,
      57,    -1,     5,     1,    31,     1,    32,    57,     6,    57,
      -1,     8,    31,    60,    32,    57,    -1,     8,     1,    31,
       1,    32,    57,    -1,    22,    31,    42,    32,    38,    -1,
      17,    60,    38,    -1,    17,     1,    38,    -1,    38,    -1,
      60,    38,    -1,     1,    38,    -1,    42,    -1,    42,    35,
      60,    36,    -1,    42,     1,    35,     1,    36,    -1,    61,
      -1,    59,    28,    61,    -1,    62,    -1,    62,    29,    62,
      -1,    63,    -1,    63,    27,    63,    -1,    64,    -1,    63,
      23,    64,    -1,    65,    -1,    64,    24,    65,    -1,    23,
      65,    -1,    30,    65,    -1,    66,    -1,    59,    -1,    31,
      60,    32,    -1,    39,    -1,    40,    -1,    41,    -1,    59,
      25,    -1,    59,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    80,    82,    84,    86,    92,    96,   101,
     131,   167,   168,   197,   233,   235,   237,   239,   240,   243,
     245,   247,   248,   250,   251,   254,   281,   287,   291,   296,
     302,   311,   314,   317,   322,   355,   410,   444,   499,   500,
     503,   506,   514,   517,   520,   536,   537,   550,   551,   567,
     568,   584,   585,   636,   642,   645,   650,   654,   657,   672,
     706,   709,   713,   790,   795,   869,   873,  1025,  1029,  1085,
    1089,  1174,  1193,  1205,  1235,  1258,  1259,  1262,  1265,  1268,
    1299
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHITESPACE", "NEWLINE", "IF", "ELSE",
  "FOR", "WHILE", "DO", "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "MAIN",
  "VOID", "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "PRINTLN",
  "ADDOP", "MULOP", "INCOP", "DECOP", "RELOP", "ASSIGNOP", "LOGICOP",
  "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "CONST_INT", "CONST_FLOAT", "CONST_CHAR", "ID",
  "LOWER_THAN_ELSE", "$accept", "Start", "global_var_declaration",
  "global_dec_list", "func_declaration", "Parameter_List", "Parameter",
  "Program", "compound_statement", "var_declaration", "type_specifier",
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
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    48,    48,    48,    48,    49,
      49,    50,    50,    50,    50,    51,    52,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     1,     3,     4,     3,
       6,     6,     1,     4,     4,     6,     6,     7,     7,     3,
       1,     2,     4,     5,     1,     5,     4,     3,     2,     3,
       4,     1,     1,     1,     3,     6,     1,     4,     7,     5,
       1,     2,     1,     1,     7,     8,     5,     6,     7,     8,
       5,     6,     5,     3,     3,     1,     2,     2,     1,     4,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     1,     1,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    31,    33,    32,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     1,     0,     5,     0,     0,     4,     0,
       0,    12,     0,     0,     0,     0,     0,     3,     0,     2,
       0,    12,     0,     0,     0,     0,     7,     0,     0,    31,
      24,     0,    20,     0,     8,     0,     0,     0,     0,     9,
       0,    25,     0,     0,     0,     0,    21,     0,     0,    14,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    55,    76,    77,    78,     0,    43,     0,     0,
       0,    40,    42,    74,     0,    61,    63,    65,    67,    69,
      73,     0,    16,    19,     0,     0,     0,    15,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    71,    72,     0,     0,     0,     0,     0,     0,     0,
      27,    41,    79,    80,     0,    56,     0,     0,     0,     0,
      18,     0,    22,    17,    11,    10,     0,     0,     0,     0,
       0,     0,    54,    53,     0,    75,     0,     0,     0,    26,
       0,     0,     0,    29,    62,    64,    68,    66,    70,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    30,
       0,     0,     0,     0,    46,     0,     0,     0,    50,    52,
      60,     0,    37,     0,     0,    47,     0,     0,     0,    51,
      39,     0,     0,     0,    48,     0,    44,     0,    35,    49,
      45,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,    22,     7,    41,    42,     8,    77,    78,
      43,   119,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int16 yypact[] =
{
      11,   -10,  -104,  -104,     2,    26,    11,   112,  -104,     8,
      -2,     3,    12,  -104,    64,  -104,     8,   112,  -104,    38,
      74,    10,    96,    80,    94,    91,   -10,  -104,    98,  -104,
      38,   106,   108,    91,    13,   104,  -104,   122,   125,  -104,
    -104,   -12,  -104,    18,  -104,   128,    -4,   129,   130,   126,
     109,  -104,   166,   131,    91,   135,   136,   171,   137,  -104,
    -104,    14,   138,    17,    30,    31,    16,   146,    88,    88,
      88,  -104,  -104,  -104,  -104,  -104,   282,  -104,   151,   145,
     178,  -104,  -104,    44,   140,  -104,   159,    69,   156,  -104,
    -104,   158,  -104,  -104,   193,   161,   160,  -104,   163,   167,
    -104,   173,    88,   174,    48,   175,    88,   164,   169,   168,
     119,  -104,  -104,   181,   179,    88,   145,   220,    39,   100,
    -104,  -104,  -104,  -104,    88,  -104,    88,    88,    88,    88,
    -104,   186,  -104,  -104,  -104,  -104,   214,   191,    48,    48,
     223,   194,  -104,  -104,   197,  -104,   229,   195,   116,  -104,
     198,   196,   190,  -104,  -104,  -104,   156,   211,  -104,  -104,
     204,   262,    48,    88,   206,   262,   201,   205,  -104,  -104,
     239,   208,    63,   262,   240,   244,   215,   262,  -104,  -104,
    -104,   212,  -104,   217,   210,   249,   262,   224,   262,  -104,
    -104,   256,   228,   262,  -104,   262,  -104,   230,  -104,  -104,
    -104,  -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,   258,     0,   265,   235,   218,    77,   236,  -104,
       4,   162,   199,   -80,  -103,   -61,   -64,   150,   149,   148,
     153,   -56,  -104
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
     121,   139,   108,    11,     9,    10,   113,   110,   110,    20,
      16,    19,   111,   112,    47,    98,    28,   107,   101,    55,
      53,    30,     1,     2,     3,    54,    13,     4,    58,    23,
      28,   103,   105,    54,    24,   162,   163,   121,   137,    68,
     150,    33,   141,    25,    12,    34,    69,    70,   102,    62,
      21,   147,    48,    99,    79,    73,    74,    75,    76,   175,
      56,   104,   106,   110,   183,   110,   110,   110,   110,   122,
     123,    68,   124,   158,   151,    26,   -36,   -36,    69,    70,
      31,   174,   116,    15,    18,   178,    72,    73,    74,    75,
      76,    27,   127,   185,    29,    38,   128,   189,   184,   176,
     -34,   -34,    39,     2,     3,    32,   194,    40,   196,    45,
      62,    68,    37,   199,    63,   200,    64,    65,    69,    70,
      39,     2,     3,     1,     2,     3,    66,    73,    74,    75,
      76,    67,    68,    35,    36,    35,    44,   152,   153,    69,
      70,    34,    50,    71,   122,   123,    49,    72,    73,    74,
      75,    76,    62,   152,   169,    50,    63,    52,    64,    65,
      57,    61,    39,     2,     3,    59,    60,    91,    66,    92,
      94,    95,    96,    67,    68,    97,   100,   109,   125,    62,
     129,    69,    70,    63,    50,    64,    65,   118,   126,    72,
      73,    74,    75,    76,   131,    66,   130,   132,   133,   134,
      67,    68,   142,   135,   136,   138,   140,   143,    69,    70,
     144,    50,   120,   145,   146,   160,    72,    73,    74,    75,
      76,    62,   159,   161,   164,    63,   165,    64,    65,   166,
     167,   168,   172,   170,   127,   171,   173,    66,   177,   179,
     181,   180,    67,    68,   182,   187,   186,   188,   190,   192,
      69,    70,   191,    50,   149,   193,   195,   197,    72,    73,
      74,    75,    76,    62,   198,    17,   201,    63,    46,    64,
      65,    14,    93,    51,   154,   155,   157,   117,   148,    66,
     156,     0,     0,   114,    67,    68,     0,     0,     0,     0,
       0,     0,    69,    70,     0,    50,     0,     0,     0,     0,
      72,    73,    74,    75,    76,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,   -58,     0,     0,   115,   -58,     0,
     -58
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      80,   104,    66,     1,     0,    15,    70,    68,    69,     1,
       6,     7,    68,    69,     1,     1,    16,     1,     1,     1,
      32,    17,    11,    12,    13,    37,     0,    16,    32,    31,
      30,     1,     1,    37,    31,   138,   139,   117,   102,    23,
       1,    31,   106,    31,    42,    35,    30,    31,    31,     1,
      42,   115,    39,    39,    50,    39,    40,    41,    42,   162,
      42,    31,    31,   124,     1,   126,   127,   128,   129,    25,
      26,    23,    28,   129,    35,    11,    37,    38,    30,    31,
      42,   161,    78,     6,     7,   165,    38,    39,    40,    41,
      42,    14,    23,   173,    17,     1,    27,   177,    35,   163,
      37,    38,    11,    12,    13,    31,   186,    16,   188,     1,
       1,    23,    32,   193,     5,   195,     7,     8,    30,    31,
      11,    12,    13,    11,    12,    13,    17,    39,    40,    41,
      42,    22,    23,    37,    38,    37,    38,    37,    38,    30,
      31,    35,    33,    34,    25,    26,    42,    38,    39,    40,
      41,    42,     1,    37,    38,    33,     5,    32,     7,     8,
      32,    35,    11,    12,    13,    36,    36,     1,    17,    38,
      35,    35,     1,    22,    23,    38,    38,    31,    38,     1,
      24,    30,    31,     5,    33,     7,     8,    42,    29,    38,
      39,    40,    41,    42,     1,    17,    38,    36,    38,    36,
      22,    23,    38,    36,    31,    31,    31,    38,    30,    31,
      42,    33,    34,    32,    35,     1,    38,    39,    40,    41,
      42,     1,    36,    32,     1,     5,    32,     7,     8,    32,
       1,    36,    42,    35,    23,    39,    32,    17,    32,    38,
       1,    36,    22,    23,    36,     1,     6,    32,    36,    39,
      30,    31,    35,    33,    34,     6,    32,     1,    38,    39,
      40,    41,    42,     1,    36,     7,    36,     5,    33,     7,
       8,     6,    54,    37,   124,   126,   128,    78,   116,    17,
     127,    -1,    -1,     1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,
      38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    16,    45,    46,    48,    51,    54,
      15,     1,    42,     0,    48,    51,    54,    46,    51,    54,
       1,    42,    47,    31,    31,    31,    11,    51,    47,    51,
      54,    42,    31,    31,    35,    37,    38,    32,     1,    11,
      16,    49,    50,    54,    38,     1,    49,     1,    39,    42,
      33,    52,    32,    32,    37,     1,    42,    32,    32,    36,
      36,    35,     1,     5,     7,     8,    17,    22,    23,    30,
      31,    34,    38,    39,    40,    41,    42,    52,    53,    54,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     1,    38,    50,    35,    35,     1,    38,     1,    39,
      38,     1,    31,     1,    31,     1,    31,     1,    60,    31,
      59,    65,    65,    60,     1,    35,    54,    56,    42,    55,
      34,    57,    25,    26,    28,    38,    29,    23,    27,    24,
      38,     1,    36,    38,    36,    36,    31,    60,    31,    58,
      31,    60,    38,    38,    42,    32,    35,    60,    55,    34,
       1,    35,    37,    38,    61,    62,    64,    63,    65,    36,
       1,    32,    58,    58,     1,    32,    32,     1,    36,    38,
      35,    39,    42,    32,    57,    58,    60,    32,    57,    38,
      36,     1,    36,     1,    35,    57,     6,     1,    32,    57,
      36,    35,    39,     6,    57,    32,    57,     1,    36,    57,
      57,    36
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
#line 79 "1305002.y"
    {fprintf(out, "\n\nStart : func_declaration global_var_declaration Program\n");}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 81 "1305002.y"
    {fprintf(out, "\n\nStart : global_var_declaration func_declaration Program\n");}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 83 "1305002.y"
    {fprintf(out, "\n\nStart : func_declaration Program\n");}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 85 "1305002.y"
    {fprintf(out, "\n\nStart : global_var_declaration Program\n");}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 86 "1305002.y"
    {
			fprintf(out, "\n\nStart : Program\n");
			if(error_count==0)fprintf(code, "\tEND MAIN\n");
		}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 93 "1305002.y"
    {fprintf(out, "\n\nglobal_var_declaration : type_specifier global_dec_list SEMICOLON\n");
					scope = 2;
				}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 97 "1305002.y"
    {fprintf(out, "\n\nglobal_var_declaration : global_var_declaration type_specifier global_dec_list SEMICOLON\n");
					scope = 2;
				}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 102 "1305002.y"
    {fprintf(out, "\n\nglobal_dec_list : global_dec_list COMMA ID\n");
				fprintf(out,"%s\n",(yyvsp[(3) - (3)])->name.c_str());
				multiple = table1->lookSymbol((yyvsp[(3) - (3)])->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						(yyvsp[(3) - (3)])->dataType = 0;
						(yyvsp[(3) - (3)])->v.i = -99999;
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						(yyvsp[(3) - (3)])->dataType = 1;
						(yyvsp[(3) - (3)])->v.f = -99999.000000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						(yyvsp[(3) - (3)])->dataType = 2;
						(yyvsp[(3) - (3)])->v.c = '0';
					}
					table1->insertSymbol((yyvsp[(3) - (3)]));
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,(yyvsp[(3) - (3)])->name.c_str());
					yyerror(msg);
				}
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 132 "1305002.y"
    {fprintf(out, "\n\nglobal_dec_list : global_dec_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",(yyvsp[(3) - (6)])->name.c_str());
				multiple = table1->lookSymbol((yyvsp[(3) - (6)])->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						(yyvsp[(3) - (6)])->dataType = 0;
						(yyvsp[(3) - (6)])->sz = (yyvsp[(5) - (6)])->v.i;
						(yyvsp[(3) - (6)])->v.i_Arr = (int*)malloc(((yyvsp[(3) - (6)])->sz)*sizeof(int));
						for(int k = 0; k<(yyvsp[(3) - (6)])->sz; k++) (yyvsp[(3) - (6)])->v.i_Arr[k] = -1;
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						(yyvsp[(3) - (6)])->dataType = 1;
						(yyvsp[(3) - (6)])->sz = (yyvsp[(5) - (6)])->v.i;
						(yyvsp[(3) - (6)])->v.f_Arr = (float*)malloc(((yyvsp[(3) - (6)])->sz)*sizeof(float));
						for(int k = 0; k<(yyvsp[(3) - (6)])->sz; k++) (yyvsp[(3) - (6)])->v.f_Arr[k] = -1.00000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						(yyvsp[(3) - (6)])->dataType = 2;
						(yyvsp[(3) - (6)])->sz = (yyvsp[(5) - (6)])->v.i;
						(yyvsp[(3) - (6)])->v.c_Arr = (char*)malloc(((yyvsp[(3) - (6)])->sz)*sizeof(char));
						for(int k = 0; k<(yyvsp[(3) - (6)])->sz; k++) (yyvsp[(3) - (6)])->v.c_Arr[k] = '0';
					}
					table1->insertSymbol((yyvsp[(3) - (6)]));
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,(yyvsp[(3) - (6)])->name.c_str());
					yyerror(msg);
				}
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 168 "1305002.y"
    {fprintf(out, "\n\nglobal_dec_list : ID\n");
				fprintf(out,"%s\n",(yyvsp[(1) - (1)])->name.c_str());
				multiple = table1->lookSymbol((yyvsp[(1) - (1)])->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						(yyvsp[(1) - (1)])->dataType = 0;
						(yyvsp[(1) - (1)])->v.i = -99999;
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						(yyvsp[(1) - (1)])->dataType = 1;
						(yyvsp[(1) - (1)])->v.f = -99999.000000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						(yyvsp[(1) - (1)])->dataType = 2;
						(yyvsp[(1) - (1)])->v.c = '0';
					}
					table1->insertSymbol((yyvsp[(1) - (1)]));
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,(yyvsp[(1) - (1)])->name.c_str());
					yyerror(msg);
				}
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 198 "1305002.y"
    {fprintf(out, "\n\nglobal_dec_list : ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",(yyvsp[(1) - (4)])->name.c_str());
				multiple = table1->lookSymbol((yyvsp[(1) - (4)])->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						(yyvsp[(1) - (4)])->dataType = 0;
						(yyvsp[(1) - (4)])->sz = (yyvsp[(3) - (4)])->v.i;
						(yyvsp[(1) - (4)])->v.i_Arr = (int*)malloc(((yyvsp[(1) - (4)])->sz)*sizeof(int));
						for(int k = 0; k<(yyvsp[(1) - (4)])->sz; k++) (yyvsp[(1) - (4)])->v.i_Arr[k] = -1; 
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						(yyvsp[(1) - (4)])->dataType = 1;
						(yyvsp[(1) - (4)])->sz = (yyvsp[(3) - (4)])->v.i;
						(yyvsp[(1) - (4)])->v.f_Arr = (float*)malloc(((yyvsp[(1) - (4)])->sz)*sizeof(float));
						for(int k = 0; k<(yyvsp[(1) - (4)])->sz; k++) (yyvsp[(1) - (4)])->v.f_Arr[k] = -1.000000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						(yyvsp[(1) - (4)])->dataType = 2;
						(yyvsp[(1) - (4)])->sz = (yyvsp[(3) - (4)])->v.i;
						(yyvsp[(1) - (4)])->v.c_Arr = (char*)malloc(((yyvsp[(1) - (4)])->sz)*sizeof(char));
						for(int k = 0; k<(yyvsp[(1) - (4)])->sz; k++) (yyvsp[(1) - (4)])->v.c_Arr[k] = '0';
					}
					table1->insertSymbol((yyvsp[(1) - (4)]));
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,(yyvsp[(1) - (4)])->name.c_str());
					yyerror(msg);
				}
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 236 "1305002.y"
    {fprintf(out, "\n\nfunc_declaration : type_specifier ID LPAREN Parameter_List RPAREN SEMICOLON\n");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 238 "1305002.y"
    {fprintf(out, "\n\nfunc_declaration : VOID ID LPAREN Parameter_List RPAREN SEMICOLON\n");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 244 "1305002.y"
    {fprintf(out, "\n\nParameter_List : Parameter_List COMMA Parameter\n");}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 245 "1305002.y"
    {fprintf(out, "\n\nParameter_List : Parameter\n");}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 247 "1305002.y"
    {fprintf(out, "\n\nParameter : type_specifier ID\n");}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 249 "1305002.y"
    {fprintf(out, "\n\nParameter : type_specifier ID LTHIRD CONST_INT RTHIRD\n");}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 251 "1305002.y"
    {fprintf(out, "\n\nParameter : VOID\n");}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 255 "1305002.y"
    {
			fprintf(out, "\n\nProgram: INT MAIN LPAREN RPAREN compound_statement\n");
			//$$ = $5;
			if(error_count==0)
			{
				fprintf(code, "TITLE: CODE GENERATION\n");
				fprintf(code, ".MODEL SMALL\n");
				fprintf(code, ".STACK 100H\n");		
				fprintf(code, ".DATA\n");
				fprintf(code, "\tCR EQU 0DH\n");		
				fprintf(code, "\tLF EQU 0AH\n");
				for(int i = 0; i<tempCount; i++)
					fprintf(code, "t%d DW ?\n",i);
				(yyval) = (yyvsp[(5) - (5)]);
				(yyval)->code += "MAIN ENDP\n\n";
				(yyval)->code +="OUTDEC PROC\nPUSH AX\nPUSH BX\nPUSH CX\nPUSH DX\nOR AX,AX\nJGE @END_IF1\nPUSH AX\n";
				(yyval)->code +="MOV DL,'-'\nMOV AH,2\nINT 21H\nPOP AX\nNEG AX\n\n @END_IF1:\nXOR CX,CX\nMOV BX,10D\n";
				(yyval)->code +="@REPEAT1:\nXOR DX,DX\nDIV BX\nPUSH DX\nINC CX\nOR AX,AX\nJNE @REPEAT1\n\nMOV AH,2\n";
				(yyval)->code +="@PRINT_LOOP:\n\nPOP DX\nOR DL,30H\nINT 21H\nLOOP @PRINT_LOOP\n\nMOV DX, CR\nINT 21H\n";
				(yyval)->code +="MOV DX, LF\nINT 21H\nPOP DX\nPOP CX\nPOP BX\nPOP AX\nRET\nOUTDEC ENDP\n\n";
				fprintf(code,"%s",(yyval)->code.c_str());
			}
		}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 282 "1305002.y"
    {
					fprintf(out, "\n\ncompound_statement: LCURL var_declaration statements RCURL\n");
					(yyval)=(yyvsp[(3) - (4)]);
					(yyval)->code=(yyvsp[(2) - (4)])->code+".CODE\nMAIN PROC\nMOV AX, @DATA\nMOV DS, AX\n"+(yyvsp[(3) - (4)])->code;	
				}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 288 "1305002.y"
    {fprintf(out, "\n\ncompound_statement: LCURL statements RCURL\n");
					(yyval)=(yyvsp[(2) - (3)]);
				}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 291 "1305002.y"
    {fprintf(out, "\n\ncompound_statement: LCURL RCURL\n");
					}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 297 "1305002.y"
    {
				fprintf(out, "\n\nvar_declaration: type_specifier declaration_list SEMICOLON\n");
				(yyval)=(yyvsp[(2) - (3)]);
				delete (yyvsp[(1) - (3)]);
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 303 "1305002.y"
    {
				fprintf(out, "\n\nvar_declaration: var_declaration type_specifier declaration_list SEMICOLON\n");
				(yyval)=(yyvsp[(1) - (4)]);
				(yyval)->code+=(yyvsp[(3) - (4)])->code;
				delete (yyvsp[(2) - (4)]);
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 311 "1305002.y"
    {fprintf(out, "\n\ntype_specifier: INT\n");
					sm->name = "int";
				}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 314 "1305002.y"
    {fprintf(out, "\n\ntype_specifier: FLOAT\n");
					sm->name = "float";
				}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 317 "1305002.y"
    {fprintf(out, "\n\ntype_specifier: CHAR\n");
					sm->name = "char";
				}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 322 "1305002.y"
    {fprintf(out, "\n\ndeclaration_list: declaration_list COMMA ID\n");
							fprintf(out,"%s\n",(yyvsp[(3) - (3)])->name.c_str());
							multiple = table2->lookSymbol((yyvsp[(3) - (3)])->name);
							if(multiple==NULL)
							{
								(yyval)=(yyvsp[(1) - (3)]);
								if(strcmp(sm->name.c_str(),"int")==0)
								{
									(yyvsp[(3) - (3)])->dataType = 0;
									(yyvsp[(3) - (3)])->v.i = -99999;
									(yyval)->code+=(yyvsp[(3) - (3)])->name+" DW " + "?\n";
								}
								else if(strcmp(sm->name.c_str(),"float")==0)
								{
									(yyvsp[(3) - (3)])->dataType = 1;
									(yyvsp[(3) - (3)])->v.f = -99999.000000;
									(yyval)->code+=(yyvsp[(3) - (3)])->name+" DW " + "?\n";
								}
								else if(strcmp(sm->name.c_str(),"char")==0)
								{
									(yyvsp[(3) - (3)])->dataType = 2;
									(yyvsp[(3) - (3)])->v.c = '0';
									(yyval)->code+=(yyvsp[(3) - (3)])->name+" DW " + "?,\'$\'\n";
								}
								table2->insertSymbol((yyvsp[(3) - (3)]));
							}
							else
							{
								char msg[30] = "Multiple Declaration For ID: ";
								strcat(msg,(yyvsp[(3) - (3)])->name.c_str());
								yyerror(msg);
							}
						}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 356 "1305002.y"
    {fprintf(out, "\n\ndeclaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",(yyvsp[(3) - (6)])->name.c_str());
				multiple = table2->lookSymbol((yyvsp[(3) - (6)])->name);
				if(multiple==NULL)
				{
					(yyval)=(yyvsp[(1) - (6)]);
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						(yyvsp[(3) - (6)])->dataType = 0;
						(yyvsp[(3) - (6)])->sz = (yyvsp[(5) - (6)])->v.i;
						(yyvsp[(3) - (6)])->v.i_Arr = (int*)malloc(((yyvsp[(3) - (6)])->sz)*sizeof(int));
						for(int k = 0; k<(yyvsp[(3) - (6)])->sz; k++) (yyvsp[(3) - (6)])->v.i_Arr[k] = -1;
						int length = (yyvsp[(5) - (6)])->v.i;
						(yyval)->code+=(yyvsp[(3) - (6)])->name+" DW ";
						for(int i=0;i<length-1;i++){
							(yyval)->code += "?, " ;
						}
						(yyval)->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						(yyvsp[(3) - (6)])->dataType = 1;
						(yyvsp[(3) - (6)])->sz = (yyvsp[(5) - (6)])->v.i;
						(yyvsp[(3) - (6)])->v.f_Arr = (float*)malloc(((yyvsp[(3) - (6)])->sz)*sizeof(float));
						for(int k = 0; k<(yyvsp[(3) - (6)])->sz; k++) (yyvsp[(3) - (6)])->v.f_Arr[k] = -1.00000;
						int length = (yyvsp[(5) - (6)])->v.i;
						(yyval)->code+=(yyvsp[(3) - (6)])->name+" DW ";
						for(int i=0;i<length-1;i++){
							(yyval)->code += "?, " ;
						}
						(yyval)->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						(yyvsp[(3) - (6)])->dataType = 2;
						(yyvsp[(3) - (6)])->sz = (yyvsp[(5) - (6)])->v.i;
						(yyvsp[(3) - (6)])->v.c_Arr = (char*)malloc(((yyvsp[(3) - (6)])->sz)*sizeof(char));
						for(int k = 0; k<(yyvsp[(3) - (6)])->sz; k++) (yyvsp[(3) - (6)])->v.c_Arr[k] = '0';
						int length = (yyvsp[(5) - (6)])->v.i;
						(yyval)->code+=(yyvsp[(3) - (6)])->name+" DW ";
						for(int i=0;i<length-1;i++){
							(yyval)->code += "?, " ;
						}
						(yyval)->code+="?,\'$\'\n";;
					}
					table2->insertSymbol((yyvsp[(3) - (6)]));
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,(yyvsp[(3) - (6)])->name.c_str());
					yyerror(msg);
				}
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 410 "1305002.y"
    {fprintf(out, "\n\ndeclaration_list: ID\n");
				fprintf(out,"%s\n",(yyvsp[(1) - (1)])->name.c_str());
				multiple = table2->lookSymbol((yyvsp[(1) - (1)])->name);
				if(multiple==NULL)
				{
					(yyval)=new symbolInfo((yyvsp[(1) - (1)]));
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						(yyvsp[(1) - (1)])->dataType = 0;
						(yyvsp[(1) - (1)])->v.i = -99999;
						(yyval)->code=(yyvsp[(1) - (1)])->name+" DW " + "?\n";
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						(yyvsp[(1) - (1)])->dataType = 1;
						(yyvsp[(1) - (1)])->v.f = -99999.000000;
						(yyval)->code=(yyvsp[(1) - (1)])->name+" DW " + "?\n";
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						(yyvsp[(1) - (1)])->dataType = 2;
						(yyvsp[(1) - (1)])->v.c = '0';
						(yyval)->code=(yyvsp[(1) - (1)])->name+" DW " + "?, \'$\'\n";
					}
					table2->insertSymbol((yyvsp[(1) - (1)]));
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,(yyvsp[(1) - (1)])->name.c_str());
					yyerror(msg);
				}
				
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 445 "1305002.y"
    {fprintf(out, "\n\ndeclaration_list: ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",(yyvsp[(1) - (4)])->name.c_str());
				multiple = table2->lookSymbol((yyvsp[(1) - (4)])->name);
				if(multiple==NULL)
				{
					(yyval)=new symbolInfo((yyvsp[(1) - (4)]));
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						(yyvsp[(1) - (4)])->dataType = 0;
						(yyvsp[(1) - (4)])->sz = (yyvsp[(3) - (4)])->v.i;
						(yyvsp[(1) - (4)])->v.i_Arr = (int*)malloc(((yyvsp[(1) - (4)])->sz)*sizeof(int));
						for(int k = 0; k<(yyvsp[(1) - (4)])->sz; k++) (yyvsp[(1) - (4)])->v.i_Arr[k] = -1;
						int length = (yyvsp[(3) - (4)])->v.i;
						(yyval)->code=(yyvsp[(1) - (4)])->name+" DW ";
						for(int i=0;i<length-1;i++){
							(yyval)->code += "?, " ;
						}
						(yyval)->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						(yyvsp[(1) - (4)])->dataType = 1;
						(yyvsp[(1) - (4)])->sz = (yyvsp[(3) - (4)])->v.i;
						(yyvsp[(1) - (4)])->v.f_Arr = (float*)malloc(((yyvsp[(1) - (4)])->sz)*sizeof(float));
						for(int k = 0; k<(yyvsp[(1) - (4)])->sz; k++) (yyvsp[(1) - (4)])->v.f_Arr[k] = -1.000000;
						int length = (yyvsp[(3) - (4)])->v.i;
						(yyval)->code=(yyvsp[(1) - (4)])->name+" DW ";
						for(int i=0;i<length-1;i++){
							(yyval)->code += "?, " ;
						}
						(yyval)->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						(yyvsp[(1) - (4)])->dataType = 2;
						(yyvsp[(1) - (4)])->sz = (yyvsp[(3) - (4)])->v.i;
						(yyvsp[(1) - (4)])->v.c_Arr = (char*)malloc(((yyvsp[(1) - (4)])->sz)*sizeof(char));
						for(int k = 0; k<(yyvsp[(1) - (4)])->sz; k++) (yyvsp[(1) - (4)])->v.c_Arr[k] = '0';
						int length = (yyvsp[(3) - (4)])->v.i;
						(yyval)->code=(yyvsp[(1) - (4)])->name+" DW ";
						for(int i=0;i<length-1;i++){
							(yyval)->code += "?, " ;
						}
						(yyval)->code+="?, \'$\'\n";
					}
					table2->insertSymbol((yyvsp[(1) - (4)]));
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,(yyvsp[(1) - (4)])->name.c_str());
					yyerror(msg);
				}
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 503 "1305002.y"
    {fprintf(out, "\n\nstatements: statement\n");
					(yyval)=(yyvsp[(1) - (1)]);
				}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 506 "1305002.y"
    {fprintf(out, "\n\nstatements: statements statement\n");
						(yyval)=(yyvsp[(1) - (2)]);
						(yyval)->code += (yyvsp[(2) - (2)])->code;
						delete (yyvsp[(2) - (2)]);
					}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 514 "1305002.y"
    {fprintf(out, "\n\nstatement: expression_statement\n");
						(yyval)=(yyvsp[(1) - (1)]);
					}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 517 "1305002.y"
    {fprintf(out, "\n\nstatement: compound_statement\n");
						(yyval)=(yyvsp[(1) - (1)]);
					}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 521 "1305002.y"
    {
			fprintf(out, "\n\nstatement: FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
			(yyval) = (yyvsp[(3) - (7)]);

			char *label1=newLabel();
			char *label2=newLabel();
			(yyval)->code+=string(label1)+":\n";
			(yyval)->code+=(yyvsp[(4) - (7)])->code;
			(yyval)->code+="CMP "+(yyvsp[(4) - (7)])->name+", 0\n";
			(yyval)->code+="JLE "+string(label2)+"\n";
			(yyval)->code+=(yyvsp[(7) - (7)])->code;
			(yyval)->code+=(yyvsp[(5) - (7)])->code;
			(yyval)->code+="JMP "+string(label1)+"\n";
			(yyval)->code+=string(label2)+":\n";
		}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 538 "1305002.y"
    {
			fprintf(out,"\n\nstatement: IF LPAREN expression RPAREN statement\n");
			(yyval)=(yyvsp[(3) - (5)]);
					
			char *label=newLabel();
			(yyval)->code+="MOV AX, "+ (yyvsp[(3) - (5)])->name +"\n";
			(yyval)->code+="CMP AX, 0\n";
			(yyval)->code+="JLE "+string(label)+"\n";
			(yyval)->code+=(yyvsp[(5) - (5)])->code;
			(yyval)->code+=string(label)+":\n";
					
		}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 552 "1305002.y"
    {	
			fprintf(out,"\n\nstatement: IF LPAREN expression RPAREN statement ELSE statement\n");
			(yyval) = (yyvsp[(3) - (7)]);

			char *label1=newLabel();
			char *label2=newLabel();
			(yyval)->code+="MOV AX, "+ (yyvsp[(3) - (7)])->name +"\n";
			(yyval)->code+="CMP AX, 0\n";
			(yyval)->code+="JLE "+string(label1)+"\n";
			(yyval)->code+=(yyvsp[(5) - (7)])->code;
			(yyval)->code+="JMP "+string(label2)+"\n";
			(yyval)->code+=string(label1)+":\n";
			(yyval)->code+=(yyvsp[(7) - (7)])->code;
			(yyval)->code+=string(label2)+":\n";
		}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 569 "1305002.y"
    {
			fprintf(out,"\n\nstatement: WHILE LPAREN expression RPAREN statement\n");
			(yyval) = new symbolInfo();
			char *label1=newLabel();
			char *label2=newLabel();
			(yyval)->code=string(label1)+":\n";
			(yyval)->code+=(yyvsp[(3) - (5)])->code;
			(yyval)->code+="MOV AX, "+ (yyvsp[(3) - (5)])->name +"\n";
			(yyval)->code+="CMP AX, 0\n";
			(yyval)->code+="JLE "+string(label2)+"\n";
			(yyval)->code+=(yyvsp[(5) - (5)])->code;
			(yyval)->code+="JMP "+string(label1)+"\n";
			(yyval)->code+=string(label2)+":\n";
			
		}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 586 "1305002.y"
    {fprintf(out,"\n\nstatement: PRINTLN LPAREN ID RPAREN SEMICOLON\n");
			pr_id = table2->lookSymbol((yyvsp[(3) - (5)])->name);
			if(pr_id!=NULL)
			{
				(yyval)=(yyvsp[(3) - (5)]);
				if(pr_id->dataType==0)
				{
					if(pr_id->sz==0)
					{
						printf("%d\n",pr_id->v.i);
						(yyval)->code+="MOV AX, "+(yyvsp[(3) - (5)])->name+"\n";
						(yyval)->code+="CALL OUTDEC\n";
					}
					else
					{
						
						int i = pr_id->sz;
						char buffer[20];
						itoa(i,buffer,10);
						char* label1 = newLabel();
						char* label2 = newLabel();
						(yyval)->code += "MOV BX, " + string(buffer) +"\n";
						(yyval)->code += "MOV CX, 0\n";
						(yyval)->code += string(label1) +":\n";
						(yyval)->code += "CMP CX, BX\nJGE ";
						(yyval)->code += string(label2)+"\n";
						(yyval)->code += "LEA DI, "+ (yyval)->name+"\n";
						(yyval)->code += "ADD DI, CX\nADD DI, CX\nMOV AX, [DI]\n";
						(yyval)->code += "CALL OUTDEC\nINC CX\nJMP "+ string(label1)+"\n";
						(yyval)->code += string(label2)+ ":\n";

					}
				}
				else if(pr_id->dataType==1)printf("%f\n",pr_id->v.f);
				else if(pr_id->dataType==2)
				{
					printf("%c\n",pr_id->v.c);
					(yyval)->code+="LEA DX, "+(yyvsp[(3) - (5)])->name+"\n";
					(yyval)->code+="MOV AH, 9\nINT 21H\n";
					(yyval)->code+="MOV AH, 2\nMOV DX, CR\nINT 21H\nMOV DX, LF\nINT 21H\n";
				}
			}
			else
			{
				char msg[30] = "Undeclared Identifier: ";
				strcat(msg,(yyvsp[(3) - (5)])->name.c_str());
				yyerror(msg);
			}
		
		}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 637 "1305002.y"
    {	
			fprintf(out,"\n\nstatement: RETURN expression SEMICOLON\n");
			(yyval) = (yyvsp[(2) - (3)]);
			(yyval)->code += "MOV AH, 4CH\nINT 21H\n";
		}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 645 "1305002.y"
    {
						fprintf(out, "\n\nexpression_statement: SEMICOLON\n");
						(yyval)=new symbolInfo(";","SEMICOLON");
						(yyval)->code="";
					}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 650 "1305002.y"
    {
							fprintf(out, "\n\nexpression_statement: expression SEMICOLON\n");
							(yyval)=(yyvsp[(1) - (2)]);
						}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 657 "1305002.y"
    {fprintf(out, "\n\nvariable: ID\n"); fprintf(out,"%s\n",(yyvsp[(1) - (1)])->name.c_str());
						asgn = table2->lookSymbol((yyvsp[(1) - (1)])->name);
						if(asgn!=NULL)
						{
							if(asgn->sz!=0) yyerror("identifier to an array");
							else (yyval) = new symbolInfo(table2->lookSymbol((yyvsp[(1) - (1)])->name));
							printf("in var: ID  %s\n",(yyval)->name.c_str());
						}
						else 
						{
							char msg[30] = "Undeclared Identifier: ";
							strcat(msg,(yyvsp[(1) - (1)])->name.c_str());
							yyerror(msg);
						}
					}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 672 "1305002.y"
    {fprintf(out, "\n\nvariable: ID LTHIRD expression RTHIRD\n");
						fprintf(out,"%s\n",(yyvsp[(1) - (4)])->name.c_str());
						asgn = table2->lookSymbol((yyvsp[(1) - (4)])->name);
						if(asgn!=NULL)
						{
							if(asgn->sz>0)
							{
								arr_ind = (yyvsp[(3) - (4)]);
								name_holder->name = (yyvsp[(3) - (4)])->name;
								index = (yyvsp[(3) - (4)])->v.i;
								printf("var %s\n",name_holder->name.c_str());
								if(((yyvsp[(3) - (4)])->dataType==0||(yyvsp[(3) - (4)])->dataType==2)&&(((yyvsp[(3) - (4)])->v.i>=0&&(yyvsp[(3) - (4)])->v.i<asgn->sz)||((yyvsp[(3) - (4)])->v.c>=0&&(yyvsp[(3) - (4)])->v.c<asgn->sz)))
								{
									(yyval) = new symbolInfo(table2->lookSymbol((yyvsp[(1) - (4)])->name));
									(yyval)->code = (yyvsp[(3) - (4)])->code;
									(yyval)->index = arr_ind->v.i;
									printf("**in var: ID[exp] -> %d\n",(yyval)->index);
								}
								else if((yyvsp[(3) - (4)])->dataType==1)yyerror("index can not be a float");
								else yyerror("array index out-of-bound");
							}
							else
							{
								yyerror("not an array");
							}
						}
						else 
						{
							char msg[30] = "Undeclared Identifier: ";
							strcat(msg,(yyvsp[(1) - (4)])->name.c_str());
							yyerror(msg);
						}
						delete (yyvsp[(3) - (4)]);
					}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 709 "1305002.y"
    {fprintf(out,"\n\nexpression: logic_expression\n");
						(yyval)=(yyvsp[(1) - (1)]);
						printf("exp %s\n",(yyval)->name.c_str());
					}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 714 "1305002.y"
    {fprintf(out,"\n\nexpression: variable ASSIGNOP logic_expression\n");
			
			if((yyvsp[(3) - (3)])->dataType == 3) {}
			else if(!(((yyvsp[(1) - (3)])->dataType==0||(yyvsp[(1) - (3)])->dataType==2)&&(yyvsp[(3) - (3)])->dataType==1))
			{
				//$1->index == -1 was in condition
				if((yyvsp[(1) - (3)])->sz == 0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyvsp[(1) - (3)])->v.i=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyvsp[(1) - (3)])->v.i=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyvsp[(1) - (3)])->v.f=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyvsp[(1) - (3)])->v.f=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyvsp[(1) - (3)])->v.f=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyvsp[(1) - (3)])->v.c=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyvsp[(1) - (3)])->v.c=(yyvsp[(3) - (3)])->v.c;
				}
				else
				{
					
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyvsp[(1) - (3)])->v.i_Arr[index]=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyvsp[(1) - (3)])->v.i_Arr[index]=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyvsp[(1) - (3)])->v.f_Arr[index]=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyvsp[(1) - (3)])->v.f_Arr[index]=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyvsp[(1) - (3)])->v.f_Arr[index]=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyvsp[(1) - (3)])->v.c_Arr[index]=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyvsp[(1) - (3)])->v.c_Arr[index]=(yyvsp[(3) - (3)])->v.c;
				}
				printf("in assignop -> index value %d\n",(yyvsp[(1) - (3)])->index);
				(yyval)=(yyvsp[(1) - (3)]);
				printf("in assign  %d\n",index);
				printf("in assign  %s\n",(yyvsp[(1) - (3)])->name.c_str());
				(yyval)->code=(yyvsp[(3) - (3)])->code+(yyvsp[(1) - (3)])->code;
				(yyval)->code+="MOV AX, "+(yyvsp[(3) - (3)])->name+"\n";
				//$$->index==-1 was in condition
				if((yyval)->sz==0)
				{
					(yyval)->code+= "MOV "+(yyvsp[(1) - (3)])->name+", AX\n";
				}
				
				else
				{
					(yyval)->code+="LEA DI, " + (yyvsp[(1) - (3)])->name+"\n";
					char buffer[20];
					itoa((yyval)->index,buffer,10);
					printf("**in assignop -> %d\n",(yyval)->index);
					for(int i=0;i<2;i++){
						(yyval)->code += "ADD DI, " + string(buffer) +"\n";
						//$$->code += "ADD DI, " + name_holder->name +"\n";
						//printf("%s\n",buffer);
					}
					(yyval)->code+= "MOV [DI], AX\n";
					(yyval)->index = -1;
				}
				delete (yyvsp[(3) - (3)]);
				//table2->deleteSymbol($1->name);
				//table2->insertSymbol($$);
				table2->printTable(out);
			}
			else yyerror("Type Mismatch");
		}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 790 "1305002.y"
    {
						fprintf(out,"\n\nlogic_expression: rel_expression\n");
						(yyval)=(yyvsp[(1) - (1)]);
						printf("log_exp %s\n",(yyval)->name.c_str());
					}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 796 "1305002.y"
    {fprintf(out,"\n\nlogic_expression: rel_expression LOGICOP rel_expression\n");
				(yyval) = (yyvsp[(1) - (3)]);
				(yyval)->code+=(yyvsp[(3) - (3)])->code;
				(yyval)->code+="MOV AX, " + (yyvsp[(1) - (3)])->name+"\n";
				(yyval)->code+="MOV BX, " + (yyvsp[(3) - (3)])->name+"\n";
				char *temp=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				(yyval)->dataType = 0;
				if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"&&")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i&&(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i&&(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i&&(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f&&(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f&&(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f&&(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c&&(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c&&(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c&&(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="CMP AX, 0\n";
					(yyval)->code+="JLE "+string(label1)+"\n";
					(yyval)->code+="CMP BX, 0\n";
					(yyval)->code+="JLE "+string(label1)+"\n";
					(yyval)->code+="MOV "+string(temp)+", 1\n";
					(yyval)->code+="JMP "+string(label2)+"\n";
					(yyval)->code+=string(label1)+":\nMOV "+string(temp)+", 0\n";

				}
				else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"||")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i||(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i||(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i||(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f||(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f||(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f||(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c||(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c||(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c||(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="CMP AX, 0\n";
					(yyval)->code+="JG "+string(label1)+"\n";
					(yyval)->code+="CMP BX, 0\n";
					(yyval)->code+="JG "+string(label1)+"\n";
					(yyval)->code+="MOV "+string(temp)+", 0\n";
					(yyval)->code+="JMP "+string(label2)+"\n";
					(yyval)->code+=string(label1)+":\nMOV "+string(temp)+", 1\n";
				}
				(yyval)->code+=string(label2)+":\n";
				(yyval)->name=temp;
				printf("%s\n",(yyval)->name.c_str());
				delete (yyvsp[(3) - (3)]);
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 869 "1305002.y"
    {fprintf(out,"\n\nrel_expression: simple_expression\n");
						(yyval)=(yyvsp[(1) - (1)]);
						printf("rel_exp %s\n",(yyval)->name.c_str());
					}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 874 "1305002.y"
    {fprintf(out,"\n\nrel_expression: simple_expression RELOP simple_expression\n");
				(yyval) = (yyvsp[(1) - (3)]);
				(yyval)->dataType = 0;
				(yyval)->code+=(yyvsp[(3) - (3)])->code;
				(yyval)->code+="MOV AX, " + (yyvsp[(1) - (3)])->name+"\n";
				(yyval)->code+="CMP AX, " + (yyvsp[(3) - (3)])->name+"\n";
				char *temp=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"<")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i<(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i<(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i<(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f<(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f<(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f<(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c<(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c<(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c<(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="JL " + string(label1)+"\n";
				}
				else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),">")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i>(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i>(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i>(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f>(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f>(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f>(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c>(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c>(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c>(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="JG " + string(label1)+"\n";
				}
				else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"<=")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i<=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i<=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i<=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f<=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f<=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f<=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c<=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c<=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c<=(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="JLE " + string(label1)+"\n";
				}
				else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),">=")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i>=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i>=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i>=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f>=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f>=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f>=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c>=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c>=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c>=(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="JGE " + string(label1)+"\n";
				}
				else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"==")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i==(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i==(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i==(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f==(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f==(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f==(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c==(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c==(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c==(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="JE " + string(label1)+"\n";
				}
				else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"!=")==0)
				{
					if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i!=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i!=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.i!=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f!=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f!=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.f!=(yyvsp[(3) - (3)])->v.c;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c!=(yyvsp[(3) - (3)])->v.i;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c!=(yyvsp[(3) - (3)])->v.f;
					else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
						(yyval)->v.i = (yyvsp[(1) - (3)])->v.c!=(yyvsp[(3) - (3)])->v.c;
					(yyval)->code+="JNE " + string(label1)+"\n";
				}
				(yyval)->code+="MOV "+string(temp) +", 0\n";
				(yyval)->code+="JMP "+string(label2) +"\n";
				(yyval)->code+=string(label1)+":\nMOV "+string(temp)+", 1\n";
				(yyval)->code+=string(label2)+":\n";
				(yyval)->name = temp;
				printf("%s\n",(yyval)->name.c_str());
				delete (yyvsp[(3) - (3)]);
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 1025 "1305002.y"
    {fprintf(out,"\n\nsimple_expression: term\n");
						(yyval)=(yyvsp[(1) - (1)]);
						printf("simple_exp %s\n",(yyval)->name.c_str());
					}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 1029 "1305002.y"
    {fprintf(out,"\n\nsimple_expression: simple_expression ADDOP term\n");
							(yyval)=(yyvsp[(1) - (3)]);
							(yyval)->code+=(yyvsp[(3) - (3)])->code;
							(yyval)->code+="MOV AX, "+(yyvsp[(1) - (3)])->name+"\n";
							if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"+")==0)
							{
								if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.i+(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.i+(yyvsp[(3) - (3)])->v.f;}
								else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.i+(yyvsp[(3) - (3)])->v.c;}
								else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.f+(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.f+(yyvsp[(3) - (3)])->v.f;}
								else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.f+(yyvsp[(3) - (3)])->v.c;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.c+(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.c+(yyvsp[(3) - (3)])->v.f;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.c+(yyvsp[(3) - (3)])->v.c;}
								(yyval)->code+="ADD AX, "+(yyvsp[(3) - (3)])->name+"\n";
							}
							else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"-")==0)
							{
								if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.i-(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.i-(yyvsp[(3) - (3)])->v.f;}
								else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.i-(yyvsp[(3) - (3)])->v.c;}
								else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.f-(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.f-(yyvsp[(3) - (3)])->v.f;}
								else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.f-(yyvsp[(3) - (3)])->v.c;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.c-(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
									{(yyval)->dataType = 1;(yyval)->v.f = (yyvsp[(1) - (3)])->v.c-(yyvsp[(3) - (3)])->v.f;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 0;(yyval)->v.i = (yyvsp[(1) - (3)])->v.c-(yyvsp[(3) - (3)])->v.c;}
								(yyval)->code+="SUB AX, "+(yyvsp[(3) - (3)])->name+"\n";
							}
							char *temp = newTemp();
							(yyval)->code+="MOV "+string(temp)+", AX\n";
							(yyval)->name = temp;
							printf("%s\n",(yyval)->name.c_str());
							delete (yyvsp[(3) - (3)]);
						}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 1085 "1305002.y"
    {fprintf(out,"\n\nterm: unary_expression\n");
						(yyval)=(yyvsp[(1) - (1)]);
						printf("%s\n",(yyval)->name.c_str());
					}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 1089 "1305002.y"
    {fprintf(out,"\n\nterm: term MULOP unary_expression\n");
						(yyval)=(yyvsp[(1) - (3)]);
						(yyval)->code += (yyvsp[(3) - (3)])->code;
						(yyval)->code += "MOV AX, "+ (yyvsp[(1) - (3)])->name+"\n";
						(yyval)->code += "MOV BX, "+ (yyvsp[(3) - (3)])->name+"\n";
						char *temp=newTemp();
						if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"*")==0)
						{
							if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.i*(yyvsp[(3) - (3)])->v.i;}
							else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.i*(yyvsp[(3) - (3)])->v.f;}
							else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.i*(yyvsp[(3) - (3)])->v.c;}
							else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.f*(yyvsp[(3) - (3)])->v.i;}
							else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.f*(yyvsp[(3) - (3)])->v.f;}
							else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.f*(yyvsp[(3) - (3)])->v.c;}
							else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.c*(yyvsp[(3) - (3)])->v.i;}
							else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.c*(yyvsp[(3) - (3)])->v.f;}
							else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.c*(yyvsp[(3) - (3)])->v.c;}
							(yyval)->code += "MUL BX\n";
							(yyval)->code += "MOV "+ string(temp) + ", AX\n";
							(yyval)->name = temp;
							printf("mulop  %s\n",(yyval)->name.c_str());
						}
						else if(strcmp((yyvsp[(2) - (3)])->name.c_str(),"/")==0)
						{
							if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.i/(yyvsp[(3) - (3)])->v.i;}
							else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 1)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.i/(yyvsp[(3) - (3)])->v.f;}
							else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.i/(yyvsp[(3) - (3)])->v.c;}
							else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 0)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.f/(yyvsp[(3) - (3)])->v.i;}
							else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 1)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.f/(yyvsp[(3) - (3)])->v.f;}
							else if((yyvsp[(1) - (3)])->dataType == 1 && (yyvsp[(3) - (3)])->dataType == 2)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.f/(yyvsp[(3) - (3)])->v.c;}
							else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.c/(yyvsp[(3) - (3)])->v.i;}
							else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 1)
								{(yyval)->dataType = 1; (yyval)->v.f = (yyvsp[(1) - (3)])->v.c/(yyvsp[(3) - (3)])->v.f;}
							else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
								{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.c/(yyvsp[(3) - (3)])->v.c;}
							(yyval)->code += "XOR DX, DX\n";
							(yyval)->code += "DIV BX\n";
							(yyval)->code += "MOV "+ string(temp) + ", AX\n";
							(yyval)->name = temp;
							printf("%s\n",(yyval)->name.c_str());
						}
						else 
						{
							if(!((yyvsp[(1) - (3)])->dataType==1 || (yyvsp[(3) - (3)])->dataType==1))
							{
								if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.i%(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 0 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.i%(yyvsp[(3) - (3)])->v.c;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 0)
									{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.c%(yyvsp[(3) - (3)])->v.i;}
								else if((yyvsp[(1) - (3)])->dataType == 2 && (yyvsp[(3) - (3)])->dataType == 2)
									{(yyval)->dataType = 0; (yyval)->v.i = (yyvsp[(1) - (3)])->v.c%(yyvsp[(3) - (3)])->v.c;}
								(yyval)->code += "XOR DX, DX\n";
								(yyval)->code += "DIV BX\n";
								(yyval)->code += "MOV "+ string(temp) + ", DX\n";
								(yyval)->name = temp;
								printf("%s\n",(yyval)->name.c_str());
							}
							else
							{
								(yyval)->dataType = 3;
								yyerror("invalid operands for modulo operation");
							}
						}
						delete (yyvsp[(3) - (3)]);
					}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 1174 "1305002.y"
    {fprintf(out,"\n\nunary_expression: ADDOP unary_expression\n");
						if(strcmp((yyvsp[(1) - (2)])->name.c_str(),"+")==0)
						{
							(yyval)=(yyvsp[(2) - (2)]);
						}
						else if(strcmp((yyvsp[(1) - (2)])->name.c_str(),"-")==0)
						{
							if((yyvsp[(1) - (2)])->dataType == 0) {(yyvsp[(2) - (2)])->v.i=-(yyvsp[(2) - (2)])->v.i;}
							else if((yyvsp[(1) - (2)])->dataType == 1) {(yyvsp[(2) - (2)])->v.f=-(yyvsp[(2) - (2)])->v.f;}
							else if((yyvsp[(1) - (2)])->dataType == 2) {(yyvsp[(2) - (2)])->v.c=-(yyvsp[(2) - (2)])->v.c;}
							(yyval)=(yyvsp[(2) - (2)]);
							char *temp=newTemp();
							//$$->code="MOV AX, " + $2->name + "\n"; was here
							(yyval)->code+="MOV AX, " + (yyvsp[(2) - (2)])->name + "\n";
							(yyval)->code+="NEG AX\n";
							(yyval)->code+="MOV "+string(temp)+", AX\n";
							(yyval)->name = temp;
						}
					  }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 1193 "1305002.y"
    {fprintf(out,"\n\nunary_expression: NOT unary_expression\n");
						if((yyvsp[(1) - (2)])->dataType == 0) {(yyvsp[(2) - (2)])->v.i=!(yyvsp[(2) - (2)])->v.i;}
						else if((yyvsp[(1) - (2)])->dataType == 1) {(yyvsp[(2) - (2)])->v.f=!(yyvsp[(2) - (2)])->v.f;}
						else if((yyvsp[(1) - (2)])->dataType == 2) {(yyvsp[(2) - (2)])->v.c=!(yyvsp[(2) - (2)])->v.c;}
						(yyval)=(yyvsp[(2) - (2)]);
						char *temp=newTemp();
						//$$->code="MOV AX, " + $2->name + "\n"; was here
						(yyval)->code+="MOV AX, " + (yyvsp[(2) - (2)])->name + "\n";
						(yyval)->code+="NOT AX\n";
						(yyval)->code+="MOV "+string(temp)+", AX\n";
						(yyval)->name = temp;
					}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 1205 "1305002.y"
    {fprintf(out,"\n\nunary_expression: factor\n");
				(yyval) = new symbolInfo();
				(yyval)->name = (yyvsp[(1) - (1)])->name;
				(yyval)->type = (yyvsp[(1) - (1)])->type;
				(yyval)->dataType = (yyvsp[(1) - (1)])->dataType;
				(yyval)->index = (yyvsp[(1) - (1)])->index;
				//$$->pos = $1->pos;
				(yyval)->sz = (yyvsp[(1) - (1)])->sz;
				(yyval)->code = (yyvsp[(1) - (1)])->code;
				if((yyvsp[(1) - (1)])->sz == 0)
				{
					if((yyvsp[(1) - (1)])->dataType==0)(yyval)->v.i = (yyvsp[(1) - (1)])->v.i;
					else if((yyvsp[(1) - (1)])->dataType==1)(yyval)->v.f = (yyvsp[(1) - (1)])->v.f;
					else if((yyvsp[(1) - (1)])->dataType==2)(yyval)->v.c = (yyvsp[(1) - (1)])->v.c;
				}
				else
				{
					printf("*** index: %d\n",index);
					if((yyvsp[(1) - (1)])->dataType==0){(yyval)->v.i = (yyvsp[(1) - (1)])->v.i_Arr[index];
					printf("ekhane achi....9.b.1\n");}
					else if((yyvsp[(1) - (1)])->dataType==1){(yyval)->v.f = (yyvsp[(1) - (1)])->v.f_Arr[index];
					printf("ekhane achi....9.b.2\n");}
					else if((yyvsp[(1) - (1)])->dataType==2){(yyval)->v.c = (yyvsp[(1) - (1)])->v.c_Arr[index];
					printf("ekhane achi....9.b.3\n");}
					index = -1;
				}
				printf("%s\n",(yyval)->name.c_str());
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 1235 "1305002.y"
    {fprintf(out,"\n\nfactor: variable\n");
			(yyval)=(yyvsp[(1) - (1)]);
			printf("factor %s\n",(yyval)->name.c_str());
			printf("factor %s\n",name_holder->name.c_str());
			if((yyval)->sz>0)
			{
				(yyval)->code+="LEA DI, " + (yyvsp[(1) - (1)])->name+"\n";
				printf("**in factor: var -> %d\n",arr_ind->v.i);
				string s1 = name_holder->name;
				for(int i=0;i<2;i++)
				{
					(yyval)->code += "ADD DI, " + s1 +"\n";
					printf("%s\n",name_holder->name.c_str());
				}
				char *temp= newTemp();
				(yyval)->code+= "MOV AX, [DI]\n";
				(yyval)->code+= "MOV " + string(temp) + ", AX\n";
				(yyval)->name = temp;
				(yyval)->index = -1;
				name_holder->name = "";
			}
			printf("%s\n",(yyval)->name.c_str());
		   }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 1258 "1305002.y"
    {fprintf(out,"\nfactor: LPAREN expression RPAREN\n"); (yyval)=(yyvsp[(2) - (3)]);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 1259 "1305002.y"
    {fprintf(out,"\n\nfactor: CONST_INT\n");
				fprintf(out,"%d\n",(yyvsp[(1) - (1)])->v.i);
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 1262 "1305002.y"
    {fprintf(out,"\n\nfactor: CONST_FLOAT\n");
				fprintf(out,"%f\n",(yyvsp[(1) - (1)])->v.f);
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 1265 "1305002.y"
    {fprintf(out,"\n\nfactor: CONST_CHAR\n");
				fprintf(out,"%c\n",(yyvsp[(1) - (1)])->v.c);
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 1268 "1305002.y"
    {fprintf(out,"\n\nfactor: variable INCOP\n");
				(yyval)=(yyvsp[(1) - (2)]);
				//index==-1 was in condition
				if((yyval)->sz==0)
				{
					if((yyvsp[(1) - (2)])->dataType == 0) {(yyvsp[(1) - (2)])->v.i++;}
					else if((yyvsp[(1) - (2)])->dataType == 1) {(yyvsp[(1) - (2)])->v.f++;}
					else if((yyvsp[(1) - (2)])->dataType == 2) {(yyvsp[(1) - (2)])->v.c++;}
					(yyval)->code += "INC " + (yyvsp[(1) - (2)])->name + "\n";
				}
				else
				{
					if((yyvsp[(1) - (2)])->dataType==0){(yyvsp[(1) - (2)])->v.i_Arr[index]++;}
					else if((yyvsp[(1) - (2)])->dataType==1){(yyvsp[(1) - (2)])->v.f_Arr[index]++;}
					else if((yyvsp[(1) - (2)])->dataType==2){(yyvsp[(1) - (2)])->v.c_Arr[index]++;}	
					(yyval)->code+="LEA DI, " + (yyvsp[(1) - (2)])->name+"\n";
					string s1 = name_holder->name;
					for(int i=0;i<2;i++)
					{
						(yyval)->code += "ADD DI, " + s1 +"\n";
						printf("%s\n",name_holder->name.c_str());
					}
					(yyval)->code+= "MOV AX, [DI]\n";
					(yyval)->code += "INC AX\n";
					(yyval)->code+= "MOV [DI], AX\n";
					(yyval)->index = -1;
					name_holder->name = "";
				}
				
				printf("%s\n",(yyval)->name.c_str());
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 1299 "1305002.y"
    {fprintf(out,"\n\nfactor: variable DECOP\n");
				(yyval)=(yyvsp[(1) - (2)]);
				//index==-1 was in condition
				if((yyval)->sz==0)
				{
					if((yyvsp[(1) - (2)])->dataType == 0) {(yyvsp[(1) - (2)])->v.i--;}
					else if((yyvsp[(1) - (2)])->dataType == 1) {(yyvsp[(1) - (2)])->v.f--;}
					else if((yyvsp[(1) - (2)])->dataType == 2) {(yyvsp[(1) - (2)])->v.c--;}
					(yyval)->code += "DEC " + (yyvsp[(1) - (2)])->name + "\n";
				}
				else
				{
					if((yyvsp[(1) - (2)])->dataType==0){(yyvsp[(1) - (2)])->v.i_Arr[arr_ind->v.i]--;}
					else if((yyvsp[(1) - (2)])->dataType==1){(yyvsp[(1) - (2)])->v.f_Arr[arr_ind->v.i]--;}
					else if((yyvsp[(1) - (2)])->dataType==2){(yyvsp[(1) - (2)])->v.c_Arr[arr_ind->v.i]--;}
					(yyval)->code+="LEA DI, " + (yyvsp[(1) - (2)])->name+"\n";
					string s1 = name_holder->name;
					for(int i=0;i<2;i++)
					{
						(yyval)->code += "ADD DI, " + s1 +"\n";
						printf("%s\n",name_holder->name.c_str());
					}
					(yyval)->code+= "MOV AX, [DI]\n";
					(yyval)->code += "DEC AX\n";
					(yyval)->code+= "MOV [DI], AX\n";
					(yyval)->index = -1;
					name_holder->name = "";
				}
				printf("%s\n",(yyval)->name.c_str());
			}
    break;


/* Line 1792 of yacc.c  */
#line 3164 "y.tab.c"
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
#line 1332 "1305002.y"

int main(int argc,char *argv[]){
	
	extern FILE *yyin;
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	out= fopen("1305002_log.txt","w");
	code= fopen("1305002_code.asm","w");


	yyin= fin;
	/*yydebug=1;*/
	yyparse();
	fprintf(out,"\n*******global symbol table******\n");
	table1->printTable(out);
	fprintf(out,"\n*******local symbol table******\n");
	table2->printTable(out);
	fprintf(out,"\nTotal Lines: %d\n",line_count);
	fprintf(out,"\nTotal Errors: %d\n",error_count);
	fclose(yyin);
	fclose(out);
	fclose(code);
	//optimize("1305002_code.asm");
	return 0;
}
