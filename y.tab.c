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
char *params[1000];
char output[1000], param_fun[100];
char nume_clasa[100], nume_functie[100];
struct signature tabel_fnc[100];
struct signature new_function_buff;
int total_vars=0, errors=0, total_fnc=1,nr_param=0, param=0, var_in_class, conditie=0, ok=0, var_in_fun, ok_fun;
int err_count = 0;
char scope[100], scope2[100], param_eval[100];
int stack_idx = 0;
int exists_in_var_table(char x[100]);
int exists_in_var_table_s(struct var *x);
struct var * get_var_from_table(char id[100]);
int is_default(char x[100]);
int find_param_fun( char x[1000], char params[100]);
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
char * get_var_return(char id[100]);
int same_scope(char x[100], char y[100]) ;
int exists_function (char x[100]);
void stack_push(struct var new_elem);
int stack_pop(); //ASTA DA POP LA INDEX 
float get_float_cast(struct var *from, const int idx);
int get_type(struct var * from);
int check_idx(struct var *x, const int idx);
int val_expr;

#line 140 "y.tab.c"

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
    EVAL = 264,
    VIS = 265,
    CLASS = 266,
    IF = 267,
    WHILE = 268,
    FOR = 269,
    OP_BIN = 270,
    OP_STR = 271,
    STRING = 272,
    FLOAT = 273,
    NR = 274,
    ARR_ACCESS = 275,
    CHR = 276,
    STR_ASSIGN = 277,
    bool = 278,
    AND = 279,
    OR = 280,
    EQ = 281,
    NEQ = 282,
    GT = 283,
    LT = 284,
    GE = 285,
    LE = 286
  };
#endif
/* Tokens.  */
#define ID 258
#define TIP 259
#define BGIN 260
#define END 261
#define CONST 262
#define ASSIGN 263
#define EVAL 264
#define VIS 265
#define CLASS 266
#define IF 267
#define WHILE 268
#define FOR 269
#define OP_BIN 270
#define OP_STR 271
#define STRING 272
#define FLOAT 273
#define NR 274
#define ARR_ACCESS 275
#define CHR 276
#define STR_ASSIGN 277
#define bool 278
#define AND 279
#define OR 280
#define EQ 281
#define NEQ 282
#define GT 283
#define LT 284
#define GE 285
#define LE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 71 "limbaj.y"

    char *strval;
    int intval;
    int blval;
    struct nmbr{
        float value;
        int type;
        int type_err;
    } number;

