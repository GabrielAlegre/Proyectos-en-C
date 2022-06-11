/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int menu()
{
    int opcion;
    system("cls");
    printf("--------------------------------------------------------------------------------------\n");
    printf("                      *** Menu Employee ***            \n");
    printf("--------------------------------------------------------------------------------------\n\n");
    printf("1- Cantidad de jugadores disponibles\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3- Alta de empleados\n");
    printf("4- Modificar datos de empleado\n");
    printf("5- Baja de empleado\n");
    printf("6- Listar empleados\n");
    printf("7- Ordenar Empleados\n");
    printf("8- Guardar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("9- Guardar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("10- Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int main(void)
{



	setbuf(stdout, NULL);

	char salir='n';

    LinkedList* lista = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                printf("La cantidad de jugadores son: %d\n y son los siguientes: ", ll_len(lista));

                break;

            case 2:
                printf("Entre al case 2\n");

                break;

            case 3:
                printf("Entre al case 3\n");

                break;

            case 4:
                printf("Entre al case 4\n");


                break;

            case 5:
                printf("Entre al case 5\n");

                break;

            case 6:
                printf("Entre al case 6\n");

                break;

            case 7:
                printf("Entre al case 7\n");

                break;

            case 8:
                printf("Entre al case 8\n");

                break;

            case 9:
                printf("Entre al case 9\n");

                break;

            case 10:
                printf("Entre al case 10\n");


                break;

            default:
			printf("Opcion invalida!\n");
				break;

        }
        system("pause");

    }while(salir=='n');


































































    /*
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add

    startTesting(6);  // ll_get

    startTesting(7);  // ll_set

    startTesting(8);  // ll_remove

    startTesting(9);  // ll_clear

    startTesting(10); // ll_deleteLinkedList

    startTesting(11); // ll_indexOf

    startTesting(12); // ll_isEmpty

    startTesting(13); // ll_push

    startTesting(14); // ll_pop

    startTesting(15); // ll_contains

    startTesting(16); // ll_containsAll

    startTesting(17); // ll_subList

    startTesting(18); // ll_clone

    startTesting(19); // ll_sort
    */

    return 0;
}





























