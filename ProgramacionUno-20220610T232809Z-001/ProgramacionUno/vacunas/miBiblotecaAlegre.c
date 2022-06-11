#include "miBiblotecaAlegre.h"
#include <stdio.h>
#include <ctype.h>

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

float ingresarFlotante(char mensaje[])
{
    float numeroIngresado;

    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}

char funcionLetra(char mensaje[])
{
    char letraIngresada;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c", &letraIngresada);
    letraIngresada=toupper(letraIngresada);

    return letraIngresada;
}