#line 265 "y.tab.c"

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
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
       2,     2,    44,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    35,    33,    37,    34,    18,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      15,    16,    17,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    99,   100,   105,   121,   141,   160,   175,
     176,   188,   197,   209,   224,   225,   230,   235,   236,   240,
     281,   330,   361,   379,   418,   444,   460,   489,   497,   498,
     499,   500,   501,   504,   539,   540,   541,   542,   544,   556,
     559,   560,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   576,   577,   595,   613,   614,   618,   632,   645,   646,
     652,   655,   658,   662,   665,   668,   671,   674,   677
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TIP", "BGIN", "END", "CONST",
  "ASSIGN", "EVAL", "VIS", "CLASS", "IF", "WHILE", "FOR", "OP_BIN",
  "OP_STR", "STRING", "'.'", "FLOAT", "NR", "ARR_ACCESS", "CHR",
  "STR_ASSIGN", "bool", "AND", "OR", "EQ", "NEQ", "GT", "LT", "GE", "LE",
  "'+'", "'-'", "'*'", "'/'", "','", "'('", "')'", "'{'", "'}'", "':'",
  "';'", "' '", "$accept", "progr", "fnc", "lista_param", "functie",
  "clasa", "decl_cl", "declaratiecl", "bloc", "list", "statement",
  "apel_functie", "operations", "compute", "instructiune_if", "operatii",
  "variable", "decl_gl", "declaratie", "operatii_binare", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    46,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,    43,    45,    42,    47,    44,    40,    41,
     123,   125,    58,    59,    32
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,    25,    35,    23,    15,   -12,   -76,    86,    81,    58,
     -76,   -76,    20,    79,   106,   190,   -76,   -76,   121,   -76,
      -8,   141,    93,    43,   -76,   -76,   -76,   157,   -76,   122,
      72,   155,   169,   137,   175,   194,   195,     9,   156,   136,
     -76,   -76,   -76,   227,   230,   196,    95,    70,   232,    69,
      85,    12,   216,    70,    70,   214,   236,   199,    66,   -76,
     198,   -76,   -76,   239,     7,   200,    43,   204,   224,   -76,
      70,   -28,   -76,   -76,    70,   229,   -76,   -76,    -2,   -76,
     210,   209,   187,   -76,   110,   -28,   180,   211,   241,   -76,
     -76,   -76,   213,   249,   -76,    13,   212,   -76,   101,    43,
     -76,   192,    70,    70,    70,    70,   -28,   -76,    78,    78,
     -76,    78,   -76,    70,    70,    70,    70,    70,    70,    70,
      70,   -76,   217,   250,    82,   218,   -76,   -76,   -76,   114,
      70,    70,    70,    70,   182,   182,   -76,   -76,   -76,   -76,
     160,   160,   -76,   -76,   -76,   -76,   -76,   -76,    43,   215,
     -76,   113,    83,   -76,    64,   138,   220,   221,   126,    70,
     -76,   196,   177,   -76,   -76,   -76,   -76,   -76,   172,   204,
      70,   147,   222,    43,   144,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    56,     1,     0,     0,     0,
      54,    57,     0,     0,     0,     0,     3,    55,     0,    59,
       0,     0,     0,     0,     4,     2,     5,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    32,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    16,
       0,    17,     6,     0,     0,     0,     0,     0,    52,    51,
       0,    19,    50,    26,     0,     0,    21,    24,    52,    27,
      36,     0,    34,    22,     0,    68,     0,     0,     0,    40,
      41,    18,    13,     0,    10,     0,     0,    11,     0,     0,
      53,     0,     0,     0,     0,     0,    20,    25,     0,     0,
      33,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,     0,     0,    13,     9,    12,     8,     0,
       0,     0,     0,     0,    42,    44,    46,    48,    37,    35,
      60,    61,    62,    63,    66,    67,    64,    65,     0,     0,
      15,     0,     0,     7,    42,    44,    46,    48,     0,     0,
      14,    15,     0,    43,    45,    47,    49,    30,     0,    14,
       0,     0,     0,     0,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   197,   -27,   -13,   -76,   -76,   201,   -76,   -36,
     -38,   -47,   120,   -76,   -76,   -37,   -76,   -76,   251,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    15,    20,    16,     8,    64,    65,    25,    38,
      39,    40,    81,    41,    42,    85,    72,     3,     4,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      60,    58,    24,    46,    80,   102,   103,   104,   105,    11,
      71,    93,    31,    32,    82,    78,    84,    14,    33,   100,
      60,    34,    35,    36,    18,     1,    12,     1,     5,    27,
      98,    28,    69,   101,     7,     6,   108,   106,   140,   141,
     142,   143,   144,   145,   146,   147,    31,    32,    94,    37,
      70,    79,    33,    57,   126,    34,    35,    36,    10,    19,
      60,    80,    80,   129,    80,   134,   135,   136,   137,    31,
      32,    82,    82,    68,    82,    33,    18,    74,    34,    35,
      36,    78,    24,    37,   168,    14,    18,    18,    76,    13,
      69,    60,    75,   154,   155,   156,   157,   151,    69,   104,
     105,    17,    77,   163,    31,    32,    37,    90,    70,    22,
      33,    45,   158,    34,    35,    36,    70,    31,    32,    21,
      60,   150,   161,    33,    26,   162,    34,    35,    36,    31,
      32,    30,    27,   171,    67,    33,    60,   174,    34,    35,
      36,    37,   128,   102,   103,   104,   105,    31,    32,   112,
      27,    29,   160,    33,    37,   153,    34,    35,    36,    31,
      32,    43,    59,    47,    44,    33,    37,   167,    34,    35,
      36,    48,    52,   104,   105,    53,    49,   164,    50,    61,
     102,   103,   104,   105,    37,   175,   172,   115,   116,   117,
     118,   119,   120,    51,    14,    23,    37,   113,   114,   115,
     116,   117,   118,   119,   120,   113,   114,   115,   116,   117,
     118,   119,   120,    54,    27,   170,   169,   104,   105,   121,
     102,   103,   104,   105,   111,   130,   131,   132,   133,   138,
      62,   139,    55,    56,    63,    73,    66,    83,    87,    88,
      89,    91,    92,    97,    99,   100,   107,   109,   110,   123,
     122,   124,   125,   149,     9,   127,   152,   148,   159,   165,
     166,    95,   173,     0,     0,    96
};

