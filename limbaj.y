%{
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
void stack_push(struct var new_elem);
void update_var_int(char x[100], int valoare);
char * get_var_table(char id[100]) ;
char* get_var_scope(char id[100]) ;
int get_var_value(char id[100]);
int same_scope(char x[100], char y[100]) ;
int stack_pop(); //ASTA DA POP LA INDEX 
int val_expr;
%}
 
%union {
     char *strval;
     char _char; 
     char  id[100], type[100], value[100], scope[100], where[100];
     int _int, intval; 
     int _float; 
     char * _string;
}


%token <strval>ID <strval>TIP BGIN END CONST ASSIGN VIS CLASS IF WHILE FOR OP_BIN OP_STR BOOL
%token <strval>FLOAT <intval>NR  
%type <intval>operatii
%left '+' '-'
%left '*' '/'
%start progr
%%
progr
     : decl_gl clasa fnc bloc
     ;
 
 
fnc    
     : functie {
                    ;//cod
               }
     | fnc functie  {
                          ;//cod
                    }
     ;
 
 
lista_param 
     : TIP ID  {
                    if(ok_fun==0)
                    {
                         var_in_fun=total_vars;
                         ok_fun=1;
                    }
                    new_function_buff.param_types[new_function_buff.params_count] = strdup($1);
                    new_function_buff.params_count++;
                    strcpy(tabel_var[total_vars].id, $2);
                    strcpy(tabel_var[total_vars].type, $1);
                    strcpy(tabel_var[total_vars].value, "default");
                    strcpy(tabel_var[total_vars].scope, "functie");
                    total_vars++;
 
                    // printf("1 param  ------ %s \n", $1);
               }
     | lista_param ','  TIP ID     {    if(ok_fun==0)
                                        {
                                            var_in_fun=total_vars;
                                            ok_fun=1;
                                        }
                                        // printf("\t\tdolar: 3 %s, 4 %s\n", $3, $4);
                                        new_function_buff.param_types[new_function_buff.params_count] = strdup($3);
                                        new_function_buff.params_count++;
                                        strcpy(tabel_var[total_vars].id, $4);
                                        strcpy(tabel_var[total_vars].type, $3);
                                        strcpy(tabel_var[total_vars].value, "default");
                                        strcpy(tabel_var[total_vars].scope, "functie");
                                        total_vars++;
                                        printf("HEI, SUNT AICI \n");
                                   }
     ;
 
 
functie   
     : TIP ID '(' lista_param ')' '{' list '}'    { 
                                                       strcpy(new_function_buff.nume, $2);
                                                       if(exists_signature(&new_function_buff) == 1)
                                                            yyerror(),  printf("function %s redefined", 
                                                                                               new_function_buff.nume);
                                                       else
                                                            add_signature(&new_function_buff), total_fnc++;

                                                       // printf("variabile in functie: %d, %d \n",var_in_fun,total_vars);
                                                       for(int i= var_in_fun; i< total_vars; i++)
                                                       {
                                                            // printf("I ARE VALOAREA : %d, %s", i, $2);
                                                            strcpy(tabel_var[i].where, $2);
                                                            strcpy(tabel_var[i].scope, "functie");
                                                       }
                                                       ok_fun=0;
                                                  }
     | TIP ID '(' ')' '{' list '}' { 
                                        new_function_buff.params_count = 0;
                                        strcpy(new_function_buff.nume, $2);
                                        if(exists_signature(&new_function_buff) == 1)
                                             yyerror(), printf("function %s redefined", new_function_buff.nume);
                                        else
                                             add_signature(&new_function_buff);
                                             total_fnc++;
                                   }
                                                                                               
     ;
clasa         
     : CLASS ID '{' VIS ':' decl_cl fnc '}'  {
                                                  strcpy(nume_clasa, $2);     
                                             }
     | CLASS ID '{' VIS ':' decl_cl '}' {
                                             strcpy(nume_clasa, $2); //cod
                                            //  printf("%d, %d\n", var_in_class, total_vars);
                                             for (int i=var_in_class-2; i<total_vars; i++)
                                             {
                                                  strcpy(tabel_var[i].where, nume_clasa);
                                             }
                                             ok=0;
                                             
                                        }
     ;           
decl_cl 
     :  declaratiecl ';'   {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars+1;
                                        ok=1;
                                   }
                              strcpy(tabel_var[total_vars].scope, "clasa");
                              //cod
                         }
     | decl_cl declaratiecl ';' {
                                   if(ok==0)
                                   {
                                        var_in_class=total_vars;
                                        ok=1;
                                   }
                                    strcpy(tabel_var[total_vars].scope, "clasa");
                                  //cod
                              }
     ;
 
declaratiecl
     : TIP ID  { 
                    if(exists_in_var_table($2)==0)
                    {
                         strcpy(tabel_var[total_vars].id, $2);
                         strcpy(tabel_var[total_vars].type, $1);
                         strcpy(tabel_var[total_vars].value, "default");
                         strcpy(tabel_var[total_vars].scope, "clasa");
                         strcpy(tabel_var[total_vars].where, nume_clasa);
                         printf("NUME: CLASA : %s\n", nume_clasa);
                         total_vars++;
                         snprintf(buffer, 100,"%s %s\n", $1 , $2);
                         fprintf(fd, "%s", buffer);}
                    else
                         yyerror(); 
               }
     | TIP ID '(' lista_param ')'  {
                                        //Decl functie cu param
                                   }
     | TIP ID '(' ')'    {
                              //nush ce e aici *: e apelul unei functii fara parametrii
                         }
     ;
      
