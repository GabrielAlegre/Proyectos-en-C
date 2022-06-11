#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

    int id;
    char descripcionTipo[20];

}eTipo;

#endif // TIPO_H_INCLUDED

int cargarDescripcionTipo(eTipo ArrayTipos[], int tamTipo, int idTipo, char descripcionTipo[]);

int mostrarTipos(eTipo ArrayTipos[], int tamTipos);
