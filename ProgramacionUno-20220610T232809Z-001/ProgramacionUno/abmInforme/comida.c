#include "comida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionComida(eComida comidas[], int tamComida, int idComida,  char descripcionComida[])
{
    int todoOk=0;
    if(comidas!=NULL && tamComida>0 && descripcionComida!=NULL)
    {

        for(int i=0; i<tamComida; i++)
        {

            if(comidas[i].idDeComida==idComida)
            {
                strcpy(descripcionComida, comidas[i].descripcion);
                break;
            }

        }
        todoOk=1;

    }
    return todoOk;
}

int mostrarComidas(eComida comidas[], int tamComida)
{
    int todoOk=0;

    if(comidas!=NULL && tamComida>0)
    {

        printf(" *** Localidades ***\n\n");
        printf("  Id\tDescripcion\n");

        for(int i=0; i<tamComida; i++)
        {
            printf("%d\t %10s\n", comidas[i].idDeComida, comidas[i].descripcion);
        }
        todoOk=1;
    }
    return todoOk;
}
