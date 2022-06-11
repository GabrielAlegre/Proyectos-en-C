#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"
#include "pais.h"
#include "input.h"
#include "parser.h"


int controller_cargarArchivo(LinkedList* pArrayListaPaises, int banderaPaisesExitosos, int banderaPaisesEnElHorno)
{
	int todoOk=0;
	FILE* pArchivo;
	char nombreDelArchivo[50];

	if(pArrayListaPaises!=NULL)
	{
	    ll_clear(pArrayListaPaises);

        printf("\nIngrese el nombre del archivo a leer\nSugerencia: \n-paises.csv\nIngrese nombre: ");
        fflush(stdin);
        gets(nombreDelArchivo);

		pArchivo = fopen(nombreDelArchivo, "r");

		if(pArchivo!=NULL)
		{
			if(parser_PaisText(pArchivo, pArrayListaPaises))
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

/*
int controller_cargarArchivoBin(LinkedList* pArrayListaPaises)
{
	int todoOk = 0;
	FILE* pArchivo;
	char nombreDelArchivo[50];

	if(pArrayListaPaises!=NULL)
	{
        printf("\nIngrese el nombre del archivo a leer\nSugerencia: \n-paises.csv\nIngrese nombre: ");
        fflush(stdin);
        gets(nombreDelArchivo);

		pArchivo = fopen(nombreDelArchivo,"rb");

		if(pArchivo!= NULL)
		{
			if(parser_PaisBin(pArchivo, pArrayListaPaises))
			{
				printf("Se cargo con exito el archivo binario\n");
				todoOk=1;
			}
			fclose(pArchivo);
		}
		else
		{
			printf("No se pudo cargar el archivo porque no existe u ocurrio un error al abrirse\n");
		}
	}

    return todoOk;
}
*/

int controller_listarPaises(LinkedList* pArrayListaPaises)
{
	int todoOk=0;
	int tam;
	ePais* pais=NULL;

	if(pArrayListaPaises!=NULL)
	{

		tam=ll_len(pArrayListaPaises);

		if(tam>=1)
		{
			printf(" %-10s %-15s %-20s %-20s %-20s\n","Id","Nombre pais","vacPrimeraDosis","vacSegundaDosis", "sinVacunar");
			for (int i = 0; i < tam; ++i)
			{
				pais = (ePais*) ll_get(pArrayListaPaises, i);

				if(pais!=NULL)
				{
					mostrarUnPais(pais);
				}
			}
		}
		else
		{
			printf("No hay ningun pais que mostrar\n");
		}
	}
    return todoOk;
}

int controller_mapPais(LinkedList* pArrayListaPaises)
{
    int todoOk = 0;
    char confirmaVerLista;

    if(pArrayListaPaises!=NULL)
    {
        system("cls");
        if(ll_isEmpty(pArrayListaPaises) == 0)
        {
            pArrayListaPaises = ll_map(pArrayListaPaises, calcularPorcentajeVacunasPais);

            printf("Se asignaron las estadisticas con exito!\n");

            validarCaracter(&confirmaVerLista, "\nDesea ver la lista de los paises con las estadisticas ya asignadas? (s/n): ",  "Respuesta invalida. 's' para confirmar. 'n' para cancelar: ", 's', 'n');

            if(confirmaVerLista=='s')
            {
                printf("--------------------------------------------------------------------------------------\n");
                printf("            ***   Lista de Paises con estadisticas asignadas  ***             \n");
                printf("--------------------------------------------------------------------------------------\n");
                controller_listarPaises(pArrayListaPaises);
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

int controller_masCastigados(LinkedList* pArrayListaPaises)
{
	int todoOk=0;
	int tam=ll_len(pArrayListaPaises);
	ePais* pais=NULL;
	int sinVacunaMaximo;
	int bandera=0;
	int sinVacunarAux;
	char nombreMasCastigado[30];

	if(pArrayListaPaises!=NULL)
	{
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                    ***    Mostrar pais/paises mas castigado   ***             \n");
        printf("--------------------------------------------------------------------------------------\n");

        //busco cual es el mayor porcentaje de no vacunados
		if(ll_isEmpty(pArrayListaPaises) == 0)
		{
			for (int i = 0; i < tam; i++)
			{
			    //obtengo el pais que este en el indice i
				pais = (ePais*) ll_get(pArrayListaPaises, i);

				//verifico que sea distinto de null
				if(pais!=NULL)
				{
                    //Obtengo el porcentaje de no vacunados de dicho pais
				    paisGetSinVacunar(pais, &sinVacunarAux);

				    //verifico si el porcentaje de no vacunados de ese pais sea el maximo
					if(bandera==0 || sinVacunarAux > sinVacunaMaximo)
					{
						sinVacunaMaximo = sinVacunarAux;
						bandera=1;
					}
				}
			}

			printf("\nEl mayor porcentaje de no vacunados es: %d%%\n", sinVacunaMaximo);
			printf("\nEl/Los paises mas castigados son/es: \n");

			//busco a todos los paises con el mayor porcentaje de no vacunados
			for (int i = 0; i < tam; i++)
			{
				pais = (ePais*) ll_get(pArrayListaPaises, i);

				if(pais!=NULL)
				{
				    paisGetSinVacunar(pais, &sinVacunarAux);

					if(sinVacunarAux == sinVacunaMaximo)
					{
					    //cuando encuentro el o los paises con el mayor porcentaje de no vacunados busco su nombre y luego lo imprimo
					    paisGetNombre(pais, nombreMasCastigado);
					    printf("- %s", nombreMasCastigado);
					    printf("\n");
					}
				}
			}
		}
		else
		{
			printf("No hay ningun pais en la lista\n");
		}
	}
    return todoOk;
}

int controller_sortEmployee(LinkedList* pArrayListaPaises)
{
	int todoOk=0;
	int order;
	LinkedList* listaCloneOrdenada;

	if(pArrayListaPaises!=NULL)
	{
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                    ***    Lista ordenada por primera dosis   ***             \n");
        printf("--------------------------------------------------------------------------------------\n");

		listaCloneOrdenada=ll_clone(pArrayListaPaises);

		//verifico que la lista no este vacia con (ll_isEmpty) y que se haya clonado correctamente
		if(!ll_isEmpty(listaCloneOrdenada) && ll_containsAll(pArrayListaPaises, listaCloneOrdenada))
		{
			//Le pido al usuario el criterio de ornamiento (Ascendente o descendente)
			ingresoEntero(&order, "\nIngrese order 1 (Ascendente) o 0 (Descendente): ", "order invalido. 1 (Ascendente) o 0 (Descendente): ", 0, 1);

            ll_sort(listaCloneOrdenada, pais_compararPrimeraDosis, order);

            controller_listarPaises(listaCloneOrdenada);

            printf("\nSe ordeno exitosamente la lista por primera dosis!\n");

			ll_deleteLinkedList(listaCloneOrdenada);
			todoOk=1;
		}
		else
		{
			printf("La lista esta vacia, no hay ningun pais cargado\n");
		}
	}
    return todoOk;
}

int controller_guardarListaTexto(char* path, LinkedList* pArrayListaPaises)
{
	int todoOk= 0;
	int id;
	char nombre[30];
	int vacPrimeraDosis;
	int vacSegundaDosis;
	int sinVacunar;
	int tam;

	ePais* auxPais = NULL;
	FILE* pFile;

	//Verifico que este todo ok, en caso de estarlo abro el archivo y guardo cada empleado de la lista en el archivo txt
	if(path != NULL && pArrayListaPaises != NULL)
	{
	    tam = ll_len(pArrayListaPaises);

		pFile = fopen(path, "w");

		auxPais = new_Pais();

		if(auxPais!=NULL)
		{
			fprintf(pFile, "id,nombre,vac1dosis,vac2dosis,sinVacunar\n");
			for(int i=0; i<tam; i++)
			{
				auxPais = (ePais*) ll_get(pArrayListaPaises, i);
				if(auxPais != NULL)
				{
				    paisGetId(auxPais, &id);
				    paisGetNombre(auxPais, nombre);
                    paisGetVacPrimeraDosis(auxPais, &vacPrimeraDosis);
                    paisGetVacSegundaDosis(auxPais, &vacSegundaDosis);
                    paisGetSinVacunar(auxPais, &sinVacunar);

					fprintf(pFile, "%d,%s,%d,%d,%d\n", id, nombre, vacPrimeraDosis, vacSegundaDosis, sinVacunar);
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

int controller_filterPaisesExitosos(LinkedList* pArrayListaPaises)
{
    int todoOk=0;
    LinkedList* listaFiltradaPaisesExitosos=NULL;
    int tamLista;

    if(pArrayListaPaises!=NULL)
    {
        system("cls");

        //obtengo la lista con los paises exitosos que hayan pasado el filter
        listaFiltradaPaisesExitosos = ll_filter(pArrayListaPaises, filtroPaisesExitosos);

        if(listaFiltradaPaisesExitosos != NULL)
        {
            tamLista = ll_len(listaFiltradaPaisesExitosos);

            if(tamLista>0)
            {
                printf("--------------------------------------------------------------------------------------\n");
                printf("    ***   Lista de Paises exitosos (porcentaje de segunda dosis mayor al 30%%.)  ***             \n");
                printf("--------------------------------------------------------------------------------------\n");


                printf("%d paises han pasado el filter y son los siguientes:\n", tamLista);
                //Muestro la lista con todos los paises exitosos
                controller_listarPaises(listaFiltradaPaisesExitosos);

                //Genero el archivo donde solo aparezcan los países exitosos.
                controller_guardarListaTexto("paisesEnElHorno.csv", listaFiltradaPaisesExitosos);

                printf("\nSe ha generado un archivo de salida (paisesExitosos.csv) con los paises exitosos filtrados de la lista original\n");
            }
            else
            {
                printf("Ningun pais paso el filter de tener un porcentaje de segunda dosis mayor al 30%%.\n");
            }
            ll_deleteLinkedList(listaFiltradaPaisesExitosos);
            todoOk=1;
        }
        else
        {
            ll_deleteLinkedList(listaFiltradaPaisesExitosos);
        }
    }

    return todoOk;
}
int controller_filterPaisesEnElHorno(LinkedList* pArrayListaPaises)
{
    int todoOk=0;
    LinkedList* listaFiltradaPaisesEnElHorno=NULL;
    int tamLista;

    if(pArrayListaPaises!=NULL)
    {
        system("cls");
        listaFiltradaPaisesEnElHorno = ll_filter(pArrayListaPaises, filtroPaisesEnElHorno);

        if(listaFiltradaPaisesEnElHorno != NULL)
        {
            tamLista = ll_len(listaFiltradaPaisesEnElHorno);

            if(tamLista>0)
            {
                printf("--------------------------------------------------------------------------------------------------------\n");
                printf("    ***   Lista de Paises en el horno (La cantidad de no vacunados es mayor a la de vacunados.)  ***             \n");
                printf("--------------------------------------------------------------------------------------------------------\n");

                printf("%d paises han pasado el filter y son los siguientes:\n", tamLista);
                controller_listarPaises(listaFiltradaPaisesEnElHorno);

                controller_guardarListaTexto("paisesEnElHorno.csv", listaFiltradaPaisesEnElHorno);

                printf("\nSe ha generado un archivo de salida paisesEnElHorno.csv con los paises en el horno filtrados de la lista original\n");

            }
            else
            {
                printf("Ningun pais paso el filter donde la cantidad de no vacunados sea mayor a la de vacunados.\n");
            }

            //controller_guardarListaBin("paisesEnElHorno.bin", listaFiltradaPaisesEnElHorno);
            //printf("\nSe ha generado un archivo (paisesEnElHorno.bin) de salida con los paises exitosos filtrados de la lista original\n");

            ll_deleteLinkedList(listaFiltradaPaisesEnElHorno);
            todoOk=1;
        }
        else
        {
            ll_deleteLinkedList(listaFiltradaPaisesEnElHorno);
        }
    }

    return todoOk;
}

int controller_VerificarSiLosPaisesTienenEstadisticas(LinkedList* pArrayListaPaises)
{
	int todoOk=0;
	int tam=ll_len(pArrayListaPaises);
	ePais* pais=NULL;
	int sinVacuna;
	int vac1dosis;
	int vac2dosi;

	if(pArrayListaPaises!=NULL)
	{
        for (int i = 0; i < tam; i++)
        {
            pais = (ePais*) ll_get(pArrayListaPaises, i);

            if(pais!=NULL)
            {
                paisGetSinVacunar(pais, &sinVacuna);
                paisGetVacPrimeraDosis(pais, &vac1dosis);
                paisGetSinVacunar(pais, &vac2dosi);

                if(sinVacuna>0 && vac1dosis>0 && vac2dosi>0)
                {
                    todoOk=1;
                }
                else
                {
                    todoOk=0;
                    break;
                }
            }
        }

	}
    return todoOk;
}


/*
int controller_guardarListaBin(char* path , LinkedList* pArrayListaPaises)
{
	int todoOk = 0;
	FILE* pArchivo;
	ePais* unPais = NULL;

	//Verifico que este todo ok, en caso de estarlo abro el archivo y guardo cada empleado de la lista en el archivo txt
	if(path!=NULL && pArrayListaPaises!=NULL)
	{
		pArchivo = fopen(path,"wb");

		if(pArchivo!= NULL && ll_len(pArrayListaPaises)>0)
		{
			for(int i=0; i<ll_len(pArrayListaPaises) ;i++)
			{
				unPais = (ePais*) ll_get(pArrayListaPaises,i);

				if(unPais!=NULL)
				{
					fwrite(unPais, sizeof(ePais), 1, pArchivo);
					todoOk=1;
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}

		fclose(pArchivo);

		if(todoOk)
		{
			printf("Se ha guardado correctamente el listado!\n");
		}
	}

    return todoOk;
}
*/
