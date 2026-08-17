#ifndef REIDOMOCOTO_H_INCLUDED
#define REIDOMOCOTO_H_INCLUDED

typedef struct no{
    char nome[20];
    struct no *prox;
}No;

typedef struct fila{
    No *inicio;
    int tam;
} Fila;

void IniciarFila(Fila *fila);
void Adicionar(Fila *fila);
void ImprimirFila(Fila *fila);
void RemoverFilaPedido(Fila *pedido, Fila *pagamento);
void RemoverFilaPagamento(Fila *pagamento, Fila *encomenda);
void AtenderEncomenda(Fila *encomenda);
void MenuPrin(void);
void Filas(void);

#endif // REIDOMOCOTO_H_INCLUDED
