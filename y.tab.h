/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 130 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
