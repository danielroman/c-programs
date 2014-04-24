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

double calculate_average_programacion(struct TStudents alumno[]){

    double media;

    for (int i = 0; i < N; i++)

	media += alumno[i].asignaturas.programacion;

    return media / N;
}

double calculate_average_bases(struct TStudents alumno[]){

    double media;

    for (int i = 0; i < N; i++)

	media += alumno[i].asignaturas.base_de_datos;

    return media / N;
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
	printf("\n");
    }
    
    printf("La nota media de la clase en la asignatura de Programacion es: %.2lf \n", calculate_average_programacion(alumnos));
    printf("La nota media de la clase en la asignatura de Base de Datos es: %.2lf \n", calculate_average_bases(alumnos));

}

int main(int argc, char *argv[]){

    struct TStudents alumnos[N];

    pedir_calificaciones(alumnos);

    sample_average(alumnos);

    return EXIT_SUCCESS;

}
