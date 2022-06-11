#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "miBiblotecaAlegre.h"


/*hacer una funcion donde te muestre un menu y pida una opcion,
dicha funcion no debe recibir ningun parametro pero si rertorna(retornaria la opcion elegida)
*/

int main()
{
    char seguir='s';
    int flagSaludo=0;
    int flagBrindis=0;

    do
    {
        switch (menu())
        {
            case 1:
                printf("La bandera es: %d\n", flagSaludo);
                saludar();

                setFlag(&flagSaludo, 1);

                printf("La bandera es: %d\n", flagSaludo);
                break;

            case 2:

                if(flagSaludo==1 && flagBrindis==0)
                {
                    brindar();
                    if(setFlag(&flagBrindis, 1))
                    {
                        printf("Hay error no se setio la bandera\n");
                    }
                }
                else
                {
                    if(flagBrindis==1)
                    {

                        printf("Para un poco mostro\n");
                    }
                    else
                    {
                        printf("Para brindar primero debemos saludarnos\n");
                    }
                }
                break;

            case 3:
                if(flagBrindis==1 && flagSaludo==1)
                {
                    despedir();
                    setFlag(&flagBrindis, 0);
                    setFlag(&flagSaludo, 0);
                }
                else
                {
                    if(flagSaludo==1 && flagBrindis==0)
                    {
                        printf("Antes de despedirnos hay que brindar\n");
                    }
                    else
                    {
                        printf("Antes de despedirnos hay que brindar y saludarnos\n");
                    }
                }

                break;
            case 4:
                printf("Quiere cancelar la salida s/n: ");
                fflush(stdin);
                scanf("%c", &seguir);
                seguir=tolower(seguir);

                break;
            default:
                printf("OPCION INVALIDA!!!!!!!!!!!!!!!!!!!!!!\n");
                break;
        }

        system("pause");

    }while(seguir=='s');

}
