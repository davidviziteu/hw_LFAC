/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"

#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
char buffer[100];
FILE* fd;
 
enum data_type {__int, __char, __string, __bool}; 

struct var{
          bool is_const;
          char  id[100], type[100], value[100], scope[100], where[100];
          enum data_type _type;
          int _int; 
          int _float; 
          char * _char;
          bool _bool;
          };
 
struct signature{
          char nume[100], parent_class[100];
          int is_method, params_count;
          char * param_types[100];
};
struct var tabel_var[1000];
struct var stack[1000];

char nume_clasa[100], nume_functie[100];
struct signature tabel_fnc[100];
struct signature new_function_buff;
int total_vars=0, errors=0, total_fnc=1, param=0, conditie, var_in_class, ok=0, var_in_fun, ok_fun;
int err_count = 0;
char scope[100], scope2[100];
int stack_idx = 0;
int exists_in_var_table(char x[100]);
int exists_in_var_table_s(struct var *x);
struct var * get_var_from_table(char id[100]);
int is_default(char x[100]);
void var_assign(struct var *to, struct var * from);
void update_int(char x[100], int nr);
void update_var(char x[100], char y[100]);
int update_var_s(struct var *to, struct var *from);
int same_type(char x[100], char y[100]);
int same_type_s(struct var *x, struct var *y);
int same_type_number(char x[100], char y[100]);
int exists_signature(struct signature *new_f);
int add_signature(struct signature *new_f);
void stack_push(struct var new_elem);
void update_var_int(char x[100], int valoare);
char * get_var_table(char id[100]) ;
char* get_var_scope(char id[100]) ;
int get_var_value(char id[100]);
int same_scope(char x[100], char y[100]) ;
int exists_function (char x[100]);
int stack_pop(); //ASTA DA POP LA INDEX 
int val_expr;

#line 135 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ID = 258,
    TIP = 259,
    BGIN = 260,
    END = 261,
    ENDIF = 262,
    CONST = 263,
    ASSIGN = 264,
    VIS = 265,
    CLASS = 266,
    IF = 267,
    WHILE = 268,
    FOR = 269,
    OP_BIN = 270,
    OP_STR = 271,
    BOOL = 272,
    FLOAT = 273,
    NR = 274
  };
#endif
/* Tokens.  */
#define ID 258
#define TIP 259
#define BGIN 260
#define END 261
#define ENDIF 262
#define CONST 263
#define ASSIGN 264
#define VIS 265
#define CLASS 266
#define IF 267
#define WHILE 268
#define FOR 269
#define OP_BIN 270
#define OP_STR 271
#define BOOL 272
#define FLOAT 273
#define NR 274

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "limbaj.y"

     char *strval;
     char _char; 
     char  id[100], type[100], value[100], scope[100], where[100];
     int _int, intval; 
     int _float; 
     char * _string;

#line 234 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

