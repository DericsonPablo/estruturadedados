#include<stdio.h>

struct pilha{       //struct para letra
char letra;
struct pilha *next;
};

struct pilha *topo = NULL;  //como nao há ninguem na pilha, entao o topo aponta para nada

char push(char x);          //função que empilha letras na pilha
char pop();                 //função que desempilha

int main(){

char letra = 'a';                 //letra a ser inserida

while((letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122)){       //enquanto uma letra for lida
    letra = getchar();                //recebo essa letra
    if((letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122)){
    push(letra);                        //e entao a empilho
    }
}
while(topo != NULL){                  // e entao a desempilho até nao ter ninguem na pilha
    pop();

}

}
char push(char x){

struct pilha *aux;
aux = new(struct pilha);
aux->letra = x;
aux->next = topo;
topo = aux;
}

char pop(){
struct pilha *aux;
if(topo == NULL){
    printf("Pilha vazia");
}
else{
printf("%c",topo->letra);
aux = topo;
topo = topo->next;
delete(aux);
}
}

