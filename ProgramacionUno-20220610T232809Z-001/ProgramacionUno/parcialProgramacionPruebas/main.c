#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num =10;
    float *pnum = malloc(sizeof(float));
    *pnum = 2*num;
    free(pnum);
    printf("%.0f", num);

    return 0;
}
