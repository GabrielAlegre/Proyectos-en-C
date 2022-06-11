#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

#include "fecha.h"
#include "person.h"
#include "localidad.h"
#include "comida.h"

typedef struct{

    int idDeAlmuerzo;
    int idPersona;
    int idComida;
    eFecha fecha;
    int isEmpty;


}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

int inicializarAlmuerzos(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo);

int buscarLibreAlmuerzo(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo);

int altaAlmuerzo(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo, ePersona arrayPersonas[], int tamPer, eLocalidad arrayLocalidades[], int tamLoc, eComida arrayComidas[], int tamCom, int* pIdAlmuerzo);

int mostrarAlmuerzos(eAlmuerzo arrayDeAlmuerzos[], int tamAlmuerzo, ePersona arrayPersonas[], int tamPer, eLocalidad arrayLocalidades[], int tamLoc, eComida arrayComidas[], int tamCom);

void mostrarUnAlmuerzo(eAlmuerzo unAlmuerzo, ePersona arrayPersonas[], int tamPer, eComida arrayComida[], int tamCom);
