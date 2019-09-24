#include <iostream>
#include <list>
#include <algorithm>
#include <locale.h>

using namespace std;

list <int>lista;
list <int>::iterator it;

int main(){

    setlocale(LC_ALL, "");
    lista.push_back(40);
    lista.push_back(10);
    lista.push_back(30);
    lista.push_back(20);
    lista.push_back(50);
    it = lista.begin();
    it ++;
    it++;
    lista.insert(it, 15);

    //PRINTAR USANDO O ITERADOR
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";

    cout << endl;
    cout << endl;

    //PROCURAR UM NUMERO USANDO FUNCAO FIND DA ALGORITHM
    cout << "procurando n�mero" << endl;
    it = find(lista.begin(), lista.end(), 450);

    if(it == lista.end())
        cout << "n�o achei " << endl;
    else
        cout << "Achei" << endl;

    cout << endl;
    cout << endl;

    //ORDENA��O
    cout << "ordena��o" << endl;
    lista.sort();
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";

    cout << endl;
    cout << endl;

    //REMOVER DA LISTA
    lista.pop_front();
    lista.remove(15);

    //LIMPAR A LISTA TODA
    lista.clear();

    //VERIFICA��O DE LISTA VAZIA
    if(lista.empty())
        cout << "est� vazia mesm" << endl;
    else
        cout << "num ta vazia" << endl;

    return 0;


}
