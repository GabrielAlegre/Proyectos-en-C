#include <stdio.h>
#include <stdlib.h>

void calcular (float n1, float n2, int pFunc(float*, float, float));

int dividir (float* resultado, float n1, float n2);

int main()
{
    float n1 = 3.14;
    float n2 = 2.45;

    calcular(n1, n2, dividir);

    return 0;
}

void calcular (float n1, float n2, int pFunc(float*, float, float))
{
    float resultado;

    int retorno;

    retorno = pFunc(&resultado, n1, n2);

    if(retorno == 0)
    {
        printf("no se pudo calcular");

    }
    else
    {
        printf("el resultado de la divicion es: %f", resultado);
    }


}

int dividir (float* resultado, float n1, float n2)
{
    int sePudoCalcular = 0;

    if(n2==0)
    {
        sePudoCalcular=0;

    }
    else
    {
        *resultado=n1/n2;
        sePudoCalcular=1;
    }
    return sePudoCalcular;
}
