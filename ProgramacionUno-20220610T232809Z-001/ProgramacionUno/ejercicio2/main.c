#include <stdio.h>
#include <stdlib.h>
//pedir dos numeros y mostrar el promedio de ambos
int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    float promedio;


    printf("Ingrese el numero uno: ");
	scanf("%d", &numeroUno);

	printf("Ingrese el numero dos: ");
	scanf("%d", &numeroDos);

	suma=numeroUno+numeroDos;

	promedio=(float)suma/2; //poner el float en la suma quiere decir que lo estoy casteando (no confundir con parsear) que lo que hace es "trasformar" la suma de int a float para que el promedio de float

	//promedio=(float)(numeroUno+numeroDos)/2; sin usar la variable suma

	//printf("La suma de los dos numeros es: %d", suma);

	printf("El promedio del primer numero (%d) y del segundo numero (%d) es: %.2f", numeroUno, numeroDos, promedio);

    return 0;
}
