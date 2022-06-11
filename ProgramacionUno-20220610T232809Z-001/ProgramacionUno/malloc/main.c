#include <stdio.h>
#include <stdlib.h>

#define TAM 5
//cargar un vector que esta en la memoria dinamica

//funcion para mostrar numeros de memoria dinamica

int mostrarNumeros (int* arrayDeNumeros, int tam);
int cargarNumeros (int* arrayDeNumeros, int tam);

int main()
{
    //declaro el array
    int* listaDeNumeros;

    //pido memoria dinamica
    listaDeNumeros = (int*) malloc(sizeof(int)* TAM);// por 5 porque quiero guardar 5 numeros, si quisiera guardar 22 numeros seria por 22

    //valido que la direccion de memoria que me retorno malloc no sea null
    if(listaDeNumeros==NULL)
    {
        printf("No se pudo conseguir memory\n");
        exit(1);//Para cerrar el progrema ante un error
    }

    //cargo el vector
    cargarNumeros(listaDeNumeros, TAM);
    /*
    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: "); //{5,6,7,5,9}
        scanf("%d", listaDeNumeros + i); //Para desplazarme del indice 0 al tam, por ejemplo cuando i vale 4 estaremos en el indice 4 que seria el 9
    }*/                                  // listaDeNumeros + i es: i * sizeof(int) cuando i valga 0 va 0 * sizeof(int) que da 0 bytes y quiere decir que se corra 0 bytes osea se queda en el mismo lugar,
                                        // cuando i valga 1 va a ser 1 * sizeof(int) que da 4 bytes y quiere decir que se corra 4 bytes (un array de int hay un espacio de 4 bytes del 0 al 1 y un espacio de 8 bytes del 0 al 2 y asi respectivamnete) osea va a pasar del indice 0 al 1
                                        // cuando i valga 3 va a hacer 3 * sizeof(int) que da 12 bytes por lo que se va a correr 12 bytes y va a pasar del indice 0 al 3

    //muestro el valor cargado
    mostrarNumeros(listaDeNumeros, TAM);
    /*
    for(int i=0; i<TAM; i++)
    {
        printf("%d", *(listaDeNumeros+ i));
    }
    */

    free(listaDeNumeros); //Libero el espacio de memoria reservado en la memoria dinamica
    return 0;
}

int cargarNumeros (int* arrayDeNumeros, int tam)
{
    int todoOk=0;

    if(arrayDeNumeros!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("Ingrese numero: ");
            scanf("%d", arrayDeNumeros+i);
        }
        todoOk=1;
    }

    return todoOk;
}

int mostrarNumeros(int* arrayDeNumeros, int tam)
{
    int todoOk=0;

    if(arrayDeNumeros!=NULL && tam>0)
    {
        printf("\n");
        for(int i=0; i<tam; i++)
        {
            printf("%d ", *(arrayDeNumeros+ i));
        }
        todoOk=1;
    }

    return todoOk;
}
