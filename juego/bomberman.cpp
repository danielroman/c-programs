#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>

#define FILAS 25
#define COL 50
#define ESC 27


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

    clear();
    for(int fila = 0; fila < FILAS; fila++){
	for (int col = 0; col < COL; col++){
	    printw("%c", tablero[fila][col]);

	}
	printw("\n");
    }
    refresh();

}

void inicializar(char tablero[FILAS][COL]){


    for (int fila = 0; fila < FILAS; fila++)
	for (int col = 0; col < COL; col++)
	    if (tablero[fila][col] == '1')
		tablero[fila][col] = 'T';
	    else
		if(tablero[fila][col] == '0')    
		    tablero[fila][col] = ' ';
		else 	    
		    if (tablero[fila][col] == '2')
			tablero[fila][col] = 'I';
		    else
			if (tablero[fila][col] == '4')
			    tablero[fila][col] = 'L';
}
void mover(int user_input, struct Coordenadas *jugador, char tablero[FILAS][COL]){

    switch(tolower(user_input)){
	case 'w':
	case KEY_UP:
	    if (tablero[jugador->y - 1][jugador->x] != 'T'){
		tablero[jugador->y][jugador->x] = ' ';
		jugador->y += -1;
	    }
	    break;
	case 's':
	case KEY_DOWN:
	    if (tablero[jugador->y + 1][jugador->x] != 'T'){
		tablero[jugador->y][jugador->x] = ' ';
		jugador->y += 1;
	    }
	    break;
	case 'a':
	case KEY_LEFT:
	    if (tablero[jugador->y][jugador->x - 1] != 'T'){
		tablero[jugador->y][jugador->x] = ' ';
		jugador->x += -1;
	    }
	    break;
	case 'd':
	case KEY_RIGHT:
	    if (tablero[jugador->y][jugador->x + 1] != 'T'){
		tablero[jugador->y][jugador->x] = ' ';
		jugador->x += 1;
	    }
	    break;	
    }
    tablero[jugador->y][jugador->x] = 'U';
}

int main(int argc, char *argv[]){

    struct Coordenadas jugador = {1, 1}; //posicion inicial del jugador
    struct Coordenadas movimiento = {0,0}; //no se movera
    char tablero[FILAS][COL];
    int user_input;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    mapa(tablero);
    inicializar(tablero);
    while ((user_input = getch()) != ESC){	
	mover(user_input, &jugador, tablero);
	pintar_mapa(tablero, jugador);
    }
    endwin();
    return EXIT_SUCCESS;

}
