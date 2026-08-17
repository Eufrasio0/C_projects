#include <stdio.h>
#include <stdlib.h>
#include "fila_hospital.h"
#include <string.h>

int main(){
    Fila preferencial;
    Fila normal;
    Inicializar(&normal);
    Inicializar(&preferencial);
    int opcao;
    while(opcao != 6){
            MenuPrin();
            scanf("%d", &opcao);
        switch(opcao){
        case 1:
            ExibirFila(&preferencial, &normal);
            break;
        case 2:
            AdicionarPaciente(&preferencial, &normal);
            break;
        case 3:
            RemoverPaciente(&preferencial, &normal);
            break;
        case 4:
            ImprimirPrimeiro(&preferencial, &normal);
            break;
        case 5:
            Tamanho(&preferencial, &normal);
            break;
        default:
            printf("opcao invalida\n");
            break;
        }
    }

}
