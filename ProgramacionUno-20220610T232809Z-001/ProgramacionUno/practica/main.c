#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "input.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "hardcodeo.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

#define TAM_COLOR 5
#define TAM_MARCA 5
#define TAM_AUTO 20
#define TAM_SERVICIO 4
#define TAM_TRAB 20
#define TAM_CLIENTES 20


/** \brief Funcion que muestra el menu del ABM con sus respectivas opciones.
 *
 * \return char retorna la opcion elegida por el usuario.
 *
 */
char menu();

int main()
{
    char salir='n';
    int nextIdAutos=1;
    int nextIdTrabajo=1;
    int nextIdCliente=1;
    int hayUnAuto=0;
    int hayUnTrabajo=0;
    int hayUnCliente=0;

    eAuto listaDeAutos[TAM_AUTO];
    eTrabajo listaDeTrabajos[TAM_TRAB];

    eCliente listaDeClientes[TAM_CLIENTES];

    eColor colores[TAM_COLOR]={

    {5000, "Negro"},
    {5001, "Blanco"},
    {5002, "Rojo"},
    {5003, "Gris"},
    {5004, "Azul"}
    };

    eMarca marcas[TAM_MARCA]={

    {1000, "Renault"},
    {1001, "Ford"},
    {1002, "Fiat"},
    {1003, "Chevrolet"},
    {1004, "Peugeot"}
    };

    eServicio servicios[TAM_SERVICIO]={

        {20000, "Lavado", 450},
        {20001, "Pulido", 500},
        {20002, "Encerado", 600},
        {20003, "Completo", 900}
    };

    if(inicializarAutos(listaDeAutos, TAM_AUTO)==-1)
    {
        printf("Ocurrio un problema al inicializar los autos");
    }

    if(inicializarTrabajos(listaDeTrabajos, TAM_TRAB)==-1)
    {
        printf("Ocurrio un problema al inicializar los trabajos");
    }

    if(inicializarClientes(listaDeClientes, TAM_CLIENTES)==-1)
    {
        printf("Ocurrio un problema al inicializar los trabajos");
    }

    harcodearAutos(listaDeAutos, TAM_AUTO, 10, &nextIdAutos);
    hayUnAuto=1;

    hardcodearTrabajos(listaDeTrabajos, TAM_TRAB, 10, &nextIdTrabajo);
    hayUnTrabajo=1;

    hardcodearClientes(listaDeClientes, TAM_CLIENTES, &nextIdCliente, 11);
    hayUnCliente=1;

    do{
        switch(menu())
        {
            case 'A':
                if(hayUnCliente)
                {
                    altaAuto(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR, listaDeClientes, TAM_CLIENTES,&nextIdAutos);
                    hayUnAuto=1;
                }
                else
                {
                    printf("\nNo se puede dar de alta un auto si no hay un cliente\n");
                }
                break;

            case 'B':
                if(hayUnAuto)
                {
                    modificarAuto(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR, listaDeClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("No hay ningun auto para modificar, opcion A para dar de alta e ingresar un auto\n");
                }
                break;

            case 'C':
                if(hayUnAuto)
                {
                    bajaAuto(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR, listaDeClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("No hay ningun auto para dar de baja, opcion A para dar de alta e ingresar un auto\n");
                }
                buscarSiHayUnAuto(listaDeAutos, TAM_AUTO, &hayUnAuto);
                break;

            case 'D':
                if(hayUnAuto)
                {
                    ordenarAutos(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR);
                    mostrarAutos(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR, listaDeClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("No hay ningun auto para listar, opcion A para dar de alta e ingresar un auto\n");
                }
                break;

            case 'E':
                system("cls");
                mostrarMarcas(marcas, TAM_MARCA);
                break;

            case 'F':
                system("cls");
                mostrarColor(colores, TAM_COLOR);
                break;
            case 'G':
                system("cls");
                mostrarServicios(servicios, TAM_SERVICIO);
                break;
            case 'H':
                if(hayUnAuto)
                {
                    altaDeTrabajo(listaDeTrabajos, TAM_TRAB, listaDeAutos, TAM_AUTO, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR, listaDeClientes, TAM_CLIENTES, &nextIdTrabajo);
                    hayUnTrabajo=1;
                }
                else
                {
                    printf("No hay ningun auto de alta, por lo tanto no hay trabajos activos.\n");
                }
                break;
            case 'I':
                if(hayUnAuto && hayUnTrabajo)
                {
                    mostrarTrabajos(listaDeTrabajos, TAM_TRAB, listaDeAutos, TAM_AUTO, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR);
                }
                else
                {
                     printf("No hay trabajos para elistar\n");
                }
                break;
            case 'J':
                if(hayUnAuto && hayUnTrabajo)
                {
                    menuInformes(listaDeTrabajos, TAM_TRAB, listaDeAutos, TAM_AUTO, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR, listaDeClientes, TAM_CLIENTES);
                }
                break;

            case 'K':
                altaCliente(listaDeClientes, TAM_CLIENTES, &nextIdCliente);
                hayUnCliente=1;
                break;

            case 'L':
                if(hayUnCliente)
                {
                    system("cls");
                    mostrarClientes(listaDeClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("\nNo hay clientes para mostrar, opcion 'K' para dar de alta uno\n");
                }
                break;

            case 'M':
                validarCaracter(&salir, "Esta seguro que desea salir s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
                break;

            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        system("pause");

      }while(salir=='n');

    return 0;
}

