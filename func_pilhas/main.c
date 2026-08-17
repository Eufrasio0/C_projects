#include <stdio.h>
#include <stdlib.h>
#include "pilhasEnca.h"

int main(){
    PilhaEnca p1, p2, p3;
    IniciarPilha(&p1);
    IniciarPilha(&p2);
    IniciarPilha(&p3);
    int pilhaUsada = -1;
    int opcao = -1;
    int dado;

    while(opcao != 0){
        MenuPrinc();
        scanf("%d", &opcao);
        switch(opcao){
        case 8:
            MenuPilhas();
            scanf("%d", &pilhaUsada);
            if(pilhaUsada < 1 || pilhaUsada > 3){
                printf("\nPilha invalida\n");
                pilhaUsada = -1;
            }
            break;
        case 1:
            if(pilhaUsada == -1){
                printf("\nEscolha antes qual pilha usar (opcao 8)\n");
                break;
            }
            if(pilhaUsada == 1) IniciarPilha(&p1);
            else if(pilhaUsada == 2) IniciarPilha(&p2);
            else IniciarPilha(&p3);
            printf("\nPilha inicializada\n");
            break;
        case 2:
            if(pilhaUsada == -1){
                printf("\nEscolha antes qual pilha usar (opcao 8)\n");
                break;
            }
            printf("\nDigite o valor a empilhar: ");
            scanf("%d", &dado);
            if(pilhaUsada == 1) Empilhar(&p1, dado);
            else if(pilhaUsada == 2) Empilhar(&p2, dado);
            else Empilhar(&p3, dado);
            break;
        case 3:
            if(pilhaUsada == -1){
                printf("\nEscolha antes qual pilha usar (opcao 8)\n");
                break;
            }
            if(pilhaUsada == 1) dado = Desempilhar(&p1);
            else if(pilhaUsada == 2) dado = Desempilhar(&p2);
            else dado = Desempilhar(&p3);
            if(dado != -1)
                printf("\nValor removido: %d\n", dado);
            break;

        case 4:
            if(pilhaUsada == -1){
                printf("\nEscolha antes qual pilha usar (opcao 8)\n");
                break;
            }
            if(pilhaUsada == 1 && !Vazia(&p1)){
                printf("\nTopo: %d\n", Topo(&p1));
            } else if(pilhaUsada == 2 && !Vazia(&p2)){
                 printf("\nTopo: %d\n", Topo(&p2));
            } else if(pilhaUsada == 3 && !Vazia(&p3)) {
                printf("\nTopo: %d\n", Topo(&p3));
            } else{
                printf("\nPilha vazia!\n");
            }
            break;

        case 5:
            if(pilhaUsada == -1){
                printf("\nEscolha antes qual pilha usar (opcao 8)\n");
                break;
            }
            printf("\nConteudo da pilha:\n");
            if(pilhaUsada == 1) ImprimirPilha(&p1);
            else if(pilhaUsada == 2) ImprimirPilha(&p2);
            else ImprimirPilha(&p3);
            break;
        case 6:
            if(pilhaUsada == -1){
                printf("\nEscolha antes qual pilha usar (opcao 8)\n");
                break;
            }
            if(pilhaUsada == 1) InverterPilha(&p1);
            else if(pilhaUsada == 2) InverterPilha(&p2);
            else InverterPilha(&p3);
            printf("\nPilha invertida!\n");
            break;
        case 7:
            if(pilhaUsada == -1){
                printf("\nEscolha antes qual pilha usar (opcao 8)\n");
                break;
            }
            if(pilhaUsada == 1) EsvaziarPilha(&p1);
            else if(pilhaUsada == 2) EsvaziarPilha(&p2);
            else EsvaziarPilha(&p3);
            printf("\nPilha esvaziada!\n");
            break;
        case 0:
            printf("\nFim do programa\n");
            break;
        default:
            printf("\nOpçao invalida!\n");
        }
    }

    return 0;
}

