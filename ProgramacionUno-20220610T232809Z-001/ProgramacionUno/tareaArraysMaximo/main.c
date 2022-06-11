#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo(int array[], int tamanio, int* pMaximo);

int main()
{
    int numeros[5]={10, 2, 12, 8, 9};
    int maximo;
    int sePudoObtenerMaximo;

    sePudoObtenerMaximo=obtenerMaximo(numeros, 5, &maximo);

    if(sePudoObtenerMaximo)
    {
        printf("El numero maximo es: %d", maximo);
    }
    else
    {
        printf("No se pudo obtener el numero maximo");
    }
    return 0;
}

int obtenerMaximo(int array[], int tamanio, int* pMaximo)
{
    int banderaPrimerIngreso=0;
    int sePudoObtenerMaximo=0;

    if(array!=NULL && tamanio>0 && pMaximo)
    {
        for(int i=0; i<tamanio; i++)
        {
            if(banderaPrimerIngreso==0 || array[i]>*pMaximo)
            {
                *pMaximo=array[i];
                banderaPrimerIngreso=1;
                sePudoObtenerMaximo=1;
            }
        }
    }
    return sePudoObtenerMaximo;
}

/*
int obtenerMaximo(int array[], int tamanio)
{
    int banderaPrimerIngreso=0;
    int numeroMaximo;

    for(int i=0; i<tamanio; i++)
    {
        if(banderaPrimerIngreso==0 || array[i]>numeroMaximo)
        {
            numeroMaximo=array[i];
            banderaPrimerIngreso=1;
        }
    }
    return numeroMaximo;
}
*/
