#include "io.h"
#include <stdio.h>
int main()
{
    int x = 0;
    int y = 0;
    int area = 0;
    double resultado;
    IO_clrscr();
    IO_printf("%s\n", "Exemplo0113");
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("\nEntre com os valores de 2 lados de um retangulo e obtenha um terco da area");
    x = IO_readint("\neixo x = ");
    y = IO_readint("eixo y = ");
    area = x * y;
    resultado = (float)area / 3;
    IO_printf("\nUm terco da area do retangulo e = %f", resultado);
    IO_pause("\nAperte ENTER para terminar.\n");
    IO_clrscr();
    return (0);
}