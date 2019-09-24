#include <stdio.h>
#define TAM 10
#include <locale.h>

int vertice[TAM];
int adj[TAM][TAM];
int contV = 0;

void preencher(){
    for (int i = 0;i<TAM;i++){
        vertice[i] = 0;
    }
    for(int i = 0;i<TAM;i++){
        for(int j = 0;j<TAM;j++){
            adj[i][j] = 0;
        }
    }
}

void insereVertice(int valor){
    if(contV == TAM){
        printf("grafo cheio\n");
        return;
    }else{
        vertice[contV] = valor;
        printf("valor inserido com sucesso\n");
        contV++;
    }
}

void insereAresta(){
    int origem,destino;
    int a = -1,b = -1;
    if(!contV){
        printf("grafo vazio\n");
        return;
    }else{
        printf("\t\t*INSERINDO ARESTA*\n");
        printf("Digite a origem: ");
        scanf("%d", &origem);
        printf("Digite o destino: ");
        scanf("%d", &destino);
        for(int i = 0; i<=contV; i++){
            if(origem == vertice[i]){
                a = i;
            }
            if(destino == vertice[i]){
                b = i;
            }
        }
    }
    if (a == -1 || b == -1){
        printf("Vertice inexistente\n");
        return;
    }else{
        adj[a][b] = 1;
        printf("Aresta inserida\n");
    }
}

void removeAresta(){
    int origem,destino;
    int a = -1,b = -1;
    if(!contV){
        printf("grafo vazio\n");
        return;
    }else{
        printf("\t\t*REMOVENDO ARESTA*\n");
        printf("Digite a origem: ");
        scanf("%d", &origem);
        printf("Digite o destino: ");
        scanf("%d", &destino);
        for(int i = 0; i<=contV; i++){
            if(origem == vertice[i]){
                a = i;
            }
            if(destino == vertice[i]){
                b = i;
            }
        }
    }
    if (a == -1 || b == -1){
        printf("Vertice inexistente\n");
        return;
    }else{
        adj[a][b] = 0;
    }
}

void haAresta(){
    int origem,destino;
    int a = -1,b = -1;
    if(!contV){
        printf("grafo vazio\n");
        return;
    }else{
        printf("\t\t*VERIFICAÇÃO DE EXISTENCIA DE ARESTA*\n");
        printf("Digite a origem: ");
        scanf("%d", &origem);
        printf("Digite o destino: ");
        scanf("%d", &destino);
        for(int i = 0; i<=contV; i++){
            if(origem == vertice[i]){
                a = i;
            }
            if(destino == vertice[i]){
                b = i;
            }
        }
    }
    if (a == -1 || b == -1){
        printf("Aresta inexistente\n");
        return;
    }else if(adj[a][b] == 1){
        printf("Existe uma aresta entre esses dois pontos\n");
    }
}

void imprimeGrafo(){
    for(int i = 0; i<contV; i++){
        printf("%d ->", vertice[i]);
        for(int j = 0; j<contV; j++){
            if(adj[i][j] > 0){
                printf(" <%d,%d>", vertice[i], vertice[j]);
            }
        }
        printf("\n");
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");

    preencher();
    insereVertice(2);
    insereVertice(4);
    insereVertice(7);
    insereVertice(3);
    insereAresta();
    haAresta();
    imprimeGrafo();
    printf("\n");
    insereAresta();
    insereAresta();
    printf("\n");
    imprimeGrafo();


return 0;
}

