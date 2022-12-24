#include "io.h"
#include <stdio.h>
int main()
{
    int x = 0;
    int y = 0;
    double area = 0;
    // int perimetro = 0;
    // double resultado;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo0115");
    IO_printf("\nEntre com os valores da base e da altura de um triangulo e obtenha a area de um triangulo com um quinto da altura");
    x = IO_readint("\nbase x = ");
    y = IO_readint("altura y = ");
    area = (x * ((double)y / 5)) / 2;
    IO_printf("\nA area e = %f", area);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}