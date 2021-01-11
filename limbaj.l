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
"begin_progr"                       { return BGIN;}
"end_progr"                         { return END;}                                              
"int"|"float"|"string"|"bool"|"char" { yylval.strval=strdup(yytext); return TIP;}
\"[_a-zA-Z0-9 ]*\"                  { yylval.strval=strdup(yytext); strcpy(yylval.strval, yylval.strval + 1); yylval.strval[strlen(yylval.strval)-1] = '\0'; return STRING; }
\'[_a-zA-Z0-9 ]\'                   { yylval.strval=strdup(yytext); yylval.strval[0]=yylval.strval[1]; yylval.strval[1] ='\0'; return CHR; }
\[[0-9]+\]                          { 
    yylval.strval=strdup(yytext); 
    yylval.strval[0]='0'; 
    yylval.intval=atoi(yylval.strval); //WORKS
    return ARR_ACCESS; 
}
"class"                             { return CLASS;}
"public"|"private"                  { return VIS; }                                                                                         
"if"                                { return IF;}
"while"                             { return WHILE;}
"for"                               { return FOR;}
"true"|"false"                      { yylval.strval = strdup(yytext); return BOOL;}
"||"|"&&"|">"|"<"|"!"|"<="|">="|"!=" { yylval.strval = strdup(yytext); return OP_BIN;}
"strcat"|"upper"|"lower"            { yylval.strval = strdup(yytext); return OP_STR;}
[_a-zA-Z][_a-zA-Z0-9]*              { yylval.strval=strdup(yytext); return ID;}
"="                                 { return ASSIGN;}

[+-]?([0-9]*[.])?[0-9]+ { 
    yylval.number.value=atof(yytext);
    if(strchr(yytext,'.') != NULL)
        yylval.number.is_float=1; 
    else 
        yylval.number.is_float=0;
    return NR;
}
"+" {return ('+');}
"-" {return ('-');}
"*" {return ('*');}
"/" {return ('/');}


[ \t]                               ;
\n                                  { yylineno++;}
.                                   { return yytext[0];}
 
