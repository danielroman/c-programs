#include <stdio.h>
#include <stdlib.h>

struct TPuntos{
    double x;
    double y;
};

struct TCoordenada{
    struct TPuntos punto;
    struct TPuntos velocidad;
    struct TPuntos aceleracion;
};

int main(int argc, char *argv[]){

    double tiempo = 1;
    struct TPuntos punto;
    struct TPuntos velocidad;
    struct TPuntos aceleracion;

    aceleracion.x = 0;
    aceleracion.y = -10;

    punto.x = 0;
    punto.y = 5;

    printf("Indiqueme la velocidad de X: ");
    scanf("%lf", &velocidad.x);
    printf("Indiqueme la velocidad de Y: ");
    scanf("%lf", &velocidad.y);

    while(punto.y >= 0){

	punto.x += velocidad.x + aceleracion.x * tiempo;
	punto.y += velocidad.y + aceleracion.y * tiempo;
	printf("Coordenadas (%.2lf , %.2lf)", punto.x, punto.y);
	printf("\n");
    }


    return EXIT_SUCCESS;

}
