#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <typename T>

T quadrado(T dado){
    return dado*dado;
}

/*
double quadrado(double dado){
    return dado*dado;
}
*/

int main(){

    int valor = 5;
    double valorD = 5.5;

    cout << quadrado<int>(valor) << endl;
    cout << quadrado(valorD) << endl;


    stack<int> pilha;
    queue<int> fila;
    priority_queue<int> pfila;
    vector<int> lista;

    lista.push_back(10);
    lista.push_back(40);
    lista.push_back(30);

    for (int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }
     cout << endl;

     for(int i = 0; i < lista.size(); i++){
        cout << lista.at(i) << " ";
     }

     cout << endl;

    pilha.push(10);
    pilha.push(100);
    pilha.push(50);
    pilha.push(20);
    fila.push(10);
    fila.push(100);
    fila.push(50);
    fila.push(20);
    pfila.push(10);
    pfila.push(100);
    pfila.push(50);
    pfila.push(20);

    cout << "o valor no topo da pilha eh " << pilha.top() << endl;
    cout << "o valor no comeco da fila eh " << fila.front() << endl;
    cout << "----------------------" <<endl;
    cout << "Pilha = " << endl;
    cout  << "comeco: " << pilha.top() << endl;
    cout << "tamanho: " << pilha.size() << endl;

    cout << "--------------------" << endl;

    cout << "Fila = " << endl;
    cout << "comeco: " <<fila.front() << endl;
    cout <<"tamanho: " << fila.size() << endl;
    cout << "---------------------" << endl;
    cout << "Fila de Prioridade = " << endl;
    cout << "comeco: " << pfila.top() << endl;
    cout << "tamanho:  " << pfila.size() << endl;

    pilha.pop();
    fila.pop();
    pfila.pop();


    cout << "o valor no topo da pilha eh " << pilha.top() << endl;
    cout << "o valor no comeco da fila eh " << fila.front() << endl;
    cout << "----------------------" <<endl;
    cout << "Pilha = " << endl;
    cout  << "comeco: " << pilha.top() << endl;
    cout << "tamanho: " << pilha.size() << endl;

    cout << "--------------------" << endl;

    cout << "Fila = " << endl;
    cout << "comeco: " <<fila.front() << endl;
    cout <<"tamanho: " << fila.size() << endl;
    cout << "---------------------" << endl;
    cout << "Fila de Prioridade = " << endl;
    cout << "comeco: " << pfila.top() << endl;
    cout << "tamanho:  " << pfila.size() << endl;

    cout << pilha.empty() << endl;

    return 0;
}
