#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int inicializarPersonas(ePersona arrayDePersonas[], int tam)
{
    int todoOk=0;

    if(arrayDePersonas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            arrayDePersonas[i].isEmpty=1;
        }

        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(ePersona arrayDePersonas[], int tam)
{
    int indiceLibre=-1;

    if(arrayDePersonas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].isEmpty==1)
            {
                indiceLibre=i;
                break;//break Porque solo necesitamos el PRIMER indice que encontremos vacio una vez que lo encontramos no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}
int altaPersona(ePersona arrayDePersonas[], int tam, int* pId, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int indiceLibre;
    ePersona auxPersona;
    char auxString[150];

    if(arrayDePersonas!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("        ***Alta Persona***      \n");

        indiceLibre=buscarLibre(arrayDePersonas, tam);
        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxPersona.id= *pId;
            (*pId)++;
            //Se tiene que validar todo
            printf("Ingrese nombre persona: ");
            fflush(stdin);
            gets(auxString);
            while(strlen(auxString)>19)
            {
                printf("Error nombre demasiado largo, reingrese nombre: ");
                fflush(stdin);
                gets(auxString);
            }
            strcpy(auxPersona.nombre, auxString);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &auxPersona.sexo);
            while(auxPersona.sexo!='m' && auxPersona.sexo!='f')
            {
                printf("Sexo incorrecto, reingrese sexo: ");
                fflush(stdin);
                scanf("%c", &auxPersona.sexo);
            }

            printf("Ingrese Edad: ");
            scanf("%d", &auxPersona.edad);
            while(auxPersona.edad>110)
            {
                printf("Error. Ingrese Edad: ");
                scanf("%d", &auxPersona.edad);
            }

            printf("Ingrese Altura: ");
            scanf("%f", &auxPersona.altura);
            while(auxPersona.altura>2.40 || auxPersona.altura<0.80)
            {
                printf("Error. Ingrese Altura: ");
                scanf("%f", &auxPersona.altura);
            }

            mostrarLocalidades(arrayLocalidades, tamLoc);
            printf("Ingrese id localidad: ");
            scanf("%d", &auxPersona.idLocalidad);

            while(!validadLocalidad(arrayLocalidades, tamLoc, auxPersona.idLocalidad))
            {
                mostrarLocalidades(arrayLocalidades, tamLoc);
                printf("Id de localidad incorrecto ingrese nuevamente el id: ");
                scanf("%d", &auxPersona.idLocalidad);
            }

            auxPersona.isEmpty=0;

            arrayDePersonas[indiceLibre]=auxPersona;
            todoOk=1;
        }
    }
    return todoOk;

}

void mostrarUnaPersona(ePersona unaPersona, eLocalidad arrayLocalidades[], int tamLoc)
{
    char nombreLocalidad[20];

    cargarDescripcionLocalidad(arrayLocalidades, tamLoc, unaPersona.idLocalidad, nombreLocalidad);
    printf("%d\t%10s\t%c\t%d\t%.2f\t%10s\n",
           unaPersona.id,
           unaPersona.nombre,
           unaPersona.sexo,
           unaPersona.edad,
           unaPersona.altura,
           nombreLocalidad);
}

int mostrarPersonas(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int flag=1;

    if(arrayDePersonas!=NULL && tam>0)
    {
        system("cls");

        printf("    ***Listado de Personas***   \n");
        printf(" Id        Nombre\tSexo\tEdad\tAltura\tLocalidad\n");

        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].isEmpty==0)
            {
                mostrarUnaPersona(arrayDePersonas[i], arrayLocalidades, tamLoc);
                flag=0;
            }
        }

        if(flag==1)
        {
            printf("No hay nada para mostrar\n");
        }
        todoOk=1;
    }
    return todoOk;
}

