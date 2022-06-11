#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include "localidad.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    float altura;
    int idLocalidad;
    int isEmpty;

}ePersona;

#endif // PERSON_H_INCLUDED
// inicializa el campo isEmpy en 1
//1 quiere decir que esta vacio

int inicializarPersonas(ePersona arrayDePersonas[], int tam);

// retorna el indice de la primer estructura libre o devuelve -1 si esta todo el array lleno
int buscarLibre(ePersona arrayDePersonas[], int tam);

// 1 si se pudo dar de alta 0 si ocurrio un problema
int altaPersona(ePersona arrayDePersonas[], int tam, int* pId, eLocalidad arrayLocalidades[], int tamLoc);

int mostrarPersonas(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

void mostrarUnaPersona(ePersona unaPersona, eLocalidad arrayLocalidades[], int tamLoc);

int buscarPersona(ePersona arrayDePersonas[], int tam, int id);

int BajaPersona(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int modificarPersonas(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int ordenarPersonas(ePersona arrayDePersonas[], int tam, int campo);

int menuDeModificacion();

int menuOrdenamientos(ePersona arrayDePersonas[], int tam);

int mostrarMujeres(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int informePersonasLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int mostrarPersonaIdLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc, int idLoc);

int mostrarPersonasPorLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int promedioEdadVaronesLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int informePersonaMasAltaLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int InformeLocalidadMujerMasJoven(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int cantidadPersonasLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int localidadMasHabitada(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int cantidadPersonasEnCadaLocalidad(ePersona list[], int tam, eLocalidad arrayLocalidades[], int tamLoc);

int cargarDescripcionPersona(ePersona arrayDePersonas[], int tam, int idPersona,  char descripcionPersona[]);

//plus
int informes(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc);
int menuInformar();


//hacer un vector del mismo tamanio que el vector de habitantes (5) que sea entero con habitantes y guardadr el contador
//de habitantes en cada localidad despues recorro este este para encontrar el maximo una vez encontrado el indice
// de ese array va a ser el indice de una localidad

