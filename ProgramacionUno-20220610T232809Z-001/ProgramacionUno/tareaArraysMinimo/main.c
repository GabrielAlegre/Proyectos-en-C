#include <stdio.h>
#include <stdlib.h>

int obtenerMinimo(int array[], int tamanio, int* pMinimo);

int main()
{
    int numeros[5]={10, 2, 12, 8, 9};
    int minimo;
    int sePudoObtenerMinimo;

    sePudoObtenerMinimo=obtenerMinimo(numeros, 5, &minimo);

    if(sePudoObtenerMinimo)
    {
        printf("El numero minimo es: %d", minimo);
    }
    else
    {
        printf("No se pudo obtener el numero minimo");
    }
    return 0;
}

int obtenerMinimo(int array[], int tamanio, int* pMinimo)
{
    int banderaPrimerIngreso=0;
    int sePudoObtenerMinimo=0;

    if(array!=NULL && tamanio>0 && pMinimo!=NULL)
    {
        for(int i=0; i<tamanio; i++)
        {
            if(banderaPrimerIngreso==0 || array[i]<*pMinimo)
            {
                *pMinimo=array[i];
                banderaPrimerIngreso=1;
                sePudoObtenerMinimo=1;
            }
        }
    }
    return sePudoObtenerMinimo;
}
