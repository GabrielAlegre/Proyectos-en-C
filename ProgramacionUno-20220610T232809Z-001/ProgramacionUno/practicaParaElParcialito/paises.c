#include "paises.h"
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <string.h>

ePais* new_Pais()
{
	ePais* nuevoPais=NULL;

    nuevoPais = (ePais*) malloc(sizeof (ePais));
    if(nuevoPais != NULL)
    {
		employee_setId(nuevoPais, 0);
		employee_setNombre(nuevoPais, "nn");
		employee_setHorasTrabajadas(nuevoPais, 0);
		employee_setSueldo(nuevoPais,0);
    }

    return nuevoPais;
}


ePais* new_PaisParametros(char* idStr, char* nombreStr, char* vacPrimeraDosisStr, char* vacSegundaDosisStr, char* sinVacunarStr)
{
    ePais* nuevoPais = NULL;
    nuevoPais = new_Pais();

    if(nuevoPais != NULL)
    {
        if(!(employee_setId(nuevoPais, atoi(idStr))
        && employee_setNombre(nuevoPais, nombreStr)
        && employee_setHorasTrabajadas(nuevoPais, atoi(horasTrabajadasStr))
        && employee_setSueldo(nuevoPais, atoi(sueldoStr))))
        {
        	//Si algunos de los campos del empleado es invalido
        	employee_delete(nuevoPais);
        }
    }
    return nuevoPais;
}


//Setters
int paisSetId(ePais* pais, int id)
{
    int todoOk=0;

    if(pais != NULL && id>0)
    {
        pais->id = id;

        todoOk=1;
    }
    return todoOk;
}

int paisSetNombre(ePais* pais,char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre!=NULL)
    {
        if(strlen(nombre)<40 && strlen(nombre)>1)
        {
            strcpy(this->nombre, nombre);
            todoOk=1;
        }
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this != NULL && horasTrabajadas>=50 && horasTrabajadas<=350)
    {
    	this->horasTrabajadas=horasTrabajadas;
    	todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    //Lo del sueldo igual a 0 es para cuando uso la funcion Employee* employee_new() que le asigna todos los campos a 0 pueda pasar la validacion
    if((this != NULL && sueldo>=10000 && sueldo <=50000) || (this != NULL && sueldo==0))
    {
        this->sueldo = sueldo;
        todoOk=1;
    }
    return todoOk;
}

//Getters
int employee_getId(Employee* this,int* id)
{

	int todoOk = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}

	return todoOk;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_delete(Employee* this)
{
    int empleadoEliminado = 0;

    if(this != NULL)
    {
        free(this);
        empleadoEliminado = 1;
    }
    return empleadoEliminado;
}

Employee* employee_AltaDeNuevoEmpleado()
{
    Employee* empleado=NULL;
    int horasTrabajadas;
    int salario;
    char nombre[128];

    empleado = employee_new();

    //A la hora de dar de alta un empleado se invocara esta funcion para poder pedirle y validar los datos que ingrese el usuario
    if(empleado != NULL)
    {
        fflush(stdin);
        validarCadena(nombre,"\nIngrese el nombre del empleado: ", "Nombre invalido. Ingrese el nombre nuevamente: ", 50);
        ingresoEntero(&horasTrabajadas, "\nIngrese las horas trabajadas (50 - 350): ", "Horas invalidas. Ingrese horas trabajadas (50 - 350): ", 50, 350);
        ingresoEntero(&salario, "\nIngrese el salario (10000 - 50000): ", "Salario invalido. Ingrese salario (10000 - 50000): ", 10000, 50000);
        employee_setHorasTrabajadas(empleado, horasTrabajadas);
        employee_setNombre(empleado, nombre);
        employee_setSueldo(empleado, salario);

    }
    return empleado;
}

void employee_mostrarUnEmpleado(Employee* empleado)
{
	int id;
	char nombre[124];
	int horas;
	int sueldo;

	if(empleado != NULL )
	{
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horas);
		employee_getSueldo(empleado, &sueldo);

		printf(" %-10d %-15s %-15d %-15d \n",id, nombre, horas, sueldo);
	}
}

