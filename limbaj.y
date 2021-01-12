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
 

#define _int 1
#define _char 2
#define _float 3
#define _bool 4
#define _string 5

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
float get_float_cast(struct var *from, const int idx);
int get_type(struct var * from);
int val_expr;
%}
 
%union {
    char *strval;
    int intval;
    int blval;
    struct nmbr{
        float value;
        int type;
        int type_err;
    } number;
}

%token <strval>ID <strval>TIP BGIN END CONST ASSIGN VIS CLASS IF WHILE FOR OP_BIN OP_STR BOOL <strval>STRING AND OR NOT '.'    
%token <strval>FLOAT <number>NR <intval>ARR_ACCESS <strval>CHR STR_ASSIGN
%type <number> operatii <blval>bool <blval>operatii_binare <number> variable
%left '+' '-'
%left '*' '/'
%start progr
%%
progr
     : decl_gl clasa fnc bloc
     ;
fnc    
     : functie {}
     | fnc functie  {}
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
    | lista_param ','  TIP ID {    
        if(ok_fun==0)
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
         // printf("HEI, SUNT AICI \n");
    }
    ;
 
 
functie
     : TIP ID '(' lista_param ')' '{' list '}'   { 
        //decl globala functie
        strcpy(new_function_buff.ret_type, $1);
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
        strcpy(new_function_buff.ret_type, $1);
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
     : CLASS ID '{' VIS ':' decl_cl fnc '}'  {strcpy(nume_clasa, $2);}
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
                        //  printf("NUME: CLASA : %s\n", nume_clasa);
                         total_vars++;
                         snprintf(buffer, 100,"%s %s\n", $1 , $2);
                         fprintf(fd, "%s", buffer);}
                    else
                         yyerror(); 
               }
     | TIP ID '(' lista_param ')' {}
     | TIP ID '(' ')' {}
     ;
      
/* bloc */
bloc 
     : BGIN list END     {}   
     ;
     
/* lista instructiuni */
list 
     : statement ';'    {}
     | list statement ';'     { }
     ;

