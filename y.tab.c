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
          char  id[100], type[100], value[100], scope[100], where[100];
          char *string_arr_value[100]; float floats[100]; int ints[100];
          int is_arr, arr_len;
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
int val_expr;

#line 131 "y.tab.c"

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
    CHR = 279
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "limbaj.y"

    char *strval;
    int intval;
    int blval;
    struct nmbr{
        float value;
        int is_float;
    } number;

#line 238 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

#define YYUNDEFTOK  2
#define YYMAXUTOK   279


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
      31,    32,    28,    26,    30,    27,    21,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    23,    24,    25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    83,    84,    89,   105,   125,   144,   158,
     159,   171,   180,   192,   207,   208,   213,   218,   219,   223,
     245,   277,   296,   311,   335,   357,   381,   386,   398,   399,
     400,   405,   406,   407,   408,   409,   410,   416,   417,   421,
     433,   434,   438,   439,   446,   449,   450,   451,   452,   453,
     454,   461,   464,   470
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
  "CHR", "'+'", "'-'", "'*'", "'/'", "','", "'('", "')'", "'{'", "'}'",
  "':'", "';'", "$accept", "progr", "fnc", "lista_param", "functie",
  "clasa", "decl_cl", "declaratiecl", "bloc", "list", "statement",
  "operatii", "decl_gl", "declaratie", "lista_apel", "bool",
  "operatii_binare", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    46,   276,   277,   278,   279,    43,    45,    42,    47,
      44,    40,    41,   123,   125,    58,    59
};
# endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,    63,   118,    83,    47,    57,   -61,   102,    96,    92,
     -61,     6,    98,   127,   105,   -61,   -61,   129,   -61,    62,
     124,   103,   100,   -61,   -61,   -61,   131,   -61,   101,    29,
      36,   134,   107,   108,   109,    95,   106,   138,   139,   111,
      89,    73,   142,   140,    32,   122,    49,    49,   144,   -61,
     113,   -61,   -61,   147,     3,   115,   100,   119,   130,   -61,
     -61,    88,   -61,    72,   132,   -61,   -61,    90,   -61,   141,
     -61,   121,   -61,   125,   150,   -61,   128,   157,   -61,    20,
     126,   -61,     2,   100,   -61,    72,    72,    72,    72,   130,
      88,   -61,    74,   -61,   158,   133,   135,   160,    30,   136,
     -61,   -61,   -61,     5,    28,    28,   -61,   -61,   143,   -61,
     -61,   -61,   100,   100,   137,   -61,    93,    42,   -61,    40,
       8,    19,   161,   -61,   111,    94,   -61,    97,   -61,   -61,
     145,   119,   -61,    72,    52,   146,   100,    37,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    39,     1,     0,     0,     0,
      37,     0,     0,     0,     0,     3,    38,     0,    41,     0,
       0,     0,     0,     4,     2,     5,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,    16,
       0,    17,     6,     0,     0,     0,     0,     0,    21,    24,
      35,    19,    25,     0,    43,    42,    26,     0,    22,     0,
      51,     0,    52,     0,     0,    18,    13,     0,    10,     0,
       0,    11,     0,     0,    36,     0,     0,     0,     0,     0,
      20,    44,    50,    27,     0,     0,     0,     0,     0,    13,
       9,    12,     8,     0,    31,    32,    33,    34,    46,    49,
      45,    53,     0,     0,     0,    15,     0,     0,     7,     0,
       0,     0,     0,    14,    15,     0,    48,     0,    28,    29,
       0,    14,    47,     0,     0,     0,     0,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   116,   -28,   -10,   -61,   -61,   117,   -61,   -54,
     -35,   -60,   -61,   162,    50,   148,    53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    14,    19,    15,     8,    54,    55,    24,    35,
      36,    61,     3,     4,    67,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    40,    82,    90,    23,    30,    31,    77,    30,    31,
      17,    30,    31,    32,    33,    34,    32,    33,    34,    32,
      33,    34,    30,    31,    13,   104,   105,   106,   107,   103,
      32,    33,    34,    17,    17,    64,   102,    78,    18,   118,
      30,    31,   128,    64,    41,     1,    17,    50,    32,    33,
      34,    42,    69,   129,   100,    65,    87,    88,   120,   121,
      43,    39,   115,    65,    66,    70,     5,    44,    50,    23,
     116,   138,   126,   134,   124,    89,    58,   108,    85,    86,
      87,    88,   137,    10,   135,    50,    50,     1,    11,   125,
      59,   109,    26,     7,    27,    60,    60,   110,    30,    31,
      13,    49,    50,    30,    31,    12,    32,    33,    34,    13,
      22,    32,    33,    34,    85,    86,    87,    88,     6,    26,
      92,    57,    93,    26,    26,   123,   131,    92,    16,   132,
      21,    20,    25,    28,    29,    37,    38,    45,    46,    47,
      48,    52,    51,    53,    56,    62,    68,    74,    63,    75,
      76,    81,    83,    95,    84,    94,    91,    96,    97,    98,
      99,   111,   101,   114,    69,     9,   112,   117,   113,   127,
      79,    80,     0,   122,   119,   130,     0,     0,     0,   136,
       0,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73
};

