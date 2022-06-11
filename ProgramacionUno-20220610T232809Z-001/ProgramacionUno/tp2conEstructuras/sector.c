#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"



int cargarDescripcionSector(eSector sectores[], int tamSec, int idSector, char descSector[])
{
    int todoOk=0;
    if(sectores!=NULL && tamSec>0 && descSector!=NULL)
    {
        for(int i=0; i<tamSec; i++)
        {
            if(sectores[i].idSector==idSector)
            {
                strcpy(descSector, sectores[i].descripcionSector);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarSectores(eSector sectores[], int tamSec)
{
    int todoOk=0;
    if(sectores!=NULL && tamSec>0)
    {
        printf("Sectores:\n");
        printf("    Id      Sector:\n");
        for(int i=0; i<tamSec; i++)
        {
            printf("    %d      %s\n", sectores[i].idSector, sectores[i].descripcionSector);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}
