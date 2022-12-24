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


int recImpCresc(int n, int x)
{
    if(n>0)     
    {
        recImpCresc(n-2, x);
        IO_printf("%d ", (n*x));
    }
}
int recImpDecresc(int n, int x)
{
    if(n>0)     
    {
        IO_printf("%d ", (n*x));
        recImpDecresc(n-2, x);
    }
}
int recCresc(int n, int x)
{
    if(n>0)     
    {
        recCresc(n-1, x);
        IO_printf("%d ", (n*x));
    }
    else if (n==0)
    {
        IO_printf("1 ");
    }
}
int recDecrescFrac(int n, int x)
{
    if(n>0)     
    {
        IO_printf("1/%d ", (int)pow(x, n));
        recDecrescFrac(n-1, x);
    }
}
int recLetras(char a[80], int n)
{
    if(n>=0)     
    {
        recLetras(a, n-1);
        IO_printf("%c\n", a[n]);
    }
}
int recCrescImp2(int n, int x, int total, int igual)
{
    if(n>0)     
    {
        total = ((n+x)-1) + recCrescImp2(n-2, x, total, 1);
        IO_printf("%d", (n+x)-1);
        if (igual == 0)
            IO_printf(" = ");
        else
            IO_printf(" + ");
    }
    return(total);
}
double recCrescImp2Inv(int n, int x, double total, int igual)
{
    if(n>0)     
    {
        total = (1.0/((n+x)-1)) + recCrescImp2Inv(n-2, x, total, 1);
        IO_printf("1/%d", (n+x)-1);
        if (igual == 0)
            IO_printf(" = ");
        else
            IO_printf(" + ");
    }
    return(total);
}
int fibonacci(int n){
    int resposta=0;
    
    if (n==1 || n==2)
        resposta=1;
    else if (n>1)
        resposta=fibonacci(n-1)+fibonacci(n-2);
    return(resposta);
}
void fibonacciPar(int n, int y, int total)
{
    if(n>0)     
    {
        if(ePar(fibonacci(y)))
        {
            total +=fibonacci(y);
            if (n == 1)
                IO_printf("%d = %d ", fibonacci(y), total);
            else
                IO_printf("%d + ", fibonacci(y));
            n--;
        }
        fibonacciPar(n, y+1, total);
    }
}
int recNumPar(char a[80], int n)
{
    int count = 0;
    if(n<strlen(a))     
    {
        if (eDigito(a[n]))
        {
            if (ePar(a[n]))
            {
                count = 1;
            }
        }
        count = count + recNumPar(a, n+1);
    }
    return(count);
}
int recMaiusc(char a[80], int n)
{
    int count = 0;
    if(n<strlen(a))     
    {
        if (eMaiuscula(a[n]))
            count = 1;
        count = count + recMaiusc(a, n+1);
    }
    return(count);
}
int recPot(int x, int n, int igual, int total)
{
    if(n>0)     
    {
        total = (int)pow(x, n) + recPot(x, n-2, 1, total);
        IO_printf("%d^%d", x, n);
        if (igual == 0)
            IO_printf(" = ");
        else
            IO_printf(" + ");
    }
    return(total);
}
int recFat(int n)
{
    if ((n==1) || (n==0)) 
        return (1);               
    else
        return (recFat(n-1)*n);
}
double recDivFat(int n, int x, int igual, double total)
{
    if(n>1)     
    {
        total = ((double)n/recFat(n+1)) + recDivFat(n-1, x, 1, total);
        IO_printf("%d/%d!", n, n+1);
        if (igual == 0)
            IO_printf(" = ");
        else
            IO_printf(" + ");
    }
    return(total);
}