static const yytype_int16 yycheck[] =
{
      35,    29,    56,    63,    14,     3,     4,     4,     3,     4,
       4,     3,     4,    11,    12,    13,    11,    12,    13,    11,
      12,    13,     3,     4,     4,    85,    86,    87,    88,    83,
      11,    12,    13,     4,     4,     3,    34,    34,    32,    34,
       3,     4,    34,     3,     8,     4,     4,    82,    11,    12,
      13,    15,     3,    34,    34,    23,    28,    29,   112,   113,
      24,    32,    32,    23,    32,    16,     3,    31,   103,    79,
      98,    34,    32,   133,    32,     3,     3,     3,    26,    27,
      28,    29,   136,    36,    32,   120,   121,     4,    31,   117,
      17,    17,    30,    10,    32,    23,    23,    23,     3,     4,
       4,     6,   137,     3,     4,     3,    11,    12,    13,     4,
       5,    11,    12,    13,    26,    27,    28,    29,     0,    30,
      30,    32,    32,    30,    30,    32,    32,    30,    36,    32,
       3,    33,     3,     9,    31,     4,    35,     3,    31,    31,
      31,     3,    36,     4,    33,     3,    24,     3,     8,    36,
       3,    36,    33,    32,    24,    14,    24,    32,     8,    31,
       3,     3,    36,     3,     3,     3,    33,    31,    33,   119,
      54,    54,    -1,    36,    31,   122,    -1,    -1,    -1,    33,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    38,    49,    50,     3,     0,    10,    42,    50,
      36,    31,     3,     4,    39,    41,    36,     4,    32,    40,
      33,     3,     5,    41,    45,     3,    30,    32,     9,    31,
       3,     4,    11,    12,    13,    46,    47,     4,    35,    32,
      40,     8,    15,    24,    31,     3,    31,    31,    31,     6,
      47,    36,     3,     4,    43,    44,    33,    32,     3,    17,
      23,    48,     3,     8,     3,    23,    32,    51,    24,     3,
      16,    52,    53,    52,     3,    36,     3,     4,    34,    39,
      44,    36,    46,    33,    24,    26,    27,    28,    29,     3,
      48,    24,    30,    32,    14,    32,    32,     8,    31,     3,
      34,    36,    34,    46,    48,    48,    48,    48,     3,    17,
      23,     3,    33,    33,     3,    32,    40,    31,    34,    31,
      46,    46,    36,    32,    32,    40,    32,    51,    34,    34,
      53,    32,    32,    36,    48,    32,    33,    46,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    44,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    48,    48,    48,    48,    48,    48,    49,    49,    50,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     2,     4,     8,     7,     8,
       7,     2,     3,     2,     5,     4,     3,     2,     3,     3,
       4,     3,     3,     2,     3,     3,     3,     4,     7,     7,
      13,     3,     3,     3,     3,     1,     2,     2,     3,     2,
       5,     4,     1,     1,     2,     3,     3,     6,     5,     3,
       2,     1,     1,     3
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
#line 83 "limbaj.y"
               {}
#line 1505 "y.tab.c"
    break;

  case 4:
#line 84 "limbaj.y"
                    {}
#line 1511 "y.tab.c"
    break;

  case 5:
#line 89 "limbaj.y"
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
#line 1532 "y.tab.c"
    break;

  case 6:
#line 105 "limbaj.y"
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
#line 1553 "y.tab.c"
    break;

  case 7:
#line 125 "limbaj.y"
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
#line 1577 "y.tab.c"
    break;

  case 8:
#line 144 "limbaj.y"
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
#line 1592 "y.tab.c"
    break;

  case 9:
#line 158 "limbaj.y"
                                             {strcpy(nume_clasa, (yyvsp[-6].strval));}
#line 1598 "y.tab.c"
    break;

  case 10:
#line 159 "limbaj.y"
                                        {
                                             strcpy(nume_clasa, (yyvsp[-5].strval)); //cod
                                            //  printf("%d, %d\n", var_in_class, total_vars);
                                             for (int i=var_in_class-2; i<total_vars; i++)
                                             {
                                                  strcpy(tabel_var[i].where, nume_clasa);
                                             }
                                             ok=0;
                                             
                                        }
#line 1613 "y.tab.c"
    break;

  case 11:
#line 171 "limbaj.y"
                           {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars+1;
                                        ok=1;
                                   }
                              strcpy(tabel_var[total_vars].scope, "clasa");
                              //cod
                         }
