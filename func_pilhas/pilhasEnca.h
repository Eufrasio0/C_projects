#ifndef PILHASENCA_H_INCLUDED
#define PILHASENCA_H_INCLUDED

typedef struct no{
    int dado;
    struct no *prox;
}No;

typedef struct pilha{
    No *inicio;
    int tam;
}PilhaEnca;

void Empilhar(PilhaEnca *pilhaEnca, int info);
int Desempilhar(PilhaEnca *pilhaEnca);
void EsvaziarPilha(PilhaEnca *pilhaEnca);
void ImprimirPilha(PilhaEnca *pilhaEnca);
void IniciarPilha(PilhaEnca *pilhaEnca);
void InverterPilha(PilhaEnca *pilhaEnca);
void MenuPilhas();
void MenuPrinc();
int Topo(PilhaEnca *pilhaEnca);
int Vazia(PilhaEnca *pilhaEnca);

#endif // PILHASENCA_H_INCLUDED
