#include <stdio.h>
#include <stdlib.h>

#define N 10

double fraction(double n, int level){
    
    return level > 0 ? n = n + 1. / (fraction(n, level - 1)) : n = 0; 
}

int main(int argc, char *argv[]){

    double numero = 2;

    printf("%.10lf \n", fraction(numero, N));

  return EXIT_SUCCESS;

}
