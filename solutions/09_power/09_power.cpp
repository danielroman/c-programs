#include <stdio.h>
#include <stdlib.h>

#define N 0x10

int power(int list[N], int exponet){


}

void fill_in(int list[N]){
    for (int cont = 0; cont < N; cont++)
	list[cont] = cont + 1;
}


int main(int argc, char *argv[]){

    if(argc != 2)
	error(argv[0]);

    int list[N];
    int exponent = atoi(argv[1]);

    fill_in(list, exponent);

    for(int contador=0; contador < N; contador++)
	printf("%i\n", list[contador]);


    return EXIT_SUCCESS;

}
