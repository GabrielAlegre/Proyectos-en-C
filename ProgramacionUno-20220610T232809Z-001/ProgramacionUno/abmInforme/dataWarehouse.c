#include <string.h>
#include "dataWarehouse.h"
char nombres[10][20]={
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"

};

char sexos[10]={'m', 'm', 'f', 'm', 'f', 'f', 'f', 'm', 'm', 'f',};

int edades[10]={23, 27, 27, 32, 45, 29, 39, 23, 28, 27};

float alturas[10]= {1.65, 1.67, 1.90, 1.78, 1.75, 1.70, 1.65, 1.73, 1.69, 1.78};

int idLocalidades[10]={1001, 1002, 1000, 1001, 1001, 1003, 1004, 1002, 1004, 1001};


int harcodearPersonas(ePersona lista[], int tam, int cantidadACargar, int *pId)
{
    int contador=-1;
    int nextId=2000;

    if(lista!=NULL && tam>0 && cantidadACargar>=0 && cantidadACargar<=tam && pId!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            lista[i].id= nextId;
            nextId++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo=sexos[i];
            lista[i].altura=alturas[i];
            lista[i].edad=edades[i];
            lista[i].idLocalidad=idLocalidades[i];
            lista[i].isEmpty=0;

            contador++;
        }
    }
    return contador;
}
