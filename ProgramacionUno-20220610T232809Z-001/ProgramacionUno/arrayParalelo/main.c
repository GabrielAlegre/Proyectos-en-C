#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define DESCENDENTE 1 // sexo // promedio
#define ASCENDENTE 0
#define COLUMNAS 20

int validarNumeroEntero(int numero, int minimo, int maximo);

int validarCaracter(char caracter, char opcionA, char opcionB);

float calcularPromedio(int numeroUno, int numeroDos);

void mostrarAlumno(char nombre[], int legajo, char sexo, int notaUno, int notaDos, float promedio);

void mostrarAlumnos (char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio);

//int ordenarFlotante(float arrayFlotantes[], int tamanio, int criterio);

//int ordenarCaracter(char arrayCaracteres[], int tamanio, int criterio);

int ordenarAlumnosLegajo(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio);

int ordenarAlumnosSexo(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio);

int ordenarAlumnosPromedio(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio);

int ordenarAlumnosSexoLegajo(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio);

int ordenarAlumnosSexoPromedio(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio);

int ordenarAlumnosNombres(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio);
int main()
{
    int legajos[TAM]={11045, 18700,15000 ,10380,10456,15952,1129,16806,19069,11259};
    char sexos[TAM]={'f','f','f','m','m','f','m','f','f','m'};
    int notasUno[TAM]={9,10,2,6,10,5,8,2,4,8};
    int notasDos[TAM]={5,10,4,9,8,8,4,6,8,2};
    float promedios[TAM]={7,10,3,7.5,9,6.5,6,4,6,5};
    char nombres[TAM][COLUMNAS]={{"Juan"}, {"Luis"}, {"Ana"}, {"Xavier"}, {"Pedro"}, {"Romina"}, {"Batista"}, {"Lucas"}, {"Carlos"}, {"Fabricio"}};
/*
    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese legeajo (10000-20000): ");
        scanf("%d", &legajos[i]);

        while(validarNumeroEntero(legajos[i], 10000, 20000)==0)
        {
            printf("Legajo invalido. Reingrese el legajo (10000-20000): ");
            scanf("%d", &legajos[i]);
        }

        printf("Ingrese sexo f/m: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        while(validarCaracter(sexos[i], 'f', 'm')==0)
        {
            printf("Sexo invalido. Reingrese el sexo (f-m): ");
            fflush(stdin);
            scanf("%c", &sexos[i]);
        }

        printf("Ingrese nota uno (0-10): ");
        scanf("%d", &notasUno[i]);

        while(validarNumeroEntero(notasUno[i], 0, 10)==0)
        {
            printf("nota uno invalida. Reingrese la nota uno (0-10): ");
            scanf("%d", &notasUno[i]);
        }

        printf("Ingrese nota dos (0-10): ");
        scanf("%d", &notasDos[i]);

        while(validarNumeroEntero(notasDos[i], 0, 10)==0)
        {
            printf("nota dos invalida. Reingrese la nota dos (0-10): ");
            scanf("%d", &notasDos[i]);
        }

        promedios[i]=calcularPromedio(notasUno[i], notasDos[i]);

        //cuando paso un array por parametros solo se pasa el nombre ya que estarias pasando la dirreccion de memoria del valor del indice 0
        //mostrarAlumno(legajos[i], sexos[i], notasUno[i], notasDos[i], promedios[i]);

    }
    */

    /*if(ordenarFlotante(promedios, TAM, ASCENDENTE)==1 && ordenarCaracter(sexos, TAM, ASCENDENTE)==1)
    {
       mostrarAlumnos(legajos, sexos, notasUno, notasDos, promedios, TAM);
    }
    else
    {
        printf("No se pudo realizar el ordenamiento");
    }
    */

    mostrarAlumnos(nombres, legajos, sexos, notasUno, notasDos, promedios, TAM);

    ordenarAlumnosNombres(nombres, legajos, sexos, notasUno, notasDos, promedios, TAM, DESCENDENTE);
       mostrarAlumnos(nombres, legajos, sexos, notasUno, notasDos, promedios, TAM);


    return 0;
}


int validarNumeroEntero(int numero, int minimo, int maximo)
{
    int todoOk=0;

    if(numero>= minimo && numero<=maximo)
    {
        todoOk=1;
    }

    return todoOk;
}

int validarCaracter(char caracter, char opcionA, char opcionB)
{
    int todoOk=0;

    if(caracter==opcionA || caracter==opcionB)
    {
        todoOk=1;
    }
    return todoOk;
}

