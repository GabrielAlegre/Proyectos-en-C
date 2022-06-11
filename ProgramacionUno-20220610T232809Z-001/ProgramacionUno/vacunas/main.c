/*
Alumno: Gabriel Alegre
Enunciado del ejercicio clase 1:
Se necesita llevar el registro de un vacunatorio.
Para ello se podrá registrar los datos de las personas vacunadas mientras el usuario quiera.
De cada vacunado se solicita:
-nombre (solo inicial)
-edad ( mayor o igual a 12)
-vacuna (“r (rusa)”, “c (china)”, “a (americana)”)
Si la edad esta entre 12 y 17 años ambos incluidos solo se permite la vacuna americana
-dosis (“p” en caso de ser la primer dosis o “s” en caso de ser la segunda dosis)
-sexo( “f” o “m” )
Informar:
a- Promedio de edad de los que se vacunaron con la rusa
b- Nombre y vacuna de la mujer con más edad
c- De las personas que recibieron la vacuna americana que porcentaje son mayores de edad
d- Porcentaje de los que están vacunados con 2 dosis sobre el total de vacunados
e- Vacuna menos inoculada
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int edad;
    char nombre;
    char vacuna;
    char dosis;
    char sexo;
    char condicion;
    int contadorRusa=0;
    int acumuladorEdadRusa=0;
    float promedioEdadRusa=0;
    int banderaPrimerIngreso=0;
    int mujerMasVieja;
    char nombreMujerMasVieja;
    char vacunaMasVieja;
    int contadorAmericana=0;
    int contadorMayoresAmericana=0;
    float porcentajeMayoresAmericana=0;
    int contadorVacunasAplicadas=0;
    int contadorPersonasDosDosis=0;
    float porcentajeDosDosis;
    int contadorChina=0;
    char vacunaMenosInoculada;

    do
    {
        nombre=funcionLetra("Ingrese nombre: ");

        edad=ingresarEntero("Ingrese su edad: ");

        while(edad<12)
        {
            edad=ingresarEntero("Ingrese su edad: ");
        }

        if(edad>17)
        {
            vacuna=funcionLetra("Usted es mayor de edad, puede elegir cualquier vacuna (R (rusa), C (china), A (americana)): ");

            while(vacuna!='R'&&vacuna!='C'&&vacuna!='A')
            {
                vacuna=funcionLetra("Error. Ingrese vacuna (R (rusa), C (china), A (americana)): ");
            }
        }
        else //Si no se cumple la condicion anterior (que sea mayor de edad) es porque la persona tiene si o si entre 12 y 17 anios y por lo tanto le corresponde la vacuna A (americana)
        {
            vacuna=funcionLetra("Usted tiene entre 12 y 17 anios, solo puede elegir la vacuna A (americana): ");

            while(vacuna!='A')
            {
                vacuna=funcionLetra("Error. Ingrese vacuna A (AMERICANA): ");
            }
        }

        dosis=funcionLetra("Ingrese P en caso de ser la primera dosis o S en caso de ser la segunda dosis: ");

        if(dosis=='S')
        {
            contadorPersonasDosDosis++;
        }

        while(dosis!='P'&&dosis!='S')
        {
            dosis=funcionLetra("Error. solo puede ingresar P (primera dosis) o S (segunda dosis): ");
        }

        sexo=funcionLetra("Ingrese sexo F para femenino, M para masculino): ");

        while(sexo!='F'&&sexo!='M')
        {
            sexo=funcionLetra("Error. Ingrese sexo (f, m): ");
        }

        switch(vacuna)
        {
            case 'R':
                contadorRusa++;
                acumuladorEdadRusa+=edad;
                break;
            case 'C':
                contadorChina++;
                break;
            case 'A':
                contadorAmericana++;
                if(edad>17)
                {
                    contadorMayoresAmericana++;
                }
                break;
        }

        //b)Nombre y vacuna de la mujer con más edad
        if (sexo=='F')
        {
            if(edad>mujerMasVieja || banderaPrimerIngreso==0)
            {
                mujerMasVieja=edad;
                nombreMujerMasVieja=nombre;
                vacunaMasVieja=vacuna;
                banderaPrimerIngreso=1;
            }
        }

        contadorVacunasAplicadas++;

        condicion=funcionLetra("Desea continuar? s para continuar: ");

    }while(condicion=='s');


    if(contadorRusa!=0)
    {
        //a)Promedio de edad de los que se vacunaron con la rusa.
        promedioEdadRusa=(float)acumuladorEdadRusa/contadorRusa;
    }

    //b-Nombre y vacuna de la mujer con más edad
    if(banderaPrimerIngreso!=0)
    {
        printf("El nombre de la mujer con mas edad es: %c y se vacuno con: %c\n", nombreMujerMasVieja, vacunaMasVieja);
    }
    else
    {
        printf("No se ingreso ninguna mujer\n");
    }

    if(contadorAmericana!=0)
    {
        //c) De las personas que recibieron la vacuna americana que porcentaje son mayores de edad
        porcentajeMayoresAmericana=(float)contadorMayoresAmericana*100/contadorAmericana;
    }

    //d- Porcentaje de los que están vacunados con 2 dosis sobre el total de vacunados
    porcentajeDosDosis=(float)contadorPersonasDosDosis*100/contadorVacunasAplicadas;

    //e- Vacuna menos inoculada
    if(contadorAmericana<contadorChina && contadorAmericana<contadorRusa)
    {
        vacunaMenosInoculada='A';
    }
    else
    {
        if(contadorChina<contadorRusa)
        {

            vacunaMenosInoculada='C';
        }
        else
        {

            vacunaMenosInoculada='R';
        }
    }

    printf("El promedio de edad de las personas vacunadas con rusa es: %.2f\n", promedioEdadRusa);
    printf("De las personas que recibieron la vacuna americana el porcentaje de los mayores de edad es: %.2f\n", porcentajeMayoresAmericana);
    printf("El porcentaje de los que están vacunados con 2 dosis sobre el total de vacunados es: %.2f\n", porcentajeDosDosis);
    printf("La vacuna menos inoculada es: %c", vacunaMenosInoculada);

    return 0;
}

