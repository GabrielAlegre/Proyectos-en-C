#ifndef MIBIBLOTECAALEGRE_H_INCLUDED
#define MIBIBLOTECAALEGRE_H_INCLUDED

#endif // MIBIBLOTECAALEGRE_H_INCLUDED

int menu(int x, int y, int banderaPrimerOperador, int banderaSegundoOperador);

int funcionSumar(int x, int y);

int funcionRestar(int x, int y);

int funcionMultiplicar(int x, int y);

int funcionDividir(int x, int y, float*pResultadoDeLaDivision);

int funcionFactorial(int z, int* resultadoFactorial);

int realizarOperaciones(int x, int y, int*suma, int*resta, float*division, int*factorialDeA, int*factorialDeB, int*multiplicacion, int*sePudoDividir, int*seHizoFactorialDeA, int*seHizoFactorialDeB);

void informarResultados(int x, int y, int suma, int resta, float division, int factorialDeA, int factorialDeB, int multiplicacion, int sePudoDividir, int seHizoFactorialDeA, int seHizoFactorialDeB);


