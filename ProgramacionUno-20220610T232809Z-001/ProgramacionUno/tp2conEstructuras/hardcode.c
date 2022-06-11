#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcode.h"
char nombres[11][20]={
    "Agustin luca",
    "Luis Pedro",
    "Carlos luis",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia",
    "Alexander"

};

char Apellidos[11][20]={
    "Rossi",
    "Advinvula",
    "Izquierdoz",
    "Rojo",
    "Valentini",
    "Varela",
    "Almendra",
    "Molinas",
    "Zeballos",
    "Vazquez",
    "Moreno"

};

char sexo[11]={'m', 'm', 'm', 'm', 'f', 'f', 'f', 'm', 'm', 'f','m'};

float salario[11]= {97000, 149000, 37000, 17000, 7000, 7000, 130000, 87000, 87000, 37000, 55000};

int sectores[11]={2, 5, 3, 3, 2, 4, 5, 4, 4, 1,5};

int id[11]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11};


int harcodearPersonas(eEmployee lista [], int tam, int cantidadACargar, int *pId, int *pBanderaEmpleado)
{
    int contador=-1;

    if(lista!=NULL && tam>0 && cantidadACargar>=0 && cantidadACargar<=tam && pId!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            lista[i].id= *pId;
            (*pId)++;
            strcpy(lista[i].name, nombres[i]);
            strcpy(lista[i].lastName, Apellidos[i]);
            lista[i].sexo=sexo[i];
            lista[i].salary=salario[i];
            lista[i].sector=sectores[i];
            lista[i].id=id[i];
            lista[i].isEmpty=0;

            contador++;
        }
        *pBanderaEmpleado=1;
    }
    return contador;
}
