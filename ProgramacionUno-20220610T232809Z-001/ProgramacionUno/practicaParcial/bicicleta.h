#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "tipo.h"
#include "color.h"
typedef struct{

    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;

}eBicicleta;

#endif // BICICLETA_H_INCLUDED


/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone los isEmpty en TRUE(1) en todas las posiciones del array.
 *
 * \param arrayBicicletas[] eBicicleta array de bicicletas.
 * \param tamBici int tamanio del array de bicicletas.
 * \return int retorna 0 si no hubo error o -1 si hubo error.
 *
 */
int inicializarBicicletas(eBicicleta arrayBicicletas[], int tamBici);


/** \brief Esta funcion recorre todas las posiciones del array hasta encontrar el primer indice libre (isEmpty en 1) para luego retornarlo.
 *
 * \param arrayBicicletas[] eBicicleta array de bicicletas.
 * \param tamBici int Tamanio del array de bicicletas.
 * \return int retorna el indice libre de la primera bicicleta con isEmpty en 1 o -1 si no se encontro un indice libre o si hubo un error y nose pudo completar la funcion.
 *
 */
int buscarLibre(eBicicleta arrayBicicletas[], int tamBici);

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

int altaBicicleta(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, int* pIdBici);


/** \brief funcion que recibe la estructura de un empleado como parametro e imprime el valor de sus campos.
 *
 * \param unEmpleado estructura del empleado del cual se le implimiran sus datos.
 *
 */

void mostrarUnaBicicleta(eBicicleta unaBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief esta funcion busca a todos los empleados activos que se encuentren en el array e imprime sus datos.
 *
 * \param list array de empleado.
 * \param tamBicigth Tamanio del array.
 * \return retorna 0 en caso de realizarse correctamente la funcion o -1 en caso de error.
 *
 */

int mostrarBicicletras(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief Se le pedira al usuario ingresar un id y la funcion se encargara de busca y encontra al empleado que coincida con dicha id ingresada.
 *
 * \param list array que contiene a todos los empleados, que sera recorrido hasta encontrar a la persona que coincida con el id.
 * \param tamBici Tamanio del array de empleados.
 * \param id  variable que contiene el valor del id del empleado a buscar.
 * \return retorna el indice donde se encuntra el empleado que coincide con la id o -1 si no se encontro la persona o si la funcion no se pudo realizar correctamente.
 *
 */

int buscarBicicletaPorId(eBicicleta arrayBicicletas[], int tamBici, int idBici);

/** \brief Elimina de manera lógica (isEmpty en 1) a un empleado atravez del numero de id que recibe como parámetro.
 *
 * \param list array que contiene a todos los empleados.
 * \param tamBici Tamanio del array.
 * \param id El numero del id de la persona a eliminar.
 * \return retorna 0 en caso de no haber ningun error o -1 en caso de error.
 *
 */

int bajaBicicleta(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/**\brief Funcion que permite modificar los datos de un empleado atravez de un numero de id. Permitiendo modificar: Nombre, Apellido, Salario o Sector.
 *
 * \param list array que contiene a todos los empleados.
 * \param tamBici Tamanio del array.
 * \return retorna 1 en caso de no haber ningun error o 0 en caso de error.
 *
 */

int modificarBicicleta(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief Funcion que ordena el array de empleados por apellido y sector de manera descendente o ascendente segun elija el usuario.
 *
 * \param list array de empleados que sera recorrido para verificar que el empleado este ordenado correctamente segun el criterio de ordenamiento seleccionado por el usuario.
 * \param tamBici Tamanio del array.
 * \param order criterio de ornedamiento; 1 implica ordenar de manera ascendente y 0 de manera descendente.
 * \return retorna 0 en caso de no haber ningun error o -1 en caso de error.
 *
 */

char menuDeModificacion();

int ordenarBicicletas(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);



































































 int buscarSiHayUnaBicicleta(eBicicleta arrayBicicletas[], int tamBici, int* banderaHayUnaBici);

