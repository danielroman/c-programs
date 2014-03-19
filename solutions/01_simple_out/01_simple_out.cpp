#include <stdio.h>
#include <stdlib.h>

#define RMAX 10 //Me da el valor maximo de repeticiones

int main(int argc, char *argv[]){

    char *frase;
    frase = argv[1];

  for(int repeticiones = 0; repeticiones<RMAX; repeticiones++)
	printf("\n\t%s", frase);

    printf("\n\n");
	



  return EXIT_SUCCESS;

}
