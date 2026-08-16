#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// estrutura relogio (se ainda não estiver declarada)
typedef struct {
    int h;
    int m;
    int s;
} relogio;

// funções
relogio* randomVector(int shots, int max);

void printLadoALado(void);
void printDir(void);
void printEsq(void);

void CronoBebida(int escolha);

#endif