#include <stdio.h>
#include "io.h"

void exemplo0311()
{
    IO_clrscr();
    IO_printf("Exemplo0311");
    IO_printf("\nEntre com uma palavra para mostrar as letras minusculas:");
    char c[80];
    IO_printf("\n->");
    scanf("%s", c);
    int posicao = 0;
    for (posicao = 0; posicao < strlen(c); posicao++)
    {
        if (c[posicao]>='a' && c[posicao]<='z')
        {
            IO_printf("%c", c[posicao]);
        }
    }
    getchar();
}

void exemplo0312()
{
    IO_clrscr();
    IO_printf("Exemplo0312");
    IO_printf("\nEntre com uma palavra para contar e mostrar apenas as letras minusculas:");
    char c[80];
    IO_printf("\n->");
    scanf("%s", c);
    int posicao = 0;
    int minusculas = 1;
    for (posicao = 0; posicao < strlen(c); posicao++)
    {
        if (c[posicao]>='a' && c[posicao]<='z')
        {
            IO_printf("%d - %c\n", minusculas, c[posicao]);
            minusculas ++;
        }
    }
    getchar();
}

void exemplo0313()
{
    IO_clrscr();
    IO_printf("Exemplo0313");
    IO_printf("\nEntre com uma palavra para contar e mostrar as letras minusculas percorrendo do fim para o inicio da palavra:");
    char c[80];
    IO_printf("\n->");
    scanf("%s", c);
    int posicao = 0;
    int minusculas = 1;
    for (posicao = strlen(c); posicao >= 0; posicao--)
    {
        if (c[posicao]>='a' && c[posicao]<='z')
        {
            IO_printf("%d - %c\n", minusculas, c[posicao]);
            minusculas ++;
        }
    }
    getchar();
}

void exemplo0314()
{
    IO_clrscr();
    IO_printf("Exemplo0314");
    IO_printf("\nEntre com uma cadeia de caracteres do teclado para contar e mostrar todos simbolos que forem letras, ou maiusculas ou minusculas:");
    char c[80];
    IO_printf("\n->");
    scanf("%s", c);
    int posicao = 0;
    int minusculas = 1;
    for (posicao = 0; posicao < strlen(c); posicao++)
    {
        if (c[posicao]>='a' && c[posicao]<='z' || c[posicao]>='A' && c[posicao]<='Z' )
        {
            IO_printf("%d - %c\n", minusculas, c[posicao]);
            minusculas ++;
        }
    }
    getchar();
}

void exemplo0315()
{
    IO_clrscr();
    IO_printf("Exemplo0315");
    IO_printf("\nEntre com uma cadeia de caracteres do teclado para contar e mostrar todos os digitos, percorrendo do fim para o inicio da cadeia de caracteres:");
    char c[80];
    IO_printf("\n->");
    scanf("%s", c);
    int posicao = 0;
    int quantidade = 1;
    for (posicao = strlen(c) - 1; posicao >= 0; posicao--)
    {
        if (true)
        {
            IO_printf("%d - %c\n", quantidade, c[posicao]);
            quantidade ++;
        }
    }
    getchar();
}

void exemplo0316()
{
    IO_clrscr();
    IO_printf("Exemplo0316");
    IO_printf("\nEntre com uma cadeia de caracteres do teclado para contar e mostrar tudo o que nao for digito e tambem nao for letra:");
    char c[80];
    IO_printf("\n->");
    scanf("%s", c);
    int posicao = 0;
    int quantidade = 1;
    for (posicao = 0; posicao < strlen(c); posicao++)
    {
        if (!(c[posicao] >= 'a' && c[posicao] <= 'z' || c[posicao] >= 'A' && c[posicao] <= 'Z' || c[posicao] >= '0' && c[posicao] <= '9'))
        {
            IO_printf("%d - %c\n", quantidade, c[posicao]);
            quantidade ++;
        }
    }
    getchar();
}

void exemplo0317()
{
    IO_clrscr();
    IO_printf("Exemplo0317");
    IO_printf("\nEntre com dois valores inteiros (a,b), limites para definirem um intervalo [a:b]:");
    int a = IO_readint("\na -> ");
    int b = IO_readint("b -> ");
    IO_printf("\nEntre com uma quantidade (n) de valores inteiros a serem testados:");
    int c = IO_readint("\nn -> ");
    int valores[c];
    int i;
    IO_printf("\nEntre com os outros tantos valores quantos os indicados pela quantidade (n), um (x) por vez:\n");
    for (i = 0; i < c; i++)
    {
        valores[i] = IO_readint("-> ");
    }
    int estaoDentro = 0;
    for (i = 0; i < c; i++)
    {
        if (valores[i] >= a && valores[i] <= b && valores[i]%5==0)
        {
            estaoDentro++;
        }
    }
    IO_printf("\n%d valores sao multiplos de 5 e pertencem ao intervalo [%d:%d]", estaoDentro, a, b);
}

