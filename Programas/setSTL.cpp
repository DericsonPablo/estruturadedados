#include <iostream>
#include <set>

using namespace std;

set <int>conjunto;
set <int>::iterator it;

main{

    conjunto.insert(40);
    conjunto.insert(10);
    conjunto.insert(20);
    conjunto.insert(30);
    conjunto.insert(50);

    for(it = conjunto.begin(); it != conjunto.end(); it++)
        cout << *it << " ";

    cout << endl;

    it = conjunto.find(40);

    if(it == conjunto.end())
        cout << "nao encontrado" << endl;
    else
        cout << "encontrado mesmo" << endl;

    conjunto.erase(30);

    for(it = conjunto.begin(); it != conjunto.end(); it++)
        cout << *it << " ";

    cout << endl;



}
