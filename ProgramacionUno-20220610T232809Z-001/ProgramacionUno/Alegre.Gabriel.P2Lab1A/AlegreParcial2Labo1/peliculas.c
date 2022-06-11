#include "peliculas.h"
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <string.h>

void eliminarPeli(eMovie* pelicula)
{
    free(pelicula);
}

void mostrarUnaPeli(eMovie* pelicula)
{
    int id;
    char titulo[30];
    char genero[30];
    int duracion;

	if(pelicula != NULL )
	{
		peliGetId(pelicula, &id);
		peliGetTitulo(pelicula, titulo);
		peliGetGenero(pelicula, genero);
		peliGetDuracion(pelicula, &duracion);

		printf(" %-10d %-30s %-30s %5d \n",id, titulo, genero, duracion);
	}
}

eMovie* new_Peli()
{
	eMovie* nuevaPeli=NULL;

    nuevaPeli = (eMovie*) malloc(sizeof (eMovie));

    if(nuevaPeli != NULL)
    {
        peliSetId(nuevaPeli, 0);
        peliSetTitulo(nuevaPeli, "-");
        peliSetGenero(nuevaPeli, "-");
        peliSetDuracion(nuevaPeli, 0);

    }
    return nuevaPeli;
}


eMovie* new_PeliParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
    eMovie* nuevaPeli;

    nuevaPeli = new_Peli();

    if(nuevaPeli != NULL)
    {
        if(!(peliSetId(nuevaPeli, atoi(idStr))
        && peliSetTitulo(nuevaPeli, tituloStr)
        && peliSetGenero(nuevaPeli, generoStr)
        && peliSetDuracion(nuevaPeli, atoi(duracionStr))))
        {
        	eliminarPeli(nuevaPeli);
        	nuevaPeli = NULL;
        }
    }
    return nuevaPeli;
}

int peliSetId(eMovie* pelicula, int id)
{
    int todoOk=0;

    if(pelicula != NULL && id>0)
    {
        pelicula->id_peli = id;

        todoOk=1;
    }
    return todoOk;
}

int peliSetTitulo(eMovie* pelicula, char* titulo)
{
    int todoOk=0;
    if(pelicula != NULL && titulo!=NULL)
    {
        if(strlen(titulo)<30 && strlen(titulo)>1)
        {
            strcpy(pelicula->titulo, titulo);
            todoOk=1;
        }
    }
    return todoOk;
}

int peliSetGenero(eMovie* pelicula, char* genero)
{
    int todoOk=0;
    if(pelicula != NULL && genero!=NULL)
    {
        if(strlen(genero)<30 && strlen(genero)>1)
        {
            strcpy(pelicula->genero, genero);
            todoOk=1;
        }
    }
    return todoOk;
}

int peliSetDuracion(eMovie* pelicula, int duracion)
{
    int todoOk=0;
    if(pelicula != NULL && duracion>=0 && duracion<=240)
    {
    	pelicula->duracion = duracion;
    	todoOk=1;
    }
    return todoOk;
}

int peliGetId(eMovie* pelicula, int* pId)
{
    int todoOk=0;

    if(pelicula != NULL && pId != NULL)
    {
        *pId = pelicula->id_peli;

        todoOk=1;
    }
    return todoOk;
}

int peliGetTitulo(eMovie* pelicula, char* pTituloPeli)
{
    int todoOk=0;
    if(pelicula != NULL && pTituloPeli!=NULL)
    {
        strcpy(pTituloPeli, pelicula->titulo);
        todoOk=1;
    }
    return todoOk;
}

int peliGetGenero(eMovie* pelicula, char* pGeneroPeli)
{
    int todoOk=0;
    if(pelicula != NULL && pGeneroPeli!=NULL)
    {
        strcpy(pGeneroPeli, pelicula->genero);
        todoOk=1;
    }
    return todoOk;
}

int peliGetDuracion(eMovie* pelicula, int* pDuracion)
{
    int todoOk=0;

    if(pelicula != NULL && pDuracion != NULL)
    {
        *pDuracion = pelicula->duracion;

        todoOk=1;
    }
    return todoOk;
}

void* calcularDuracionPeli(void* element)
{
	eMovie* nuevaPeliConDuracion=NULL;
	int duracion;
	int maximo = 240;
	int minimo = 100;

	if(element!=NULL)
    {
        nuevaPeliConDuracion = (eMovie*) element;

        if(nuevaPeliConDuracion != NULL)
        {
            //"Formula": rand() % (maximo -  minimo + 1)  + minimo;

            //calculo la duracion de la peli
            duracion = rand() % (maximo - minimo + 1)  + minimo;

            //asigno los valores
            peliSetDuracion(nuevaPeliConDuracion, duracion);
        }

    }
    return nuevaPeliConDuracion;
}

int filtroPeliculasDrama(void* pElement)
{
    int retorno=0;
    char generoDrama[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoDrama);

        if(!strcmp(generoDrama, "Drama"))
        {
            retorno=1;
        }

    }

    return retorno;
}


int filtroPeliculasAventuras(void* pElement)
{
    int retorno=0;
    char generoAdventure[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoAdventure);

        if(!strcmp(generoAdventure, "Adventure"))
        {
            retorno=1;
        }

    }

    return retorno;
}

int filtroPeliculasComedia(void* pElement)
{
    int retorno=0;
    char generoComedia[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoComedia);

        if(!strcmp(generoComedia, "Comedy"))
        {
            retorno=1;
        }

    }

    return retorno;
}

int filtroPeliculasHorror(void* pElement)
{
    int retorno=0;
    char generoHorror[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoHorror);

        if(!strcmp(generoHorror, "Horror"))
        {
            retorno=1;
        }

    }

    return retorno;
}

int filtroPeliculasAccion(void* pElement)
{
    int retorno=0;
    char generoAction[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoAction);

        if(!strcmp(generoAction, "Horror"))
        {
            retorno=1;
        }

    }

    return retorno;
}

int filtroPeliculasDocumental(void* pElement)
{
    int retorno=0;
    char generoDocumentary[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoDocumentary);

        if(!strcmp(generoDocumentary, "Documentary"))
        {
            retorno=1;
        }

    }

    return retorno;
}

int pelis_compararPelis(void* peliUno, void* peliDos)
{
	int retorno=0;
	int duracionUno;
	int duracionDos;
	char auxNombreUno[30];
	char auxNombreDos[30];

	eMovie* primerPeli;
	eMovie* segundaPeli;

	primerPeli = (eMovie*) peliUno;
	segundaPeli = (eMovie*) peliDos;

	if(primerPeli != NULL && segundaPeli != NULL)
	{
		peliGetDuracion(primerPeli, &duracionUno);
		peliGetDuracion(segundaPeli, &duracionDos);
        peliGetGenero(primerPeli, auxNombreUno);
        peliGetGenero(segundaPeli, auxNombreDos);

		if(strcmp(auxNombreUno, auxNombreDos)<0)
		{
			retorno=1;
		}

	}
	return retorno;
}
