#include "LinkedList.h"


#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int controller_cargarArchivo(LinkedList* pArrayListaPelis);

int controller_listarPelis(LinkedList* pArrayListaPelis);

int controller_mapPeli(LinkedList* pArrayListaPelis);

int controller_filterPeliGenero(LinkedList* pArrayListaPelis);

int controller_guardarListaTexto(char* path, LinkedList* pArrayListaPelis);

int controller_sortPelis(LinkedList* pArrayListaPelis);

