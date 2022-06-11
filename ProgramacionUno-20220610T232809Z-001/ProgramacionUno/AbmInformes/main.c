#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    float altura;
    int isEmpty;

}ePersona;

int menu();
// inicializa el campo isEmpy en 1
//1 quiere decir que esta vacio

int menuDeModificacion();

int main()
{
    char seguir='s';
    int nextId=20000;
    ePersona listaDePersonas[TAM];

    if(inicializarPersonas(listaDePersonas, TAM)==0)
    {
        printf("Ocurrio un problema al inicializar las personas");
    }

    do{

        switch(menu())
        {
            case 1:
                if(altaPersona(listaDePersonas, TAM, &nextId)==1)
                {
                    printf("Alta exitosa!!!\n");
                }
                else
                {
                    printf("Hubo problemas al cargar la persona\n");
                }
                break;

            case 2:
                if(BajaPersona(listaDePersonas, TAM)==1)
                {
                    printf("Baja exitosa!!!!\n");
                }
                else
                {
                    printf("Hubo problemas al dar de baja a la persona\n");
                }
                break;

            case 3:
                if(modificarPersonas(listaDePersonas, TAM)==1)
                {
                    printf("modificacion exitosa!!!!\n");
                }
                else
                {
                    printf("Hubo problemas al modificar a la persona\n");
                }
                break;

            case 4:
                if(mostrarPersonas(listaDePersonas, TAM)==0)
                {
                    printf("Ocurrio problemas al mostrar personas\n");
                }
                break;

            case 5:
                printf("Salir Persona\n");
                seguir='n';
                break;
        }
        system("pause");

    }while(seguir=='s');
    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("                *** ABM Persona ***             \n");
    printf("-----------------------------------------------------------------------\n");
    printf("1- Alta Persona\n");
    printf("2- Baja Persona\n");
    printf("3- Modificar Persona\n");
    printf("4- Listar Persona\n");
    printf("5- Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int inicializarPersonas(ePersona arrayDePersonas[], int tam)
{
    int todoOk=0;

    if(arrayDePersonas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            arrayDePersonas[i].isEmpty=1;
        }

        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(ePersona arrayDePersonas[], int tam)
{
    int indiceLibre=-1;

    if(arrayDePersonas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].isEmpty==1)
            {
                indiceLibre=i;
                break;//break Porque solo necesitamos el PRIMER indice que encontremos vacio una vez que lo encontramos no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}
int altaPersona(ePersona arrayDePersonas[], int tam, int* pId)
{
    int todoOk=0;
    int indiceLibre;
    ePersona auxPersona;
    char auxString[150];

    if(arrayDePersonas!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("        ***Alta Persona***      \n");

        indiceLibre=buscarLibre(arrayDePersonas, tam);
        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxPersona.id= *pId;
            (*pId)++;
            //Se tiene que validar todo
            printf("Ingrese nombre persona: ");
            fflush(stdin);
            gets(auxString);
            while(strlen(auxString)>19)
            {
                printf("Error nombre demasiado largo, reingrese nombre: ");
                fflush(stdin);
                gets(auxString);
            }
            strcpy(auxPersona.nombre, auxString);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &auxPersona.sexo);
            while(auxPersona.sexo!='m' && auxPersona.sexo!='f')
            {
                printf("Sexo incorrecto, reingrese sexo: ");
                fflush(stdin);
                scanf("%c", &auxPersona.sexo);
            }

            printf("Ingrese Edad: ");
            scanf("%d", &auxPersona.edad);
            while(auxPersona.edad>110)
            {
                printf("Error. Ingrese Edad: ");
                scanf("%d", &auxPersona.edad);
            }

            printf("Ingrese Altura: ");
            scanf("%f", &auxPersona.altura);
            while(auxPersona.altura>2.40 || auxPersona.altura<0.80)
            {
                printf("Error. Ingrese Altura: ");
                scanf("%f", &auxPersona.altura);
            }

            auxPersona.isEmpty=0;

            arrayDePersonas[indiceLibre]=auxPersona;
            todoOk=1;
        }
    }
    return todoOk;

}

void mostrarUnaPersona(ePersona unaPersona)
{
        printf("%d\t%10s\t%c\t%d\t%.2f\n",
           unaPersona.id,
           unaPersona.nombre,
           unaPersona.sexo,
           unaPersona.edad,
           unaPersona.altura);
}

int mostrarPersonas(ePersona arrayDePersonas[], int tam)
{
    int todoOk=0;
    int flag=1;

    if(arrayDePersonas!=NULL && tam>0)
    {
        system("cls");

        printf("    ***Listado de Personas***   \n");
        printf(" Id        Nombre\tSexo\tEdad\tAltura\n");

        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].isEmpty==0)
            {
                mostrarUnaPersona(arrayDePersonas[i]);
                flag=0;
            }
        }

        if(flag==1)
        {
            printf("No hay nada para mostrar\n");
        }
        todoOk=1;
    }
    return todoOk;
}

