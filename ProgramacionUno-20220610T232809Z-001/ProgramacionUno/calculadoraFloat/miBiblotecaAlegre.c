#include "miBiblotecaAlegre.h"
#include <stdio.h>
#include <stdlib.h>

int funcionMenu(float x, float y, int banderaPrimerOperador, int banderaSegundoOperador)
{
    int opcion;

    system("cls");
    printf("Menu de opciones:\n");
    if(banderaPrimerOperador==0)
    {
        printf("1. Ingresar 1er operando (A)\n");
    }
    else
    {
        printf("1. Ingresar 1er operando (A=%.1f)\n", x);
    }

    if(banderaSegundoOperador==0)
    {
        printf("2. Ingresar 2do operando (B)\n");
    }
    else
    {
        printf("2. Ingresar 2do operando (B=%.1f)\n", y);;
    }

    printf("3. Calcular las operaciones\n");
    printf("   a) Suma (A+B)\n");
    printf("   b) Resta (A-B)\n");
    printf("   c) Division (A/B)\n");
    printf("   d) Multiplicacion (A*B)\n");
    printf("   e) Factorial (A!) y (B!)\n");
    printf("4. Informar resultados \n");
    printf("5. salir \n\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

float funcionSumar(float x, float y)
{
    float resultadoDeLaSuma;

    return resultadoDeLaSuma=x+y;
}

float funcionRestar(float x, float y)
{
    float resultadoDeLaResta;

    return resultadoDeLaResta=x-y;
}

float funcionMultiplicar(float x, float y)
{
    float resultadoDeLaMultiplicacion;

    return resultadoDeLaMultiplicacion=x*y;
}

int funcionDividir(float x, float y, float* pResultadoDeLaDivision)
{
    int SePudoDividir=0;

    if(pResultadoDeLaDivision!=NULL && y!=0)
    {
        *pResultadoDeLaDivision= x/y;
        SePudoDividir=1;
    }
    return SePudoDividir;
}

int funcionFactorial(float numeroIngresado, int* resultadoFactorial)
{
    int factorial=1;
    int enteroDelNumeroIngresado;
    int SePudoHacerElFactorial=0;
    int i;

    enteroDelNumeroIngresado=numeroIngresado;

    if(resultadoFactorial!= NULL && numeroIngresado>=0 && enteroDelNumeroIngresado-numeroIngresado==0)
    {
        for(i=1; i<=numeroIngresado; i++)
        {
            factorial*=i;
        }

        *resultadoFactorial=factorial;
        SePudoHacerElFactorial=1;

    }
    return SePudoHacerElFactorial;
}

int realizarOperaciones(float x, float y, float*suma, float*resta, float*division, int*factorialDeA, int*factorialDeB, float*multiplicacion, int*sePudoDividir, int*seHizoFactorialDeA, int*seHizoFactorialDeB)
{
    int huboError=1;

    if(suma!=NULL && resta!=NULL && division!=NULL && factorialDeA!=NULL && factorialDeB!=NULL && multiplicacion!=NULL && sePudoDividir!=NULL && seHizoFactorialDeA!=NULL && seHizoFactorialDeB!=NULL)
    {
        *suma=funcionSumar(x, y);
        *resta=funcionRestar(x, y);
        *multiplicacion=funcionMultiplicar(x, y);
        *sePudoDividir=funcionDividir(x, y, &*division);
        *seHizoFactorialDeA=funcionFactorial(x, &*factorialDeA);
        *seHizoFactorialDeB=funcionFactorial(y, &*factorialDeB);
        huboError=0;
    }
    return huboError;
}

void informarResultados(float x, float y, float suma, float resta, float division, int factorialDeA, int factorialDeB, float multiplicacion, int sePudoDividir, int seHizoFactorialDeA, int seHizoFactorialDeB)
{
    printf("a) El resultado de %.1f+%.1f es: %.2f\n", x, y, suma);

    printf("b) El resultado de %.1f-%.1f es: %.2f\n", x, y, resta);

    if(sePudoDividir)
    {
        printf("c) El resultado de %.1f/%.1f es: %.2f\n", x, y, division);
    }
    else
    {
        printf("c) No se puede dividir por cero\n");
    }

    printf("d) El resultado de %.1f*%.1f es: %.2f\n", x, y, multiplicacion);

    if(seHizoFactorialDeA)
    {
        printf("e) El factorial de A (!%.0f) es: %d ", x, factorialDeA);
    }
    else
    {
        printf("e) El factorial de A (!%.1f) no se pudo realizar ", x);
    }

    if(seHizoFactorialDeB)
    {
        printf("y el factorial de B (!%.0f) es: %d\n", y, factorialDeB);
    }
    else
    {
        printf("y el factorial de B (!%.1f) no se pudo realizar\n ", y);
    }
}





