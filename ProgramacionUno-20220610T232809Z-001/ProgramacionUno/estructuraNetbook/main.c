#include <stdio.h>
#include <stdlib.h>
#include "netbook.h"

#define TAM_NET 5

int main()
{
    eNetbook netbooks[TAM_NET]={

    {1, "Opteron 6274", "Amd", 2500},
    {2, "SW26010", "Sunway", 2000},
    {3, "Xeon", "Intel", 1000},
    {4,"7 5700G", "Ryzen", 1500},
    {5, "i7 9700F", "Intel", 5000}
    };

    printf("Lista de las netbook antes de ordenar por marca y precio: \n\n");
    printf("Id   Procesador      Marca      Precio\n");
    for(int i=0; i<TAM_NET; i++)
    {
           printf("%-5d%-15s %-10s %d\n",
           netbooks[i].id,
           netbooks[i].procesador,
           netbooks[i].marca,
           netbooks[i].precio);
    }

    ordenarNetbook(netbooks, TAM_NET);
    printf("\n");

    for(int i=0; i<TAM_NET; i++)
    {
           printf("%-5d%-15s %-10s %d\n",
           netbooks[i].id,
           netbooks[i].procesador,
           netbooks[i].marca,
           netbooks[i].precio);
    }

    return 0;
}
