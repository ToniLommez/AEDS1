#include "io.h"
#include <stdio.h>
int main()
{
    int x = 0;
    int area = 0;
    int perimetro = 0;
    // double resultado;
    IO_clrscr();
    IO_printf("%s\n", "Exemplo0112");
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("\nEntre com o valor do lado do quadrado e obtenha a area e o perimetro do triplo deste tamanho:");
    x = IO_readint("\n");
    x = x * 3;
    area = x * x;
    perimetro = x * 4;
    // resultado = (float)area / 4;
    IO_printf("\nA area e: %d\nO perimetro e:%d", area, perimetro);
    IO_pause("\nAperte ENTER para terminar.\n");
    IO_clrscr();
    return (0);
}