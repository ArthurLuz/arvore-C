#ifndef H_ABB_H
#define H_ABB_H
#include <stdio.h>
#include <stdlib.h>
struct no{
    int info;
    struct no *esq;
    struct no*dir;
    int fb;
};
typedef struct no tno;

void inicializar(tno **t);

void insereR(tno** t, int info);
int busca(tno*t,int x);
int buscaR(tno*t,int x);

void Ordem (tno*t) ;
void PreOrdem (tno*t) ;
void PosOrdem (tno*t) ;





#endif
