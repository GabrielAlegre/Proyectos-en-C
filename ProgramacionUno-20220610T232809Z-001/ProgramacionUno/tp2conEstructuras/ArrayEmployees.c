#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "sector.h"
#include "funcionesParaIngresos.h"
#include <string.h>

int menu()
{
    int opcion;
    system("cls");
    printf("--------------------------------------------------------------------------------------\n");
    printf("                      *** Menu Employee ***            \n");
    printf("--------------------------------------------------------------------------------------\n\n");
    printf("1- Alta de un empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja de un empleado\n");
    printf("4- Informar\n");
    printf("5- Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(eEmployee* list, int len)
{
    int huboError=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        huboError=0;
    }
    return huboError;
}

int addEmployee(eEmployee list[], int len, int* pId, eSector sectores[], int tamSec)
{
    int huboError=-1;
    int indiceLibre;
    eEmployee auxEmpleado;

    if(list!=NULL && len>0 && pId!=NULL && sectores!=NULL && tamSec>0)
    {
        system("cls");
        indiceLibre=buscarLibre(list, len);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de Empleados   ***             \n");
            printf("--------------------------------------------------------------------------------------\n\n");

            auxEmpleado.id=*pId;
            (*pId)++;

            validarCadena(auxEmpleado.name, "Ingrese su Nombre: ", "Error, nombre demasiado largo o ingreso numeros: ", 51);

            validarCadena(auxEmpleado.lastName, "Ingrese su Apellido: ", "Error, apellido demasiado largo o ingreso numeros: ", 51);

            validarCaracter(&auxEmpleado.sexo, "Ingrese su sexo (f/m): ", "Sexo invalido, reingrese su sexo (f/m): ", 'f', 'm');

            validarFlotante(&auxEmpleado.salary, "Ingrese su salario (15000 a 200000): ", "Error, salario invalido (15000 a 100000): ", 15000, 200000);

            mostrarSectores(sectores, tamSec);
            validarEntero(&auxEmpleado.sector, "Ingrese su sector de trabajo (1 a 5): ", "Error, ingrese su sector de trabajos (1 a 5): ", 1, 5);

            auxEmpleado.isEmpty=0;

            printf("\nExcelente. Se realizo correctamente la alta del empleado: \n");
            printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");
            mostrarUnEmployee(auxEmpleado, sectores, tamSec);
            list[indiceLibre]=auxEmpleado;
        }
        huboError=0;
    }
    return huboError;
}

int findEmployeeById(eEmployee* list, int len,int id)
{
    int indiceDeIdEncontrado=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}


