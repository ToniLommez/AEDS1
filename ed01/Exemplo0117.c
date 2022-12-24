#include "io.h"
#include <stdio.h>
int main()
{
    double x = 0.0;
    double temp = 0.0;
    double area = 0.0;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo0111");
    IO_printf("\nEntre com o valor do lado do cubo e receba a area de um cubo com um sexto do tamanho do lado");
    x = IO_readdouble("\nlado x = ");
    temp = x/6;
    area = pow(temp, 3.0);
    IO_printf("\nA area e = %f", area);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}