#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
int main()
{
    eEmpleado* unEmpleado= new_EmpleadoParam(4, "Daniel", "Juarez", 'f', 80000);

    //mostrarUnEmpleado(unEmpleado);

    FILE* f = fopen ("archivo.bin", "wb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    if(fwrite(unEmpleado, sizeof(eEmpleado), 1, f)==1)
    {
        printf("Empleado guardado con exito!\n");
    }
    fclose(f);
    destroyEmpleado(unEmpleado);

    eEmpleado emp2;//estatico

    f=fopen("archivo.bin", "rb");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    if(fread(&emp2, sizeof(eEmpleado), 1, f)==1)
    {
        printf("Empleado cargado con exito\n");
        printf("Muestro el empeado que acabo de cargar desde el archivo\n");
        mostrarUnEmpleado(&emp2);
    }
    fclose(f);



    return 0;
}