static const yytype_int16 yycheck[] =
{
      38,    37,    15,    30,    51,    33,    34,    35,    36,    21,
      47,     4,     3,     4,    51,     3,    53,     4,     9,    21,
      58,    12,    13,    14,     4,     4,    38,     4,     3,    37,
      66,    39,    20,    70,    11,     0,    38,    74,   113,   114,
     115,   116,   117,   118,   119,   120,     3,     4,    41,    40,
      38,    39,     9,    44,    41,    12,    13,    14,    43,    39,
      98,   108,   109,    99,   111,   102,   103,   104,   105,     3,
       4,   108,   109,     3,   111,     9,     4,     8,    12,    13,
      14,     3,    95,    40,   159,     4,     4,     4,     3,     3,
      20,   129,    23,   130,   131,   132,   133,   124,    20,    35,
      36,    43,    17,    39,     3,     4,    40,    41,    38,     3,
       9,    39,   148,    12,    13,    14,    38,     3,     4,    40,
     158,    39,    39,     9,     3,   152,    12,    13,    14,     3,
       4,    38,    37,   170,    39,     9,   174,   173,    12,    13,
      14,    40,    41,    33,    34,    35,    36,     3,     4,    39,
      37,    10,    39,     9,    40,    41,    12,    13,    14,     3,
       4,     4,     6,     8,    42,     9,    40,    41,    12,    13,
      14,    16,     3,    35,    36,    38,    21,    39,    23,    43,
      33,    34,    35,    36,    40,    41,    39,    27,    28,    29,
      30,    31,    32,    38,     4,     5,    40,    25,    26,    27,
      28,    29,    30,    31,    32,    25,    26,    27,    28,    29,
      30,    31,    32,    38,    37,    43,    39,    35,    36,    39,
      33,    34,    35,    36,    37,    33,    34,    35,    36,   109,
       3,   111,    38,    38,     4,     3,    40,    21,    24,     3,
      41,    43,     3,    43,    40,    21,    17,    37,    39,     8,
      39,    38,     3,     3,     3,    43,    38,    40,    43,    39,
      39,    64,    40,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    46,    62,    63,     3,     0,    11,    50,    63,
      43,    21,    38,     3,     4,    47,    49,    43,     4,    39,
      48,    40,     3,     5,    49,    53,     3,    37,    39,    10,
      38,     3,     4,     9,    12,    13,    14,    40,    54,    55,
      56,    58,    59,     4,    42,    39,    48,     8,    16,    21,
      23,    38,     3,    38,    38,    38,    38,    44,    54,     6,
      55,    43,     3,     4,    51,    52,    40,    39,     3,    20,
      38,    60,    61,     3,     8,    23,     3,    17,     3,    39,
      56,    57,    60,    21,    60,    60,    64,    24,     3,    41,
      41,    43,     3,     4,    41,    47,    52,    43,    54,    40,
      21,    60,    33,    34,    35,    36,    60,    17,    38,    37,
      39,    37,    39,    25,    26,    27,    28,    29,    30,    31,
      32,    39,    39,     8,    38,     3,    41,    43,    41,    54,
      33,    34,    35,    36,    60,    60,    60,    60,    57,    57,
      64,    64,    64,    64,    64,    64,    64,    64,    40,     3,
      39,    48,    38,    41,    60,    60,    60,    60,    54,    43,
      39,    39,    48,    39,    39,    39,    39,    41,    64,    39,
      43,    60,    39,    40,    54,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    57,    57,    57,    57,    58,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     2,     4,     8,     7,     8,
       7,     2,     3,     2,     5,     4,     3,     2,     3,     3,
       4,     3,     3,     2,     3,     4,     3,     3,     1,     1,
       7,    13,     1,     4,     1,     3,     1,     3,     4,     4,
       3,     3,     3,     5,     3,     5,     3,     5,     3,     5,
       1,     1,     1,     2,     2,     3,     2,     3,     5,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     1
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
#line 99 "limbaj.y"
               {}
#line 1564 "y.tab.c"
    break;

  case 4:
#line 100 "limbaj.y"
                    {}
#line 1570 "y.tab.c"
    break;

  case 5:
#line 105 "limbaj.y"
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
#line 1591 "y.tab.c"
    break;

  case 6:
#line 121 "limbaj.y"
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
#line 1612 "y.tab.c"
    break;

  case 7:
#line 141 "limbaj.y"
                                                 { 
        //decl globala functie
        strcpy(new_function_buff.ret_type, (yyvsp[-7].strval));
        strcpy(new_function_buff.nume, (yyvsp[-6].strval));
        strcpy(new_function_buff.parent_class, "global");
        if(exists_signature(&new_function_buff) == 1)
             yyerror(), printf("function %s redefined", new_function_buff.nume);
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
#line 1636 "y.tab.c"
    break;

  case 8:
#line 160 "limbaj.y"
                                  { 
        strcpy(new_function_buff.ret_type, (yyvsp[-6].strval));
        new_function_buff.params_count = 0;
        strcpy(new_function_buff.nume, (yyvsp[-5].strval));
        strcpy(new_function_buff.parent_class, "global");
        if(exists_signature(&new_function_buff) == 1)
             yyerror(), printf("function %s redefined", new_function_buff.nume);
        else
             add_signature(&new_function_buff);
             total_fnc++;
    }
#line 1652 "y.tab.c"
    break;

  case 9:
#line 175 "limbaj.y"
                                             {strcpy(nume_clasa, (yyvsp[-6].strval));}
#line 1658 "y.tab.c"
    break;

  case 10:
#line 176 "limbaj.y"
                                        {
                                             strcpy(nume_clasa, (yyvsp[-5].strval)); //cod
                                            //  printf("%d, %d\n", var_in_class, total_vars);
                                             for (int i=var_in_class-2; i<total_vars; i++)
                                             {
                                                  strcpy(tabel_var[i].where, nume_clasa);
                                             }
                                             ok=0;
                                             
                                        }
#line 1673 "y.tab.c"
    break;

  case 11:
#line 188 "limbaj.y"
                           {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars+1;
                                        ok=1;
                                   }
                              strcpy(tabel_var[total_vars].scope, "clasa");
                              //cod
                         }
#line 1687 "y.tab.c"
    break;

  case 12:
#line 197 "limbaj.y"
                                {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars;
                                        ok=1;
                                   }
                                    strcpy(tabel_var[total_vars].scope, "clasa");
                                  //cod
                              }
