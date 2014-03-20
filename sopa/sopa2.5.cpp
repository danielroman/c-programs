#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define NMAX 10
#define NMAX15 15
#define NMAX20 20

enum TipoOpcion {sopapequenia, sopamedia, sopagrande, cargar, ver, guardar, manual, salir};
enum Opcion {creditos};

void cabecera(const char *titulo){
  char ejecutar[0x100] = "toilet -f term -F border --gay ";

  strcat(ejecutar, titulo);
  system(ejecutar);
}

void inform(const char *mssg){
/* Funcion para volver atras desde cualquier parte del menu y tambien permite ponerle un comentario al usuario*/     
     printf("\n%s\n", mssg);
     printf("Pulsa enter para continuar");
     __fpurge(stdin);
     getchar();
     __fpurge(stdin);
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}

void manualinform(){
    /*Funcion para que pare el manual y puedas volver al menu principal*/
     printf("Pulsa enter para volver al menu");
     __fpurge(stdin);
     getchar();
     __fpurge(stdin);
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}

void imprimir_directorio(const char *nombre_directorio){
     /*Funcion para imprimir el contenido del directorio*/
     DIR *dp;
     struct dirent *ep;

     cabecera("Contenidos del directorio");

     dp = opendir (nombre_directorio);
     if (dp != NULL)
     {
        while (ep = readdir (dp))
           if (ep->d_name[0] != '.'){
               printf("\t");
               puts (ep->d_name);
           }
        (void) closedir (dp);
     }
     else
         perror ("Couldn't open the directory");
     printf("\n");
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}

void titulo(){// Funcion del titulo
     system("clear"); //limpia la pantalla
     system("figlet SopaDeLetras"); // me hace unas letras para ponerle un titulo a la sopa de letras con el programa figlet de linux
     printf("\n"); 
}

enum TipoOpcion leer_menu(){ //Funcion del menu principal
   int opcion;

  do{
      titulo(); //Invocar funcion titulo
      /*Mostramos por pantalla las diferentes posibilidades del menu*/
      printf("1.Crear 10x10 " "\t2.Crear 15x15 " "\t3.Crear 20x20 " "\t4. Cargar " "\t5. Ver Sopa "  "\t6. Guardar " "\t7. Manual" "\t 8. Salir " "\t Tu Opción: ");
      /*---------------------------------------------------------------------------------------------------------------------------------------*/
      /* Escluimos todas las letras para que solo me pueda introducir un numero*/
      __fpurge(stdin);
      /*---------------------------------------------------------------------------------------------------------------------------------------*/
      scanf(" %i", &opcion);
   }while(opcion<1 || opcion > salir + 1);
   titulo();
   return (enum TipoOpcion) (opcion - 1);
}

