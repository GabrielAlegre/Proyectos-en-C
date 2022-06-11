#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f1(int* a)
{

    *a= *a * 2;
    return *a;
}

void f2(int a, int b)
{
    a = f1(&b);
}

int main()
{
    /*
    char cadena[20] = "Mai lopez";
    char* punteroString;
    punteroString=cadena;
    int aux = strlen(cadena);
   // cadena = punteroString; Error no puede asignar un puntero a un string





    printf("%d", aux);

    printf("\n%c", *(cadena+1));

    printf("\n%s", punteroString);

*/
    int a=2, b=2;
    f2( f1(&a), b );

    printf("%d, %d", a+1, b+2);





    //printf("\n%s\n", punteroString);
    return 0;
}
