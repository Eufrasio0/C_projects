#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reidomocoto.h"

void IniciarFila(Fila *fila){
    fila->inicio = NULL;
    fila->tam = 0;
    return;
}


void Adicionar(Fila *fila){
    No *novo = (No *)malloc(sizeof(No));
    char nome[20];
    printf("Digite o nome do cliente: ");
    getchar();
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->tam++;
        return;
    }
    No *aux = fila->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    fila->tam++;
}


void RemoverFilaPedido(Fila *pedido, Fila *pagamento){
    if (pedido->inicio == NULL) {
        printf("Fila de pedidos vazia\n");
        return;
    }
    No *removido = pedido->inicio;
    pedido->inicio = removido->prox;
    removido->prox = NULL;
    pedido->tam--;
    if (pagamento->inicio == NULL) {
        pagamento->inicio = removido;
    } else {
        No *aux = pagamento->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = removido;
    }
    pagamento->tam++;
    printf("removido com sucesso!\n");
}


void RemoverFilaPagamento(Fila *pagamento, Fila *encomenda){
    if (pagamento->inicio == NULL) {
        printf("Fila de pagamento vazia!\n");
        return;
    }
    No *removido = pagamento->inicio;
    pagamento->inicio = removido->prox;
    removido->prox = NULL;
    pagamento->tam--;
    if (encomenda->inicio == NULL) {
        encomenda->inicio = removido;
    } else {
        No *aux = encomenda->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = removido;
    }
    encomenda->tam++;
    printf("removido com sucesso!\n");
}

void ImprimirFila(Fila *fila){
    No *aux = fila->inicio;
    if(aux == NULL){
        printf("\nFila Vazia\n");
        return;
    }
    while(aux!= NULL){
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
    return;
}

void AtenderEncomenda(Fila *encomenda){
    if (encomenda->inicio == NULL) {
        printf("Fila de encomenda vazia!\n");
        return;
    }
    No *removido = encomenda->inicio;
    encomenda->inicio = removido->prox;
    encomenda->tam--;
    printf("%s atendido com sucesso!\n", removido->nome);
    free(removido);
}

void MenuPrin(){
    printf("\n1 - Adicionar cliente em pedidos\n");
    printf("2 - Remover cliente em pedidos\n");
    printf("3 - Remover cliente em pagamento\n");
    printf("4 - Remover cliente em encomenda\n");
    printf("5 - Imprimir Filas\n");
    printf("0 - Finalizar programa\n");
    printf("Escolha:");
}

void Filas(){
    printf("\nQual fila deseja imprimir?\n");
    printf("1 - imprimir fila de pedidos\n");
    printf("2 - imprimir fila de pagamentos\n");
    printf("3 - imprimir fila de encomendas\n");
    printf("Escolha:");
}
