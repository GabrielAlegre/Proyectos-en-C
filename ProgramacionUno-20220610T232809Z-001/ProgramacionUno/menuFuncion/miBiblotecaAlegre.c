#include "miBiblotecaAlegre.h"
#include <stdio.h>
#include <stdlib.h>



void mostrarElMensaje(char mensaje[])
{
    printf("%s\n",mensaje);
}

void saludar()
{
    printf("Hola \n");
}

void brindar()
{
    printf("Chin Chin \n");
}

void despedir()
{
    printf("Chau nos vemos \n");
}

int menu()
{
    int opcion;

    system("cls");
    printf("Menu de opciones:\n");
    printf("1. Saludar \n");
    printf("2. Brindar\n");
    printf("3. Despedirse \n");
    printf("4. Salir \n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int setFlag(int* bandera, int valor)
{
    int hayError=0;

    if(bandera!=NULL && valor<2)
    {
        *bandera=valor;
    }
    else
    {
        hayError=1;
    }

    return hayError;

}






