#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>

#define FILAS 25
#define COL 50

struct Coordenadas{
    int x;
    int y;
};

void mapa(char tablero[FILAS][COL]){

    FILE *fichero;

    fichero = fopen("tablero.txt", "r");
    if(fichero == NULL){
	printf("El archivo tablero.txt no se encuentra");
	//falta poner que se salga cuando esto ocurra
    }else{
	for(int fila = 0; fila < FILAS; fila++)
	    for(int col = 0; col < COL; col++)
		fscanf(fichero, " %c", &tablero[fila][col]);
	fclose(fichero);
    }
}

void pintar_mapa(char tablero[FILAS][COL], struct Coordenadas jugador){

    mapa(tablero);
    for(int fila = 0; fila < FILAS; fila++){
	for (int col = 0; col < COL; col++){

	    if(fila == jugador.y && col == jugador.x)
		printf("%c", tablero[fila][col] = 'U');

	    if (tablero[fila][col] == '1')
		printf("%c",tablero[fila][col] = 'T');

	    if(tablero[fila][col] == '0')    
		printf("%c", tablero[fila][col] = ' ');	

	    if (tablero[fila][col] == '2')
		printf("%c", tablero[fila][col] = ' ');
	}
    printf("\n");
    }

}

void mover(struct Coordenadas movimiento, struct Coordenadas jugador){



}


void mover(int user_input, struct Coordenadas movimiento, struct Coordenadas jugador, char tablero[FILAS][COL]){

    while((user_input = getch()) != ESC){

	switch(tolower(user_input)){
	    case 'w':
	    case KEY_UP:
		if (tablero[jugador.y + 1][jugador.x] != 'T'){
		movimiento.x = 0;
		movimiento.y = -1;

		}
		break;
	    case 's':
	    case KEY_DOWN:
		movimiento.x = 0;
		movimiento.y = -1;
		break;
            case 'a':
	    case KEY_LEFT:
		movimiento.x = -1;
		movimiento.y = 0;
		break;
	    case 'd':
	    case KEY_RIGHT:
		movimiento.x = +1;
		movimiento.y = 0;
		break;	
	}
    }
}

int main(int argc, char *argv[]){

    struct Coordenadas jugador = {1, 1}; //posicion inicial del jugador
    struct Coordenadas movimiento = {0,0}; //no se movera
    char tablero[FILAS][COL];
    int user_input;
    pintar_mapa(tablero, jugador);

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
  //  movimiento_jugador(user_input, movimiento, jugador);
    endwin();
    return EXIT_SUCCESS;

}
