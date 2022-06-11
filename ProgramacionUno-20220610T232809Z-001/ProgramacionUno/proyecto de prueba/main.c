#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int x;
    char nombre[20]=" juan carlos ";
    char nombre2[20]="olivia";


       for(int i = 0; nombre[i]; i++) {
      printf("%c %d\n", nombre[i], isspace(nombre[i]));
       }

    return 0;
}
