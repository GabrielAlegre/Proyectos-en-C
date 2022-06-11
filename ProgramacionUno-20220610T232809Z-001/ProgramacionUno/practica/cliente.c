#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


int cargarNombreCliente(eCliente arrayClientes[], int tamCliente, int idCliente, char descripcionNombre[])
{
    int todoOk=0;
    if(arrayClientes!=NULL && tamCliente>0 && descripcionNombre!=NULL)
    {
        for(int i=0; i<tamCliente; i++)
        {
            if(arrayClientes[i].id==idCliente)
            {
                strcpy(descripcionNombre, arrayClientes[i].nombreCliente);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int inicializarClientes(eCliente arrayClientes[], int tamCliente)
{
    int todoOk=0;

    if(arrayClientes!=NULL && tamCliente>0)
    {
        for(int i=0; i<tamCliente; i++)
        {
            arrayClientes[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarIndiceLibre(eCliente arrayClientes[], int tamCliente)
{
    int indiceLibre=-1;

    if(arrayClientes!=NULL && tamCliente>0)
    {
        for(int i=0; i<tamCliente; i++)
        {
            if(arrayClientes[i].isEmpty)
            {
                indiceLibre=i;
                break;//xq solo necesitamos el PRIMER indice que encontremos libre una vez encontrado no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}

int altaCliente(eCliente arrayClientes[], int tamCliente, int* pIdCliente)
{
    int todoOk=0;
    int indiceLibre;
    eCliente auxCliente;

    if(arrayClientes!=NULL && tamCliente>0)
    {
        system("cls");
        indiceLibre=buscarIndiceLibre(arrayClientes, tamCliente);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de Clientes   ***             \n");
            printf("--------------------------------------------------------------------------------------\n");

            auxCliente.id= *pIdCliente;
            (*pIdCliente)++;

            validarCadena(auxCliente.nombreCliente, "Ingrese su nombre (Max 20 caracteres): ", "Error. Ingrese su nombre (Max 20 caracteres): ", 21);

            validarCaracter(&auxCliente.sexo, "Ingrese su sexo (f/m): ", "Error. Reingrese su sexo (f/m): ", 'f', 'm');

            auxCliente.isEmpty=0;

            arrayClientes[indiceLibre]=auxCliente;

            printf("\nExcelente. Se realizo correctamente la alta del cliente: \n");
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarUnCliente(eCliente unCliente, int tamCliente)
{
    int todoOk=0;

    if(tamCliente>0)
    {
        printf("%d\t%-15s  %-5c\n", unCliente.id, unCliente.nombreCliente, unCliente.sexo);

        todoOk=1;
    }
    return todoOk;
}

int mostrarClientes(eCliente arrayClientes[], int tamCliente)
{
    int todoOk=1;

    if(arrayClientes!=NULL && tamCliente>0)
    {
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de clientes   ***             \n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("Id\tNombre           Sexo\n");

        for(int i=0; i<tamCliente; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                mostrarUnCliente(arrayClientes[i], tamCliente);
            }
        }
        todoOk=1;
    }

    return todoOk;
}


int buscarClientePorId(eCliente arrayClientes[], int tamCliente, int idCliente)
{
    int indiceDeIdEncontrado=-1;
    if(arrayClientes!=NULL && tamCliente>0)
    {
        for(int i=0; i<tamCliente; i++)
        {
            if(arrayClientes[i].id==idCliente && arrayClientes[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}
