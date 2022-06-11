#include <stdio.h>
#include <stdlib.h>

float calcularPromedio(int array[], int tamanio, float* pPromedio);

int main()
{
    int numeros[5]={5,3,8,7,10};
    float promedio;

    //cargarVector(numeros, TAMANIO);
    if(calcularPromedio(numeros, 5, &promedio))
    {
        printf("El promedio es: %.2f\n",  promedio);
    }
    else
    {
        printf("Error en los parametros, no se puede calcular los promedios");
    }

    return 0;
}

float calcularPromedio(int array[], int tamanio, float* pPromedio)
{
    int acumuladorDeNumeros=0;
    int sePudoHizoElPromedio=0;

    if(array!=NULL && tamanio>0)
    {

        for(int i=0; i<tamanio; i++)
        {
            acumuladorDeNumeros+=array[i];
        }
        *pPromedio= (float)acumuladorDeNumeros/tamanio;
        sePudoHizoElPromedio=1;
    }

    return sePudoHizoElPromedio;
}

/*
void cargarVector(int array[], int tamanio)
{

    for(int i=0; i<tamanio; i++)
    {
        printf("El tamanio del array es %d, ingrese el numero que se guardara en el indice %d: ", tamanio, i);
        scanf("%d", &array[i]);
    }
}
*/
