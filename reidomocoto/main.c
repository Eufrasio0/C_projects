#include <stdio.h>
#include <stdlib.h>
#include "reidomocoto.h"

int main(){
    Fila pedido;
    Fila pagamento;
    Fila encomenda;
    IniciarFila(&pedido); IniciarFila(&pagamento); IniciarFila(&encomenda);
    int opcao;
    while(opcao){
        MenuPrin();
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            Adicionar(&pedido);
            break;
        case 2:
            RemoverFilaPedido(&pedido, &pagamento);
            break;
        case 3:
            RemoverFilaPagamento(&pagamento, &encomenda);
            break;
        case 4:
            AtenderEncomenda(&encomenda);
            break;
        case 5:
            Filas();
            scanf("%d", &opcao);
            if(opcao == 1){
                ImprimirFila(&pedido);
                    break;
            }else if(opcao == 2){
                ImprimirFila(&pagamento);
                break;
            }else if(opcao == 3){
                ImprimirFila(&encomenda);
                break;
            }
            else{
                printf("opcao invalida\n");
                break;
            }
        default:
            printf("Opcao invalida\n");
            break;
        }
    }

}
