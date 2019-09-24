#include <iostream>
#include <stdio.h>
#include <string.h> //comparacao strings, etc
#include <ctype.h> //caracteres minusculos

using namespace std;

struct no {
       char dado[50];
       struct no *esq;
       struct no *dir;
};

struct no *raiz = NULL;

void insere(char palavra){
       struct no *atual;
       struct no *anterior;
       struct no *aux;
           aux = new(struct no);
           aux->dado= palavra;
           aux->esq=NULL;
           aux->dir=NULL;
           atual=raiz;
              if(atual==NULL){
                     raiz=aux;
              return;
              }
              while(atual!=NULL){
                     anterior = atual;
                     if(palavra<atual->dado)
                            atual = atual->esq;
                     else
                            atual = atual->dir;
              }
              if(palavra<anterior ->dado){
                     anterior->esq = aux;
                     cout<<"O valor "<<palavra<<" foi inserido a esquerda do numero: "<<anterior->dado<<endl;
              }
              else {
                     anterior ->dir = aux;
              cout<<"O valor "<<palavra<<" foi inserido a direita do numero: "<<anterior->dado<<endl;
              }
}

void emOrdem(struct no *atual){
       if(atual!=NULL){
              emOrdem(atual->esq);
              cout<<""<<atual->dado<<endl;
              emOrdem(atual->dir);
       }
}

int main (){

    char palavra[50];
    FILE *fp;
    fp = fopen ("texto.txt", "r");
    if(fp == NULL){
        cout << "Erro!" < "\n";
        return 0;
    }

    while(!feof(fp)){   //ENQUANTO NAO FIM DE ARQUIVO
        fscanf(fp,"%s", palavra); //NAO PRECISA & PORQUE E STRING
        cout << palavra ;
    }
    fclose(fp);

    /*  a = b; ================= strcpy(a,b);
        if(a==b); ============== if(strcmp(a,b)==0)
    */
}
