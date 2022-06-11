#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "funcionesParaIngresos.h"
#include "hardcode.h"
#include "sector.h"
#define ELEMENTS 17
#define TAM_SECTORES 5
int main()
{
	setbuf(stdout, NULL);
    eEmployee arrayEmployees[ELEMENTS];

    eSector sectores[TAM_SECTORES] = {
        {1, "Finanzas"},
        {2, "Legales"},
        {3, "Recursos humanos"},
        {4, "Marketing"},
        {5, "Mantenimiento"}
    };

    char salir='n';
    int nextId=1;
    int hayUnEmpleado=0;

    if(initEmployees(arrayEmployees, ELEMENTS)==-1)
    {
        printf("Ocurrio un problema al inicializar las personas");
    }
    harcodearPersonas(arrayEmployees, ELEMENTS, 11, &nextId, &hayUnEmpleado);
    do{
        switch(menu())
        {
            case 1:
                if(addEmployee(arrayEmployees, ELEMENTS, &nextId, sectores, TAM_SECTORES)==-1)
                {
                    printf("Error. No se pudo realizar el alta.\n");
                }
                hayUnEmpleado=1;
                nextId++;
                break;

            case 2:
                if(hayUnEmpleado)
                {
                    if(!modifyEmployee(arrayEmployees, ELEMENTS, sectores, TAM_SECTORES))
                    {
                        printf("Error. No se pudo realizar la modificacion.\n");
                    }
                }
                else
                {
                    printf("No hay ningun empleado para modificar, opcion 1 para dar de alta e ingresar un empleado\n");
                }
                break;

            case 3:
                if(hayUnEmpleado)
                {
                    if(!removeEmployee(arrayEmployees, ELEMENTS, sectores, TAM_SECTORES))
                    {
                        printf("Error. No se pudo realizar la baja.\n");
                    }
                }
                else
                {
                    printf("No hay ningun empleado para dar de baja, opcion 1 para dar de alta e ingresar un empleado\n");
                }
                buscarSiHayUnEmpleado(arrayEmployees, ELEMENTS, &hayUnEmpleado);
                break;

            case 4:
                if(hayUnEmpleado)
                {
                    if(!informes(arrayEmployees, ELEMENTS, sectores, TAM_SECTORES))
                    {
                        printf("Error. No se pudo realizar el informe.\n");
                    }
                }
                else
                {
                    printf("No hay ningun empleado para informar, opcion 1 para dar de alta e ingresar un empleado\n");
                }
                break;

            case 5:
                validarCaracter(&salir, "Esta seguro que desea salir s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
                break;
            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        system("pause");

    }while(salir=='n');

    return 0;
}