#define YYUNDEFTOK  2
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    31,     2,     2,     2,     2,     2,     2,     2,
      25,    26,    22,    20,    24,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    30,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    89,    92,    99,   115,   134,   151,   163,
     166,   178,   187,   199,   214,   217,   224,   231,   234,   240,
     243,   246,   250,   253,   257,   261,   268,   281,   284,   290,
     300,   332,   335,   339,   367,   375,   388,   390,   394,   395,
     395,   398,   401,   404,   407,   410,   419,   422,   428
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TIP", "BGIN", "END", "ENDIF",
  "CONST", "ASSIGN", "VIS", "CLASS", "IF", "WHILE", "FOR", "OP_BIN",
  "OP_STR", "BOOL", "FLOAT", "NR", "'+'", "'-'", "'*'", "'/'", "','",
  "'('", "')'", "'{'", "'}'", "':'", "';'", "' '", "$accept", "progr",
  "fnc", "lista_param", "functie", "clasa", "decl_cl", "declaratiecl",
  "bloc", "list", "operatii", "decl_gl", "declaratie", "statement",
  "instructiune_if", "$@1", "lista_apel", "bool", "operatii_binare", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      43,    45,    42,    47,    44,    40,    41,   123,   125,    58,
      59,    32
};
# endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    12,    23,    79,    -2,    32,   -82,    69,    34,    66,
     -82,    35,    75,   107,    77,   -82,   -82,   111,   -82,    39,
     112,    82,    85,   -82,   -82,   -82,   113,   -82,   105,    43,
       4,   126,   108,   110,   114,     6,    81,   106,   -82,   134,
     136,   115,    87,    61,    97,   -82,    59,    59,   135,   116,
      85,   -82,   117,   -82,   -82,   138,     7,   118,    85,   119,
     -82,   -82,    98,   -82,   -82,   -82,   -82,   -82,   100,   128,
     -82,   123,   -82,   124,   142,   -82,   125,   -82,   120,   149,
     -82,     8,   127,   -82,    13,    85,   137,   137,   137,   137,
     139,   -82,   151,   -82,   132,   152,   -82,    51,   140,   -82,
     -82,   -82,    18,   109,   109,   -82,   -82,   -82,   -82,    85,
     130,   -82,   101,    52,   -82,    40,   158,   -82,   115,   104,
     -82,   133,   119,   137,    83,   141,    85,    46,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    26,     1,     0,     0,     0,
      24,     0,     0,     0,     0,     3,    25,     0,    28,     0,
       0,     0,     0,     4,     2,     5,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
      39,    16,     0,    17,     6,     0,     0,     0,     0,     0,
      30,    23,    29,    44,    42,    41,    34,    43,     0,     0,
      46,     0,    47,     0,     0,    38,     0,    18,    13,     0,
      10,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,    35,     0,    37,     0,     0,    40,     0,    13,     9,
      12,     8,     0,    19,    20,    21,    22,    45,    48,     0,
       0,    15,     0,     0,     7,     0,     0,    14,    15,     0,
      31,     0,    14,     0,     0,     0,     0,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   121,   -27,   -10,   -82,   -82,   122,   -82,   -34,
     -81,   -82,   159,   -36,   -82,   -82,   -82,   129,    48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    14,    19,    15,     8,    56,    57,    24,    36,
      62,     3,     4,    37,    38,    76,    68,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    50,    42,     1,    23,   103,   104,   105,   106,    30,
      31,    79,    13,    43,    52,     5,    30,    31,    32,    33,
      34,    30,    31,     6,    84,    32,    33,    34,    10,    44,
      32,    33,    34,    35,    67,    80,    99,    49,    13,    17,
      35,   101,   124,    30,    31,    35,   114,    17,    52,    30,
      31,   102,    32,    33,    34,    17,    17,    11,    32,    33,
      34,    18,    69,    26,    60,    27,    52,    35,   120,    41,
     112,    23,    12,    35,   128,   115,    70,   111,   118,    52,
      61,    13,    22,     1,    30,    31,   119,    51,    30,    31,
       7,    52,   127,    32,    33,    34,    16,    32,    33,    34,
      63,    13,    20,    86,    87,    88,    89,    29,    35,   125,
      21,    26,    35,    59,    25,    64,    65,    39,    86,    87,
      88,    89,    28,    66,    90,    26,    91,   117,    26,    45,
     122,    88,    89,    46,    40,    47,    53,    54,    74,    48,
      55,    78,    58,    92,    75,    97,    85,    77,    83,    93,
      94,    95,    98,    96,   108,   110,    61,   100,   107,   109,
     116,    69,     9,   123,   121,   113,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,    73,    81,    82
};

