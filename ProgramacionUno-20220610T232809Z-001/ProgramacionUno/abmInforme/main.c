#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "dataWarehouse.h"
#include "localidad.h"
#include "comida.h"
#include "almuerzo.h"
#include "fecha.h"
#define TAM 20
#define TAM_LOC 5
#define TAM_COMIDA 5
#define TAM_ALMUERZO 50

int menu();

int main()
{
    char seguir='s';
    int nextId=20000;
    int nextIdAlmuerzo=50000;
    ePersona listaDePersonas[TAM];
    eAlmuerzo listaDeAlmuerzos[TAM_COMIDA];

    eLocalidad localidades[TAM_LOC]={

        {1000, "Avellaneda"},
        {1001, "Bernal"},
        {1002, "Quilmes"},
        {1003, "Lanus"},
        {1004, "Sarandi"}
    };

    eComida comidas[TAM_COMIDA]={

        {5000, "Milanesa", 450.70},
        {5001, "Pizza", 400.50},
        {5002, "Ensalada", 530.75},
        {5003, "Fideos", 390.10},
        {5004, "Hamburguesa", 478.40}
    };

    if(inicializarPersonas(listaDePersonas, TAM)==0)
    {
        printf("Ocurrio un problema al inicializar las personas");
    }


    if(inicializarAlmuerzos(listaDeAlmuerzos, TAM_ALMUERZO)==0)
    {
        printf("Ocurrio un problema al inicializar los almuerzos");
    }



    //harcodearPersonas(listaDePersonas, TAM, 8, &nextId);

    do{
        switch(menu())
        {
            case 1:
                if(altaPersona(listaDePersonas, TAM, &nextId, localidades, TAM_LOC)==1)
                {
                    printf("Alta exitosa!!!\n");
                }
                else
                {
                    printf("Hubo problemas al cargar la persona\n");
                }
                break;

            case 2:
                if(BajaPersona(listaDePersonas, TAM, localidades, TAM_LOC)==1)
                {
                    printf("Baja exitosa!!!!\n");
                }
                else
                {
                    printf("Hubo problemas al dar de baja a la persona\n");
                }
                break;

            case 3:
                if(modificarPersonas(listaDePersonas, TAM, localidades, TAM_LOC)==1)
                {
                    printf("modificacion exitosa!!!!\n");
                }
                else
                {
                    printf("Hubo problemas al modificar a la persona\n");
                }
                break;

            case 4:
                if(mostrarPersonas(listaDePersonas, TAM, localidades, TAM_LOC)==0)
                {
                    printf("Ocurrio problemas al mostrar personas\n");
                }
                break;
            case 5:
                if(menuOrdenamientos(listaDePersonas, TAM))
                {
                    printf("El ordenamiento ha sido exitoso\n");
                }
                else
                {
                    printf("No se pudo realizar el ordenamiento\n");
                }
                break;

            case 6:
                if(!informes(listaDePersonas, TAM, localidades, TAM_LOC))
                {
                    printf("Ocurrio un error para informar");
                }
                break;

            case 7:
                system("cls");
                if(!mostrarComidas(comidas, TAM_COMIDA))
                {
                    printf("Ocurrio un error para informar");
                }
                break;
            case 8:
                system("cls");
                if(!mostrarAlmuerzos(listaDeAlmuerzos, TAM_ALMUERZO, listaDePersonas, TAM, localidades, TAM_LOC, comidas, TAM_COMIDA))
                {
                    printf("Ocurrio un error para informar");
                }
                break;
            case 9:
                if(!altaAlmuerzo(listaDeAlmuerzos, TAM_ALMUERZO, listaDePersonas, TAM, localidades, TAM_LOC, comidas, TAM_COMIDA, &nextIdAlmuerzo))
                {
                    printf("Ocurrio un error para informar");
                }
                break;

            case 15:
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
    printf("4- Listar Personas\n");
    printf("5- Ordenar Personas\n");
    printf("6- Informes \n");
    printf("7- Listar comidas\n");
    printf("8- Mostrar Almuerzos \n");
    printf("9- Alta Almuerzo\n");
    /*
    printf("6- Listar mujeres\n");
    printf("7- Listar Localidades\n");
    printf("8- Personas de una localidades\n");//informe
    printf("9- Personas de cada localidad\n");//informe
    printf("10- Promedio edad de varones\n");//informe
    printf("11- Maxima altura en una localidad\n");//informe
    printf("12- Localidad donde vive la mujer mas joven\n");//informe
    */
    printf("15- Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



