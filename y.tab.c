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
 

#define _int 1
#define _char 2
#define _float 3
#define _bool 4
#define _string 5

struct var{
          char  id[100], type[100], value[100], scope[100], where[100];
          char *arr_data[100];
          int is_arr, arr_len, idx_init[100];
          };
 
struct signature{
          char nume[100], parent_class[100], ret_type[100];
          int is_method, params_count;
          char * param_types[100];
};
struct var tabel_var[1000];
struct var stack[1000];

char nume_clasa[100], nume_functie[100];
struct signature tabel_fnc[100];
struct signature new_function_buff;
int total_vars=0, errors=0, total_fnc=1, param=0, var_in_class, ok=0, var_in_fun, ok_fun;
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
void update_var_int(char x[100], int valoare);
char * get_var_table(char id[100]) ;
char* get_var_scope(char id[100]) ;
int get_var_value(char id[100]);
int same_scope(char x[100], char y[100]) ;
int exists_function (char x[100]);
void stack_push(struct var new_elem);
int stack_pop(); //ASTA DA POP LA INDEX 
float get_float_cast(struct var *from, const int idx);
int get_type(struct var * from);
int check_idx(struct var *x, const int idx);
int val_expr;

#line 138 "y.tab.c"

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
    CONST = 262,
    ASSIGN = 263,
    VIS = 264,
    CLASS = 265,
    IF = 266,
    WHILE = 267,
    FOR = 268,
    OP_BIN = 269,
    OP_STR = 270,
    BOOL = 271,
    STRING = 272,
    AND = 273,
    OR = 274,
    NOT = 275,
    FLOAT = 276,
    NR = 277,
    ARR_ACCESS = 278,
    CHR = 279,
    STR_ASSIGN = 280
  };
#endif
/* Tokens.  */
#define ID 258
#define TIP 259
#define BGIN 260
#define END 261
#define CONST 262
#define ASSIGN 263
#define VIS 264
#define CLASS 265
#define IF 266
#define WHILE 267
#define FOR 268
#define OP_BIN 269
#define OP_STR 270
#define BOOL 271
#define STRING 272
#define AND 273
#define OR 274
#define NOT 275
#define FLOAT 276
#define NR 277
#define ARR_ACCESS 278
#define CHR 279
#define STR_ASSIGN 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 69 "limbaj.y"

    char *strval;
    int intval;
    int blval;
    struct nmbr{
        float value;
        int type;
        int type_err;
    } number;

#line 251 "y.tab.c"

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
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

