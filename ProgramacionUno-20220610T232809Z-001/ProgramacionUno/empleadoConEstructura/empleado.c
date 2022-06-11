#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"


int mostrarUnEmpleado (eEmpleado* unEmpleado)
{
    int todoOk=0;

    if(unEmpleado!=NULL)
    {
        printf("%d  %s  %s  %c  %2.f", unEmpleado->id, unEmpleado->nombre, unEmpleado->apellido, unEmpleado->sexo, unEmpleado->sueldo);
        todoOk=1;
    }

    return todoOk;
}

eEmpleado* new_Empleado()
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = (eEmpleado*) malloc(sizeof (eEmpleado));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id=0;
        strcpy(nuevoEmpleado->nombre, "-");
        strcpy(nuevoEmpleado->apellido, "-");
        nuevoEmpleado->sexo='i';
        nuevoEmpleado->sueldo=0;
    }

    return nuevoEmpleado;
}

eEmpleado* new_EmpleadoParam(int id, char nombre[], char apellido[], char sexo, float sueldo)
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = new_Empleado();
    if(nuevoEmpleado != NULL)
    {
        if(!(empleadoSetId(nuevoEmpleado, id)
        && empleadoSetNombre(nuevoEmpleado, nombre)
        && empleadoSetApellido(nuevoEmpleado, apellido)
        && empleadoSetSexo(nuevoEmpleado, sexo)
        && empleadoSetSueldo(nuevoEmpleado, sueldo)))
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

//Setters

int empleadoSetId(eEmpleado* unEmpleado, int id)
{
    int todoOk=0;
    if(unEmpleado != NULL && id>0 && id<101)
    {
        unEmpleado->id = id;
        todoOk=1;
    }
    return todoOk;
}

int empleadoSetNombre(eEmpleado* unEmpleado, char nombre[])
{
    int todoOk=0;
    if(unEmpleado != NULL && nombre!=NULL)
    {
        if(strlen(nombre)<20 && strlen(nombre)>2)
        {
            strcpy(unEmpleado->nombre, nombre);
            todoOk=1;
        }

    }
    return todoOk;
}

int empleadoSetApellido(eEmpleado* unEmpleado, char apellido[])
{
    int todoOk=0;
    if(unEmpleado != NULL && apellido!=NULL)
    {
        if(strlen(apellido)<20 && strlen(apellido)>2)
        {
            strcpy(unEmpleado->apellido, apellido);
            todoOk=1;
        }
    }
    return todoOk;
}

int empleadoSetSexo(eEmpleado* unEmpleado, char sexo)
{
    int todoOk=0;
    if(unEmpleado != NULL && (sexo == 'f' || sexo == 'm'))
    {
        unEmpleado->sexo = sexo;
        todoOk=1;
    }
    return todoOk;
}

int empleadoSetSueldo(eEmpleado* unEmpleado, float sueldo)
{
    int todoOk=0;
    if(unEmpleado != NULL && sueldo>=50000 && sueldo <=200000)
    {
        unEmpleado->sueldo = sueldo;
        todoOk=1;
    }
    return todoOk;
}

//Getters

int empleadoGetId(eEmpleado* unEmpleado, int* pId)
{
    int todoOk=0;
    if(unEmpleado != NULL && pId!=NULL)
    {
        *pId = unEmpleado->id;
        todoOk=1;
    }
    return todoOk;
}
int empleadoGetNombre(eEmpleado* unEmpleado, char nombre[])
{
    int todoOk=0;
    if(unEmpleado != NULL && nombre!=NULL)
    {
        strcpy(unEmpleado->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}

int empleadoGetApellido(eEmpleado* unEmpleado, char apellido[])
{
    int todoOk=0;
    if(unEmpleado != NULL && apellido!=NULL)
    {
        strcpy(unEmpleado->apellido, apellido);
        todoOk=1;
    }
    return todoOk;
}


int empleadoGetSexo(eEmpleado* unEmpleado, char* pSexo)
{
    int todoOk=0;
    if(unEmpleado != NULL && pSexo!=NULL)
    {
        *pSexo = unEmpleado->sexo;
        todoOk=1;
    }
    return todoOk;
}

int empleadoGetSueldo(eEmpleado* unEmpleado, float* pSueldo)
{
    int todoOk=0;
    if(unEmpleado != NULL && pSueldo!=NULL)
    {
        *pSueldo = unEmpleado->sueldo;
        todoOk=1;
    }
    return todoOk;
}

void destroyEmpleado(eEmpleado* unEmpledo)
{
    free(unEmpledo);
}