#line 1627 "y.tab.c"
    break;

  case 12:
#line 180 "limbaj.y"
                                {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars;
                                        ok=1;
                                   }
                                    strcpy(tabel_var[total_vars].scope, "clasa");
                                  //cod
                              }
#line 1641 "y.tab.c"
    break;

  case 13:
#line 192 "limbaj.y"
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
                         snprintf(buffer, 100,"%s %s\n", (yyvsp[-1].strval) , (yyvsp[0].strval));
                         fprintf(fd, "%s", buffer);}
                    else
                         yyerror(); 
               }
#line 1661 "y.tab.c"
    break;

  case 14:
#line 207 "limbaj.y"
                                  {}
#line 1667 "y.tab.c"
    break;

  case 15:
#line 208 "limbaj.y"
                      {}
#line 1673 "y.tab.c"
    break;

  case 16:
#line 213 "limbaj.y"
                         {}
#line 1679 "y.tab.c"
    break;

  case 17:
#line 218 "limbaj.y"
                         {}
#line 1685 "y.tab.c"
    break;

  case 18:
#line 219 "limbaj.y"
                              { }
#line 1691 "y.tab.c"
    break;

  case 19:
#line 223 "limbaj.y"
                        {
        // printf("%s assign operatii result: %f\n", $1,$3.value);
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table((yyvsp[-2].strval));
        if (dol1 == NULL)
            {yyerror(); printf("undeclared var: %s\n", (yyvsp[-2].strval)); return 0;}
        else 
        if(strcmp(dol1->type, "float") == 0){
            char temp[100];
            sprintf(temp, "%f", (yyvsp[0].number).value);
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "int") == 0){
            if((yyvsp[0].number).is_float > 0)
                {printf("WARNING casting floating number to int variable: %s\n", (yyvsp[-2].strval));}
            char temp[100];
            sprintf(temp, "%d", (int)(yyvsp[0].number).value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
    }
#line 1718 "y.tab.c"
    break;

  case 20:
#line 245 "limbaj.y"
                                    {
        // printf("id[arr] assign operatii result: %f\n", $4.value);
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table((yyvsp[-3].strval));
        if (dol1 == NULL)
            {yyerror(); printf("undeclared arr: %s\n", (yyvsp[-3].strval)); return 0;}
        else 
        if(dol1->is_arr == 0) {yyerror(); printf("%s is not an array\n", (yyvsp[-3].strval)); return 0;}
        else
        if(dol1->arr_len >= (yyvsp[-2].intval)) {yyerror(); printf("accessing index out of bound of array %s\n", (yyvsp[-3].strval)); return 0;}
        if(strcmp(dol1->type, "float") == 0){
            char temp[100];
            sprintf(temp, "%f", (yyvsp[0].number).value);
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "int") == 0){
            if((yyvsp[0].number).is_float > 0)
                {printf("WARNING casting floating number to int variable: %s\n", (yyvsp[-3].strval));}
            char temp[100];
            sprintf(temp, "%d", (int)(yyvsp[0].number).value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "bool") == 0){
            char temp[100];
            sprintf(temp, "%d", (bool)(yyvsp[0].number).value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
    }
#line 1755 "y.tab.c"
    break;

  case 21:
#line 277 "limbaj.y"
                   {
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table((yyvsp[-2].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[-2].strval)); return 0;}
        struct var * dol3;
        dol3 = get_var_from_table((yyvsp[0].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[0].strval)); return 0;}
        if (dol1 != NULL && dol3!= NULL){
             if((same_scope((yyvsp[-2].strval), (yyvsp[0].strval)) || (strcmp(get_var_scope((yyvsp[0].strval)),"globala")==0))) 
                 update_var_s(dol1, dol3);
             else{
                  yyerror(); 
                  printf("trying to do operation on variables of different scopes: %s , %s\n", dol1->id, dol3->id);
                  break;
             }
        }
    }