#define YYUNDEFTOK  2
#define YYMAXUTOK   280


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    29,    27,    31,    28,    21,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    37,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    23,    24,    25,
      26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    91,    92,    97,   113,   133,   152,   166,
     167,   179,   188,   200,   215,   216,   221,   226,   227,   231,
     265,   312,   340,   355,   378,   401,   426,   452,   457,   469,
     470,   471,   475,   476,   477,   478,   479,   483,   484,   503,
     521,   522,   526,   538,   551,   552,   556,   557,   564,   567,
     568,   569,   570,   571,   572,   579,   583,   587
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TIP", "BGIN", "END", "CONST",
  "ASSIGN", "VIS", "CLASS", "IF", "WHILE", "FOR", "OP_BIN", "OP_STR",
  "BOOL", "STRING", "AND", "OR", "NOT", "'.'", "FLOAT", "NR", "ARR_ACCESS",
  "CHR", "STR_ASSIGN", "'+'", "'-'", "'*'", "'/'", "','", "'('", "')'",
  "'{'", "'}'", "':'", "';'", "$accept", "progr", "fnc", "lista_param",
  "functie", "clasa", "decl_cl", "declaratiecl", "bloc", "list",
  "statement", "operatii", "variable", "decl_gl", "declaratie",
  "lista_apel", "bool", "operatii_binare", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    46,   276,   277,   278,   279,   280,    43,    45,    42,
      47,    44,    40,    41,   123,   125,    58,    59
};
# endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,    88,    87,   110,    64,    56,   -63,   102,   121,    90,
     -63,   -63,    19,   100,   130,    78,   -63,   -63,   132,   -63,
      27,   127,   105,    96,   -63,   -63,   -63,   134,   -63,   103,
      38,    60,   137,   109,   111,   112,    91,   108,   139,   142,
     113,    65,     4,   145,    55,    52,    21,   125,    61,    61,
     147,   -63,   114,   -63,   -63,   149,     6,   116,    96,   120,
     131,   -63,    94,   -63,   -63,     4,   140,   -63,   -63,   135,
     -63,   -63,    84,   -63,   144,   -63,   123,   -63,   128,   152,
     -63,   133,   159,   -63,    18,   126,   -63,     2,    96,   -63,
       4,     4,     4,     4,    94,   -63,   -63,    42,   -63,   161,
     136,   138,   163,    45,   141,   -63,   -63,   -63,     5,    89,
      89,   -63,   -63,   143,   -63,   -63,   -63,    96,    96,   146,
     -63,    95,    46,   -63,    33,     8,    22,   164,   -63,   113,
      98,   -63,    99,   -63,   -63,   148,   120,   -63,     4,    83,
     150,    96,    35,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    42,     1,     0,     0,     0,
      40,    43,     0,     0,     0,     0,     3,    41,     0,    45,
       0,     0,     0,     0,     4,     2,     5,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,    16,     0,    17,     6,     0,     0,     0,     0,     0,
      38,    37,    19,    36,    26,     0,     0,    21,    24,    47,
      46,    27,     0,    22,     0,    55,     0,    56,     0,     0,
      18,    13,     0,    10,     0,     0,    11,     0,     0,    39,
       0,     0,     0,     0,    20,    25,    48,    54,    28,     0,
       0,     0,     0,     0,    13,     9,    12,     8,     0,    32,
      33,    34,    35,    50,    53,    49,    57,     0,     0,     0,
      15,     0,     0,     7,     0,     0,     0,     0,    14,    15,
       0,    52,     0,    29,    30,     0,    14,    51,     0,     0,
       0,     0,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   115,   -29,   -11,   -63,   -63,   118,   -63,   -56,
     -36,   -62,   -63,   -63,   165,    53,   129,    49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    15,    20,    16,     8,    56,    57,    25,    36,
      37,    62,    63,     3,     4,    72,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    41,    87,    94,    24,    31,    32,    60,    31,    32,
      82,    31,    32,    33,    34,    35,    33,    34,    35,    33,
      34,    35,    14,    18,    69,    31,    32,    61,   109,   110,
     111,   112,   108,    33,    34,    35,    69,   107,    31,    32,
     123,    83,    18,   133,    70,   113,    33,    34,    35,    18,
      18,    52,    19,   105,    71,    67,    70,   134,    27,   114,
      28,   125,   126,    65,    74,   115,   131,     1,    42,    68,
     143,    40,    52,    24,   121,    43,   139,    75,   120,   129,
      11,    66,    14,    23,    44,   142,    45,     6,    12,    52,
      52,     5,    46,   130,    31,    32,    27,    51,    59,    31,
      32,    10,    33,    34,    35,    13,    52,    33,    34,    35,
      90,    91,    92,    93,     1,    97,   140,    98,    92,    93,
       7,    90,    91,    92,    93,    14,    27,    17,   128,    27,
      97,   136,   137,    22,    21,    26,    29,    30,    38,    39,
      47,    48,    54,    49,    50,    53,    55,    58,    64,    73,
      79,    80,    81,    86,    88,    89,   100,    95,    99,    96,
     102,   101,   104,   106,   116,   103,   119,    74,     9,     0,
     117,    84,   118,   122,    85,   124,   135,   132,    78,     0,
       0,     0,     0,   127,   141,   138
};

