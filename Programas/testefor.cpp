#include <iostream>

using namespace std;

int main(){

int vetor[10] = {0,1,2,3,4,5,6,7,8,9};
int existe1 = 2, existe2 = 5;

for(int i = 0 ; i< 10; i++){
    if(vetor[i] == existe1)
        existe1 = 1;
    if(vetor[i] == existe2)
        existe2 = 1;
}

cout << existe1 << existe2 << endl;



}
