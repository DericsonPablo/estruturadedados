//Alunos: Dericson Pablo e Lucas Henrique Fonseca
#include <iostream>
#define TAM 10

// tabela hashing como uma lista encadeada

using namespace std;

struct no{
    int chave;
    struct no *prox;
};

struct no *tabela[TAM];

void inicia(){

    for(int i = 0; i < TAM; i++)
        tabela[i] = NULL;

}

int espalha(int chave){

    return chave % TAM;

}

void insere(int chave){

    int pos;
    struct no *atual, *anterior, *novo;
    pos = espalha(chave);
    atual = tabela[pos];

    while(atual != NULL){
        if(atual->chave == chave){
            return;  // pra nao inserir chave repetida
        }
        anterior = atual;
        atual = atual->prox;
    }

    novo = new(struct no);
    novo->chave = chave;
    cout << "chave " << novo->chave << " inserida." << endl;
    novo->prox = NULL;

    if(tabela[pos] != NULL)
        anterior->prox = novo;
    else
        tabela[pos] = novo;
}

void imprime(){

    struct no *atual;
    for(int i = 0; i < TAM; i++){
        atual = tabela[i];
        cout << "Posicao " << i << " da tabela = ";
        if(atual == NULL ){
            cout << "vazia" << endl;
        }else{
            while(atual!= NULL){
                cout << atual->chave << " ";
                atual = atual->prox;
            }
        cout << endl;
        }
    }
}

void busca(int chave){

    int pos;
    struct no *atual;
    pos = espalha(chave);
    atual = tabela[pos];
    while (atual!=NULL){
        if(atual -> chave == chave){
            cout << "chave encontrada: " << chave << endl;
            return;
        }
        atual = atual -> prox;
    }
    cout << "chave " << chave << " nao encontrada" << endl;

}

int main(){
    inicia();
    insere(50);
    insere(51);
    insere(52);
    insere(53);
    insere(54);
    insere(55);
    insere(56);
    insere(57);
    insere(58);
    insere(68);
    insere(59);
    cout << "imprimindo.." << endl;
    imprime();
    cout << "buscando numeros..." << endl;
    busca(23);
    busca(68);
    return 0;
}