static const yytype_int16 yycheck[] =
{
      36,    30,    58,    65,    15,     3,     4,     3,     3,     4,
       4,     3,     4,    11,    12,    13,    11,    12,    13,    11,
      12,    13,     4,     4,     3,     3,     4,    23,    90,    91,
      92,    93,    88,    11,    12,    13,     3,    35,     3,     4,
      35,    35,     4,    35,    23,     3,    11,    12,    13,     4,
       4,    87,    33,    35,    33,     3,    23,    35,    31,    17,
      33,   117,   118,     8,     3,    23,    33,     4,     8,    17,
      35,    33,   108,    84,   103,    15,   138,    16,    33,    33,
      24,    26,     4,     5,    24,   141,    26,     0,    32,   125,
     126,     3,    32,   122,     3,     4,    31,     6,    33,     3,
       4,    37,    11,    12,    13,     3,   142,    11,    12,    13,
      27,    28,    29,    30,     4,    31,    33,    33,    29,    30,
      10,    27,    28,    29,    30,     4,    31,    37,    33,    31,
      31,    33,    33,     3,    34,     3,     9,    32,     4,    36,
       3,    32,     3,    32,    32,    37,     4,    34,     3,    24,
       3,    37,     3,    37,    34,    24,    33,    17,    14,    24,
       8,    33,     3,    37,     3,    32,     3,     3,     3,    -1,
      34,    56,    34,    32,    56,    32,   127,   124,    49,    -1,
      -1,    -1,    -1,    37,    34,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    39,    51,    52,     3,     0,    10,    43,    52,
      37,    24,    32,     3,     4,    40,    42,    37,     4,    33,
      41,    34,     3,     5,    42,    46,     3,    31,    33,     9,
      32,     3,     4,    11,    12,    13,    47,    48,     4,    36,
      33,    41,     8,    15,    24,    26,    32,     3,    32,    32,
      32,     6,    48,    37,     3,     4,    44,    45,    34,    33,
       3,    23,    49,    50,     3,     8,    26,     3,    17,     3,
      23,    33,    53,    24,     3,    16,    54,    55,    54,     3,
      37,     3,     4,    35,    40,    45,    37,    47,    34,    24,
      27,    28,    29,    30,    49,    17,    24,    31,    33,    14,
      33,    33,     8,    32,     3,    35,    37,    35,    47,    49,
      49,    49,    49,     3,    17,    23,     3,    34,    34,     3,
      33,    41,    32,    35,    32,    47,    47,    37,    33,    33,
      41,    33,    53,    35,    35,    55,    33,    33,    37,    49,
      33,    34,    47,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    45,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     2,     4,     8,     7,     8,
       7,     2,     3,     2,     5,     4,     3,     2,     3,     3,
       4,     3,     3,     2,     3,     4,     3,     3,     4,     7,
       7,    13,     3,     3,     3,     3,     1,     1,     1,     2,
       2,     3,     2,     3,     5,     4,     1,     1,     2,     3,
       3,     6,     5,     3,     2,     1,     1,     3
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
#line 91 "limbaj.y"
               {}
#line 1520 "y.tab.c"
    break;

  case 4:
#line 92 "limbaj.y"
                    {}
#line 1526 "y.tab.c"
    break;

  case 5:
#line 97 "limbaj.y"
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
#line 1547 "y.tab.c"
    break;

  case 6:
#line 113 "limbaj.y"
                              {    
        if(ok_fun==0)
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
         // printf("HEI, SUNT AICI \n");
    }
#line 1568 "y.tab.c"
    break;

  case 7:
#line 133 "limbaj.y"
                                                 { 
        //decl globala functie
        strcpy(new_function_buff.ret_type, (yyvsp[-7].strval));
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
#line 1592 "y.tab.c"
    break;

  case 8:
#line 152 "limbaj.y"
                                  { 
        strcpy(new_function_buff.ret_type, (yyvsp[-6].strval));
        new_function_buff.params_count = 0;
        strcpy(new_function_buff.nume, (yyvsp[-5].strval));
        if(exists_signature(&new_function_buff) == 1)
             yyerror(), printf("function %s redefined", new_function_buff.nume);
        else
             add_signature(&new_function_buff);
             total_fnc++;
    }
#line 1607 "y.tab.c"
    break;

  case 9:
#line 166 "limbaj.y"
                                             {strcpy(nume_clasa, (yyvsp[-6].strval));}
#line 1613 "y.tab.c"
    break;

  case 10:
#line 167 "limbaj.y"
                                        {
                                             strcpy(nume_clasa, (yyvsp[-5].strval)); //cod
                                            //  printf("%d, %d\n", var_in_class, total_vars);
                                             for (int i=var_in_class-2; i<total_vars; i++)
                                             {
                                                  strcpy(tabel_var[i].where, nume_clasa);
                                             }
                                             ok=0;
                                             
                                        }
#line 1628 "y.tab.c"
    break;

  case 11:
#line 179 "limbaj.y"
                           {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars+1;
                                        ok=1;
                                   }
                              strcpy(tabel_var[total_vars].scope, "clasa");
                              //cod
                         }
#line 1642 "y.tab.c"
    break;

  case 12:
#line 188 "limbaj.y"
                                {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars;
                                        ok=1;
                                   }
                                    strcpy(tabel_var[total_vars].scope, "clasa");
                                  //cod
                              }
#line 1656 "y.tab.c"
    break;

  case 13:
#line 200 "limbaj.y"
               { 
                    if(exists_in_var_table((yyvsp[0].strval))==0)
                    {
                         strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
                         strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
                         strcpy(tabel_var[total_vars].value, "default");
                         strcpy(tabel_var[total_vars].scope, "clasa");
                         strcpy(tabel_var[total_vars].where, nume_clasa);
                        //  printf("NUME: CLASA : %s\n", nume_clasa);
                         total_vars++;
                         
                         }
                    else
                         yyerror(); 
               }
#line 1676 "y.tab.c"
    break;

  case 14:
#line 215 "limbaj.y"
                                  {}
#line 1682 "y.tab.c"
    break;

  case 15:
#line 216 "limbaj.y"
                      {}
#line 1688 "y.tab.c"
    break;

  case 16:
#line 221 "limbaj.y"
                         {}
#line 1694 "y.tab.c"
    break;

  case 17:
#line 226 "limbaj.y"
                        {}
#line 1700 "y.tab.c"
    break;

  case 18:
#line 227 "limbaj.y"
                              { }
#line 1706 "y.tab.c"
    break;

  case 19:
