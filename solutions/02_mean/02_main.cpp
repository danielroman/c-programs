#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Me define que 10 es el maximo de numeros que puedo meter
int main(int argc, char *argv[]){

    double resultado,numeros, acumulacion;

    printf("Introduce 10 numeros\n ");
    for (int repeticiones = 0; repeticiones <= MAX; numeros++){
	printf("Introduce un Numero:");
	scanf(" %lf", &numeros);
	acumulacion += numeros;
    }

    resultado = acumulacion / MAX;
    printf(" %lf", resultado);

    printf("\n");

  return EXIT_SUCCESS;

}
