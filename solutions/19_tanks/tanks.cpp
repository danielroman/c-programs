#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define TIEMPO 0.1
struct TPuntos{
    double x;
    double y;
};

struct TCoordenada{
    struct TPuntos punto;
    struct TPuntos velocidad;
    struct TPuntos aceleracion;
};

void pintar(struct TCoordenada proyectil){

    mvprintw(20 - proyectil.punto.y, proyectil.punto.x,  "*");
    refresh();

}

int main(int argc, char *argv[]){

    struct TCoordenada bala = { 
	{20, 0},
	{0, 0},
	{0, -10}
    };

    printf("Indiqueme la velocidad de X: ");
    scanf("%lf", &bala.velocidad.x);
    printf("Indiqueme la velocidad de Y: ");
    scanf("%lf", &bala.velocidad.y);

    initscr();
    clear();

    while(bala.punto.y >= 0){

	pintar(bala);

	bala.velocidad.x += bala.aceleracion.x * TIEMPO;
	bala.velocidad.y += bala.aceleracion.y * TIEMPO;
	bala.punto.x += bala.velocidad.x * TIEMPO;
	bala.punto.y += bala.velocidad.y * TIEMPO;
    }


    getch();
    endwin();

    return EXIT_SUCCESS;

}
