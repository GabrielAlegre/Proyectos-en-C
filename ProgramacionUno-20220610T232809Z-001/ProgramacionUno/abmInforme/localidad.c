
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"

int cargarDescripcionLocalidad(eLocalidad arrayLocalidades[], int tam, int idLocalidad, char descripcion[])
{
    int todoOk=0;
    if(arrayLocalidades!=NULL && tam>0 && descripcion!=NULL)
    {

        for(int i=0; i<tam; i++)
        {

            if(arrayLocalidades[i].id==idLocalidad)
            {
                strcpy(descripcion, arrayLocalidades[i].descripcion);
                break;
            }

        }
        todoOk=1;

    }
    return todoOk;
}

int mostrarLocalidades(eLocalidad localidades[], int tam)
{
    int todoOk=0;

    if(localidades!=NULL && tam>0)
    {

        printf(" *** Localidades ***\n\n");
        printf("  Id\tDescripcion\n");

        for(int i=0; i<tam; i++)
        {
            printf("%d\t %10s\n", localidades[i].id, localidades[i].descripcion);
        }
        todoOk=1;
    }
    return todoOk;
}

int validadLocalidad(eLocalidad localidades[], int tam, int idAvalidar)
{
    int todoOk=0;

    if(localidades!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(localidades[i].id==idAvalidar)
            {
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}


/*
int validadLocalidad(eLocalidad localidades[], int tam, int idAvalidar)
{
    int todoOk=0;

    if(localidades!=NULL && tam>0)
    {
        if(localidades[0].id<=idAvalidar && localidades[tam-1].id>=idAvalidar)
        {
            todoOk=1;
        }

    }

    return todoOk;
}
*/