statement
    :ID ASSIGN operatii {
        // printf("%s assign operatii result: %f\n", $1,$3.value);
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table($1);
        if (dol1 == NULL)
            {yyerror(); printf("undeclared var: %s\n", $1); return 0;}
        if($3.type_err > 0)
                {yyerror(); printf("the right side of the assignment does not have the same type throughout the assignment\n"); return 0;}
        else
        if(strcmp(dol1->type, "float") == 0){
            char temp[100];
            sprintf(temp, "%f", $3.value);
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "int") == 0){
            char temp[100];
            sprintf(temp, "%d", (int)$3.value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "bool") == 0){
            printf("da BOOL\n");
            char temp[100];
            sprintf(temp, "%d", (bool)$3.value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
    }
    | ID ARR_ACCESS ASSIGN operatii {
        // printf("id[arr] assign operatii result: %f\n", $4.value);
        struct var * dol1; //era pera lung "dollar"
        dol1 = get_var_from_table($1);
        if (dol1 == NULL)
            {yyerror(); printf("undeclared arr: %s\n", $1); return 0;}
        else 
        if(dol1->is_arr == 0) {yyerror(); printf("%s is not an array\n", $1); return 0;}
        else
        if(dol1->arr_len >= $2) {yyerror(); printf("accessing index out of bound of array %s\n", $1); return 0;}
        if(strcmp(dol1->type, "float") == 0){
            char temp[100];
            sprintf(temp, "%f", $4.value);
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "int") == 0){
            if($4.type_err > 0)
                {yyerror(); printf("the right side of the assignment does not have the same type throughout the assignment\n"); return 0;}
            char temp[100];
            sprintf(temp, "%d", (int)$4.value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
        else 
        if(strcmp(dol1->type, "bool") == 0){
            char temp[100];
            sprintf(temp, "%d", (bool)$4.value); //TREBUIE NEAPARAT CAST CA ALTFEL DA 0
            // printf("%s assign %d\n", $1, (int)$3.value); 
            strcpy(dol1->value, temp);
        }
    }
    | ID STR_ASSIGN ID {
        struct var * dol1;
        struct var * dol3;
        dol1 = get_var_from_table($1);
        dol3 = get_var_from_table($3);
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", $1); return 0;}
        if (dol3 == NULL)
            {yyerror(), printf("undeclared var: %s\n", $1); return 0;}
        if(same_type_s(dol1, &dol3)){
            if(strcmp(dol1->type, "string") != 0){
                yyerror(); 
                printf("trying to do string operation on non string variables\n");
                break;
            }
            if(strcmp(dol1->scope, "main") != 0 && strcmp(dol1->scope, "global") != 0)
                {yyerror(); printf("accessig var from outer scope: %s\n", $1); return 0;}
            if(strcmp(dol3->scope, "main") != 0 && strcmp(dol3->scope, "global") != 0)
                {yyerror(); printf("accessig var from outer scope: %s\n", $3); return 0;}
            var_assign(dol1, dol3);
        }
        else{
            yyerror(); 
            printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, $2, dol3->type);
            break;
        }
    }
    | TIP ID ARR_ACCESS {
        // printf("declared array %d\n", $3);
        if($3 > 100) {yyerror(""), printf("\tmax arr size is 100 and you declared %d\n", $3); return 0;}
        struct var * dol2;
        dol2 = get_var_from_table($2);
        if (dol2 != NULL && (same_scope(dol2->id, $2)))
            {yyerror(), printf("already declared array: %s\n", $2); return 0;}
        strcpy(tabel_var[total_vars].id, $2);
        strcpy(tabel_var[total_vars].type, $1);
        strcpy(tabel_var[total_vars].value, "default");
        strcpy(tabel_var[total_vars].scope, "main");
        tabel_var[total_vars].arr_len = $3;
        tabel_var[total_vars].is_arr = 1;
        total_vars++;
    }
    | TIP ID  { 
        // printf("declarare tip id\n");
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
             strcpy(tabel_var[total_vars].scope, "main");
             total_vars++;
        }
        else
             {yyerror(), printf("already declared variable1: %s\n", $2); return 0;} 
        // printf("%d\n", ok_fun);
        if(ok_fun==1)
        {
             strcpy(tabel_var[total_vars].scope, "functie");
        }
    }
    | ID STR_ASSIGN STRING {
        struct var * dol1;
        struct var dol3;
        dol1 = get_var_from_table($1);
        strcpy(dol3.type, "string");
        strcpy(dol3.value, $3);
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", $1); return 0;}
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
            printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, $2, dol3.type);
            break;
        }
    }
    | ID OP_STR ID {
        struct var * dol1;
        struct var * dol3;
        dol1 = get_var_from_table($1);
        dol3 = get_var_from_table($3);
        if (dol1 == NULL)
            {yyerror(), printf("undeclared var: %s\n", $1); return 0;}
        if (dol3 == NULL)
            {yyerror(), printf("undeclared var: %s\n", $3); return 0;}
        if(strcmp(dol3->value, "default") == 0)
            {yyerror(), printf("uninitialised string: %s\n", $3); return 0;}
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
            printf("trying to do operation on variables of different types: %s %s %s\n", dol1->type, $2, dol3->type);
        }
    }
    | ID '(' ')' {      
        printf("apel functie din main\n");
        if(exists_function($1)==0)
            {yyerror(), printf("call to undeclared function: %s\n", $1); return 0;}
    }
    | ID '(' lista_apel ')' {
        printf("apel funectie din main + lista apel\n");
        if(exists_function($1)==0)
            yyerror();
        ///
        ///////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////
        //TREBUIE FACUT UN VECTOR DE TIPURI PENTRU APEL SI VERIFICAT DACA ARE ACELASI TIP CU VARIABILELE 
        //DIN FUNCTIA DECLARATA MAI SUS
        /////////////////////////////////////////////
        ////////////////////////////////
    }
    | IF '(' bool ')' '{' list '}'     {}
    | WHILE '(' bool ')' '{' list '}'  {}
    | FOR '(' ID ASSIGN ID ';' operatii_binare ';' operatii ')' '{' list '}'    {}
    ;
 
 
