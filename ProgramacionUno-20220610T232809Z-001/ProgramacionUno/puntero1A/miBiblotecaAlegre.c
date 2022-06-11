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

char ingresarLetra(char mensaje[])
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

int menu()
{
    int opcion;


    system("cls");
    printf("Menu de opciones:\n");
    printf("1. Ingresar 1er operando \n");
    printf("2. Ingresar 2do operando\n");
    printf("3. Calcular todas las operaciones \n");
    printf("4. Informar resultados \n");
    printf("5. salir \n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


void operaciones(float* a, float* b, float* suma, float* resta, float* division, int* factorialDeA, int* factorialDeB, float* multiplicacion)
{
    *suma= (float)*a+*b;
    *resta= (float)*a-*b;
    *multiplicacion= (float)*a * *b;
    *division= (float)*a / *b;

	int i;

	for(i=1; i<=*a; i++)
	{
		*factorialDeA*=i;
	}

    for(i=1; i<=*b; i++)
	{
		*factorialDeB*=i;
	}

    mostrar("el resultado de la suma es: ", *suma);
    mostrar("el resultado de la resta es: ", *resta);
    mostrar("el resultado de la division es: ", *division);
    mostrar("el resultado de la multiplicacion es: ", *multiplicacion);
    mostrar("el factorial de A es es: ", *factorialDeA);
    mostrar("el factorial de B es es:  ", *factorialDeB);
}


