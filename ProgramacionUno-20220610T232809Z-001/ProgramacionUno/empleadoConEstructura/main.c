#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

/*Diferencia de archivo de texto y archivo en binario
/////bin////////
en binario los datos se guardan igual que en memoria
para enteros se guardan en complemento a2 que seria su sistema de representacion
para flotantes se guardan en ieee754  que seria su sistema de representacion
para char se guardan en ascii  que seria su sistema de representacion
para estructura se guardan segun el campo por ejemplo si en la estructura tenes campo int id ese campo de 4 bytes va a estar en complemento a2, si dsp tenes una cadena de caracteres esa se guardara en ascii, y si tenes un float se guardara en ieee754

//////texto//////////
se guarda la representacion en ascii de los datos
guardar un int en archivo de texto ocupa 2 bytes

fopen(path, modo) -> para abrir el archivo
path -> una cadena de caracteres que le dice donde esta ubicado y el nombre del archivo
modos: hay muchos
- para texto:
r->read
w-> write si quiero escribir un archivo que no existe la funcion lo crea. si el archivo ya estaba creado se pisa todo lo creado

- para binario:
rb->read Binary
wb-> write Binary

otro de color:
a-> append para texto
ab-> append binary para binario

*/


int main()
{
    /*PARA USAR ARCHIVO TEXTO
    char cadena[20] = "Hola mundo";
    //escribir un archivo, siempre que queremos trabajar con un archivo hay que declarar un puntero a file
    FILE* direcDelArchivo = fopen("bokitaPasion.txt", "w");

    if (direcDelArchivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    //los archivos se abren se usan (leerlo o escribirlo) y se cierran

    //para escribir:

    fprintf(direcDelArchivo, "%s  %d  %c", cadena, 124, 'f');

    //para cerrar
    fclose(direcDelArchivo);
    */

    int numero = 123654;
    int x;
    int cant;
    char cadena[20] = "Hola mundo";
    //escribir un archivo, siempre que queremos trabajar con un archivo hay que declarar un puntero a file
    FILE* direcDelArchivo = fopen("bokitaPasion.bin", "wb");

    if (direcDelArchivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    //los archivos se abren se usan (leerlo o escribirlo) y se cierran

    //para escribir:

    //fwrite(origen (que quiero escribir, tipo puntero), tam de lo que quiero escribir (con sizeof), cuantos valores del segundo parametro quiero escribir(si uso arrays seria el tam), destino, adonde lo va a escribir)
    fwrite(&numero, sizeof(int), 1, direcDelArchivo);

    fclose(direcDelArchivo);

    //ahora leo lo que escribi
    direcDelArchivo=fopen("bokitaPasion.bin", "rb");

    cant = fread(&x, sizeof(int), 1, direcDelArchivo);
    if(cant == 1)
    {
        printf("Lectura exitosa\n");
    }

    printf("x: %d\n", x);

    printf("cant: %d\n", cant);

    //para cerrar
    fclose(direcDelArchivo);
    return 0;
}