static const yytype_int8 yycheck[] =
{
      36,    35,    29,     4,    14,    86,    87,    88,    89,     3,
       4,     4,     4,     9,    50,     3,     3,     4,    12,    13,
      14,     3,     4,     0,    58,    12,    13,    14,    30,    25,
      12,    13,    14,    27,    44,    28,    28,    31,     4,     4,
      27,    28,   123,     3,     4,    27,    28,     4,    84,     3,
       4,    85,    12,    13,    14,     4,     4,    25,    12,    13,
      14,    26,     3,    24,     3,    26,   102,    27,    28,    26,
      97,    81,     3,    27,    28,   109,    17,    26,    26,   115,
      19,     4,     5,     4,     3,     4,   113,     6,     3,     4,
      11,   127,   126,    12,    13,    14,    30,    12,    13,    14,
       3,     4,    27,    20,    21,    22,    23,    25,    27,    26,
       3,    24,    27,    26,     3,    18,    19,     4,    20,    21,
      22,    23,    10,    26,    24,    24,    26,    26,    24,     3,
      26,    22,    23,    25,    29,    25,    30,     3,     3,    25,
       4,     3,    27,    15,    28,    25,    27,    30,    30,    26,
      26,     9,     3,    28,     3,     3,    19,    30,    19,    27,
      30,     3,     3,    30,   116,    25,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    56,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    33,    43,    44,     3,     0,    11,    37,    44,
      30,    25,     3,     4,    34,    36,    30,     4,    26,    35,
      27,     3,     5,    36,    40,     3,    24,    26,    10,    25,
       3,     4,    12,    13,    14,    27,    41,    45,    46,     4,
      29,    26,    35,     9,    25,     3,    25,    25,    25,    31,
      41,     6,    45,    30,     3,     4,    38,    39,    27,    26,
       3,    19,    42,     3,    18,    19,    26,    36,    48,     3,
      17,    49,    50,    49,     3,    28,    47,    30,     3,     4,
      28,    34,    39,    30,    41,    27,    20,    21,    22,    23,
      24,    26,    15,    26,    26,     9,    28,    25,     3,    28,
      30,    28,    41,    42,    42,    42,    42,    19,     3,    27,
       3,    26,    35,    25,    28,    41,    30,    26,    26,    35,
      28,    50,    26,    30,    42,    26,    27,    41,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    38,    39,    39,    39,    40,    41,    41,    42,
      42,    42,    42,    42,    43,    43,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      46,    48,    48,    48,    48,    48,    49,    49,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     2,     4,     8,     7,     8,
       7,     2,     3,     2,     5,     4,     3,     2,     3,     3,
       3,     3,     3,     1,     2,     3,     2,     5,     4,     3,
       3,     7,    13,     2,     3,     4,     1,     4,     3,     0,
       4,     1,     1,     1,     1,     3,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 3:
#line 89 "limbaj.y"
               {
                    ;//cod
               }
#line 1492 "y.tab.c"
    break;

  case 4:
#line 92 "limbaj.y"
                    {
                          ;//cod
                    }
#line 1500 "y.tab.c"
    break;

  case 5:
#line 99 "limbaj.y"
               {
                    if(ok_fun==0)
                    {
                         var_in_fun=total_vars;
                         ok_fun=1;
                    }
                    new_function_buff.param_types[new_function_buff.params_count] = strdup((yyvsp[-1].strval));
                    new_function_buff.params_count++;
                    strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
                    strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
                    strcpy(tabel_var[total_vars].value, "default");
                    strcpy(tabel_var[total_vars].scope, "functie");
                    total_vars++;
 
                    // printf("1 param  ------ %s \n", $1);
               }
#line 1521 "y.tab.c"
    break;

  case 6:
#line 115 "limbaj.y"
                                   {    if(ok_fun==0)
                                        {
                                            var_in_fun=total_vars;
                                            ok_fun=1;
                                        }
                                        // printf("\t\tdolar: 3 %s, 4 %s\n", $3, $4);
                                        new_function_buff.param_types[new_function_buff.params_count] = strdup((yyvsp[-1].strval));
                                        new_function_buff.params_count++;
                                        strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
                                        strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
                                        strcpy(tabel_var[total_vars].value, "default");
                                        strcpy(tabel_var[total_vars].scope, "functie");
                                        total_vars++;
                                        printf("HEI, SUNT AICI \n");
                                   }
#line 1541 "y.tab.c"
    break;

  case 7:
#line 134 "limbaj.y"
                                                  { 
                                                       strcpy(new_function_buff.nume, (yyvsp[-6].strval));
                                                       if(exists_signature(&new_function_buff) == 1)
                                                            yyerror(),  printf("function %s redefined", 
                                                                                               new_function_buff.nume);
                                                       else
                                                            add_signature(&new_function_buff), total_fnc++;

                                                       // printf("variabile in functie: %d, %d \n",var_in_fun,total_vars);
                                                       for(int i= var_in_fun; i< total_vars; i++)
                                                       {
                                                            // printf("I ARE VALOAREA : %d, %s", i, $2);
                                                            strcpy(tabel_var[i].where, (yyvsp[-6].strval));
                                                            strcpy(tabel_var[i].scope, "functie");
                                                       }
                                                       ok_fun=0;
                                                  }
#line 1563 "y.tab.c"
    break;

  case 8:
#line 151 "limbaj.y"
                                   { 
                                        new_function_buff.params_count = 0;
                                        strcpy(new_function_buff.nume, (yyvsp[-5].strval));
                                        if(exists_signature(&new_function_buff) == 1)
                                             yyerror(), printf("function %s redefined", new_function_buff.nume);
                                        else
                                             add_signature(&new_function_buff);
                                             total_fnc++;
                                   }
#line 1577 "y.tab.c"
    break;

  case 9:
#line 163 "limbaj.y"
                                             {
                                                  strcpy(nume_clasa, (yyvsp[-6].strval));     
                                             }
#line 1585 "y.tab.c"
    break;

  case 10:
#line 166 "limbaj.y"
                                        {
                                             strcpy(nume_clasa, (yyvsp[-5].strval)); //cod
                                            //  printf("%d, %d\n", var_in_class, total_vars);
                                             for (int i=var_in_class-2; i<total_vars; i++)
                                             {
                                                  strcpy(tabel_var[i].where, nume_clasa);
                                             }
                                             ok=0;
                                             
                                        }
#line 1600 "y.tab.c"
    break;

  case 11:
#line 178 "limbaj.y"
                           {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars+1;
                                        ok=1;
                                   }
                              strcpy(tabel_var[total_vars].scope, "clasa");
                              //cod
                         }