#line 1701 "y.tab.c"
    break;

  case 13:
#line 209 "limbaj.y"
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
#line 1721 "y.tab.c"
    break;

  case 14:
#line 224 "limbaj.y"
                                  {}
#line 1727 "y.tab.c"
    break;

  case 15:
#line 225 "limbaj.y"
                      {}
#line 1733 "y.tab.c"
    break;

  case 16:
#line 230 "limbaj.y"
                         {}
#line 1739 "y.tab.c"
    break;

  case 17:
#line 235 "limbaj.y"
                        {}
#line 1745 "y.tab.c"
    break;

  case 18:
#line 236 "limbaj.y"
                              { }
#line 1751 "y.tab.c"
    break;

  case 19:
#line 240 "limbaj.y"
                        {
        if(conditie==0)
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
            char temp[100];
            sprintf(temp, "%d", (int)(yyvsp[0].number).value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "char") == 0){
            dol1->value[0] = (char)((yyvsp[0].number).value);
            dol1->value[1] = '\0';
        }
    }
    }
#line 1797 "y.tab.c"
    break;

  case 20:
#line 281 "limbaj.y"
                                    {
        if(conditie==0)
        // printf("id[arr] assign operatii result: %f\n", $4.value);
        {struct var * dol1; //era pera lung "dollar"
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
            printf("FLOAT SSIGNED %s\n", temp);
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
            dol1->arr_data[(yyvsp[-2].intval)] = strdup(temp);
            dol1->idx_init[(yyvsp[-2].intval)] = 1;
        }
        }
    }
