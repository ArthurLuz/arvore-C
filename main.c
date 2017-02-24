#include "abb.h"
int main(int argc, char const *argv[]){
  tno*t;
  inicializar(&t);
  insereR(&t,10);
  insereR(&t,5);
  insereR(&t,15);
  insereR(&t,8);
  insereR(&t,3);
  PreOrdem(t);
      printf("\n");
      return 0;
}
