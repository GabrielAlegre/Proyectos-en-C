
#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"
#include "peliculas.h"
#include "input.h"
#include "parser.h"

int controller_cargarArchivo(LinkedList* pArrayListaPelis, int array[])
{
	int todoOk=0;
	FILE* pArchivo;
	char nombreDelArchivo[50];

	if(pArrayListaPelis!=NULL)
	{

        nose(array);
        fflush(stdin);
        gets(nombreDelArchivo);


		pArchivo = fopen(nombreDelArchivo, "r");

		if(pArchivo!=NULL)
		{
		    ll_clear(pArrayListaPelis);
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
			todoOk=1;
		}
		else
		{
			printf("No hay ningun pelis que mostrar");
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
	int order;

	if(pArrayListaPelis!=NULL)
	{
		listaCloneOrdenada=ll_clone(pArrayListaPelis);

		//verifico que la lista no este vacia con (ll_isEmpty) y que se haya clonado correctamente
		if(!ll_isEmpty(listaCloneOrdenada) && ll_containsAll(pArrayListaPelis, listaCloneOrdenada))
		{
		    ingresoEntero(&order, "\nIngrese order 1 (Ascendente) o 0 (Descendente): ", "order invalido. 1 (Ascendente) o 0 (Descendente): ", 0, 1);

            ll_sort(listaCloneOrdenada, pelis_compararPelis, order);

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

int controller_filterPeliGenero(LinkedList* pArrayListaPelis, int array[])
{

    int todoOk=0;
    char salir='n';
    LinkedList* listaFiltrada;

    if(pArrayListaPelis!=NULL)
    {
        system("cls");

        do{
            switch(menuPelis())
            {
                case 1:
                    array[0]=1;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Terror filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");
                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasHorror);
                    controller_guardarListaTexto("pelisTerror.csv", listaFiltrada);
                    printf("\n");
                    controller_listarPelis(listaFiltrada);
                    printf("\nSe ha generado un archivo de salida (pelisTerror.csv)\n");

                    break;

                case 2:
                    array[1]=2;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Drama filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");

                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasDrama);
                    controller_guardarListaTexto("pelisDrama.csv", listaFiltrada);
                    printf("\n");
                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Drama\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisDrama.csv)\n");
                    }

                    break;

                case 3:
                    array[2]=3;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Accion filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");

                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasAccion);
                    controller_guardarListaTexto("pelisAccion.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Accion\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisAccion.csv)\n");
                    }
                    break;

                case 4:
                    array[3]=4;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Comedia filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");

                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasComedia);
                    controller_guardarListaTexto("pelisComedia.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Comedia\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisComedia.csv)\n");
                    }
                    break;

                case 5:
                    array[4]=5;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Aventura filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");

                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasAventuras);
                    controller_guardarListaTexto("pelisAventura.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Aventura\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisAventura.csv)\n");
                    }
                    break;

                case 6:
                    array[5]=6;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Documental filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");

                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasDocumental);
                    controller_guardarListaTexto("pelisDocumental.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Documental\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisDocumental.csv)\n");
                    }
                    break;

                case 7:
                    array[6]=7;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Animacion filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");

                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasAnimation);
                    controller_guardarListaTexto("pelisAnimacion.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Animacion\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisAnimacion.csv)\n");
                    }
                    break;

                case 8:
                    array[7]=8;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Musical filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");
                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasMusical);
                    controller_guardarListaTexto("pelisMusical.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Musical\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisMusical.csv)\n");
                    }
                    break;

                case 9:
                    array[8]=9;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Romanticas filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");
                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasRomance);
                    controller_guardarListaTexto("pelisRomanticas.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Romanticas\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisRomanticas.csv)\n");
                    }
                    break;

                case 10:
                    array[9]=10;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Thriller filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");
                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasThriller);
                    controller_guardarListaTexto("pelisThriller.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Thriller\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisThriller.csv)\n");
                    }
                    break;

                case 11:
                    array[10]=11;
                    system("cls");
                    printf("--------------------------------------------------------------------------------------\n");
                    printf("     ***   Peliculas de Western filtrada de la lista actual  *** \n");
                    printf("--------------------------------------------------------------------------------------\n");
                    listaFiltrada = ll_filter(pArrayListaPelis, filtroPeliculasWestern);
                    controller_guardarListaTexto("pelisWestern.csv", listaFiltrada);
                    printf("\n");

                    if(!controller_listarPelis(listaFiltrada))
                    {
                        printf(", en el listado actual no hay ninguna pelicula de Western\n");
                    }
                    else
                    {
                        printf("\nSe ha generado un archivo de salida (pelisWestern.csv)\n");
                    }
                    break;

                case 12:

                    printf("Salida exitosa!\n");
                    salir='s';
                    break;
                default:

                    printf("Opcion invalida!!!\n");
                    break;

                todoOk=1;

            }
            system("pause");

        }while(salir=='n');

    }
    else
    {
        todoOk=0;
    }
    return todoOk;
}

int nose(int arraysito[])
{

    int todoOk=0;
    if(arraysito!=NULL)
    {
        printf("\nIngrese el nombre del archivo a leer\nSugerencia: \n-movies.csv");
        for(int i=0; i<12; i++)
        {
            switch(arraysito[i])
            {
                case 1:
                    printf("\n-pelisTerror.csv");
                    break;
                case 2:
                    printf("\n-pelisDrama.csv");
                    break;
                case 3:
                    printf("\n-pelisAccion.csv");
                    break;
                case 4:
                    printf("\n-pelisComedia.csv");
                    break;
                case 5:
                    printf("\n-pelisAventura.csv");
                    break;
                case 6:
                    printf("\n-pelisDocumental.csv");
                    break;
                case 7:
                    printf("\n-pelisAnimacion.csv");
                    break;
                case 9:
                    printf("\n-pelisRomanticas.csv");
                    break;
                case 10:
                    printf("\n-pelisThriller.csv");
                    break;
                case 11:
                    printf("\n-pelisWestern.csv");
                    break;
            }
            /*
            if(arraysito[i]==1)
            {
                printf("\n-pelisTerror.csv");
            }
            else if(arraysito[i]==2)
            {
                printf("\n-pelisDrama.csv");
            }
            else if(arraysito[i]==3)
            {
                printf("\n-pelisAccion.csv");
            }
            */
        }
        printf("\nIngrese nombre: ");
    todoOk=1;
    }
    return todoOk;
}


