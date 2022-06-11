#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "pais.h"
#include "input.h"
#include "parser.h"

//cargar es leer lo que contiene el archivo en la lista
//Guardar es escribir lo que contiene la lista en el archivo
int main()
{
    srand(time(NULL));
    char salir='n';
    int banderaPaisesExitosos=0;
    int banderaPaisesEnElHorno=0;
    int seCargoUnArchivo=0;
    int losPaisesTienenEstadisticas=0;
    //int asignoEstadistica=0;

    LinkedList* listaPaises = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                if(controller_cargarArchivo(listaPaises, banderaPaisesExitosos, banderaPaisesEnElHorno))
                {
                    seCargoUnArchivo=1;
                    losPaisesTienenEstadisticas = controller_VerificarSiLosPaisesTienenEstadisticas(listaPaises);
                }
                break;

            case 2:
                if(seCargoUnArchivo)
                {
                    system("cls");
                    controller_listarPaises(listaPaises);
                }
                else
                {
                    printf("No hay nada que listar, cargue un archivo\n");
                }
                break;

            case 3:
                if(seCargoUnArchivo)
                {
                    controller_mapPais(listaPaises);
                    losPaisesTienenEstadisticas=1;
                }
                else
                {
                    printf("Error. Primero debe cargar una lista\n");
                }
                break;

            case 4:
                if(losPaisesTienenEstadisticas)
                {
                    controller_filterPaisesExitosos(listaPaises);
                    banderaPaisesExitosos=1;
                }
                else
                {
                    printf("Para poder filtrar el archivo primero debe cargarlo y tener estadisticas asignadas\n");
                }

                break;

            case 5:
                if(losPaisesTienenEstadisticas)
                {
                    controller_filterPaisesEnElHorno(listaPaises);
                    banderaPaisesEnElHorno=1;
                }
                else
                {
                    printf("Para poder filtrar el archivo primero debe cargarlo y tener estadisticas asignadas\n");
                }
                break;

            case 6:
                if(losPaisesTienenEstadisticas)
                {
                    controller_sortEmployee(listaPaises);
                }
                else
                {
                    printf("Para poder ordenar una lista primero debe cargarlo un archivo\n");
                }
                break;

            case 7:
                if(losPaisesTienenEstadisticas)
                {
                    controller_masCastigados(listaPaises);
                }
                else
                {
                    printf("Error. Primero debe cargar una lista\n");
                }
                break;
            case 8:

                validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
                if(salir=='s')
                {

                    ll_deleteLinkedList(listaPaises);
                    printf("Salida exitosa!\n");
                }
                else
                {
                    printf("Se ha cancelado la salida\n");
                }
                break;

            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        system("pause");

      }while(salir=='n');

    return 0;
}

