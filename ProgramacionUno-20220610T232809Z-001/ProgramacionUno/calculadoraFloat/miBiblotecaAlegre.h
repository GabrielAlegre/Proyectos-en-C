#ifndef MIBIBLOTECAALEGRE_H_INCLUDED
#define MIBIBLOTECAALEGRE_H_INCLUDED

#endif // MIBIBLOTECAALEGRE_H_INCLUDED

int funcionMenu(float x, float y, int banderaPrimerOperador, int banderaSegundoOperador);

float funcionSumar(float x, float y);

float funcionRestar(float x, float y);

float funcionMultiplicar(float x, float y);

int funcionDividir(float x, float y, float* pResultadoDeLaDivision);

int funcionFactorial(float numeroIngresado, int* resultadoFactorial);

int realizarOperaciones(float x, float y, float*suma, float*resta, float*division, int*factorialDeA, int*factorialDeB, float*multiplicacion, int*sePudoDividir, int*seHizoFactorialDeA, int*seHizoFactorialDeB);

void informarResultados(float x, float y, float suma, float resta, float division, int factorialDeA, int factorialDeB, float multiplicacion, int sePudoDividir, int seHizoFactorialDeA, int seHizoFactorialDeB);


