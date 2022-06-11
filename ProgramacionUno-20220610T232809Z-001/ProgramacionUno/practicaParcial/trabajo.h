#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"
#include "bicicleta.h"
#include "color.h"
#include "tipo.h"

typedef struct{

    int idTrabajo;;
    int idBici;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/**
 * @fn int initEmployees(eEmployee*, int)
 * @brief Para indicar que todas las posiciones del array están vacías, esta función pone los isEmpty en TRUE(1) en todas las posiciones del array.
 *
 * @param list eEmployee* puntero al array de empleados.
 * @param len Tamanio del array de empleados.
 * @return retorna 0 si no hubo error y la funcion se realizo correctamente o -1 si hubo error y no se pudo realizar la funcion.
 */

int inicializarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab);

/** \brief Esta funcion recorre todas las posiciones del array hasta encontrar el primer indice libre (isEmpty en 1) para luego retornarlo.
 *
 * \param list eBicicleta* puntero al array lista de empleados.
 * \param tamBici Tamanio del array de empleados.
 * \return retorna el indice libre del primer empleado con isEmpty en 1 o -1 si no se encontro un indice libre o si hubo un error y nose pudo completar la funcion.
 *
 */

int buscarLibreTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab);

/** \brief Funcion que verifica si hay un indice libre en la lista de empleados, de haberlo, da de alta a un empleado cargando todos los campos de la estructura.
 *
 * \param list eBicicleta* puntero al array de la lista de empleados.
 * \param tamBici Tamanio del array de empleados.
 * \param id variable donde se le asignara a cada empleado su correspondiente id.
 * \param name variable donde el usuario va a cargar el nombre del empleado.
 * \param lastName variable donde el usuario va a cargar el apellido del empleado.
 * \param salary variable donde el usuario va a cargar el salario del empleado.
 * \param sector variable donde el usuario va a cargar el sector del empleado.
 * \return retorna 0 si no hubo error o -1 si la funcion no se pudo realizar correctamente.
 *
 */

int altaDeTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab, eBicicleta bicis[], int tamBici, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, int* pIdTrabajo);


/** \brief funcion que recibe la estructura de un empleado como parametro e imprime el valor de sus campos.
 *
 * \param unEmpleado estructura del empleado del cual se le implimiran sus datos.
 *
 */

void mostrarUnTrabajo(eTrabajo unTrabajo, eBicicleta bicis[], int tamBici, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief esta funcion busca a todos los empleados activos que se encuentren en el array e imprime sus datos.
 *
 * \param list array de empleado.
 * \param tamBicigth Tamanio del array.
 * \return retorna 0 en caso de realizarse correctamente la funcion o -1 en caso de error.
 *
 */

int mostrarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab, eBicicleta bicis[], int tamBici, eServicio servicios[],int tamServ, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief Se le pedira al usuario ingresar un id y la funcion se encargara de busca y encontra al empleado que coincida con dicha id ingresada.
 *
 * \param list array que contiene a todos los empleados, que sera recorrido hasta encontrar a la persona que coincida con el id.
 * \param tamBici Tamanio del array de empleados.
 * \param id  variable que contiene el valor del id del empleado a buscar.
 * \return retorna el indice donde se encuntra el empleado que coincide con la id o -1 si no se encontro la persona o si la funcion no se pudo realizar correctamente.
 *
 */
