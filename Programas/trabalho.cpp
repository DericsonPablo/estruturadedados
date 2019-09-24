#include <iostream>
#include <time.h>
#define TAM 5

using namespace std;

struct no {
            int dado;
            struct no *esq;
            struct no *dir;
            int bal;
			};

int vetor[TAM];

void GeraVetor(){
    for (int i = 0; i < TAM; i++){
        vetor[i] = rand() % 20;
    }

}

// --------------------------- ORDENACAO--------------------------
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


//Insere valor em uma árvore binária

void insere(int valor)
{

   struct no *atual, *aux;

   aux = new(struct no);
   aux->dado = valor;
   aux->esq = NULL;
   aux->dir = NULL;

   atual=raiz;

   if (atual==NULL) {
   	  raiz = aux;
   	  return;
   }

   while (1) {
         	if (valor < atual->dado)
            	if (atual->esq==NULL) {
            	    atual->esq=aux;
            	    return;
                 }
                 else atual=atual->esq;
            else if (atual->dir==NULL) {
            	    atual->dir=aux;
            	    return;
                 }
                 else atual=atual->dir;
         }
}

//Insere valor em uma árvore AVL
void insere_bal(int chave)
{

	struct no *pp=NULL, *p=raiz_avl, *pajovem=NULL, *ajovem=raiz_avl, *q, *filho;
   int imbal;

   if (p==NULL) {             /* Arvore vazia */
   	  raiz_avl = cria_no(chave);  /* Funcao para criacao de um novo no */
      return;
   }

/* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
   while (p!=NULL) {
   	if (chave < p->dado)
      	q = p->esq;
         else q = p->dir;
      if (q!=NULL)
      	if (q->bal != 0) {
         	pajovem=p;
            ajovem=q;
      }
      pp = p;
      p = q;
   }

   q = cria_no(chave);

   if (chave<pp->dado)
   	pp->esq=q;
      else pp->dir=q;

/* Balanceamento de todos os nós entre ajovem e q devem ser ajustados */
   if (chave<ajovem->dado)
   	filho = ajovem->esq;
      else filho = ajovem->dir;

   p = filho;

   while (p!=q) {
   	if (chave < p->dado) {
      	p->bal=1;
         p=p->esq;
   	} else {
   			p->bal = -1;
            p=p->dir;
   			}
   }

   if (chave<ajovem->dado)
   	imbal = 1;
      else imbal = -1;

   if (ajovem->bal==0) {      /*Não houve desbalanceamento */
   	ajovem->bal=imbal;
      return;
   }


	if (ajovem->bal!=imbal) {   /*Não houve desbalanceamento */
   	ajovem->bal=0;
      return;
   }

	/* Houve desbalanceamento */
   if (filho->bal == imbal) {
   	p=filho;
      if (imbal==1)        /* Faz rotação simples */
      	direita(ajovem);
      	else esquerda(ajovem);
      ajovem->bal=0;
      filho->bal=0;
   } else {
   		if (imbal==1) {	  /*Faz rotação dupla */
      		p=filho->dir;
         	esquerda(filho);
         	ajovem->esq=p;
         	direita(ajovem);
      	} else {
              p=filho->esq;
              direita(filho);
              ajovem->dir=p;
              esquerda(ajovem);
         }
         if (p->bal==0) {
         	ajovem->bal=0;
            filho->bal=0;
         } else {
         		if (p->bal == imbal) {
               	ajovem->bal = - imbal;
                  filho->bal = 0;
               } else {
               	ajovem->bal = 0;
                  filho->bal = imbal;
               }
         }
      p->bal=0;
   }

   if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
      raiz_avl = p;
      else if (ajovem==pajovem->dir)
      			 pajovem->dir = p;
                else pajovem->esq = p;

   return;
}



// FAZER A FUNCAO RAND E COLOCAR PRA PROCURAR // ELA USAR FOR PRA FAZER 1000 VEZES CADA BUSCA // ARMAZENAR NUMA VARIAVEL A QUANTIDADE DE
//COMPARACOES SOMANDO ELA MESMA E NO FINAL DIVIDIR POR 1000

int main(){

    srand(time(NULL));
    return 0;
}
