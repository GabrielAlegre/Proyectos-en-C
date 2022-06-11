#include "miBiblotecaAlegre.h"
#include <stdio.h>
#include <stdlib.h>

int menu(int x, int y, int* banderaPrimerOperador, int* banderaSegundoOperador, int* opcion)
{
    int huboError=1;
    int aux;

    if(banderaPrimerOperador!=NULL && banderaSegundoOperador!=NULL && opcion!=NULL)
    {
        system("cls");
        printf("Menu de opciones:\n");
        if(*banderaPrimerOperador==0)
        {
            printf("1. Ingresar 1er operando (A)\n");
        }
        else
        {
            printf("1. Ingresar 1er operando (A=%d)\n", x);
        }

        if(*banderaSegundoOperador==0)
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
        printf("5. salir \n");

        printf("ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &aux);

        *opcion=aux;
        huboError=0;
    }
    return huboError;
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
    int huboError=1;

    if(pResultadoDeLaDivision!=NULL && y!=0)
    {
        *pResultadoDeLaDivision= (float)x/y;
        huboError=0;
    }
    return huboError;
}

int funcionFactorial(int z, int* resultadoFactorial)
{
    *resultadoFactorial=1;
    int huboError=1;
    int i;

    if(resultadoFactorial!= NULL && z>0)
    {
        for(i=1; i<=z; i++)
        {
            *resultadoFactorial*=i;
            huboError=0;
        }
    }
    return huboError;
}

int funcionOperaciones(int x, int y, int*suma, int*resta, float*division, int*factorialDeA, int*factorialDeB, int*multiplicacion)
{
    int huboError=1;

    if(suma!=NULL && resta!=NULL && division!=NULL && factorialDeA!=NULL && factorialDeB!=NULL && multiplicacion!=NULL)
    {
        *suma=funcionSumar(x, y);
        *resta=funcionRestar(x, y);
        *multiplicacion=funcionMultiplicar(x, y);
        funcionDividir(x, y, &*division);
        funcionFactorial(x, &*factorialDeA);
        funcionFactorial(y, &*factorialDeB);
        huboError=0;
    }
    return huboError;
}

int funcionInformarResultados(int x, int y, int*suma, int*resta, float*division, int*factorialDeA, int*factorialDeB, int*multiplicacion)
{
    int huboError=1;

    if(suma!=NULL && resta!=NULL && division!=NULL && factorialDeA!=NULL && factorialDeB!=NULL && multiplicacion!=NULL)
    {
        printf("a) El resultado de %d+%d es: %d\n", x, y, *suma);

        printf("b) El resultado de %d-%d es: %d\n", x, y, *resta);

        if(!funcionDividir(x, y, &*division))
        {
            printf("c) El resultado de %d/%d es: %.2f\n", x, y, *division);
        }
        else
        {
            printf("c) No se puede dividir por cero\n");
        }

        printf("d) El resultado de %d*%d es: %d\n", x, y, *multiplicacion);

        if(!funcionFactorial(x, &*factorialDeA))
        {
            printf("e) El factorial de A (!%d) es: %d ", x, *factorialDeA);
        }
        else
        {
            printf("e) No se pudo realizar el factorial de A ");
        }

        if(!funcionFactorial(y, &*factorialDeB))
        {
            printf("y el factorial de B (!%d) es: %d\n", y, *factorialDeB);
        }
        else
        {
            printf("y no se pudo realizar el factorial de B\n");
        }

        huboError=0;

    }
    return huboError;
}





