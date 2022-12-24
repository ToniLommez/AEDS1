#include "io.h"
#include <stdio.h>
int main()
{
    int x = 0;
    int area =0;
    double resultado;
    IO_clrscr();
    IO_printf("%s\n", "Exemplo0111");
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("\nEntre com o valor do lado do quadrado e obtenha um quarto da area dele:");
    x = IO_readint("\n");
    area = x * x;
    resultado = (float)area / 4;
    IO_printf("\nUm quarto da area do quadrado e %f", resultado);
    IO_pause("\nAperte ENTER para terminar.\n");
    return (0);
}