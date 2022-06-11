#include <stdio.h>
#include <stdlib.h>

int totalizarEnteros(int array[], int tamanio);

int main()
{
    int numeros[]={5,3,8,7,10};

    if(totalizarEnteros(numeros, 5)==0)
    {
        printf("Error en los parametros");
    }

    return 0;
}

int totalizarEnteros(int array[], int tamanio)
{
    int acumuladorDeNumeros=0;
    int todoOk=0;

    if(array!=NULL && tamanio>0)
    {

        for(int i=0; i<tamanio; i++)
        {
            acumuladorDeNumeros+=array[i];
            printf("%d ", array[i]);
            array[tamanio-1]=acumuladorDeNumeros;
        }
        todoOk=1;
    }
    return todoOk;
}
