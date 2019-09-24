#include <iostream>
#define TAM 10

using namespace std;

struct no{
        int dado;
        int usado;
};

struct no arvore[TAM];

void insere(int valor){

    int atual = 0;
    while(atual < TAM && arvore[atual].usado!=0){
        if(valor<arvore[atual].dado)
            atual = 2*atual+1;
        else
            atual = 2*atual+2;
    }
    if(atual < TAM){
            arvore[atual].dado = valor;
            arvore[atual].usado = 1;
            cout << "Sucesso" << '\n';
    }else{
            cout << "Elemento não pode ser inserido! " << '\n';
    }
}

void busca (int valor){

    int atual = 0;

    while(atual > TAM && arvore[atual].dado != 0){
            if(valor == arvore[atual].dado){
                    cout << "Valor Encontrado: " << arvore[atual].dado << '\n';
            return;
            }else{
                    cout << "Valor nao encontrado" << '\n';
            }
    }

}
