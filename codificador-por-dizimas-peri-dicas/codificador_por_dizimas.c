#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int mdc(int a, int b) {
    return b == 0 ? a : mdc(b, a % b);
}

void CriadorGeratriz(int *numerador, int *denominador, char *dizima) {
    char *ponto = strchr(dizima, '.');
    if (!ponto) {
        *numerador = 1;
        *denominador = 1;
        return;
    }

    char parte_inteira[20];
    strncpy(parte_inteira, dizima, ponto - dizima);
    parte_inteira[ponto - dizima] = '\0';
    int inteiro = atoi(parte_inteira);

    char parte_decimal[50];
    strcpy(parte_decimal, ponto + 1);
    int tam = strlen(parte_decimal);

    int intrusos = 0;
    if (tam > 6) intrusos = tam - 6;

    int periodo = tam - intrusos;

    long long denominador_local = 0;
    for (int i = 0; i < periodo; i++) denominador_local = denominador_local * 10 + 9;
    for (int i = 0; i < intrusos; i++) denominador_local *= 10;

    long long parte_total = atoll(parte_decimal);
    char parte_sem_periodo[50];
    strncpy(parte_sem_periodo, parte_decimal, intrusos);
    parte_sem_periodo[intrusos] = '\0';
    long long parte_nao_periodica = intrusos ? atoll(parte_sem_periodo) : 0;

    long long numerador_local = parte_total - parte_nao_periodica;
    numerador_local += (long long)inteiro * denominador_local;

    int divisor = mdc(labs(numerador_local), labs(denominador_local));
    *numerador = numerador_local / divisor;
    *denominador = denominador_local / divisor;
}

void Codificador(int numerador, int denominador, int tamanho, char *string, long long *codigo) {
    for (int i = 0; i < tamanho; i++) {
        double valor = ((double)(unsigned char)string[i] * denominador) / numerador;
        codigo[i] = (long long)round(valor * 1000);
    }
}


void Decodificador(long long *codigo, int numerador, int denominador, int tamanho) {
    char *mensagem = (char*)malloc((tamanho + 1) * sizeof(char));

    for (int i = 0; i < tamanho; i++) {
        double valor = ((double)codigo[i] / 1000.0) * numerador / denominador;
        int caractere = (int)round(valor);

        if (caractere < 32 || caractere > 126) caractere = '?';
        mensagem[i] = (char)caractere;
    }

    mensagem[tamanho] = '\0';
    printf("\n--- MENSAGEM DECODIFICADA ---\n%s\n", mensagem);
    free(mensagem);
}

int main() {
    char *string, dizima[20];
    int numerador, denominador, tamanho;
    long long *codigo;

    while (1) {
        int escolha;
        printf("\n---- BEM VINDO AO CRIPTOGRAFO POR DIZIMAS ----\n");
        printf("1 - CODIFICAR MENSAGEM\n");
        printf("2 - DECODIFICAR MENSAGEM\n");
        printf("3 - SAIR\n: ");
        scanf("%d", &escolha);

        if (escolha == 3) {
            printf("--- FIM DO PROGRAMA ---\n");
            break;
        }

        switch (escolha) {
        case 1:
            printf("-- DIGITE O TAMANHO DA MENSAGEM -- \n: ");
            scanf("%d", &tamanho);
            getchar();

            string = (char*)malloc(sizeof(char) * (tamanho + 1));
            codigo = (long long*)malloc(sizeof(long long) * tamanho);

            printf("-- DIGITE A MENSAGEM QUE SERA CODIFICADA:\n: ");
            fgets(string, tamanho + 1, stdin);

            printf("-- DIGITE A DIZIMA CHAVE (ex: XX.XXXX)\n: ");
            scanf("%s", dizima);

            CriadorGeratriz(&numerador, &denominador, dizima);

            printf("\nNumerador: %d\nDenominador: %d\n", numerador, denominador);

            Codificador(numerador, denominador, tamanho, string, codigo);

            printf("\n--- VALORES CODIFICADOS ---\n");
            for (int i = 0; i < tamanho; i++) {
                printf("%lld ", codigo[i]);
            }
            printf("\n");

            free(string);
            free(codigo);
            break;

        case 2:
            printf("-- QUANTOS CARACTERES TEM A MENSAGEM CODIFICADA? -- \n: ");
            scanf("%d", &tamanho);

            codigo = (long long*)malloc(sizeof(long long) * tamanho);

            printf("-- DIGITE OS VALORES CODIFICADOS --\n:");
            for (int i = 0; i < tamanho; i++) {
                scanf("%lld", &codigo[i]);
            }

            printf("-- DIGITE A DIZIMA CHAVE --:\n: ");
            scanf("%s", dizima);

            CriadorGeratriz(&numerador, &denominador, dizima);

            Decodificador(codigo, numerador, denominador, tamanho);

            free(codigo);
            break;

        default:
            printf("--- ESCOLHA INVALIDA ---\n");
            break;
        }
    }

    return 0;
}
