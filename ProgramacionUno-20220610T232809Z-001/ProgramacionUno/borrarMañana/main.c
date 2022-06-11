#include <stdio.h>
#include <stdlib.h>

int main()
{
    int datos[] = {10, 20, 30};
    int *p = datos;

    *(p+1) = *p + (*p+2);

    printf("%d\n", datos[1]);


    //char* proximoId [10];
    //int inicializarId;

    /*
	int ultimoId;
	char ultimoIdStr[100];

	FILE* pFile = fopen("ultimoId.txt", "r+");

	if(pFile == NULL)
	{
	    ultimoId=1001;
	    pFile = fopen("ultimoId.txt", "w");
	    if(pFile!=NULL)
        {
            fprintf(pFile, "%d\n", ultimoId);
        }

	}
	else
    {
        ultimoId=1005;
    }
	fclose(pFile);

    printf("Ultimo id: %d", ultimoId);
    */
    return 0;
}

