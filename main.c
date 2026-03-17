#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    no* raiz = NULL;
    
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int tamanho_array = sizeof(array) / sizeof(array[0]);
    
    printf("\n------Construindo arvore muito foda------\n\n");
    
    raiz = construir(array, 0, tamanho_array - 1);
    
    imprimir(raiz, 0);
    
    printf("\n----------------------------------------------------------\n");
    printf("\nTotal de nos: %d", total_nos);
    printf("\nTotal de nos(recursão): %d", tamanho(raiz));
    printf("\nTotal de folhas: %d", folhas(raiz));
    printf("\n\n----------------------------------------------------------\n");
    
    no* menor = buscarMenor(raiz);
    no* maior = buscarMaior(raiz);
    no* alvo = buscarValor(raiz, 20);
    no* sucessor = buscarSucessor(raiz, 20);
    no* predecessor = buscarPredecessor(raiz, 20);
    
    if(menor == NULL){
        printf("\nFunção de buscar menor falhou!");
    }
    else{
        printf("\nO menor valor é %d", menor -> valor);
    }
    if(maior == NULL){
        printf("\nFunção de buscar maior falhou");
    }
    else{
        printf("\nO maior valor é %d", maior -> valor);
    }
    
    printf("\n\nBuscando informações do numero 20\n");
    
    if(alvo == NULL){
        printf("\nNumero alvo nao foi encontrado");
    }
    else{
        printf("\nO numero %d foi encontrado na arvore", alvo -> valor);
    }
    if(sucessor == NULL){
        printf("\nFunção buscar sucessor falhou");
    }
    else{
        printf("\nO sucessor é %d", sucessor -> valor);
    }
    if(predecessor == NULL){
        printf("\nFunção de buscar predecessor falhou");
    }
    else{
        printf("\nO predecessor é %d", predecessor -> valor);
    }
    
    printf("\n\n----------------------------------------------------------\n");
    
    remover(raiz, 50);
    printf("\nRemovendo valor 50 da arvore!\n\n");
    
    imprimir(raiz, 0);
    printf("\n\nTotal de nos: %d", total_nos);
    
    destruir(raiz);
    printf("\n\n--------Destruindo a arvore--------\n");
    printf("\nTotal de nos: %d", total_nos);
    
    printf("\n\n----------Encerrando arvore----------");
    return 0;
}