#line 1779 "y.tab.c"
    break;

  case 22:
#line 296 "limbaj.y"
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
#line 1799 "y.tab.c"
    break;

  case 23:
#line 311 "limbaj.y"
              { 
        // printf("declarare tip id\n");
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
#line 1828 "y.tab.c"
    break;

  case 24:
#line 335 "limbaj.y"
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
            printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, (yyvsp[-1].strval), dol3.type);
            break;
        }
    }
#line 1855 "y.tab.c"
    break;

  case 25:
#line 357 "limbaj.y"
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
#line 1884 "y.tab.c"
    break;

  case 26:
#line 381 "limbaj.y"
                 {      
        printf("apel functie din main\n");
        if(exists_function((yyvsp[-2].strval))==0)
            {yyerror(), printf("call to undeclared function: %s\n", (yyvsp[-2].strval)); return 0;}
    }
#line 1894 "y.tab.c"
    break;

  case 27:
#line 386 "limbaj.y"
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
#line 1911 "y.tab.c"
    break;

  case 28:
#line 398 "limbaj.y"
                                       {}
#line 1917 "y.tab.c"
    break;

  case 29:
#line 399 "limbaj.y"
                                       {}
#line 1923 "y.tab.c"
    break;

  case 30:
#line 400 "limbaj.y"
                                                                                {}
#line 1929 "y.tab.c"
    break;

  case 31:
#line 405 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value + (yyvsp[0].number).value; (yyval.number).is_float = (yyvsp[-2].number).is_float + (yyvsp[0].number).is_float; }
#line 1935 "y.tab.c"
    break;

  case 32:
#line 406 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value - (yyvsp[0].number).value; (yyval.number).is_float = (yyvsp[-2].number).is_float + (yyvsp[0].number).is_float; }
#line 1941 "y.tab.c"
    break;

  case 33:
#line 407 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value * (yyvsp[0].number).value; (yyval.number).is_float = (yyvsp[-2].number).is_float + (yyvsp[0].number).is_float; }
#line 1947 "y.tab.c"
    break;

  case 34:
#line 408 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value / (yyvsp[0].number).value; (yyval.number).is_float = (yyvsp[-2].number).is_float + (yyvsp[0].number).is_float; }
#line 1953 "y.tab.c"
    break;

  case 35:
#line 409 "limbaj.y"
         { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).is_float = (yyvsp[0].number).is_float; }
#line 1959 "y.tab.c"
    break;

  case 36:
#line 410 "limbaj.y"
                    {

    }
#line 1967 "y.tab.c"
    break;

  case 37:
#line 416 "limbaj.y"
                       {strcpy(tabel_var[total_vars].scope, "global");}
#line 1973 "y.tab.c"
    break;

  case 38:
#line 417 "limbaj.y"
                             {strcpy(tabel_var[total_vars].scope, "global");}
#line 1979 "y.tab.c"
    break;

  case 39:
#line 421 "limbaj.y"
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
#line 1996 "y.tab.c"
    break;

  case 40:
#line 433 "limbaj.y"
                                  {printf("var: %s\n", (yyvsp[-3].strval));}
#line 2002 "y.tab.c"
    break;

  case 41:
#line 434 "limbaj.y"
                     {}
#line 2008 "y.tab.c"
    break;

  case 42:
#line 438 "limbaj.y"
         {printf("small rule\n");}
#line 2014 "y.tab.c"
    break;

  case 43:
#line 439 "limbaj.y"
         {
        struct var * dol1;
        dol1 = get_var_from_table((yyvsp[0].strval));
        if (dol1 == NULL)
            {yyerror(), printf("function call with undeclared variable: %s\n", (yyvsp[0].strval)); return 0;} 

    }
