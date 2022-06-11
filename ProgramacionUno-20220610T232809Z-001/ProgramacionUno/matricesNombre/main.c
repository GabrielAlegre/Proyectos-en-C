#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 3
#define COLUMNAS 5

int mostrarNombres(char matrizNombre[][5], int filas);
int ordenarNombreAsc(char matrizNombre[][5], int filas);

int main()
{
    int matrizNumeros[FILAS][COLUMNAS]={{3,7,8,9,2}, {9,7,2,5,8}, {1,6,8,3,2}};
    char matrizCaracteres[FILAS][COLUMNAS]={{'b','t','c','f','t'}, {'z','m','d','o','p'}, {'w','q','s','d','v'}};
    /*La cantidad de filas representa la cantidad de nombres que puedo poner y las columnas
    la cantidad de caracteres que pueden llevar esos nombre. en este caso serian 3 nombres
    de como maximo 4 caracteres (no cuento el \0)*/
    char nombres[FILAS][COLUMNAS]={{"Juan"},
                                    {"Luis"},
                                    {"Ana"}};

        char Apellidos[4][21]={{"Pascucci"},
                                    {"Pascucci"},
                                    {"Real"},
                                    {"Tancredi"};


    for(int i=0; i<FILAS; i++)
    {

        for(int j=0; j<COLUMNAS; j++)
        {

            printf("%d ", matrizNumeros[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    for(int i=0; i<FILAS; i++)
    {

        for(int j=0; j<COLUMNAS; j++)
        {

            printf("%c ", matrizCaracteres[i][j]);

        }
        printf("\n");
    }


    printf("\n\n");
    /*

    for(int i; i<FILAS; i++)
    {
        printf("%s \n", nombres[i]);
    }
    */

    //Ahora le vamos a pedir al usuario que ingrese los nombres
    for(int i; i<FILAS; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);
    }

    mostrarNombres(nombres, FILAS);

    //no anda
    ordenarNombreAsc(nombres, FILAS);

    mostrarNombres(nombres, FILAS);

    return 0;
}

int mostrarNombres(char matrizNombre[][5], int filas)
{
    int todoOk=0;

    if(matrizNombre!=NULL && filas>0)
    {

        for(int i; i<filas; i++)
        {
            printf("%s \n", matrizNombre[i]);
        }
        todoOk=1;

    }


    return todoOk;
}

int ordenarNombreAsc(char matrizNombre[][5], int filas)
{
    int todoOk=0;
    char auxiliarCadenas[20];

    if(matrizNombre!=NULL && filas>0)
    {
        for(int i=0; i<filas-1; i++)
        {
            for(int j= i+1; i<filas; i++)
            {
                if(strcmp(matrizNombre[i], matrizNombre[j])>0)
                {
                    strcpy(auxiliarCadenas, matrizNombre[i]);
                    strcpy(matrizNombre[i], matrizNombre[j]);
                    strcpy(matrizNombre[j], auxiliarCadenas);

                }
            }
        }
        todoOk=1;
    }


    return todoOk;

}