#line 1851 "y.tab.c"
    break;

  case 21:
#line 330 "limbaj.y"
                       {
        if(conditie==0)
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
    }
#line 1887 "y.tab.c"
    break;

  case 22:
#line 361 "limbaj.y"
                        {
        if(conditie==0)
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
    }
#line 1910 "y.tab.c"
    break;

  case 23:
#line 379 "limbaj.y"
              { 
        if(conditie==0)
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
             {
                 
            if(strcmp(get_var_scope((yyvsp[0].strval)), "global")==0 || strcmp(get_var_scope((yyvsp[0].strval)), "main")==0)
                yyerror(); 
            else
            {
                strcpy(tabel_var[total_vars].id, (yyvsp[0].strval));
             strcpy(tabel_var[total_vars].type, (yyvsp[-1].strval));
             strcpy(tabel_var[total_vars].value, "default");
             strcpy(tabel_var[total_vars].scope, "main");
             total_vars++;
            }
                // yyerror(), printf("already declared variable1: %s\n", $2); return 0;
                } 
        // printf("%d\n", ok_fun);
        if(ok_fun==1)
        {
             strcpy(tabel_var[total_vars].scope, "functie");
        }
    }
    }
#line 1954 "y.tab.c"
    break;

  case 24:
#line 418 "limbaj.y"
                           {
        if(conditie==0)
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
    }
#line 1985 "y.tab.c"
    break;

  case 25:
#line 444 "limbaj.y"
                                      {
        if(conditie!=0) return 0;
        struct var * dol1;
        struct var dol4;
        dol1 = get_var_from_table((yyvsp[-3].strval));
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", (yyvsp[-3].strval)); return 0;}
        int res = check_idx(dol1, (yyvsp[-2].intval));
        if(res != 0) return 0;
        // printf("string assing in arr\n");
        
        if(check_idx(dol1, (yyvsp[-2].intval)) != 0) return 0;
        if(strcmp(dol1->type, "string") != 0) {yyerror(); printf("illegal operation on string %s\n", dol1->id); return 0;}
        dol1->arr_data[(yyvsp[-2].intval)] = strdup((yyvsp[0].strval));
        dol1->idx_init[(yyvsp[-2].intval)] = 1;
    }
#line 2006 "y.tab.c"
    break;

  case 26:
#line 460 "limbaj.y"
                   {
        if(conditie==0)
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
    }
#line 2040 "y.tab.c"
    break;

  case 27:
#line 489 "limbaj.y"
                 {     
        if(conditie==0)
        { 
        printf("apel functie din main\n");
        if(exists_function((yyvsp[-2].strval))==0)
            {yyerror(), printf("call to undeclared function: %s\n", (yyvsp[-2].strval)); return 0;}
    }
    }
#line 2053 "y.tab.c"
    break;

  case 28:
#line 497 "limbaj.y"
                   { }
#line 2059 "y.tab.c"
    break;

  case 30:
#line 499 "limbaj.y"
                                       {}
#line 2065 "y.tab.c"
    break;

  case 31:
#line 500 "limbaj.y"
                                                                                {}
#line 2071 "y.tab.c"
    break;

  case 32:
#line 501 "limbaj.y"
              {  if(strcmp(param_eval, "1")!=0)  yyerror();  bzero(param_eval, 100);  }
#line 2077 "y.tab.c"
    break;

  case 33:
#line 504 "limbaj.y"
                                    {
                    if(conditie==0)
                    {
                    if(exists_function((yyvsp[-3].strval))==0)
                        yyerror();
                    }
                    if(find_param_fun((yyvsp[-3].strval), param_fun)==0)
                        yyerror();
                        bzero(param_fun,100);
                    //strcpy($$, get_var_return($1));
                    char tempo[100];
                    bzero(tempo,100);
                    strcpy(tempo, get_var_return((yyvsp[-3].strval)));
                    if(strcmp( tempo, "int")==0)
                         {
                             sprintf((yyval.strval), "%d", 1); 
                         }
                          if(strcmp( tempo, "char")==0)
                         {
                             sprintf((yyval.strval), "%d", 2); 
                         }
                     if(strcmp( tempo, "float")==0)
                         {
                             sprintf((yyval.strval), "%d", 3); 
                         }
                     if(strcmp( tempo, "bool")==0)
                         {
                             sprintf((yyval.strval), "%d", 4); 
                         }
                     if(strcmp( tempo, "string")==0)
                         {
                             sprintf((yyval.strval), "%d", 5); 
                         }
                }
