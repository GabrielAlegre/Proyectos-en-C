#include <stdio.h>
#include <stdlib.h>

int swap(int*x, int*y);

int sumar(int a, int b, float*pResultado);

int division(int a, int b, float*pResultado);

int main()
{
    //intercambiar el valor de x e y
    int x=5;
    int y=4;
    float resultado;

    /*
    printf("El valor de X es: %d y el valor de Y es: %d\n\n", x, y);

    //swap(&x, &y);
    if(swap(&x, &y))
    {
        printf("El valor de X ahora es: %d y el valor de Y ahora es: %d\n\n", x, y);
    }
    else
    {
        printf("No se pudo swapear");
    }
    */

    if(sumar(x, y, &resultado))
    {
        printf("La suma %d+%d es: %f\n\n", x, y, resultado);
    }
    else
    {
        printf("No se pudo realizar la suma\n\n");
    }


    if(division(x, y, &resultado))
    {
        printf("La division %d/%d es: %f\n\n", x, y, resultado);
    }
    else
    {
        printf("No se pudo realizar la division\n\n");
    }



    return 0;
}

int swap(int*pA, int*pB)
{
    int auxiliar;
    int noHayError=1;

    if(pA!=NULL && pB!=NULL)
    {
        auxiliar=*pA;

        *pA=*pB;

        *pB=auxiliar;
    }
    else
    {
        noHayError=0;
    }

    return noHayError;
}

int sumar(int a, int b, float*pResultado)
{
    int noHuboError=1;
    if(pResultado!=NULL)
    {
        *pResultado=a+b;
    }
    else
    {
        noHuboError=0;
    }

    return noHuboError;
}

int division(int a, int b, float*pResultado)
{
    int noHuboError=0;

    if(pResultado!=NULL && b!=0)
    {
        *pResultado=(float)a/b;
        noHuboError=1;
    }

    return noHuboError;

}
