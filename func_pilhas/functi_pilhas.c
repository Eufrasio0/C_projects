#include <stdio.h>
#include <stdlib.h>
#include "pilhasEnca.h"

void IniciarPilha(PilhaEnca *pilhaEnc){
    pilhaEnc->inicio = NULL;
    pilhaEnc->tam = 0;
}

int Desempilhar(PilhaEnca *pilhaEnca){
    if(Vazia(pilhaEnca)){
        printf("pilha vazia\n");
        return -1;
    }
    No *aux = pilhaEnca->inicio;
    int valor = aux->dado;
    pilhaEnca->inicio = aux->prox;
    free(aux);
    pilhaEnca->tam--;
    return valor;
}

int Vazia(PilhaEnca *pilhaEnca){
    if(pilhaEnca->inicio == NULL){
        return 1;
    }
    return 0;
}

void Empilhar(PilhaEnca *pilhaEnca, int info){
    No *aux = (No *)malloc(sizeof(No));
    aux->dado = info;
    if(Vazia(pilhaEnca)){
        aux->prox = NULL;
        pilhaEnca->inicio = aux;
    }
    else {
        aux->prox = pilhaEnca->inicio;
        pilhaEnca->inicio = aux;
    }
    pilhaEnca->tam++;
}

int Topo(PilhaEnca *pilhaEnca){
    return pilhaEnca->inicio->dado;
}

void ImprimirPilha(PilhaEnca *pilhaEnca){
    if(Vazia(pilhaEnca)){
        printf("Pilha vazia\n");
        return;
    }
    No *aux = pilhaEnca->inicio;
    int tam = 1;
    while(aux != NULL){
        printf("Elemento %d - Dado: %d\n", tam, aux->dado);
        aux = aux->prox;
        tam++;
    }
}


void InverterPilha(PilhaEnca *pilhaEnca){
    if (Vazia(pilhaEnca)) {
            return;
    }
    PilhaEnca aux;
    IniciarPilha(&aux);
    while (!Vazia(pilhaEnca)){
        int x = Desempilhar(pilhaEnca);
        Empilhar(&aux, x);
    }
    pilhaEnca->inicio = aux.inicio;
    pilhaEnca->tam = aux.tam;
}
void EsvaziarPilha(PilhaEnca *pilhaEnca){
    while(!Vazia(pilhaEnca)){
        Desempilhar(pilhaEnca);
    }
}

void MenuPrinc(){
    printf("\n----Menu-----\n");
    printf("\n1 - Inicializar");
    printf("\n2 - Empilhar");
    printf("\n3 - Desempinhar");
    printf("\n4 - Elemento do topo");
    printf("\n5 - Imprimir Pilha");
    printf("\n6 - Inverter Pilha");
    printf("\n7 - Esvaziar a pilha");
    printf("\n8 - \Mudar Pilha");
    printf("\n0- Fim do programa");
    printf("\nEscolha: ");
}

void MenuPilhas(){
    printf("\nEscolha a pilha que sera usada");
    printf("\n1 - Pilha 1");
    printf("\n2 - Pilha 2");
    printf("\n3 - Pilha 3");
    printf("\nEscolha: ");
}

