#include <iostream>
#include <clocale>
#include <cstdlib>
using namespace std;
const int TAM = 1000;

struct no {
    int destino;
    struct no *prox;
};

struct no *arestas[TAM];
int vertices[TAM];
int contadorVertices = 0;

void insereVertice(int valor) {
    if (contadorVertices == TAM-1) {
        cout << "Não há espaço no vetor" << endl;
        return;
    }

    vertices[contadorVertices] = valor;
    contadorVertices++;
}

void insereAresta(int origem, int destino) {
    // Encontrar a posição da origem e do destino...
    int cont;
    int i = -1;
    int j = -1;
    for (cont=0; cont<contadorVertices; cont++) {
        if (vertices[cont] == origem) {
            i = cont;
            break;
        }
    }
    for (cont=0; cont<contadorVertices; cont++) {
        if (vertices[cont] == destino) {
            j = cont;
            break;
        }
    }
    if (i == -1 || j == -1) {
        cout << "Não existe algum dos vértices" << endl;
        return;
    }

    struct no *atual, *anterior, *aux;
    atual = arestas[i]; // i=1

    // CHECA PRA VER SE TEM REPETIDA E PEGA A ULTIMA ARESTA COLOCADA
    while (atual != NULL) {
        if (destino == atual->destino) {
            cout << "Aresta repetida" << endl;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }


    aux = new(struct no);
    aux-> destino = destino;
    aux->prox = NULL;


    if (arestas[i] == NULL)
        arestas[i] = aux; // SE O PONTEIRO NESSA POSICAO TIVER NULL PASSA A APONTAR PRA ARESTA ADICIONADA
    else anterior->prox = aux; // COLOCA MAIS UMA ARESTA NO FINAL DA ULTIMA ARESTA ADICIONADA

}

void removeAresta(int origem, int destino) {
    // Encontrar a posição da origem e do destino...
    int cont;
    int i = -1;
    int j = -1;
    for (cont=0; cont<contadorVertices; cont++) {
        if (vertices[cont] == origem) {
            i = cont;
            break;
        }
    }
    for (cont=0; cont<contadorVertices; cont++) {
        if (vertices[cont] == destino) {
            j = cont;
            break;
        }
    }
    if (i == -1 || j == -1) {
        cout << "Não existe algum dos vértices" << endl;
        return;
    }

    struct no *atual, *anterior = NULL;
    atual = arestas[i];
    while (atual != NULL) {
        if (destino == atual->destino) {
            if (anterior == NULL)
                arestas[i] = atual->prox;
            else
                anterior->prox = atual->prox;
            delete(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    cout << "Não existe a aresta" << endl;
}

void haAresta(int origem, int destino) {
    // Encontrar a posição da origem e do destino...
    int cont;
    int i = -1;
    int j = -1;
    for (cont=0; cont<contadorVertices; cont++) {
        if (vertices[cont] == origem) {
            i = cont;
            break;
        }
    }
    for (cont=0; cont<contadorVertices; cont++) {
        if (vertices[cont] == destino) {
            j = cont;
            break;
        }
    }
    if (i == -1 || j == -1) {
        cout << "Não existe algum dos vértices" << endl;
        return;
    }

    struct no *atual, *anterior;
    atual = arestas[i];
    while (atual != NULL) {
        if (destino == atual->destino) {
            cout << "Existe a aresta" << endl;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    cout << "Não existe a aresta" << endl;

}

void imprimeGrafo() {
    for (int i=0; i<contadorVertices; i++) {
        cout << vertices[i] << " -> ";

        struct no *atual, *anterior;
        atual = arestas[i];
        while (atual != NULL) {
            cout << "<" << vertices[i] << "," << atual->destino << "> ";
            anterior = atual;
            atual = atual->prox;
        }

        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    system("color 3a");
    int option;
    int valor1, valor2; //a ser inserido
    bool continuar = 1;

    while (continuar) {

        cout << endl << endl << "Selecione uma opção:" << endl;
        cout << "1- Inserir vértice" << endl;
        cout << "2- Inserir aresta" << endl;
        cout << "3- Remover aresta" << endl;
        cout << "4- Verificar se há aresta" << endl;
        cout << "5- Imprimir grafo" << endl;
        cout << "0- Sair" << endl;

        cin >> option;

        switch(option) {
            case 1:
                cout << "Qual o vértice a ser inserido? ";
                cin >> valor1;
                insereVertice(valor1);
                system("Pause");
                system("cls");
                break;
            case 2:
                cout << "Quais os vértices da aresta? ";
                cin >> valor1 >> valor2;
                insereAresta(valor1, valor2);
                system("Pause");
                system("cls");
                break;
            case 3:
                cout << "Quais os vértices da aresta a ser removida? ";
                cin >> valor1 >> valor2;
                removeAresta(valor1, valor2);
                system("Pause");
                system("cls");
                break;
            case 4:
                cout << "Quais os vértices da aresta? ";
                cin >> valor1 >> valor2;
                haAresta(valor1, valor2);
                system("Pause");
                system("cls");
                break;
            case 5:
                imprimeGrafo();
                system("Pause");
                system("cls");
                break;
            case 0:
                system("cls");
                continuar = 0;
                cout << endl << "Obrigado por usar este programa." << endl << endl;
                system("Pause");
                break;

            }

    }

}
