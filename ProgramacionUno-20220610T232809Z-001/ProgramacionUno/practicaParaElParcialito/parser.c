#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"

#ifndef PARSER_C_INCLUDED
#define PARSER_C_INCLUDED


#endif // PARSER_C_INCLUDED

int parser_PaisText(FILE* pFile, LinkedList* pArrayListaPaises)
{
    int todoOk=0;
    char id [10];
    char nombre[30];
    char vacPrimeraDosis[3];
    char vacSegundaDosis[3];
    char sinVacunar [3];

	ePais* pais=NULL;

	if(pFile!=NULL && pArrayListaPaises!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, vacPrimeraDosis, vacSegundaDosis, sinVacunar);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, vacPrimeraDosis, vacSegundaDosis, sinVacunar)==5)
			{
				pais=new_PaisParametros(id, nombre, vacPrimeraDosis, vacSegundaDosis, sinVacunar);

				if(pais!=NULL)
				{
					if(ll_add(pArrayListaPaises, pais)==-1)
					{
						eliminarPais(pais);
						break;
					}
					else
					{
						todoOk=1;
					}
				}
			}
			else
			{
				break;
			}
		}
		while(!feof(pFile));
	}
	return todoOk;
}

/*
int parser_PaisBin(FILE* pFile , LinkedList* pArrayListaPaises)
{
	int todoOk = 0;
	ePais* unPais = NULL;

	if(pFile!=NULL && pArrayListaPaises!=NULL)
	{
	//Mientras no haya llegado al final del archivo
		do
		{
			unPais = new_Pais();

			if(unPais!=NULL)
			{
			//Voy a ir leyendo de un empleado
				if(fread(unPais, sizeof(ePais), 1, pFile))
				{
					ll_add(pArrayListaPaises,unPais);
					todoOk=1;
				}
				else
				{
					eliminarPais(unPais);
				}
			}
		}while(!feof(pFile));
	}

    return todoOk;
}
*/
