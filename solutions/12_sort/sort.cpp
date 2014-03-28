#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){


    const char *list[] = { "yield", "yelp", "yellow"};

    int longitud = sizeof(list) / sizeof (char*);

    for (int posicion = 0; posicion < longitud; posicion++){
	const char *aux;
	for (int palabra = posicion + 1; palabra < longitud; palabra++)
	    if (strcmp(list[posicion], list[palabra]) > 0){
		 aux = list[posicion];
		 list[posicion] = list[palabra];
		 list[palabra] = aux;
	    }
    }

    for (int i = 0; i < longitud; i++)
	printf("%s\n", list[i]);

  return EXIT_SUCCESS;

}
