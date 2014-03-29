#include <stdio.h>
#include <stdlib.h>

char string(const char *sentence){

    //si sentence es distinto o igual que '\0' (terminacion de la cadena)
    if(*sentence != '\0'){
	//llama a la funcion y le sumamos 1 al puntero para que apunte a la siquiente letra
	string(sentence + 1);	
	//pintame el valor de sentence
	printf("%c", *sentence);
    }
}

int main(int argc, char *argv[]){

    const char *sentence  = "The world is a vampire.";

    string(sentence);

    printf("\n");




    return EXIT_SUCCESS;
}