void rellenar(char matriz[NMAX][NMAX]){// Funcion para rellenar la sopa con cararacter aleatorios
  
    /*declaramos las variables que vamos a usar para pedir palabras*/
    char palabra1[NMAX];//definimos una variable de tipo char (string) con el tamaño de NMAX o 10
    char palabra2[NMAX];
    char palabra3[NMAX];
    /*---------------------------------------------------------------------------------------------------------------------------------------*/

    /*Declaramos las variables para posteriormente generar una posicion aleatoria */
    int posicion_columna = 0;//definimos la variable posicion_columna para generar una posicion aleatoria para la columna
    int posicion_fila = 0;//definimos la variable posicion_fila para generar una posicion aleatoria para la fila
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    
    /* Pedimos palabras de diferentes tamaños */
    printf("Introduce una palabra de 9 letras: ");//pedimos al usuario que meta la primera palabra de 9 caracteres
    scanf("%s", palabra1);// scaneamos la palabra introducida por el usuario
    int direccion1 = rand() % 2; // generamos una direccion aleatoria
    printf("Introduce una palabra de 7 letras: ");
    scanf("%s", palabra2);
    int direccion2 = rand() % 2;
    printf("Introduce una palabra de 5 letras: ");
    scanf("%s", palabra3);
    int direccion3 = rand() % 2;
    /*---------------------------------------------------------------------------------------------------------------------------------------*/


    /* Medimos la longitud de cada una de las palabras introducidas y le declaramos una varible para cada palabra introducida por el usuario*/
    int longitud1 = strlen(palabra1);
    int longitud2 = strlen(palabra2);
    int longitud3 = strlen(palabra3);
    /* -------------------------------------------------------------------------------------------------------------------------------------*/

    /*Rellenamos la matriz con caracteres aleatorios*/
    for (int fila = 0; fila < NMAX; fila++)
	for (int columna = 0; columna < NMAX; columna++)
	    matriz[fila][columna] =/* '*';*/ (char) (rand() % ('z' -'a') + 'a');
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
     if (direccion1 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 2; contador < longitud1; contador++,columna_palabra++)
	    matriz[posicion_fila][columna_palabra] = palabra1[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 2; contador < longitud1; contador++,fila_palabra++)
	    matriz[fila_palabra][posicion_columna] = palabra1[contador];
    } 
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
    if (direccion2 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 4; contador < longitud2; contador++,columna_palabra++)
	    matriz[posicion_fila][columna_palabra] = palabra2[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 4; contador < longitud2; contador++,fila_palabra++)
	    matriz[fila_palabra][posicion_columna] = palabra2[contador];
    }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
    if (direccion3 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 6; contador < longitud3; contador++,columna_palabra++)
	    matriz[posicion_fila][columna_palabra] = palabra3[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 6; contador < longitud1; contador++,fila_palabra++)
	    matriz[fila_palabra][posicion_columna] = palabra3[contador];
    }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}

void escribir(FILE *salida, char matriz[NMAX][NMAX]){//Funcion para escribir el contenido de la sopa con las palabras ya introducidas
// Creamos un for para imprimir los resultados de la sopa  
   for (int fila=0; fila<NMAX; fila++){
      fprintf(salida, "\t");
      for(int col=0; col<NMAX; col++)
          fprintf(salida, "%c ", matriz[fila][col]);
      fprintf(salida, "\n");
  }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
} 

void leer(FILE *entrada, char matriz[NMAX][NMAX]){//Funcion para leer la sopa
   for(int fila=0; fila<NMAX; fila++)
      for(int col=0; col<NMAX; col++)
         fscanf(entrada, " %c", &matriz[fila][col]);

   inform("Sopa cargada");
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}

void pintar(char matriz[NMAX][NMAX]){//Funcion para pintar la sopa
   escribir(stdout, matriz);
   inform("Esta es tu sopa");//Llama a la funcion inform para que me aparezca el texto "Esta es tu sopa" y A continuación Pulsa una tecla para continuar...
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}

