#include "abb.h"
int main(int argc, char const *argv[]){
  tno*t;
  inicializar(&t);
  insereR(&t,10);
  insereR(&t,5);
  insereR(&t,15);
  insereR(&t,8);
  insereR(&t,3);
  insereR(&t,11);
  insereR(&t,16);
  PreOrdem(t);
      printf("\n");
  remover(&t,5);
  PreOrdem(t);
      // int x =busca(t,15);
      // // printf("%d\n",x );
      // if(x!=1) printf("nao achou\n");

      return 0;
}
