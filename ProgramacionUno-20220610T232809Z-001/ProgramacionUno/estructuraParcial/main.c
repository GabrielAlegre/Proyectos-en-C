#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"


/** \brief Funcion que muestra el menu con las opciones para realizar una modificion .
 *
 * \return char retorna la opcion elegida por el usuario.
 *
 */
char menuDeModificacion();

/** \brief Funcion que muestra el menu del ABM con sus respectivas opciones.
 *
 * \return char retorna la opcion elegida por el usuario.
 *
 */
char menu();

int main()
{
    char salir='n';
    int nextId=1;
    int hay=0;

    //eBicicleta listaDeBicicletas[TAM_BICI]; solo las que se dan de alta hay que declararlas como array
    //eTrabajo listaDeTrabajos[TAM_TRAB];

    //Hardcodeo de estructuras

    //inicializar

    //harcodearBicis(listaDeBicicletas, TAM_BICI, 8, &nextIdBici);
    //hayUnaBici=1;

    do{
        switch(menu())
        {
            case 'A':
                //Alta
                hay=1;
                break;

            case 'B':
                //Baja
                break;

            case 'C':
                //Modificar
                break;

            case 'D':
                break;

            case 'E':
                break;

            case 'F':
                validarCaracter(&salir, "Esta seguro que desea salir s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
                break;

            default:
                printf("Opcion invalida!!!\n");
                break;
        }
      }while(salir=='n');


    return 0;
}

char menu()
{
    char opcion;
    system("cls");

    printf("                *** MENU  ***             \n");
    printf("-----------------------------------------------------------------------\n");
    printf("A- ALTA AUTO\n");
    printf("B- MODIFICAR AUTO\n");
    printf("C- BAJA AUTO\n");
    printf("D- LISTAR AUTOS\n");
    printf("E- LISTAR MARCAS\n");
    printf("F- LISTAR COLORES\n");
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

char menuDeModificacion()
{
    char opcion;
    printf("\nQue le desea modificar a la XXXX: \n");
    printf("A- Modificar \n");
    printf("B- Modificar \n");
    printf("C- Cancelar Modificacion\n");

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);

    return opcion;
}
