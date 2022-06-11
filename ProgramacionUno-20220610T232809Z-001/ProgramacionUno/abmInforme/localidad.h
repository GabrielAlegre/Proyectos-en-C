#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED

int cargarDescripcionLocalidad(eLocalidad arrayLocalidades[], int tam, int idLocalidad, char descripcion[]);

int mostrarLocalidades(eLocalidad localidades[], int tam);

int validadLocalidad(eLocalidad localidades[], int tam, int idAvalidar);


