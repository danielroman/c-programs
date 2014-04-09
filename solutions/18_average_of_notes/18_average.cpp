#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define N 3
#define MAX 25

struct TSubjects {

    double programacion;
    double base_de_datos;
};

struct TStudents {

    char name[MAX];
    struct TSubjects asignaturas;

};

double calculate_average(struct TStudents alumno){

    return (alumno.asignaturas.programacion + alumno.asignaturas.base_de_datos) / 2;

}

void pedir_calificaciones(struct TStudents alumnos[]){
    
    for (int i = 0; i < N; i++){
	printf("El nombre del Alumno es: ");
	gets( alumnos[i].name);
	__fpurge(stdin);
	printf("La nota de Programacion: ");
	scanf(" %lf", &alumnos[i].asignaturas.programacion);
	__fpurge(stdin);
	printf("La nota de Base de datos: ");
	scanf(" %lf", &alumnos[i].asignaturas.base_de_datos);
	__fpurge(stdin);
	calculate_average(alumnos[i]);
	__fpurge(stdin);
    }
  }

void sample_average(struct TStudents alumnos[]){
    
    for (int x = 0; x < N; x++){
	printf("Nombre: %s \n", alumnos[x].name);
	printf("Nota Programacion: %.2lf \n", alumnos[x].asignaturas.programacion);
	printf("Nota Base de Datos: %.2lf \n", alumnos[x].asignaturas.base_de_datos);
	printf("La media es: %.2lf \n", calculate_average(alumnos[x]));
    }
}


int main(int argc, char *argv[]){


    struct TStudents alumnos[N];
    
    pedir_calificaciones(alumnos);

    sample_average(alumnos);

    printf("\n");





  return EXIT_SUCCESS;

}