int BajaPersona(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int id;
    int indicePersonaBajar;
    char confirmacionDeBaja;

    if(arrayDePersonas!=NULL && tam>0)
    {
        mostrarPersonas(arrayDePersonas, tam, arrayLocalidades, tamLoc);

        printf("\n");

        printf("        *** Dar de Baja ***      \n");

        printf("Ingrese el ID de la persona a dar de baja: ");
        scanf("%d", &id);

        indicePersonaBajar=buscarPersona(arrayDePersonas, tam, id);

        if(indicePersonaBajar>=0)
        {
            mostrarUnaPersona(arrayDePersonas[indicePersonaBajar], arrayLocalidades, tamLoc);

            printf("Esta seguro que desea dar de baja a esta persona (s/n): ");
            fflush(stdin);
            scanf("%c", &confirmacionDeBaja);

            if(confirmacionDeBaja=='s')
            {
                arrayDePersonas[indicePersonaBajar].isEmpty=1;
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }

        }
        else
        {
            printf("No se encontro el ID: %d\n", id);
        }
    }
    return todoOk;
}
int buscarPersona(ePersona arrayDePersonas[], int tam, int idAbuscar)
{
    int indiceDeIdEncontrado=-1;
    if(arrayDePersonas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].id==idAbuscar && arrayDePersonas[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}

int modificarPersonas(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int id;
    int indiceAModificar;
    char auxString[150];
    char confirmacionModificar;

    if(arrayDePersonas!=NULL && tam>0)
    {
        system("cls");
        printf("        *** Modificar Persona ***      \n");

        printf("Ingrese su ID: ");
        scanf("%d", &id);

        indiceAModificar=buscarPersona(arrayDePersonas, tam, id);

        if(indiceAModificar>=0)
        {
            printf("\n");
            mostrarUnaPersona(arrayDePersonas[indiceAModificar], arrayLocalidades, tamLoc);
            printf("\n");


            printf("Confirma la modificacion?:  ");
            fflush(stdin);
            scanf("%c", &confirmacionModificar);

            if(confirmacionModificar=='s')
            {
                switch(menuDeModificacion())
                {
                case 1:
                    printf("Ingrese el nombre modificado de la persona: ");
                    fflush(stdin);
                    gets(auxString);
                    while(strlen(auxString)>19)
                    {
                        printf("Error nombre demasiado largo, reingrese nombre: ");
                        fflush(stdin);
                        gets(auxString);
                    }
                    strcpy(arrayDePersonas[indiceAModificar].nombre, auxString);
                    break;

                case 2:
                    printf("Ingrese se sexo modificado: ");
                    fflush(stdin);
                    scanf("%c", &arrayDePersonas[indiceAModificar].sexo);
                    while(arrayDePersonas[indiceAModificar].sexo!='m' && arrayDePersonas[indiceAModificar].sexo!='f')
                    {
                        printf("Sexo incorrecto, reingrese sexo: ");
                        fflush(stdin);
                        scanf("%c", &arrayDePersonas[indiceAModificar].sexo);
                    }

                    break;

                case 3:
                    printf("Ingrese su edad modificada: ");
                    scanf("%d", &arrayDePersonas[indiceAModificar].edad);
                    while(arrayDePersonas[indiceAModificar].edad>110)
                    {
                        printf("Error. Ingrese Edad: ");
                        scanf("%d", &arrayDePersonas[indiceAModificar].edad);
                    }

                    break;

                case 4:
                    printf("Ingrese su altura modificada: ");
                    scanf("%f", &arrayDePersonas[indiceAModificar].altura);
                    while(arrayDePersonas[indiceAModificar].altura>2.50)
                    {
                        printf("Error. Ingrese Altura: ");
                        scanf("%f", &arrayDePersonas[indiceAModificar].altura);
                    }
                    break;
                default:
                    printf("Opcion invalida");
                    break;
                }
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion\n");
            }
        }
        else
        {
            printf("No se encontro el ID: %d\n", id);
        }
    }
    return todoOk;
}

int menuDeModificacion()
{
    int opcion;

    printf("Que desea modificar? elija su respectiva opcion: \n");
    printf("1- Modificar nombre\n");
    printf("2- Modificar Sexo\n");
    printf("3- Modificar Edad\n");
    printf("4- Listar Altura\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int ordenarPersonas(ePersona arrayDePersonas[], int tam, int campo)
{
    int todoOk=0;
    ePersona auxiliar;
    if(arrayDePersonas!=NULL && tam>0 && campo>0 && campo<8)
    {
        switch (campo)
        {
        case 1:
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(arrayDePersonas[i].edad>arrayDePersonas[j].edad)
                    {
                        auxiliar=arrayDePersonas[i];
                        arrayDePersonas[i]=arrayDePersonas[j];
                        arrayDePersonas[j]=auxiliar;
                    }
                }
            }
            break;

        case 2:
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(arrayDePersonas[i].sexo>arrayDePersonas[j].sexo)
                    {
                        auxiliar=arrayDePersonas[i];
                        arrayDePersonas[i]=arrayDePersonas[j];
                        arrayDePersonas[j]=auxiliar;
                    }
                }
            }
            break;

        case 3:
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(arrayDePersonas[i].altura>arrayDePersonas[j].altura)
                    {
                        auxiliar=arrayDePersonas[i];
                        arrayDePersonas[i]=arrayDePersonas[j];
                        arrayDePersonas[j]=auxiliar;
                    }
                }
            }

            break;

        case 4:
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(strcmp(arrayDePersonas[i].nombre, arrayDePersonas[j].nombre)>0)
                    {
                        auxiliar=arrayDePersonas[i];
                        arrayDePersonas[i]=arrayDePersonas[j];
                        arrayDePersonas[j]=auxiliar;
                    }
                }
            }
            break;

        case 5:
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(arrayDePersonas[i].sexo==arrayDePersonas[j].sexo && arrayDePersonas[i].edad>arrayDePersonas[j].edad)
                    {
                        auxiliar=arrayDePersonas[i];
                        arrayDePersonas[i]=arrayDePersonas[j];
                        arrayDePersonas[j]=auxiliar;
                    }
                    else
                    {
                        if(arrayDePersonas[i].sexo!=arrayDePersonas[j].sexo && arrayDePersonas[i].sexo>arrayDePersonas[j].sexo)
                        {
                            auxiliar=arrayDePersonas[i];
                            arrayDePersonas[i]=arrayDePersonas[j];
                            arrayDePersonas[j]=auxiliar;
                        }
                    }
                }

            }
            break;
        case 6:
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(arrayDePersonas[i].sexo==arrayDePersonas[j].sexo && arrayDePersonas[i].altura>arrayDePersonas[j].altura)
                    {
                        auxiliar=arrayDePersonas[i];
                        arrayDePersonas[i]=arrayDePersonas[j];
                        arrayDePersonas[j]=auxiliar;
                    }
                    else
                    {
                        if(arrayDePersonas[i].sexo!=arrayDePersonas[j].sexo && arrayDePersonas[i].sexo>arrayDePersonas[j].sexo)
                        {
                            auxiliar=arrayDePersonas[i];
                            arrayDePersonas[i]=arrayDePersonas[j];
                            arrayDePersonas[j]=auxiliar;
                        }
                    }
                }

            }
            break;

        case 7:
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {

                    if(arrayDePersonas[i].sexo==arrayDePersonas[j].sexo && strcmp(arrayDePersonas[i].nombre, arrayDePersonas[j].nombre)>0)
                    {
                        auxiliar=arrayDePersonas[i];
                        arrayDePersonas[i]=arrayDePersonas[j];
                        arrayDePersonas[j]=auxiliar;
                    }
                    else
                    {
                        if(arrayDePersonas[i].sexo!=arrayDePersonas[j].sexo && arrayDePersonas[i].sexo>arrayDePersonas[j].sexo)
                        {
                            auxiliar=arrayDePersonas[i];
                            arrayDePersonas[i]=arrayDePersonas[j];
                            arrayDePersonas[j]=auxiliar;
                        }
                    }
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}



