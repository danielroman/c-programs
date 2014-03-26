#include <stdio.h>
#include <stdlib.h>

#define N 70

int main(int argc, char *argv[]){

    int primos[N];//Creamos un array con 70 celdas para los 70 numeros
    primos[0] = 2;//La primera celda la ocupamos con el 2 ya que sabemos que es el unico numero par y primo a la vez
    int celdas = 0;//La utilizamos para guardar el numero probado en la variable en caso de que sea un primo
    int primo_encontrado = 1;//La inicializamos a 1 ya que el primer numero ya esta encontrado
    int numero = 3;

    bool primo_hallado = true;

    //Mientras que la cantidad de primos encontrados sea < 70, buscamos primos
    while(primo_encontrado <= N){

	for (int divisor = 2; divisor < numero; divisor++){
	//divisores lo inicialiazamos a 2 por que es el unico numero par y primo a la vez
	    if (numero % divisor == 0)
		primo_hallado = false;
	}

	if (primo_hallado == true){  
	    primo_encontrado++;
	    celdas++;//Incrementamos para ir guardando en las posiciones del array
	    primos[celdas] = numero;
	}

	primo_hallado = true;

	numero++;
    }

    //imprimir la matriz de los 70 primeros PRIMOS
    for (int numeros_primos = 0; numeros_primos < N; numeros_primos++)
	printf("%i ", primos[numeros_primos]);
    printf("\n");


    /*    if(primo == true){
	  printf("EL numero %i es primo \n", numeros);
	  else
	  printf("EL numero %i no es primo \n", numeros);
     */
    return EXIT_SUCCESS;
}
