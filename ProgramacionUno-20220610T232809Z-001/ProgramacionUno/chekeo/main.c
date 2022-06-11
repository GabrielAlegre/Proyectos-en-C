#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleado.h"

#define LENGTH 5

int main()
{
    char seguir='s';
    char salir;
    int nextId=1;
    int order=0;
    int option1=0;
    Employee arrayEmployees[LENGTH];
    Employee unEmployees;

    initEmployees(arrayEmployees, LENGTH);

    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                addEmployee(arrayEmployees,
                            LENGTH,
                            nextId,
                            unEmployees.name,
                            unEmployees.lastName,
                            unEmployees.salary,
                            unEmployees.sector);
                nextId++;
                option1=1;
                break;
            case 2:
                if(option1)
                {
                    editEmployee(arrayEmployees, LENGTH);
                }
                else
                {
                   printf("No hay ningún empleado dado de alta para modificar.\n");
                }
                break;
            case 3:
                if(option1)
                {
                    removeEmployee(arrayEmployees, LENGTH, unEmployees.id);
                }
                else
                {
                   printf("No hay ningún empleado dado de alta para dar de baja.\n");
                }

                for(int i=0; i<LENGTH; i++)
                {
                    if(arrayEmployees[i].isEmpty)
                    {
                        option1=0;
                    }
                    else
                    {
                        option1=1;
                        break;
                    }
                }
                break;
            case 4:
                if(option1)
                {
                    sortEmployees(arrayEmployees, LENGTH, order);
                }
                else
                {
                   printf("No hay ningún empleado dado de alta para informar.\n");
                }
                break;
            case 5:
                checkCharacter(&salir, "\nConfirmar salida (S/N): ", "Opción inválida. Confirmar salida (S/N): ", 'S', 'N');

                if(salir=='S')
                {
                    seguir='n';
                }
                break;
            default:
                printf("Opción inválida. Ingrese una opción del 1 al 5.\n");
                fflush(stdin);
                break;
        }
        system("pause");
    }while(seguir=='s');

    return 0;
}
