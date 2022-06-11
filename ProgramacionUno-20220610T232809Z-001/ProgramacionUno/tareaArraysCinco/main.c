#include <stdio.h>
#include <stdlib.h>

int buscarCaracterPos(char x, char array[], int tamanio);


int main()
{
    char caracteres[7]={'b', 'o', 'k', 'e', 'm', 'i', 't'};
    char caracterRandom='t';
    char indiceDelCaracterEncontrado;

    indiceDelCaracterEncontrado=buscarCaracterPos(caracterRandom, caracteres, 7);

    if(indiceDelCaracterEncontrado>=0)
    {
        printf("Se encontro el caracter '%c' en el indice del array: %d", caracterRandom, indiceDelCaracterEncontrado);
    }
    else
    {
        printf("No se encontro el caracter '%c' en el array", caracterRandom);
    }
    return 0;
}

int buscarCaracterPos(char x, char array[], int tamanio)
{
    int indiceDondeSeEncontroCaracter=-1;

    for(int i=0; i<tamanio; i++)
    {
        if(array[i]==x)
        {
            indiceDondeSeEncontroCaracter=i;
        }
    }
    return indiceDondeSeEncontroCaracter;
}
