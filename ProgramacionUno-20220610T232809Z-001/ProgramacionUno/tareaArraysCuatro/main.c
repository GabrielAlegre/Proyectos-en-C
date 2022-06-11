#include <stdio.h>
#include <stdlib.h>

int buscarCaracter(char x, char array[], int tamanio);


int main()
{
    char caracteres[5]={'b', 'o', 'k', 'e', 'm'};
    char caracterABuscar='a';
    int seEncontroCaracter;

    seEncontroCaracter=buscarCaracter(caracterABuscar, caracteres, 5);

    if(seEncontroCaracter==1)
    {
        printf("%d: Se encontro el caracter '%c' en el array", seEncontroCaracter, caracterABuscar);
    }
    else
    {
        if(seEncontroCaracter==0)
        {
            printf("%d: No se encontro el caracter '%c' en el array", seEncontroCaracter, caracterABuscar);
        }
        else
        {
            printf("%d: No se pudo buscar el caracter '%c' en el array, error en los parametros", seEncontroCaracter, caracterABuscar);
        }
    }
    return 0;
}

int buscarCaracter(char x, char array[], int tamanio)
{
    int seEncontroElCaracter=-1;

    if(array!=NULL && tamanio>0)
    {
        seEncontroElCaracter=0;
        for(int i=0; i<tamanio; i++)
        {
            if(array[i]==x)
            {
                seEncontroElCaracter=1;
                break;
            }
        }
    }
    return seEncontroElCaracter;
}
