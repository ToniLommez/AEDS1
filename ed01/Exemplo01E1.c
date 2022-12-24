#include "io.h"
#include <stdio.h>
int main()
{
    double x = 0.0;
    double area = 0.0;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo01E1");
    IO_printf("\nEntre com o valor da area de uma circunferencia e obtenha o raio do dobro dessa area");
    area = IO_readdouble("\narea = ")*2;
    x = sqrt(area/M_PI);
    IO_printf("\nO raio e = %f", x);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}