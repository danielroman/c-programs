#include <stdio.h>
#include <stdlib.h>

void fallo(char *argv[]){

        fprintf(stderr, "Usage: %s number number \n", argv[0]);
	    exit(EXIT_FAILURE);
}

double add(double numero1, double numero2){

	        return numero1 + numero2;
}

int main(int argc, char *argv[]){

        // Si no se introducen 2 numeros, llamada a la funcion para que indique el error y su forma de uso.
        if(argc<3)
	    fallo(argv);

	    // Atof para convertir los datos en tipo float.
	    double numero1 = atof(argv[1]),
		   numero2 = atof(argv[2]),
		   resultado = 0;

	        // La variable resultado tiene el valor que le devuelva la funcion add.
	        resultado = add(numero1, numero2);

		    printf(" %.2lf + %.2lf = %.2lf \n", numero1, numero2, resultado);

		        return EXIT_SUCCESS;
}
