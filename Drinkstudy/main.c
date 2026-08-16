#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "func_random.c"

//gcc main.c func_random.c -Wall -Wextra -g3 -o output/main.exe

int main() {
    int h = 0, m = 0, s = 0;
    int esc, min, tipo, shots;
    printLadoALado();
    Beep(750, 300);
    printf("Escolha: ");
    scanf("%d", &esc);
    printf("\nDigite o numero de minutos para o cronometro ou 0 para desligar: ");
    scanf("%d", &min);
        if(min == 0) return 0;
    if(esc == 0){
            while(1){
                printf("Digite 0 para um numero aleatorio de shots\nDigite 1 para definir o numero de shots\n");
                scanf("%d", &tipo);
                if(tipo == 1){
                    printf("Numero de shots: ");
                    scanf("%d", &shots);
                    break;
                }else if(tipo == 0){
                    shots = rand() % (10 - 1 + 1) + 1;
                    break;
                }else{
                    printf("Entrada invalida\n");
                }
            }
        }
    else if(esc == 1){
        while(1){
                printf("Digite 0 para um numero aleatorio de goles\nDigite 1 para definir o numero de goles\n");
                scanf("%d", &tipo);
                if(tipo == 1){
                    printf("Numero de goles: ");
                    scanf("%d", &shots);
                    break;
                }else if(tipo == 0){
                    shots = rand() % (10 - 1 + 1) + 1;
                    break;
                }else{
                    printf("Entrada invalida\n");
                }
            }

    }
    relogio *v = randomVector(shots, min);
    int cont = 0;

    while(m != min) {
        // Limpa a tela (use "cls" no Windows)
        printf("\033[H\033[J"); 

        printf("TIMER\n");
        printf("%02d:%02d:%02d\n", h, m, s);
        if(m == v[cont].m && s == v[cont].s){
            CronoBebida(esc);
            cont++;
        }
        s++;
        if (s > 59) { s = 0; m++; }
        if (m > 59) { m = 0; h++; }
        if (h > 23) { h = 0; }
        printf("\n FIM EM: 00:%02d:00\n", min );
        if(tipo == 1){
        printf("Shots/goles restantes: %d\n", shots - cont);
        }
        else if(tipo == 0){
            printf("Shots/goles restantes: ???\n");
        }
        Sleep(1000);
    }
    return 0;
}