void exemplo0611()
{
    IO_clrscr();
    IO_printf("Exemplo0611\n");
    IO_printf("Valores impares em ordem crescente comecando no valor 7:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    IO_printf("\n");
    n = n+n-1;
    recImpCresc(n, 7);
}
void exemplo0612()
{
    IO_clrscr();
    IO_printf("Exemplo0612\n");
    IO_printf("Multiplos de 7 em ordem decrescente encerrando no valor 7:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    IO_printf("\n");
    n = n+n-1;
    recImpDecresc(n, 7);
}
void exemplo0613()
{
    IO_clrscr();
    IO_printf("Exemplo0613\n");
    IO_printf("Mostrar essa quantidade em valores da sequencia: 1 7 14 21 28 35 ... :\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    IO_printf("\n");
    n--;
    recCresc(n, 7);
}
void exemplo0614()
{
    IO_clrscr();
    IO_printf("Exemplo0614\n");
    IO_printf("Mostrar essa quantidade em valores decrescentes da sequencia: ... 1/2401 1/343 1/49 1/7 1 :\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    IO_printf("\n");
    recDecrescFrac(n, 7);
}
void exemplo0615()
{
    char a[80];
    IO_clrscr();
    IO_printf("Exemplo0615\n");
    IO_printf("Mostrar cada simbolo separadamente, um por linha:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite uma sequencia de caracteres:\n");
    IO_printf("a -> ");
    scanf("%s", a);
    getchar();
    IO_printf("\n");
    recLetras(a, strlen(a)-1);
}
void exemplo0616()
{
    IO_clrscr();
    IO_printf("Exemplo0616\n");
    IO_printf("Calcular a soma dos primeiros valores impares positivos comecando no valor 7:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    IO_printf("\n");
    n = n+n-1;
    IO_printf("%d", recCrescImp2(n, 7, 0, 0));
}
void exemplo0617()
{
    IO_clrscr();
    IO_printf("Exemplo0617\n");
    IO_printf("Calcular a soma dos inversos (1/x) dos primeiros valores impares positivos comecando no valor 7:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    IO_printf("\n");
    n = n+n-1;
    IO_printf("%lf", recCrescImp2Inv(n, 7, 0, 0));
}
void exemplo0618()
{
    IO_clrscr();
    IO_printf("Exemplo0618\n");
    IO_printf("Calcular certo termo par da serie de Fibonacci comecando em 1:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    IO_printf("\n");
    fibonacciPar(n, 1, 0);
}
void exemplo0619()
{
    IO_clrscr();
    char a[80];
    IO_printf("Exemplo0619\n");
    IO_printf("Contar os digitos com valores pares em uma cadeia de caracteres:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite uma sequencia de caracteres:\n");
    IO_printf("a -> ");
    scanf("%s", a);
    getchar();
    IO_printf("\nnumeros pares: %d", recNumPar(a, 0));
}
void exemplo0620()
{
    IO_clrscr();
    char a[80];
    IO_printf("Exemplo0620\n");
    IO_printf("Calcular a quantidade de maiusculas em uma cadeia de caracteres:\n");
    IO_printf("\n\n");
    IO_printf("\nDigite uma sequencia de caracteres:\n");
    IO_printf("a -> ");
    scanf("%s", a);
    getchar();
    IO_printf("\nLetras Maiusculas: %d", recMaiusc(a, 0));
}
void exemplo06E1()
{
    IO_clrscr();
    IO_printf("Exemplo06E1\n");
    IO_printf("Calcular o valor da funcao definida abaixo:\nf ( x, n ) = 1 + x2 + x4 + x6 + x8 + ...\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int x = IO_readint("x -> ");
    int n = IO_readint("n -> ");
    n = (n*2)-2;
    IO_printf("1 + ");
    IO_printf("%d\n", recPot(x, n, 0, 1));
}
void exemplo06E2()
{
    IO_clrscr();
    IO_printf("Exemplo06E2\n");
    IO_printf("Calcular o valor indicado abaixo:\ne = 1 + 1/2! + 2/3! + 4/5! + 6/7! + ...\n");
    IO_printf("\n\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("e -> ");
    IO_printf("1 + ");
    IO_printf("%lf\n", recDivFat(n, 1, 0, 1));
}