#include <iostream>
#include <clocale>

using namespace std;

const int TAM = 5;

struct no
{
    int dado;
    struct no * prox;
};

struct no * inicio;
struct no * fim;

bool vazia()
{
    if(inicio==NULL)
        return true;
    return false;
}

void insereFila(int valor)
{
    struct no * aux;
    aux=new(struct no);
    aux->dado=valor;
    aux->prox=NULL;
    if(vazia())
        inicio=aux;
    else
        fim->prox=aux;
    fim=aux;
}

void removeFila()
{
    struct no *aux;
    if(vazia())
    {
        cout << "Fila vazia";
    }
    aux=inicio;
    inicio=inicio->prox;
    if(inicio==NULL)
        fim=NULL;
    delete(aux);
}

int inicioFila()
{
    if(!vazia)
        return inicio->dado;
    return -1;
}

void imprime()
{
    struct no * aux=inicio;
    if(aux!=NULL)
    {
        while(aux!=NULL)
        {
            cout << aux->dado << endl;
            aux=aux->prox;
        }
        return;
    }
    else
        cout << "Fila vazia" << endl;
}
