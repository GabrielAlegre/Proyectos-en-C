#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief funcion que se encarga de carga en la lista de paises que contenga el archivo de txt
 *
 * \param pArrayListaPaises LinkedList* lista de paises
 * \param banderaPaisesExitosos int bandera que indica si el archivo que contiene los paises exitosos fue creado
 * \param banderaPaisesEnElHorno int bandera que indica si el archivo que contiene los paises en el horno fue creado
 * \return int retorna 0 si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_cargarArchivo(LinkedList* pArrayListaPaises, int banderaPaisesExitosos, int banderaPaisesEnElHorno);

int controller_listarPaises(LinkedList* pArrayListaPaises);

int controller_mapPais(LinkedList* pArrayListaPaises);

int controller_masCastigados(LinkedList* pArrayListaPaises);

int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_filterPaisesExitosos(LinkedList* pArrayListEmployee);

int controller_filterPaisesEnElHorno(LinkedList* pArrayListEmployee);

int controller_guardarListaTexto(char* path, LinkedList* pArrayListaPaises);

int controller_VerificarSiLosPaisesTienenEstadisticas(LinkedList* pArrayListaPaises);

//int controller_cargarArchivoBin(LinkedList* pArrayListaPaises);

//int controller_guardarListaBin(char* path , LinkedList* pArrayListaPaises);
