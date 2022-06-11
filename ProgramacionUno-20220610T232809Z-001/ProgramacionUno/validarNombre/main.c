#include <stdio.h>
#include <stdlib.h>
#include "input.h"
int main()
{

    char nombre [50];
    int i=100;

    while(i>0)
    {
        validarCadena(nombre, "ingrese name: ", "\nerror ingrese name: ", 50);
        printf("%s\n", nombre);
        i--;
    }
    return 0;
}
