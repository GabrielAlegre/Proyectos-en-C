#include "miBiblotecaAlegre.h"
#include <stdio.h>
#include <stdlib.h>

int menu(int x, int y, int banderaPrimerOperador, int banderaSegundoOperador)
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
        printf("1. Ingresar 1er operando (A=%d)\n", x);
    }

    if(banderaSegundoOperador==0)
    {
        printf("2. Ingresar 2do operando (B)\n");
    }
    else
    {
        printf("2. Ingresar 2do operando (B=%d)\n", y);;
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

int funcionSumar(int x, int y)
{
    int resultadoDeLaSuma;

    return resultadoDeLaSuma=x+y;
}

int funcionRestar(int x, int y)
{
    float resultadoDeLaResta;

    return resultadoDeLaResta=x-y;
}

int funcionMultiplicar(int x, int y)
{
    int resultadoDeLaMultiplicacion;

    return resultadoDeLaMultiplicacion=x*y;
}

int funcionDividir(int x, int y, float* pResultadoDeLaDivision)
{
    int SePudoDividir=0;

    if(pResultadoDeLaDivision!=NULL && y!=0)
    {
        *pResultadoDeLaDivision= (float)x/y;
        SePudoDividir=1;
    }
    return SePudoDividir;
}

int funcionFactorial(int z, int* resultadoFactorial)
{
    int factorial=1;
    int SePudoHacerElFactorial=0;
    int i;

    if(resultadoFactorial!= NULL && z>=0)
    {
        for(i=1; i<=z; i++)
        {
            factorial*=i;
        }

        *resultadoFactorial=factorial;
        SePudoHacerElFactorial=1;

    }
    return SePudoHacerElFactorial;
}

int realizarOperaciones(int x, int y, int*suma, int*resta, float*division, int*factorialDeA, int*factorialDeB, int*multiplicacion, int*sePudoDividir, int*seHizoFactorialDeA, int*seHizoFactorialDeB)
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

void informarResultados(int x, int y, int suma, int resta, float division, int factorialDeA, int factorialDeB, int multiplicacion, int sePudoDividir, int seHizoFactorialDeA, int seHizoFactorialDeB)
{
    printf("a) El resultado de %d+%d es: %d\n", x, y, suma);

    printf("b) El resultado de %d-%d es: %d\n", x, y, resta);

    if(sePudoDividir)
    {
        printf("c) El resultado de %d/%d es: %.2f\n", x, y, division);
    }
    else
    {
        printf("c) No se puede dividir por cero\n");
    }

    printf("d) El resultado de %d%d es: %d\n", x, y, multiplicacion);

    if(seHizoFactorialDeA)
    {
        printf("e) El factorial de A (!%d) es: %d ", x, factorialDeA);
    }
    else
    {
        printf("e) El factorial de A no se pudo realizar ");
    }

    if(seHizoFactorialDeB)
    {
        printf("y el factorial de B (!%d) es: %d\n", y, factorialDeB);
    }
    else
    {
        printf("y el factorial de B no se pudo realizar\n");
    }
}