#line 1614 "y.tab.c"
    break;

  case 12:
#line 187 "limbaj.y"
                                {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars;
                                        ok=1;
                                   }
                                    strcpy(tabel_var[total_vars].scope, "clasa");
                                  //cod
                              }
#line 1628 "y.tab.c"
    break;

  case 13:
#line 199 "limbaj.y"
               { 
                    if(exists_in_var_table((yyvsp[0].strval))==0)
                    {
                         strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
                         strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
                         strcpy(tabel_var[total_vars].value, "default");
                         strcpy(tabel_var[total_vars].scope, "clasa");
                         strcpy(tabel_var[total_vars].where, nume_clasa);
                         printf("NUME: CLASA : %s\n", nume_clasa);
                         total_vars++;
                         snprintf(buffer, 100,"%s %s\n", (yyvsp[-1].strval) , (yyvsp[0].strval));
                         fprintf(fd, "%s", buffer);}
                    else
                         yyerror(); 
               }
#line 1648 "y.tab.c"
    break;

  case 14:
#line 214 "limbaj.y"
                                   {
                                        //Decl functie cu param
                                   }
#line 1656 "y.tab.c"
    break;

  case 15:
#line 217 "limbaj.y"
                         {
                              //nush ce e aici *: e apelul unei functii fara parametrii
                         }
#line 1664 "y.tab.c"
    break;

  case 16:
#line 224 "limbaj.y"
                         {
                              ;//cod
                         }
#line 1672 "y.tab.c"
    break;

  case 17:
#line 231 "limbaj.y"
                         {
                             printf("am intrati cii dupa if\n") ;//cod
                         }
#line 1680 "y.tab.c"
    break;

  case 18:
#line 234 "limbaj.y"
                              {
                                   ;//cod
                              }
#line 1688 "y.tab.c"
    break;

  case 19:
#line 240 "limbaj.y"
                                 {     
                                             {(yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);  val_expr=(yyval.intval); }
                                   }
#line 1696 "y.tab.c"
    break;

  case 20:
#line 243 "limbaj.y"
                                 {
                                             {(yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);  val_expr=(yyval.intval);}
                                  }
#line 1704 "y.tab.c"
    break;

  case 21:
#line 246 "limbaj.y"
                                 { 
                                        {(yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);  val_expr=(yyval.intval);}

                                   }