void rellenar15(char matriz15[NMAX15][NMAX15]){// Funcion para rellenar la sopa con cararacter aleatorios e introducir las palabras

    /*declaramos las variables que vamos a usar para pedir palabras*/
    char palabra1[NMAX];//definimos una variable de tipo char (string) con el tamaño de NMAX o 10
    char palabra2[NMAX];
    char palabra3[NMAX];
    /*---------------------------------------------------------------------------------------------------------------------------------------*/

    /*Declaramos las variables para posteriormente generar una posicion aleatoria */
    int posicion_columna = 0;//definimos la variable posicion_columna para generar una posicion aleatoria para la columna
    int posicion_fila = 0;//definimos la variable posicion_fila para generar una posicion aleatoria para la fila
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    
    /* Pedimos palabras de diferentes tamaños */
    printf("Introduce una palabra de 9 letras: ");//pedimos al usuario que meta la primera palabra de 9 caracteres
    scanf("%s", palabra1);// scaneamos la palabra introducida por el usuario
    int direccion1 = rand() % 2; // generamos una direccion aleatoria
    printf("Introduce una palabra de 7 letras: ");
    scanf("%s", palabra2);
    int direccion2 = rand() % 2;
    printf("Introduce una palabra de 5 letras: ");
    scanf("%s", palabra3);
    int direccion3 = rand() % 2;
    /*---------------------------------------------------------------------------------------------------------------------------------------*/


    /* Medimos la longitud de cada una de las palabras introducidas y le declaramos una varible para cada palabra introducida por el usuario*/
    int longitud1 = strlen(palabra1);
    int longitud2 = strlen(palabra2);
    int longitud3 = strlen(palabra3);
    /* -------------------------------------------------------------------------------------------------------------------------------------*/

    /*Rellenamos la matriz con caracteres aleatorios*/
    for (int fila = 0; fila < NMAX15; fila++)
	for (int columna = 0; columna < NMAX15; columna++)
	    matriz15[fila][columna] =/* '*';*/ (char) (rand() % ('z' -'a') + 'a');
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
     if (direccion1 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 2; contador < longitud1; contador++,columna_palabra++)
	    matriz15[posicion_fila][columna_palabra] = palabra1[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 2; contador < longitud1; contador++,fila_palabra++)
	    matriz15[fila_palabra][posicion_columna] = palabra1[contador];
    } 
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
    if (direccion2 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 4; contador < longitud2; contador++,columna_palabra++)
	    matriz15[posicion_fila][columna_palabra] = palabra2[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 4; contador < longitud2; contador++,fila_palabra++)
	    matriz15[fila_palabra][posicion_columna] = palabra2[contador];
    }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
    if (direccion3 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 6; contador < longitud3; contador++,columna_palabra++)
	    matriz15[posicion_fila][columna_palabra] = palabra3[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 6; contador < longitud1; contador++,fila_palabra++)
	    matriz15[fila_palabra][posicion_columna] = palabra3[contador];
    }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}
  
void escribir15(FILE *salida, char matriz15[NMAX15][NMAX15]){//misma funcion que la de escribir
  for (int fila=0; fila<NMAX15; fila++){
      fprintf(salida, "\t");
      for(int col=0; col<NMAX15; col++)
          fprintf(salida, "%c ", matriz15[fila][col]);
      fprintf(salida, "\n");
  }
} 

void leer15(FILE *entrada, char matriz15[NMAX15][NMAX15]){//misma funcion que la de leer
   for(int fila=0; fila<NMAX15; fila++)
      for(int col=0; col<NMAX15; col++)
         fscanf(entrada, " %c", &matriz15[fila][col]);

   inform("Sopa cargada");
}

void pintar15(char matriz15[NMAX15][NMAX15]){//misma funcion que la de pintar
   escribir15(stdout, matriz15);
   inform("Esta es tu sopa");//Llama a la funcion inform para que me aparezca el texto "Esta es tu sopa" y A continuación Pulsa una tecla para continuar...
}

