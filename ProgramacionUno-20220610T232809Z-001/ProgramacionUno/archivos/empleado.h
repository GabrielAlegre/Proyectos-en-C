#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;

} eEmpleado;


#endif // EMPLEADO_H_INCLUDED

int mostrarUnEmpleado(eEmpleado* unEmpledo);

//Funcion que se encarga de conseguir espacio de memoria para un empleado, le limpia los campos y devuelve la direccion de memoria de un empleado para ya poder usar el empleado
eEmpleado* new_Empleado();

//Te devuelve una estructura perfectamente cargada o si algun dato de algun campo es invalido devuelve null
eEmpleado* new_EmpleadoParam(int id, char nombre[], char apellido[],  char sexo, float sueldo);

//setters funciones que incorporan la validacion para cada uno de los campos
int empleadoSetId(eEmpleado* unEmpleado, int id);
int empleadoSetNombre(eEmpleado* unEmpleado, char nombre[]);
int empleadoSetApellido(eEmpleado* unEmpleado, char apellido[]);
int empleadoSetSexo(eEmpleado* unEmpleado, char sexo);
int empleadoSetSueldo(eEmpleado* unEmpleado, float sueldo);

//getters
int empleadoGetId(eEmpleado* unEmpleado, int* pId);
int empleadoGetNombre(eEmpleado* unEmpleado, char nombre[]);
int empleadoGetApellido(eEmpleado* unEmpleado, char apellido[]);
int empleadoGetSexo(eEmpleado* unEmpleado, char* pSexo);
int empleadoGetSueldo(eEmpleado* unEmpleado, float* pSueldo);

//bajar
void destroyEmpleado(eEmpleado* unEmpledo);
