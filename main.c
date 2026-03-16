#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{   
    no* raiz = NULL;
    
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}
    int tamanho = sizeof(array[]) / sizeof(array[0]);
    
    printf("----CONSTRUINDO ARVORE FODAPLAYS----\n\n");
    
    raiz = construir(array, 0, tamanho - 1);
    
    imprimir(raiz, 0);
    
    printf("\n----------------------------------------------\n");

    printf("\nTotal de nos: %d", total_nos);
    printf("\nTotal nos(recursão): %d", tamanho(raiz));
    printf("\nTotal folhas: %d", folhas(raiz));
    
    printf("\n----------------------------------------------\n");
    
    no* menor = buscarMenor(raiz);
    no* maior = buscarMaior(raiz);
    
    if(menor == NULL){
        printf("\nFunção de buscar menor falhou!");
    }
    else{
        printf("\nO menor é %d", menor -> valor);
    }
    if(maior == NULL){
        printf("\nFunção de buscar maior falhou!");
    }
    else{
        printf("\nO maior é %d", maior -> valor);
    }
    
    printf("\n----------------------------------------------\n");
    
    remover(raiz, 50);
    printf("\n");
    imprimir(raiz, 0);
    printf("\nTotal de nos: %d", total_nos);
    
    printf("\n----------------------------------------------\n");
    
    destruir(raiz);
    raiz = NULL;
    printf("\nTotal de nos: %d", total_nos);
    
    printf("----ENCERRANDO ARVORE FODAPLAYS----\n\n");
    return 0;
}