#line 1713 "y.tab.c"
    break;

  case 22:
#line 250 "limbaj.y"
                                 { 
                                        {(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);  val_expr=(yyval.intval);}
                                   }
#line 1721 "y.tab.c"
    break;

  case 23:
#line 253 "limbaj.y"
              { (yyval.intval)= (yyvsp[0].intval); val_expr=(yyval.intval); }
#line 1727 "y.tab.c"
    break;

  case 24:
#line 257 "limbaj.y"
                         {
                              strcpy(tabel_var[total_vars].scope, "global");
                              ;//cod
                         }
#line 1736 "y.tab.c"
    break;

  case 25:
#line 261 "limbaj.y"
                              {
                                    strcpy(tabel_var[total_vars].scope, "global");
                                   ;//cod
                              }
#line 1745 "y.tab.c"
    break;

  case 26:
#line 268 "limbaj.y"
               { 
                    if(exists_in_var_table((yyvsp[0].strval))==0)
                    {
                         strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
                         strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
                         strcpy(tabel_var[total_vars].value, "default");
                         strcpy(tabel_var[total_vars].scope, "global");
                         total_vars++;
                         snprintf(buffer, 100,"%s %s\n", (yyvsp[-1].strval) , (yyvsp[0].strval));
                         fprintf(fd, "%s", buffer);}
                    else
                         yyerror(); 
               }
#line 1763 "y.tab.c"
    break;

  case 27:
#line 281 "limbaj.y"
                                   {
                                        //Decl functie cu param
                                   }
#line 1771 "y.tab.c"
    break;

  case 28:
#line 284 "limbaj.y"
                         {
                              // e apelul unei functii fara parametrii
                         }
#line 1779 "y.tab.c"
    break;

  case 29:
#line 290 "limbaj.y"
                              {
                                if(conditie==0)
                                {printf("id assign operatii\n");
                                 if (exists_in_var_table((yyvsp[-2].strval))==0 )
                                      yyerror();
                                 
                                 printf("%s := %d\n", (yyvsp[-2].strval), val_expr);
                                 update_var_int((yyvsp[-2].strval), val_expr);
                                }
                            }
#line 1794 "y.tab.c"
    break;

  case 30:
#line 300 "limbaj.y"
                    {
                    if(conditie==0)
                    {printf("id op id\n");
                         struct var * dol1; //era pera lung "dollar"
                         struct var * dol3;
                         dol1 = get_var_from_table((yyvsp[-2].strval));
                         dol3 = get_var_from_table((yyvsp[0].strval));
                         if (dol1 == NULL)
                             {yyerror(), printf("undeclared var: %s", (yyvsp[-2].strval)); return;}
                         if (dol1 == NULL)
                             {yyerror(), printf("undeclared var: %s", (yyvsp[0].strval)); return;}
                         if (dol1 != NULL && dol3!= NULL){
                              if(same_type_s(dol1, dol3) && (same_scope((yyvsp[-2].strval), (yyvsp[0].strval)) || (strcmp(get_var_scope((yyvsp[0].strval)),"globala")==0))) 
                              {
                                  if(strcmp(get_var_table((yyvsp[0].strval)),"default")==0)
                                    yyerror();
                                  else
                                {
                                  printf("%s :=%s   %d \n",(yyvsp[-2].strval), (yyvsp[0].strval), get_var_value((yyvsp[0].strval)));
                              
                                  update_var_int((yyvsp[-2].strval), get_var_value((yyvsp[0].strval)));
                                }
                                  }
                              else{
                                   yyerror(); ++err_count;
                                   printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, (yyvsp[-1].strval), dol3->type);
                                   break;
                              }
                         }
                    }
                    }
#line 1830 "y.tab.c"
    break;

  case 31:
#line 332 "limbaj.y"
                                        {
                                             ;//cod
                                        }
#line 1838 "y.tab.c"
    break;

  case 32:
#line 335 "limbaj.y"
                                                                                 {
                                                                                ;//cod
                                                                           }
#line 1846 "y.tab.c"
    break;

  case 33:
