#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


int cargarDescripcionTipo(eTipo ArrayTipos[], int tamTipo, int idTipo, char descripcionTipo[])
{
    int todoOk=0;
    if(ArrayTipos!=NULL && tamTipo>0 && descripcionTipo!=NULL)
    {
        for(int i=0; i<tamTipo; i++)
        {
            if(ArrayTipos[i].id==idTipo)
            {
                strcpy(descripcionTipo, ArrayTipos[i].descripcionTipo);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;


}

int mostrarTipos(eTipo ArrayTipos[], int tamTipos)
{
    int todoOk=0;
    if(ArrayTipos!=NULL && tamTipos>0)
    {
        printf("\nTipos:\n");
        printf("Id        Tipos:\n");
        for(int i=0; i<tamTipos; i++)
        {
            printf("%d      %-10s\n", ArrayTipos[i].id, ArrayTipos[i].descripcionTipo);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}
