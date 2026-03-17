#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int total_nos = 0;

no* criarNo(int v){
    no* novo = (no*) malloc(sizeof(no));
    if(novo){
        novo -> valor = v;
        novo -> esq = NULL;
        novo -> dir = NULL;
        total_nos++;
    }
    return novo;
}

no* construir(int array[], int inicio, int fim){
    if(inicio > fim){
        return NULL;
    }
    
    int meio = (inicio + fim) / 2;
    
    no* novo = criarNo(array[meio]);
    
    novo -> esq = construir(array, inicio, meio - 1);
    
    novo -> dir = construir(array, meio + 1, fim);
    
    return novo;
}

no* inserir(no* raiz, int v){
    if(raiz == NULL){
        criarNo(v);
    }
    else if(v < raiz -> valor){
        raiz -> esq = inserir(raiz -> esq, v);
    }
    else{
        raiz -> dir = inserir(raiz -> dir, v);
    }
    return raiz;
}

no* buscarMenor(no* raiz){
    if(raiz == NULL){
        return NULL;
    }
    
    if(raiz -> esq != NULL){
        return buscarMenor(raiz -> esq);
    }
    
    else{
        return raiz;
    }
}

no* buscarMaior(no* raiz){
    if(raiz == NULL){
        return NULL;
    }
    
    if(raiz -> dir != NULL){
        return buscarMaior(raiz -> dir);
    }
    
    else{
        return raiz;
    }
}

no* buscarSucessor(no* raiz, int v){
    if(raiz == NULL){
        return NULL;
    }
    
    if(raiz -> valor <= v){
        return buscarSucessor(raiz -> dir, v);
    }
    
    else{
        no* temp = buscarSucessor(raiz -> esq, v);
        
        if(temp != NULL){
            return temp;
        }
        
        else{
            return raiz;
        }
    }
}

no* buscarPredecessor(no* raiz, int v){
    if(raiz == NULL){
        return NULL;
    }
    
    if(raiz -> valor >= v){
        return buscarPredecessor(raiz -> esq, v);
    }
    
    else{
        no* temp = buscarPredecessor(raiz -> dir, v);
        
        if(temp != NULL){
            return temp;
        }
        
        else{
            return raiz;
        }
    }
}

no* buscarValor(no* raiz, int v){
    if(raiz == NULL || raiz -> valor == v){
        return raiz;
    }
    
    if(v < raiz -> valor){
        return buscarValor(raiz -> esq, v);
    }
    
    else{
        return buscarValor(raiz -> dir, v);
    }
}

no* remover(no* raiz, int v){
    if(raiz == NULL){
        return NULL;
    }
    
    if(v < raiz -> valor){
        raiz -> esq = remover(raiz -> esq, v);
        return raiz;
    }
    
    else if(v > raiz -> valor){
        raiz -> dir = remover(raiz -> dir, v);
        return raiz;
    }
    
    else{
        
        if(raiz -> esq == NULL && raiz -> dir == NULL){
            free(raiz);
            total_nos--;
            return NULL;
        }
        else if(raiz -> esq == NULL){
            no* temp = raiz -> dir;
            free(raiz);
            total_nos--;
            return temp;
        }
        else if(raiz -> dir == NULL){
            no* temp = raiz -> esq;
            free(raiz);
            total_nos--;
            return temp;
        }
        else{
            no* temp = buscarMenor(raiz -> dir);
            raiz -> valor = temp -> valor;
            raiz -> dir = remover(raiz -> dir, temp -> valor);
            return raiz;
        }
    }
}

int tamanho(no* raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        return 1 + tamanho(raiz -> esq) + tamanho(raiz -> dir);
    }
}

int folhas(no* raiz){
    if(raiz == NULL){
        return 0;
    }
    else if(raiz -> esq == NULL && raiz -> dir == NULL){
        return 1;
    }
    else{
        return folhas(raiz -> esq) + folhas(raiz -> dir);
    }
}

void destruir(no* raiz){
    if(raiz != NULL){
        destruir(raiz -> esq);
        destruir(raiz -> dir);
        free(raiz);
        total_nos--;
    }
}

void imprimir(no* raiz, int n){
    if(raiz){
        imprimir(raiz -> dir, n + 1);
        printf("%*s -> %d\n", n * 5, "", raiz -> valor);
        imprimir(raiz -> esq, n + 1);
    }
}
