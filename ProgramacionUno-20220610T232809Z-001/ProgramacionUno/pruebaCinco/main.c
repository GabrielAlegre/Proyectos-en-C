/*
De los 10 empleados de una PYME se ingresan los siguientes datos:
Nombre y apellido
Genero del empleado(Femenino, Masculino, No Binario)
Cantidad de hijos(no puede ser un numero negativo)

El programa debera mostrar:
a) Porcentaje de empleados por cada genero.
b) El nombre del empleado No Binario con mas cantidad de hijos.
c) Nombre y apellido del primer empleado que no tiene hijos.

Sabiendo que:

*Si no tiene hijos no le corresponde asignacion familiar
*Si tiene un hijo le corresponde 5000
*Si tiene dos gijos le corresponde 8000 por sus dos hijos
Y si tiene mas de dos hijos le corresponde 10000

d) Mostrar el total de dinero que debera pagar la PYME en concepto de asignaciones/
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char nombre;
    char sexo;
    int cantidadHijos;
    int iterador;
    float porcentajeFemenino;
    float porcentajeMasculino;
    float porcentajeNoBinario;
    int contadorFemenino=0;
    int contadorMasculino=0;
    int contadorNoBinario=0;
    int mayorCantidadHijosNb;
    char nombreNoBinarioMasHijos;
    int banderaPrimerIngreso=0;
    int banderaPrimerIngresoNoHijos=0;
    char nombrePrimerEmpleadoSinHijos;
    int asignacionFamiliar;
    int acumuladorAsignacion=0;

    for(iterador=0; iterador<3; iterador++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%c", &nombre);
        nombre=toupper(nombre);

        printf("Ingrese sexo (M para masculino, F para femenino N para No Binario): ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo=toupper(sexo);

        while(sexo!='M'&&sexo!='F'&&sexo!='N')
        {
            printf("Error. Ingrese sexo (M para masculino, F para femenino): ");
            fflush(stdin);
            scanf("%c", &sexo);
            sexo=toupper(sexo);
        }

        printf("Ingrese cantidad de hijos (positiva): ");
        scanf("%d", &cantidadHijos);

        while(cantidadHijos<0)
        {
            printf("Error. cantidad de hijos (positiva): ");
            scanf("%d", &cantidadHijos);
        }

        switch(sexo)
        {
            case 'F':
                contadorFemenino++;
                break;

            case 'M':
                contadorMasculino++;
                break;

            default:
                contadorNoBinario++;
                //b) El nombre del empleado No Binario con mas cantidad de hijos.
                if(cantidadHijos>mayorCantidadHijosNb || banderaPrimerIngreso==0)
                {
                    mayorCantidadHijosNb=cantidadHijos;
                    nombreNoBinarioMasHijos=nombre;
                    banderaPrimerIngreso=1;
                }
                break;
        }

        //c) Nombre y apellido del primer empleado que no tiene hijos.
        if(cantidadHijos==0 && banderaPrimerIngresoNoHijos==0)
        {
            nombrePrimerEmpleadoSinHijos=nombre;
            banderaPrimerIngresoNoHijos=1;
        }

        //d) Mostrar el total de dinero que debera pagar la PYME en concepto de asignaciones
        if(cantidadHijos>2)
        {
            asignacionFamiliar=10000;
        }
        else
        {
            if(cantidadHijos==2)
            {
                asignacionFamiliar=8000;
            }
            else
            {
                if(cantidadHijos==1)
                {
                    asignacionFamiliar=5000;
                }
                else
                {
                    asignacionFamiliar=0;
                }
            }
        }
        acumuladorAsignacion+=asignacionFamiliar;


    }
    //Porcentaje de empleados por cada genero.
    porcentajeMasculino=(float)contadorMasculino*100/iterador;
    porcentajeFemenino=(float)contadorFemenino*100/iterador;
    porcentajeNoBinario=(float)contadorNoBinario*100/iterador;

    printf("El porcentaje de empleados femeninos es: %.2f\n el porcentaje de empleados masculinos: %.2f\n el porcentaje de empleados no binarios es: %.2f\n", porcentajeFemenino, porcentajeMasculino, porcentajeNoBinario);
    printf("El nombre del empleado No Binario con mas cantidad de hijos es: %c\n", nombreNoBinarioMasHijos);
    printf("Nombre del primer empleado que no tiene hijos: %c\n", nombrePrimerEmpleadoSinHijos);
    printf("El total de dinero que debera pagar la PYME en concepto de asignaciones es: %d\n", acumuladorAsignacion);

    return 0;
}