void exemplo0318()
{
    IO_clrscr();
    IO_printf("Exemplo0318");
    IO_printf("\nEntre com dois valores inteiros (a,b), limites para definirem um intervalo [a:b]:");
    int a = IO_readint("\na -> ");
    int b = IO_readint("b -> ");
    IO_printf("\nEntre com uma quantidade (n) de valores inteiros a serem testados:");
    int c = IO_readint("\nn -> ");
    int valores[c];
    int i;
    IO_printf("\nEntre com os outros tantos valores quantos os indicados pela quantidade (n), um (x) por vez:\n");
    for (i = 0; i < c; i++)
    {
        valores[i] = IO_readint("-> ");
    }
    int estaoDentro = 0;
    for (i = 0; i < c; i++)
    {
        if (valores[i] >= a && valores[i] <= b && valores[i]%5==0 && valores[i]%3!=0)
        {
            estaoDentro++;
        }
    }
    IO_printf("\n%d valores sao multiplos de 5 e nao sao multiplos de 3 e pertencem ao intervalo [%d:%d]", estaoDentro, a, b);
}

void exemplo0319()
{
    IO_clrscr();
    IO_printf("Exemplo0319");
    IO_printf("\nEntre com dois valores reais (a, b), o primeiro (a) menor que o segundo (b), confirmadamente, para definirem um intervalo aberto (a:b)");
    float a = IO_readfloat("\na -> ");
    float b = IO_readfloat("b -> ");
    while (a>b)
    {
        IO_clrscr();
        IO_printf("'b' deve ser maior do que 'a'!\nEntre com os valores novamente:");
        a = IO_readfloat("\na -> ");
        b = IO_readfloat("b -> ");
    };
    IO_printf("\nEntre com quantidade (n) de valores reais a serem testados");
    int c = IO_readint("\nn -> ");
    float valores[c];
    int i;
    IO_printf("\nEntre com os outros tantos valores quantos os indicados pela quantidade (n), um (x) por vez:\n");
    for (i = 0; i < c; i++)
    {
        valores[i] = IO_readfloat("-> ");
    }
    int estaoDentro = 0;
    for (i = 0; i < c; i++)
    {
        if (valores[i] >= a && valores[i] <= b && int(valores[i])%2!=0.0)
        {
            estaoDentro++;
        }
    }
    IO_printf("\n%d valores pertencem ao [%f:%f], cujas partes inteiras sao impares.", estaoDentro, a, b);
}

void exemplo0320()
{
    IO_clrscr();
    IO_printf("Exemplo0320");
    IO_printf("\nEntre com dois valores reais (a e b), maiores que 0 e menores que 1, confirmadamente, para definirem um intervalo aberto (a:b)");
    float a = IO_readfloat("\na -> ");
    while (a<0 || a>1)
    {
        IO_clrscr();
        IO_printf("'a' deve estar entre 0 e 1!\nEntre com os valores novamente:");
        a = IO_readfloat("\na -> ");
    };
    float b = IO_readfloat("b -> ");
    while (b<0 || b>1)
    {
        IO_clrscr();
        IO_printf("'b' deve estar entre 0 e 1!\nEntre com os valores novamente:\na = %f", a);
        b = IO_readfloat("\nb -> ");
    };
    IO_printf("\nEntre com uma quantidade (n) de valores reais a serem testados");
    int c = IO_readint("\nn -> ");
    float valores[c];
    int i;
    IO_printf("\nEntre com os outros tantos valores quantos os indicados pela quantidade (n), um (x) por vez:\n");
    for (i = 0; i < c; i++)
    {
        valores[i] = IO_readfloat("-> ");
    }
    int estaoDentro = 0;
    float valorFracionado[c];
    for (i = 0; i < c; i++)
    {
        valorFracionado[i] = valores[i] - int(valores[i]);
    }
    for (i = 0; i < c; i++)
    {
        if (valorFracionado[i] < a || valorFracionado[i] > b)
        {
            estaoDentro++;
        }
    }
    IO_printf("\n%d valores cujas partes fracionadas nao pertencem ao intervalo ]%f:%f[.", estaoDentro, a, b);
}

void exemplo03E1()
{
    IO_clrscr();
    IO_printf("Exemplo03E1");
    IO_printf("\nEntre com uma linha do teclado para separar em outra cadeia de caracteres\ne mostrar todos os simbolos nao alfanumericos (letras ou digitos) na cadeia de caracteres:");
    char c[80];
    IO_printf("\n->");
    gets(c);
    int posicao = 0;
    int quantidade = 1;
    IO_printf("\n");
    for (posicao = 0; posicao < strlen(c); posicao++)
    {
        if (!(c[posicao] >= 'a' && c[posicao] <= 'z' || c[posicao] >= 'A' && c[posicao] <= 'Z' || c[posicao] >= '0' && c[posicao] <= '9'))
        {
            IO_printf("%c", c[posicao]);
            quantidade ++;
        }
    }
}

void exemplo03E2()
{
    IO_clrscr();
    IO_printf("Exemplo03E2");
    IO_printf("\nEntre com uma cadeia de caracteres do teclado para dizer se a sequencia contem apenas simbolos que nao sao letras");
    char c[80];
    IO_printf("\n->");
    scanf("%s", c);
    int posicao = 0;
    int quantidade = 1;
    bool possuiLetra = false;
    for (posicao = 0; posicao < strlen(c); posicao++)
    {
        if (c[posicao] >= 'a' && c[posicao] <= 'z')
        {
            possuiLetra = true;
            quantidade ++;
        }
    }
    if (possuiLetra)
    {
        IO_printf("\nA palavra possui letra dentro dela.");
    }
    else
    {
        IO_printf("\nA palavra possui apenas simbolos e/ou numeros.");
    }
    getchar();
}