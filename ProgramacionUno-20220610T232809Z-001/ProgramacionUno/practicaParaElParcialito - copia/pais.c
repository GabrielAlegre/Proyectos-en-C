#include "pais.h"
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <string.h>

void mostrarUnPais(ePais* pais)
{
    int id;
    char nombre[30];
    int vacPrimeraDosis;
    int vacSegundaDosis;
    int sinVacunar;

	if(pais != NULL )
	{
		paisGetId(pais, &id);
		paisGetNombre(pais, nombre);
		paisGetVacPrimeraDosis(pais, &vacPrimeraDosis);
		paisGetVacSegundaDosis(pais, &vacSegundaDosis);
		paisGetSinVacunar(pais, &sinVacunar);

		printf(" %-10d %-15s %8d%% %18d%% %17d%% \n",id, nombre, vacPrimeraDosis, vacSegundaDosis, sinVacunar);
	}
}

ePais* new_Pais()
{
	ePais* nuevoPais=NULL;

    nuevoPais = (ePais*) malloc(sizeof (ePais));

    if(nuevoPais != NULL)
    {
        paisSetId(nuevoPais, 0);
        paisSetNombre(nuevoPais, "-");
        paisSetVacPrimeraDosis(nuevoPais, 0);
        paisSetVacSegundaDosis(nuevoPais, 0);
        paisSetSinVacunar(nuevoPais, 0);
    }
    return nuevoPais;
}


ePais* new_PaisParametros(char* idStr, char* nombreStr, char* vacPrimeraDosisStr, char* vacSegundaDosisStr, char* sinVacunarStr)
{
    ePais* nuevoPais;

    nuevoPais = new_Pais();

    if(nuevoPais != NULL)
    {
        if(!(paisSetId(nuevoPais, atoi(idStr))
        && paisSetNombre(nuevoPais, nombreStr)
        && paisSetVacPrimeraDosis(nuevoPais, atoi(vacPrimeraDosisStr))
        && paisSetVacSegundaDosis(nuevoPais, atoi(vacSegundaDosisStr))
        && paisSetSinVacunar(nuevoPais, atoi(sinVacunarStr))))
        {
        	//Si algunos de los campos del pais es invalido, elimino el pais
        	eliminarPais(nuevoPais);
        	nuevoPais = NULL;
        }
    }
    return nuevoPais;
}


//Setters
int paisSetId(ePais* pais, int id)
{
    int todoOk=0;

    if(pais != NULL && id>0)
    {
        pais->id = id;

        todoOk=1;
    }
    return todoOk;
}

int paisSetNombre(ePais* pais, char* nombre)
{
    int todoOk=0;
    if(pais != NULL && nombre!=NULL)
    {
        if(strlen(nombre)<30 && strlen(nombre)>1)
        {
            strcpy(pais->nombre, nombre);
            todoOk=1;
        }
    }
    return todoOk;
}

int paisSetVacPrimeraDosis(ePais* pais, int vacunadosPrimeraDosis)
{
    int todoOk=0;
    if(pais != NULL && vacunadosPrimeraDosis>=0 && vacunadosPrimeraDosis<=60)
    {
    	pais->vacPrimeraDosis = vacunadosPrimeraDosis;
    	todoOk=1;
    }
    return todoOk;
}

int paisSetVacSegundaDosis(ePais* pais, int vacunadosSegundaDosis)
{
    int todoOk=0;
    if(pais != NULL && vacunadosSegundaDosis>=0 && vacunadosSegundaDosis<=40)
    {
    	pais->vacSegundaDosis = vacunadosSegundaDosis;
    	todoOk=1;
    }
    return todoOk;
}

int paisSetSinVacunar(ePais* pais, int sinVacunar)
{
    int todoOk=0;
    if(pais != NULL && sinVacunar>=0 && sinVacunar<=98)
    {
    	pais->sinVacunar = sinVacunar;
    	todoOk=1;
    }
    return todoOk;
}

//Getters
int paisGetId(ePais* pais, int* pId)
{
    int todoOk=0;

    if(pais != NULL && pId != NULL)
    {
        *pId = pais->id;

        todoOk=1;
    }
    return todoOk;
}

int paisGetNombre(ePais* pais, char* pNombrePais)
{
    int todoOk=0;
    if(pais != NULL && pNombrePais!=NULL)
    {
        strcpy(pNombrePais, pais->nombre);
        todoOk=1;
    }
    return todoOk;
}

int paisGetVacPrimeraDosis(ePais* pais, int*pVacunadosPrimeraDosis)
{
    int todoOk=0;
    if(pais != NULL && pVacunadosPrimeraDosis!=NULL)
    {
    	*pVacunadosPrimeraDosis = pais->vacPrimeraDosis;
    	todoOk=1;
    }
    return todoOk;
}