#line 2026 "y.tab.c"
    break;

  case 44:
#line 446 "limbaj.y"
                   {

    }
#line 2034 "y.tab.c"
    break;

  case 45:
#line 449 "limbaj.y"
                        {printf("small rule apel functie\n");}
#line 2040 "y.tab.c"
    break;

  case 46:
#line 450 "limbaj.y"
                        {}
#line 2046 "y.tab.c"
    break;

  case 47:
#line 451 "limbaj.y"
                                           {/*idk man*/}
#line 2052 "y.tab.c"
    break;

  case 48:
#line 452 "limbaj.y"
                                {}
#line 2058 "y.tab.c"
    break;

  case 49:
#line 453 "limbaj.y"
                            {}
#line 2064 "y.tab.c"
    break;

  case 51:
#line 461 "limbaj.y"
                    {
                         ;//cod
                    }
#line 2072 "y.tab.c"
    break;

  case 52:
#line 464 "limbaj.y"
                          {
                         ;//cod
                    }
#line 2080 "y.tab.c"
    break;

  case 53:
#line 470 "limbaj.y"
                       {
                         ;//cod
                    }
#line 2088 "y.tab.c"
    break;


#line 2092 "y.tab.c"

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
#line 474 "limbaj.y"

 
void yyerror(char * s){
printf("eroare: %s la linia: %d\n",s,yylineno);
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
        printf("\n\nProgram corect sintactic!\n");
        printf("\n\t%-15s %-15s %-10s %-4s %-10s %-10s \n", "id", "value", "type", "arr?","scope", "additional");
        printf("\t%-15s %-15s %-10s %-4s %-10s %-10s \n", "---------", "------", "----","----","-----", "----------");

        for (int i = 0; i < total_vars; i++)
            printf("\t%-15s %-15s %-10s %-4s %-10s %-10s \n", tabel_var[i].id, tabel_var[i].value, tabel_var[i].type, (tabel_var[i].is_arr == 1 ? "yes" : "   ") ,tabel_var[i].scope, tabel_var[i].where);
        printf("fun decl %d:\n", total_fnc);
            printf("\t%-7s %-10s\n", "retType", "fnc");
        for (int i = 0; i < total_fnc; i++){
            printf("\t%-7s %-7s ", tabel_fnc[i].ret_type, tabel_fnc[i].nume);
            printf("\t(");
            for(int ii = 0; ii < tabel_fnc[i].params_count; ++ii)
               printf("%-4s", tabel_fnc[i].param_types[ii]);
            printf(")\n");
        }
    } else {
        printf("Au fost gasite erori de compilare\n");
    }
    //SCRIE IN FISIER ACELASI TABEL
    if (errors == 0) {
        fprintf(fd, "\n\nProgram corect sintactic!\n");
        } else  fprintf(fd, "Au fost gasite erori de compilare\n"); 
        fprintf(fd, "\n\t%-15s %-15s %-10s %-4s %-10s %-10s \n", "id", "value", "type", "arr?","scope", "additional");
        fprintf(fd, "\t%-15s %-15s %-10s %-4s %-10s %-10s \n", "---------", "------", "----","----","-----", "----------");

        for (int i = 0; i < total_vars; i++)
            fprintf(fd, "\t%-15s %-15s %-10s %-4s %-10s %-10s \n", tabel_var[i].id, tabel_var[i].value, tabel_var[i].type, (tabel_var[i].is_arr == 1 ? "yes" : "   ") ,tabel_var[i].scope, tabel_var[i].where);
        fprintf(fd, "fun decl %d:\n", total_fnc);
            fprintf(fd, "\t%-7s %-10s\n", "retType", "fnc");
        for (int i = 0; i < total_fnc; i++){
            fprintf(fd, "\t%-7s %-7s ", tabel_fnc[i].ret_type, tabel_fnc[i].nume);
            fprintf(fd, "\t(");
            for(int ii = 0; ii < tabel_fnc[i].params_count; ++ii)
               fprintf(fd, "%-4s", tabel_fnc[i].param_types[ii]);
            fprintf(fd, ")\n");
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

/* 
 lex limbaj.l; yacc -d limbaj.y
 
gcc lex.yy.c y.tab.c
 
todo:
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
