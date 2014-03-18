#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int numero; //Variable para recoger el numero del usuario
    int  contador = 0; //Variable para saber posteriormente por cuanto lo tengo que dividir para calcular la media
    double total = 0; //Variable donde guardo la suma de todos los numeros y despues la divido

    do{
	printf("Numero: ");
	scanf(" %i", &numero);
	if(numero > 0){ 
	    total += numero;
	    contador++;
	}
    }while(numero > 0);

    total /= contador;
    printf("La media es: %.2lf\n", total);

  return EXIT_SUCCESS;

}
