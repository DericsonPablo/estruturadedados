#include <iostream>
#include <clocale>
#define TAM 10
using namespace std;

struct no{
    int dado;
    struct no *esq;
    struct no * dir;
};
struct no * raiz = NULL;

void insereArvore(int valor){
    struct no *atual;
    struct no *anterior;
    struct no *aux;

    aux = new(struct no);
    aux -> dado = valor;
    aux -> esq = NULL;
    aux -> dir = NULL;
    atual = raiz;

    if(atual == NULL){
        raiz = aux;
        return;
    }
    while(atual != NULL){
        anterior = atual;
        if(valor < atual -> dado){
            atual = atual -> esq;
        } else {
            atual = atual -> dir;
        }
    }
    if(valor < anterior -> dado){
        anterior -> esq = aux;
    } else{
        anterior -> dir = aux;
    }

    cout<<"Inserido com sucesso!"<<endl;

}

void insereArvoreSemRepetidos(int valor){
    struct no *atual;
    struct no *anterior;
    struct no *aux;

    aux = new(struct no);
    aux -> dado = valor;
    aux -> esq = NULL;
    aux -> dir = NULL;
    atual = raiz;

    if(atual == NULL){
        raiz = aux;
        return;
    }
    while(atual != NULL){
        anterior = atual;
        if(valor < atual -> dado){
            atual = atual -> esq;
        } else {
            atual = atual -> dir;
        }
    }
    if(valor == anterior -> dado){
        cout<<"Elemento repetido!"<<endl;
        return;
    }
    if(valor < anterior -> dado){
        anterior -> esq = aux;
    } else{
        anterior -> dir = aux;
    }

    cout<<"Inserido com sucesso!"<<endl;

}

bool vazia(){
    if(raiz == NULL){
        return true;
    } else {
        return false;
    }
}

void buscaArvore(int valor){
    struct no *atual;
    struct no *anterior;
    atual = raiz;

    while(atual != NULL){
       if(valor == atual -> dado){
            cout<<"Encontrei o valor."<<endl;
            return;
        }
        if(valor < atual -> dado){
            atual = atual -> esq;
        } else {
            atual = atual -> dir;
        }
    }
    cout<<"Não encontrei o valor!"<<endl;


}

void em_ordem(struct no *atual){
    if(atual != NULL){
        em_ordem(atual -> esq);
        cout<<atual -> dado<<endl;
        em_ordem(atual -> dir);
    }
}

int  main(){
    insereArvore(14);
    insereArvore(24);
    insereArvore(12);
    insereArvore(35);
    insereArvore(10);
    buscaArvore(36);
    em_ordem(raiz);


}



