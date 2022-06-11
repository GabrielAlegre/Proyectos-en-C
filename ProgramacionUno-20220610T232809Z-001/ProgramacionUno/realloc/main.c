#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mostrarNumeros (int* arrayDeNumeros, int tam);

//int cargarNumeros (int* arrayDeNumeros, int tam);

int main()
{
    //declaro el array
    int* listaDeNumeros = NULL; //Lo inicializo en null xq sino se va a inicializar con una direecion de memoria aletoria, en el mpmento que usemos el malloc se cargara con la memoria que corresponda
    int* auxListaDeNumeros = NULL;
    int tam =5;

    //pido memoria dinamica
    listaDeNumeros = (int*) malloc(sizeof(int)* tam);// por 5 porque quiero guardar 5 numeros, si quisiera guardar 22 numeros seria por 22

    //valido que la direccion de memoria que me retorno malloc no sea null
    if(listaDeNumeros==NULL)
    {
        printf("No se pudo conseguir memory\n");
        exit(1);//Para cerrar el progrema ante un error
    }

    //cargo el vector
    for(int i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", listaDeNumeros + i);
    }
    printf("\n");

    mostrarNumeros(listaDeNumeros, tam);

    //VAMOS A USAR REALLOC PARA AGRANDAR EL ARRAY QUE ERA DE 5 LO PASO A 10
    auxListaDeNumeros = (int*) realloc(listaDeNumeros, sizeof(int)* (tam+5));
    //Lo hacemos en un auxiliar xq en el caso de no encuentra nada me retornara null y encima pierdo todo lo que este adentro del array
    //Para prevenir eso lo hago en un aux y en el momento que valide que lo que me retorno realoc no es null sino una direccion de memoria valida
    //le asigno esa direccion de memoria valida con el array ya agrandado a mi listaDeNumeros (linea 41) y si es null no se agranda y mando mensaje que no se pudo agrandar y quedara con el tamaño original, 5
    if(auxListaDeNumeros!=NULL)
    {
        listaDeNumeros=auxListaDeNumeros;
        auxListaDeNumeros=NULL;//Le pongo null xq el aux ya cumplio su funcio y no lo usare mas
        tam+=5;

        printf("\n\nAgrandando el array.......");
        printf("\n");

        for(int i=5; i<tam; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", listaDeNumeros + i);
        }
        mostrarNumeros(listaDeNumeros, tam);
    }
    else
    {
        printf("\n No se pudo agrandar el array");
    }

    //AHORA QUIERO ACHICAR CON REALLOC DE 10 A 7

    printf("\n\nAchicamos el array (de 10 a 7) .......");

    listaDeNumeros = (int*) realloc(listaDeNumeros, sizeof(int)* (tam-3));
    tam=7;

    mostrarNumeros(listaDeNumeros, tam);

    free(listaDeNumeros); //Libero el espacio de memoria reservado en la memoria dinamica

    return 0;
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


