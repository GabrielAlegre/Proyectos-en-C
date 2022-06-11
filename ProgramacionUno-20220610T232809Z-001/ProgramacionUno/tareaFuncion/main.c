#include <stdio.h>
#include <stdlib.h>
#include "miBiblotecaAlegre.h"

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroDeDocumento;
    int numeroDeLegajo;
    float promedio;
    float division;

    /*
    printf("ingrese el priiiiiiiiiimer numero: ");
    scanf("%d", &numeroUno);

    printf("ingrese el seg3333333undo numero: ");
    scanf("%d", &numeroDos);

    printf("ingrese el docu numero: ");
    scanf("%d", &numeroDos);
    */

    numeroUno=ingresarEntero("Ingrese el primer numero: ");
    numeroDos=ingresarEntero("Ingrese el segundo numero: ");
    numeroDeDocumento=ingresarEntero("Ingrese su numero de documento: ");
    numeroDeLegajo=ingresarEntero("Ingrese numero de legajo: ");

    promedio=promediar(numeroUno, numeroDos);

    division=dividir(numeroUno, numeroDos);

    printf("El primer numero que ingreso fue el: %.2d\n", numeroUno);

    mostrar("El primer numero que ingreso fue el: ", numeroUno);

    printf("El segundo numero que ingreso fue el: %.2d\n", numeroDos);

    printf("El promedio es: %.2f\n", promedio);

    if(numeroDos!=0)
    {
        printf("La division es: %.2f\n", division);

    }
    else
    {
        printf("No se puede dividir por 0 mostro\n");
    }

    printf("Su numero de documento es: %.2d\n", numeroDeDocumento);

    printf("Su numero de legajo es: %.2d\n", numeroDeLegajo);

    return 0;
}

