lex limbaj.l ; sleep .2;
yacc -d -v limbaj.y ; sleep .2;
gcc lex.yy.c y.tab.c -ll
