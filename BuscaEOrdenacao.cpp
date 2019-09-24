#include <iostream>
#include <stdlib.h>
#define TAM 10

using namespace std;

int vetor[TAM] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void GeraVetor(){
    for(int i = 0; i < TAM; i++){
        vetor[i] = rand() %20;
    }
}

void Bubblers(){

    int aux;
    for(int i = 0; i < TAM; i++){
        for(int j = i+1; j < TAM; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;

            }
        }
    }

}

void buscaLote(){

    int i, j = 0;
    int numBuscas;
    cin >> numBuscas;
    int buscas[numBuscas];

    for(int j = 0; j < numBuscas ; j++)
        cin >> buscas[j];

    for(i = 0; i < numBuscas; i++){
        while(j < TAM && buscas[i] > vetor[j]){
            j++;
        }if(j < TAM && buscas[i] == vetor[j]){
            cout << "Achei " << buscas[i] << endl;
        }else{
            cout << "nao achei " << buscas[i] << endl;
        }
    }

}

void Binario(int valor){
    int e = 0, d = TAM-1, m;

    while(e <= d){
        m = (e+d)/2;

            if(vetor[m] == valor){
                cout << "Achei" << endl;
                return;
            }if(vetor[m] > valor){
                d = m - 1;
            }else{
                e = m + 1;
            }

    }

    cout << "nao achei pora" << endl;

}



int main(){


    Bubblers();
    int a;
    for(int i = 0; i < TAM; i++)
        cout << vetor[i] << endl;
    cin >> a;
    Binario(a);
    buscaLote();
    return 0;
}

