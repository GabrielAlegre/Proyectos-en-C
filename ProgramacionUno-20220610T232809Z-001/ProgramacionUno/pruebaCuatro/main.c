/*
Enunciado:
Bienvenidos.
debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,
de cada persona debemos optener los siguientes datos:
Nombre,
Obra Social ("PAMI", "OSDE" o "otras"),
edad( solo mayores de edad, mas de 17),
temperatura corporal(validar por favor)
y sexo (validar).
NOTA:el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con OSDE de mas de 60 años.
b) el nombre y temperatura de la mujer soltera mas joven.
c) cuanto sale el viaje total sin descuento.
d) si hay mas del 50% de los pasajeros que pertenecen a PAMI, el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char nombre;
    char obraSocial;
    int edad;
    float temperatura;
    char sexo;
    int precioPorPasajero=600;
    int contadorDePasajeros=0;
    int personasViejasOsde=0;
    char condicion;
    int edadMujerMasJoven;
    char nombreMujerMasJoven;
    float temperaturaMasJoven;
    int banderaPrimerIngreso=0;
    float costeViajeSinDescuento;
    int contadorPami=0;
    float porcentajePami;
    float descuento;
    float costeViajeConDescuento;

    do
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%c", &nombre);
        nombre=toupper(nombre);

        printf("Ingrese obra social (P para Pami, O para Osde, y X para otra): ");
        fflush(stdin);
        scanf("%c", &obraSocial);
        obraSocial=toupper(obraSocial);

        while(obraSocial!='P'&&obraSocial!='O'&&obraSocial!='X')
        {
            printf("Error. Ingrese obra social (P para Pami, O para Osde, y X para otra): ");
            fflush(stdin);
            scanf("%c", &obraSocial);
            obraSocial=toupper(obraSocial);
        }

        printf("Ingrese edad (+17): ");
        scanf("%d", &edad);

        while(edad<18)
        {
            printf("Error. Ingrese edad (+17): ");
            scanf("%d", &edad);
        }

        printf("Ingrese temperatura (positiva): ");
        scanf("%f", &temperatura);

        while(edad<1)
        {
            printf("Error. Ingrese temperatura (positiva): ");
            scanf("%f", &temperatura);
        }

        printf("Ingrese sexo (M para masculino, F para femenino): ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo=toupper(sexo);

        while(sexo!='M'&&sexo!='F')
        {
            printf("Error. Ingrese sexo (M para masculino, F para femenino): ");
            fflush(stdin);
            scanf("%c", &sexo);
            sexo=toupper(sexo);
        }

        //a)La cantidad de personas con OSDE de mas de 60 años.
        if(obraSocial=='O' && edad>60)
        {
            personasViejasOsde++;
        }

        //b) el nombre y temperatura de la mujer soltera mas joven.
        if(sexo=='F')
        {
            if(edad<edadMujerMasJoven || banderaPrimerIngreso==0)
            {
                edadMujerMasJoven=edad;
                temperaturaMasJoven=temperatura;
                nombreMujerMasJoven=nombre;
                banderaPrimerIngreso=1;
            }
        }

        if(obraSocial=='P')
        {
            contadorPami++;
        }

        contadorDePasajeros++;

        printf("desea continuar? S para si N para no: ");
        fflush(stdin);
        scanf("%c", &condicion);
        condicion=toupper(condicion);


    }while(condicion=='S');

    //c) cuanto sale el viaje total sin descuento.
    costeViajeSinDescuento=contadorDePasajeros*precioPorPasajero;

    //si hay mas del 50% de los pasajeros que pertenecen a PAMI, el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
    porcentajePami=contadorPami*100/contadorDePasajeros;

    if(porcentajePami>50)
    {
        descuento=costeViajeSinDescuento*25/100;
        costeViajeConDescuento=costeViajeSinDescuento-descuento;
        printf("Como el 50%% de los pasajeros pertenecen a PAMI se aplico un descuento del 25%% al precio final(%f) ahora el nuevo precio final seria: %f\n", costeViajeSinDescuento, costeViajeConDescuento);
    }

    printf("La cantidad de personas con OSDE de mas de 60 anios son: %d\n", personasViejasOsde);
    printf("El nombre de la mujer mas joven es: %c y su temperatura es de: %f\n", nombreMujerMasJoven, temperaturaMasJoven);
    printf("El precio del viaje sin descuento es de: %f\n", costeViajeSinDescuento);

    return 0;
}