int menuOrdenamientos(ePersona arrayDePersonas[], int tam)
{
    int todoOk;
    int opcion;

    printf("Como desea ordenar la lista?: \n");
    printf("1- Ordenar por edad\n");
    printf("2- Ordenar por sexo\n");
    printf("3- Ordenar por altura\n");
    printf("4- Ordenar por nombre\n");
    printf("5- Ordenar por sexo y edad\n");
    printf("6- Ordenar por sexo y altura\n");
    printf("7- Ordenar por sexo y nombre\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    todoOk=ordenarPersonas(arrayDePersonas, tam, opcion);

    return todoOk;

}

int mostrarMujeres(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int flag=1;

    if(arrayDePersonas!=NULL && tam>0)
    {
        system("cls");

        printf("    ***Listado de Personas***   \n");
        printf(" Id        Nombre\tSexo\tEdad\tAltura\tLocalidad\n");

        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].isEmpty==0 && arrayDePersonas[i].sexo=='f')
            {
                mostrarUnaPersona(arrayDePersonas[i], arrayLocalidades, tamLoc);
                flag=0;
            }
        }

        if(flag==1)
        {
            printf("No hay mujeres para mostrar\n");
        }
        todoOk=1;
    }
    return todoOk;
}

int informePersonasLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int idLoc;
    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        system("cls");

        printf("   ********** Informe personas de una localidad ***********   \n");

        mostrarLocalidades(arrayLocalidades, tamLoc);

        printf("Ingrese el id de la localidad que desea en listar: ");
        scanf("%d", &idLoc);

        while(!validadLocalidad(arrayLocalidades, tamLoc, idLoc))
        {
            mostrarLocalidades(arrayLocalidades, tamLoc);
            printf("Id de localidad incorrecto ingrese nuevamente el id: ");
            scanf("%d", &idLoc);
        }

        mostrarPersonaIdLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc, idLoc);

    }

    return todoOk;
}

int mostrarPersonaIdLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc, int idLoc)
{
    int todoOk=0;
    int flag=1;

    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        printf("   ********** Informe personas de una localidad ***********   \n");
        printf(" Id        Nombre\tSexo\tEdad\tAltura\tLocalidad\n");

        for(int i=0; i<tam; i++)
        {
            if(!arrayDePersonas[i].isEmpty && arrayDePersonas[i].idLocalidad==idLoc)
            {
                mostrarUnaPersona(arrayDePersonas[i], arrayLocalidades, tamLoc );
                flag=0;
            }
        }

        if(flag==1)
        {
            printf("No hay personas en esa localidad para mostrar\n");
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

int mostrarPersonasPorLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;

    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {

        system("cls");

        for(int i=0; i<tamLoc; i++)
        {
            printf("%s: \n\n", arrayLocalidades[i].descripcion);

            mostrarPersonaIdLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc, arrayLocalidades[i].id);

        }
        todoOk=1;
    }

    return todoOk;

}

int promedioEdadVaronesLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int acumEdad=0;
    int contador=0;
    int idLoc;
    float prom;
    char descLocalidad[20];

    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        system("cls");

        printf("   ********** Informe promedio edad varones ***********   \n");

        mostrarLocalidades(arrayLocalidades, tamLoc);

        printf("Ingrese el id de la localidad a promediar: ");
        scanf("%d", &idLoc);

        while(!validadLocalidad(arrayLocalidades, tamLoc, idLoc))
        {
            mostrarLocalidades(arrayLocalidades, tamLoc);
            printf("Id de localidad incorrecto ingrese nuevamente el id: ");
            scanf("%d", &idLoc);
        }

        for(int i=0; i<tam; i++)
        {
            if(!arrayDePersonas[i].isEmpty && arrayDePersonas[i].sexo=='m' && arrayDePersonas[i].idLocalidad==idLoc)
            {
                acumEdad+=arrayDePersonas[i].edad;
                contador++;
            }

        }

        if(contador>0)
        {
            prom=(float)acumEdad/contador;
        }
        else
        {
            printf("El promedio no se pudo calcular\n");
        }

        cargarDescripcionLocalidad(arrayLocalidades, tamLoc, idLoc, descLocalidad);

        printf("Promedio edad varones de la localidad %s es: %.2f \n", descLocalidad, prom);

        todoOk=1;
    }


    return todoOk;
}

int informePersonaMasAltaLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    float maximaAltura;
    int banderaMaximaAltura=0;
    int idLoc;

    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        system("cls");

        printf("   ********** Informe persona mas alta de una localidad ***********   \n");

        mostrarLocalidades(arrayLocalidades, tamLoc);

        printf("Ingrese el id de la localidad a buscar max altura: ");
        scanf("%d", &idLoc);

        while(!validadLocalidad(arrayLocalidades, tamLoc, idLoc))
        {
            mostrarLocalidades(arrayLocalidades, tamLoc);
            printf("Id de localidad incorrecto ingrese nuevamente el id: ");
            scanf("%d", &idLoc);
        }

        for(int i=0; i<tam; i++)
        {
            if(!arrayDePersonas[i].isEmpty && arrayDePersonas[i].idLocalidad==idLoc)
            {
                if(banderaMaximaAltura==0 || arrayDePersonas[i].altura>maximaAltura)
                {
                    maximaAltura=arrayDePersonas[i].altura;
                    banderaMaximaAltura=1;
                }
            }
        }

        if(banderaMaximaAltura==0)
        {
            printf("No hay personas en esta localidad\n");
        }
        for(int i=0; i<tam; i++)
        {
            if(arrayDePersonas[i].idLocalidad==idLoc && arrayDePersonas[i].altura==maximaAltura)
            {
                //mostrarPersonaIdLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc, arrayLocalidades[i].id);
                mostrarUnaPersona(arrayDePersonas[i], arrayLocalidades, tamLoc);
            }
        }

        todoOk=1;
    }
    return todoOk;
}


int InformeLocalidadMujerMasJoven(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int edadMujerMasJoven;
    int banderamujerMasJoven=0;
    char descLocalidad[20];

    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        system("cls");

        printf("   ********** Informe localidad de la mujer mas joven ***********   \n");



        for(int i=0; i<tam; i++)
        {
            if(!arrayDePersonas[i].isEmpty && arrayDePersonas[i].sexo=='f')
            {
                if(banderamujerMasJoven==0 || arrayDePersonas[i].edad<edadMujerMasJoven)
                {
                    edadMujerMasJoven=arrayDePersonas[i].edad;
                    banderamujerMasJoven=1;
                }
            }
        }

        if(banderamujerMasJoven==0)
        {
            printf("No hay mujeres\n");
        }
        for(int i=0; i<tam; i++)
        {
            if(!arrayDePersonas[i].isEmpty && arrayDePersonas[i].sexo=='f' && arrayDePersonas[i].edad==edadMujerMasJoven)
            {
                cargarDescripcionLocalidad(arrayLocalidades, tamLoc, arrayDePersonas[i].idLocalidad, descLocalidad);

                printf("%s \n", descLocalidad);
            }
        }

        todoOk=1;
    }
    return todoOk;
}

