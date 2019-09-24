#include <iostream>
#include <vector>
#include <algorithm>
#include <locale.h>

using namespace std;

vector <int>lista;
vector <int>::iterator it;

int main(){

    setlocale(LC_ALL, "");
    lista.push_back(40);
    lista.push_back(10);
    lista.push_back(30);
    lista.push_back(20);
    lista.push_back(50);
    it = lista.begin();
    it += 2;
    lista.insert(it, 15);

    //PRINTAR JEITO NORMAL
    for(int i = 0; i < lista.size(); i++)
        cout << lista[i] << " ";

    cout << endl;
    cout << endl;

    //PRINTAR USANDO AT
    for(int i = 0; i < lista.size(); i++)
        cout << lista.at(i) << " ";

    cout << endl;
    cout << endl;

    //PRINTAR USANDO O ITERADOR
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";

    cout << endl;
    cout << endl;

    //PROCURAR UM NUMERO USANDO FUNCAO FIND DA ALGORITHM
    cout << "procurando número" << endl;
    it = find(lista.begin(), lista.end(), 450);

    if(it == lista.end())
        cout << "não achei " << endl;
    else
        cout << "Achei" << endl;

    cout << endl;
    cout << endl;

    //ORDENAÇÃO
    cout << "ordenação" << endl;
    sort(lista.begin(), lista.end());
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";

    cout << endl;
    cout << endl;

    //REMOVER DA LISTA
    it = lista.begin();
    lista.erase(it);

    //LIMPAR A LISTA TODA
    lista.clear();

    //VERIFICAÇÃO DE LISTA VAZIA
    if(lista.empty())
        cout << "está vazia mesm" << endl;
    else
        cout << "num ta vazia" << endl;

    return 0;


}
