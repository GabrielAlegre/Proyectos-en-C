#include "auto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "marca.h"
#include "input.h"


char menu()
{
    char opcion;
    system("cls");

    printf("                *** MENU  ***             \n");
    printf("-----------------------------------------------------------------------\n");
    printf("A- ALTA AUTO\n");
    printf("B- MODIFICAR AUTO\n");
    printf("C- BAJA AUTO\n");
    printf("D- LISTAR AUTOS\n");
    printf("E- LISTAR MARCAS\n");
    printf("F- LISTAR COLORES\n");
    printf("G- LISTAR SERVICIOS\n");
    printf("H- ALTA TRABAJO\n");
    printf("I- LISTAR TRABAJO\n");
    printf("J- INFORMES\n");
    printf("K- SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion=toupper(opcion);

    return opcion;
}



int inicializarAutos(eAuto arrayAutos[], int tamAuto)
{
    int todoOk=0;

    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            arrayAutos[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(eAuto arrayAutos[], int tamAuto)
{
    int indiceLibre=-1;

    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].isEmpty)
            {
                indiceLibre=i;
                break;//xq solo necesitamos el PRIMER indice que encontremos libre una vez encontrado no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}

int altaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int* pIdAuto)
{
    int todoOk=0;
    int indiceLibre;
    eAuto auxAuto;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && pIdAuto!=NULL)
    {
        system("cls");
        indiceLibre=buscarLibre(arrayAutos, tamAuto);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de Autos   ***             \n");
            printf("--------------------------------------------------------------------------------------\n");

            auxAuto.id= *pIdAuto;
            (*pIdAuto)++;

            mostrarMarcas(marcas, tamMarca);
            ingresoEntero(&auxAuto.idMarca, "Ingrese el id de la marca del auto: ", "Error. Ingrese el id de la marca del auto: ", 1000, 1004);

            mostrarColor(colores, tamColor);
            ingresoEntero(&auxAuto.idColor, "Ingrese el id del color de auto: ", "Error. Ingrese el id del color de auto: ", 5000, 5004);

            validarCaracter(&auxAuto.caja, "\nIngrese caja ('m' manual, 'a' automatica): ", "Error. Ingrese caja (“m” manual, “a” automática): ", 'm','a');

            auxAuto.isEmpty=0;

            arrayAutos[indiceLibre]=auxAuto;

            printf("\nExcelente. Se realizo correctamente la alta del auto: \n");
            printf("Id\tMarca      Color     Caja\n");
            mostrarUnAuto(arrayAutos[indiceLibre], marcas, tamMarca, colores, tamColor);
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarUnAuto(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    char descripcionMarca[20];
    char descripcionColor[20];

    if(marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        cargarDescripcionColor(colores, tamColor, unAuto.idColor, descripcionColor);
        cargarDescripcionMarca(marcas, tamMarca, unAuto.idMarca, descripcionMarca);

        printf("%d\t%-10s %-10s %c\n",
           unAuto.id,
           descripcionMarca,
           descripcionColor,
           unAuto.caja);

        todoOk=1;
    }
    return todoOk;
}

int mostrarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=1;
    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Autos   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("Id\tMarca      Color     Caja\n");

        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].isEmpty==0)
            {
                mostrarUnAuto(arrayAutos[i], marcas, tamMarca, colores, tamColor);
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int buscarAutoPorId(eAuto arrayAutos[], int tamAuto, int idAuto)
{
    int indiceDeIdEncontrado=-1;
    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].id==idAuto && arrayAutos[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}

int bajaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    int idAutoBaja;
    int indiceAutoBajar;
    char confirmacionDeBaja;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {


        printf("\n");
        mostrarAutos(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Dar de baja un auto   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID del auto a dar de baja: ");
        scanf("%d", &idAutoBaja);

        indiceAutoBajar=buscarAutoPorId(arrayAutos, tamAuto, idAutoBaja);

        if(indiceAutoBajar>=0)
        {
            printf("Id\tMarca      Color     Caja\n");
            mostrarUnAuto(arrayAutos[indiceAutoBajar], marcas, tamMarca, colores, tamColor);

            validarCaracter(&confirmacionDeBaja,
            "Esta seguro que desea dar de baja a este auto (s/n): ",
            "Respuesta Invalida. 's' para confirmar baja o 'n' para cancelar baja: ",
            's',
            'n');

            if(confirmacionDeBaja=='s')
            {
                arrayAutos[indiceAutoBajar].isEmpty=1;
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
            printf("No se encontro el ID \n");
        }
    }
    return todoOk;
}

char menuDeModificarAuto()
{
    char opcion;
    printf("\nQue le desea modificar al auto: \n");
    printf("A- Color \n");
    printf("B- Marca/Modelo \n");
    printf("C- Cancelar Modificacion\n");

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);

    return opcion;
}

int modificarAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    int idAutoModificar;
    int indiceModificarAuto;
    char confirmacionModificar;
    char opcionMenuModificacion;
    eAuto auxAuto;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        printf("\n");
        mostrarAutos(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Modificar Auto   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID del auto a modificar: ");
        scanf("%d", &idAutoModificar);

        indiceModificarAuto=buscarAutoPorId(arrayAutos, tamAuto, idAutoModificar);

        if(indiceModificarAuto>=0)
        {
            printf("Id\tMarca      Color     Caja\n");

            mostrarUnAuto(arrayAutos[indiceModificarAuto], marcas, tamMarca, colores, tamColor);

            validarCaracter(&confirmacionModificar,
            "Esta seguro que desea modificar este auto (s/n): ",
            "Respuesta Invalida. 's' para confirmar modificacion o 'n' para cancelar modificacion: ",
            's',
            'n');

            if(confirmacionModificar=='s')
            {
                opcionMenuModificacion=menuDeModificarAuto();

                switch(opcionMenuModificacion)
                {
                    case 'A':
                        mostrarColor(colores, tamColor);
                        if(ingresoEntero(&auxAuto.idColor, "Ingrese el id del color a modificar: ", "Error. Ingrese el id modificado del color del auto: ", 5000, 5004))
                        {
                            arrayAutos[indiceModificarAuto].idColor=auxAuto.idColor;

                            printf("Modificacion exitosa!!!\n\n Auto con la modificacion actualizada:\n");

                            mostrarUnAuto(arrayAutos[indiceModificarAuto], marcas, tamMarca, colores, tamColor);
                        }
                        break;

                    case 'B':
                        mostrarMarcas(marcas, tamMarca);
                        if(ingresoEntero(&auxAuto.idMarca, "Ingrese el id marca a modificar: ", "Error. Ingrese el id modificado de la marca del auto: ", 1000, 1004))
                        {
                            arrayAutos[indiceModificarAuto].idMarca=auxAuto.idMarca;

                            printf("Modificacion exitosa!!!\n\n Auto con la modificacion actualizada:\n");

                            mostrarUnAuto(arrayAutos[indiceModificarAuto], marcas, tamMarca, colores, tamColor);
                        }

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
            }
            else
            {
                printf("Se ha cancelado la modificacion\n");
            }
        }
        else
        {
            printf("No se encontro el ID\n");
        }
    }
    return todoOk;
}

 int buscarSiHayUnAuto(eAuto arrayAutos[], int tamAuto, int* banderaHayUnAuto)
 {
    int todoOk=0;

    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].isEmpty==0)
            {
                *banderaHayUnAuto=1;
                break;
            }
            else
            {
                *banderaHayUnAuto=0;
            }
        }
        todoOk=1;
    }
    return todoOk;
 }

 int ordenarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
 {

    int todoOk=0;
    char descripcionMarcaPadre[20];
    char descripcionMarca[20];
    eAuto auxAuto;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        for(int i=0; i<tamAuto-1; i++)
        {
            for(int j=i+1; j<tamAuto; j++)
            {
                cargarDescripcionMarca(marcas, tamMarca, arrayAutos[i].idMarca, descripcionMarcaPadre);
                cargarDescripcionMarca(marcas, tamMarca, arrayAutos[j].idMarca, descripcionMarca);

                //Ascendente
                if(strcmp(descripcionMarcaPadre, descripcionMarca)>0 || (strcmp(descripcionMarcaPadre, descripcionMarca)==0 && arrayAutos[i].id>arrayAutos[j].id))
                {
                    auxAuto=arrayAutos[i];
                    arrayAutos[i]=arrayAutos[j];
                    arrayAutos[j]=auxAuto;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;

 }

int informeMostrarAutosDeUnColor(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
	int colorMostrar;
	char descripcionColor[20];
	if(arrayAutos!=NULL && tamAuto>0 && marcas && tamMarca && colores!=NULL && tamColor>0)
	{
		system("cls");
		mostrarColor(colores, tamColor);
		ingresoEntero(&colorMostrar, "Seleccione el color, y a continuación se mostrará los autos con ese tipo de color(5000-5004): \n", "Error, id no valido. Vuelva a ingresarlo(5000-5004)\n", 5000, 5004);

		cargarDescripcionColor(colores, tamColor, colorMostrar, descripcionColor);

		printf("\nExcelente, usted eligio mostrar los autos del color: %s", descripcionColor);

        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Informe autos del color: %s   ***             \n", descripcionColor);
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Id\tMarca      Color     Caja\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(arrayAutos[i].isEmpty==0 && arrayAutos[i].idColor==colorMostrar)
			{
				mostrarUnAuto(arrayAutos[i],marcas,tamMarca,colores,tamColor);
			}
		}
    todoOk=1;
	}
	return todoOk;
}

int informeMostrarAutosDeUnaMarca(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
	int marcaMostrar;
	char descricionMarca[20];
	if(arrayAutos!=NULL && tamAuto>0 && marcas && tamMarca && colores!=NULL && tamColor>0)
	{
		system("cls");
		mostrarMarcas(marcas, tamMarca);
		ingresoEntero(&marcaMostrar, "Seleccione el color, y a continuación se mostrará los autos con ese tipo de color(5000-5004): \n", "Error, id no valido. Vuelva a ingresarlo(1000-1004)\n", 1000, 1004);

		cargarDescripcionMarca(marcas, tamMarca, marcaMostrar, descricionMarca);

		printf("\nExcelente, usted eligio mostrar los autos de la marca: %s", descricionMarca);

        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Informe autos de la marca: %s   ***             \n", descricionMarca);
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Id\tMarca      Color     Caja\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(arrayAutos[i].isEmpty==0 && arrayAutos[i].idMarca==marcaMostrar)
			{
				mostrarUnAuto(arrayAutos[i],marcas,tamMarca,colores,tamColor);
			}
		}
    todoOk=1;
	}
	return todoOk;
}

int informeAutoMasViejo(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    int banderaAutoMasViejo=0;
    int idDelAutoMasViejo=0;
    int indiceDelAutoMasViejo;


	if(arrayAutos!=NULL && tamAuto>0 && marcas && tamMarca && colores!=NULL && tamColor>0)
	{
		system("cls");

        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Informe del auto mas viejo   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Id\tMarca      Color     Caja\n");

        for(int i=0;i<tamAuto;i++)
		{
			if(arrayAutos[i].isEmpty==0)
			{
                if(banderaAutoMasViejo==0 || arrayAutos[i].id<idDelAutoMasViejo)
                {
                    idDelAutoMasViejo=arrayAutos[i].id;
                    banderaAutoMasViejo=1;
                }
			}
		}
		indiceDelAutoMasViejo=buscarAutoPorId(arrayAutos, tamAuto, idDelAutoMasViejo);
		mostrarUnAuto(arrayAutos[indiceDelAutoMasViejo], marcas, tamMarca, colores, tamColor);

    todoOk=1;
	}
	return todoOk;
}

int mostrarAutosPorIdMarca(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int IdDeLaMarca)
{
    int todoOk=0;
    int bandera=0;

    if(arrayAutos!=NULL && tamAuto>0 && marcas && tamMarca && colores!=NULL && tamColor>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(!arrayAutos[i].isEmpty && arrayAutos[i].idMarca==IdDeLaMarca)
            {
                mostrarUnAuto(arrayAutos[i], marcas, tamMarca, colores, tamColor);
                bandera=1;
            }
        }
        if(bandera==0)
        {
            printf("No hay Autos de esta marca\n");
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

int informeAutosPorMarcas(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
	char descricionMarca[20];

	if(arrayAutos!=NULL && tamAuto>0 && marcas && tamMarca && colores!=NULL && tamColor>0)
	{
        system("cls");

        for(int i=0; i<tamMarca; i++)
        {
            cargarDescripcionMarca(marcas, tamMarca, marcas[i].id, descricionMarca);
            printf("--------------------------------------------------------------------------------------\n");
            printf("                     ***   Lista de los autos marca: %s   ***             \n", descricionMarca);
            printf("--------------------------------------------------------------------------------------\n\n");
            printf("Id\tMarca      Color     Caja\n");

            mostrarAutosPorIdMarca(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor, marcas[i].id);
        }
        todoOk=1;
	}
	return todoOk;
}

int informeCantAutosDeUnColorMarca(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
	int idDeLaMarcaParaContar;
	int idDelColorParaContar;
	char descricionMarca[20];
	char descricionColor[20];
	int contadorDeAutos=0;
	int bandera=0;

	if(arrayAutos!=NULL && tamAuto>0 && marcas && tamMarca && colores!=NULL && tamColor>0)
	{
		system("cls");

		mostrarAutos(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);

		printf("\n");
		mostrarMarcas(marcas, tamMarca);
		ingresoEntero(&idDeLaMarcaParaContar, "Seleccione la marca(1000-1004): ", "Error, id no valido. Vuelva a ingresarlo(1000-1004): ", 1000, 1004);


        mostrarColor(colores, tamColor);
		ingresoEntero(&idDelColorParaContar, "Seleccione el color, y a continuacion se mostraran los autos con ese tipo de color(5000-5004): ", "Error, id no valido. Vuelva a ingresarlo(5000-5004): ", 5000, 5004);

		cargarDescripcionMarca(marcas, tamMarca, idDeLaMarcaParaContar, descricionMarca);

		cargarDescripcionColor(colores, tamColor, idDelColorParaContar, descricionColor);

        printf("\n--------------------------------------------------------------------------------------------------------------\n");
        printf("           ***   Informe Cantidad de autos del color: %s y de la marca: %s   ***             \n", descricionColor, descricionMarca);
        printf("-------------------------------------------------------------------------------------------------------------\n");

        printf("Id\tMarca      Color     Caja\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(arrayAutos[i].isEmpty==0 && arrayAutos[i].idMarca==idDeLaMarcaParaContar && arrayAutos[i].idColor==idDelColorParaContar)
			{
			    contadorDeAutos++;
				mostrarUnAuto(arrayAutos[i],marcas,tamMarca,colores,tamColor);
				bandera=1;
			}
		}
		if(bandera>0)
        {
            printf("\nLa cantidad de autos del color %s y de la marca %s son: %d\n", descricionColor, descricionMarca, contadorDeAutos);
        }
        else
        {
            printf("\nLo siento, no hay autos del color %s y de la marca %s\n", descricionColor, descricionMarca);
        }
        todoOk=1;
	}
	return todoOk;
}

int informeMarcaDeAutoMasElegida(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    int contadores[5]={0};
    int marcaMasElegida=0;
    int flag=0;
    if(arrayAutos!=NULL && tamAuto>0 && marcas && tamMarca && colores!=NULL && tamColor>0)
    {
        system("cls");
        mostrarAutos(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
        printf("\n--------------------------------------------------------------------------------------------------------------\n");
        printf("           ***   Informe marca de auto mas elegida    ***             \n");
        printf("-------------------------------------------------------------------------------------------------------------\n");

        for(int i=0;i<tamMarca;i++)
        {
            for(int j=0;j<tamAuto;j++)
            {
                if(arrayAutos[j].isEmpty==0 &&  marcas[i].id==arrayAutos[j].idMarca)
                {
                    contadores[i]++;
                }
            }
        }

        for(int i=0;i<tamMarca;i++)
        {
            if(contadores[i]>marcaMasElegida || flag==0)
            {
                marcaMasElegida=contadores[i];
                flag=1;
            }
        }

        printf("\nLa/s marca mas elegida: \n");
        for(int i=0; i<tamMarca; i++)
        {
            if(contadores[i]==marcaMasElegida)
            {
                printf("- %s\n", marcas[i].descripcion);
            }
        }
        todoOk=1;
	}
	return todoOk;
}



int informeSoloDeAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int opcion;
    system("cls");


        printf("-----------------------------------------------------------------------------------------\n");
        printf("         *** Informes solo de autos  ***             \n");
        printf("------------------------------------------------------------------------------------------\n");


        printf("1- Mostrar autos del color seleccionado por el usuario.\n");
        printf("2- Mostrar autos de una marca seleccionada.\n");
        printf("3- Informar el o los autos más viejos.\n");
        printf("4- Mostrar un listado de los autos separados por marca.\n");
        printf("5- Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca.\n");
        printf("6- Mostrar la o las marcas más elegidas por los clientes.\n");
        printf("7- Salir\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                informeMostrarAutosDeUnColor(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;

            case 2:
                informeMostrarAutosDeUnaMarca(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;

            case 3:
                 informeAutoMasViejo(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;

            case 4:
                informeAutosPorMarcas(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;

            case 5:
                informeCantAutosDeUnColorMarca(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;

            case 6:
                informeMarcaDeAutoMasElegida(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;

            case 7:
                 //Salir
                 printf("\nChau, chau, adios\n");
                break;

            default:
                printf("\nOpcion Invalida\n!!!!!!");
                break;
        }

    return opcion;
}
