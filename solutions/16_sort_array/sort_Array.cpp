#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int A[] = {22, 3, 77, 50, 40, 23, 37, 35, 22, 2, 61, 71, 0};
    int cantidad_numeros = sizeof(A) / sizeof(int);

    for (int numero = 0; numero <= cantidad_numeros; numero++){
	int aux;
	for(int posicion = numero + 1; posicion < cantidad_numeros; posicion++)
	    if(A[numero] > A[posicion]){
		aux = A[numero];
		A[numero] = A[posicion];
		A[posicion] = aux;
	    }	    
    }

    for (int muestra = 0; muestra < cantidad_numeros; muestra++)
	printf("%i ", A[muestra]);
    printf("\n");

    return EXIT_SUCCESS;

}
