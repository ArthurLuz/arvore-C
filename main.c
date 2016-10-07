#include <stdio.h>
#include <stdlib.h>

    typedef struct no{
        int info;
        struct no *esq;
        struct no*dir;

    }tno;

    void insere(tno**t, int x){
    tno*no;
    no = (tno*)(malloc(sizeof(tno)));
    no->info=x;
    no->esq=NULL;
    no->dir=NULL;
    tno* aux,*ant;
    if(*t ==NULL){
        *t = no;
    }else{
        aux= *t;


    while(aux!=NULL){
        ant=aux;
        if (x<aux->info)
            aux=aux->esq;
        else
            aux = aux->dir;
    }
    if (x<ant->info)
        ant->esq=no;
    else
        ant->dir=no;
    }
}
    // metodo busca
    int busca(tno*t,int x){
        while(t!=NULL){
            if (x==t->info)
                return 1;
            else if(t->info <x)
                t = t->dir;
                else t = t->esq;
        }
    return -1;
    }

    //busca recursiva
    int buscaR (tno*t,int k) {
    if ( t->info == k){
        //printf( "achou aki: %d",t->info);
        return k;
      }else{
        if(k > t->info){
            if(t->dir != NULL)
              buscaR(t->dir,k);
            else
              return -1;
          }else{
            if(t->esq != NULL)
                buscaR(t->esq,k);
            else
                return -1;
          }
      }return 0;
    }
    void imprimelvl(tno*t,int nivel){
        if(t==NULL)
            return;
        printf("%d nivel: %d",t->info,nivel);
        imprimelvl(t->esq,nivel+1);
        imprimelvl(t->dir,nivel+1);
    }
    void Ordem (tno*t) {
        tno *no;
        no=t;
      if(no->esq != NULL)
        Ordem(no->esq);
            printf("%d\n",no->info);
      if(no->dir != NULL)
        Ordem(no->dir);
    }

    void PreOrdem (tno*t) {
        //tno *no;
      printf("%d\n",t->info);
      if(t->esq != NULL)
        PreOrdem(t->esq);

      if(t->dir != NULL)
      PreOrdem(t->dir);
    }

    void PosOrdem (tno*t) {
        //tno *no;
      if(t->esq != NULL)
        PosOrdem(t->esq);

      if(t->dir != NULL)
      PosOrdem(t->dir);

     printf("%d\n",t->info);
    }

    tno *maior(tno**t){
        if((*t)->dir!=NULL)
            return maior(&(*t)->dir);
        else{
            tno*aux=*t;
            if((*t)->esq==NULL){
                *t=NULL;
                return aux;
            }else{
                *t=(*t)->esq;
                return aux;
            }
        }
    }
void remover(tno**t,int x){
        //============== Metodo Apaga folha =================
    if(*t!=NULL) {
            tno*aux;
            if(x<(*t)->info)
                remover(&((*t)->esq),x);
            else if(x>(*t)->info)
                remover(&((*t)->dir),x);
            else{

                aux=*t;
                if(aux->esq==NULL&&aux->dir==NULL){
                    *t = NULL;
                    free (aux);
                }else if (aux->esq==NULL || aux->dir == NULL){
                    if(aux->esq==NULL)
                        *t=aux->dir;
                    else
                        *t= aux->esq;
                    free(aux);

                }else {
                    aux=maior(&((*t))->esq);
                    aux->esq=(*t)->esq;
                    aux->dir =(*t)->dir;
                    free((*t));
                    *t=aux;
            }
        }
    }
}
int main(){
    tno*t = NULL;

    insere(&t,5);
    insere(&t,3);
    insere(&t,10);
    insere(&t,7);
    insere(&t,15);
    insere(&t,9);
    insere(&t,8);
    PreOrdem(t);
    printf("\n");
    //int x =buscaR(t,9);
    //if(x!=-1)printf("achou :%d",x);
    //else printf("nao achou");
    remover(&t,10);
    PreOrdem(t);

    return 0;
}
