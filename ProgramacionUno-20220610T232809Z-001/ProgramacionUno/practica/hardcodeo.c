#include "hardcodeo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


///Autos
int IdMarca[10]={1000, 1001, 1004, 1003, 1003, 1004, 1001, 1002,1002,1004};

int color[10]={5004, 5001, 5000, 5003, 5004, 5002, 5001, 5002, 5000, 5001};

char caja[10]={'m', 'a', 'm', 'm', 'a', 'm', 'a', 'a', 'm', 'a'};

///Trabajos
int idAuto[10]={1,8,4,6,5,9,10,6,5,7};

int idServ[10]={20001,20003,20002,20001,20001,20003,20002,20003,20002,20003};

eFecha fecha[10]={
            {15,7,2021},
            {16,6,2019},
            {15,7,2021},
            {16,6,2019},
            {20,3,2021},
            {30,6,2020},
            {30,6,2020},
            {15,4,2020},
            {16,6,2019},
            {15,4,2020},
    };

///Clientes

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

char sexo[11]={'m', 'f', 'm', 'm', 'f', 'm', 'f', 'f', 'm', 'f', 'm'};

int idCliente[11]={1,8,4,6,5,9,10,6,5,7,2};

int harcodearAutos(eAuto arrayAutos[], int tamAuto, int cantidadACargar, int* pIdAuto)
{
    int contador=-1;

    if(arrayAutos!=NULL && tamAuto>0 && cantidadACargar>=0 && cantidadACargar<=tamAuto && pIdAuto!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            arrayAutos[i].id= *pIdAuto;
            (*pIdAuto)++;
            arrayAutos[i].idMarca=IdMarca[i];
            arrayAutos[i].idColor=color[i];
            arrayAutos[i].caja=caja[i];
            arrayAutos[i].idCliente=idCliente[i];
            arrayAutos[i].isEmpty=0;
            contador++;
        }
    }
    return contador;
}


int hardcodearTrabajos(eTrabajo trabajo[], int tamTrabajo, int cant, int* pIdTrabajo)
{
    int contador=-1;
    if(trabajo!=NULL && tamTrabajo>0 && cant>=0 && cant <=tamTrabajo && pIdTrabajo!=NULL)
    {
        contador=0;
        for(int i=0; i < cant; i++)
        {
            trabajo[i].idTrabajo= *pIdTrabajo;
            (*pIdTrabajo)++;
            trabajo[i].idAuto=idAuto[i];
            trabajo[i].idServicio=idServ[i];
            trabajo[i].fecha=fecha[i];
            trabajo[i].isEmpty=0;
            contador++;

        }
    }
    return contador;
}


int hardcodearClientes(eCliente clientes[], int tamClientes, int* pIdCliente, int cant)
{
    int contador=-1;
    if(clientes!=NULL && tamClientes>0 && pIdCliente!=NULL && cant>=0 && cant <=tamClientes)
    {
        contador=0;
        for(int i=0; i < cant; i++)
        {
            clientes[i].id= *pIdCliente;
            (*pIdCliente)++;
            strcpy(clientes[i].nombreCliente, nombres[i]);
            clientes[i].sexo=sexo[i];
            clientes[i].isEmpty=0;
            contador++;

        }
    }
    return contador;
}
