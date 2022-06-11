#include <stdio.h>
#include <stdlib.h>
#include "miBiblotecaAlegre.h"

int main()
{
	int a;
	int b;
	int factorialDeA;
	int factorialDeB;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	int ingresoPrimerOperador=0;
	int ingresoSegundoOperador=0;
	int realizoLasOperaciones=0;
    int opcionElegida;
    char salir='n';

    do
    {
        if(!menu(a, b, &ingresoPrimerOperador, &ingresoSegundoOperador, &opcionElegida))
        {
            switch(opcionElegida)
            {
                case 1:
                    if(ingresoPrimerOperador==1)
                    {
                        printf("Ya ingreso como primer operador el numero: %d\n",a);
                    }
                    else
                    {
                        printf("Ingrese el primer operador: ");
                        scanf("%d", &a);
                        ingresoPrimerOperador=1;
                    }
                    break;

                case 2:
                    if(ingresoPrimerOperador==0)
                    {
                        printf("Primero debe ingresar el primer operador\n");
                    }
                    else
                    {
                        if(ingresoSegundoOperador==1)
                        {
                            printf("Ya ingreso como segundo operador el numero: %d\n", b);
                        }
                        else
                        {
                            printf("Ingrese el segundo operador: ");
                            scanf("%d", &b);
                            ingresoSegundoOperador=1;
                        }
                    }
                    break;

                case 3:
                    if(ingresoSegundoOperador==1)
                    {
                        if(!funcionOperaciones(a, b, &suma, &resta, &division, &factorialDeA, &factorialDeB, &multiplicacion))
                        {
                            printf("Se realizaron las operaciones correctamente. Si desea que le informemos los resultados seleccione la opcion 4\n");
                            realizoLasOperaciones=1;
                        }
                        else
                        {
                            printf("No se pudieron hacer las operaciones\n");
                        }
                    }
                    else
                    {
                        if(ingresoPrimerOperador==0)
                        {
                            printf("Debe ingresar ambos operadores para calcular las operaciones\n");
                        }
                        else
                        {
                            printf("Debe ingresar el segundo operador para calcular las operaciones\n");
                        }
                    }
                    break;
                case 4:
                    if(realizoLasOperaciones==1)
                    {
                        if(!funcionInformarResultados(a, b, &suma, &resta, &division, &factorialDeA, &factorialDeB, &multiplicacion))
                        {
                            ingresoPrimerOperador=0;
                            ingresoSegundoOperador=0;
                            realizoLasOperaciones=0;
                        }
                        else
                        {
                            printf("No se puedieron informar los resultados\n");
                        }
                    }
                    else
                    {
                        printf("Para informar los resultados primero debe calcular las operaciones (opcion 3)\n");
                    }
                    break;

                case 5:
                    printf("Esta seguro que desea salir s/n: ");
                    fflush(stdin);
                    scanf("%c",&salir);
                    break;
                default:
                    printf("Opcion invalida!!\n");
                    break;
            }
            system("pause");
        }
        else
        {
            printf("No se pudo inicializar el menu\n");
        }

    }while(salir=='n');

    return 0;
}