#line 231 "limbaj.y"
                        {
        // printf("%s assign operatii result: %f\n", $1,$3.value);
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table((yyvsp[-2].strval));
        if (dol1 == NULL)
            {yyerror(); printf("undeclared var: %s\n", (yyvsp[-2].strval)); return 0;}
        int t = get_type(dol1);
        if(t != (yyvsp[0].number).type){
            {yyerror(); printf("the right side of the assignment does not have the same type as left side\n"); return 0;}
        }
        if((yyvsp[0].number).type_err > 0)
                {yyerror(); printf("the right side of the assignment does not have the same type throughout the assignment\n"); return 0;}
        else
        if(strcmp(dol1->type, "float") == 0){
            char temp[100];
            sprintf(temp, "%f", (yyvsp[0].number).value);
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "int") == 0){
            char temp[100];
            sprintf(temp, "%d", (int)(yyvsp[0].number).value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "bool") == 0){
            printf("da BOOL\n");
            char temp[100];
            sprintf(temp, "%d", (bool)(yyvsp[0].number).value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
    }
#line 1745 "y.tab.c"
    break;

  case 20:
#line 265 "limbaj.y"
                                    {
        // printf("id[arr] assign operatii result: %f\n", $4.value);
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table((yyvsp[-3].strval));
        if (dol1 == NULL)
            {yyerror(); printf("undeclared arr: %s\n", (yyvsp[-3].strval)); return 0;}
        if(check_idx(dol1, (yyvsp[-2].intval)) != 0) return 0;
        if(strcmp(dol1->type, "string") == 0) {yyerror(); printf("illegal operation on string %s\n", dol1->id); return 0;}
        if(get_type(dol1) != (yyvsp[0].number).type) {yyerror(); printf("the right side of the assignment does not have the same type as left side\n"); return 0;}
        if((yyvsp[0].number).type_err > 0) {yyerror(); printf("the right side of the assignment does not have the same type throughout the assignment\n"); return 0;}
        
        if(strcmp(dol1->type, "float") == 0){
            if((yyvsp[0].number).type != _float) {yyerror(); printf("the right side of the assignment does not have the same type as left side\n"); return 0;}
            char temp[100];
            sprintf(temp, "%f", (yyvsp[0].number).value);
            dol1->arr_data[(yyvsp[-2].intval)] = strdup(temp);
            dol1->idx_init[(yyvsp[-2].intval)] = 1;
        }
        else 
        if(strcmp(dol1->type, "int") == 0){
            if((yyvsp[0].number).type != _int) {yyerror(); printf("the right side of the assignment does not have the same type as left side\n"); return 0;}
            char temp[100];
            sprintf(temp, "%d", (int)((yyvsp[0].number).value));
            dol1->arr_data[(yyvsp[-2].intval)] = strdup(temp);
            dol1->idx_init[(yyvsp[-2].intval)] = 1;
        }
        else 
        if(strcmp(dol1->type, "bool") == 0){
            if((yyvsp[0].number).type != _bool) {yyerror(); printf("the right side of the assignment does not have the same type as left side\n"); return 0;}
            char temp[100];
            sprintf(temp, "%d", (int)((yyvsp[0].number).value));
            dol1->arr_data[(yyvsp[-2].intval)] = strdup(temp);
            dol1->idx_init[(yyvsp[-2].intval)] = 1;
        }
        else
        if(strcmp(dol1->type, "char") == 0){
            if((yyvsp[0].number).type != _char) {yyerror(); printf("the right side of the assignment does not have the same type as left side\n"); return 0;}
            char temp[100];
            if((yyvsp[0].number).value > 255) {printf("char overflow\n"); (yyvsp[0].number).value = (int)((yyvsp[0].number).value) % 255;}
            // sprintf(temp, "%c", (char)($4.value));
            temp[0] = (char)((yyvsp[0].number).value);
            temp[1] = '\0';
            printf("%s\n", temp);
            dol1->arr_data[(yyvsp[-2].intval)] = strdup(temp);
            dol1->idx_init[(yyvsp[-2].intval)] = 1;
        }
    }
#line 1797 "y.tab.c"
    break;

  case 21:
#line 312 "limbaj.y"
                       {
        struct var * dol1;
        struct var * dol3;
        dol1 = get_var_from_table((yyvsp[-2].strval));
        dol3 = get_var_from_table((yyvsp[0].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[-2].strval)); return 0;}
        if (dol3 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[-2].strval)); return 0;}
        if(same_type_s(dol1, dol3)){
            if(strcmp(dol1->type, "string") != 0){
                yyerror(); 
                printf("trying to do string operation on non string variables\n");
                break;
            }
            if(strcmp(dol1->scope, "main") != 0 && strcmp(dol1->scope, "global") != 0)
                {yyerror(); printf("accessig var from outer scope: %s\n", (yyvsp[-2].strval)); return 0;}
            if(strcmp(dol3->scope, "main") != 0 && strcmp(dol3->scope, "global") != 0)
                {yyerror(); printf("accessig var from outer scope: %s\n", (yyvsp[0].strval)); return 0;}
                
            var_assign(dol1, dol3);
        }
        else{
            yyerror(); 
            printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, (yyvsp[-1].strval), dol3->type);
            break;
        }
    }
#line 1830 "y.tab.c"
    break;

  case 22:
