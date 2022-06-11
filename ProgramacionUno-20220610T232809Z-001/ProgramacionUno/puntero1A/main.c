#include <stdio.h>
#include <stdlib.h>
#include "miBiblotecaAlegre.h"

/*
Punteros:

int w=98

&w -> indica la direccion de memoria de la variable (casi siempre va en los parametros de la funcion que queremos invocar dentro del main)

int* z= &w-> para indicar que esa variable en este caso "z" va a contener una direccion de memoria (casi siempre va en la bibloteca de funciones en el parametro)

*z -> te dice cual es el valor de la direccion de memoria que guarda ese puntero, en este caso z esta guardando la direccion de memoria de w, que a su vez vale 98, por lo que, z va a valer 98 tambien

*/

/*
int main()
{
	float a;
	float b;
	int factorialDeA;
	int factorialDeB;
	float suma;
	float resta;
	float division;
	int factorial;
	float multiplicacion;
	char seguir;


    do
    {



        switch (menu())
        {
            case 1:
                ingresarFloat("Ingrese el primer operador: ")
                break;

            case 2:
                ingresarFloat("Ingrese el segundo operador: ")
                break;

            case 3:
                mostrarMensaje("Ya se realizaron las operaciones")
                break;

            case 4:
                operaciones(&a, &b, &suma, &resta, &division, &factorialDeA, &factorialDeB, &multiplicacion);
                break;

            case 5:
                break;


            	break;
            default:
                printf("OPCION INVALIDA!!!!!!!!!!!!!!!!!!!!!!\n");
                break;
        }




        system("pause");

    }while(seguir=='s');

    return 0;

}
*/


void operaciones(int* a, int* b, int* suma, int* resta, float* division, int* factorialDeA, int* factorialDeB, float* multiplicacion);

int main()
{
    int a=4;
    int b=6;
    int suma;
    int resta;
    float division;
    int factorialDeA=1;
    int factorialDeB=1;
	float multiplicacion;

    operaciones(&a, &b, &suma, &resta, &division, &factorialDeA, &factorialDeB, &multiplicacion);


    return 0;
}

void operaciones(int* a, int* b, int* suma, int* resta, float* division, int* factorialDeA, int* factorialDeB, float* multiplicacion)
{
    *suma= (float)*a+*b;
    *resta= (float)*a-*b;
    *multiplicacion= (float)*a * *b;
    *division= (float)*a / *b;

	int i;

	for(i=1; i<=*a; i++)
	{
		*factorialDeA*=i;
	}

    for(i=1; i<=*b; i++)
	{
		*factorialDeB*=i;
	}

    mostrar("el resultado de la suma es: ", *suma);
    mostrar("el resultado de la resta es: ", *resta);
    mostrar("el resultado de la division es: ", *division);
    mostrar("el resultado de la multiplicacion es: ", *multiplicacion);
    mostrar("el factorial de A es es: ", *factorialDeA);
    mostrar("el factorial de B es es:  ", *factorialDeB);
}

