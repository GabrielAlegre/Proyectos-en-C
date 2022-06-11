#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabraOriginal[20]="Hola mundo";
    char palabraInvertida[20];

    int j;
    int tam=strlen(palabraOriginal);
    char auxCadena[tam];

    printf("%s\n", palabraOriginal);
    strcpy(palabraInvertida, palabraOriginal);
    strcpy(auxCadena, palabraInvertida);

    j=tam-1;

    for(int i=0 ;i<tam; i++)
    {
        palabraInvertida[i] = auxCadena[j];
        j--;
    }
    printf("%s\n", palabraInvertida);
    printf("%s\n", palabraOriginal);

    return 0;
}
