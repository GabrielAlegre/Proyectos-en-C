#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
     int idSector;
     char descripcionSector[20];

} eSector;


#endif // SECTOR_H_INCLUDED

int cargarDescripcionSector(eSector sectores[], int tamSec, int idSector, char descSector[]);

int mostrarSectores(eSector sectores[], int tamSec);

