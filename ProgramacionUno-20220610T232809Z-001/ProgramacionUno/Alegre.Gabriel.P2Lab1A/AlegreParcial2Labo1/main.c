#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "LinkedList.h"
#include "controller.h"

int main()
{
    srand(time(NULL));
    char salir='n';

    char path[40];
    LinkedList* listaDePelis = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                controller_cargarArchivo(listaDePelis);

                break;

            case 2:

                controller_listarPelis(listaDePelis);

                break;

            case 3:

                controller_mapPeli(listaDePelis);

                break;

            case 4:

                controller_filterPeliGenero(listaDePelis);


                break;

            case 5:

                controller_filterPeliGenero(listaDePelis);

                break;

            case 6:

                printf("Ingrese el nombre del archivo que quiere guardar: ");
                fflush(stdin);
                gets(path);

                controller_guardarListaTexto(path, listaDePelis);

                break;

            case 7:


                validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');

                if(salir=='s')
                {

                    ll_deleteLinkedList(listaDePelis);
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
