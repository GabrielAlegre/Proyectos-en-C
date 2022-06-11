/*
La empresa SILKEY necesita liquidar las comisiones de sus 3 vendedores para la zona sur de GBA.
Se cargan las planillas de ventas que poseen los siguientes datos(no sabemos cuantas planillas hay)
*Nombre de vendedor (Juan,Pedro o Maria)
Importe de la venta(numero positivo NO mayor que 10000)
Al terminar de cargar las planillas se debe calcular el total de la comision por vendedor:
Si el vendedor logro recaudar en sus ventas un importe mayor o igual a $50000 obtendra una
comision del 10% sobre ese total.
De no alcanzar esta cifra, su comision sera del 5%.
Mostrar:
a) Importe total de ventas, cantidad de ventas y comision. (Por cada vendedor)
b) El nombre del vendedor que mas dinero recaudo en comisiones
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char nombreVendedor;
    float importe;
    char condicion;
    float acumuladorImporteJuan=0;
    float acumuladorImportePedro=0;
    float acumuladorImporteMaria=0;
    int contadorventasJuan=0;
    int contadorventasPedro=0;
    int contadorventasMaria=0;
    int porcentajeDeComisionJuan;
    int porcentajeDeComisionPedro;
    int porcentajeDeComisionMaria;
    float comisionJuan;
    float comisionMaria;
    float comisionPedro;
    char vendedorMasRecaudo;


    do
    {
        printf("Ingrese nombre del vendedor (J para Juan, P para Pedro, M para Maria): ");
        fflush(stdin);
        scanf("%c", &nombreVendedor);
        nombreVendedor=toupper(nombreVendedor);

        while(nombreVendedor!='J'&&nombreVendedor!='P'&& nombreVendedor!='M')
        {
            printf("Error. Ingrese nombre del vendedor (J para Juan, P para Pedro, M para Maria): ");
            fflush(stdin);
            scanf("%c", &nombreVendedor);
            nombreVendedor=toupper(nombreVendedor);
        }

        printf("Ingrese importe de 0 a 10.000: ");
        scanf("%f", &importe);

        while(importe<1||importe>30000)
        {
            printf("Rrror. Ingrese importe de 0 a 10.000: ");
            scanf("%f", &importe);
        }

        switch(nombreVendedor)
        {
            case 'J':
                acumuladorImporteJuan+=importe;
                contadorventasJuan++;
                break;
            case 'M':
                acumuladorImporteMaria+=importe;
                contadorventasMaria++;
                break;
            case 'P':
                acumuladorImportePedro+=importe;
                contadorventasPedro++;
                break;
        }

        printf("desea continuar? S para si N para no: ");
        fflush(stdin);
        scanf("%c", &condicion);
        condicion=toupper(condicion);

    }while(condicion=='S');

    if(acumuladorImporteJuan>50000)
    {
        porcentajeDeComisionJuan=10;
    }
    else
    {
        porcentajeDeComisionJuan=5;
    }

    if(acumuladorImporteMaria>50000)
    {
        porcentajeDeComisionMaria=10;
    }
    else
    {
        porcentajeDeComisionMaria=5;
    }

    if(acumuladorImportePedro>50000)
    {
        porcentajeDeComisionPedro=10;
    }
    else
    {
        porcentajeDeComisionPedro=5;
    }

    comisionJuan=acumuladorImporteJuan*porcentajeDeComisionJuan/100;
    comisionMaria=acumuladorImporteMaria*porcentajeDeComisionMaria/100;
    comisionPedro=acumuladorImportePedro*porcentajeDeComisionPedro/100;

    if(comisionJuan>comisionMaria&&comisionJuan>comisionPedro)
    {
        vendedorMasRecaudo='J';
    }
    else
    {
        if(comisionMaria>comisionPedro)
        {
            vendedorMasRecaudo='M';
        }
        else
        {
            vendedorMasRecaudo='P';
        }
    }

    printf("El importe total de ventas realizadas por Juan es: %.2f, la cantidad de ventas que realizo son: %d y la comision que le corresponde es: %.2f\n", acumuladorImporteJuan, contadorventasJuan, comisionJuan);
    printf("El importe total de ventas realizadas por Maria es: %.2f, la cantidad de ventas que realizo son: %d y la comision que le corresponde es: %.2f\n", acumuladorImporteMaria, contadorventasMaria, comisionMaria);
    printf("El importe total de ventas realizadas por Pedro es: %.2f, la cantidad de ventas que realizo son: %d y la comision que le corresponde es: %.2f\n", acumuladorImportePedro, contadorventasPedro, comisionPedro);
    printf("El nombre del vendedor que mas dinero recaudo en comisiones es: %c", vendedorMasRecaudo);
    return 0;
}