#line 340 "limbaj.y"
                        {
        // printf("declared array %d\n", $3);
        if((yyvsp[0].intval) > 100) {yyerror(""), printf("\tmax arr size is 100 and you declared %d\n", (yyvsp[0].intval)); return 0;}
        struct var * dol2;
        dol2 = get_var_from_table((yyvsp[-1].strval));
        if (dol2 != NULL && (same_scope(dol2->id, (yyvsp[-1].strval))))
            {yyerror(), printf("already declared array: %s\n", (yyvsp[-1].strval)); return 0;}
        strcpy(tabel_var[total_vars].id, (yyvsp[-1].strval));
        strcpy(tabel_var[total_vars].type, (yyvsp[-2].strval));
        strcpy(tabel_var[total_vars].value, "default");
        strcpy(tabel_var[total_vars].scope, "main");
        tabel_var[total_vars].arr_len = (yyvsp[0].intval);
        tabel_var[total_vars].is_arr = 1;
        total_vars++;
    }
#line 1850 "y.tab.c"
    break;

  case 23:
#line 355 "limbaj.y"
              { 
        // printf("declarare tip id\n");
        if(ok_fun==0){
             var_in_fun=total_vars;
             ok_fun=1;
        }
 
        if(exists_in_var_table((yyvsp[0].strval))==0)
        {
             strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
             strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
             strcpy(tabel_var[total_vars].value, "default");
             strcpy(tabel_var[total_vars].scope, "main");
             total_vars++;
        }
        else
             {yyerror(), printf("already declared variable1: %s\n", (yyvsp[0].strval)); return 0;} 
        // printf("%d\n", ok_fun);
        if(ok_fun==1)
        {
             strcpy(tabel_var[total_vars].scope, "functie");
        }
    }
#line 1878 "y.tab.c"
    break;

  case 24:
#line 378 "limbaj.y"
                           {
        struct var * dol1;
        struct var dol3;
        dol1 = get_var_from_table((yyvsp[-2].strval));
        strcpy(dol3.type, "string");
        strcpy(dol3.value, (yyvsp[0].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[-2].strval)); return 0;}
        
        if(same_type_s(dol1, &dol3)){
            if(strcmp(dol1->type, "string") != 0){
                yyerror(); 
                printf("trying to do string operation on non string variables\n");
                break;
            }
            var_assign(dol1, &dol3);
        }
        else{
            yyerror(); 
            printf("trying to do stringa assign operation on variables of different types: %s %s\n", dol1->type, dol3.type);
            break;
        }
    }
#line 1906 "y.tab.c"
    break;

  case 25:
#line 401 "limbaj.y"
                                      {
        struct var * dol1;
        struct var dol4;
        dol1 = get_var_from_table((yyvsp[-3].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[-3].strval)); return 0;}
        int res = check_idx(dol1, (yyvsp[-2].intval));
        if(res != 0) return 0;
        strcpy(dol4.type, "string");
        strcpy(dol4.value, (yyvsp[-1].strval));
        
        if(same_type_s(dol1, &dol4)){
            if(strcmp(dol1->type, "string") != 0){
                yyerror(); 
                printf("trying to do string operation on non string variables\n");
                break;
            }
            var_assign(dol1, &dol4);
        }
        else{
            yyerror(); 
            printf("trying to do stringa assign operation on variables of different types: %s %s\n", dol1->type, dol4.type);
            break;
        }
    }
#line 1936 "y.tab.c"
    break;

  case 26:
#line 426 "limbaj.y"
                   {
        struct var * dol1;
        struct var * dol3;
        dol1 = get_var_from_table((yyvsp[-2].strval));
        dol3 = get_var_from_table((yyvsp[0].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[-2].strval)); return 0;}
        if (dol3 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[0].strval)); return 0;}
        if(strcmp(dol3->value, "default") == 0)
            {yyerror(), printf("uninitialised string: %s\n", (yyvsp[0].strval)); return 0;}
        if(strcmp(dol1->value, "default") == 0)
            {yyerror(), printf("uninitialised string: %s\n", (yyvsp[-2].strval)); return 0;}
        if(same_type_s(dol1, dol3)){
            if(strcmp(dol1->type, "string") != 0){
                yyerror(); 
                printf("trying to do string operation on non string variables\n");
                return 0;
            }
            strcat(dol1->value, dol3->value);
        }
        else{
            yyerror(); 
            printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, (yyvsp[-1].strval), dol3->type);
        }
    }
#line 1967 "y.tab.c"
    break;

  case 27:
#line 452 "limbaj.y"
                 {      
        printf("apel functie din main\n");
        if(exists_function((yyvsp[-2].strval))==0)
            {yyerror(), printf("call to undeclared function: %s\n", (yyvsp[-2].strval)); return 0;}
    }
#line 1977 "y.tab.c"
    break;

  case 28:
