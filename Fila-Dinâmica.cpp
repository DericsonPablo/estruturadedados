#include<stdio.h>
#include<windows.h>

struct no{

int valor;
struct no *prox;

};

struct no *inicio = NULL;
struct no *fim = NULL;

void retiraFila();
void insereFila(int n);
void mostraInicio();
void mostraFila();


int main(){
int choose,loop;
do{
printf("***************Opcoes***************\n");
printf("1)Inserir\n");
printf("2)Retirar\n");
printf("3)MostraInicio\n");
printf("4)Mostrar tudo\n");
printf("Resposta: ");
scanf("%d",&choose);
    switch(choose){
case 1:
    printf("\nQual numero sera inserido?: ");
    scanf("%d", &choose);
    insereFila(choose);
    break;
case 2:
    retiraFila();
    break;
case 3:
    mostraInicio();
    break;
case 4:
    mostraFila();
    break;
default:
    printf("Opção indisponível");
    break;
    }
    printf("\nRepetir?: ");
    scanf("%d",&loop);
    system("cls");
}while(loop);
}


void retiraFila(){
if(inicio == NULL){         //se a fila apontar para null, i.e se a fila nao possui elementos
    printf("Fila Vazia\n");
}
else{               //senão
    struct no *aux;         //crio um ponteiro para tipo struct
    aux = inicio;           //faço ele appontar para a mesma posição que o inicio aponta
    inicio = inicio->prox;      //e entao o inicio aponta para a mesma posição que o ponteiro da estrutura aponta, i.e para a estrutura anterior
    delete(aux);            //e entao libero esse endereço
}
}

void insereFila(int n){
struct no *aux;             //ponteiro para estrutura
aux = new(struct no);       //reservo um espaço para essa estrutura
aux->prox = NULL;           //como esse elemento foi o ultimo a ser inserido, entao depois dele não há ninguem, faço o ponteiro apontar para null
aux->valor = n;             //e o elemento recebe n
if(inicio == NULL){         //se o inicio == null,i.e se nenhum elemento ainda foi inserido na fila
    inicio = aux;           //o inicio aponta para o primeiro elemento
    fim = aux;              //e o fim tambem
}
else{                       //se a fila nao estiver vazia
fim->prox = aux;            //o ponteiro prox aponta para esse elemento que foi colocado por ultimo
fim = aux;                  //e o fim tambem
}
system("cls");
}


void mostraInicio(){
if(inicio == NULL){
    printf("Fila vazia");
}
else
printf("\n%d", inicio->valor);

}

void mostraFila(){
struct no *aux;

aux = inicio;
if(aux == NULL){
    printf("Fila Vazia");
}
else{
while(aux != NULL){
    printf("%d ", aux->valor);
    aux = aux->prox;
}
}
}
