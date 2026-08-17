#ifndef FILA_HOSPITAL_H_INCLUDED
#define FILA_HOSPITAL_H_INCLUDED

typedef struct paciente{
    long long int cpf;
    char nome[20];
    int idade;
    char e_gestante;
}Paciente;

typedef struct no{
    Paciente dados;
    struct no *prox;
}No;

typedef struct fila{
    No *inicio;
    int tam;
} Fila;

#endif // FILA_HOSPITAL_H_INCLUDED
