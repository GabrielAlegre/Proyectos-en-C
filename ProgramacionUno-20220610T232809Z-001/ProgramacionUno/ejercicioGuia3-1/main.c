#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 4
int cargarVector(int array[], char mensaje[], char mensajeError[], int tamanio, int minimo, int maximo);
int funcionPositivos(int array[], int tamanio);
int funcionNegativos(int array[], int tamanio);
int funcionPares(int array[], int tamanio);
int funcionImpares(int array[], int tamanio);
void mostrarLosNumerosCargados(int array[], int tamanio);

int main()
{
    int numerosEnteros[TAMANIO];
    int cantidadPositivos;
    int cantidadNegativos;
    int maximoImpar;
    int sumaDePares;
    cargarVector(numerosEnteros, "Ingrese un numero: ", "Error. El numero debe ser entre -1000 y 1000 ingrese otro: ", TAMANIO, -1000, 1000);

    cantidadPositivos=funcionPositivos(numerosEnteros, TAMANIO);
    cantidadNegativos=funcionNegativos(numerosEnteros, TAMANIO);

    mostrarLosNumerosCargados(numerosEnteros, TAMANIO);

    printf("La cantidad de positivos son: %d\n", cantidadPositivos);
    printf("La cantidad de negativos son: %d\n\n", cantidadNegativos);

    sumaDePares=funcionPares(numerosEnteros, TAMANIO);
    printf("La suma de los numeros pares es: %d\n\n", sumaDePares);

    maximoImpar=funcionImpares(numerosEnteros, TAMANIO);
    printf("El numero mayor de los impares es: %d\n", maximoImpar);

    return 0;
}

int cargarVector(int array[], char mensaje[], char mensajeError[], int tamanio, int minimo, int maximo)
{
	int retorno= -1;

	if(minimo<=maximo && tamanio>=0)
	{
        for(int i=0; i<tamanio; i++)
        {
            printf("%s", mensaje);
            scanf("%d", &array[i]);

            while(array[i]<minimo || array[i]>maximo)
            {
                printf("%s", mensajeError);
                scanf("%d", &array[i]);
            }
        }
    }
    return retorno;
}

int funcionPositivos(int array[], int tamanio)
{
    int cantPositivos=0;
    for(int i=0; i<tamanio; i++)
    {
        if(array[i]>0)
        {
            cantPositivos++;
        }
    }

    return cantPositivos;
}

int funcionNegativos(int array[], int tamanio)
{
    int cantNegativos=0;
    for(int i=0; i<tamanio; i++)
    {
        if(array[i]<0)
        {
            cantNegativos++;
        }
    }

    return cantNegativos;
}

int funcionPares(int array[], int tamanio)
{
    int sumaDePares=0;

    printf("Listado de los numeros pares:\n");

    for(int i=0; i<tamanio; i++)
    {
        if(array[i]%2==0)
        {
            sumaDePares+=array[i];
            printf("Par: %d\n", array[i]);
        }
    }
    return sumaDePares;
}

int funcionImpares(int array[], int tamanio)
{
    int mayorDeLosImpares;
    int flagImpares=0;

    printf("Listado de la posicion de los numeros impares:\n");

    for(int i=0; i<tamanio; i++)
    {
        if(array[i]%2!=0)
        {
            printf("Posicion: %d\n", i);
            if(flagImpares==0 || array[i]>mayorDeLosImpares)
            {
                mayorDeLosImpares=array[i];
                flagImpares=1;
            }
        }
    }
    return mayorDeLosImpares;
}

void mostrarLosNumerosCargados(int array[], int tamanio)
{
    printf("Listado de los numeros cargados:\n");
    for(int i=0; i<tamanio; i++)
    {
        printf("%d\n", array[i]);
    }
}



