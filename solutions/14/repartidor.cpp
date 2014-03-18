#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

//Quiero un jugador que reparta cartas a los distintos jugadores 
//equitativamente

    int jugador[4] = {0, 0, 0, 0};
    int cartas = 0;
    int contador = 0;

    //Obtener las cartas a repartir entre los 4 jugadores
    cartas = atoi(argv[1]);

    //Repartir cartas entre los jugadores
    for (int repartidas = 0; repartidas < cartas; repartidas++){
	//Si cartas es divisible entre 4 
	if(cartas / 4 != 0){
	    //Incrementar el valor de la variable en 1
	    jugador[contador] += 1;
	    //Incrementar la posicion de la variable en 1
	    contador++;
	    //Si la pocion de la variable es igual a 4 volver variable a valor inicial
	    if(contador == 4)
		contador = 0;
	}
    }
    printf("Cartas Jugador1 = %i, Jugador2 = %i, Jugador3 = %i, Jugador4 = %i \n", jugador[0], jugador[1], jugador[2], jugador[3]);
    








  return EXIT_SUCCESS;

}
