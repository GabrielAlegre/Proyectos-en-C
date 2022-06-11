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

/** \brief funcion que se encarga de imprimir a todos los paises que se encuentren en la lista
 *
 * \param pArrayListaPaises LinkedList* lista de paises
 * \return int 0 si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_listarPaises(LinkedList* pArrayListaPaises);


/** \brief funcion que invoca a ll_map para asignarle a los campos vac1dosis, vac2dosis y sinVacunar valores aleatorios
 *
 * \param pArrayListaPaises LinkedList* lista de paises
 * \return int 0 si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_mapPais(LinkedList* pArrayListaPaises);


/** \brief funcion que se encarga de buscar e informar el pais o los paises con el mayor porcentaje de no vacunados
 *
 * \param pArrayListaPaises LinkedList* lista de paises
 * \return int int 0 si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_masCastigados(LinkedList* pArrayListaPaises);


/** \brief funcion que se encarga de ordenar la lista de paises  por cantidad de vacunados con 1 dosis.
 *
 * \param pArrayListEmployee LinkedList* lista de paises
 * \return int 0 si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_sortPaises(LinkedList* pArrayListEmployee);

/** \brief funcion que invoca a ll_filter para filtrar de la lista original a los paises exitosos (países cuya población este vacunada con dos dosis en un porcentaje mayor al 30%.)
 *
 * \param pArrayListEmployee LinkedList* lista de paises
 * \return int si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_filterPaisesExitosos(LinkedList* pArrayListEmployee);

/** \brief funcion que invoca a ll_filter para filtrar de la lista original a los paises en el horno (países donde la cantidad de no vacunados sea mayor a la de vacunados.)
 *
 * \param pArrayListEmployee LinkedList* lista de paises
 * \return int si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_filterPaisesEnElHorno(LinkedList* pArrayListEmployee);

/** \brief funcion que se encarga de guardar en el archivo txt lo que contenga la lista
 *
 * \param path char* ubicacion del archivo
 * \param pArrayListaPaises LinkedList* lista de paises
 * \return int si hubo algun error o 1 en caso de no haber error.
 *
 */
int controller_guardarListaTexto(char* path, LinkedList* pArrayListaPaises);


/** \brief funcion que se encarga de verificar si los paises que esten en el archivo tienen los campos vac1dosis, vac2dosis y sinVacunar cargados
 *
 * \param pArrayListaPaises LinkedList* lista de paises
 * \return int si hubo algun error o 1 en caso de no haber error y que los paises tengan la estadistica asignada.
 *
 */
int controller_VerificarSiLosPaisesTienenEstadisticas(LinkedList* pArrayListaPaises);

//int controller_cargarArchivoBin(LinkedList* pArrayListaPaises);

//int controller_guardarListaBin(char* path , LinkedList* pArrayListaPaises);
