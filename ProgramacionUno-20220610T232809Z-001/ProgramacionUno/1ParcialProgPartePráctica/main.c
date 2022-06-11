#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NET 5
#define TAM_CADENA 30

typedef struct{

    int id;
    char procesador[20];
    char marca[20];
    int precio;

}eNetbook;

int aplicarDescuento(int* precioParaHacerDescuento);

int contarCaracteres(char cadenaCaracteres[], char caracterParaBuscar);

int ordenarNetbook(eNetbook netbooks[], int tamNet);

int main()
{
    int precio=400;
    char cadenaParaBuscarChar[TAM_CADENA]= "Ojala pueda aprobar";

    eNetbook netbooks[TAM_NET]={
        {1, "Opteron 6274", "Amd", 2500},
        {2, "SW26010", "Sunway", 2000},
        {3, "Xeon", "Intel", 1000},
        {4,"7 5700G", "Ryzen", 1500},
        {5, "i7 9700F", "Intel", 5000}
    };

    aplicarDescuento(&precio);
    contarCaracteres(cadenaParaBuscarChar, 'a');
    ordenarNetbook(netbooks, TAM_NET);

    return 0;
}

int aplicarDescuento(int* precioParaHacerDescuento)
{
    printf("\n///////////////////////////////PRIMERA FUNCION////////////////////////////////////////////////////\n");
    int todoOk=0;
    int descuento;
    int porcentaje = 5;
    printf("\nEl precio original era de $%d", *precioParaHacerDescuento);

    if(*precioParaHacerDescuento>0)
    {
        descuento = (*precioParaHacerDescuento) * porcentaje/100;

        *precioParaHacerDescuento = (*precioParaHacerDescuento)-descuento;

        todoOk=1;
    }
    printf(" Ahora el precio con un %%5 de descuento es de: $%d\n\n", *precioParaHacerDescuento);

    return todoOk;
}

int contarCaracteres(char cadenaCaracteres[], char caracterParaBuscar)
{
    printf("///////////////////////////////SEGUNDA FUNCION////////////////////////////////////////////////////\n");
    int contador=-1;

    if(cadenaCaracteres!=NULL)
    {
        contador=0;
        for (int i=0 ;i<strlen(cadenaCaracteres); i++)
        {
            if(cadenaCaracteres[i]==caracterParaBuscar)
            {
                contador++;
            }
        }
        printf("\nEn la cadena: - %s - el caracter '%c' se encuentra: %d veces\n", cadenaCaracteres, caracterParaBuscar, contador);
    }

    return contador;
}


 int ordenarNetbook(eNetbook netbooks[], int tamNet)
 {
     printf("\n///////////////////////////////TERCERA FUNCION////////////////////////////////////////////////////\n");

    int todoOk=0;
    int criterio;
    eNetbook auxNet;

    if(netbooks!=NULL && tamNet>0)
    {

        printf("\nLista de las netbook antes de ordenar por marca y precio: \n\n");
        printf("Id   Procesador      Marca      Precio\n");
        for(int i=0; i<TAM_NET; i++)
        {
               printf("%-5d%-15s %-10s %d\n",
               netbooks[i].id,
               netbooks[i].procesador,
               netbooks[i].marca,
               netbooks[i].precio);
        }

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
                printf("\nId   Procesador      Marca      Precio\n");
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

        for(int i=0; i<tamNet; i++)
        {
           printf("%-5d%-15s %-10s %d\n",
           netbooks[i].id,
           netbooks[i].procesador,
           netbooks[i].marca,
           netbooks[i].precio);
        }
        todoOk=1;
    }
    return todoOk;

 }
