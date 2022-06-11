#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2
/*
Ejercicio 3-5 (VECTORES PARALELOS O ESTRUCTURAS):
Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de
goles).
Crear una función que permita cargar los datos de un jugador y otra que los muestre.
Una tercera función calculará el promedio de goles.
Cargar los datos de 5 jugadores. Y mostrarlos por pantalla.*/
typedef struct
{
    char nombreFutbolista[20];
    int golesMetidos;
    int partidosJugados;
    float promedioDeGoles;

}eJugador;

int mostrarDatos(eJugador vec[], int tam);

int cargarDatos(eJugador vec[], int tam);

float funcionPromedioDeGoles(int goles, int partidosJugados);

int main()
{
    eJugador listaDeJugadores[TAM];
    /*
    eJugador listaDeJugadores[TAM]={
    {"Jose Pedrol", 788, 1079, 0.73},
    {"Ana", 765, 831, 0.92},
    {"Juan Carlos",753, 971, 0.77},
    {"Fabiola",752 ,931 , 0.80},
    {"Maia Maria Luz", 746, 755, 0.99}
    };*/

    cargarDatos(listaDeJugadores, TAM);
    mostrarDatos(listaDeJugadores, TAM);
}

int cargarDatos(eJugador vec[], int tam)
{
    int todoOk=0;
    char auxiliarString[20];

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("Ingrese el nombre del futbolista: ");
            fflush(stdin);
            gets(auxiliarString);
            while(strlen(auxiliarString)>19)
            {
                printf("Nombre demasiado largo, ingre el nombre con 19 char max: ");
                fflush(stdin);
                gets(auxiliarString);
            }
            strcpy(vec[i].nombreFutbolista, auxiliarString);


            printf("Ingrese los goles del futbolista: ");
            scanf("%d", &vec[i].golesMetidos);

            while(vec[i].golesMetidos<0)
            {
                printf("No existen goles negativos. Reingrese los goles del futbolista: ");
                scanf("%d", &vec[i].golesMetidos);
            }

            printf("Ingrese los partidos jugados del futbolista: ");
            scanf("%d", &vec[i].partidosJugados);

            while(vec[i].partidosJugados<0)
            {
                printf("No existen partidos negativos. Reingrese los partidos del futbolista: ");
                scanf("%d", &vec[i].partidosJugados);
            }

            vec[i].promedioDeGoles=funcionPromedioDeGoles(vec[i].golesMetidos, vec[i].partidosJugados);
        }

        todoOk=1;
    }
    return todoOk;

}

int mostrarDatos(eJugador vec[], int tam)
{
    int todoOk=0;
    printf("    *** Listado de Futbolistas *** \n");

    printf("Nombre\t\tPartidos Goles\tPromedio de goles\n");
    if(vec!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("%10s", vec[i].nombreFutbolista);
            printf("\t %d",vec[i].golesMetidos);
            printf("\t %d",vec[i].partidosJugados);
            printf("\t %.2f", vec[i].promedioDeGoles);
            printf("\n");
        }

        todoOk=1;
    }
    return todoOk;
}

float funcionPromedioDeGoles(int goles, int partidosJugados)
{
    float promedio;

    promedio=(float)goles/partidosJugados;

    return promedio;
}
