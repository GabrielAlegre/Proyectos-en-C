#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_ARRAY 50

void agrandarAchicarArray(int* arrayNum, int numeroIndicador);

int main()
{
    int parametro;
    int* listaDeNumeros=NULL;

    listaDeNumeros = (int*) malloc(sizeof(int)* TAM_ARRAY);

    if(listaDeNumeros==NULL)
    {
        printf("No se pudo conseguir espacio en memoria\n");
        exit(1);//Para cerrar el progrema ante un error
    }
    else
    {
        printf("Se consigui espacio en memoria dinamica correctamente\n");
    }

    printf("\nIngrese parametro: 0 para achicar el array, 1 para agrandarlo: ");
    scanf("%d", &parametro);

    agrandarAchicarArray(listaDeNumeros, parametro);
    return 0;
}

void agrandarAchicarArray(int* arrayNum, int numeroIndicador)
{
    int* auxLista=NULL;
    int cantidad;
    int tam=TAM_ARRAY;

    if(numeroIndicador==0)
    {

        printf("Ingrese cuantos indice desea achicar el array?: ");
        scanf("%d", &cantidad);

        arrayNum = (int*) realloc(arrayNum, sizeof(int)* (tam-cantidad));
        tam-=cantidad;

        printf("Se achico el array %d indices", cantidad);
        printf("\nNuevo tamanio del array: %d", tam);

    }
    else
    {
        printf("Ingrese cuantos indice desea agrandar el array?: ");
        scanf("%d", &cantidad);

        auxLista = (int*) realloc(arrayNum, sizeof(int)* (tam+cantidad));

        if(auxLista!=NULL)
        {
            arrayNum=auxLista;
            auxLista=NULL;//Le pongo null xq el aux ya cumplio su funcio y no lo usare mas
            tam+=cantidad;
            printf("Se agrando el array %d incices\n", cantidad);
            printf("Nuevo tamanio del array: %d", tam);

        }
        else
        {
            printf("\n No se pudo agrandar el array");
        }
    }


}
