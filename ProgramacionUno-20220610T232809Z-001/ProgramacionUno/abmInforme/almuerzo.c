#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "funcionesParaIngresos.h"
int inicializarAlmuerzos(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo)
{
    int todoOk=0;

    if(arrayDeAlmuerzos!=NULL && tamAlmuerzo>0)
    {
        for(int i=0; i<tamAlmuerzo; i++)
        {
            arrayDeAlmuerzos[i].isEmpty=1;
        }

        todoOk=1;
    }
    return todoOk;
}

int buscarLibreAlmuerzo(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo)
{
    int indiceLibre=-1;

    if(arrayDeAlmuerzos!=NULL && tamAlmuerzo>0)
    {
        for(int i=0; i<tamAlmuerzo; i++)
        {
            if(arrayDeAlmuerzos[i].isEmpty==1)
            {
                indiceLibre=i;
                break;//break Porque solo necesitamos el PRIMER indice que encontremos vacio una vez que lo encontramos no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}

int altaAlmuerzo(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo, ePersona arrayPersonas[], int tamPer, eLocalidad arrayLocalidades[], int tamLoc, eComida arrayComidas[], int tamCom, int* pIdAlmuerzo)
{
    int todoOk=0;
    int indiceLibre;
    eAlmuerzo auxAlmuerzo;

    if(arrayPersonas!=NULL && tamPer>0 && pIdAlmuerzo!=NULL && arrayComidas!=NULL && tamCom>0 && arrayDeAlmuerzos!=NULL && tamAlmuerzo>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        system("cls");
        printf("        ***Alta Almuerzo***      \n");

        indiceLibre=buscarLibreAlmuerzo(arrayDeAlmuerzos, tamAlmuerzo);
        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxAlmuerzo.idDeAlmuerzo= *pIdAlmuerzo;
            (*pIdAlmuerzo)++;

            //Muestro personas y pido que elija una
            mostrarPersonas(arrayPersonas, tamPer, arrayLocalidades, tamLoc);
            validarEntero(&auxAlmuerzo.idPersona, "\nIngrese id de la persona: ", "Error. Id invalido, reingrese id: ", 1, 2100);

            //Muestro comidas y pido que elija una
            mostrarComidas(arrayComidas, tamCom);
            validarEntero(&auxAlmuerzo.idComida, "Ingrese su comida: ", "Error, su comida (1 a 5): ", 5000, 5004);

            printf("Ingrese fecha: ");
            scanf("%d/%d/%d", &auxAlmuerzo.fecha.dia, &auxAlmuerzo.fecha.mes, &auxAlmuerzo.fecha.anio);

            auxAlmuerzo.isEmpty=0;

            printf("\nExcelente. Se realizo correctamente la alta del almuerzo\n");
            arrayDeAlmuerzos[indiceLibre]=auxAlmuerzo;
            todoOk=1;
        }
    }
    return todoOk;
}

void mostrarUnAlmuerzo(eAlmuerzo unAlmuerzo, ePersona arrayPersonas[], int tamPer, eComida arrayComida[], int tamCom)
{
    char descripcionComida[20];
    char descripcionNombre[20];

    cargarDescripcionComida(arrayComida, tamCom, unAlmuerzo.idComida, descripcionComida);
    cargarDescripcionPersona(arrayPersonas, tamPer, unAlmuerzo.idPersona, descripcionNombre);

    printf("%d\t%10s\t%10s\t%2d/%2d/%2d\n",
           unAlmuerzo.idDeAlmuerzo,
           descripcionNombre,
           descripcionComida,
           unAlmuerzo.fecha.dia,
           unAlmuerzo.fecha.mes,
           unAlmuerzo.fecha.anio);
}

int mostrarAlmuerzos(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo, ePersona arrayPersonas[], int tamPer, eLocalidad arrayLocalidades[], int tamLoc, eComida arrayComidas[], int tamCom)
{
    int todoOk=0;
    int flag=1;

    if(arrayPersonas!=NULL && tamPer>0 && arrayComidas!=NULL && tamCom>0 && arrayDeAlmuerzos!=NULL && tamAlmuerzo>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        system("cls");

        printf("    ***Listado de Almuerzos***   \n");
        printf("id\tNombre\tComida\tFecha\n");

        for(int i=0; i<tamAlmuerzo; i++)
        {
            if(arrayDeAlmuerzos[i].isEmpty==0)
            {
                mostrarUnAlmuerzo(arrayDeAlmuerzos[i], arrayPersonas, tamPer, arrayComidas, tamCom);
                flag=0;
            }
        }
        if(flag==1)
        {
            printf("No hay nada almuerzos para mostrar\n");
        }
        todoOk=1;
    }
    return todoOk;
}