operatii 
    : operatii '+' operatii { $$.value = $1.value + $3.value; $$.type_err = ($1.type != $3.type); $$.type = $1.type; if($1.type==_string || $3.type == _string) {yyerror(); printf("illegal operation on string var\n"); return 0;}}
    | operatii '-' operatii { $$.value = $1.value - $3.value; $$.type_err = ($1.type != $3.type); $$.type = $1.type; if($1.type==_string || $3.type == _string) {yyerror(); printf("illegal operation on string var\n"); return 0;}}
    | operatii '*' operatii { $$.value = $1.value * $3.value; $$.type_err = ($1.type != $3.type); $$.type = $1.type; if($1.type==_string || $3.type == _string) {yyerror(); printf("illegal operation on string var\n"); return 0;}}
    | operatii '/' operatii { $$.value = $1.value / $3.value; $$.type_err = ($1.type != $3.type); $$.type = $1.type; if($1.type==_string || $3.type == _string) {yyerror(); printf("illegal operation on string var\n"); return 0;}}
    | variable {/*NON STRING VARIABLE*/}
    ;

variable
    : NR { $$.value = $1.value; $$.type_err = 0; $$.type = $1.type;}
    | ID {
        struct var * dol1;
        dol1 = get_var_from_table($1); 
        if (dol1 == NULL)
            {yyerror(), printf("undeclared variable: %s\n", $1); return 0;}
        if(strcmp(dol1->scope, "main") != 0 && strcmp(dol1->scope, "global") != 0){
            {yyerror(); printf("accessig var from outer scope: %s\n", $1); return 0;}
        }
        if(strcmp(dol1->value, "default") == 0){
            {yyerror(); printf("uninitialised var on the right side: %s\n", $1); return 0;}
        }
        $$.value = get_float_cast(dol1, -1);
        $$.type = get_type(dol1);
        $$.type_err = 0;
    }
    | ID ARR_ACCESS {
        struct var * dol1;
        dol1 = get_var_from_table($1);
        if (dol1 == NULL)
            {yyerror(), printf("function call with undeclared variable: %s\n", $1); return 0;} 
        if(strcmp(dol1->scope, "main") != 0 && strcmp(dol1->scope, "global") != 0){
            {yyerror(); printf("accessig var from outer scope: %s\n", $1); return 0;}
        }
        if(strcmp(dol1->value, "default") == 0){
            {yyerror(); printf("uninitialised var on the right side: %s\n", $1); return 0;}
        }
        //verif pt uninitialised?
        $$.value = get_float_cast(dol1, $2);
        $$.type = get_type(dol1);
        $$.type_err = 0;
    }
    ;

/* instructiune */
decl_gl 
    : declaratie ';'   {strcpy(tabel_var[total_vars].scope, "global");}
    | decl_gl declaratie ';' {strcpy(tabel_var[total_vars].scope, "global");}
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
        }
        else
             yyerror(); 
    }
    | TIP ID ARR_ACCESS {
        if(exists_in_var_table($2)==0){
            strcpy(tabel_var[total_vars].id, $2);
            strcpy(tabel_var[total_vars].type, $1);
            strcpy(tabel_var[total_vars].value, "default");
            strcpy(tabel_var[total_vars].scope, "global");
            total_vars++;
            tabel_var[total_vars].arr_len = $3;
            tabel_var[total_vars].is_arr = 1;
        }
        else
             yyerror();
    }
    | TIP ID '(' lista_param ')'  {printf("var: %s\n", $2);}
    | TIP ID '(' ')' {}
    ;

lista_apel 
    : NR {printf("small rule\n");}
    | ID {
        struct var * dol1;
        dol1 = get_var_from_table($1);
        if (dol1 == NULL)
            {yyerror(), printf("function call with undeclared variable: %s\n", $1); return 0;} 

    }
    | ID ARR_ACCESS{
        
    }
    | lista_apel ',' NR {printf("small rule apel functie\n");}
    | lista_apel ',' ID {}
    | lista_apel ',' ID '(' lista_apel ')' {/*idk man*/}
    | lista_apel ',' ID '(' ')' {}
    | lista_apel ',' STRING {}
    | lista_apel ',' 
    ;
////////////////////////////////////////////////////////////////////////////

//////////////TREBUIE ADAUGATE OPERATII PE BOOL SI STRING 
/////////////////////////////////////////////////////////////
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

float get_float_cast(struct var *from, const int idx){
    if(idx >= 0){
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
