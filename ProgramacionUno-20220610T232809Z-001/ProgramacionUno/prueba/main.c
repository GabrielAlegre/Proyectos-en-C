#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*Se ingresaran 5 importes
-marca del producto
-pais de origen (china, uruguay o paraguay
-calcular y mostrar
a- minimo importe con su pais
b- maximo importe con su marca
c- promedio importe
d-cantidad de productos de china
e- sobre el maximo encontrado aplicar un descuento del 10% a dicho
importe*/
int main()
{
    float importe;
    char marca;
    char paisDeOrigen;
    int banderaMinimo=0;
    int banderaMaximo=0;
    float importeMinimo;
    float importeMaximo;
    char paisMinimo;
    char marcaMaxima;
    float acumuladorImporte=0;
    float importePromedio;
    int contadorProductosChinos=0;
    float importeMaximoConDescuento;
    float descuento;
    int i;


    for(i=0; i<5; i++)
    {
        printf("Ingrese importe: ");
        scanf("%f", &importe);

        acumuladorImporte+=importe;

        printf("ingrese marca: ");
        fflush(stdin);
        scanf("%c", &marca);
        marca=toupper(marca);

        printf("Ingrese pais de origen (C para china, U para Uruguay y P para Paraguay): ");
        fflush(stdin);
        scanf("%c", &paisDeOrigen);
        paisDeOrigen=toupper(paisDeOrigen);

        while(paisDeOrigen!='C'&&paisDeOrigen!='U'&&paisDeOrigen!='P')
        {
            printf("ERROR. Ingrese pais de origen (C para china, U para Uruguay y P para Paraguay): ");
            fflush(stdin);
            scanf("%c", &paisDeOrigen);
            paisDeOrigen=toupper(paisDeOrigen);
        }

        //a- minimo importe con su pais
        if(importe<importeMinimo || banderaMinimo==0)
        {
            importeMinimo=importe;
            paisMinimo=paisDeOrigen;
            banderaMinimo=1;
        }
        //b- maximo importe con su marca
        if(importe>importeMaximo || banderaMaximo==0)
        {
            importeMaximo=importe;
            marcaMaxima=marca;
            banderaMaximo=1;
        }

        //d-cantidad de productos de china
        if(paisDeOrigen=='C')
        {
            contadorProductosChinos++;
        }
    }

    //c- promedio importe
    importePromedio=acumuladorImporte/5;

    //e- sobre el maximo encontrado aplicar un descuento del 10% a dicho importe
    descuento=importeMaximo*10/100;
    importeMaximoConDescuento=importeMaximo-descuento;

    printf("El importe minimo es: %f y su pais es: %c\n", importeMinimo, paisMinimo);
    printf("El importe maximo es: %f y su marca es: %c\n", importeMaximo, marcaMaxima);
    printf("El importe promedio fue de: %.2f\n", importePromedio);
    printf("La cantidad de productos de china son: %d\n", contadorProductosChinos);
    printf("El importe maximo con un 10%% de descuento queda en: %.2f\n", importeMaximoConDescuento);
    return 0;
}
