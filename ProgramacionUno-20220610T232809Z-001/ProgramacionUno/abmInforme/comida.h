#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{

    int idDeComida;
    char descripcion[20];
    float precio;


}eComida;


#endif // COMIDA_H_INCLUDED
int cargarDescripcionComida(eComida comidas[], int tamComida, int idComida,  char descripcionComida[]);

int mostrarComidas(eComida comidas[], int tamComida);


