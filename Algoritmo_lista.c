
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    
        int codigo, idade;
        char nome[30];
        struct lista *prox;
} lista;


typedef struct{
    
    lista *primeiro;
    lista *ultimo;
    
} tipo_lista;

void creat_list(tipo_lista *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
}

int empty(tipo_lista *l){
        l->primeiro == NULL;
}

void insert_end(lista c, tipo_lista *l){
    
    lista *newGuy = (lista*) malloc(sizeof(lista));
    
    *newGuy = c;
    newGuy->prox = NULL;
    
    if(empty(l)){
        l->primeiro = newGuy;
        l-> ultimo  = newGuy;
    }else{
        l->ultimo->prox = newGuy;
        l->ultimo = newGuy;
    }
}

void abrir_lista(tipo_lista *l){
    lista *c = l->primeiro;
    while(c != NULL){
        printf("Codigo: %d\n", c->codigo);
        c = c->prox;
    }
    
}

void creat_user(lista *l){
    printf("Digite o seu nome: ");
    scanf("%s", l->nome);
    printf("\n");
    printf("Digite seu codigo: ");
    scanf("%d". l->codigo);
    printf("\n");
    printf("Digite sua idade: ");
    scanf("%d", l->idade);
    
}


void procurar_codigo(tipo_lista *l){
    
}

int main(){
    
    
    tipo_lista llista;
    lista lis;
    creat_list(&llista);
    
    lis.codigo = 2;
    insert_end(lis, &llista);
    lis.codigo = 3;
    insert_end(lis, &llista);
    abrir_lista(&llista);

    return 0;
}
