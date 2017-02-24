#include <stdio.h>
#include <stdlib.h>

    struct no{
        int info;
        struct no *esq;
        struct no*dir;
        int fb;
    };
    typedef struct no tno;
//-----------------------------------------------------
void insereR(tno** t, int info){// insere os elementos de forma recursiva

  if(*t == NULL)  {
    *t = (tno*)malloc(sizeof(tno));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->info = info;
  } else {
    if(info < (*t)->info) // Se o número for menor então vai pra esquerda
      insereR(&(*t)->esq, info);
    if(info > (*t)->info) // Se o número for maior então vai pra direita
      insereR(&(*t)->dir, info);
  }
}
//---------------------------------------------------------------------
    void insere(tno**t, int x){
      tno *no,* aux,*ant;
        if(*t ==NULL){
            no = (tno*)(malloc(sizeof(tno)));
            no->info=x;
            no->esq=NULL;
            no->dir=NULL;
            *t = no;
                printf("asfasfafsdafafa" );
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
        //printf("%d nivel: %d",t->info,nivel);
        t->fb=t->dir->fb - t->esq->fb;
        printf("%d\n",t->fb );
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
    //=================ROTAÇÃO DIREITA=======================
    void RD(tno **p){
      tno *u;
      u=(*p)->esq;
      (*p)->esq=u->dir;
      u->dir=(*p);
      (*p)->fb=0;
      //imprimelvl((*p),0);
      (*p)=u;
    }

    //==================ROTAÇÃO ESQUERDA===================
    void RE(tno **p){
      tno *u;
      u=(*p)->dir;
      (*p)->dir=u->esq;
      u->esq=(*p);
      (*p)->fb=0;
      (*p)=u;
    }
    //===============ROTAÇÃO DUPLADIREITA===================
    /*
    void RDD(tno**p){
      tno *u,*v;
      u=(*p)->esq;
      v=u->dir;
      (*p)->esq= v->dir;
      u->dir=v->esq;
      v->esq=u;
      v->dir=*p;
      (*p)->fb=(v->fb==-1)?1=0;
      u->fb=(v->fb==1)?-1:0;
    }
    //====================== ROTAÇÃO DUPLAESQUERDA=================
    void RDE(tno**p){
      tno *u,*v;
      u=(*p)->dir;
      v=u->esq;
      (*p)->dir= v->esq;
      u->esq=v->dir;
      v->dir=u;
      v->esq=*p;
    }
*/
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
int contanos (tno*t){
  return((t==NULL)?0 : 1+contanos(t->esq)+contanos(t->dir));
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
  insereR(&t,5);
   insereR(&t,3);
   insereR(&t,10);
   insereR(&t,7);
   insereR(&t,15);
   insereR(&t,9);
   insereR(&t,8);
    int con=0;
    Ordem(t);
    printf("\n");
    //int x =buscaR(t,9);
    //if(x!=-1)printf("achou :%d",x);
    //else printf("nao achou");
    //remover(&t,10);
    //con=  contanos(t);

    printf("\n");
      printf("\n");
}
