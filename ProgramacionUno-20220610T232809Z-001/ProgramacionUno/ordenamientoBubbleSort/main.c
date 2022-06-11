#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define DESCENDENTE 1
#define ASCENDENTE 0

int mostrarEnteros(int array[], int tamanio);

int mostrarFlotantes(float array[], int tamanio);

int mostrarChar(char array[], int tamanio);

//criterio=0 ascendente // criterio=1 descendente
int ordenarEnteros(int arrayEnteros[], int tamanio, int criterio);

int ordenarFlotante(float arrayFlotantes[], int tamanio, int criterio);

int ordenarCaracter(char arrayCaracteres[], int tamanio, int criterio);

int main()
{
    int vectorEnteros[TAM]={4,9,5,8,2};
    float vectorFlotantes[TAM]={7.45, 5.95, 1.53, 9.23, 2.74};
    char vectorCaracteres[TAM]={'n','b','z','a','e'};

    mostrarEnteros(vectorEnteros, TAM);

    if(ordenarEnteros(vectorEnteros, TAM, ASCENDENTE))
    {
        mostrarEnteros(vectorEnteros, TAM);
    }
    else
    {
        printf("No se pudo realizar el ordenamiento de los enteros\n\n");
    }

/*****************************************************************************************************************/

    mostrarFlotantes(vectorFlotantes, TAM);

    if(ordenarFlotante(vectorFlotantes, TAM, ASCENDENTE))
    {
        mostrarFlotantes(vectorFlotantes, TAM);
    }
    else
    {
        printf("No se pudo realizar el ordenamiento de los flotantes\n\n");
    }

/*****************************************************************************************************************/

    mostrarChar(vectorCaracteres, TAM);

    if(ordenarCaracter(vectorCaracteres, TAM, ASCENDENTE))
    {
        mostrarChar(vectorCaracteres, TAM);
    }
    else
    {
        printf("No se pudo realizar el ordenamiento de caracteres\n\n");
    }

    return 0;
}

int mostrarEnteros(int array[], int tamanio)
{
    int todoOk=0;

    if(array!=NULL && tamanio>0)
    {
        for(int i=0; i<tamanio; i++)
        {
            printf("%d ", array[i]);
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}

int mostrarFlotantes(float array[], int tamanio)
{
    int todoOk=0;

    if(array!=NULL && tamanio>0)
    {
        for(int i=0; i<tamanio; i++)
        {
            printf("%.2f ", array[i]);
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}


int mostrarChar(char array[], int tamanio)
{
    int todoOk=0;

    if(array!=NULL && tamanio>0)
    {
        for(int i=0; i<tamanio; i++)
        {
            printf("%c ", array[i]);
            //fflush(stdin);
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}


int ordenarEnteros(int arrayEnteros[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliar;

    if(arrayEnteros!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0 && arrayEnteros[i]>arrayEnteros[j])
                {
                    auxiliar=arrayEnteros[i];
                    arrayEnteros[i]=arrayEnteros[j];
                    arrayEnteros[j]=auxiliar;

                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(arrayEnteros[i]<arrayEnteros[j])// criterio de ordenamiento descendente
                    {
                        auxiliar=arrayEnteros[i];
                        arrayEnteros[i]=arrayEnteros[j];
                        arrayEnteros[j]=auxiliar;
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int ordenarFlotante(float arrayFlotantes[], int tamanio, int criterio)
{
    int todoOk=0;
    float auxiliar;

    if(arrayFlotantes!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0)
                {
                    if(arrayFlotantes[i]>arrayFlotantes[j])// criterio de ordenamiento; ascendente
                    {
                        auxiliar=arrayFlotantes[i];
                        arrayFlotantes[i]=arrayFlotantes[j];
                        arrayFlotantes[j]=auxiliar;
                    }
                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(arrayFlotantes[i]<arrayFlotantes[j])// criterio de ordenamiento descendente
                    {
                        auxiliar=arrayFlotantes[i];
                        arrayFlotantes[i]=arrayFlotantes[j];
                        arrayFlotantes[j]=auxiliar;
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int ordenarCaracter(char arrayCaracteres[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliar;

    if(arrayCaracteres!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0)
                {
                    if(arrayCaracteres[i]>arrayCaracteres[j])// criterio de ordenamiento; ascendente
                    {
                        auxiliar=arrayCaracteres[i];
                        arrayCaracteres[i]=arrayCaracteres[j];
                        arrayCaracteres[j]=auxiliar;
                    }
                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(arrayCaracteres[i]<arrayCaracteres[j])// criterio de ordenamiento descendente
                    {
                        auxiliar=arrayCaracteres[i];
                        arrayCaracteres[i]=arrayCaracteres[j];
                        arrayCaracteres[j]=auxiliar;
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

/* opcion mocha
int ordenarEnteros(int vectorEnteros[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliar;

    if(vectorEnteros!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        if(criterio==0)
        {
            for(int i=0; i<TAM-1; i++)
            {
                for(int j=i+1; j<TAM; j++)
                {
                    if(vectorEnteros[i]>vectorEnteros[j])// criterio de ordenamiento; ascendente
                    {
                        auxiliar=vectorEnteros[i];
                        vectorEnteros[i]=vectorEnteros[j];
                        vectorEnteros[j]=auxiliar;
                    }
                }
            }
        }
        else
        {
            for(int i=0; i<TAM-1; i++)
            {
                for(int j=i+1; j<TAM; j++)
                {
                    if(vectorEnteros[i]<vectorEnteros[j])// criterio de ordenamiento descendente
                    {
                        auxiliar=vectorEnteros[i];
                        vectorEnteros[i]=vectorEnteros[j];
                        vectorEnteros[j]=auxiliar;
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}
*/