int informes(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;

    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        switch(menuInformar())
        {
        case 1:
            if(!mostrarMujeres(arrayDePersonas, tam, arrayLocalidades, tamLoc ))
            {
                printf("Ocurrio problemas al mostrar personas\n");
            }
            break;

        case 2:
            system("cls");
            if(!mostrarLocalidades(arrayLocalidades, tamLoc ))
            {
                printf("Ocurrio problemas al mostrar arrayLocalidades\n");
            }
            break;

        case 3:
            if(!informePersonasLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc ))
            {
                printf("Ocurrio un error");
            }
            break;

        case 4:
            if(!mostrarPersonasPorLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;

        case 5:
            if(!promedioEdadVaronesLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;

        case 6:
            if(!informePersonaMasAltaLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;

        case 7:
            if(!InformeLocalidadMujerMasJoven(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;

        case 8:
            if(!cantidadPersonasLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;

        case 9:
            if(!localidadMasHabitada(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;
        case 10:
            if(!cantidadPersonasEnCadaLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;
        case 11:
            if(!localidadMasHabitada(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;
        case 12:
            if(!cantidadPersonasEnCadaLocalidad(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;
        case 13:
            if(!localidadMasHabitada(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;
        case 14:
            if(!localidadMasHabitada(arrayDePersonas, tam, arrayLocalidades, tamLoc))
            {
                printf("Ocurrio un error");
            }
            break;
        }
        todoOk=1;
    }
    return todoOk;
}

int menuInformar()
{
    int opcion;
    system("cls");

    printf("                *** Informes de Personas ***             \n");
    printf("-----------------------------------------------------------------------\n");

    printf("1- informar una lista con las mujeres\n");
    printf("2- informar la lista de Localidades\n");
    printf("3- informar las personas de una localidades\n");//informe
    printf("4- Informar las personas que hay en cada localidad\n");//informe
    printf("5- Informar promedio de edad de los hombres de una localidad\n");//informe
    printf("6- informar la persona mas alta en una localidad\n");//informe
    printf("7- Informar la localidad donde vive la mujer mas joven\n");//informe
    printf("8- Informar cantidad de personas en una localidad\n");//informe
    printf("9- Informar localidad mas habitada\n");
    printf("10- Informar cantidad de personas en cada localidad\n");
    printf("11- Informar localidad mas habitada\n");
    printf("12- Informar localidad mas habitada\n");//informe

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int cantidadPersonasLocalidad(ePersona arrayDePersonas[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int idLoc;
    int contador=0;
    char descLocalidad[20];

    if(arrayDePersonas!=NULL && tam>0 && arrayLocalidades!=NULL && tamLoc>0)
    {
        system("cls");

        printf("   ********** Informe cantidad personas de una localidad ***********   \n");

        mostrarLocalidades(arrayLocalidades, tamLoc);

        printf("Ingrese el id de la localidad a buscar max altura: ");
        scanf("%d", &idLoc);

        while(!validadLocalidad(arrayLocalidades, tamLoc, idLoc))
        {
            mostrarLocalidades(arrayLocalidades, tamLoc);
            printf("Id de localidad incorrecto ingrese nuevamente el id: ");
            scanf("%d", &idLoc);
        }

        for(int i=0; i<tam; i++)
        {
            if(!arrayDePersonas[i].isEmpty && arrayDePersonas[i].idLocalidad==idLoc)
            {
                contador++;
            }
        }

        cargarDescripcionLocalidad(arrayLocalidades, tam, idLoc, descLocalidad);
        printf("La cantidad de personas que viven en %s son: %d \n", descLocalidad, contador);

        todoOk=1;
    }
    return todoOk;
}

int localidadMasHabitada(ePersona lista[],int tam,eLocalidad localidades[],int tamLoc)
{
    int todoOk=0;
    int contadores[5]={0};
    int localidadMasHabitada;
    int flag=0;
    if(localidades!=NULL && lista!=NULL && tamLoc>0 && tam>0)
    {
        system("cls");
        printf("               LOCALIDAD CON MAS PERSONAS           \n");
        for(int i=0;i<tamLoc;i++)
        {
            for(int j=0;j<tam;j++)
            {
                if(lista[j].isEmpty==0 && localidades[i].id==lista[j].idLocalidad)
                {
                    contadores[i]++;
                }
            }
        }

        for(int i=0;i<tamLoc;i++)
        {
            if(contadores[i]>localidadMasHabitada || flag==0)
            {
                localidadMasHabitada=contadores[i];
                flag=1;
            }
        }

        printf("\nLa/s localidades con mas habitantes son: \n");
        for(int i=0; i<tamLoc; i++)
        {
            if(contadores[i]==localidadMasHabitada)
            {
                printf("\n%s\n", localidades[i].descripcion);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int cantidadPersonasEnCadaLocalidad(ePersona list[], int tam, eLocalidad arrayLocalidades[], int tamLoc)
{
    int todoOk=0;
    int contador=0;

    if(list!=NULL && tam>0 && list!=NULL && tamLoc>0)
    {
        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Cantidad de personas en cada localidad   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamLoc; i++)
        {
            for(int j=0; j<tam; j++)
            {
                if(list[j].isEmpty==0 && list[j].idLocalidad==arrayLocalidades[i].id)
                {
                    contador++;
                }
            }
            printf("\nLa cantidad de personas en la localidad %s son: %d\n", arrayLocalidades[i].descripcion, contador);
            contador=0;
        }
        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionPersona(ePersona arrayDePersonas[], int tam, int idPersona,  char descripcionPersona[])
{
    int todoOk=0;
    if(arrayDePersonas!=NULL && tam>0 && descripcionPersona!=NULL)
    {

        for(int i=0; i<tam; i++)
        {

            if(arrayDePersonas[i].id==idPersona)
            {
                strcpy(descripcionPersona, arrayDePersonas[i].nombre);
                break;
            }

        }
        todoOk=1;

    }
    return todoOk;
}
