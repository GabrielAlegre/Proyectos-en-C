#include <stdio.h>
#include <stdlib.h>
int mostrarLosNumerosCargados(int array[], int tamanio);

int main()
{
    int numeros[5]={2,5,8,6,3};

    if(mostrarLosNumerosCargados(numeros, 5)==0)
    {
        printf("Error en los parametros\n");
    }

    return 0;

}

int mostrarLosNumerosCargados(int array[], int tamanio)
{
    int todoOk=0;

    if(array!=NULL && tamanio>0)
    {
        printf("Array invertido:\n");

        for(int i=tamanio-1; i>=0 ; i--)
        {
            printf("%d ", array[i]);
        }
        todoOk=1;
    }

    return todoOk;
}
