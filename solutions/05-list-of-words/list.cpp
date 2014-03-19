#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    const char *list[] = {
	"bread", 
	"toast", 
	"bacon",
	"hamburguer",
	NULL
    };
    //forma 1 con sizeof 
    //for (int contenido_list = 0; contenido_list < sizeof(list) / sizeof(char *); contenido_list++)
    //	printf("%s\n", list[contenido_list]);

    for (int contenido_list = 0; list[contenido_list] != NULL; contenido_list++)
	printf("%s\n", list[contenido_list]);
	    

  return EXIT_SUCCESS;

}
