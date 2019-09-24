#include<stdio.h>
#include<string.h>
#define STACKSIZE 100

void push(int valor);
int vazia();
void pop();
int topopilha();
void imprime();
int menu();

struct pilha
{
    int cadeia[STACKSIZE];
    int top;

};
pilha p1;

int main()
{
push(4);
push(20);
push(3);
push(6);
push(7);
topopilha();

}



void push(int n)
{
    p1.cadeia[p1.top] = n;
    p1.top++;
}
int vazia()
{
    if(p1.top<0)
    {
        return 0;
    }
    else
        return 1;
}
void pop()
{
    p1.top--;
}
int topopilha()
{
    printf("%d",p1.cadeia[p1.top-1]);
}
void imprime()
{

}


/*
char push(char var[],int i);
int pop();

struct pilha{
int top;
char cadeia[STACKSIZE];
};
pilha p1;


int main(){

int i = 0;
char aux[STACKSIZE];

gets(aux);



for(i = 0; i<strlen(aux); i++){

    if(aux[i] == '(' ){
        push(aux,i);
       }
    else if(aux[i] == ')' && p1.cadeia[p1.top-1] == '('){
        pop();
    }
    if(p1.top < 0){
        i = 10;
    }
}
if(!p1.top){
    printf("A cadeia esta fechada corretamente");
}
else
    printf("A cadeia esta incorreta");
}

char push(char var[],int i){

p1.cadeia[p1.top] = var[i];
p1.top++;
}

int pop(){
p1.top--;
}
*/
