//Alunos: Dericson Pablo e Lucas Henrique Fonseca
#include <iostream>
#define TAM 10

int h[TAM];

using namespace std;

int espalha(int chave){
    return chave % TAM;
}

int reespalha(int pos){
    return (pos+1) % TAM;
}

void insere(int chave){

    int pos;
    pos = espalha(chave);
    int i = 0;
    if(h[pos] == -1){
        h[pos] = chave;
        cout << "chave inserida" << endl;
        return;
    }

    while(h[pos] != -1){
        pos = reespalha(pos);
        i++;
        if(i == TAM){
            cout << "vetor cheio" << endl;
            return;
        }
    }

    h[pos] = chave;
    cout << "chave inserida" << endl;
}

void busca (int chave) {
    int pos;
    pos = espalha(chave);
    int i = 0;
    if(h[pos] == chave){
        cout << "chave encontrada" << endl;
        return;
    }
    while(h[pos] != chave){
        pos = reespalha(pos);
        i++;
        if(h[pos] == -1){
            cout << "nao achei" << endl;
            return;
        }
        if(i == TAM){
            break;
        }
        if(h[pos] == chave){
            cout << "chave encontrada" << endl;
            return;
        }
    }
    cout << "nao achei" << endl;
}

void imprime(){

    for(int i = 0; i < TAM; i++){
        if(h[i] == -1){
            cout << "posicao " << i << " = " << "vazia" <<  endl;
        }else{
            cout << "posicao " << i << " = " << h[i] << endl;
        }
    }
}

int main(){

    //INICIA COM -1
    for(int i = 0; i < TAM; i++){
        h[i] = -1;
    }

    insere(555);
    insere(16);
    insere(25);
    insere(5);
    insere(6);

    busca(25);
    busca(9);
    cout << "imprimindo.. " << endl;
    imprime();

    return 0;
}