#line 339 "limbaj.y"
               { 
                    if(conditie==0)
                    {
                    if(ok_fun==0)
                    {
                         var_in_fun=total_vars;
                         ok_fun=1;
                    }
 
                    if(exists_in_var_table((yyvsp[0].strval))==0)
                    {
                         strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
                         strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
                         strcpy(tabel_var[total_vars].value, "default");
                         strcpy(tabel_var[total_vars].scope, "local");
                         total_vars++;
                         snprintf(buffer, 100,"%s %s %s \n", (yyvsp[-1].strval) , (yyvsp[0].strval), "default");
                         fprintf(fd, "%s", buffer);
                    }
                    else
                         yyerror(); 
                    // printf("%d\n", ok_fun);
                    if(ok_fun==1)
                    {
                         strcpy(tabel_var[total_vars].scope, "functie");
                    }
                    }
               }
#line 1879 "y.tab.c"
    break;

  case 34:
#line 367 "limbaj.y"
                     {                          //apel functie fara param
                            if(exists_function((yyvsp[-2].strval))==0)
                                yyerror();
                            else
                            {
                                //se executa codul
                            }
                            }
#line 1892 "y.tab.c"
    break;

  case 35:
#line 376 "limbaj.y"
                                {
                                    if(exists_function((yyvsp[-3].strval))==0)
                                        yyerror();
                                    ///
                                    ///////////////////////////////////////////////////////////////////
                                    ///////////////////////////////////////////////////////////////////
                                    //TREBUIE FACUT UN VECTOR DE TIPURI PENTRU APEL SI VERIFICAT DACA ARE ACELASI TIP CU VARIABILELE 
                                    //DIN FUNCTIA DECLARATA MAI SUS
                                    /////////////////////////////////////////////

                                    ////////////////////////////////
                                }
#line 1909 "y.tab.c"
    break;

  case 37:
#line 390 "limbaj.y"
                                 { 
                        if(strcmp("true", "true")==0) { conditie=1; goto s3; }
                        else {goto s4; conditie=0;}
                         }
#line 1918 "y.tab.c"
    break;

  case 38:
#line 394 "limbaj.y"
                            { s3: printf("nu mi place aici \n");}
#line 1924 "y.tab.c"
    break;

  case 39:
#line 395 "limbaj.y"
                           { printf("HEI AM SARIT PESTE ASTA\n"); }
#line 1930 "y.tab.c"
    break;

  case 40:
#line 395 "limbaj.y"
                                                                         {s4: printf("am iesit"); conditie=0;}
#line 1936 "y.tab.c"
    break;

  case 41:
#line 398 "limbaj.y"
          {
               ;//cod
          }
#line 1944 "y.tab.c"
    break;

  case 42:
#line 401 "limbaj.y"
               {
                    ;//cod
               }
#line 1952 "y.tab.c"
    break;

  case 43:
#line 404 "limbaj.y"
               {
                    ;//cod
               }
#line 1960 "y.tab.c"
    break;

  case 44:
#line 407 "limbaj.y"
          {
               ;//cod
          }
#line 1968 "y.tab.c"
    break;

  case 45:
#line 410 "limbaj.y"
                         {
                              ;//cod
                         }
#line 1976 "y.tab.c"
    break;

  case 46:
#line 419 "limbaj.y"
                    {
                         ;//cod
                    }
#line 1984 "y.tab.c"
    break;

  case 47:
#line 422 "limbaj.y"
                          {
                         ;//cod
                    }
#line 1992 "y.tab.c"
    break;

  case 48:
#line 428 "limbaj.y"
                       {
                         ;//cod
                    }
#line 2000 "y.tab.c"
    break;


#line 2004 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 432 "limbaj.y"

 
void yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
errors++;
}
 
// FUNCTIA EVAL
 
