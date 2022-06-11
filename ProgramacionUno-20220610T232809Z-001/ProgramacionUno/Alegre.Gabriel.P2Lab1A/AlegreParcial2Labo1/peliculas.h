#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[30];
    char genero[30];
    int duracion;

}eMovie;

#endif // PELICULAS_H_INCLUDED

void eliminarPeli(eMovie* pelicula);

void mostrarUnaPeli(eMovie* pelicula);

eMovie* new_Peli();

eMovie* new_PeliParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr);

int peliSetId(eMovie* pelicula, int id);

int peliSetTitulo(eMovie* pelicula, char* titulo);

int peliSetGenero(eMovie* pelicula, char* genero);

int peliSetDuracion(eMovie* pelicula, int duracion);

int peliGetId(eMovie* pelicula, int* pId);

int peliGetTitulo(eMovie* pelicula, char* pTituloPeli);

int peliGetGenero(eMovie* pelicula, char* pGeneroPeli);

int peliGetDuracion(eMovie* pelicula, int* pDuracion);

void* calcularDuracionPeli(void* element);

int filtroPeliculasDrama(void* pElement);

int filtroPeliculasAccion(void* pElement);

int filtroPeliculasAventuras(void* pElement);

int filtroPeliculasHorror(void* pElement);

int filtroPeliculasComedia(void* pElement);

int filtroPeliculasDocumental(void* pElement);


int pelis_compararPelis(void* peliUno, void* peliDos);
