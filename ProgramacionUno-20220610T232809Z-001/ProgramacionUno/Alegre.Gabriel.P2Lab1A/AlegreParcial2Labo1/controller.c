
#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"
#include "peliculas.h"
#include "input.h"
#include "parser.h"

int controller_cargarArchivo(LinkedList* pArrayListaPelis)
{
	int todoOk=0;
	FILE* pArchivo;
	char nombreDelArchivo[50];

	if(pArrayListaPelis!=NULL)
	{

        printf("\nIngrese el nombre del archivo a leer\nSugerencia: \n-movies.csv\nIngrese nombre: ");
        fflush(stdin);
        gets(nombreDelArchivo);


		pArchivo = fopen(nombreDelArchivo, "r");

		if(pArchivo!=NULL)
		{
			if(parser_PeliText(pArchivo, pArrayListaPelis))
			{
				printf("Se a cargado la lista exitosamente!\n");
				todoOk=1;
			}
			else
            {
                printf("Error al cargar el archivos");
            }
            fclose(pArchivo);
		}
		else
        {
            printf("\nEl archivo en la ruta %s no existe.\n", nombreDelArchivo);
        }
	}
	else
	{
		printf("No se pudo cargar el archivo\n");
	}
    return todoOk;
}


int controller_listarPelis(LinkedList* pArrayListaPelis)
{
	int todoOk=0;
	int tam;
	eMovie* pelis=NULL;

	if(pArrayListaPelis!=NULL)
	{

		tam=ll_len(pArrayListaPelis);

		if(tam>=1)
		{
			printf(" %-10s %-30s %-30s %-20s\n","Id","titulo","genero","duracion");
			for (int i = 0; i < tam; ++i)
			{
				pelis = (eMovie*) ll_get(pArrayListaPelis, i);

				if(pelis!=NULL)
				{
					mostrarUnaPeli(pelis);
				}
			}
		}
		else
		{
			printf("No hay ningun pelis que mostrar\n");
		}
	}
    return todoOk;
}

int controller_mapPeli(LinkedList* pArrayListaPelis)
{
    int todoOk = 0;
    char confirmaVerLista;

    if(pArrayListaPelis!=NULL)
    {
        system("cls");
        if(ll_isEmpty(pArrayListaPelis) == 0)
        {
            pArrayListaPelis = ll_map(pArrayListaPelis, calcularDuracionPeli);

            printf("Se asigno duracion con exito!\n");

            validarCaracter(&confirmaVerLista, "\nDesea ver la lista de las peliculas con duracion asignads? (s/n): ",  "Respuesta invalida. 's' para confirmar. 'n' para cancelar: ", 's', 'n');

            if(confirmaVerLista=='s')
            {
                printf("--------------------------------------------------------------------------------------\n");
                printf("            ***   Lista de peliculas con duracion asignadas  ***             \n");
                printf("--------------------------------------------------------------------------------------\n");
                controller_listarPelis(pArrayListaPelis);
            }
            todoOk=1;
        }
        else
        {
            printf("No existen paises en el sistema.\n");
        }
    }
    return todoOk;
}

int controller_sortPelis(LinkedList* pArrayListaPelis)
{
	int todoOk=0;
	LinkedList* listaCloneOrdenada;

	if(pArrayListaPelis!=NULL)
	{

		listaCloneOrdenada=ll_clone(pArrayListaPelis);

		//verifico que la lista no este vacia con (ll_isEmpty) y que se haya clonado correctamente
		if(!ll_isEmpty(listaCloneOrdenada) && ll_containsAll(pArrayListaPelis, listaCloneOrdenada))
		{
            ll_sort(listaCloneOrdenada, pelis_compararPelis, 0);

            controller_listarPelis(listaCloneOrdenada);

			ll_deleteLinkedList(listaCloneOrdenada);
			todoOk=1;
		}
		else
		{
			printf("La lista esta vacia, no hay ningun peli cargado\n");
		}
	}
    return todoOk;
}

int controller_guardarListaTexto(char* path, LinkedList* pArrayListaPelis)
{
	int todoOk=0;
	int id;
	char titulo[30];
	char genero[30];
	int duracion;
	int tam;


	eMovie* auxPeli = NULL;
	FILE* pFile;

	//Verifico que este todo ok, en caso de estarlo abro el archivo y guardo cada empleado de la lista en el archivo txt
	if(path != NULL && pArrayListaPelis != NULL)
	{
	    tam = ll_len(pArrayListaPelis);

		pFile = fopen(path, "w");

		auxPeli = new_Peli();

		if(auxPeli!=NULL)
		{
			fprintf(pFile, "id,nombre,vac1dosis,vac2dosis,sinVacunar\n");
			for(int i=0; i<tam; i++)
			{
				auxPeli = (eMovie*) ll_get(pArrayListaPelis, i);
				if(auxPeli != NULL)
				{
				    peliGetId(auxPeli, &id);
				    peliGetTitulo(auxPeli, titulo);
                    peliGetGenero(auxPeli, genero);
                    peliGetDuracion(auxPeli, &duracion);

					fprintf(pFile, "%d,%s,%s,%d\n", id, titulo, genero, duracion);
					todoOk = 1;
				}
				else
				{
					todoOk = 0;
					break;
				}
			}
		}
		fclose(pFile);
	}

    return todoOk;
}

int controller_filterPeliGenero(LinkedList* pArrayListaPelis)
{

    int todoOk=0;
    LinkedList* listaFiltrada;


    if(pArrayListaPelis!=NULL)
    {
        system("cls");





                switch(menuPelis())
                {
                    case 1:
                        listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasHorror);
                        controller_guardarListaTexto("pelisTerror.csv", listaFiltrada);
                         printf("\nSe ha generado un archivo de salida (pelisTerror.csv)\n");
                         controller_listarPelis(listaFiltrada);

                        break;

                    case 2:
                        listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasDrama);
                        controller_guardarListaTexto("pelisDrama.csv", listaFiltrada);
                         printf("\nSe ha generado un archivo de salida (pelisDrama.csv)\n");
                        break;
                        case 3:
                        listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasAccion);
                        controller_guardarListaTexto("pelisAcccion.csv", listaFiltrada);
                         printf("\nSe ha generado un archivo de salida (pelisAcccion.csv)\n");
                        break;
                        case 4:
                        listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasComedia);
                        controller_guardarListaTexto("pelisComedia.csv", listaFiltrada);
                         printf("\nSe ha generado un archivo de salida (pelisComedia.csv)\n");
                        break;
                            case 5:
                                                        listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasAventuras);
                        controller_guardarListaTexto("pelisAventura.csv", listaFiltrada);
                         printf("\nSe ha generado un archivo de salida (pelisAventura.csv)\n");

                }


            ll_deleteLinkedList(pArrayListaPelis);
            todoOk=1;
        }
        else
        {
            ll_deleteLinkedList(pArrayListaPelis);
        }


    return todoOk;
}


