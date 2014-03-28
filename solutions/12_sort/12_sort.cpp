#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    const char *list[] = { "yield", "yelp", "yellow"};
    const char *aux[2];
   if((strcmp(list[1], list[2]) > 0) && (strcmp(list[0], list[2]) > 0)){
	aux[0] = list[2];
	if(strcmp(list[0], list[1]) > 0){
	    aux[1] = list[1];
	    list[2] = list[0];
	    list[0] = aux[0];
	    list[1] = aux[1];
	}else{
	    aux[1] = list[0];
	    list[2] = list[1];
	    list[0] = aux[0];
	    list[1] = aux[1];	
	}	    
   }
   
   if((strcmp(list[0], list[1]) > 0) && (strcmp(list[2], list[1]) > 0)){
	aux[0] = list[1];
	if(strcmp(list[0], list[2]) > 0){
	    aux[1] = list[2];
	    list[2] = list[0];
	    list[0] = aux[0];
	    list[1] = aux[1];
	}else{
	    aux[1] = list[0];
	    list[0] = aux[0];
	    list[1] = aux[1];	
	}	    
   }
   
   if((strcmp(list[1], list[0]) > 0) && (strcmp(list[2], list[0]) > 0)){
	aux[0] = list[0];
	if(strcmp(list[1], list[2]) > 0){
	    aux[1] = list[2];
	    list[2] = list[1];
	    list[0] = aux[0];
	    list[1] = aux[1];
	}else{
	    aux[1] = list[1];
	    list[0] = aux[0];
	    list[1] = aux[1];
	    list[2] = list[2];
	}	    
   }
 
    for (int i = 0; i < 3; i++)
	printf("%s\n", list[i]);

    return EXIT_SUCCESS;
}
