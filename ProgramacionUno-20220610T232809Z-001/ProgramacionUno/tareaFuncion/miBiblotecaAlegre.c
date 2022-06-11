#include "miBiblotecaAlegre.h"
#include <stdio.h>

float promediar(int a, int b)
{
    float respuesta;

    respuesta= (float)(a + b) / 2;

    return respuesta;
}


float dividir(int a, int b)
{
    float respuesta;

    respuesta= (float)a/b;

    return respuesta;
}


int ingresarEntero(char mensaje[])
{
    int numeroIngresado;

    printf("%s",mensaje);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}

float ingresarFloat(char mensaje[])
{
    float numeroIngresado;

    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}

char letra(char mensaje[])
{
    char letraIngresada;

    printf("%s",mensaje);
    scanf("%c",&letraIngresada);

    return letraIngresada;
}

void mostrar(char mensaje[], int mostrarVariable)
{
    printf("%s%d\n",mensaje, mostrarVariable);
}

void mostrarMensaje(char mensaje[])
{
    printf("%s\n",mensaje);
}

