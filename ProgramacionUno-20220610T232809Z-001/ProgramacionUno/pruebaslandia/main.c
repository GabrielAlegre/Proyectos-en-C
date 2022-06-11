#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ingresoEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max);

int validarEntero(char pEnteroAValidar[]);

//int validarNumeros(char numeros[]);


//int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

int main()
{
    int numero;
    int segunNum;
    char segundoNum[10];
    int cantIndice;

    for(int i=0; i<13000; i++)
    {

            ingresoEntero(&numero, "\n\nIngrese su edad (-100, 100): ", "\nError. Edad invalida: ", -100, 100);

            printf("El numero que ingreso es: %d", numero);
    }


    /*
    printf("\nIngrese numero: ");
    scanf("%d", &segunNum);


    itoa(segunNum, segundoNum, 20);


    cantIndice=strlen(segundoNum);


    printf("\nIndices: %d", cantIndice);
    */
    return 0;
}



/*
int validarNumeros(char numeros[])
{
	int todoOk=1;
	//int esNumero;
	//if(numeros!=NULL)
	//{
	if(strlen(numeros) > 0)
		{
			for(int i = 0;i< strlen(numeros);i++)
			{
				if(isdigit(numeros[i]) == 0)
				{
					if(i == 0 && numeros[0] == '-')
					{
	                    todoOk = 1;
	                    break;
					}
					else
					{
						todoOk = 0;
					}
				}
			}
		}
	    else
	    {
	        todoOk=0;
	    }
	return todoOk;
}


int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	//int numeroIngresado;
	char auxEntero[150];

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		//scanf("%d", &numeroIngresado);
		fflush(stdin);
		gets(auxEntero);


		while(validarNumeros(auxEntero)==0||atoi(auxEntero) < min || atoi(auxEntero) > max)
		{
			printf("%s", mensajeError);
			//scanf("%d", &numeroIngresado);
			fflush(stdin);
			gets(auxEntero);

		}
		*entero = atoi(auxEntero);
		retorno = 0;
	}

	return retorno;
}

*/










































int validarEntero(char pEnteroAValidar[])
{
	int todoOk = 1;

    //Primero verifico que por lo menos un indice del array este activo
	if(strlen(pEnteroAValidar) > 0)
	{
	    //segundo, con el for hago recorrer todos los indices del array para ir validando num por num
		for(int i = 0;i< strlen(pEnteroAValidar);i++)
		{
		    //el isdigit me devuelve 0 si encuentra en el indice que se esta validando algo que no es un numuero
			if(isdigit(pEnteroAValidar[i]) == 0)
			{
			    // si el indice que se verifico anteriormente no es un numero (isdigit==0), se verifica que ese indice sea el 0 (el primero)
			    //y que ademas ese caracter que esta en el indice 0 sea un "-"(guion), en caso de que se cumplan estas dos condiciones
			    //todoOk=1 porque simboliza que es un numero negativo
				if(i == 0 && pEnteroAValidar[0] == '-')
				{
                    todoOk = 1;

				}
				//En caso de que ese indice que dio isdigit==0 no este en la posicion 0 y no sea un guion marcamos que hay error
				else
				{
					todoOk = 0;
				}
			}
		}
	}
	//si el strlen da como resultado algo menor a 0 es xq el usuario no ingreso nada, por lo que hay que marcar el error
	//sin este else el usuario puede apretar enter y lo tomara como valido
    else
    {
        todoOk=0;
    }

	return todoOk;
}

int ingresoEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max)
{
    //el aux es para no validad directamente el numero que ingreso el usuario
	char auxEntero[150];
	int todoOk = 0;

	if(enteroValidado != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(auxEntero);

        //En el while valido que el entero ingresado por usuario sea valido(validar entero me tiene que devolver 1)
        // ademas valida que dicho entero no sea mayor al maximo y menor al minimo
        //el atoi lo que hace es convertir la cadena de caracteres en numero decimal para poder hacer la condicion de que no
        //supere al maximo ni sea menor al minimo
		while(validarEntero(auxEntero) == 0 || atoi(auxEntero) > max || atoi(auxEntero) < min)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(auxEntero);
		}
		// una vez validado que el numero ingresado sea valido se lo asigno a la variable.

		*enteroValidado = atoi(auxEntero);
		todoOk = 1;
	}
	return todoOk;
}


