%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

struct var{
          char  id[100], type[100], ch_value[100], scope[100], where[100];
          int _int; 
          int _float; 
          char * _char;
          };


/* 
"&&" {return AND;}
"||" {return OR;}
"==" {return EQ;}
"!=" {return NE;}
">=" {return GE;}
"<=" {return LE;}
">" {return '>';}
"<" {return '<';}
"!" {return NOT;}
 */

%}
%option noyywrap
%%
"int"|"float"|"string"|"bool"|"char" { yylval.strval=strdup(yytext); return TIP;}
\"[_a-zA-Z0-9 ]*\"                  { yylval.strval=strdup(yytext); strcpy(yylval.strval, yylval.strval + 1); yylval.strval[strlen(yylval.strval)-1] = '\0'; return STRING; }
"begin_progr"                       { return BGIN;}
"class"                             { return CLASS;}
"public"|"private"                  { return VIS; }                                                                                         
"end_progr"                         { return END;}                                              
"if"                                { return IF;}
"while"                             { return WHILE;}
"for"                               { return FOR;}
"true"|"false"                      { yylval.strval = strdup(yytext); return BOOL;}
"||"|"&&"|">"|"<"|"!"|"<="|">="|"!=" { yylval.strval = strdup(yytext); return OP_BIN;}
"strcat"                            { yylval.strval = strdup(yytext); return OP_STR;}
[_a-zA-Z][_a-zA-Z0-9]*              { yylval.strval=strdup(yytext); return ID;}
"="                                 { return ASSIGN;}

 
("+"|"-")?([0-9]+)                  { yylval.intval=atoi(yytext); return NR;} 
("+"|"-")?([0-9]+)?"."([0-9]+)?     { yylval.flval=atof(yytext); return FLOAT;}
"+" {return ('+');}
"-" {return ('-');}
"*" {return ('*');}
"/" {return ('/');}

[ \t]                               ;
\n                                  { yylineno++;}
.                                   { return yytext[0];}
 
