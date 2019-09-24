#include <iostream>
#include <stdlib.h>
#define TAM 10
#include <time.h>

using namespace std;

int vetor[TAM] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};



void Ordena(int vetor[]){

    int aux;
    for(int i = 0; i < TAM ; i++){
        for(int j = i+1; j < TAM; j++){
            if(vetor[i] > vetor[j]){
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }
            }
    }

}

void BuscaBinaria(int valor){

    int e = 0, m, d = TAM-1;
    while(e <= d){
            m = (e + d)/2;
            if(vetor[m] == valor){
                cout << "achei o numero" << endl;
                return;
            }
            if(vetor[m] < valor)
                e = m + 1;
            else
                d = m - 1;
    }

    cout << "nao achei pora" << endl;
}

int main(){

    int i = 0;
    clock_t tempo, tempo2;
    tempo = clock();
    Ordena(vetor);
    tempo2 = clock() - tempo;
    cout <<  (double)tempo2/CLOCKS_PER_SEC << endl;
    BuscaBinaria(2);
    return 0;
}
