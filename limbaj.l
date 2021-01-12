%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

#define _int 1
#define _char 2
#define _float 3
#define _bool 4
#define _string 5

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
\"[_a-zA-Z0-9 ]*\" { 
    yylval.strval=strdup(yytext); 
    strcpy(yylval.strval, yytext + 1); 
    yylval.strval[strlen(yylval.strval)-1] = '\0'; 
    return STRING; 
}

\'[_a-zA-Z0-9 ]\'                   {  yylval.number.type=_char; yylval.number.value=yytext[1]; return NR; }
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
"true"|"false"                      { 
    yylval.number.type=_bool;
    if(strcmp(yytext,"true") == 0)
        yylval.number.value=1;
    else 
        yylval.number.value=0;
    return NR;
}
"||"|"&&"|">"|"<"|"!"|"<="|">="|"!=" { yylval.strval = strdup(yytext); return OP_BIN;}
"strcat"                            { yylval.strval = strdup(yytext); return OP_STR;}
"strcpy"                            { return STR_ASSIGN;}
[_a-zA-Z][_a-zA-Z0-9]*              { yylval.strval=strdup(yytext); return ID;}
"="                                 { return ASSIGN;}

[+-]?([0-9]*[.])?[0-9]+ { 
    yylval.number.value=atof(yytext);
    if(strchr(yytext,'.') != NULL)
        yylval.number.type=_float; 
    else 
        yylval.number.type=_int;
    return NR;
}
"+" {return ('+');}
"-" {return ('-');}
"*" {return ('*');}
"/" {return ('/');}


[ \t]                               ;
\n                                  { yylineno++;}
.                                   { return yytext[0];}
 