void rellenar20(char matriz20[NMAX20][NMAX20]){// Funcion para rellenar y que te pida las palabras para la sopa de 20x20

    /*declaramos las variables que vamos a usar para pedir palabras*/
    char palabra1[NMAX];//definimos una variable de tipo char (string) con el tamaño de NMAX o 10
    char palabra2[NMAX];
    char palabra3[NMAX];
    /*---------------------------------------------------------------------------------------------------------------------------------------*/

    /*Declaramos las variables para posteriormente generar una posicion aleatoria */
    int posicion_columna = 0;//definimos la variable posicion_columna para generar una posicion aleatoria para la columna
    int posicion_fila = 0;//definimos la variable posicion_fila para generar una posicion aleatoria para la fila
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    
    /* Pedimos palabras de diferentes tamaños */
    printf("Introduce una palabra de 9 letras: ");//pedimos al usuario que meta la primera palabra de 9 caracteres
    scanf("%s", palabra1);// scaneamos la palabra introducida por el usuario
    int direccion1 = rand() % 2; // generamos una direccion aleatoria
    printf("Introduce una palabra de 7 letras: ");
    scanf("%s", palabra2);
    int direccion2 = rand() % 2;
    printf("Introduce una palabra de 5 letras: ");
    scanf("%s", palabra3);
    int direccion3 = rand() % 2;
    /*---------------------------------------------------------------------------------------------------------------------------------------*/


    /* Medimos la longitud de cada una de las palabras introducidas y le declaramos una varible para cada palabra introducida por el usuario*/
    int longitud1 = strlen(palabra1);
    int longitud2 = strlen(palabra2);
    int longitud3 = strlen(palabra3);
    /* -------------------------------------------------------------------------------------------------------------------------------------*/

    /*Rellenamos la matriz con caracteres aleatorios*/
    for (int fila = 0; fila < NMAX20; fila++)
	for (int columna = 0; columna < NMAX20; columna++)
	    matriz20[fila][columna] =/* '*';*/ (char) (rand() % ('z' -'a') + 'a');
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
     if (direccion1 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 2; contador < longitud1; contador++,columna_palabra++)
	    matriz20[posicion_fila][columna_palabra] = palabra1[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 2; contador < longitud1; contador++,fila_palabra++)
	    matriz20[fila_palabra][posicion_columna] = palabra1[contador];
    } 
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
    if (direccion2 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 4; contador < longitud2; contador++,columna_palabra++)
	    matriz20[posicion_fila][columna_palabra] = palabra2[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 4; contador < longitud2; contador++,fila_palabra++)
	    matriz20[fila_palabra][posicion_columna] = palabra2[contador];
    }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
    /*Generamos la posicion para la pimera palabra, recorremos todo su tamaño y rellenamos la matriz con la palabra*/
    if (direccion3 == 1){
	posicion_fila = rand() %10;
	for (int contador = 0, columna_palabra = rand() % 6; contador < longitud3; contador++,columna_palabra++)
	    matriz20[posicion_fila][columna_palabra] = palabra3[contador]; 
    }else{
	posicion_columna = rand() %10;
	for (int contador = 0, fila_palabra = rand() % 6; contador < longitud1; contador++,fila_palabra++)
	    matriz20[fila_palabra][posicion_columna] = palabra3[contador];
    }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/
}

void escribir20(FILE *salida, char matriz20[NMAX20][NMAX20]){//Funcion para guardar la sopa
  for (int fila=0; fila<NMAX20; fila++){
      fprintf(salida, "\t");
      for(int col=0; col<NMAX20; col++)
          fprintf(salida, "%c ", matriz20[fila][col]);
      fprintf(salida, "\n");
  }
} 

void leer20(FILE *entrada, char matriz20[NMAX20][NMAX20]){//Funcion para cargar la sopa
   for(int fila=0; fila<NMAX20; fila++)
      for(int col=0; col<NMAX20; col++)
         fscanf(entrada, " %c", &matriz20[fila][col]);

   inform("Sopa cargada");
}

void pintar20(char matriz20[NMAX20][NMAX20]){//Funcion para pintar la sopa
   escribir20(stdout, matriz20);
   inform("Esta es tu sopa");//Llama a la funcion inform para que me aparezca el texto "Esta es tu sopa" y A continuación Pulsa una tecla para continuar...
}

void manualuser(){
    /*Funcion que imprime por pantalla el manual de uso*/
	       system("clear");
               system("\tfiglet MANUAL DE USO\n ");
	       printf("\tEste es un manual de uso del programa\n\n"
		      "\t1.La opcion Crear 10x10, crea una sopa de ese tamaño.\n"
		      "\t1.1.La opcion Crear 15x15, crea una sopa de ese tamaño.\n"
		      "\t1.2.La opcion Crear 20x20, crea una sopa de ese tamaño.\n"
		      "\t2.La opcion Cargar, carga una sopa previamente guardada.\n"
		      "\t3.La opcion Ver, sirve para ver la sopa que se ha cargado.\n"
		      "\t4.La opcion Guardar, sirve para guardar una sopa hecha o sin hacer.\n"
		      "\t5.La opcion Manual, muestra este manual.\n"
		      "\t6.La opcion Salir, sale del juego.\n");
	       printf("\n");
	       manualinform();
    /*---------------------------------------------------------------------------------------------------------------------------------------*/

}

