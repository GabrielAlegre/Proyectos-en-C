#include "miBibliotecaAlegre.h"
#include <stdio.h>
#include <stdlib.h>

float promediar(int a, int b)
{
    float respuesta;

    respuesta= (float)(a + b) / 2;

    return respuesta;
}


float dividir(int a, int b)
{
    float respuesta;

    respuesta= (a / b);

    return respuesta;
}

void saludo()
{
    printf("Hola\n");
}

void brindar()
{
    printf("Chin chin\n");
}

void despedir()
{
    printf("Chau, nos vemos\n");
}


int menu()
{
    int opcion;


    system("cls");
    printf("Menu de opciones:\n");
    printf("1. Saludar \n");
    printf("2. Brindar\n");
    printf("3. Despedir \n");
    printf("4. salir \n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

