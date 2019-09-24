#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

using namespace std;

int vetor[TAM];

int contador = 0;

void GeraVetor(){

    for(int i = 0; i < TAM; i++){
        vetor[i] = rand() % 20;
        contador++;
    }

}

void insereVetor(){


    for(int i = 0; i < TAM; i++){
        cin  >> vetor[i];
        contador++;
    }

}

void BuscaSequencial(int dado){


    for(int i = 0; i < TAM ; i++){
        if(vetor[i] == dado){
            cout << "Achei o numero " << dado << endl;
            return;
        }

    }

    cout << "nao achei o numero!" << endl;
}


void BuscaSequencialSentinela(int dado){

    int i = 0;
    vetor [contador] = dado;
    while(vetor[i] != dado)
        i++;

    if(i == contador){
        cout << "numero nao encontrado!" << endl;
    }else{
        cout << "achei o numero " << dado << endl;
    }

}

void imprime(){

    cout << "\n";
    for(int i = 0 ; i < contador ; i++)
        cout <<vetor[i] << endl;

}

void moverPraFrente(int dado){

    int i = 0;
    int aux = 0;
    while(i < contador){
        if(vetor[i] == dado){
            cout << "Achei" << endl;
            while(i!=0){
                aux = vetor[i-1];
                vetor[i-1] = vetor[i];
                vetor[i] = aux;
                i--;

            }
             return;
        }
        i++;

    }
    cout << "nao achei" << endl;
}

void transposicao(int dado){

    int i = 0;
    int aux = 0;

    while(i < contador){
        if(vetor[0] == dado){
            cout << "nao eh possivel subir de nivel" << endl;
            return;
        }else if(vetor[i] == dado){
            cout << "Achei" << endl;
                aux = vetor[i-1];
                vetor[i-1] = vetor[i];
                vetor[i] = aux;
                return;
        }
        i++;

    }
    cout << "nao achei" << endl;


}

int main(){
    int i;
    do{
        cout << "\n1 - gera vetor" << endl;
        cout << "2 - inserir vetor" << endl;
        cout << "3 - imprime vetor " << endl;
        cout << "4 - busca sequencial" << endl;
        cout << "5 - busca sequencial com sentinela" << endl;
        cout << "6 - usar o mover pra frente" << endl;
        cout << "7 - usar a transposicao" << endl;
        cout << "0 - Sair\n" << endl;
        cin >> i;

    switch(i){
        case 1:{
            GeraVetor();
        }break;
        case 2:{
            insereVetor();
        }break;
        case 3:{
            imprime();
        }break;
        case 4:{
            cout << "Digite numero a buscar: " << endl;
            cin >> i;
            BuscaSequencial(i);
        }break;
        case 5:{
            cout << "Digite numero a buscar " << endl;
            cin >> i;
            BuscaSequencialSentinela(i);
        }break;
        case 6:{
            cout << "Digite um numero a buscar" << endl;
            cin >> i;
            moverPraFrente(i);
        }break;
        case 7:{
            cout << "Digite um numero a buscar" << endl;
            cin >> i;
            transposicao(i);
        }break;

        cout << "Continuar ?" << endl;
        cin >> i;
    }

    }while(i !=-1);

}
