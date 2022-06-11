#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "color.h"
#include "servicio.h"
#include "tipo.h"
#include "bibliotecaDeValidaciones.h"
#include "fecha.h"
#include "hardcode.h"
#include "trabajo.h"
#include "bicicleta.h"
#define TAM_COLOR 5
#define TAM_TIPO 4
#define TAM_SERVICIO 4
#define TAM_BICI 30
#define TAM_TRAB 30


char menu();

int main()
{
    char salir='n';
    int nextIdBici=1;
    int nextIdTrabajo=1;
    int hayUnaBici=0;
    int hayUnTrabajo=0;

    eBicicleta listaDeBicicletas[TAM_BICI];
    eTrabajo listaDeTrabajos[TAM_TRAB];

    eTipo tipos[TAM_TIPO]={

        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };

    eColor colores[TAM_COLOR]={

        {5000, "Gris",},
        {5001, "Negro",},
        {5002, "Blanco"},
        {5003, "Azul"},
        {5004, "Rojo"}
    };

    eServicio servicios[TAM_SERVICIO]={

        {20000, "Limpieza", 250},
        {20001, "Parche", 300},
        {20002, "Centrado", 400},
        {20003, "Cadena", 350}
    };

    if(inicializarBicicletas(listaDeBicicletas, TAM_BICI)==-1)
    {
        printf("Ocurrio un problema al inicializar la bici");
    }

    if(inicializarTrabajos(listaDeTrabajos, TAM_TRAB)==-1)
    {
        printf("Ocurrio un problema al inicializar el trabajo");
    }

    harcodearBicis(listaDeBicicletas, TAM_BICI, 8, &nextIdBici);
    hayUnaBici=1;


    do{
        switch(menu())
        {
            case 'A':
                altaBicicleta(listaDeBicicletas, TAM_BICI, tipos, TAM_TIPO, colores, TAM_COLOR, &nextIdBici);
                hayUnaBici=1;
                break;

            case 'B':
                if(hayUnaBici)
                {
                    modificarBicicleta(listaDeBicicletas, TAM_BICI, tipos, TAM_TIPO, colores, TAM_COLOR);
                }
                else
                {
                    printf("No hay ninguna bicicleta para modificar, opcion 1 para dar de alta e ingresar una bicicleta\n");
                }
                break;

            case 'C':
                if(hayUnaBici)
                {
                    bajaBicicleta(listaDeBicicletas, TAM_BICI, tipos, TAM_TIPO, colores, TAM_COLOR);
                }
                else
                {
                    printf("No hay ninguna bicicleta para dar de baja, opcion 1 para dar de alta e ingresar una bicicleta\n");
                }
                buscarSiHayUnaBicicleta(listaDeBicicletas, TAM_BICI, &hayUnaBici);
                break;

            case 'D':
                if(hayUnaBici)
                {
                    ordenarBicicletas(listaDeBicicletas, TAM_BICI, tipos, TAM_TIPO, colores, TAM_COLOR);
                    mostrarBicicletras(listaDeBicicletas, TAM_BICI, tipos, TAM_TIPO, colores, TAM_COLOR);
                }
                else
                {
                    printf("No hay ninguna bicicleta para listar, opcion 1 para dar de alta e ingresar una bicicleta\n");
                }
                break;

            case 'E':
                mostrarTipos(tipos, TAM_TIPO);
                break;

            case 'F':
                mostrarColor(colores, TAM_COLOR);
                break;

            case 'G':
                mostrarServicios(servicios, TAM_SERVICIO);
                break;

            case 'H':
                if(hayUnaBici)
                {
                    altaDeTrabajo(listaDeTrabajos, TAM_TRAB, listaDeBicicletas, TAM_BICI,servicios,TAM_SERVICIO,tipos,TAM_TIPO, colores, TAM_COLOR,&nextIdTrabajo);
                    hayUnTrabajo=1;
                }
                else
                {
                    printf("No se puede realizar trabajos sin bicicletas de alta, opcion 1 para dar de alta e ingresar una bicicleta\n");
                }
                break;

            case 'I':
                if(hayUnaBici && hayUnTrabajo)
                {
                     mostrarTrabajos(listaDeTrabajos, TAM_TRAB, listaDeBicicletas, TAM_BICI,servicios,TAM_SERVICIO,tipos,TAM_TIPO, colores, TAM_COLOR);
                }
                else
                {
                    printf("No se puede listar trabajos sin bicicletas o trabajos de alta.\n");
                }
                break;

            case 'J':
                validarCaracter(&salir, "Esta seguro que desea salir s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
                break;

            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        system("pause");

    }while(salir=='n');

}

char menu()
{
    char opcion;
    system("cls");

    printf("                *** MENU BICICLETERIA ***             \n");
    printf("-----------------------------------------------------------------------\n");
    printf("A- ALTA BICICLETA\n");
    printf("B- MODIFICAR BICICLETA\n");
    printf("C- BAJA BICICLETA\n");
    printf("D- LISTAR BICICLETA\n");
    printf("E- LISTAR TIPO\n");
    printf("F- LISTAR COLOR\n");
    printf("G- LISTAR SERVICIOS\n");
    printf("H- ALTA TRABAJO\n");
    printf("I- LISTAR TRABAJO\n");
    printf("J- SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion=toupper(opcion);

    return opcion;
}
