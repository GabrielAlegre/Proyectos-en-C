#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"
#include "color.h"
#include "tipo.h"
#include "bibliotecaDeValidaciones.h"

int inicializarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab)
{
    int todoOk=0;

    if(arrayDeTrabajos!=NULL && tamTrab>0)
    {
        for(int i=0; i<tamTrab; i++)
        {
            arrayDeTrabajos[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab)
{
    int indiceLibre=-1;

    if(arrayDeTrabajos!=NULL && tamTrab>0)
    {
        for(int i=0; i<tamTrab; i++)
        {
            if(arrayDeTrabajos[i].isEmpty)
            {
                indiceLibre=i;
                break;//xq solo necesitamos el PRIMER indice que encontremos libre una vez encontrado no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}


int altaDeTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab, eBicicleta bicis[], int tamBici, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, int* pIdTrabajo)
{

    int todoOk=0;
    int indiceLibre;
    eTrabajo auxTrabajo;

    if(arrayDeTrabajos!=NULL && tamTrab>0 && bicis!=NULL && tamBici>0 && servicios!=NULL && tamServ>0 && pIdTrabajo!=NULL && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        indiceLibre=buscarLibreTrabajo(arrayDeTrabajos, tamTrab);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            mostrarBicicletras(bicis, tamBici, tipos, tamTipos, colores, tamColores);

            printf("\n--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de Trabajo   ***             \n");
            printf("--------------------------------------------------------------------------------------\n\n");

            auxTrabajo.idTrabajo= *pIdTrabajo;
            (*pIdTrabajo)++;

            printf("Ingrese el id del tipo de la bicicleta: ");
            scanf("%d", &auxTrabajo.idBici);
            while(buscarBicicletaPorId(bicis, tamBici, auxTrabajo.idBici)<0)
            {
                printf("Id invalido, reingrese el id del tipo de la bicicleta: ");
                scanf("%d", &auxTrabajo.idBici);
            }

            mostrarServicios(servicios, tamServ);
            validarEntero(&auxTrabajo.idServicio, "Ingrese el id del color de la bicicleta: ", "Error. Ingrese el id del color de la bicicleta: ", 20000, 20003);

            validarFecha(&auxTrabajo.fecha);

            auxTrabajo.isEmpty=0;

            arrayDeTrabajos[indiceLibre]=auxTrabajo;

            printf("\nExcelente. Se realizo correctamente la alta del trabajo: \n");

            printf("ID TRABAJO  |                    BICICLETA                       |   SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
            printf("            |  Id\tMarca      Tipo       Color\t Rodado  |\n");
            mostrarUnTrabajo(arrayDeTrabajos[indiceLibre], bicis, tamBici, servicios, tamServ, tipos, tamTipos, colores, tamColores);

        }
        todoOk=1;
    }
    return todoOk;
}

void mostrarUnTrabajo(eTrabajo unTrabajo, eBicicleta bicis[], int tamBici, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    char descripcionServicio[20];
    char descripcionTipo[20];
    char descripcionColor[20];
    int indiceBiciAMostrar;
    int indiceServicioAMostrar;


    if(bicis!=NULL && tamBici>0 && servicios!=NULL && tamServ>0&& tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        indiceBiciAMostrar=buscarBicicletaPorId(bicis, tamBici, unTrabajo.idBici);
        indiceServicioAMostrar=buscarServicioPorId(servicios, tamServ, unTrabajo.idServicio);
        cargarDescripcionServicio(servicios, tamServ, unTrabajo.idServicio, descripcionServicio);
        cargarDescripcionColor(colores, tamColores, bicis[indiceBiciAMostrar].idColor, descripcionColor);
        cargarDescripcionTipo(tipos, tamTipos, bicis[indiceBiciAMostrar].idTipo, descripcionTipo);

        printf("%d           |  \t%d      %-10s  %-10s  %-10s %.2f  |    %-10s   %d              %02d/%02d/%d\n",
        unTrabajo.idTrabajo,
        bicis[indiceBiciAMostrar].id,
        bicis[indiceBiciAMostrar].marca,
        descripcionTipo,
        descripcionColor,
        bicis[indiceBiciAMostrar].rodado,
        descripcionServicio,
        servicios[indiceServicioAMostrar].precio,
        unTrabajo.fecha.dia,
        unTrabajo.fecha.mes,
        unTrabajo.fecha.anio);
    }
}

int mostrarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab, eBicicleta bicis[], int tamBici, eServicio servicios[],int tamServ, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int todoOk=0;

    if(arrayDeTrabajos!=NULL && tamTrab>0 && bicis!=NULL && tamBici>0 && servicios!=NULL && tamServ>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Trabajos   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("ID servicio |                    BICICLETA                       |   SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
        printf("            |  Id\tMarca      Tipo       Color\t Rodado  |\n");

        for(int i=0; i<tamTrab; i++)
        {
            if(arrayDeTrabajos[i].isEmpty==0)
            {
                mostrarUnTrabajo(arrayDeTrabajos[i], bicis, tamBici, servicios, tamServ, tipos, tamTipos, colores, tamColores);
            }
        }
        todoOk=1;
    }
    return todoOk;
}




