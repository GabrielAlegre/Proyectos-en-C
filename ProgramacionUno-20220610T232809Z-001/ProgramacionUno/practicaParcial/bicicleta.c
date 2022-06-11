#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "color.h"
#include "tipo.h"
#include "bibliotecaDeValidaciones.h"

int inicializarBicicletas(eBicicleta arrayBicicletas[], int tamBici)
{
    int todoOk=0;

    if(arrayBicicletas!=NULL && tamBici>0)
    {
        for(int i=0; i<tamBici; i++)
        {
            arrayBicicletas[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(eBicicleta arrayBicicletas[], int tamBici)
{
    int indiceLibre=-1;

    if(arrayBicicletas!=NULL && tamBici>0)
    {
        for(int i=0; i<tamBici; i++)
        {
            if(arrayBicicletas[i].isEmpty)
            {
                indiceLibre=i;
                break;//xq solo necesitamos el PRIMER indice que encontremos libre una vez encontrado no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}

int altaBicicleta(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, int* pIdBici)
{
    int todoOk=0;
    int indiceLibre;
    eBicicleta auxBici;

    if(arrayBicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0 && pIdBici!=NULL)
    {


        system("cls");
        indiceLibre=buscarLibre(arrayBicicletas, tamBici);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de bicicleta   ***             \n");
            printf("--------------------------------------------------------------------------------------\n\n");

            auxBici.id= *pIdBici;
            (*pIdBici)++;

            validarCadena(auxBici.marca, "Ingrese la marca de la bicicleta (max 20 chars): ", "Error, marca demasiada larga o ingreso numeros: ", 20);

            mostrarTipos(tipos, tamTipos);
            validarEntero(&auxBici.idTipo, "Ingrese el id del tipo de la bicicleta: ", "Error. Ingrese el id del tipo de la bicicleta: ", 1000, 1003);

            mostrarColor(colores, tamColores);
            validarEntero(&auxBici.idColor, "Ingrese el id del color de la bicicleta: ", "Error. Ingrese el id del color de la bicicleta: ", 5000, 5004);

            printf("Ingrese rodado (20, 26, 27.5 o 29): ");
            scanf("%f", &auxBici.rodado);
            while(auxBici.rodado!=20 && auxBici.rodado!=26 && auxBici.rodado!=27.5 && auxBici.rodado!=29)
            {
                printf("MAL. Reingrese rodado (20, 26, 27.5 o 29): ");
                scanf("%f", &auxBici.rodado);
            }

            auxBici.isEmpty=0;

            arrayBicicletas[indiceLibre]=auxBici;

            printf("\nExcelente. Se realizo correctamente la alta de la bicicleta: \n");
            printf("Id\tMarca      Tipo       Color\t Rodado\n");
            mostrarUnaBicicleta(arrayBicicletas[indiceLibre], tipos, tamTipos, colores, tamColores);

        }
        todoOk=1;
    }
    return todoOk;
}

void mostrarUnaBicicleta(eBicicleta unaBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    char descripcionTipo[20];
    char descripcionColor[20];

    if(tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        cargarDescripcionColor(colores, tamColores, unaBici.idColor, descripcionColor);
        cargarDescripcionTipo(tipos, tamTipos, unaBici.idTipo, descripcionTipo);

        printf("%d\t%-10s %-10s %-10s %.2f\n",
           unaBici.id,
           unaBici.marca,
           descripcionTipo,
           descripcionColor,
           unaBici.rodado);
    }
}

int mostrarBicicletras(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int todoOk=0;
    if(arrayBicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Bicicleta   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("Id\tMarca      Tipo       Color\t Rodado\n");

        for(int i=0; i<tamBici; i++)
        {
            if(arrayBicicletas[i].isEmpty==0)
            {
                mostrarUnaBicicleta(arrayBicicletas[i], tipos, tamTipos, colores, tamColores);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarBicicletaPorId(eBicicleta arrayBicicletas[], int tamBici, int idBici)
{
    int indiceDeIdEncontrado=-1;
    if(arrayBicicletas!=NULL && tamBici>0)
    {
        for(int i=0; i<tamBici; i++)
        {
            if(arrayBicicletas[i].id==idBici && arrayBicicletas[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}

int bajaBicicleta(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int todoOk=0;
    int idBiciBaja;
    int indiceBiciBajar;
    char confirmacionDeBaja;
    if(arrayBicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        printf("\n");
        mostrarBicicletras(arrayBicicletas, tamBici, tipos, tamTipos, colores, tamColores);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Dar de baja una Bicicleta   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID de la bicicleta a dar de baja: ");
        scanf("%d", &idBiciBaja);

        indiceBiciBajar=buscarBicicletaPorId(arrayBicicletas, tamBici, idBiciBaja);

        if(indiceBiciBajar>=0)
        {
            printf("Id\tMarca      Tipo       Color\t Rodado\n");
            mostrarUnaBicicleta(arrayBicicletas[indiceBiciBajar], tipos, tamTipos, colores, tamColores);

            validarCaracter(&confirmacionDeBaja,
            "Esta seguro que desea dar de baja a esta persona (s/n): ",
            "Respuesta Invalida. 's' para confirmar baja o 'n' para cancelar baja: ",
            's',
            'n');

            if(confirmacionDeBaja=='s')
            {
                arrayBicicletas[indiceBiciBajar].isEmpty=1;
                printf("Baja exitosa!\n");
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
        else
        {
            printf("No se encontro el ID %d\n", idBiciBaja);
        }
    }
    return todoOk;
}

char menuDeModificacion()
{
    char opcion;
    printf("\nQue le desea modificar a la bicicleta: \n");
    printf("A- Modificar Tipo\n");
    printf("B- Modificar Rodado\n");
    printf("C- Cancelar Modificacion\n");

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);

    return opcion;
}


int modificarBicicleta(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int todoOk=0;
    int idBiciModificar;
    int indiceModificarBici;
    char confirmacionModificar;
    char opcionMenuModificacion;
    eBicicleta auxBiciModifir;

    if(arrayBicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        printf("\n");
        mostrarBicicletras(arrayBicicletas, tamBici, tipos, tamTipos, colores, tamColores);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Modificar bicicleta   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID de la bicicleta a modificar: ");
        scanf("%d", &idBiciModificar);

        indiceModificarBici=buscarBicicletaPorId(arrayBicicletas, tamBici, idBiciModificar);

        if(indiceModificarBici>=0)
        {
            printf("Id\tMarca      Tipo       Color\t Rodado\n");

            mostrarUnaBicicleta(arrayBicicletas[indiceModificarBici], tipos, tamTipos, colores, tamColores);

            validarCaracter(&confirmacionModificar,
            "Esta seguro que desea modificar esta bicicleta (s/n): ",
            "Respuesta Invalida. 's' para confirmar modificacion o 'n' para cancelar modificacion: ",
            's',
            'n');

            if(confirmacionModificar=='s')
            {
                opcionMenuModificacion=menuDeModificacion();

                switch(opcionMenuModificacion)
                {
                    case 'A':
                        mostrarTipos(tipos, tamTipos);
                        if(validarEntero(&auxBiciModifir.idTipo, "Ingrese el id modificado del tipo de la bicicleta: ", "Error. Ingrese el id modificado del tipo de la bicicleta: ", 1000, 1003))
                        {
                            arrayBicicletas[indiceModificarBici].idTipo=auxBiciModifir.idTipo;

                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 'B':
                        printf("Ingrese rodado modificado (20, 26, 27.5 o 29): ");
                        scanf("%f", &auxBiciModifir.rodado);
                        while(auxBiciModifir.rodado!=20 && auxBiciModifir.rodado!=26 && auxBiciModifir.rodado!=27.5 && auxBiciModifir.rodado!=29)
                        {
                            printf("MAL. Reingrese rodado modificado (20, 26, 27.5 o 29): ");
                            scanf("%f", &auxBiciModifir.rodado);
                        }

                        arrayBicicletas[indiceModificarBici].rodado=auxBiciModifir.rodado;

                        printf("Modificacion exitosa!!!\n");
                        break;

                    case 'C':
                        printf("Se ha cancelado la modificacion\n");
                        confirmacionModificar='n';
                        break;

                    default:
                        printf("Opcion invalida!!!\n");
                        break;
                }

                if(opcionMenuModificacion<3)
                {
                    printf("\nBicicleta con la modificiacion incluida: \n");
                    printf("Id\tMarca      Tipo       Color\t Rodado\n");
                    mostrarUnaBicicleta(arrayBicicletas[indiceModificarBici], tipos, tamTipos, colores, tamColores);
                }
            }
            else
            {
                printf("Se ha cancelado la modificacion\n");
            }
        }
        else
        {
            printf("No se encontro el ID %d\n", idBiciModificar);
        }
    }
    return todoOk;


}

 int buscarSiHayUnaBicicleta(eBicicleta arrayBicicletas[], int tamBici, int* banderaHayUnaBici)
 {
    int todoOk=0;

    if(arrayBicicletas!=NULL && tamBici>0)
    {
        for(int i=0; i<tamBici; i++)
        {
            if(arrayBicicletas[i].isEmpty==0)
            {
                *banderaHayUnaBici=1;
                break;
            }
            else
            {
                *banderaHayUnaBici=0;
            }
        }
        todoOk=1;
    }
    return todoOk;
 }


int ordenarBicicletas(eBicicleta arrayBicicletas[], int tamBici, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int todoOk=0;
    char descripcionTipoPadre[20];
    char descripcionTipo[20];
    eBicicleta auxiliar;

    if(arrayBicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        for(int i=0; i<tamBici-1; i++)
        {
            for(int j=i+1; j<tamBici; j++)
            {
                cargarDescripcionTipo(tipos, tamTipos, arrayBicicletas[i].idTipo, descripcionTipoPadre);
                cargarDescripcionTipo(tipos, tamTipos, arrayBicicletas[j].idTipo, descripcionTipo);

                //Ascendente
                if(strcmp(descripcionTipoPadre, descripcionTipo)>0 || (strcmp(descripcionTipoPadre, descripcionTipo)==0 && arrayBicicletas[i].rodado>arrayBicicletas[j].rodado))
                {
                    auxiliar=arrayBicicletas[i];
                    arrayBicicletas[i]=arrayBicicletas[j];
                    arrayBicicletas[j]=auxiliar;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}