int adios(){
    /*Funcion para salir del programa tiene nombre adios por que mas arriba se declaro salir y da fallo si le ponemos salir lugar donde esta declarado el otro salir linea 11*/

	       system("clear");
               system("figlet Hasta la proxima\n ");
               system("figlet Creditos\n ");
               printf("\tDavid Serrano\n"
                      "\tDaniel Roman\n"
                      "\tJavier Benedcito\n"
                      "\tLeticia López\n"
                      "\tNerea Fernandez\n"
                      "\tVictor Kraski\n"
                     );
	       return EXIT_SUCCESS;
    /*---------------------------------------------------------------------------------------------------------------------------------------*/

}

int main(int argc, char *argv[]){

    FILE *fichero;// crea una variable de nombre fichero para poder guardar elementos dentro (NO SE COMO EXPLICARLO BIEN)
    char sopa[NMAX][NMAX];// crea una variable sopa con un espacio de 10x10
    char sopa15[NMAX15][NMAX15];// crea una variable sopa con un espacio de 15x15
    char sopa20[NMAX20][NMAX20];// crea una variable sopa con un espacio de 20x20 
    int opcion; // variable para las opciones de la sopa
    //char nombre_de_fichero[0x20];// me crea una variable de tipo char con un espacio de 0x20 para guardar el nombre del fichero
    int nombre_de_fichero;// me crea una variable de tipo int para poder cargar los diferentes archivos
    srand(time(NULL));//crea la semilla para el randon
    int sopa_cargada = 0; //0 equivale a falso, !=0 verdadero.
    int sopa_guardada = 0; //0 equivale a falso, !=0 verdadero.


do{
    	 switch (opcion = leer_menu()){
     	     case sopapequenia:
    		cabecera("Nueva Sopa 10x10");//me crea un titulo para la sopa
		rellenar(sopa);//me rellena la sopa
		sopa_guardada = 1;//me cambia el valor de la variable sopa_cargada que esta incializada a 0 y me la pone a 1 para poder guardar la sopa de 10x10
		pintar(sopa);
		break;


	     case sopamedia:
		cabecera("Nueva Sopa de 15x15");
		rellenar15(sopa15);
		sopa_guardada = 2;
		pintar15(sopa15);
		break;


	     case sopagrande:
		cabecera("Nueva Sopa 20x20");
		rellenar20(sopa20);
		sopa_guardada = 3;
		pintar20(sopa20);
		break;


	     case cargar:// comando de cargar

		imprimir_directorio("./");
		printf("Elige un tamaño para cargar la sopa (10, 15 o 20)");//Te pregunta el tamaño de la sopa para cargar
		__fpurge(stdin);
	 	scanf(" %i", &nombre_de_fichero);//recoge el valor de la variable

		if(nombre_de_fichero == 10){// en el caso de que el fichero valga 10
		    fichero = fopen("sopa10.txt", "r");//abre el fichero de la sopa10
		    leer(fichero, sopa);//lee el fichero y carga la sopa
		    sopa_cargada = 1;//me cambia valor de la variable para posteriormente mostrarla
		    fclose(fichero);//cierra el fichero
		}
		if(nombre_de_fichero == 15){// en el caso de que el fichero valga 10
		    fichero = fopen("sopa15.txt", "r");//abre el fichero de la sopa10
		    leer15(fichero, sopa15);//lee el fichero y carga la sopa
		    sopa_cargada = 2;//me cambia valor de la variable para posteriormente mostrarla
		    fclose(fichero);//cierra el fichero
		}
		if(nombre_de_fichero == 20){// en el caso de que el fichero valga 10
		    fichero = fopen("sopa20.txt", "r");//abre el fichero de la sopa10
		    leer20(fichero, sopa20);//lee el fichero y carga la sopa
		    sopa_cargada = 3;//me cambia valor de la variable para posteriormente mostrarla
		    fclose(fichero);//cierra el fichero
		}
		break;
	       
	     case ver://codigo en revision solo funciona a la vez con un tamaño de sopa
		if(sopa_cargada > 0 || sopa_cargada < 4){
		    if (sopa_cargada == 1){    
			cabecera("Sopa Activa");
			pintar(sopa);// me pinta la sopa cargada			
		    }
		    if(sopa_cargada == 2){
			cabecera("Sopa Activa");
			pintar15(sopa15);
		    }
		    if(sopa_cargada == 3){
			cabecera("Sopa Activa");
			pintar20(sopa20);
		    }
		}else
    		    inform("De momento no hay ninguna sopa cargada.");		    
		break;
	   		    
	     case guardar:// comando de guardar
	      		if(sopa_guardada != 0){// Indico si la variable sopa_cargada tiene algun valor que entre dentro del if si no que se valla al else 

			    	// Si sopa_cargada vale 2 hace los mismo que el if anterior solo que para la sopa de 10x10
				if(sopa_guardada == 1){
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/   
                  	//	printf("Elige un nombre para guardar la sopa: ");//Te pide un nombre para guardar la sopa
                  	//	scanf(" %s", nombre_de_fichero);// recojo el valor de la variable nombre_fichero para guardar la sopa con ese nombre
				// Abro el fichero con el nombre de la variable indicada y lo escribo
                  		fichero = fopen("sopa10.txt", "w"); 
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				// le añado los valores de la sopa con la funcion escribir al fichero
                  		escribir(fichero, sopa);
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				// cierro el fichero
                  		fclose(fichero);
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				//imprime el directorio 
                  		imprimir_directorio("./");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
	            		//Funcion para informar al usuario de que el fichero se a guardado asi como su nombre y vuelve al menu principal
                  		inform("Su nombre de Fichero Guardado es sopa10.txt.");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				}
				// Si sopa_cargada vale 2 hace los mismo que el if anterior solo que para la sopa de 15x15
				if(sopa_guardada == 2){
                  	//	printf("Elige un nombre para guardar la sopa: ");
                  	//	scanf(" %s", nombre_de_fichero);
				// Abro el fichero con el nombre de la variable indicada y lo escribo
                  		fichero = fopen("sopa15.txt", "w");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				// le añado los valores de la sopa con la funcion escribir al fichero
                  		escribir15(fichero, sopa15);
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				// cierro el fichero
                  		fclose(fichero);
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				//imprime el directorio 
                  		imprimir_directorio("./");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
		          	//Funcion para informar al usuario de que el fichero se a guardado asi como su nombre y vuelve al menu principal
                  		inform("Su nombre de Fichero Guardado es sopa15.txt.");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				}

				if(sopa_guardada == 3){// si sopa_cargada vale 3 hace lo mismo que los 2 if anteriores solo que para la sopa de 20x20
                  	//	printf("Elige un nombre para guardar la sopa: ");
                  	//	scanf(" %s", nombre_de_fichero);
				// Abro el fichero con el nombre de la variable indicada y lo escribo
                  		fichero = fopen("sopa20.txt", "w");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				// le añado los valores de la sopa con la funcion escribir al fichero
                  		escribir20(fichero, sopa20);
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				// cierro el fichero
                  		fclose(fichero);
    		                /*---------------------------------------------------------------------------------------------------------------------------------------*/
				//imprime el directorio 
    				imprimir_directorio("./");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				//Funcion para informar al usuario de que el fichero se a guardado asi como su nombre y vuelve al menu principal
                  		inform("Su nombre de Fichero Guardado es sopa20.txt.");
    				/*---------------------------------------------------------------------------------------------------------------------------------------*/
				}
			}else
			    inform("No hay ninguna sopa cargada.");	
	 	break;
		
	     case manual:
	
		manualuser();
		
		break;


	     case salir:

		adios();//funcion para la despedida
		
		break;
	}	
		
}while(opcion != salir);
	       	printf("\n\n");
  	       	return EXIT_SUCCESS;

}




