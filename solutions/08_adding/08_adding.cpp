#include <stdio.h>
#include <stdlib.h>

double add(double numero[], double cantidad_numeros){

    int total = 0;
    for (int contador = 0; contador < cantidad_numeros; contador++)

	total += numero[contador];

	return total;
}


int main(int argc, char *argv[]){

    double numeros[argc-1];
    double cantidad_numeros = argc - 1;
    double total =0;

    for (int contador = 0; contador < cantidad_numeros; contador++)
	numeros[contador] = atof(argv[contador+1]);

    total = add(numeros, cantidad_numeros);
    printf("%.2lf\n", total);


    return EXIT_SUCCESS;

}
