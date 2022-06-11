#ifndef NETBOOK_H_INCLUDED
#define NETBOOK_H_INCLUDED

typedef struct{

    int id;
    char procesador[20];
    char marca[20];
    int precio;



}eNetbook;


#endif // NETBOOK_H_INCLUDED

 int ordenarNetbook(eNetbook netbooks[], int tamNet);
