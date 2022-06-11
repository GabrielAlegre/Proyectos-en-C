#include "netbook.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


 int ordenarNetbook(eNetbook netbooks[], int tamNet)
 {

    int todoOk=0;
    int criterio;
    eNetbook auxNet;

    if(netbooks!=NULL && tamNet>0)
    {

        printf("\nCriterios de ordenamiento:\n0 para ordenar de forma ascendente\n1 para ordenar de forma descendente\nIngrese opcion: ");
        scanf("%d", &criterio);

        while(criterio != 0 && criterio != 1)
        {
            printf("\nError. Criterio de ordenamiento:\n0 para ordenar de forma ascendente\n1 para ordenar de forma descendente\nIngrese opcion: ");
            scanf("%d", &criterio);
        }


        if(criterio==0)
        {
            printf("\nLista de las netbook despues de ordenar por marca y precio de manera ascendente: \n");
            printf("\nId   Procesador      Marca      Precio\n");
            for(int i=0; i<tamNet-1; i++)
            {
                for(int j=i+1; j<tamNet; j++)
                {
                    //Ascendente
                    if(strcmp(netbooks[i].marca, netbooks[j].marca)>0 || (strcmp(netbooks[i].marca, netbooks[j].marca)==0 && netbooks[i].precio > netbooks[j].precio))
                    {
                        auxNet=netbooks[i];
                        netbooks[i]=netbooks[j];
                        netbooks[j]=auxNet;
                    }
                }
            }
        }
        else
        {
            if(criterio==1)
            {
                printf("\nLista de las netbook despues de ordenar por marca y precio de manera descentente: \n");
                printf("\nId   Procesador      Marca      Precio");
                for(int i=0; i<tamNet-1; i++)
                {
                    for(int j=i+1; j<tamNet; j++)
                    {
                        //Descendente
                        if(strcmp(netbooks[i].marca, netbooks[j].marca)<0 || (strcmp(netbooks[i].marca, netbooks[j].marca)==0 && netbooks[i].precio < netbooks[j].precio))
                        {
                            auxNet=netbooks[i];
                            netbooks[i]=netbooks[j];
                            netbooks[j]=auxNet;
                        }
                    }
                }

            }
        }
        todoOk=1;
    }
    return todoOk;

 }
