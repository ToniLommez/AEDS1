#include "io.h"
#include <stdio.h>
int main()
{
    double comprimento = 0.0;
    double largura = 0.0;
    double altura = 0.0;
    double area = 0.0;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo0118");
    IO_printf("\nEntre com o valor do comprimento, largura e altura de um paralelepipedo e tenha a area de seis vezes esses valores");
    comprimento = 6*(IO_readdouble("\ncomprimento = "));
    largura = 6*(IO_readdouble("largura = "));
    altura = 6*(IO_readdouble("altura = "));
    area = comprimento*largura*altura;
    IO_printf("\nA area e = %f", area);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}