int BajaPersona(ePersona arrayDePersonas[], int tam)
{
    int todoOk=0;
    int id;
    int indicePersonaBajar;
    char confirmacionDeBaja;

    if(arrayDePersonas!=NULL && tam>0)
    {
        system("cls");
        printf("        *** Dar de Baja ***      \n");

        printf("Ingrese su ID: ");
        scanf("%d", &id);

        indicePersonaBajar=buscarPersona(arrayDePersonas, tam, id);

        if(indicePersonaBajar>=0)
        {
            mostrarUnaPersona(arrayDePersonas[indicePersonaBajar]);

            printf("Esta seguro que desea dar de baja a esta persona (s/n): ");
            fflush(stdin);
            scanf("%c", &confirmacionDeBaja);

            if(confirmacionDeBaja=='s')
            {
                arrayDePersonas[indicePersonaBajar].isEmpty=1;
            }
            todoOk=1;
        }
        else
        {
            printf("No se encontro el ID: %d\n", id);
        }
    }
    return todoOk;
}
int buscarPersona(ePersona arrayDePersonas[], int tam, int idAbuscar)
{
    int indiceDeIdEncontrado=-1;
    if(arrayDePersonas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].id==idAbuscar && arrayDePersonas[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}

int modificarPersonas(ePersona arrayDePersonas[], int tam)
{
    int todoOk=0;
    int id;
    int indiceAModificar;
    char auxString[150];

    if(arrayDePersonas!=NULL && tam>0)
    {
        system("cls");
        printf("        *** Modificar Persona ***      \n");

        printf("Ingrese su ID: ");
        scanf("%d", &id);

        indiceAModificar=buscarPersona(arrayDePersonas, tam, id);

        if(indiceAModificar>=0)
        {
            printf("\n");
            mostrarUnaPersona(arrayDePersonas[indiceAModificar]);
            printf("\n");

            switch(menuDeModificacion())
            {
                case 1:
                printf("Ingrese el nombre modificado de la persona: ");
                fflush(stdin);
                gets(auxString);
                while(strlen(auxString)>19)
                {
                    printf("Error nombre demasiado largo, reingrese nombre: ");
                    fflush(stdin);
                    gets(auxString);
                }
                strcpy(arrayDePersonas[indiceAModificar].nombre, auxString);
                    break;

                case 2:
                    printf("Ingrese se sexo modificado: ");
                    fflush(stdin);
                    scanf("%c", &arrayDePersonas[indiceAModificar].sexo);
                    while(arrayDePersonas[indiceAModificar].sexo!='m' && arrayDePersonas[indiceAModificar].sexo!='f')
                    {
                        printf("Sexo incorrecto, reingrese sexo: ");
                        fflush(stdin);
                        scanf("%c", &arrayDePersonas[indiceAModificar].sexo);
                    }

                    break;

                case 3:
                    printf("Ingrese su edad modificada: ");
                    scanf("%d", &arrayDePersonas[indiceAModificar].edad);
                    while(arrayDePersonas[indiceAModificar].edad>110)
                    {
                        printf("Error. Ingrese Edad: ");
                        scanf("%d", &arrayDePersonas[indiceAModificar].edad);
                    }

                    break;

                case 4:
                    printf("Ingrese su altura modificada: ");
                    scanf("%f", &arrayDePersonas[indiceAModificar].altura);
                    while(arrayDePersonas[indiceAModificar].altura>2.50)
                    {
                        printf("Error. Ingrese Altura: ");
                        scanf("%f", &arrayDePersonas[indiceAModificar].altura);
                    }
                    break;
            }
            todoOk=1;
        }
        else
        {
            printf("No se encontro el ID: %d\n", id);
        }
    }
    return todoOk;
}

int menuDeModificacion()
{
    int opcion;

    printf("Que desea modificar? elija su respectiva opcion: \n");
    printf("1- Modificar nombre\n");
    printf("2- Modificar Sexo\n");
    printf("3- Modificar Edad\n");
    printf("4- Listar Altura\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
