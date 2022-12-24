#include "io.h"
#include <stdio.h>
int main()
{
    double x = 0.0;
    double area = 0.0;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo0119");
    IO_printf("\nEntre com o valor do raio da esfera e obtenha a area de uma esfera com tres oitavos desse raio");
    x = (IO_readdouble("\nraio = ")/8)*3;
    area = 4*(M_PI*pow(x, 2));
    IO_printf("\nA area e = %f", area);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}