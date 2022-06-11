#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "servicio.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "cliente.h"

typedef struct{

    int idTrabajo;;
    int idAuto; //en el pdf decia patente, pero me guio mejor con el nombre "idAuto"
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED


/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone los isEmpty en TRUE(1) en todas las posiciones del array.
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array trabajos
 * \return int retorna 0 si no hubo error o -1 si hubo error
 *
 */
int inicializarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab);

/** \brief Esta funcion recorre todas las posiciones del array hasta encontrar el primer indice libre (isEmpty en 1) para luego retornarl
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array trabajos
 * \return int retorna 0 si no hubo error o -1 si hubo error
 *
 */
int buscarLibreTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab);


/** \brief  Funcion que verifica si hay un indice libre en la lista de trabajos, de haberlo, da de alta a un trabajo cargando todos los campos de la estructura.
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \param clientes[] eCliente
 * \param tamClientes int
 * \param pIdTrabajo int*
 * \return int
 *
 */
int altaDeTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, eCliente clientes[], int tamClientes, int* pIdTrabajo);

int mostrarUnTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

int mostrarTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

int informesAutosTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int menuInformes(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int trabajosDeUnAuto(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int importeTotalDeUnAuto(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int autosDeUnServicio(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);

int serviciosEnUnaFecha(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);


