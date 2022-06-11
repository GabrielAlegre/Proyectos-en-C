#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char nombre[50];
    char apellido[50];
    char nombreCompleto[110];
    int i=0;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(apellido);

    strlwr(nombre);
    strlwr(apellido);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombre);
    nombreCompleto[0]=toupper(nombreCompleto[0]);


    while(nombreCompleto[i]!='\0')
    {
        if(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }
        i++;
    }

    printf("%s ", nombreCompleto);

    return 0;
}
