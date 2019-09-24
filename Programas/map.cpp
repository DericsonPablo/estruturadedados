#include <iostream>
#include <map>
#include <string>

using namespace std;

map<int, string>mapa;
map<int, string>::iterator it;

int main(){

    mapa[10] = "marcio";
    mapa[100] = "sicrano";
    mapa[50] = "beltrano";

    for(it = mapa.begin(); it != mapa.end(); it++)
        cout << it->first << "->" << it->second << endl;

    it  = mapa.find(100);

    if(it == mapa.end())
        cout << "nao achei" << endl;
    else
        cout << "achei mesmo " << it->second << endl;


    return 0;
}