#line 457 "limbaj.y"
                            {
        printf("apel funectie din main + lista apel\n");
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
#line 1994 "y.tab.c"
    break;

  case 29:
#line 469 "limbaj.y"
                                       {}
#line 2000 "y.tab.c"
    break;

  case 30:
#line 470 "limbaj.y"
                                       {}
#line 2006 "y.tab.c"
    break;

  case 31:
#line 471 "limbaj.y"
                                                                                {}
#line 2012 "y.tab.c"
    break;

  case 32:
#line 475 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value + (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2018 "y.tab.c"
    break;

  case 33:
#line 476 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value - (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2024 "y.tab.c"
    break;

  case 34:
#line 477 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value * (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2030 "y.tab.c"
    break;

  case 35:
#line 478 "limbaj.y"
                            { if((yyvsp[0].number).value == 0) printf("aoleu, imparti la 0\n");(yyval.number).value = (yyvsp[-2].number).value / (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2036 "y.tab.c"
    break;

  case 36:
#line 479 "limbaj.y"
               {/*NON STRING VARIABLE*/}
#line 2042 "y.tab.c"
    break;

  case 37:
#line 483 "limbaj.y"
         { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type_err = 0; (yyval.number).type = (yyvsp[0].number).type;}
#line 2048 "y.tab.c"
    break;

  case 38:
#line 484 "limbaj.y"
         {
        printf("id %s\n", (yyvsp[0].strval));
        struct var * dol1;
        dol1 = get_var_from_table((yyvsp[0].strval)); 
        if (dol1 == NULL)
            {yyerror(), printf("undeclared variable: %s\n", (yyvsp[0].strval)); return 0;}
        if(strcmp(dol1->scope, "main") != 0 && strcmp(dol1->scope, "global") != 0){
            {yyerror(); printf("accessig var from outer scope: %s\n", (yyvsp[0].strval)); return 0;}
        }
        if(strcmp(dol1->value, "default") == 0){
            {yyerror(); printf("uninitialised var on the right side: %s\n", (yyvsp[0].strval)); return 0;}
        }
        (yyval.number).type = get_type(dol1);
        if((yyval.number).type == _string){
            {yyerror(); printf("illegal opreration on string variable: %s\n", (yyvsp[0].strval)); return 0;}
        }
        (yyval.number).value = get_float_cast(dol1, -1);
        (yyval.number).type_err = 0;
    }
#line 2072 "y.tab.c"
    break;

  case 39:
#line 503 "limbaj.y"
                    {
        struct var * dol1;
        dol1 = get_var_from_table((yyvsp[-1].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared variable: %s\n", (yyvsp[-1].strval)); return 0;} 
        if(strcmp(dol1->scope, "main") != 0 && strcmp(dol1->scope, "global") != 0){
            {yyerror(); printf("accessig var from outer scope: %s\n", (yyvsp[-1].strval)); return 0;}
        }
        //verif pt uninitialised?
        if(dol1->idx_init[(yyvsp[0].intval)] == 0) {yyerror(); printf("access of uninitialised idx of array %s\n", (yyvsp[-1].strval)); return 0;}
        (yyval.number).value = get_float_cast(dol1, (yyvsp[0].intval));
        (yyval.number).type = get_type(dol1);
        (yyval.number).type_err = 0;
    }
#line 2091 "y.tab.c"
    break;

  case 40:
#line 521 "limbaj.y"
                       {strcpy(tabel_var[total_vars].scope, "global");}
#line 2097 "y.tab.c"
    break;

  case 41:
#line 522 "limbaj.y"
                             {strcpy(tabel_var[total_vars].scope, "global");}
#line 2103 "y.tab.c"
    break;

  case 42:
#line 526 "limbaj.y"
              {
        if(exists_in_var_table((yyvsp[0].strval))==0)
        {
             strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
             strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
             strcpy(tabel_var[total_vars].value, "default");
             strcpy(tabel_var[total_vars].scope, "global");
             total_vars++;
        }
        else
             yyerror(); 
    }
#line 2120 "y.tab.c"
    break;

  case 43:
#line 538 "limbaj.y"
                        {
        if(exists_in_var_table((yyvsp[-1].strval))==0){
            strcpy(tabel_var[total_vars].id, (yyvsp[-1].strval));
            strcpy(tabel_var[total_vars].type, (yyvsp[-2].strval));
            strcpy(tabel_var[total_vars].value, "default");
            strcpy(tabel_var[total_vars].scope, "global");
            total_vars++;
            tabel_var[total_vars].arr_len = (yyvsp[0].intval);
            tabel_var[total_vars].is_arr = 1;
        }
        else
             yyerror();
    }
#line 2138 "y.tab.c"
    break;

  case 44:
#line 551 "limbaj.y"
                                  {printf("var: %s\n", (yyvsp[-3].strval));}
#line 2144 "y.tab.c"
    break;

  case 45:
#line 552 "limbaj.y"
                     {}
#line 2150 "y.tab.c"
    break;

  case 46:
#line 556 "limbaj.y"
         {printf("small rule\n");}
#line 2156 "y.tab.c"
    break;

  case 47:
#line 557 "limbaj.y"
         {
        struct var * dol1;
        dol1 = get_var_from_table((yyvsp[0].strval));
        if (dol1 == NULL)
            {yyerror(), printf("function call with undeclared variable: %s\n", (yyvsp[0].strval)); return 0;} 

    }
#line 2168 "y.tab.c"
    break;

  case 48:
#line 564 "limbaj.y"
                   {
        
    }
#line 2176 "y.tab.c"
    break;

  case 49:
#line 567 "limbaj.y"
                        {printf("small rule apel functie\n");}
#line 2182 "y.tab.c"
    break;

  case 50:
#line 568 "limbaj.y"
                        {}
#line 2188 "y.tab.c"
    break;

  case 51:
#line 569 "limbaj.y"
                                           {/*idk man*/}
#line 2194 "y.tab.c"
    break;

  case 52:
#line 570 "limbaj.y"
                                {}
#line 2200 "y.tab.c"
    break;

  case 53:
#line 571 "limbaj.y"
                            {}
#line 2206 "y.tab.c"
    break;

  case 55:
#line 579 "limbaj.y"
           {
        // if(strcmp($1, "true") == 0) {$$ = 1; return 0;}
        // if(strcmp($1, "false") == 0) {$$ = 0; return 0;}
    }
#line 2215 "y.tab.c"
    break;

  case 56:
#line 583 "limbaj.y"
                      { (yyval.blval) = (yyvsp[0].blval); }
#line 2221 "y.tab.c"
    break;

  case 57:
#line 587 "limbaj.y"
                   {
        // printf("op binare\n");
        // struct var * dol1;
        // struct var * dol3;
        // dol1 = get_var_from_table($1);
        // dol3 = get_var_from_table($3);
        // if (dol1 == NULL)
        //     {yyerror(), printf("undeclared var: %s", $1); return 0;}
        // if (dol1 == NULL)
        //     {yyerror(), printf("undeclared var: %s", $3); return 0;}
        // if(same_type_s(dol1, dol3) && (same_scope($1, $3) || (strcmp(get_var_scope($3),"globala")==0))) {
        //     if(strcmp($2, "||")==0) {
        //         if(strcmp(dol1->type, "string")==0)
        //         return 0;
        //     }
        //     if(strcmp($2, "&&")==0){
        //         return 0;
        //     }
        //     if(strcmp($2, ">")==0){
        //         return 0;
        //     }
        //     if(strcmp($2, "<")==0){
        //         return 0;
        //     }
        //     if(strcmp($2, "!")==0){
        //         return 0;
        //     }
        //     if(strcmp($2, "<=")==0){
        //         return 0;
        //     }
        //     if(strcmp($2, ">=")==0){
        //         return 0;
        //     }
        //     if(strcmp($2, "!=")==0){
        //         return 0;
        //     }
        // }
        // else{
        //     yyerror(); 
        //     printf("trying to do binary operation on variables of different types: %s %s %s\n", dol1->type, $2, dol3->type);
        //     return 0;
        // }
    }
#line 2269 "y.tab.c"
    break;


#line 2273 "y.tab.c"

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
#line 632 "limbaj.y"

 
void yyerror(char * s){ 
    printf("eroare: %s la linia: %d\n", s ,yylineno); 
    errors++; 
}
 
void print_table(FILE* fd, int errs){
    if (errs == 0) {
        fprintf(fd, "\n\nProgram corect sintactic!\n");
    } else  {fprintf(fd, "Au fost gasite erori de compilare\n"); return;} 
    if (fd == NULL) 
        fd = stdout;
    fprintf(fd, "Var table:\n");
    fprintf(fd, "\n\t%-15s %-15s %-10s %-4s %-10s %-10s \n", "id", "value", "type", "arr?","scope", "additional");
    fprintf(fd, "\t%-15s %-15s %-10s %-4s %-10s %-10s \n", "---------", "------", "----","----","-----", "----------");

    for (int i = 0; i < total_vars; i++)
        fprintf(fd, "\t%-15s %-15s %-10s %-4s %-10s %-10s \n", tabel_var[i].id, tabel_var[i].value, tabel_var[i].type, (tabel_var[i].is_arr == 1 ? "yes" : "   ") ,tabel_var[i].scope, tabel_var[i].where);
    fprintf(fd, "\nfun decl %d:\n", total_fnc);
        fprintf(fd, "\t%-7s %-10s\n", "retType", "fnc");
    for (int i = 0; i < total_fnc; i++){
        fprintf(fd, "\t%-7s %-7s ", tabel_fnc[i].ret_type, tabel_fnc[i].nume);
        fprintf(fd, "\t(");
        for(int ii = 0; ii < tabel_fnc[i].params_count; ++ii)
           fprintf(fd, "%-4s", tabel_fnc[i].param_types[ii]);
        fprintf(fd, ")\n");
    }
    fprintf(fd, "\narrays:\n");
    fprintf(fd, "\t%-7s %-15s %-10s\n", "type", "id", "content");
    fprintf(fd, "\t%-7s %-15s %-10s\n", "----", "--", "below");
    for (int i = 0; i < total_vars; i++){
        if(tabel_var[i].is_arr == 1){
            fprintf(fd, "\t%-7s %-15s ", tabel_var[i].type, tabel_var[i].id);
            fprintf(fd, "\n");
            for(int ii = 0; ii < tabel_var[i].arr_len; ++ii){
                if(tabel_var[i].idx_init[ii] == 0)
                    continue;
                if(strcmp(tabel_var[i].type, "int") == 0 || strcmp(tabel_var[i].type, "bool") == 0){
                    int temp = 0;
                    sscanf(tabel_var[i].arr_data[ii], "%d", &temp);
                    fprintf(fd, "[%d]%d \n",ii , temp);
                } 
                if(strcmp(tabel_var[i].type, "char") == 0){
                    fprintf(fd, "[%d]%s \n",ii , tabel_var[i].arr_data[ii]);
                }
                if(strcmp(tabel_var[i].type, "float") == 0){
                    float temp;
                    sscanf(tabel_var[i].arr_data[ii], "%f", &temp);
                    fprintf(fd, "[%d]%f \n",ii , temp);
                }
                if(strcmp(tabel_var[i].type, "string") == 0){
                    fprintf(fd, "[%d]%s \n",ii , tabel_var[i].arr_data[ii]);
                }
            }
            fprintf(fd, "\n");
        }
    }
    fprintf(fd, "\n");
}
 
int main(int argc, char **argv) {
    strcpy(tabel_fnc[0].nume, "Eval");
    tabel_fnc[0].param_types[0] = strdup("int");
    tabel_fnc[0].is_method = 0;
    tabel_fnc[0].params_count = 1;
    
    FILE* fd;
    fd = fopen("table.txt", "w");
    if (fd == NULL) {
        printf("eroare");
    } 
    yyin = fopen(argv[1], "r");
    yyparse();

    print_table(fd, errors);
    
    print_table(stdout, errors);
    
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
     strcpy(tabel_fnc[total_fnc].ret_type, new_f->ret_type);
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
        
        printf("assigning incompatible types: %s <- %s (%s = %s)\n", 
            to->type, from->type, to->id, from->id);
    }
    if(strcmp(from->value, "default") == 0){
        yyerror("");
        
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

float get_float_cast(struct var *from, const int idx){
    if(idx < 0){
        if(strcmp(from->type, "int") == 0 || strcmp(from->type, "bool") == 0){
            int temp;
            sscanf(from->value, "%d", &temp);
            return (float)(temp);
        }
        if(strcmp(from->type, "char") == 0){
            return (float)(from->value[0]);
        }
        if(strcmp(from->type, "float") == 0){
            float temp;
            sscanf(from->value, "%f", &temp);
            return (float)(temp);
        }
        if(strcmp(from->type, "string") == 0){
            return 1;
        }
    }
    else {
        if(strcmp(from->type, "int") == 0 || strcmp(from->type, "bool") == 0){
            int temp;
            sscanf(from->arr_data[idx], "%d", &temp);
            return (float)(temp);
        }
        if(strcmp(from->type, "char") == 0){
            return (float)(from->arr_data[idx][0]);
        }
        if(strcmp(from->type, "float") == 0){
            float temp;
            sscanf(from->arr_data[idx], "%f", &temp);
            return (float)(temp);
        }
        if(strcmp(from->type, "string") == 0){
            return 1;
        }
    }
}

int get_type(struct var * from){
    if(strcmp(from->type, "int") == 0)
        return _int;
    if(strcmp(from->type, "bool") == 0)
        return _bool;
    if(strcmp(from->type, "char") == 0)
        return _char;
    if(strcmp(from->type, "string") == 0)
        return _string;
    if(strcmp(from->type, "float") == 0)
        return _float;
}

int check_idx(struct var *x, const int idx){
    if(x->is_arr == 0){
        yyerror("");
        printf("%s is not an array\n", x->id);
        return -1;
    }
    if(x->arr_len < idx){
        yyerror("");
        printf("accesing out of bound elem of array %s\n", x->id);
        return -1;
    }
    return 0;
}


/* 
 lex limbaj.l; yacc -d limbaj.y
 
gcc lex.yy.c y.tab.c
 
todo:
-adaugarea vectorilor
-adaugare in vector (verific daca nu depasesc lungimea)
-de adaugat operatii cu stringuri (strlen, strcpy, strcat <este deja la laborator>)
-actualizare var bool (+ operatii cu bool)
-verificare daca parametrii pt apelul functiei sunt aceeasi cu cei ai functiei declarate(daca exista)
 -tabel arrays
 
done:
-tabel_vara pentru fnc (exact la fel ca la variabile)
-trebuie verificat si pentru atribuirile de forma x= x+y daca sunt de acelasi tip sau daca au fost
initializate sau daca au fost declarate
 


 | ID ASSIGN ID {
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table($1);
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", $1); return 0;}
        struct var * dol3;
        dol3 = get_var_from_table($3);
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", $3); return 0;}
        if (dol1 != NULL && dol3!= NULL){
             if((same_scope($1, $3) || (strcmp(get_var_scope($3),"globala")==0))) 
                 update_var_s(dol1, dol3);
             else{
                  yyerror(); 
                  printf("trying to do operation on variables of different scopes: %s , %s\n", dol1->id, dol3->id);
                  break;
             }
        }
    }
*/
