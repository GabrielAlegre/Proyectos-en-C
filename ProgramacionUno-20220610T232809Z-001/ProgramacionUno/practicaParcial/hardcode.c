#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcode.h"
char marca[8][20]={
    "Olmos",
    "Piolita",
    "Caster",
    "Frankers",
    "Xenox",
    "Kylem",
    "Aliste",
    "Zartp"
};


int Idtipo[8]={1000, 1001, 1000, 1003, 1003, 1002, 1001, 1002};

int color[8]={5004, 5001, 5000, 5003, 5004, 5002, 5001, 5002};

float rodado[8]={26, 27.5, 20, 26, 27.5, 26, 20, 29};


int harcodearBicis(eBicicleta arrayBicis[], int tamBici, int cantidadACargar, int* pIdBici)
{
    int contador=-1;

    if(arrayBicis!=NULL && tamBici>0 && cantidadACargar>=0 && cantidadACargar<=tamBici && pIdBici!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            arrayBicis[i].id= *pIdBici;
            (*pIdBici)++;
            strcpy(arrayBicis[i].marca, marca[i]);
            arrayBicis[i].idTipo=Idtipo[i];
            arrayBicis[i].idColor=color[i];
            arrayBicis[i].rodado=rodado[i];
            arrayBicis[i].isEmpty=0;
            contador++;
        }
        //*pBanderaBici=1;
    }
    return contador;
}
