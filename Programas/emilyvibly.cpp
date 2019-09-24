#include <stdio.h>
#include <stdlib.h>
#define TAM 6

struct no{
    int destino;
    struct no *proximo;
};
struct no *arestas[TAM]; /*vetor de ponteiros q apontm para posições de memoria q existam variaveis struct no
                         criar uma função pra inicializar o vetor com NULL*/

int vertice[TAM];
int contVertices = 0;

void insereVertice(int valor){
    if(contVertices == TAM){
        printf("grafo full\n");
        return;
    }else{
        vertice[contVertices] = valor;
        printf("va ti toma no cu porra\n");
        contVertices++;
    }
}

void insereAresta(int origem, int destino){
    int indiceO = -1, indiceP = -1;
    for(i=0;i<=contVertices;i++){
        if(origem == vertice[i]){
            indiceO = i;
        }
        if (destino == vertice[i]){
            indiceP = i;
        }
    }
    if(indiceO == -1 || indiceP == -1){
        printf("vertice inexistente\n");
        return;
    }
    struct *atual, *anterior = NULL, *aux;
    atual = arestas[indiceO];
    while(atual != NULL){
        if(destino == atual -> destino){
            printf("aresta repetida\n");
            return;
        }
        anterior = atual;
        atual = atual -> proximo;
    }
    aux = new(struct no);
    aux -> destino = destino;
    aux -> proximo = NULL;
    if(arestas[indiceO]==NULL){
        arestas[indiceO] = aux;
    }else{
        anterior -> proximo = aux;
    }
}

void removeAresta(int origem, int destino){

}