int main(int argc, char **argv) {
    strcpy(tabel_fnc[0].nume, "Eval");
    tabel_fnc[0].param_types[0] = strdup("int");
    tabel_fnc[0].is_method = 0;
    tabel_fnc[0].params_count = 1;
    
    
    fd = fopen("table.txt", "ab+");
    fprintf(fd, "salutare");
    if (fd == NULL) {
        printf("eroare");
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    if (errors == 0) {
        printf("Program corect sintactic!\n");
        printf("Afisez varle din tabel_varul cu variabile:  \n");
        for (int i = 0; i < total_vars; i++)
            printf("\t%-10s %-10s %-5s %-10s %-10s \n", tabel_var[i].id, tabel_var[i].value, tabel_var[i].type,tabel_var[i].scope, tabel_var[i].where);
        printf("fun decl %d:\n", total_fnc);
        for (int i = 0; i < total_fnc; i++){
            printf("\t%-10s ", tabel_fnc[i].nume);
            for(int ii = 0; ii < tabel_fnc[i].params_count; ++ii)
               printf("%-10s ", tabel_fnc[i].param_types[ii]);
            printf("\n");
        }
    } else {
        printf("Au fost gasite erori de compilare\n");
    }
}
int exists_in_var_table(char id[100])  //cauta o variabila in tabel_vara, daca exista
{
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, id) == 0)
            return 1;
    }
    return 0;
}
char* get_var_table(char id[100])  //cauta o variabila in tabel_vara, daca exista
{
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, id) == 0)
            return tabel_var[i].value;
    }
    return "eroare";
}
int get_var_value(char id[100])  //cauta o variabila in tabel_vara, daca exista
{
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, id) == 0)
            return atoi(tabel_var[i].value);
    }
    return 0;
}

char* get_var_scope(char id[100])  //cauta o variabila in tabel_vara, daca exista
{
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, id) == 0)
            return tabel_var[i].scope;
    }
    return "eroare";
}
int exists_in_var_table_s(struct var *x) 
{
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, x->id) == 0)
          if(strcmp(tabel_var[i].type, x->type)==0)
            return 1;
    }
    return 0;
}

int exists_function (char x[100])
{
    for(int i=0; i< total_fnc; i++)
        if(strcmp(tabel_fnc[i].nume, x)==0)
            return 1;
    return 0;
}
 
int is_default(char x[100])  //verifica daca o variabila are vreo valoare atribuita sau a ramas doar de la atribuire
{
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, x) == 0)
            if (strcmp(tabel_var[i].value, "default") == 0)
                return 1;
    }
    return 0;
}
void update_var_int(char x[100], int valoare)  
{
    char valuex[100];
    int j;
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, x) == 0)
            j = i;
    }
    sprintf(tabel_var[j].value,"%d", valoare);
}
void update_var(char x[100], char y[100])  //face update in tabel_vara pt atribuiri de genul x:=5 , nu merge si pentru x:=y
{
    char valuex[100];
    int j;
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, y) == 0)
            strcpy(valuex, tabel_var[i].value);
        if (strcmp(tabel_var[i].id, x) == 0)
            j = i;
    }
    strcpy(tabel_var[j].value, valuex);
}

int update_var_s(struct var *to, struct var *from) {
    if(exists_in_var_table_s(to)){
         if(same_type_s(to, from))
               strcpy(to->value, from->value);
          else {
               printf("trying to assign %s (%s) a value of incompatible type (%s)\n", to->id, to->type, from->type);
               yyerror("");
          }
    }
    else{
          printf("trying to assign a value to an undefiend var: %s\n", to->id);
          yyerror("");
    }
}
 
int same_type(char x[100], char y[100])  // verifica daca 2 var au acelasi tip (ex nu se poate float=int)
{
    char typex[100], typey[100];
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, x) == 0)
            strcpy(typex, tabel_var[i].type);
        if (strcmp(tabel_var[i].id, y) == 0)
            strcpy(typey, tabel_var[i].type);
    }
    if (strcmp(typex, typey) == 0)
        return 1;
    return 0;
}
int same_scope(char x[100], char y[100])  
{
    char typex[100], typey[100];
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, x) == 0)
            strcpy(typex, tabel_var[i].scope);
        if (strcmp(tabel_var[i].id, y) == 0)
            strcpy(typey, tabel_var[i].scope);
    }
    if (strcmp(typex, typey) == 0)
        return 1;
    return 0;
}

int same_type_s(struct var *x, struct var *y) 
{
    if (strcmp(x->type, y->type) == 0)
        return 1;
    return 0;
}
 
