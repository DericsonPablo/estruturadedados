#include <iostream>
#include <clocale>
#include <cstdlib>

#include "Fila.cpp"
#define TAM 10

using namespace std;

int vertices[TAM];
int adj[TAM][TAM]; //matriz de adjacencia
int contadorVertices = 0;

void zeros() {
    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            adj[i][j] = 0;
        }
    }
}

void insereVertice(int valor) {
    if (contadorVertices == TAM-1) {
        cout << "Não há espaço no vetor" << endl;
        return;
    }

    vertices[contadorVertices] = valor;
    contadorVertices++;
}

void insereAresta(int origem, int destino) {
    int posOrig = -1;
    int posDest = -1;
    int atual = 0;

    for (int i=0; i<contadorVertices; i++) {
        if (vertices[i] == origem) {
            posOrig = i;
        }
        if (vertices[i] == destino) {
            posDest = i;
        }
    }
    if (posOrig == -1 || posDest == -1) {
        cout << "Um ou mais vértices não existem" << endl;
        return;
    }

    adj[posOrig][posDest]++;
}

void removeAresta(int origem, int destino) {
    int posOrig = -1;
    int posDest = -1;
    int atual = 0;

    for (int i=0; i<contadorVertices; i++) {
        if (vertices[i] == origem) {
            posOrig = i;
        }
        if (vertices[i] == destino) {
            posDest = i;
        }
    }
    if (posOrig == -1 || posDest == -1) {
        cout << "Um ou mais vértices não existem" << endl;
        return;
    }

    if (adj[posOrig][posDest] == 0) {
        cout << "Não há aresta" << endl;
    }
    else
        adj[posOrig][posDest]--;
}

void haAresta(int origem, int destino) {

    int posOrig = -1;
    int posDest = -1;
    int atual = 0;

    for (int i=0; i<contadorVertices; i++) {
        if (vertices[i] == origem) {
            posOrig = i;
        }
        if (vertices[i] == destino) {
            posDest = i;
        }
    }
    if (posOrig == -1 || posDest == -1) {
        cout << "Um ou mais vértices não existem" << endl;
        return;
    }

    if (adj[posOrig][posDest] == 0) {
        cout << "Não há aresta" << endl;
    }
    else
        cout << "Há uma aresta" << endl;

}

void imprimeGrafo() {
    for (int i=0; i<contadorVertices; i++) {
        cout << vertices[i] << " -> ";

        for (int j=0; j<contadorVertices; j++) {
            if (adj[i][j] > 0) {
                cout << "<" << vertices[i] << "," << vertices[j] << "> ";
            }
        }

        cout << endl;
    }
}

// vetor variável global para usar em ambas as buscas
int visita[TAM];

// Breadth First Search
void bfs(int inicial) {
    int v, a;
    for (int v=0; v<contadorVertices; v++) {
        visita[v] = 0;
    }
    visita[inicial] = 1;
    cout << vertices[inicial] << " ";
    insereFila(inicial);
    while (!estaVazia()) {
        v = removeFila();
        for (a=0; a<contadorVertices; a++) {
            if (adj[v][a] == 1 && visita[a] == 0) {
                cout << vertices[a] << " ";
                visita[a] = 1;
                insereFila(a);
            }
        }
    }
    cout << endl;
} // caso haja um vértice não alcançável pelo inicial, colocaria o BFS dentro de um for;
  // enquanto existissem vértices não percorridos, ele recomeçaria a partir desse vértice


// Depth First Search
void dfs_r(int vert);
void dfs(int inicial) {
    int v;
    for (int v=0; v<contadorVertices; v++) {
        visita[v] = 0;
    }
    dfs_r(inicial);
    cout << endl;
}
void dfs_r(int vert) { // recursiva, uma para cada vértice
    int v;
    visita[vert] = 1;
    cout << vertices[vert] << " ";
    for(v=0; v<contadorVertices; v++) { // linha do vert
        if (adj[vert][v] == 1 && visita[v] == 0) {
            dfs_r(v);
        }
    }
}


void grafoPadrao() {
    insereVertice(0);
    insereVertice(10);
    insereVertice(20);
    insereVertice(30);
    insereVertice(40);
    insereVertice(50);
    insereAresta(0, 10);
    insereAresta(0, 20);
    insereAresta(10, 40);
    insereAresta(20, 30);
    insereAresta(20, 50);
    insereAresta(30, 50);
}

// Main
int main() {
    zeros();

    setlocale(LC_ALL, "");
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
        cout << "6- Percorrer em largura" << endl;
        cout << "7- Percorrer em profundidade" << endl;
        cout << "8- Grafo padrão" << endl;
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
            case 6:
                bfs(0);
                system("Pause");
                system("cls");
                break;
            case 7:
                dfs(0);
                system("Pause");
                system("cls");
                break;
            case 8:
                grafoPadrao();
                system("cls");
                break;
            case 0:
                system("cls");
                continuar = 0;
                cout << endl << "Obrigado por usar este programa." << endl << endl;
                break;

            }

    }

}