int paisGetVacSegundaDosis(ePais* pais, int* pVacunadosSegundaDosis)
{
    int todoOk=0;
    if(pais != NULL && pVacunadosSegundaDosis!=NULL)
    {
    	*pVacunadosSegundaDosis = pais->vacSegundaDosis;
    	todoOk=1;
    }
    return todoOk;
}

int paisGetSinVacunar(ePais* pais, int* pSinVacunar)
{
    int todoOk=0;

    if(pais != NULL && pSinVacunar != NULL)
    {
    	*pSinVacunar = pais->sinVacunar;
    	todoOk=1;
    }

    return todoOk;
}

void eliminarPais(ePais* pais)
{
    free(pais);
}


void* calcularPorcentajeVacunasPais(void* element)
{
	ePais* nuevoPaisConVac=NULL;
	int primeraDosis;
	int segundaDosis;
	int sinVacunar;

	if(element!=NULL)
    {
        nuevoPaisConVac = (ePais*) element;

        if(nuevoPaisConVac != NULL)
        {
            //"Formula": rand() % (maximo -  minimo + 1)  + minimo;

            //calculo el porcentaje de gente vacunada con una dosis
            primeraDosis = rand() % (60)  + 1;

            //calculo el porcentaje de gente vacunada con dos dosis
            segundaDosis = rand() % (40)  + 1;

            //calculo la gente sin vacunar
            sinVacunar = 100 - (primeraDosis + segundaDosis);

            //asigno los valores
            paisSetVacPrimeraDosis(nuevoPaisConVac, primeraDosis);
            paisSetVacSegundaDosis(nuevoPaisConVac, segundaDosis);
            paisSetSinVacunar(nuevoPaisConVac, sinVacunar);
        }

    }
    return nuevoPaisConVac;
}

//Ordenar por primera dosis y si la primera dosis son iguales ordena por nombre del pais
int pais_compararPrimeraDosis(void* paisUno, void* paisDos)
{
	int retorno=0;
	int auxPrimeraDosisUno;
	int auxPrimeraDosisDos;
	char auxNombreUno[30];
	char auxNombreDos[30];

	ePais* primerPais;
	ePais* segundoPais;

	primerPais = (ePais*) paisUno;
	segundoPais = (ePais*) paisDos;

	if(primerPais != NULL && segundoPais != NULL)
	{
		paisGetVacPrimeraDosis(primerPais, &auxPrimeraDosisUno);
		paisGetVacPrimeraDosis(segundoPais, &auxPrimeraDosisDos);
        paisGetNombre(primerPais, auxNombreUno);
        paisGetNombre(segundoPais, auxNombreDos);

		if(auxPrimeraDosisUno > auxPrimeraDosisDos || (auxPrimeraDosisUno == auxPrimeraDosisDos && strcmp(auxNombreUno, auxNombreDos)>0))
		{
			retorno=1;
		}
		else
		{
			if(auxPrimeraDosisUno < auxPrimeraDosisDos || (auxPrimeraDosisUno == auxPrimeraDosisDos && strcmp(auxNombreUno, auxNombreDos)<0))
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
/*
int pais_compararPrimeraDosis(void* paisUno, void* paisDos)
{
	int retorno=0;
	int auxPrimeraDosisUno;
	int auxPrimeraDosisDos;

	ePais* primerPais;
	ePais* segundoPais;

	primerPais = (ePais*) paisUno;
	segundoPais = (ePais*) paisDos;

	if(primerPais != NULL && segundoPais != NULL)
	{
		paisGetVacPrimeraDosis(primerPais, &auxPrimeraDosisUno);
		paisGetVacPrimeraDosis(segundoPais, &auxPrimeraDosisDos);

		if(auxPrimeraDosisUno > auxPrimeraDosisDos)
		{
			retorno=1;
		}
		else
		{
			if(auxPrimeraDosisUno < auxPrimeraDosisDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
*/

int filtroPaisesExitosos(void* pElement)
{
    int retorno=0;
    int vacunaSegundaDosis;

    ePais* auxPais = NULL;

    if(pElement!=NULL)
    {
        auxPais = (ePais*) pElement;
        paisGetVacSegundaDosis(auxPais, &vacunaSegundaDosis);

        if(vacunaSegundaDosis>30)
        {
            retorno=1;
        }

    }

    return retorno;
}

int filtroPaisesEnElHorno(void* pElement)
{
    int retorno=0;
    int noVacunados;
    int vacunaPrimeraDosis;
    int vacunaSegundaDosis;
    int vacunadosTotal;

    ePais* auxPais = NULL;

    if(pElement!=NULL)
    {
        auxPais = (ePais*) pElement;

        paisGetVacPrimeraDosis(auxPais, &vacunaPrimeraDosis);
        paisGetVacSegundaDosis(auxPais, &vacunaSegundaDosis);
        paisGetSinVacunar(auxPais, &noVacunados);

        vacunadosTotal = vacunaPrimeraDosis + vacunaSegundaDosis;

        if(noVacunados>vacunadosTotal)
        {
            retorno=1;
        }

    }
    return retorno;
}