#line 2116 "y.tab.c"
    break;

  case 34:
#line 539 "limbaj.y"
                       {    char temp[10]; sprintf(temp, "%d", (yyvsp[0].number).type); strcat(param_fun, temp); }
#line 2122 "y.tab.c"
    break;

  case 35:
#line 540 "limbaj.y"
                                     {  char temp[10]; sprintf(temp, "%d", (yyvsp[-2].number).type); strcat(param_fun, temp);}
#line 2128 "y.tab.c"
    break;

  case 36:
#line 541 "limbaj.y"
                            { char temp[10]; sprintf(temp, "%s", (yyvsp[0].strval)); strcat(param_fun, temp); }
#line 2134 "y.tab.c"
    break;

  case 37:
#line 542 "limbaj.y"
                                          {char temp[10]; sprintf(temp, "%s", (yyvsp[-2].strval)); strcat(param_fun, temp);}
#line 2140 "y.tab.c"
    break;

  case 38:
#line 544 "limbaj.y"
                               { strcat(output, " "); char temp[100]; 
                                    int val=(int)((yyvsp[-1].number).value);
                                sprintf(temp, "%d", val); strcat(output, temp); 
                                bzero(temp,100); 
                                 sprintf(temp, "%d", (yyvsp[-1].number).type); strcat(param_eval, temp); 
                                 bzero(temp, 100); 
        
                                //printf("%s", output);
                                 }
#line 2154 "y.tab.c"
    break;

  case 39:
#line 556 "limbaj.y"
                                {  //in paranteze o sa fie un bool dupa ce o sa fie gata
        conditie = !(yyvsp[-1].blval);
    }
#line 2162 "y.tab.c"
    break;

  case 40:
#line 559 "limbaj.y"
                { s3:  conditie=0;}
#line 2168 "y.tab.c"
    break;

  case 41:
#line 560 "limbaj.y"
                    { s4: conditie=0;}
#line 2174 "y.tab.c"
    break;

  case 42:
#line 564 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value + (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2180 "y.tab.c"
    break;

  case 43:
#line 565 "limbaj.y"
                                    { (yyval.number).value = (yyvsp[-3].number).value + (yyvsp[-1].number).value; (yyval.number).type_err = ((yyvsp[-3].number).type != (yyvsp[-1].number).type); (yyval.number).type = (yyvsp[-3].number).type;}
#line 2186 "y.tab.c"
    break;

  case 44:
#line 566 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value - (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2192 "y.tab.c"
    break;

  case 45:
#line 567 "limbaj.y"
                                    { (yyval.number).value = (yyvsp[-3].number).value - (yyvsp[-1].number).value; (yyval.number).type_err = ((yyvsp[-3].number).type != (yyvsp[-1].number).type); (yyval.number).type = (yyvsp[-3].number).type;}
#line 2198 "y.tab.c"
    break;

  case 46:
