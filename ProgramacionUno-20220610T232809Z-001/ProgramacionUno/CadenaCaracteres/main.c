#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 30

int miStrlen(char arrayString[]);


int main()
{
    char nombre[TAM];
    char nombreCopiado[TAM];
    int cantidad;
    char auxiliarString[125]; // a la cadena auxiliarString la estaria usando como buffer
    char pruebaDeRango[10];
    //char nombreCompleto[70];
    int resultadoDeLaComparacion;


//----------------------------------------------------primera funcion---------------------------------------------------------//
    printf("Ingrese su nombre: ");
    fflush(stdin);
    //scanf("%s", nombre);
    //gets obtiene un string y permite espacios en blancos es el sustituto del scanf
    gets(nombre);

    printf("Su nombre es: %s\n\n", nombre);

//----------------------------------------------------segunda funcion---------------------------------------------------------//
    //devuelve un entero que es la cantidad de caracteres que tiene la cadena
    //cantidad=strlen(nombre);
    //es lo mismo pero con una funcion creada por nosotros
    cantidad=miStrlen(nombre);

    printf("La cantidad de caracteres del nombre es: %d\n\n", cantidad);

//----------------------------------------------------tercera funcion---------------------------------------------------------//
    // sirve para copiar una cadena de un array
    //strcpy(destino, origien);

    //Lo que contenga el array nombre se le asignara al array nombreCopiado
    strcpy(nombreCopiado, nombre);

    printf("El array nombreCopiado contiene: %s\n\n", nombreCopiado);

//----------------------------------------------------cuarta funcion---------------------------------------------------------//
    /*Para no desbordar la memoria, se puede hacer el siguiente metodo: creo una variable auxiliar
    con un tamaño exagerado y lo que ingrese el usuario lo almaceno en dicho auxiliar, luego, valido
    si lo que ingreso el usario esta dentro del tamaño que yo le asigne a mi array de string
   */

   printf("ingrese un nombre con maximo 9 caracteres: ");
   fflush(stdin);
   gets(auxiliarString);
   while(strlen(auxiliarString)>9)
   {
       printf("Nombre demasiado largo. ingrese un nombre con maximo 9 caracteres: ");
       fflush(stdin);
       gets(auxiliarString);
   }
    strcpy(pruebaDeRango, auxiliarString);

    printf("El nombre con maximo 9 caracteres es: %s\n\n", pruebaDeRango);

//----------------------------------------------------cuarta bis funcion-----------------------------------------------------//
    /*Otra manera de hacer lo mismo es con la funcion fgets(char array a guardar el dato, int el largo, stdin), entonces:
    la desventaja de este metodo es que no te avisa que tu nombre es incorrecto, sino que te corta directo, y no te da la
    opcion de reingresar el dato
    */
    printf("ingrese un nuevo nombre con maximo 9 caracteres: ");
    fflush(stdin);
    fgets(pruebaDeRango, 10, stdin);
    printf("El nuevo nombre con maximo 9 caracteres es: %s\n\n", pruebaDeRango);

//----------------------------------------------------quinta funcion---------------------------------------------------------//
    /*Para comparar cadenas de caracteres se utiliza la funcion: strcmp(array1, array2)
    Esta funcion puede retornar tres valores: -1, 0, 1
    Retorna 0 si las dos cadenas son iguales
    retorna -1 si la primera cadena que le pasamos es menor a la segunda osea que esta antes
    retorna 1 si la primera cadena que le pasamos es mayor a la segunda osea esta despues
    */
    resultadoDeLaComparacion=strcmp(nombre, pruebaDeRango);

//----------------------------------------------------funcion piolita---------------------------------------------------------//
    //resultadoDeLaComparacion=stricmp(nombre, pruebaDeRango); no le importa las mayusculas

    printf("%d \n\n", resultadoDeLaComparacion);

//----------------------------------------------------sexta funcion---------------------------------------------------------//
    /*Para transformar toda una cadena a mayusculas se usa la funcion strupr(cadena)
    */
    strupr(nombre);

    printf("El nombre de la array todo en mayusculas es: %s\n\n", nombre);

//----------------------------------------------------septima funcion---------------------------------------------------------//
    /*Para transformar toda una cadena a minuscula se usa la funcion strlwr(cadena)
    */
    strlwr(nombre);

    printf("El nombre de la array todo en minuscula es: %s\n\n", nombre);

//----------------------------------------------------octava funcion---------------------------------------------------------//
    //para contatenar cadenas strcat(array1, array2), se contena el primero con el segundo

    strcat(nombreCompleto, pruebaDeRango);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

//----------------------------------------------------novena funcion---------------------------------------------------------//

// para buscar espacios en blanco
//retorna 1 si encontro un espacio
//retorna 0 si encontro un espacio

isspace(nombreCopiado[TAM]);






    //puts muestra la cadena de caracteres (no se utiliza mucho)
    //puts(nombre);
    return 0;
}

int miStrlen(char arrayString[])
{
    int cantidad=0;
    int i=0;

    if(arrayString!=NULL)
    {
        while(arrayString[i]!='\0')
        {
            cantidad++;
            i++;
        }
    }
    return cantidad;
}
