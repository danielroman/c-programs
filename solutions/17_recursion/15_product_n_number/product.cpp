#include <stdio.h>
#include <stdlib.h>

#define N 7

int add(int n){ return n >= 2 ? n * add(n-1) : n;}

int main(int argc, char *argv[]){

    printf("R: %i \n", add(N));

  return EXIT_SUCCESS;

}
