#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100000

using namespace std;
int vetor[TAM];
int tam_heap;
int scratch[TAM];

void buildheap();
void heapsort();
void heapify();
void selectionsort();
void bubblesort();
void quicksort();
void insertionsort();


void gera()
{
    int i;
    for (i=0; i<TAM; i++)
    {
        vetor[i] = rand();
    }
}

void bubblesort()
{
    int pass = 1, aux,i;
    bool sorted = false;
    while (sorted == false && pass < TAM)
    {
        sorted = true;
        for (i=0; i<=TAM-pass-1; i++)
        {
            if (vetor[i] > vetor [i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                sorted = false;
            }
        }
        pass = pass +1;
    }
}

int partitio (int p,int r){
    int pivo, i, j, aux;
    pivo = vetor[p];
    i = p -1;
    j = r +1;
    while(true){
        do{
            j = j - 1;
        }while(vetor[j] > pivo);
        do{
            i = i + 1;
        }while (vetor[i]<pivo);
        if (i<j){
            aux = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = aux;
        }else{
            return j;
        }
    }
}

void quicksort(int p, int r){
    int q;
    if(p < r){
        q = partitio(p,r);
        quicksort (p,q);
        quicksort (q+1,r);
    }
}

void selectionsort()
{
    int i,j,aux,aux2;
    for (i=0; i<TAM-2; i++){
        aux = i;
        for (j=i+1; j<TAM-1; j++){
            if (vetor[aux]>vetor[j])
            {
                aux = j;
            }
        }
        aux2 = vetor[i];
        vetor[i] = vetor[aux];
        vetor[aux] = aux2;
    }
}

void heapify(int i){
    int l,r,maximo,aux;
    l = 2*i+1;
    r = 2*i+2;
    if ((l<tam_heap) && (vetor[l] > vetor[i])){
        maximo = l;
    }else{
        maximo = i;
    }
    if ((r<tam_heap) && (vetor[r]>vetor[maximo])){
        maximo = r;
    }
    if (maximo!=i){
        aux = vetor[i];
        vetor[i] = vetor[maximo];
        vetor[maximo] = aux;
        heapify(maximo);
    }
}

void heapsort(){
    int j,aux;
    buildheap();
    for (j=TAM-1; j>0; j--){
        aux = vetor[0];
        vetor[0] = vetor[j];
        vetor[j] = aux;
        tam_heap = tam_heap -1;
        heapify(0);
    }
}

void buildheap(){
    int i;
    tam_heap = TAM;
    for(i=(TAM / 2)-1; i>=0; i--){
        heapify(i);
    }
}
void insertionsort(){
    int k,i,x,aux = 0 ;
    bool found;
    for (k=1;k<TAM-1;k++){
        x = vetor[k];
        i = k - 1;
        found = false;
        while (!found && i >= 0){
            if (vetor[i] > x){
                aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
                i = i - 1;
            }else{
                found = true;
            }
        }
    }
}

void mergesort(int lo, int hi){
    int mid, l, h, k;
    if (lo < hi){
        mid = (lo+hi)/2;
        mergesort(lo,mid);
        mergesort(mid+1,hi);
        l = lo;
        h = mid +1;
        for (k = lo; k < hi; k++){
            if (l<=mid && (h > hi || vetor[l]<vetor[h])){
                scratch[k] = vetor[l];
                l = l+1;
            }else{
                scratch[k]  = vetor[h];
                h = h+1;
            }
        }
        for (k=lo;k<hi;k++){
            vetor[k] = scratch[k];
        }
    }

}

int main(){
    gera();
    clock_t tempo1,tempo2;
    tempo1 = clock();
    bubblesort();
    tempo2 = clock() - tempo1;
    printf("BUBBLE SORT: %f\n", (float) tempo2/CLOCKS_PER_SEC);

    gera();
    tempo1 = clock();
    quicksort(0,TAM-1);
    tempo2 = clock() - tempo1;
    printf("QUICK SORT: %f\n", (float) tempo2/CLOCKS_PER_SEC);

    gera();
    tempo1 = clock();
    selectionsort();
    tempo2 = clock() - tempo1;
    printf("SELECTION SORT: %f\n", (float) tempo2/CLOCKS_PER_SEC);

    gera();
    tempo1 = clock();
    heapsort();
    tempo2 = clock() - tempo1;
    printf("HEAP SORT: %f\n", (float) tempo2/CLOCKS_PER_SEC);

    gera();
    tempo1 = clock();
    insertionsort();
    tempo2 = clock() - tempo1;
    printf("%INSERTION SORT: %f\n", (float) tempo2/CLOCKS_PER_SEC);

    gera();
    tempo1 = clock();
    mergesort(0,TAM-1);
    tempo2 = clock() - tempo1;
    printf("MERGE SORT: %f\n", (float) tempo2/CLOCKS_PER_SEC);
    return 0;
}





