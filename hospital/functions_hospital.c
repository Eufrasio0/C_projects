#include <stdio.h>
#include <stdlib.h>
#include "fila_hospital.h"
#include <string.h>

void Inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->tam = 0;
    return;
}

void LerPaciente(Paciente *paciente){
    printf("Digite o CPF do paciente:\n");
    scanf("%lld", &paciente->cpf);
    printf("Digite a idade do paciente:\n");
    scanf("%d", &paciente->idade);
    getchar();
    printf("Digite o nome do paciente:\n");
    fgets(paciente->nome, 20, stdin);
    paciente->nome[strcspn(paciente->nome, "\n")] = '\0';
    printf("gestante? (s/n):\n");
    scanf("%c", &paciente->e_gestante);
    return;
}


void AdicionarPaciente(Fila *pref, Fila *normal){
    Paciente pac;
    LerPaciente(&pac);

    No *novo = (No *)malloc(sizeof(No));
    novo->dados = pac;
    novo->prox = NULL;
    if (pac.idade >= 65 || pac.e_gestante == 's') {
        if (pref->inicio == NULL) {
            pref->inicio = novo;
        } else {
            No *aux = pref->inicio;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
        pref->tam++;
    } else {

        if (normal->inicio == NULL) {
            normal->inicio = novo;
        } else {
            No *aux = normal->inicio;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }

        normal->tam++;
    }
}

void ImprimirPaciente(Paciente p) {
    printf("CPF: %lld\n", p.cpf);
    printf("Idade: %d\n", p.idade);
    printf("Nome: %s\n", p.nome);
    printf("gestante: %c\n", p.e_gestante);
}

void ExibirFila(Fila *pref, Fila *nor){
    No *aux = pref->inicio;
    No *tem = nor->inicio;
    if (aux == NULL && tem == NULL) {
        printf("Nenhum paciente nas filas.\n");
        return;
    }
    printf("PREFERENCIAL\n");
    if (aux == NULL) {
        printf("(vazia)\n");
    } else {
        while (aux != NULL) {
            ImprimirPaciente(aux->dados);
            printf("------------------------\n");
            aux = aux->prox;
        }
    }
    printf("\NORMAL\n");
    if (tem == NULL) {
        printf("(vazia)\n");
    } else {
        while (tem != NULL) {
            ImprimirPaciente(tem->dados);
            printf("------------------------\n");
            tem = tem->prox;
        }
    }
}

void RemoverPaciente(Fila *pref, Fila *nor){
    No *aux = pref->inicio;
    No *tem = nor->inicio;
    if (aux == NULL && tem == NULL) {
        printf("Nenhum paciente nas filas.\n");
        return;
    }
    if (aux != NULL) {
        Paciente p = aux->dados;
        pref->inicio = aux->prox;
        free(aux);
        pref->tam--;
        printf("Paciente %s atendido\n", p.nome);
        return;
    }
    if (tem != NULL) {
        Paciente p = tem->dados;
        nor->inicio = tem->prox;
        free(tem);
        nor->tam--;
        printf("Paciente %s atendido!\n", p.nome);
        return;
    }
}

void ImprimirPrimeiro(Fila *pref, Fila *nor){
    No *aux = pref->inicio;
    No *tem = nor->inicio;
    if (aux == NULL && tem == NULL) {
        printf("Nenhum paciente nas filas.\n");
        return;
    }

    if (aux != NULL) {
        printf("Primeiro da fila (Preferencial):\n");
        ImprimirPaciente(aux->dados);
        return;
    }
    printf("Primeiro da fila (Normal):\n");
    ImprimirPaciente(tem->dados);
}

void Tamanho(Fila *pref, Fila *nor){
    int total = pref->tam + nor->tam;
    printf("Total de pacientes nas filas: %d\n", total);
}

void MenuPrin(){
    printf("1 - Exibir a fila\n");
    printf("2 - Entrar na fila\n");
    printf("3 - Sair da fila\n");
    printf("4 - Primeiro da fila\n");
    printf("5 - quantidade da fila\n");
    printf("6 - sair\n");

}
