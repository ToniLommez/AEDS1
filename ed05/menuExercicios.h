#include <stdio.h>
#include <math.h>
#include "io.h"

bool eMaiuscula(char x)
{
    return (x >= 'A' && x <= 'Z');
}
bool eMinuscula(char x)
{
    return (x >= 'a' && x <= 'z');
}
bool eDigito(char x)
{
    return (x >= '0' && x <= '9');
}
bool eLetra(char x)
{
    return (eMaiuscula(x) || eMinuscula(x));
}
bool eAlfanumerico(char x)
{
    return (eLetra(x) || eDigito(x));
}
bool ePar(double x)
{
    return ((int)x%2==0);
}
void mostrarMultiplos7(int n)
{
    IO_printf("\n-> ");
    int a = 7;
    for (int i = 0; i < n; i++)
    {
        IO_printf("%d ", a);
        a = a + 7;
    }
}
void mostrarMultiplos7Pares(int n)
{
    IO_printf("\n-> ");
    int a = 7;
    for (int i = 0; i < n;)
    {
        if (ePar(a))
        {
        IO_printf("%d ", a);
        i++;
        }
        a = a + 7;
    }
}
void mostrarMultiplos7ImparesDecrescentes(int n)
{
    IO_printf("\n-> ");
    int a = 7;
    int b[(n-1)];
    int i = 0;
    for (; i < n;)
    {
        if (!(ePar(a)))
        {
            b[i]=a;
            i++;
        }
        a = a + 7;
    }
    n--;
    i = n;
    for (; i >= 0; i--)
    {
        IO_printf("%d ", b[i]);
    }
}
void mostrarMultiplos7Inversos(int n)
{
    double a = 7;
    for (int i = 0; i < n; i++)
    {
        IO_printf("-> 1/%d ou %f\n", (int)a, (1.0/a));
        a = a + 7;
    }
}
void mostrarNvezesXelevado(float x,  int n)
{
    int elevacao = 2;
    for (int i = 0; i < n; i++)
    {
        IO_printf("-> 1/%f^%d ou %f\n", x, elevacao, (1/pow(x, elevacao)));
        elevacao++;
    }
}
void mostrarSomaImpares3e7(int n)
{
    int a = 7;
    int resultado = 0;
    for (int i = 0; i < n;)
    {
        if ( (!(ePar(a))) && (a%3!=0) )
        {
            IO_printf("%d", a);
            i++;
            resultado = resultado + a;
            if (i < n)
            {
                IO_printf(" + ");
            }
            else
            {
                IO_printf(" = ");
            }
        }
        a = a + 2;
    }
    IO_printf("%d", resultado);
}
void mostrarSomaImpares3e7Inversos(int n)
{
    int a = 7;
    float resultado = 0.0;
    for (int i = 0; i < n;)
    {
        if ( (!(ePar(a))) && (a%3!=0) )
        {
            IO_printf("1/%d ou %f", a, (1.0/a));
            i++;
            resultado = resultado + (1.0/a);
            if (i < n)
            {
                IO_printf(" + \n");
            }
            else
            {
                IO_printf(" = \n");
            }
        }
        a = a + 2;
    }
    IO_printf("%f", resultado);
}
void mostrarSomaNaturaisApos7(int n)
{
    int a = 7;
    int resultado = 0;
    for (int i = 0; i < n;)
    {
        IO_printf("%d", a);
        i++;
        resultado = resultado + a;
        if (i < n)
        {
            IO_printf(" + ");
        }
        else
        {
            IO_printf(" = ");
        }
        a++;
    }
    IO_printf("%d", resultado);
}
void mostrarSomaQuadradosNaturaisApos7(int n)
{
    int a = 7;
    int resultado = 0;
    for (int i = 0; i < n;)
    {
        IO_printf("%d", (int)pow(a, 2));
        i++;
        resultado = resultado + pow(a, 2);
        if (i < n)
        {
            IO_printf(" + ");
        }
        else
        {
            IO_printf(" = ");
        }
        a++;
    }
    IO_printf("%d", resultado);
}
void mostrarSomaNaturaisInversosApos7(int n)
{
    int a = 7;
    float resultado = 0;
    for (int i = 0; i < n;)
    {
        IO_printf("1/%d ou %f", a, (1.0/a));
        i++;
        resultado = resultado + (1.0/a);
        if (i < n)
        {
            IO_printf(" + \n");
        }
        else
        {
            IO_printf(" = \n");
        }
        a++;
    }
    IO_printf("%f", resultado);
}
void mostrarSomaFatorial(int n)
{
    int a = n;
    int resultado = a;
    IO_printf("%d * ", a);
    for (int i = 0; a > 1; i++)
    {
        a--;
        IO_printf("%d", a);
        resultado = resultado * a;
        if (a > 1)
        {
            IO_printf(" * ");
        }
        else
        {
            IO_printf(" = ");
        }
    }
    IO_printf("%d", resultado);
}
int retornarSomaFatorial(int n)
{
    int a = n;
    int resultado = a;
    for (int i = 0; a > 1; i++)
    {
        a--;
        resultado = resultado * a;
    }
    return(resultado);
}
void mostrarSomaFatorial2(int n)
{
    int a = 2;
    int b = 3;
    double resultado = 1;
    for (int i = 0; i < n; i++)
    {
        IO_printf("1 + %d/%d!", a, b);
        resultado = resultado * (1.0+((double)a/retornarSomaFatorial(b)));
        if (i < (n-1))
        {
            IO_printf(" * \n");
        }
        else
        {
            IO_printf(" = \n");
        }
        a++;
        b++;
    }
    IO_printf("%f", resultado);
}

