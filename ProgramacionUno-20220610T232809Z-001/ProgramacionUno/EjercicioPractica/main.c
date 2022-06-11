#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
Luego de la campaña de vacunación “COVID19” se realizó un censo sobre la población para obtener distintos datos estadísticos:
Se ingresará hasta que usuario decida:
Nombre.
Edad.
Género: “F”, “M”, “NB”.
Vacuna: “SputnikV”, “AstraZeneca”, “Otra”.
Temperatura corporal (durante la primera noche).
Se pide:
a) El nombre y vacuna de la persona con mayor temperatura.
b) Cuántas personas de género Femenino recibieron la vacuna SputnikV.
c) La cantidad de personas de género No Binario que recibieron AstraZeneca u Otra.
d) Cuántas personas que se aplicaron la vacuna AstraZeneca, presentaron una temperatura mayor a 38°.
e) El promedio de edad de los hombres que se aplicaron la vacuna SputnikV y no presentaron fiebre. (37° o menos)
f) Porcentaje de personas que se aplicaron Aztrazeneca
g) Cual fue la vacuna mas aplicada
h) Promedio de edad de las personas que se dieron cada vacuna
i) Que porcentaje de personas de cada genero hay. Ej: 30% Femenino, 60% Masculino y 10% No Binario
*/
int main()
{
    char nombre;
    int edad;
    char sexo;
    char vacuna;
    float temperatura;
    char condicion;
    char nombreMayorTemperatura;
    char vacunaMayorTemperatura;
    int mayorTemperatura;
    int banderaPrimerIngreso=0;
    int contadorSputnikV=0;
    int contadorAstraZeneca=0;
    int contadorOtra=0;
    int contadorSputnikMujer=0;
    int contadorPersonasVacunasNoSputnik=0;
    int temperaturaAltaAstraZeneca=0;
    int acumuladorEdadSputnikSinFiebre=0;
    int contadorSputnikSinFiebre=0;
    float promedioHombresSinFiebre;
    int contadorPersonasVacunadas=0;
    float porcentajeAstraZeneca;
    char vacunaMasAplica;
    int acumuladorEdadSputnik=0;
    int acumuladorEdadAstraZeneca=0;
    int acumuladorEdadOtra=0;
    float promedioEdadSputnik;
    float PromedioEdadAstraZeneca;
    float PromedioEdadOtra;
    int contadorPersonasNb=0;
    int contadorPersonasHombres=0;
    int contadorPersonasMujeres=0;
    float porcentajePersonasNb;
    float porcentajePersonasHombres;
    float porcentajePersonasMujeres;


    do
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%c", &nombre);

        printf("Ingrese edad: ");
        scanf("%d", &edad);

        while(edad<1)
        {
            printf("Error. Ingrese edad: ");
            scanf("%d", &edad);
        }

        printf("Ingresa el sexo F para femenino M para masculino N para no binario: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo=toupper(sexo);

        while(sexo!='F'&&sexo!='M'&&sexo!='N')
        {
            printf("Error. Ingresa el sexo F para femenino M para masculino N para no binario: ");
            fflush(stdin);
            scanf("%c", &sexo);
            sexo=toupper(sexo);
        }

        printf("Ingrese vacuna S para SputnikV A para AstraZeneca O para Otra: ");
        fflush(stdin);
        scanf("%c", &vacuna);
        vacuna=toupper(vacuna);

        printf("Ingrese temperatura: ");
        scanf("%f", &temperatura);

        while(temperatura<1)
        {
            printf("Error. Ingrese temperatura: ");
            scanf("%f", &temperatura);
        }

        //a) El nombre y vacuna de la persona con mayor temperatura.
        if(temperatura>mayorTemperatura || banderaPrimerIngreso==0)
        {
            mayorTemperatura=temperatura;
            nombreMayorTemperatura=nombre;
            vacunaMayorTemperatura=vacuna;
            banderaPrimerIngreso=1;
        }

        //b) Cuántas personas de género Femenino recibieron la vacuna SputnikV.
        switch(vacuna)
        {
            case 'S':
                contadorSputnikV++;
                acumuladorEdadSputnik+=edad;
                if(sexo=='F')
                {
                    contadorSputnikMujer++;
                }
                else
                {
                    if(sexo=='M' && temperatura<38)
                    {
                        acumuladorEdadSputnikSinFiebre+=edad;
                        contadorSputnikSinFiebre++;
                    }

                }
                break;

            case 'A':
                contadorAstraZeneca++;
                acumuladorEdadAstraZeneca+=edad;
                //d) Cuántas personas que se aplicaron la vacuna AstraZeneca, presentaron una temperatura mayor a 38°.
                if(temperatura>38)
                {
                    temperaturaAltaAstraZeneca++;
                }

                break;

            case 'O':
                acumuladorEdadOtra+=edad;
                contadorOtra++;
                break;
        }
        //c) La cantidad de personas de género No Binario que recibieron AstraZeneca u Otra.
        if(vacuna!='S' && sexo=='N')
        {
            contadorPersonasVacunasNoSputnik++;
        }

        //i) Que porcentaje de personas de cada genero hay. Ej: 30% Femenino, 60% Masculino y 10% No Binario
        if(sexo=='F')
        {
            contadorPersonasMujeres++;
        }
        else
        {
           if(sexo=='M')
           {
               contadorPersonasHombres++;
           }
           else
           {
               contadorPersonasNb++;
           }
        }

        contadorPersonasVacunadas++;

       printf("Desea continuar? s para continuar: ");
       fflush(stdin);
       scanf("%c", &condicion);


    }while(condicion=='s');

    //e) El promedio de edad de los hombres que se aplicaron la vacuna SputnikV y no presentaron fiebre. (37° o menos)
    promedioHombresSinFiebre=(float)acumuladorEdadSputnikSinFiebre/contadorSputnikSinFiebre;

    //f) Porcentaje de personas que se aplicaron Aztrazeneca
    porcentajeAstraZeneca=(float)(contadorAstraZeneca*100)/contadorPersonasVacunadas;

    //g) Cual fue la vacuna mas aplicada
    if(contadorAstraZeneca>contadorOtra&&contadorAstraZeneca>contadorSputnikV)
    {
        vacunaMasAplica='A';
    }
    else
    {
        if(contadorOtra>contadorSputnikV)
        {
            vacunaMasAplica='O';
        }
        else
        {
            vacunaMasAplica='S';
        }
    }

    //h) Promedio de edad de las personas que se dieron cada vacuna
    promedioEdadSputnik=(float)acumuladorEdadSputnik/contadorSputnikV;
    PromedioEdadAstraZeneca=(float)acumuladorEdadAstraZeneca/contadorAstraZeneca;
    PromedioEdadOtra=(float)acumuladorEdadOtra/contadorOtra;

    //i) Que porcentaje de personas de cada genero hay. Ej: 30% Femenino, 60% Masculino y 10% No Binario
    porcentajePersonasHombres=(float)(contadorPersonasHombres*100)/contadorPersonasVacunadas;
    porcentajePersonasMujeres=(float)(contadorPersonasMujeres*100)/contadorPersonasVacunadas;
    porcentajePersonasNb=(float)(contadorPersonasNb*100)/contadorPersonasVacunadas;

    printf("el nombre de la persona con mayor temperatura es: %c y la vacuna que se aplico fue: %c\n", nombreMayorTemperatura, vacunaMayorTemperatura);
    printf("Cuántas personas de género Femenino recibieron la vacuna SputnikV: %d\n", contadorSputnikMujer);
    printf("La cantidad de personas de género No Binario que recibieron AstraZeneca u Otra: %d\n",contadorPersonasVacunasNoSputnik);
    printf("Cuántas personas que se aplicaron la vacuna AstraZeneca, presentaron una temperatura mayor a 38°: %d\n", temperaturaAltaAstraZeneca);
    printf("Porcentaje de personas que se aplicaron Aztrazeneca: %f\n", porcentajeAstraZeneca);
    printf("La vacuna mas aplicada fue: %c\n", vacunaMasAplica);
    printf("El porcentaje de personas femeninas es: %f\n. El porcentaje de hombres es: %f\n. El porcentaje de no binarios es: %f\n", porcentajePersonasMujeres, porcentajePersonasHombres, porcentajePersonasNb);


    if(acumuladorEdadSputnikSinFiebre!=0)
    {
        printf("El promedio de edad de los hombres que se aplicaron la vacuna SputnikV y no presentaron fiebre es: %f\n", promedioHombresSinFiebre);
    }
    else
    {
        printf("El promedio de edad de los hombres que se aplicaron la vacuna SputnikV y no presentaron fiebre: no se puede calcular\n");
    }

    if(acumuladorEdadSputnik!=0)
    {
        printf("Promedio de edad de las personas que se dieron la vacuna Sputnik es: %f\n", promedioEdadSputnik);
    }
    else
    {
        printf("Promedio de edad de las personas que se dieron la vacuna Sputnik: no se puede calcular\n");
    }

    if(acumuladorEdadOtra!=0)
    {
        printf("Promedio de edad de las personas que se dieron la vacuna otra es: %f\n", PromedioEdadOtra);
    }
    else
    {
        printf("Promedio de edad de las personas que se dieron la vacuna otra: no se puede calcular\n");
    }

    if(acumuladorEdadAstraZeneca!=0)
    {
        printf("Promedio de edad de las personas que se dieron la vacuna AstraZeneca es: %f\n", PromedioEdadAstraZeneca);
    }
    else
    {
        printf("Promedio de edad de las personas que se dieron la vacuna AstraZeneca: no se puede calcular\n");
    }
    return 0;
}
