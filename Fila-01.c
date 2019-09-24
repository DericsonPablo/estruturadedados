#include<stdio.h>
#include<windows.h>
#define TAM 5
struct fila
{
    int vet[TAM],inicio,fim;
};
struct fila f1;

void insere_fila(int val);
void tira_fila();
void print_inicio();
void print_tudo();
int cont = 0,aux_cont;
int aux_inicio;
int main()
{

    int resp,val,ret = 1;
    while(ret)
    {
        printf("\n1)Inserir na fila");
        printf("\n2)Tirar da fila");
        printf("\n3)Imprimir topo fila");
        printf("\n4)Mostrar tudo");
        printf("\nResposta: ");
        scanf("%d", &resp);
        system("cls");

        switch(resp)
        {

        case 1:
            printf("\nDigite o valor: ");
            scanf("%d", &val);
            insere_fila(val);
            break;
        case 2:
            tira_fila();
            break;
        case 3:
            print_inicio();
            break;
        case 4:
            print_tudo();
            break;
        default:
            printf("Isto n�o existe");
            break;
        }
        printf("\nDenovo?: ");
        scanf("%d", &ret);
        system("cls");
    }
}
void insere_fila(int val)
{

    if(f1.fim == TAM-1 && cont < TAM)       //se estiver na ultima posi��o e ainda houver posi��es dispon�veis
    {
        f1.vet[f1.fim]= val;                //coloco esse valor na ultima posi��o do vetor
        f1.fim = 0;                         //o fim volta para o come�o
        cont++;                             //e h� um dado a mais na fila
    }
    else if(cont == TAM)                    //se a quantia de elementos for igual a quantia disponivel
    {
        printf("\nFILA CHEIA");
    }
    else
    {                                       //se o fim nao estiver na ultima posi��o e houver posi��es disponiveis
        f1.vet[f1.fim] = val;               //coloco esse dado no fim da fila
        f1.fim++;                           //e o fim esta na ultima posi��o
        cont++;                             //um valor a mais que foi posto na fila
    }
}

void tira_fila()
{

    if(f1.inicio == TAM-1)          //se o inicio estiver na ultima posi��o disponivel
    {
        f1.inicio = 0;              //o inicio volta a primeira posi��o
        cont--;                     //h� um valor a menos no vetor
    }
    else if(!cont)                  //se o numero de elementos = 0
    {
        printf("\nFila vazia");
    }
    else                            //se o inicio nao estiver na ultima posi��o e houver posi��es dispon�veis
    {
        f1.inicio++;                //inicio vai para a frente
        cont--;                     //como foi tirado uma posi��o h� uma posi��o a mais disponivel
    }
}
void print_inicio()
{
    if(!cont)
    {
        printf("\nFila vazia");
    }
    else
        printf("\nPrimeiro na fila = %d",f1.vet[f1.inicio]);
}

void print_tudo()
{
    aux_cont = cont;                                            //variavel auxiliar para o contador de espa�oes disponiveis
    aux_inicio = f1.inicio;                                     //variavel auxiliara para a primeira posi��o da fila

    if(!cont)                                                 //se nao h� valores
    {
        printf("\nFila vazia");
    }
    else                                                     //sen�o
    {
        while(aux_cont)                                      //enquanto houver valores
        {
            if(aux_inicio < TAM-1)                          //se o inicio � menor que a ultima posi��o da fila
            {
                printf("%d ",f1.vet[aux_inicio]);           //o mostro
                aux_inicio++;                               //e entao o inicio vai para a frente
                aux_cont--;                                 //como um dado ja foi mostrado h� um a menos
            }
           else if(aux_inicio == TAM-1 && f1.fim != TAM-1)  //se o inicio estiver na ultima posi��o do vetor e o fim nao o estiver
            {
                printf("%d ", f1.vet[aux_inicio]);          //mostro esse valor
                aux_inicio = 0;                             //e o inicio volta para a primeira posi��o
                aux_cont--;                                 //como um valor ja foi mostrado h� um a menos
            }
        }

    }
}
