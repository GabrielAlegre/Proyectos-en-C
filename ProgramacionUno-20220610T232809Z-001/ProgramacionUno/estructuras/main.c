#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3
//definicion de una estructura:

/*
FORMA CONVENCIONAL
struct alumno
{
    int legajo;
    char nombre[20];
    char sexo;
    int notaUno;
    int notaDos;
    float promedio;
};
*/

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int notaUno;
    int notaDos;
    float promedio;
}eAlumno; //La e es para avisar que es una estructura

void mostrarAlumno(eAlumno x);

int mostrarAlumnos(eAlumno vec[], int tam);

int ordenarAlumosPromedio(eAlumno vec[], int tam);

int ordenarAlumosNombres(eAlumno vec[], int tam);

int main()
{
    //declaro una variable de tipo estructura
    //struct alumno primerAlumno;

    eAlumno primerAlumno={10003, "Julio", 'm', 7, 8 , 7.5};


    eAlumno lista[TAM]={
        {1234,"Jose",'m',8,9,8.500},
        {2345,"Ana",'f',6,7,6.5},
        {6665,"Pablo",'m',5,6,5.5},
    };

    printf("Legajo: %d\n", primerAlumno.legajo);//El '.' seria para acceder a lasvariables de la estructura primerAlumno y despues selecciono la variable que quiero mostrar, en este caso el legajo
    printf("Nombre: %s\n", primerAlumno.nombre);
    printf("Sexo: %c\n", primerAlumno.sexo);
    printf("Primer nota: %d\n", primerAlumno.notaUno);
    printf("Segunda nota: %d\n", primerAlumno.notaDos);
    printf("Promedio: %f\n\n", primerAlumno.promedio);


    printf("%d %s %c %d %d %f\n", primerAlumno.legajo, primerAlumno.nombre, primerAlumno.sexo, primerAlumno.notaUno, primerAlumno.notaDos, primerAlumno.promedio);
/*
    printf("Ingrese legajo: ");
    scanf("%d", &primerAlumno.legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(primerAlumno.nombre);

    printf("Ingrese la primer nota: ");
    scanf("%d", &primerAlumno.notaUno);

    printf("Ingrese la aegunda nota: ");
    scanf("%d", &primerAlumno.notaUno);
*/

    primerAlumno.promedio=(float)(primerAlumno.notaUno+primerAlumno.notaDos)/2;

	mostrarAlumnos(lista,TAM);

	ordenarAlumosNombres(lista,TAM);

	mostrarAlumnos(lista,TAM);

    return 0;
}

void mostrarAlumno(eAlumno x)
{
	printf("\n %d", x.legajo);
	printf("\t %s", x.nombre);
	printf("\t %c",x.sexo);
	printf("\t %d",x.notaUno);
	printf("\t %d",x.notaDos);
	printf("\t %.2f", x.promedio);
	printf("\n");
}

int mostrarAlumnos(eAlumno vec[], int tam)
{
    int todoOk=0;
    if(vec!=NULL && tam>0)
    {
        printf("    *** Listado de Alumnos *** \n");

        printf("Legajo\tNombre\tSexo\tNota1\tNota2\tPromedio\t\n");

        for(int i=0; i<tam; i++)
        {
            mostrarAlumno(vec[i]);
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}

int ordenarAlumosPromedio(eAlumno vec[], int tam)
{
    int todoOk=0;
    eAlumno auxiliar;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(vec[i].promedio<vec[j].promedio)
                {
                    auxiliar=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxiliar;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int ordenarAlumosNombres(eAlumno vec[], int tam)
{
    int todoOk=0;
    eAlumno auxiliar;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(vec[i].nombre,vec[j].nombre)>0)
                {
                    auxiliar=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxiliar;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

