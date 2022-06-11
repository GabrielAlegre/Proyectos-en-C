#include <stdio.h>
#include <stdlib.h>

int encontrarPares(int array[], int tamanio);

int main()
{
    int numeros[5]={3,7,9,1,13};
    int numerosParesEncontados;

    numerosParesEncontados=encontrarPares(numeros, 5);

    if(numerosParesEncontados>=0)
    {
        printf("La cantidad de numeros pares encontrados es: %d.", numerosParesEncontados);

    }
    else
    {
        printf("%d: Parametros invalidos.", numerosParesEncontados);
    }

    return 0;
}

int encontrarPares(int array[], int tamanio)
{
    int contadorPares=-1;

    if(array!=NULL && tamanio>0)
    {
        for(int i=0; i<tamanio; i++)
        {
            contadorPares=0;

            if(array[i]%2==0)
            {
                contadorPares++;
            }
        }
    }
    return contadorPares;

}
