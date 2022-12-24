#include "io.h"
#include <stdio.h>
int main()
{
    double raio = 0.0;
    double volume = 0.0;
    double area = 0.0;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo01E1");
    IO_printf("\nEntre com o valor do volume de uma esfera e obtenha o raio da metade do volume da esfera e a area de sua superficie");
    volume = IO_readdouble("\narea = ")/2;
    raio = cbrt((volume/M_PI)*(3.0/4.0));
    area = 4*(M_PI*pow(raio, 2));
    IO_printf("\nO raio e = %f", raio);
    IO_printf("\nA area e = %f", area);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}