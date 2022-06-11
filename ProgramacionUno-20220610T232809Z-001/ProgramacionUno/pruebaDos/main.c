/*
Se necesita un algoritmo que permita el ingreso de alumnos con los siguientes datos:
apellido,
nota (2, 6, 8),
edad (más de 17)
 ...para realizar los siguientes informes:
A) Quién tuvo la nota más alta y cuál fue
B) Quién tuvo la nota más baja y cuál fue
C) Cuántos alumnos aprobaron y deben ir a las clases de repaso (6)
D) Porcentaje de notas (sobre el 100%)------
E) Qué nota fue colocada más veces ----
F) Cuántos alumnos tienen menos de 23 y aprobaron con 8
G) El promedio total de edad
H) Si aprobaron más del 90% de los alumnos, mostrar un mensaje que diga "vamos a tener que avisarle al decano que se copiaron
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char apellido;
    int nota;
    int edad;
    char condicion;
    int notaMasAlta;
    char alumnoNotaMasAlta;
    int banderaNotaAlta=0;
    int notaMasBaja;
    char alumnoNotaMasBaja;
    int banderaNotaBaja=0;
    int contadorAlumnosRepaso=0;
    int contadorNotaDos=0;
    int contadorNotaOcho=0;
    float porcentajeDos;
    float porcentajeSeis;
    float porcentajeOcho;
    int cantidadDeNotasTotales=0;
    int notaMasPuesta;
    int contadorAprobadosJovenes=0;
    int acumuladorEdad=0;
    float promedioEdad;
    int contadorAlumnosAprobados;
    float porcentajeAprobados;


    do
    {
        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%c", &apellido);
        apellido=toupper(apellido);

        printf("Ingrese nota (2, 6, 8): ");
        scanf("%d", &nota);

        while(nota!=2 && nota!=6 && nota!=8)
        {
            printf("Error. Ingrese nota (2, 6, 8): ");
            scanf("%d", &nota);
        }

        cantidadDeNotasTotales++;

        printf("Ingrese edad (mayor de 17): ");
        scanf("%d", &edad);

        acumuladorEdad+=edad;

        while(edad<18)
        {
             printf("Error.Ingrese edad (mayor de 17): ");
             scanf("%d", &edad);
        }
        //A) Quién tuvo la nota más alta y cuál fue
        if(nota>notaMasAlta || banderaNotaAlta==0)
        {
            notaMasAlta=nota;
            alumnoNotaMasAlta=apellido;
            banderaNotaAlta=1;
        }
        //B) Quién tuvo la nota más baja y cuál fue
        if(nota<notaMasBaja || banderaNotaBaja==0)
        {
            notaMasBaja=nota;
            alumnoNotaMasBaja=apellido;
            banderaNotaBaja=1;
        }

        switch(nota)
        {

            case 8:
                contadorNotaOcho++;
                //F) Cuántos alumnos tienen menos de 23 y aprobaron con 8
                if(edad<23)
                {
                    contadorAprobadosJovenes++;
                }
                break;
            //C) Cuántos alumnos aprobaron y deben ir a las clases de repaso (6)
            case 6:
                contadorAlumnosRepaso++;
                break;
            case 2:
                contadorNotaDos++;
                break;
        }

        printf("Desea continuar? S(si) y N(no): ");
        fflush(stdin);
        scanf("%c", &condicion);
        condicion=toupper(condicion);

    }while(condicion=='S');

    //D) Porcentaje de notas (sobre el 100%)
    porcentajeDos=(float)contadorNotaDos*100/cantidadDeNotasTotales;
    porcentajeSeis=(float)contadorAlumnosRepaso*100/cantidadDeNotasTotales;
    porcentajeOcho=(float)contadorNotaOcho*100/cantidadDeNotasTotales;

    //E) Qué nota fue colocada más veces
    if(contadorNotaDos>contadorAlumnosRepaso&&contadorNotaDos>contadorNotaOcho)
    {
        notaMasPuesta=2;
    }
    else
    {
        if(contadorAlumnosRepaso>contadorNotaDos)
        {
            notaMasPuesta=6;
        }
        else
        {
            notaMasPuesta=8;
        }
    }

    //G El promedio total de edad
    promedioEdad=(float)acumuladorEdad/cantidadDeNotasTotales;
    //H Si aprobaron más del 90% de los alumnos, mostrar un mensaje que diga "vamos a tener que avisarle al decano que se copiaron"
    contadorAlumnosAprobados=contadorNotaOcho+contadorAlumnosRepaso;
    porcentajeAprobados=(float)contadorAlumnosAprobados*100/cantidadDeNotasTotales;

    printf("El nombre de la nota mas alta es: %c y se saco un: %d\n", alumnoNotaMasAlta, notaMasAlta);
    printf("El nombre de la nota mas baja es: %c y se saco un: %d\n", alumnoNotaMasBaja, notaMasBaja);
    printf("La cantidad de alumnos aprobaron que deben ir a las clases de repaso(6) son: %d\n", contadorAlumnosRepaso);
    printf("El porcentaje de notas ochos es: %.2f%%\n. El porcentaje de nota seis es: %.2f%%\n. El porcentaje de nota dos es: %.2f%%\n", porcentajeOcho, porcentajeSeis, porcentajeDos);
    printf("La nota mas colocada fue el: %d\n", notaMasPuesta);
    printf("Cuántos alumnos tienen menos de 23 y aprobaron con 8: %d\n", contadorAprobadosJovenes);
    printf("El promedio total de edad es: %.2f\n", promedioEdad);
    if(porcentajeAprobados>90)
    {
        printf("Baia baia.... aprobaron mas de 90%%, vamos a tener que avisarle al decano que se copiaron");
    }
    return 0;
}
