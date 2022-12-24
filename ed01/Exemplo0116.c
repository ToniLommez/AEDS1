#include "io.h"
#include <stdio.h>
int main()
{
    double x = 0.0;
    double temp = 0.0;
    double altura = 0.0;
    double area = 0.0;
    double perimetro = 0.0;
    IO_clrscr();
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("%s\n", "Exemplo0116");
    IO_printf("\nEntre com os valores do lado de um triangulo equilatero e obtenha a altura, a area e o perimetro de um triangulo com metade deste valor");
    x = IO_readdouble("\nlado x = ");
    x = x/2;
    perimetro = x*3;
    temp = x/2;
    altura = sqrt(3)/2*x;
    area = x*altura/2;
    IO_printf("\nA altura e = %f", altura);
    IO_printf("\nA area e = %f", area);
    IO_printf("\nO perimetro e = %f", perimetro);
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}