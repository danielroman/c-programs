#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    const char *sentence  = "The world is a vampire.";
    const char *beginning = sentence;
    const char *end	  = sentence;

    while(*end != '\0')
	*end++; 
    while(*end != *beginning){
	*end--;
	printf("%c", *end);
    }


    printf("\n");


    

    return EXIT_SUCCESS;
}
