#include <isotream>
#define ORDEM 5

using namespace std;

struct no {
    int dados[ORDEM-1];
    struct no *filhos[ORDEM];
    int n_chaves;
};

struct no *raiz = NULL;
struct no *raizB = NULL;

int insere(int chave){
    struct no *novo, *atual;
    int posicao;

    if(raiz == NULL){
        raiz  = cria_no(chave);
        return 1;
    }
    atual = encontra_no(chave, posicao);
    if(atual->dado[posicao] == chave)
        return 0;
    if(atual->n_chaves < ORDEM-1){
        insere_folha(atual,chave);
        return 1;
    }

    novo = cria_no(chave);
    atual->filhos[posicao] = novo;
    return 1;

}

struct no *cria_no(int chave){

    struct no *novo;
    int i;

    novo = new(struct no);
    novo ->dados[0] = chave;

    for(i = 0; i < ORDEM; i++)
        novo ->filhos[i] = NULL;

    novo->n_chaves = 1;
    return novo;

};

main(){


}