void exemplo0511()
{
    IO_clrscr();
    IO_printf("Exemplo0411");
    IO_printf("\nEntre com um numero inteiro e veja esta quantidade de multiplos de 7\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarMultiplos7(n);
}

void exemplo0512()
{
    IO_clrscr();
    IO_printf("Exemplo0512");
    IO_printf("\nEntre com um numero inteiro e veja esta quantidade de multiplos de 7 pares\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarMultiplos7Pares(n);
}

void exemplo0513()
{
    IO_clrscr();
    IO_printf("Exemplo0513");
    IO_printf("\nEntre com um numero inteiro e veja esta quantidade de multiplos de 7 impares de forma decrescente\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarMultiplos7ImparesDecrescentes(n);
}

void exemplo0514()
{
    IO_clrscr();
    IO_printf("Exemplo0514");
    IO_printf("\nEntre com um numero inteiro e veja esta quantidade de multiplos de 7 inversos (1/7)\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarMultiplos7Inversos(n);
}

void exemplo0515()
{
    IO_clrscr();
    IO_printf("Exemplo0515");
    IO_printf("\nEntre com um valor real 'x' para calcular 1/x^2, e um valor 'n' de quantas potencias voce quer ver\n");
    IO_printf("\nDigite o numero:\n");
    float x = IO_readfloat("-> ");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarNvezesXelevado(x, n);
}

void exemplo0516()
{
    IO_clrscr();
    IO_printf("Exemplo0516");
    IO_printf("\nEntre com uma quantidade 'n' para ver e calcular a soma dos valores impares nao multiplos de 3 comecando por 7 desta mesma quantidade 'n'\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarSomaImpares3e7(n);
}

void exemplo0517()
{
    IO_clrscr();
    IO_printf("Exemplo0517");
    IO_printf("\nEntre com uma quantidade 'n' para ver e calcular a soma dos inversos dos valores impares nao multiplos de 3 comecando por 7 desta mesma quantidade 'n'\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarSomaImpares3e7Inversos(n);
}

void exemplo0518()
{
    IO_clrscr();
    IO_printf("Exemplo0518");
    IO_printf("\nEntre com uma quantidade 'n' para ver e calcular a soma dos 'n' numeros naturais depois de 7\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarSomaNaturaisApos7(n);
}

void exemplo0519()
{
    IO_clrscr();
    IO_printf("Exemplo0519");
    IO_printf("\nEntre com uma quantidade 'n' para ver e calcular a soma dos 'n' numeros naturais depois de 7\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarSomaQuadradosNaturaisApos7(n);
}

void exemplo0520()
{
    IO_clrscr();
    IO_printf("Exemplo0520");
    IO_printf("\nEntre com uma quantidade 'n' para ver e calcular a soma dos inversos dos 'n' numeros naturais depois de 7\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarSomaNaturaisInversosApos7(n);
}

void exemplo05E1()
{
    IO_clrscr();
    IO_printf("Exemplo05E1");
    IO_printf("\nEntre com uma quantidade 'n' para ver seu fatorial\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarSomaFatorial(n);
}

void exemplo05E2()
{
    IO_clrscr();
    IO_printf("Exemplo05E2");
    IO_printf("\nEntre com uma quantidade 'n' para ver  ( n ) = (1+2/3!) * (1+3/4!) * (1+4/5!) * ...\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("-> ");
    mostrarSomaFatorial2(n);
}