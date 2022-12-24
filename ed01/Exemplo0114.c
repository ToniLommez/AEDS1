#include "io.h"
#include <stdio.h>
int main()
{
    int x = 0;
    int y = 0;
    int area = 0;
    int perimetro = 0;
    // double resultado;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo0114");
    IO_printf("\nEntre com os valores de 2 lados de um retangulo e obtenha a area e o perimetro do dobro destes valores");
    x = IO_readint("\neixo x = ");
    y = IO_readint("eixo y = ");
    x = x*2;
    y = y*2;
    perimetro = (2*x)+(2*y);
    area = x*y;
    IO_printf("\nA area e = %d\nO perimetro e = %d", area, perimetro);
    IO_pause("\nAperte ENTER para terminar.\n");
    IO_clrscr();
    return (0);
}