#line 568 "limbaj.y"
                            { (yyval.number).value = (yyvsp[-2].number).value * (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2204 "y.tab.c"
    break;

  case 47:
#line 569 "limbaj.y"
                                    { (yyval.number).value = (yyvsp[-3].number).value * (yyvsp[-1].number).value; (yyval.number).type_err = ((yyvsp[-3].number).type != (yyvsp[-1].number).type); (yyval.number).type = (yyvsp[-3].number).type;}
#line 2210 "y.tab.c"
    break;

  case 48:
#line 570 "limbaj.y"
                            { if((yyvsp[0].number).value == 0) {yyerror();printf("DIVISION BY 0 DETECTED\n"); return 0;} (yyval.number).value = (yyvsp[-2].number).value / (yyvsp[0].number).value; (yyval.number).type_err = ((yyvsp[-2].number).type != (yyvsp[0].number).type); (yyval.number).type = (yyvsp[-2].number).type;}
#line 2216 "y.tab.c"
    break;

  case 49:
#line 571 "limbaj.y"
                                    { if((yyvsp[-1].number).value == 0) {yyerror();printf("DIVISION BY 0 DETECTED\n"); return 0;} (yyval.number).value = (yyvsp[-3].number).value / (yyvsp[-1].number).value; (yyval.number).type_err = ((yyvsp[-3].number).type != (yyvsp[-1].number).type); (yyval.number).type = (yyvsp[-3].number).type;}
#line 2222 "y.tab.c"
    break;

  case 50:
#line 572 "limbaj.y"
               {/*NON STRING VARIABLE*/}
#line 2228 "y.tab.c"
    break;

  case 51:
#line 576 "limbaj.y"
         { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type_err = 0; (yyval.number).type = (yyvsp[0].number).type;}
#line 2234 "y.tab.c"
    break;

  case 52:
#line 577 "limbaj.y"
         {
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
#line 2257 "y.tab.c"
    break;

  case 53:
#line 595 "limbaj.y"
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
#line 2276 "y.tab.c"
    break;

  case 54:
#line 613 "limbaj.y"
                       {strcpy(tabel_var[total_vars].scope, "global");}
#line 2282 "y.tab.c"
    break;

  case 55:
#line 614 "limbaj.y"
                             {strcpy(tabel_var[total_vars].scope, "global");}
#line 2288 "y.tab.c"
    break;

  case 56:
#line 618 "limbaj.y"
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
        {
                yyerror(); 
        }
    }
#line 2307 "y.tab.c"
    break;

  case 57:
#line 632 "limbaj.y"
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
#line 2325 "y.tab.c"
    break;

  case 58:
#line 645 "limbaj.y"
                                  {printf("var: %s\n", (yyvsp[-3].strval));}
#line 2331 "y.tab.c"
    break;

  case 59:
#line 646 "limbaj.y"
                     {}
#line 2337 "y.tab.c"
    break;

  case 60:
#line 652 "limbaj.y"
                                          {
        (yyval.blval) = (yyvsp[-2].blval) && (yyvsp[0].blval);
    }
#line 2345 "y.tab.c"
    break;

  case 61:
#line 655 "limbaj.y"
                                         {
        (yyval.blval) = (yyvsp[-2].blval) || (yyvsp[0].blval);
    }
#line 2353 "y.tab.c"
    break;

  case 62:
#line 658 "limbaj.y"
                                         {
        (yyval.blval) = (yyvsp[-2].blval) == (yyvsp[0].blval);
        // printf("BOOLEAN EVALUATION %d\n", $$);
    }
#line 2362 "y.tab.c"
    break;

  case 63:
#line 662 "limbaj.y"
                                          {
        (yyval.blval) = (yyvsp[-2].blval) != (yyvsp[0].blval);
    }
#line 2370 "y.tab.c"
    break;

  case 64:
#line 665 "limbaj.y"
                                         {
        (yyval.blval) = (yyvsp[-2].blval) >= (yyvsp[0].blval);
    }
#line 2378 "y.tab.c"
    break;

  case 65:
#line 668 "limbaj.y"
                                         {
        (yyval.blval) = (yyvsp[-2].blval) <= (yyvsp[0].blval);
    }
#line 2386 "y.tab.c"
    break;

  case 66:
#line 671 "limbaj.y"
                                         {
        (yyval.blval) = (yyvsp[-2].blval) > (yyvsp[0].blval);
    }
#line 2394 "y.tab.c"
    break;

  case 67:
#line 674 "limbaj.y"
                                         {
        (yyval.blval) = (yyvsp[-2].blval) < (yyvsp[0].blval);
    }
#line 2402 "y.tab.c"
    break;

  case 68:
#line 677 "limbaj.y"
               {(yyval.blval) = (yyvsp[0].number).value;}
#line 2408 "y.tab.c"
    break;


#line 2412 "y.tab.c"

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
#line 680 "limbaj.y"

 
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
        fprintf(fd, "\t %-7s %-10s\n", "retType", "fnc");
    for (int i = 0; i < total_fnc; i++){
        fprintf(fd, "\t%-7s %-7s ", tabel_fnc[i].ret_type, tabel_fnc[i].nume);
        fprintf(fd, "\t(");
        for(int ii = 0; ii < tabel_fnc[i].params_count; ++ii)
           fprintf(fd, "%-4s ", tabel_fnc[i].param_types[ii]);
        fprintf(fd, ")\n");
    }
    fprintf(fd, "\narrays:\n");
    fprintf(fd, "\t%-7s %-15s %-10s\n", "type", "id", "content below");
    fprintf(fd, "\t%-7s %-15s \n", "----", "---------------");
    for (int i = 0; i < total_vars; i++){
        if(tabel_var[i].is_arr == 1){
            fprintf(fd, "\t%-7s %-15s ", tabel_var[i].type, tabel_var[i].id);
            fprintf(fd, "\n");
            for(int ii = 0; ii < tabel_var[i].arr_len; ++ii){
                fprintf(fd, "[%d]%s \n",ii , tabel_var[i].arr_data[ii]);
                if(tabel_var[i].idx_init[ii] == 0)
                    continue; 
                /* if(strcmp(tabel_var[i].type, "int") == 0 || strcmp(tabel_var[i].type, "bool") == 0){
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
                    fprintf(fd, "[%d]%f \n", temp);
                }
                if(strcmp(tabel_var[i].type, "string") == 0){
                    fprintf(fd, "[%d]%s \n",ii , tabel_var[i].arr_data[ii]);
                } */
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

    if(errors==0)
    {
    printf("REZULTATE EVAL : %s\n" , output);
    print_table(fd, errors);
    
    print_table(stdout, errors);
    }
    
}


char * get_var_return(char id[100])
{
    for(int i=0; i< total_fnc; i++)
        if(strcmp(tabel_fnc[i].nume, id)==0)
        {
         return tabel_fnc[i].ret_type;}
    return "error";
}
int find_param_fun( char x[1000], char params[100])
{
    char temp[100];
    char final[100];
    bzero(final, 100);
    for(int i=0; i< total_fnc; i++)
        if(strcmp(tabel_fnc[i].nume, x)==0)
        {

            for(int j=0; j< tabel_fnc[i].params_count; j++)
                {
                    if(strcmp( tabel_fnc[i].param_types[j], "int")==0)
                         {
                             sprintf(temp, "%d", 1); 
                             strcat(final, temp);
                         }
                          if(strcmp( tabel_fnc[i].param_types[j], "char")==0)
                         {
                             sprintf(temp, "%d", 2); 
                             strcat(final, temp);
                         }
                     if(strcmp( tabel_fnc[i].param_types[j], "float")==0)
                         {
                             sprintf(temp, "%d", 3); 
                             strcat(final, temp);
                         }
                     if(strcmp( tabel_fnc[i].param_types[j], "bool")==0)
                         {
                             sprintf(temp, "%d", 4); 
                             strcat(final, temp);
                         }
                     if(strcmp( tabel_fnc[i].param_types[j], "string")==0)
                         {
                             sprintf(temp, "%d", 5); 
                             strcat(final, temp);
                         }

                }
        }
        char temp2[100];
        bzero(temp2, 100);
        for(int i= strlen(params)-1; i >=0; i--)
        {
            temp2[strlen(params)-i-1]=params[i];
        }
        if(strcmp(final, temp2)==0)
        {
            return 1;
        }
        else{ return 0; } 
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
     strcpy(tabel_fnc[total_fnc].parent_class, new_f->parent_class);
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


    lista_apel 
    : NR {strcpy(params[nr_param++], "int");}
    | ID {
        struct var * dol1;
        dol1 = get_var_from_table($1);
        if (dol1 == NULL)
            {yyerror(), printf("function call with undeclared variable: %s\n", $1); return 0;} 
        //strcpy(params[nr_param++],get_type($1));

    }
    | ID ARR_ACCESS{
        
    }
    | lista_apel ',' NR {}
    | lista_apel ',' ID {}
    | lista_apel ',' ID '(' lista_apel ')' {}
    | lista_apel ',' ID '(' ')' { }
    | lista_apel ',' STRING {}
    | lista_apel ',' 
    ;
*/
