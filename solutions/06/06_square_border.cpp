#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if (argc < 2){
	fprintf(stderr, "Introduce un numero para el marco del triangulo. \n");
	exit (EXIT_FAILURE);
    }

    int borde = atoi(argv[1]);


    for (int fila = 0; fila < borde; fila++){
	for(int columna = 0; columna < borde; columna++){
	    //Evaluamos la condicion que se tiene que cumplir para realizar el borde del cuardrado.
	    if(fila == 0 || columna == 0 || fila == borde -1 || columna == (borde -1))
		printf("*");
	    else
		printf(" ");
	}
	printf("\n");
    }



  return EXIT_SUCCESS;

}