int buscarLibre(eEmployee list[], int len)
{
    int indiceLibre=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                indiceLibre=i;
                break;//xq solo necesitamos el PRIMER indice que encontremos libre una vez encontrado no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}

void mostrarUnEmployee(eEmployee unEmpleado, eSector sectores[], int tamSec)
{
    char descripcionSector[20];
    cargarDescripcionSector(sectores, tamSec, unEmpleado.sector, descripcionSector);
        printf("%d\t%8s\t%8s\t%c\t%8.2f\t%10s\n",
           unEmpleado.id,
           unEmpleado.name,
           unEmpleado.lastName,
           unEmpleado.sexo,
           unEmpleado.salary,
           descripcionSector);
}

int printEmployees(eEmployee* list, int length, eSector sectores[], int tamSec)
{
    int todoOk=0;

    if(list!=NULL && length>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Empleados   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");

        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty==0)
            {
                mostrarUnEmployee(list[i], sectores, tamSec);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int removeEmployee(eEmployee* list, int len, eSector sectores[], int tamSec)
{
    int noHuboError=0;
    int indicePersonaBajar;
    char confirmacionDeBaja;
    int id;

    if(list!=NULL && len>0)
    {
        printf("\n");
        printEmployees(list, len, sectores, tamSec);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Dar de baja a un Empleado   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID de la persona a dar de baja: ");
        scanf("%d", &id);

        indicePersonaBajar=findEmployeeById(list, len, id);

        if(indicePersonaBajar>=0)
        {
            printf("\n");
            printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");
            mostrarUnEmployee(list[indicePersonaBajar], sectores, tamSec);
            printf("\n");

            validarCaracter(&confirmacionDeBaja,
                            "Esta seguro que desea dar de baja a esta persona (s/n): ",
                            "Respuesta Invalida. 's' para confirmar baja o 'n' para cancelar baja: ",
                             's',
                             'n');

            if(confirmacionDeBaja=='s')
            {
                list[indicePersonaBajar].isEmpty=1;
                printf("Baja exitosa!\n");
                noHuboError=1;
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
    return noHuboError;
}

int menuDeModificacion()
{
    int opcion;
    printf("\nQue le desea modificar al empleado: \n");
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apellido\n");
    printf("3- Modificar Salario\n");
    printf("4- Modificar sector\n");
    printf("5- Cancelar modificacion\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int modifyEmployee(eEmployee* list, int len, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int id;
    int indiceAModificar;
    char auxString[150];
    char confirmacionModificar;
    eEmployee auxEmpleado;
    int opcion;

    if(list!=NULL && len>0)
    {
        system("cls");
        printEmployees(list, len, sectores, tamSec);

        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Modificar Empleados   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID del empleado que desea modificar: ");
        scanf("%d", &id);

        indiceAModificar=findEmployeeById(list, len, id);

        if(indiceAModificar>=0)
        {
            printf("\n");
            printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");
            mostrarUnEmployee(list[indiceAModificar], sectores, tamSec);
            printf("\n");

            validarCaracter(&confirmacionModificar,
                "Esta seguro que quiere modificar a esta persona (s/n): ",
                "Respuesta Invalida. 's' para confirmar o 'n' para cancelar: ",
                 's',
                 'n');

            while(confirmacionModificar=='s')
            {
                opcion=menuDeModificacion();
                switch(opcion)
                {
                     case 1:
                        if(validarCadena(auxString, "Ingrese Nombre modificado: ", "Error, nombre demasiado largo o ingreso numeros: ", 51))
                        {
                            strcpy(list[indiceAModificar].name, auxString);
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 2:
                        if(validarCadena(auxString, "Ingrese Apellido modificado: ", "Error, apellido demasiado largo o ingreso numeros: ", 51))
                        {
                            strcpy(list[indiceAModificar].lastName, auxString);
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 3:
                        if(validarFlotante(&auxEmpleado.salary, "Ingrese su salario modificado (15000 a 200000): ", "Error, salario demasiado alto (15000 a 200000): ", 15000, 200000))
                        {
                            list[indiceAModificar].salary=auxEmpleado.salary;
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;
                    case 4:
                        mostrarSectores(sectores, tamSec);
                        if(validarEntero(&auxEmpleado.sector, "Ingrese su sector modificado (1 a 10): ", "Error, sector invalido (1 a 10): ", 1, 10))
                        {
                            list[indiceAModificar].sector=auxEmpleado.sector;
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 5:
                        printf("Se ha cancelado la modificacion\n");
                        confirmacionModificar='n';
                        break;

                    default:
                        printf("Opcion invalida!!!\n");
                        break;
                }

                if(opcion>0 && opcion <5)
                {
                    printf("\nEmpleado con la modificacion actualizada: \n");

                    printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");
                    mostrarUnEmployee(list[indiceAModificar],sectores, tamSec);

                    validarCaracter(&confirmacionModificar,
                    "\nQuiere modificar otro campo de este empleado? (s/n): ",
                    "\nRespuesta Invalida. 's' para confirmar o 'n' para cancelar: ",
                     's',
                     'n');
                }
            }
            todoOk=1;
        }
        else
        {
            printf("No se encontro el ID: %d\n", id);
        }
    }
    return todoOk;
}

int sortEmployees(eEmployee* list, int len, int order, eSector sectores[], int tamSec)
{
    int todoOk=-1;
    eEmployee auxiliar;
    if(list!=NULL && len>0)
    {
        switch(order)
        {
            case 0: // Descendente
                for(int i=0; i<len-1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)<0 || (!strcmp(list[i].lastName, list[j].lastName) && list[i].sector<list[j].sector))
                        {
                            auxiliar=list[i];
                            list[i]=list[j];
                            list[j]=auxiliar;
                        }
                    }
                }
                printEmployees(list, len, sectores, tamSec);
                break;

            case 1: //Ascendente
                for(int i=0; i<len-1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)>0 || (!strcmp(list[i].lastName, list[j].lastName) && list[i].sector>list[j].sector))
                        {
                            auxiliar=list[i];
                            list[i]=list[j];
                            list[j]=auxiliar;
                        }
                    }
                }
                printEmployees(list, len, sectores, tamSec);
                break;
        }
        todoOk=0;
    }
    return todoOk;
}

int PromedioYContadorSalario(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    float acumSalario=0;
    int contador=0;
    float promedio;

    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Total y promedio de salarios e informe de empleados que superan el salario promedio   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(!list[i].isEmpty)
            {
                acumSalario+=list[i].salary;
                contador++;
            }
        }

        if(contador>0)
        {
            promedio=acumSalario/contador;
        }
        else
        {
            printf("El promedio no se pudo calcular\n");
        }

        printf("La suma de los salarios es: %.3f \n\n", acumSalario);
        printf("El salario promedio es: %.3f \n\n", promedio);
        EmpleadosQueSuperanSalarioProm(list, tam, promedio, sectores, tamSec);

        todoOk=1;
    }
    return todoOk;
}

int informes(eEmployee lista[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int order;

    if(lista!=NULL && tam>0)
    {
        switch(menuInformes())
        {
            case 1:
                validarEntero(&order,
                "\n0- Ordenar de forma descendente (Z a A)\n\n1- Ordenar de forma ascendente (A a Z)\n\ningrese opcion: ",
                "Error. Solo puede ingresar 0(descendete) o 1(ascendente): ",
                0,
                1);
                sortEmployees(lista, tam, order, sectores, tamSec);
                break;

            case 2:
                PromedioYContadorSalario(lista, tam, sectores, tamSec);
                break;

            case 3:
                informePersonasDeUnSoloSector(lista, tam, sectores, tamSec);
                break;

            case 4:
                InformePersonasDeCadaSector(lista, tam, sectores, tamSec);
                break;

            case 5:
                InformeSueldoPromVarones(lista, tam, sectores, tamSec);
                break;

            case 6:
                personaMayorSueldoSector(lista, tam, sectores, tamSec);
                break;

            case 7:
                sectorMujerMenosSueldo(lista, tam, sectores, tamSec);
                break;

            case 8:
                cantidadPersonasPorSector(lista, tam, sectores, tamSec);
                break;

            case 9:
               cantidadPersonasEnCadaSector(lista, tam, sectores, tamSec);
                break;
            case 10:
               sectorConMasEmpleados(lista, tam, sectores, tamSec);
                break;


            case 12:
                printf("Informe cancelado\n");
                break;

            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarSiHayUnEmpleado(eEmployee list[], int len, int* banderaHayUnEmpleado)
{
    int todoOk=0;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                *banderaHayUnEmpleado=1;
                break;
            }
            else
            {
                *banderaHayUnEmpleado=0;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int EmpleadosQueSuperanSalarioProm(eEmployee list[], int tam, int salarioPromedio, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int contadorSuperanSalarioProm=0;

    if(list!=NULL && tam>0 && salarioPromedio>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!list[i].isEmpty && list[i].salary>salarioPromedio)
            {
                contadorSuperanSalarioProm++;
            }
        }
        printf("Los empleados que superan el salario promedio son %d: \n\n", contadorSuperanSalarioProm);
        printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");

        for(int i=0; i<tam; i++)
        {
            if(!list[i].isEmpty && list[i].salary>salarioPromedio)
            {
                mostrarUnEmployee(list[i], sectores, tamSec);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("--------------------------------------------------------------------------------------\n");
    printf("                     ***   Informes de empleados   ***             \n");
    printf("--------------------------------------------------------------------------------------\n\n");
    printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n\n");
    printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
    printf("3. informe empleados de un solo sector\n\n");
    printf("4. informe empleados de cada sector\n\n");
    printf("5. informe promedio sueldo de varones\n\n");
    printf("6. Informe persona mayor sueldo de un sector\n\n");
    printf("7. informar sector de la mujer con menos sueldo\n\n");
    printf("8. Informe cantidad de empleados en un sector\n\n");
    printf("9. informe empleados en cada sector\n\n");
    printf("10. informe sector con mas empleados\n\n");
    printf("11. nose 8\n\n");
    printf("12. Cancelar\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

int informePersonasDeUnSoloSector(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=1;
    int sectorAMostrar;

    if(list!=NULL && tam>0 && sectores!=NULL && tamSec>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de empleados de un solo sector   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        mostrarSectores(sectores, tamSec);
        validarEntero(&sectorAMostrar, "Ingrese el sector que desea mostrar (1 a 5): ", "\nSector invalido. reingreselo: ", 1, 5);

        mostrarPersonasDeSectorPorId(list, tam, sectores, tamSec, sectorAMostrar);
        todoOk=1;
    }
    return todoOk;
}

int mostrarPersonasDeSectorPorId(eEmployee list[], int tam, eSector sectores[], int tamSec, int idABuscar)
{
    int todoOk=1;
    int flagHayPersonas=0;
    char descripcionSector[20];

    if(list!=NULL && tam>0 && sectores!=NULL && tamSec>0)
    {
        printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");

        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0 && list[i].sector==idABuscar)
            {

                mostrarUnEmployee(list[i], sectores, tamSec);
                flagHayPersonas=1;
            }
        }

        if(flagHayPersonas==0)
        {
            cargarDescripcionSector(sectores, tamSec, idABuscar, descripcionSector);
            printf("No hay empleados en el sector: %s\n", descripcionSector);
        }
        todoOk=1;
    }

    return todoOk;

}
int mostrarPersonasDeSectorPorIdSexo(eEmployee list[], int tam, eSector sectores[], int tamSec, int idABuscar, char sexo)
{
    int todoOk=1;
    int flagHayPersonas=0;
    char descripcionSector[20];

    if(list!=NULL && tam>0 && sectores!=NULL && tamSec>0)
    {
        printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");

        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0 && list[i].sector==idABuscar && list[i].sexo==sexo)
            {

                mostrarUnEmployee(list[i], sectores, tamSec);
                flagHayPersonas=1;
            }
        }

        if(flagHayPersonas==0)
        {
            cargarDescripcionSector(sectores, tamSec, idABuscar, descripcionSector);
            printf("No hay empleados del sexo %c en el sector: %s\n",sexo, descripcionSector);
        }
        todoOk=1;
    }

    return todoOk;

}

int InformePersonasDeCadaSector(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=1;

    if(list!=NULL && tam>0 && sectores!=NULL && tamSec>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de empleados de cada sector   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        for(int i=0; i<tamSec; i++)
        {
            printf("\nEmpleados de %s: \n", sectores[i].descripcionSector);

            mostrarPersonasDeSectorPorId(list, tam, sectores, tamSec, sectores[i].idSector);
        }
    }

    return todoOk;
}

int InformeSueldoPromVarones(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    float acumSalarioVarones=0;
    int contador=0;
    float promedioSalarioVarones;
    int sectorAPromediar;
    char descripcion[20];

    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Sueldo Promedio de varones de un sector   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");

        mostrarSectores(sectores, tamSec);
        validarEntero(&sectorAPromediar, "Ingrese el sector que desea mostrar (1 a 5): ", "\nSector invalido. reingreselo: ", 1, 5);
        cargarDescripcionSector(sectores, tamSec, sectorAPromediar, descripcion);
        for(int i=0; i<tam; i++)
        {
            if(!list[i].isEmpty && list[i].sexo=='m' && list[i].sector==sectorAPromediar)
            {
                acumSalarioVarones+=list[i].salary;
                contador++;
            }
        }

        printf("\nEmpleados varones en el sector %s:\n\n", descripcion);
        mostrarPersonasDeSectorPorIdSexo(list, tam, sectores, tamSec, sectorAPromediar, 'm');

        if(contador>0)
        {
            promedioSalarioVarones=acumSalarioVarones/contador;

            printf("\nEl salario promedio de los varones en el sector de %s es: %.3f \n\n",descripcion, promedioSalarioVarones);

        }
        else
        {
            printf("\nNo se pudo calcular el promedio. No hay empleados varones en el sector de %s\n\n", descripcion);
        }

        todoOk=1;
    }
    return todoOk;
}

int personaMayorSueldoSector(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int banderaMayorSueldo=0;
    int idSectorMayorSueldo;
    int sueldoMasAlto;
    char descripcion[20];

    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Persona con mayor sueldo en un sector   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");

        mostrarSectores(sectores, tamSec);

        validarEntero(&idSectorMayorSueldo, "Ingrese el sector que desea mostrar (1 a 5): ", "\nSector invalido. reingreselo: ", 1, 5);

        cargarDescripcionSector(sectores, tamSec, idSectorMayorSueldo, descripcion);
        for(int i=0; i<tam; i++)
        {
            if(list[i].sector==idSectorMayorSueldo && list[i].isEmpty==0)
            {
                if(list[i].salary>sueldoMasAlto || banderaMayorSueldo==0)
                {
                    sueldoMasAlto=list[i].salary;
                    banderaMayorSueldo=1;
                }
            }
        }

        if(banderaMayorSueldo)
        {
            printf("\nEl salario mas alto del sector %s es: %d y las persona/s que tiene el salario mas alto es/son: \n\n",descripcion, sueldoMasAlto);

            printf("Id       Nombre         Apellido\tSexo\tSalario\t\tSector\n");
            for(int i=0; i<tam; i++)
            {
                if(list[i].sector==idSectorMayorSueldo && list[i].isEmpty==0 && list[i].salary==sueldoMasAlto)
                {
                    mostrarUnEmployee(list[i], sectores, tamSec);
                }
            }
        }
        else
        {
            printf("\nNo hay empleados en el de sector %s\n", descripcion);
        }



        todoOk=1;
    }
    return todoOk;
}

int sectorMujerMenosSueldo(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int banderaMenorSueldo=0;
    int sueldoMasBajo;
    char descripcion[20];

    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   sector de la mujer con menos sueldo   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0 && list[i].sexo=='f')
            {
                if(list[i].salary<sueldoMasBajo || banderaMenorSueldo==0)
                {
                    sueldoMasBajo=list[i].salary;
                    banderaMenorSueldo=1;
                }
            }
        }

        if(banderaMenorSueldo)
        {
            printf("\nEl salario mas bajo de una mujer es/son del sector: \n");
            for(int i=0; i<tam; i++)
            {
                if(list[i].isEmpty==0 && list[i].sexo=='f' && list[i].salary==sueldoMasBajo)
                {
                    cargarDescripcionSector(sectores, tamSec, list[i].sector, descripcion);
                    printf("%s\n",descripcion);
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int cantidadPersonasPorSector(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int idSector;
    char descripcion[20];
    int contador=0;


    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Cantidad de empleados por sector   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");

        mostrarSectores(sectores, tamSec);

        validarEntero(&idSector, "Ingrese el sector que desea mostrar (1 a 5): ", "\nSector invalido. reingreselo: ", 1, 5);

        cargarDescripcionSector(sectores, tamSec, idSector, descripcion);

        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0 && list[i].sector==idSector)
            {
                contador++;
            }
        }

        if(!contador)
        {
            printf("\nNo hay empleados en el sector de %s\n", descripcion);
        }
        else
        {
            printf("\nLa cantidad de empleados en el sector de %s es: %d\n", descripcion, contador);
        }
        todoOk=1;
    }
    return todoOk;
}

int cantidadPersonasEnCadaSector(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int contador=0;
    int cantidadDeEmpleadosEnCadaSector[tamSec];

    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Cantidad de empleados por sector   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamSec; i++)
        {
            contador=0;
            for(int j=0; j<tam; j++)
            {
                if(list[j].isEmpty==0 && list[j].sector==sectores[i].idSector)
                {
                    contador++;
                }
            }
            cantidadDeEmpleadosEnCadaSector[i]=contador;
            printf("\nLa cantidad de empleados en el sector de %s son: %d\n", sectores[i].descripcionSector, cantidadDeEmpleadosEnCadaSector[i]);
        }
        todoOk=1;
    }
    return todoOk;
}

int sectorConMasEmpleados(eEmployee list[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=0;
    int contador=0;
    int cantidadDeEmpleadosEnCadaSector[tamSec];
    int sectorMasPoblado;
   // int indiceDelSectorMasPoblado;
    int flag=0;


    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Cantidad de empleados por sector   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamSec; i++)
        {
            contador=0;
            for(int j=0; j<tam; j++)
            {
                if(list[j].isEmpty==0 && list[j].sector==sectores[i].idSector)
                {
                    contador++;
                }
            }
            cantidadDeEmpleadosEnCadaSector[i]=contador;
            printf("\nLa cantidad de empleados en el sector de %s son: %d\n", sectores[i].descripcionSector, cantidadDeEmpleadosEnCadaSector[i]);
        }

        for(int i=1; i<=tamSec; i++)
        {
            if(cantidadDeEmpleadosEnCadaSector[i]>sectorMasPoblado|| flag==0)
            {
                sectorMasPoblado=cantidadDeEmpleadosEnCadaSector[i];
                flag=1;
            }
        }

        printf("\nLos/el sector con mas empleados: \n");
        for(int i=0; i<tamSec; i++)
        {
            if(cantidadDeEmpleadosEnCadaSector[i]==sectorMasPoblado)
            {
                printf("\n%s\n", sectores[i].descripcionSector);
            }
        }

        todoOk=1;
    }
    return todoOk;
}