/* bloc */
bloc 
     : BGIN list END     {
                              ;//cod
                         }   
     ;
     
/* lista instructiuni */
list 
     :  statement ';'    {
                              ;//cod
                         }
     | list statement ';'     {
                                   ;//cod
                              }
     ;
 
 
operatii : operatii '+' operatii {     
                                             {$$ = $1 + $3;  val_expr=$$; }
                                   }
         | operatii '-' operatii {
                                             {$$ = $1 - $3;  val_expr=$$;}
                                  }
         | operatii '*' operatii { 
                                        {$$ = $1 * $3;  val_expr=$$;}

                                   }
         | operatii '/' operatii { 
                                        {$$ = $1 / $3;  val_expr=$$;}
                                   }
         | NR { $$= $1; val_expr=$$; }
         ;
/* instructiune */
decl_gl 
     :  declaratie ';'   {
                              strcpy(tabel_var[total_vars].scope, "global");
                              ;//cod
                         }
     | decl_gl declaratie ';' {
                                    strcpy(tabel_var[total_vars].scope, "global");
                                   ;//cod
                              }
     ;
 
declaratie 
     : TIP ID  { 
                    if(exists_in_var_table($2)==0)
                    {
                         strcpy(tabel_var[total_vars].id, $2);
                         strcpy(tabel_var[total_vars].type, $1);
                         strcpy(tabel_var[total_vars].value, "default");
                         strcpy(tabel_var[total_vars].scope, "global");
                         total_vars++;
                         snprintf(buffer, 100,"%s %s\n", $1 , $2);
                         fprintf(fd, "%s", buffer);}
                    else
                         yyerror(); 
               }
     | TIP ID '(' lista_param ')'  {
                                        //Decl functie cu param
                                   }
     | TIP ID '(' ')'    {
                              //nush ce e aici *: e apelul unei functii fara parametrii
                         }
     ;
 
statement
     :   ID ASSIGN operatii   {
                                 printf("id assign operatii\n");
                                 if (exists_in_var_table($1)==0 )
                                      yyerror();
                                 
                                 printf("%s := %d\n", $1, val_expr);
                                 update_var_int($1, val_expr);
                            }
     | ID ASSIGN ID {

                    printf("id op id\n");
                         struct var * dol1; //era pera lung "dollar"
                         struct var * dol3;
                         dol1 = get_var_from_table($1);
                         dol3 = get_var_from_table($3);
                         if (dol1 == NULL)
                             {yyerror(), printf("undeclared var: %s", $1); return;}
                         if (dol1 == NULL)
                             {yyerror(), printf("undeclared var: %s", $3); return;}
                         if (dol1 != NULL && dol3!= NULL){
                              if(same_type_s(dol1, dol3) && (same_scope($1, $3) || (strcmp(get_var_scope($3),"globala")==0))) 
                              {
                                   ////!!!!!!!!
                                   ///MAI TREBUIE VERIFICAT DACA A DOUA VARIABILA ESTE INITIALIZATA
                                   //////////////////////
                                  printf("%s :=%s   %d \n",$1, $3, get_var_value($3));
                              
                                  update_var_int($1, get_var_value($3));
                                  }
                              else{
                                   yyerror(); ++err_count;
                                   printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, $2, dol3->type);
                                   break;
                              }
                         }
                         
                    }
     | IF '(' bool ')' '{' list '}'     {
                                             ;//cod
                                        }
     | WHILE '(' bool ')' '{' list '}'  {
                                             ;//cod
                                        }
     | FOR '(' ID ASSIGN ID ';' operatii_binare ';' operatii ')' '{' list '}'    {
                                                                                ;//cod
                                                                           }

     | TIP ID  { 
                    if(ok_fun==0)
                    {
                         var_in_fun=total_vars;
                         ok_fun=1;
                    }
 
                    if(exists_in_var_table($2)==0)
                    {
                         strcpy(tabel_var[total_vars].id, $2);
                         strcpy(tabel_var[total_vars].type, $1);
                         strcpy(tabel_var[total_vars].value, "default");
                         strcpy(tabel_var[total_vars].scope, "local");
                         total_vars++;
                         snprintf(buffer, 100,"%s %s %s \n", $1 , $2, "default");
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
     ;
 
lista_apel 
     : NR {
               ;//cod
          }
     | FLOAT   {
                    ;//cod
               }
     | functie {
                    ;//cod
               }
     | ID {
               ;//cod
          }
     | lista_apel ',' NR {
                              ;//cod
                         }
     ;

 bool 
     :      BOOL    {
                         ;//cod
                    }
     | operatii_binare    {
                         ;//cod
                    }
     ;
 
operatii_binare 
     : ID OP_BIN ID    {
                         ;//cod
                    }
     ;
%%
 
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
-actualizarea varlor
-adaugare in vector (verific daca nu depasesc lungimea)
-de adaugat operatii cu stringuri (strlen, strcpy, strcat <este deja la laborator>)
-actualizare var bool (+ operatii cu bool)
-verificare daca parametrii pt apelul functiei sunt aceeasi cu cei ai functiei declarate(daca exista)
 
 
done:
-tabel_vara pentru fnc (exact la fel ca la variabile)
-trebuie verificat si pentru atribuirile de forma x= x+y daca sunt de acelasi tip sau daca au fost
initializate sau daca au fost declarate
 
*/