float calcularPromedio(int numeroUno, int numeroDos)
{
    float  promedio;

    promedio=(float)(numeroUno+numeroDos)/2;

    return promedio;
}

void mostrarAlumnos (char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio)
{
    printf("    *** Listado de Alumnos *** \n");

    printf("Legajo\tNombre\tSexo\tNota1\tNota2\tPromedio\t\n");

    for(int i=0; i<tamanio; i++)
    {
        mostrarAlumno(nombres[i], legajos[i], sexos[i], notasUno[i], notasDos[i], promedios[i]);
    }

}

void mostrarAlumno(char nombre[], int legajo, char sexo, int notaUno, int notaDos, float promedio)
{
    //printf("\nEl numero de legajo del alumno es: %d\n", legajo);

    //printf("El sexo del alumno es: %c\n", sexo);
    printf("%d  %s\t %c\t %d\t %d\t %.2f\t\n", legajo, nombre, sexo, notaUno, notaDos, promedio);
    //printf("La primera nota del alumno es: %d\n", notaUno);

    //printf("La segunda nota del alumno es: %d\n", notaDos);

    //printf("El promedio del alumno es: %.2f\n\n", promedio);
}



int ordenarAlumnosLegajo(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliarEntero;
    float auxiliarFlotante;
    char auxiliarChar;
    char auxiliarCadena[20];

    if(legajos!=NULL && sexos!=NULL && notasUno!=NULL && notasDos!=NULL && promedios!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0)
                {
                    if(legajos[i]>legajos[j])// criterio de ordenamiento; ascendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(legajos[i]<legajos[j])// criterio de ordenamiento descendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int ordenarAlumnosSexo(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliarEntero;
    float auxiliarFlotante;
    char auxiliarChar;
    char auxiliarCadena[20];

    if(legajos!=NULL && sexos!=NULL && notasUno!=NULL && notasDos!=NULL && promedios!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0)
                {
                    if(sexos[i]>sexos[j])// criterio de ordenamiento; ascendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(sexos[i]<sexos[j])// criterio de ordenamiento descendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;

}

int ordenarAlumnosPromedio(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliarEntero;
    float auxiliarFlotante;
    char auxiliarChar;
    char auxiliarCadena[20];

    if(legajos!=NULL && sexos!=NULL && notasUno!=NULL && notasDos!=NULL && promedios!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0)
                {
                    if(promedios[i]>promedios[j])// criterio de ordenamiento; ascendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(promedios[i]<promedios[j])// criterio de ordenamiento descendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int ordenarAlumnosSexoLegajo(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliarEntero;
    float auxiliarFlotante;
    char auxiliarChar;
    char auxiliarCadena[20];

    if(legajos!=NULL && sexos!=NULL && notasUno!=NULL && notasDos!=NULL && promedios!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0)
                {
                    if(sexos[i]==sexos[j] && legajos[i]>legajos[j])// criterio de ordenamiento; ascendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                    else
                    {
                        if(sexos[i]!=sexos[j] && sexos[i]<sexos[j])
                        {
                            strcpy(auxiliarCadena, nombres[i]);
                            strcpy(nombres[i], nombres[j]);
                            strcpy(nombres[j], auxiliarCadena);

                            auxiliarEntero=legajos[i];
                            legajos[i]=legajos[j];
                            legajos[j]=auxiliarEntero;

                            auxiliarEntero=notasUno[i];
                            notasUno[i]=notasUno[j];
                            notasUno[j]=auxiliarEntero;

                            auxiliarEntero=notasDos[i];
                            notasDos[i]=notasDos[j];
                            notasDos[j]=auxiliarEntero;

                            auxiliarFlotante=promedios[i];
                            promedios[i]=promedios[j];
                            promedios[j]=auxiliarFlotante;

                            auxiliarChar=sexos[i];
                            sexos[i]=sexos[j];
                            sexos[j]=auxiliarChar;
                        }
                    }
                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(sexos[i]==sexos[j] && legajos[i]<legajos[j])// criterio de ordenamiento descendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                    else
                    {
                        if(sexos[i]!=sexos[j] && sexos[i]>sexos[j])
                        {
                            auxiliarEntero=legajos[i];
                            legajos[i]=legajos[j];
                            legajos[j]=auxiliarEntero;

                            auxiliarEntero=notasUno[i];
                            notasUno[i]=notasUno[j];
                            notasUno[j]=auxiliarEntero;

                            auxiliarEntero=notasDos[i];
                            notasDos[i]=notasDos[j];
                            notasDos[j]=auxiliarEntero;

                            auxiliarFlotante=promedios[i];
                            promedios[i]=promedios[j];
                            promedios[j]=auxiliarFlotante;

                            auxiliarChar=sexos[i];
                            sexos[i]=sexos[j];
                            sexos[j]=auxiliarChar;
                        }
                    }

                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int ordenarAlumnosSexoPromedio(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliarEntero;
    float auxiliarFlotante;
    char auxiliarChar;
    char auxiliarCadena[20];

    if(legajos!=NULL && sexos!=NULL && notasUno!=NULL && notasDos!=NULL && promedios!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM-1; i++)
        {
            for(int j=i+1; j<TAM; j++)
            {
                if(criterio==0)
                {
                    if(sexos[i]==sexos[j] && promedios[i]>promedios[j])// criterio de ordenamiento; ascendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                    else
                    {
                        if(sexos[i]!=sexos[j] && sexos[i]>sexos[j])
                        {
                            strcpy(auxiliarCadena, nombres[i]);
                            strcpy(nombres[i], nombres[j]);
                            strcpy(nombres[j], auxiliarCadena);

                            auxiliarEntero=legajos[i];
                            legajos[i]=legajos[j];
                            legajos[j]=auxiliarEntero;

                            auxiliarEntero=notasUno[i];
                            notasUno[i]=notasUno[j];
                            notasUno[j]=auxiliarEntero;

                            auxiliarEntero=notasDos[i];
                            notasDos[i]=notasDos[j];
                            notasDos[j]=auxiliarEntero;

                            auxiliarFlotante=promedios[i];
                            promedios[i]=promedios[j];
                            promedios[j]=auxiliarFlotante;

                            auxiliarChar=sexos[i];
                            sexos[i]=sexos[j];
                            sexos[j]=auxiliarChar;
                        }
                    }
                }
                else//si el criterio es no es 0 debe ser 1 por logica
                {
                    if(sexos[i]==sexos[j] && promedios[i]<promedios[j])// criterio de ordenamiento descendente
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                    else
                    {
                        if(sexos[i]!=sexos[j] && sexos[i]<sexos[j])
                        {
                            strcpy(auxiliarCadena, nombres[i]);
                            strcpy(nombres[i], nombres[j]);
                            strcpy(nombres[j], auxiliarCadena);

                            auxiliarEntero=legajos[i];
                            legajos[i]=legajos[j];
                            legajos[j]=auxiliarEntero;

                            auxiliarEntero=notasUno[i];
                            notasUno[i]=notasUno[j];
                            notasUno[j]=auxiliarEntero;

                            auxiliarEntero=notasDos[i];
                            notasDos[i]=notasDos[j];
                            notasDos[j]=auxiliarEntero;

                            auxiliarFlotante=promedios[i];
                            promedios[i]=promedios[j];
                            promedios[j]=auxiliarFlotante;

                            auxiliarChar=sexos[i];
                            sexos[i]=sexos[j];
                            sexos[j]=auxiliarChar;
                        }
                    }

                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int ordenarAlumnosNombres(char nombres[][20], int legajos[], char sexos[], int notasUno[], int notasDos[], float promedios[], int tamanio, int criterio)
{
    int todoOk=0;
    int auxiliarEntero;
    float auxiliarFlotante;
    char auxiliarChar;
    char auxiliarCadena[20];

    if(legajos!=NULL && sexos!=NULL && notasUno!=NULL && notasDos!=NULL && promedios!=NULL && tamanio>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<tamanio-1; i++)
        {
            for(int j= i+1; j<tamanio; j++)
            {
                if(criterio==0)
                {
                    if(strcmp(nombres[i], nombres[j])>0)
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }
                else
                {
                    if(strcmp(nombres[i], nombres[j])<0)
                    {
                        strcpy(auxiliarCadena, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxiliarCadena);

                        auxiliarEntero=legajos[i];
                        legajos[i]=legajos[j];
                        legajos[j]=auxiliarEntero;

                        auxiliarEntero=notasUno[i];
                        notasUno[i]=notasUno[j];
                        notasUno[j]=auxiliarEntero;

                        auxiliarEntero=notasDos[i];
                        notasDos[i]=notasDos[j];
                        notasDos[j]=auxiliarEntero;

                        auxiliarFlotante=promedios[i];
                        promedios[i]=promedios[j];
                        promedios[j]=auxiliarFlotante;

                        auxiliarChar=sexos[i];
                        sexos[i]=sexos[j];
                        sexos[j]=auxiliarChar;
                    }
                }

            }
        }

        todoOk=1;

    }
    return todoOk;
}




