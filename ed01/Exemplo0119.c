#include "io.h"
#include <stdio.h>
#include <math.h>
int main()
{
    double x = 0.0;
    double area = 0.0;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo0119");
    IO_printf("\nEntre com o valor do raio do circulo e obtenha a area de um circulo com metade desse raio");
    x = IO_readdouble("\nraio = ")/2;
    area = M_PI*pow(x, 2);
    IO_printf("\nA area e = %f", area);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}