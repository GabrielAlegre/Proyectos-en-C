#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "color.h"
#include "marca.h"
#include "cliente.h"
typedef struct{

    int id;
    int idMarca;
    int idColor;
    char caja;
    int idCliente;
    int isEmpty;

}eAuto;

#endif // AUTO_H_INCLUDED

char menu();

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone los isEmpty en TRUE(1) en todas las posiciones del array.
 *
 * \param arrayAutos[] eAuto lista de autos
 * \param tamAuto int tamanio del array
 * \return int retorna 0 si no hubo error o -1 si hubo error.
 *
 */
int inicializarAutos(eAuto arrayAutos[], int tamAuto);

/** \brief Esta funcion recorre todas las posiciones del array hasta encontrar el primer indice libre (isEmpty en 1) para luego retornarlo.
 *
 * \param arrayAutos[] eAuto lista de autos
 * \param tamAuto int tamanio del array
 * \return int retorna 0 si no hubo error o -1 si hubo error.
 *
 */
int buscarLibre(eAuto arrayAutos[], int tamAuto);


/** \brief Funcion que verifica si hay un indice libre en la lista de autos, de haberlo, da de alta a un auto cargando todos los campos de la estructura.
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param pIdAuto int* puntero a entero donde la id se va a ir incrementando
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int altaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes, int* pIdAuto);

/** \brief funcion que recibe la estructura de un auto como parametro e imprime el valor de sus campos.
 *
 * \param unAuto eAuto auto a mostrar
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \return int retorna 0 si hubo error o 1 si salio todo ok
 *
 */
int mostrarUnAuto(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[],int tamClientes);

/** \brief esta funcion muestra la lista de los autos que esten activos en ese momento
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \return int retorna 0 si hubo error o 1 si salio todo ok
 */
int mostrarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);

/** \brief Se le pedira al usuario ingresar un id y la funcion se encargara de busca y encontra al auto que coincida con dicha id ingresada.
 *
 * \param arrayAutos[] eAuto array de autos donde se buscara la id
 * \param tamAuto int tamanio del array
 * \param idAuto int id a buscar
 * \return int retorna 0 si hubo error o 1 si salio todo ok
 *
 */
int buscarAutoPorId(eAuto arrayAutos[], int tamAuto, int idAuto);

/** \brief Elimina de manera lógica (isEmpty en 1) a un auto atravez del numero de id que recibe como parámetro.
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int bajaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);

/** \brief Funcion que permite modificar los datos de un auto atravez de un numero de id. Permitiendo modificar: color y modelo.
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int modificarAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);

/** \brief Funcion que muestra el menu con las opciones para realizar una modificion .
 *
 * \return char retorna la opcion elegida por el usuario.
 *
 */
char menuDeModificarAuto();

/** \brief recorre todo el array de autos hasta encontrar un auto activo para avisar que hay un auto
 *
 * \param arrayAutos[] eAuto array a recorrer
 * \param tamAuto int tamanio del array
 * \param banderaHayUnAuto int* bandera que si hay un auto se cambia el valor a 1, y si no hay autos su valor sera 0
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int buscarSiHayUnAuto(eAuto arrayAutos[], int tamAuto, int* banderaHayUnAuto);

/** \brief Funcion que ordena el array de autos por marca y id(patente) de manera ascendente.
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int ordenarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

/** \brief esta funcion muestra los autos del color seleccionado por el usuario.
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int informeMostrarAutosDeUnColor(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);


/** \brief submenu de los informes que estan relacionado solo con autos
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int informeSoloDeAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);


/** \brief esta funcion muestra los autos de una marca seleccionada por el usuario
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int informeMostrarAutosDeUnaMarca(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);

int informeAutoMasViejo(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);


/** \brief Funcion que muestra un listado de los autos separados por marca
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int informeAutosPorMarcas(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);



/** \brief esta funcion muestra los autos segun la id que recibe como parametro
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \param IdDeLaMarca int id de la marca a buscar
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int mostrarAutosPorIdMarca(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes, int IdDeLaMarca);


/** \brief en esta funcion se le da al usuario la opcion de elegir un color y una marca y contar cuantos autos hay de ese color y esa marca
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int informeCantAutosDeUnColorMarca(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);

/** \brief esta funcion muestra la o las marcas más elegidas por los clientes.
 *
 * \param arrayAutos[] eAuto array de autos
 * \param tamAuto int tam del array
 * \param marcas[] eMarca lista de marcas del audio
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de color de auto
 * \param tamColor int tamanio del array color
 * \param clientes[] eCliente lista de los clientes
 * \param tamClientes int tamanio del array de clientes
 * \return int retorna 1 si no hubo error o 0 si hubo error
 *
 */
int informeMarcaDeAutoMasElegida(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);