int same_type_number(char x[100], char y[100])  //verifica daca o variabila si nr atribuit au acelasi tip (ex nu se poate float=int)
{
    char typex[100];
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, x) == 0)
            strcpy(typex, tabel_var[i].type);
    }
    if (strcmp(typex, y) == 0)
        return 1;
    return 0;
}
 
int exists_signature(struct signature *new_f) {
     for (int ii = 0; ii < total_fnc; ++ii) {
        if (strcmp(tabel_fnc[ii].nume, new_f->nume) == 0) {
            if (tabel_fnc[ii].is_method == new_f->is_method) {
                if (tabel_fnc[ii].params_count == new_f->params_count) {
                    for (int j = 0; j < new_f->params_count; j++) {
                        if (strcmp(tabel_fnc[ii].param_types[j],
                                   new_f->param_types[j]) != 0)
                            return 0;
                    }
                    printf("%s redefined with same signature", new_f->nume);
                    yyerror("");
                    return 1;
                }
            }
        }
    }
    return 0;
}
 
int add_signature(struct signature *new_f) {
     strcpy(tabel_fnc[total_fnc].nume, new_f->nume);
     strcpy(tabel_fnc[total_fnc].parent_class, new_f->nume);
     tabel_fnc[total_fnc].is_method = new_f->is_method;
     tabel_fnc[total_fnc].params_count = new_f->params_count;
     for (int i = 0; i < tabel_fnc[total_fnc].params_count; ++i) {
         tabel_fnc[total_fnc].param_types[i] = strdup(new_f->param_types[i]);
         free(new_f->param_types[i]);
     }
     new_f->params_count = 0; //cleanup
     return 1;
}

struct var * get_var_from_table(char id[100]){
     for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, id) == 0)
            return &tabel_var[i];
    }
    return NULL;
}

void update_int(char x[100], int y) {
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(tabel_var[i].id, x) == 0)
            sprintf(tabel_var[i].value, "%d", y);
    }
}

void stack_push(struct var new_elem){
    if(stack_idx == 1000){
        printf("cam full stiva asta\n");
        return;
    }
    stack[stack_idx++] = new_elem;
}

int stack_pop(){
    if(stack_idx == 0){
        return -1;
    }
    return --stack_idx;
}

void var_assign(struct var *to, struct var * from){
    if(!same_type_s(to, from)){
        yyerror("");
        ++err_count;
        printf("assigning incompatible types: %s <- %s (%s = %s)\n", 
            to->type, from->type, to->id, from->id);
    }
    if(strcmp(from->value, "default") == 0){
        yyerror("");
        ++err_count;
        printf("assigning with uninitialised variable: %s = %s (<- this is uninitialised)\n", 
            to->id, from->id);
    }
    if(strcmp(to->type, "int") == 0){
        strcpy(to->value, from->value);
        return;
    }
    if(strcmp(to->type, "float") == 0){
        strcpy(to->value, from->value);
        return;
    }
    if(strcmp(to->type, "bool") == 0){
        strcpy(to->value, from->value);
        return;
    }
    if(strcmp(to->type, "char") == 0){
        strcpy(to->value, from->value);
        return;
    }
    if(strcmp(to->type, "string") == 0){
        strcpy(to->value, from->value);
        return;
    }
}

/* 
 lex limbaj.l; yacc -d limbaj.y
 
gcc lex.yy.c y.tab.c
 
todo:
-avem operatii cu int (NR), trebuie adaugate ca operatii si cele cu float
-trebuie actualizata valoarea unei variabile atunci cand este de forma x=x+y (cand sunt operatii)
-adaugarea vectorilor
-adaugare in vector (verific daca nu depasesc lungimea)
-de adaugat operatii cu stringuri (strlen, strcpy, strcat <este deja la laborator>)
-actualizare var bool (+ operatii cu bool)
-verificare daca parametrii pt apelul functiei sunt aceeasi cu cei ai functiei declarate(daca exista)
 
 
done:
-tabel_vara pentru fnc (exact la fel ca la variabile)
-trebuie verificat si pentru atribuirile de forma x= x+y daca sunt de acelasi tip sau daca au fost
initializate sau daca au fost declarate
 
*/
