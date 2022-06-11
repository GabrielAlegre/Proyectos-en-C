#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "miBibliotecaAlegre.h"

#define NADA 0
#define SALUDO 1
#define BRINDO 2

/*hacer una funcion donde te muestre un menu y pida una opcion,
dicha funcion no debe recibir ningun parametro pero si rertorna(retornaria la opcion elegida)
*/

int main()
{
    char seguir='s';
    int queHizo = NADA;

    do
    {
        switch (menu())
        {
            case 1:
                saludo();
                queHizo=SALUDO;
                break;

            case 2:

                if(queHizo==NADA)
                {
                    printf("Para brindar primero debemos saludarnos\n");
                }
                else
                {
                    if(queHizo==SALUDO)
                    {
                        brindar();
                        queHizo=BRINDO;
                    }
                    else
                    {
                        printf("Para un poco mostro ya brindaste\n");
                    }
                }
                break;

            case 3:
                if(queHizo==BRINDO)
                {
                    despedir();
                    queHizo=NADA;
                }
                else
                {
                    if(queHizo==SALUDO)
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
