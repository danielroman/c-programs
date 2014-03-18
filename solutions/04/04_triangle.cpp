#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc<2){
	fprintf(stderr, "Por favor, introduce un caracter.\n");
	exit (EXIT_FAILURE);
    }

    int altura = 4;

    for(int fila = 0; fila < altura; fila++){
	for(int columna = 0; columna < altura; columna++){
	    if(fila >= columna)
		printf("%c", *argv[1]);
	    else
		printf(" ");
	}
	printf("\n");
    }

  return EXIT_SUCCESS;

}
