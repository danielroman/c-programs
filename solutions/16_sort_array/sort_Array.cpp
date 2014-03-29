#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int A[] = {22, 3, 77, 50, 40, 23, 37, 35, 22, 2, 61, 71, 0};
    int cantidad_numeros = sizeof(A) / sizeof(int);
    int veces = cantidad_numeros;
    int aux[cantidad_numeros];
    int contador = 0;
    int contador1 = 0;
    int contador2 = 0;
    do{

	for (int numero = 0; numero <= cantidad_numeros; numero++){
	    for(int posicion = 1; posicion < cantidad_numeros; posicion++){
		if(A[numero] < A[posicion]){
		    //Conseguir guardar el valor en las diferentes posiciones del array ??
			aux[contador] = A[numero];
		}	    
	    }
	}
	cantidad_numeros--;
	contador++;
    }while(contador < veces);

    for (int muestra = 0; muestra < veces; muestra++)
	printf("%i ", aux[muestra]);
    printf("\n");

    return EXIT_SUCCESS;

}
