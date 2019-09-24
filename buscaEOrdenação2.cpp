#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define TAM 10

using namespace std;
int vetor[TAM];

void gera(){
    int i;
    srand(time(NULL));
    for (i=0; i<TAM; i++){
        vetor[i] = rand()%20;
    }
}

void selectionsort(){
    int i,j,aux,aux2;
    for (i=0; i<TAM-1; i++){
        aux = i;
        for (j=i+1; j<TAM; j++){
            if (vetor[aux]>vetor[j]){
                aux = j;
            }
        }
        aux2 = vetor[i];
        vetor[i] = vetor[aux];
        vetor[aux] = aux2;
    }
}

void buscaSequencial(int valor){
    for(int i = 0; i<TAM; i++){
        if(valor == vetor[i]){
            cout << "valor encontrado " << endl;
            return;
        }
    }
    cout << "valor n encontrado" << endl;
}

void buscaSentinela(int valor){
    vetor[TAM-1] = valor;
    int i = 0;
    while(valor != vetor[i]){
        i++;
    }
    if(i == TAM-1 || vetor[i] != valor)
        cout << "valor n encontrado" << endl;
    else
        cout << "valor encontrado" << endl;

}

void buscaBinaria(int valor){
    int inicio = 0, meio;
    int fim = TAM-1;
    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if(vetor[meio] == valor){
            cout << "encontrei" << endl;
            return;
        }
        if(valor < vetor[meio]){
            fim = meio-1;
        }else{
            inicio = meio+1;
        }
    }
    cout << "n achei" << endl;
}

void buscaEmLote(){
    int j = 0, NBuscas, buscas[TAM];
    cout << "Numero de buscas: " << endl;
    cin >> NBuscas;
    for(int i = 0; i<NBuscas; i++){
        cin >> buscas[i];
    }
    for(int i = 0; i< NBuscas; i++){
        while(j<TAM && buscas[i] > vetor[j]){
            j++;
        }
        if(j<TAM && buscas[i] == vetor[j]){
            cout << "encontrei " << buscas[i] << endl;
        }else{
            cout << "n encontrei " << buscas[i] << endl;
        }
    }
}

int main(){
    gera();
    selectionsort();
    for(int i = 0; i<TAM; i++){
        cout << vetor[i] << " " ;
    }
    //buscaSequencial(15);
    //buscaSentinela(15);
    //buscaBinaria(10);
    buscaEmLote();
return 0;
}



