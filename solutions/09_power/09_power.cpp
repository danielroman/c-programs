#include <stdio.h>
#include <stdlib.h>

#define N 0x10




void error(char *argv[]){

    fprintf(stderr, "Usage: %s numero \n", argv[0]);
    exit(EXIT_FAILURE);
}

//Rellenar una matriz con numeros de 1 a 16 ambos inclusive
void fill_in(int list[N]){
    for (int numeros = 0; numeros < N; numeros++)
	list[numeros] = numeros + 1; 
}

//Elevar los numeros al exponente indicado
int power(int base[N], int exponent){
    
    int valor;
    for (int numeros = 0; numeros < N; numeros++){
	valor = base[numeros];
	for (int elevado = 0; elevado < exponent -1; elevado++)
		base[numeros] *= valor;
    }
}


int main(int argc, char *argv[]){

    int exponent;
    int base[N];

    if (argc < 2)
	error(argv);

    exponent = atoi(argv[1]);
       
    fill_in(base);
    power(base,exponent);

    
//Imprimir el resultado de la multiplicacion
    for (int cont = 0; cont < N; cont++)
	printf("%i ", base[cont]); 


    printf("\n");
    return EXIT_SUCCESS;

}
