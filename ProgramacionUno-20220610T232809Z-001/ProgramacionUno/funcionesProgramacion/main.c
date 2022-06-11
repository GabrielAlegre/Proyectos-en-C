#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CADENA 20

int inverirPalabra(char palabraInvertida[]);

int aplicarDescuento(int* precioParaHacerDescuento);

int contarCaracteres(char cadenaCaracteres[], char caracterParaBuscar);

int main()
{
    char palabraParaInvertir[TAM_CADENA];
	char auxString[125];
	int precio = 1000;
    char palabraParaBuscarChar[TAM_CADENA];
    char charABuscar='a';
    int contadorDeChar=0;



    printf("Ingrese una palabra de maximo %d caracteres: ", TAM_CADENA-1);
    fflush(stdin);
    gets(auxString);

    while(strlen(auxString)> TAM_CADENA-1)
    {
        printf("ERROR. Ingrese una palabra de maximo %d caracteres: ", TAM_CADENA-1);
        fflush(stdin);
        gets(auxString);
    }

    strcpy(palabraParaInvertir, auxString);

    printf("\n- La palabra original es: %s", palabraParaInvertir);

    inverirPalabra(palabraParaInvertir);

    printf("\n- La palabra invertida es: %s\n", palabraParaInvertir);

//////////////////////////////////////////////5% DE UN PRECIO///////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\nEl precio original era de $%d", precio);

    aplicarDescuento(&precio);

    printf(" Ahora el precio con un %%5 de descuento es de: $%d\n\n", precio);


/////////////////////////////////////////////////////////CONTADOR DE UN CARACTER EN UNA CADENA ////////////////////////////////////////////////////////////////

    printf("Ingrese una palabra de maximo %d caracteres: ", TAM_CADENA-1);
    fflush(stdin);
    gets(auxString);

    while(strlen(auxString)> TAM_CADENA-1)
    {
        printf("ERROR. Ingrese una palabra de maximo %d caracteres: ", TAM_CADENA-1);
        fflush(stdin);
        gets(auxString);
    }

    strcpy(palabraParaBuscarChar, auxString);

    contadorDeChar=contarCaracteres(palabraParaBuscarChar, charABuscar);

    printf("\nEn la palabra %s el caracter '%c' se encuentra: %d veces", palabraParaBuscarChar, charABuscar, contadorDeChar);
    return 0;
}

//////////////////////////////FUNCIONES////////////////////////////////////////////////////////////////////////////////////77

int inverirPalabra(char palabraInvertida[])
{
    int todoOk=0;
    int j=0;
    int tam=strlen(palabraInvertida);
    char auxCadena[tam];

    if(palabraInvertida!=NULL)
    {
        strcpy(auxCadena, palabraInvertida);

        j=tam-1;

        for (int i=0 ;i<tam; i++)
        {
            palabraInvertida[i] = auxCadena[j];
            j--;
        }

        todoOk=1;
    }

    return todoOk;
}

int aplicarDescuento(int* precioParaHacerDescuento)
{
    int todoOk=0;
    int descuento;
    int porcentaje = 5;
    printf("\nEl precio original era de $%d", *precioParaHacerDescuento);

    if(*precioParaHacerDescuento>0)
    {
        descuento = (*precioParaHacerDescuento) * porcentaje/100;

        *precioParaHacerDescuento = (*precioParaHacerDescuento)-descuento;

        todoOk=1;
    }
    printf(" Ahora el precio con un %%5 de descuento es de: $%d\n\n", *precioParaHacerDescuento);

    return todoOk;
}


int contarCaracteres(char cadenaCaracteres[], char caracterParaBuscar)
{
    int contador=-1;

    if(cadenaCaracteres!=NULL)
    {
        contador=0;
        for (int i=0 ;i<strlen(cadenaCaracteres); i++)
        {
            if(cadenaCaracteres[i]==caracterParaBuscar)
            {
                contador++;
            }
        }
    }

    return contador;
}

