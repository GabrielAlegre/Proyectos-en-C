#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    int vacPrimeraDosis;
    int vacSegundaDosis;
    int sinVacunar;

}ePais;

#endif // PAIS_H_INCLUDED

/** \brief Destructor de pais, libera de memoria dinamica y setea el puntero a NULL
 *
 * \param pais ePais* pais a elimiminar
 * \return void sin retorno
 *
 */
void eliminarPais(ePais* pais);
void mostrarUnPais(ePais* pais);

//Constructores
/** \brief crea un nuevo pais inicializando todos sus campos
 *
 * \return ePais* retorna el pais nuevo
 *
 */
ePais* new_Pais();

/** \brief crea un pais asignandole a todos los campos de dicho pais los valores que se le pasa por parametro
 *
 * \param idStr char* puntero a char que contiene la id a asignar
 * \param nombreStr char* puntero a char que contiene el nombre del pais a asignar
 * \param vacPrimeraDosisStr char* puntero a char que contiene el porcentaje de vacunados con una dosis
 * \param vacSegundaDosisStr char* puntero a char que contiene el porcentaje de vacunados con dos dosis
 * \param sinVacunarStr char* puntero a char que contiene el porcentaje de no vacunados
 * \return ePais* retorna el pais con los campos cargados
 *
 */
ePais* new_PaisParametros(char* idStr, char* nombreStr, char* vacPrimeraDosisStr, char* vacSegundaDosisStr, char* sinVacunarStr);

//Setters

/** \brief Le asigna al pais que recibe como parametro el valor de la id que tambien recibe como parametro
 *
 * \param pais ePais* pais al que se le va a asignar la id
 * \param id int id a asignar
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisSetId(ePais* pais, int id);

/** \brief Le asigna al pais que recibe como parametro el nombre que tambien recibe como parametro
 *
 * \param pais ePais* pais al cual se le asignara el nombre
 * \param nombre char* nombre a asignar
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */

int paisSetNombre(ePais* pais, char* nombre);

/** \brief Le asigna al pais que recibe como parametro el porcentaje de vacunados con 1 dosis que tambien recibe como parametro
 *
 * \param pais ePais* pais al cual se le asignara el porcentaje de vacunados con 1 dosis
 * \param vacunadosPrimeraDosis int porcentaje de vacunados con 1 dosis a asignar
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisSetVacPrimeraDosis(ePais* pais, int vacunadosPrimeraDosis);

/** \brief Le asigna al pais que recibe como parametro el porcentaje de vacunados con 2 dosis que tambien recibe como parametro
 *
 * \param pais ePais* pais al cual se le asignara el porcentaje de vacunados con 2 dosis
 * \param vacunadosSegundaDosis int el porcentaje de vacunados con 2 dosis a asignar
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisSetVacSegundaDosis(ePais* pais, int vacunadosSegundaDosis);


/** \brief Le asigna al pais que recibe como parametro el porcentaje de no vacunados que tambien recibe como parametro
 *
 * \param pais ePais* pais al cual se le asignara el porcentaje de no vacunados
 * \param sinVacunar int porcentaje de no vacunados
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisSetSinVacunar(ePais* pais, int sinVacunar);

//Getters

/** \brief obtiene el id del pais que recibe como parametro y se lo asigna a la variable recibe por referencia
 *
 * \param pais ePais* pais del cual se obtendra la id
 * \param pId int* variable a la cual se le asignara el id del pais
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisGetId(ePais* pais, int* pId);

/** \brief obtiene el nombre del pais que recibe como parametro y se lo asigna a la variable recibe por referencia
 *
 * \param pais ePais* pais del cual se obtendra  el nombre
 * \param pNombrePais char* variable a la cual se le asignara el nombre del pais
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisGetNombre(ePais* pais, char* pNombrePais);


/** \brief obtiene el porcentaje de vacunados con 1 dosis, del pais que recibe como parametro y se lo asigna a la variable recibe por referencia
 *
 * \param pais ePais* pais del cual se obtendra el porcentaje de vacunados con 1 dosis
 * \param int*pVacunadosPrimeraDosis variable a la cual se le asignara el porcentaje de vacunados con 1 dosis
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisGetVacPrimeraDosis(ePais* pais, int*pVacunadosPrimeraDosis);

/** \brief obtiene el porcentaje de vacunados con 2 dosis, del pais que recibe como parametro y se lo asigna a la variable recibe por referencia
 *
 * \param pais ePais* pais del cual se obtendra el porcentaje de vacunados con 2 dosis
 * \param pVacunadosSegundaDosis int* variable a la cual se le asignara el porcentaje de vacunados con 2 dosis
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisGetVacSegundaDosis(ePais* pais, int* pVacunadosSegundaDosis);



/** \brief obtiene el porcentaje de no vacunados, del pais que recibe como parametro y se lo asigna a la variable recibe por referencia
 *
 * \param pais ePais* pais del cual se obtendra el porcentaje de no vacunados
 * \param pSinVacunar int* variable a la cual se le asignara el porcentaje de no vacunados
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int paisGetSinVacunar(ePais* pais, int* pSinVacunar);


/** \brief le asignará a los campos vac1Dosis y vac2Dosis un número aleatorio y calculará el campo sinVacunar
 *
 * \param pais void* pais al cual se le asignaran aleatoriamente los campo vac1Dosis, vac2Dosis y sinVacunar
 * \return void* el retorno es el país con todos sus campos cargados
 *
 */
void* calcularPorcentajeVacunasPais(void* pais);

/** \brief en la funcion se obtienen dos porcentaje de vacunados con 1 dosis y compara cual es mayor
 *
 * \param paisUno void* primer pais a comparar el porcentaje de vacunados con 1 dosis
 * \param paisDos void* segundo pais a comparar el porcentaje de vacunados con 1 dosis
 * \return int retorna 1 si el porcentaje de vacunados con 1 dosis del primer pais es mayor al del segundo o -1 si es menor al segundo
 *
 */
int pais_compararPrimeraDosis(void* paisUno, void* paisDos);

/** \brief verifica si el elemento se debe agregar (su campo vac1Dosis debe ser mayor a 30) a la lista o no se debe agregar
 *
 * \param pElement void* elemnto elemento a filtrar
 * \return int devolverá 1 si ese ítem se debe agregar a la lista resultado o 0 si no debe agregarse
 *
 */
int filtroPaisesExitosos(void* pElement);

/** \brief verifica si el elemento se debe agregar a la lista o no se debe agregar
 *
 * \param pElement void* elemnto elemento a filtrar
 * \return int devolverá 1 si ese ítem se debe agregar a la lista resultado o 0 si no debe agregarse
 *
 */
int filtroPaisesEnElHorno(void* pElement);


