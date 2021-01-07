
int main(int argc, char **argv) {
    fd = fopen("table.txt", "ab+");
    fprintf(fd, "salutare");
    if (fd == NULL) {
        printf("eroare");
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    if (errors == 0) {
        printf("Program corect sintactic!\n");
        printf("Afisez valorile din tabelul cu variabile:  \n");
        for (int i = 0; i < total_variables; i++)
            printf("\t %s %s %s \n", tabel[i].nume_id, tabel[i].value, tabel[i].type);
        printf("fun decl :\n");
        for (int i = 0; i <= total_functions; i++)
            printf("\t %s\n", tabel_functii[i].nume);
    } else {
        printf("Au fost gasite erori de compilare\n");
    }
}
int verif(char x[100])  //cauta o variabila in tabela, daca exista
{
    for (int i = 0; i < total_variables; i++) {
        if (strcmp(tabel[i].nume_id, x) == 0)
            return 1;
    }
    return 0;
}
int is_default(char x[100])  //verifica daca o variabila are vreo valoare atribuita sau a ramas doar de la atribuire
{
    for (int i = 0; i < total_variables; i++) {
        if (strcmp(tabel[i].nume_id, x) == 0)
            if (strcmp(tabel[i].value, "default") == 0)
                return 1;
    }
    return 0;
}
void update_var(char x[100], char y[100])  //face update in tabela pt atribuiri de genul x:=5 , nu merge si pentru x:=y
{
    char valuex[100];
    int j;
    for (int i = 0; i < total_variables; i++) {
        if (strcmp(tabel[i].nume_id, y) == 0)
            strcpy(valuex, tabel[i].value);
        if (strcmp(tabel[i].nume_id, x) == 0)
            j = i;
    }
    strcpy(tabel[j].value, valuex);
}
void update_int(char x[100], int y) {
    for (int i = 0; i < total_variables; i++) {
        if (strcmp(tabel[i].nume_id, x) == 0)
            sprintf(tabel[i].value, "%d", y);
    }
}

int same_type(char x[100], char y[100])  // verifica daca 2 var au acelasi tip (ex nu se poate float=int)
{
    char typex[100], typey[100];
    for (int i = 0; i < total_variables; i++) {
        if (strcmp(tabel[i].nume_id, x) == 0)
            strcpy(typex, tabel[i].type);
        if (strcmp(tabel[i].nume_id, y) == 0)
            strcpy(typey, tabel[i].type);
    }
    if (strcmp(typex, typey) == 0)
        return 1;
    return 0;
}

int same_type_number(char x[100], char y[100])  //verifica daca o variabila si nr atribuit au acelasi tip (ex nu se poate float=int)
{
    char typex[100];
    for (int i = 0; i < total_variables; i++) {
        if (strcmp(tabel[i].nume_id, x) == 0)
            strcpy(typex, tabel[i].type);
    }
    if (strcmp(typex, y) == 0)
        return 1;
    return 0;
}

int same_signature(struct signature *new_f) {
    for (int ii = 0; ii < total_functions; ++ii) {
        if (strcmp(tabel_functii[ii].nume, new_f->nume) == 0) {
            if (tabel_functii[ii].is_method == new_f->is_method) {
                if (tabel_functii[ii].param_number == new_f->param_number) {
                    for (int j = 0; j < new_f->param_number; j++) {
                        if (strcmp(tabel_functii[ii].param_types[j],
                                   new_f->param_types[j]) != 0)
                            return 1;
                    }
                    yyerror("same signature function duplicated");
                    return 0;
                }
            }
        }
    }
    return 1;
}

int add_signature(struct signature *new_f) {
    strcpy(tabel_functii[total_functions].nume, new_f->nume);
    strcpy(tabel_functii[total_functions].parent_class, new_f->nume);
    tabel_functii[total_functions].is_method = new_f->is_method;
    tabel_functii[total_functions].param_number = new_f->param_number;
    for (int i = 0; i < tabel_functii[total_functions].param_number; ++i) {
        tabel_functii[total_functions].param_types[i] = strdup(new_f->param_types[i]);
    }
    total_functions++;
    return 1;
}