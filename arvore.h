#ifndef ARVORE_H
#define ARVORE_H

typedef struct no{
    int valor;
    struct no* esq;
    struct no* dir;
}no;

extern int total_nos;

no* criarNo(int v);
no* construir(array[], int inicio, int fim);
no* inserir(no* raiz, int v);
no* buscarMenor(no* raiz);
no* buscarMaior(no* raiz);
no* remover(no* raiz, int v);
int tamanho(no* raiz);
int folhas(no* raiz);
void destruir(no* raiz);
void imprimir(no* raiz, int nivel);

#endif
