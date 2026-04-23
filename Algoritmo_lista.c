
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {

	int codigo, idade;
	char nome[30];
	struct lista *prox;
} lista;


typedef struct {

	lista *primeiro;
	lista *ultimo;

} tipo_lista;

void creat_list(tipo_lista *l) {
	l->primeiro = NULL;
	l->ultimo = NULL;
}

int empty(tipo_lista *l) {
    return (l->primeiro == NULL);
}

void insert_end(lista c, tipo_lista *l) {

	lista *newGuy = (lista*) malloc(sizeof(lista));

	*newGuy = c;
	newGuy->prox = NULL;

	if(empty(l)) {
		l->primeiro = newGuy;
		l-> ultimo  = newGuy;
	} else {
		l->ultimo->prox = newGuy;
		l->ultimo = newGuy;
	}
}

void abrir_lista(tipo_lista *l) {
    lista *c = l->primeiro;
    
    if (c == NULL) {
        printf("\n--- A lista esta vazia ---\n");
        return;
    }

    printf("\n--- LISTA DE USUARIOS ---\n");
    while(c != NULL) {
        printf("Codigo: %d\n", c->codigo);
        printf("NOME: %s\n", c->nome);
        printf("IDADE: %d\n", c->idade); // Adicionado \n
        printf("------------------------\n");
        c = c->prox;
    }
}


void procurar_codigo(tipo_lista *l, int x) {
	lista *atual = l->primeiro;
	int encontrou = 0;

	while(atual != NULL) {
		if(atual->codigo == x) {
			printf("Encontrado \n");
			printf("NOME: %s | CODIGO: %d | IDADE: %d", atual->nome, atual->codigo, atual->idade);
			encontrou = 1;
			break;
		}
		atual = atual->prox;
	}
	if(!encontrou) {
		printf("Usuario nao encontrado");
	}
}

void remover_usuario(tipo_lista *l, int x) {
	lista *atual = l->primeiro;
	lista *anterior = NULL;


	while (atual != NULL && atual->codigo != x) {
		anterior = atual;
		atual = atual->prox;
	}


	if (atual == NULL) {
		printf("Usuario com codigo %d nao encontrado para remocao.\n", x);
		return;
	}


	if (anterior == NULL) {
		l->primeiro = atual->prox;


		if (l->primeiro == NULL) {
			l->ultimo = NULL;
		}
	}

	else {
		anterior->prox = atual->prox;


		if (atual == l->ultimo) {
			l->ultimo = anterior;
		}
	}

	free(atual);
	printf("Usuario %d removido com sucesso.\n", x);
}

int main() {

	tipo_lista llista;
	lista lis;
	creat_list(&llista);
    
	lis.codigo = 10;
	strcpy(lis.nome, "Pedro");
	lis.idade = 30;
	insert_end(lis, &llista);

	lis.codigo = 20;
	strcpy(lis.nome, "Ana");
	lis.idade = 30;
	insert_end(lis, &llista);

	int busca;
	printf("Digite o codigo para buscar: ");
	scanf("%d", &busca);
	procurar_codigo(&llista, busca);

	int cod_remover;
	printf("\nDigite o codigo para remover: ");
	scanf("%d", &cod_remover);
	remover_usuario(&llista, cod_remover);

	abrir_lista(&llista);



	return 0;
}
