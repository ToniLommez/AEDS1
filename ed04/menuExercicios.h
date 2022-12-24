#include <stdio.h>
#include "io.h"

char charBuffer[160];
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
int nDigitos(int n)
{
    int i = 0;
    while (n != 0) {
    i++;
        n /= 10;
    }
    return (i);
}
void mostrarMaiusculosMenoresQueK (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (eMaiuscula(x[i]) && x[i] < 'K')
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("Caractere maiusculo menor que K: %s", d);
    }
    else
    {
        IO_printf("Caracteres maiusculos menores que K: %s", d);
    }
}
void mostrarLetrasMenoresQueK (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if ((eMaiuscula(x[i]) && x[i] < 'K') || (eMinuscula(x[i]) && x[i] < 'k'))
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("Caractere menor que K ou k: %s", d);
    }
    else
    {
        IO_printf("Caracteres menores que K ou k: %s", d);
    }
}
void contarLetrasMenoresQueK (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if ((eMaiuscula(x[i]) && x[i] < 'K') || (eMinuscula(x[i]) && x[i] < 'k'))
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("%d caractere menor que K ou k", quantidade);
    }
    else
    {
        IO_printf("%d caracteres menores que K ou k", quantidade);
    }
}
void contarDigitosPares (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (eDigito((x[i])))
        {
            if (ePar((x[i])))
            {
                d[quantidade] = x[i];
                quantidade++;
            }
            
        }
    }
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("%d digito par", quantidade);
    }
    else
    {
        IO_printf("%d digitos pares", quantidade);
    }
}
void mostrarNaoAlfanumericos (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (!(eAlfanumerico((x[i]))))
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("Sequencia: %s\nCaractere nao alfanumerico: %s", x, d);
    }
    else
    {
        IO_printf("Sequencia: %s\nCaracteres nao alfanumericos: %s", x, d);
    }
}
void mostrarAlfanumericos (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (eAlfanumerico((x[i])))
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("Sequencia: %s\nCaractere alfanumerico: %s", x, d);
    }
    else
    {
        IO_printf("Sequencia: %s\nCaracteres alfanumericos: %s", x, d);
    }
}
void mostrarAlfanumericos2 (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (eAlfanumerico((x[i])))
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    if (quantidade == 1)
    {
        IO_printf("Sequencia: %s\nCaractere alfanumerico: %s", x, d);
    }
    else
    {
        IO_printf("Sequencia: %s\nCaracteres alfanumericos: %s", x, d);
    }
}
void contarAlfanumericos (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (eAlfanumerico((x[i])))
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("\nCaractere alfanumerico: %d", quantidade);
    }
    else
    {
        IO_printf("\nCaracteres alfanumericos: %d", quantidade);
    }
}
int contarAlfanumericos2 (char x[80])
{
    char d[80] = "";
    int quantidade = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (eAlfanumerico((x[i])))
        {
            d[quantidade] = x[i];
            quantidade++;
        }
    }
    IO_printf("\nQuantidade de alfanumericos: %d", quantidade);
    return (quantidade);
}
void lerEConcatenarAlfanumericos ()
{
    IO_printf("\nEscolha quantas sequencias de caracteres voce quer testar:");
    int n = IO_readint("\n->");
    char c[80] = "";
    char d[160] = "";
    int ponteiros[n] = {0};
    sprintf(d, "%d", n);
    int j;
    if (n<10)
    {
        j = 1;
    }
    else
    {
        j = 2;
    }
    for (size_t i = 0; i < n; i++)
    {
        ponteiros[i] = j;
        IO_printf("\n\nEntre com uma sequencia de caracteres do teclado:");
        IO_printf("\n->");
        scanf("%s", c);
        getchar();
        for (int k = 0; k < strlen(c); k++)
        {
            d[j] = c[k];
            j++;
        }
    }
    for (int l = 0; l < n; l++)
    {
        if (nDigitos(ponteiros[l]) == 1)
        {
            sprintf(d, "%s00%d", d, ponteiros[l]);
        }
        else if (nDigitos(ponteiros[l]) == 2)
        {
            sprintf(d, "%s0%d", d, ponteiros[l]);
        }
        else if (nDigitos(ponteiros[l]) == 3)
        {
            sprintf(d, "%s%d", d, ponteiros[l]);
        }
    }
    sprintf(charBuffer, "%s", d);
}
void cleanCharBuffer()
{
    for (int i = 0; i < 120; i++)
    {
        charBuffer[i] = NULL;
    }
    

}
void mostrarEContarAlfanumericosTuring(char x[160])
{
    int quantasPalavras = ((int)x[0] - 48);
    int enderecoPalavra[quantasPalavras+1];
    int j = quantasPalavras * 3;
    j = strlen(x) - j;
    enderecoPalavra[quantasPalavras] = j;
    for (int i = 0; i < quantasPalavras; i++)
    {
        enderecoPalavra[i] = (((int)x[j]-48)*100) + (((int)x[j+1]-48)*10) + (((int)x[j+2]-48));
        j = j+3;
    }

    // criar for de quantas palavras serao
    // criar dentro um for cujo iteracoes eh o tamanho da palavra
    // usar o for de dentro para passar caracteres para d[]
    int totalAlfanumericos = 0;
    char d[80];
    for (int i = 0; i < quantasPalavras; i++) // i ira acessar o enderecoPalavra
    {
        for (int k = 0; k < (enderecoPalavra[i+1] - enderecoPalavra[i]); k++) // k = tamanho da palavra
        {
            d[k] = x[enderecoPalavra[i]+k];
        }
        for (int m = (enderecoPalavra[i+1] - enderecoPalavra[i]); m < strlen(d); m++) // limpar valores extras em 'd'
        {
            d[m] = NULL;
        }
        mostrarAlfanumericos2(d);
        totalAlfanumericos = contarAlfanumericos2(d) + totalAlfanumericos;
        IO_printf("\n\n");
    }
    IO_printf("O total de alfanumericos e: %d", totalAlfanumericos);
}
bool possuiMenosAlfanumerico (char c[80], char d[80])
{
    return (contarAlfanumericos2(c) < contarAlfanumericos2(d));
}
void mostrarMenorQuantidadeDeAlfanumericos(char c[80], char d[80])
{
    if (possuiMenosAlfanumerico(c, d))
    {
        IO_clrscr();
        IO_printf("possui menos caracteres: %s", c);
    }
    else
    {
        IO_clrscr();
        IO_printf("possui menos caracteres: %s", d);
    }
    
}

void exemplo0411()
{
    IO_clrscr();
    IO_printf("Exemplo0411");
    IO_printf("\nDescubra se n numeros estao dentro do intervalo real:\n\n");
    IO_printf("\nEntre com dois valores reais para definir um intervalo fechado [a,b]:\n");
    float a = IO_readfloat("->");
    float b = IO_readfloat("->");
    IO_printf("\n\nEntre com uma quantidade 'n' de valores a serem testados:\n");
    int n = IO_readfloat("->");
    IO_printf("\n\nEntre com os valores a serem testados:\n");
    float x[n];
    int quantidade = 0;
    for (int i = 0; i < n; i++)
    {
        x[i]=IO_readfloat("->");
        if (x[i] >= a && x[i] <= b)
        {
            quantidade++;
        }
    }
    IO_clrscr();
    IO_printf("%d valores estao dentro do intervalo\n%d valores estao fora do intervalo", quantidade, n-quantidade);
}

void exemplo0412()
{
    IO_clrscr();
    IO_printf("Exemplo0412\n");
    IO_printf("\nContar e mostrar quais letras sao maiusculas e menores que K:\n\n");
    IO_printf("Entre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    char d[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    int quantidade = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (eMaiuscula(c[i]) && c[i] < 'K')
        {
            d[quantidade] = c[i];
            quantidade++;
        }
    }
    getchar();
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("%d caractere e maiusculo e menore que K\nEste caractere e: %s", quantidade, d);
    }
    else
    {
        IO_printf("%d caracteres sao maiusculos e menores que K\nEstes caracteres sao: %s", quantidade, d);
    }
}

void exemplo0413()
{
    IO_clrscr();
    IO_printf("Exemplo0413");
    IO_printf("\nMostrar quantas letras sao maiusculas e menores que K:\n\n");
    IO_printf("\nEntre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    char d[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    int quantidade = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (eMaiuscula(c[i]) && c[i] < 'K')
        {
            d[quantidade] = c[i];
            quantidade ++;
        }
    }

    getchar();
    IO_clrscr();
    if (quantidade == 1)
    {
        IO_printf("%d caractere e maiusculo e menore que K\nEste caractere e: %s", quantidade, d);
    }
    else
    {
        IO_printf("%d caracteres sao maiusculos e menores que K\nEstes caracteres sao: %s", quantidade, d);
    }
}

void exemplo0414()
{
    IO_clrscr();
    IO_printf("Exemplo0414");
    IO_printf("\nMostrar as letras maiusculas e menores que K:\n\n");
    IO_printf("\nEntre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    getchar();
    mostrarMaiusculosMenoresQueK(c);
}

void exemplo0415()
{
    IO_clrscr();
    IO_printf("Exemplo0415");
    IO_printf("\nMostrar a quantidade de letras maiusculas/minusculas e menores que K/k:\n\n");
    IO_printf("\nEntre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    getchar();
    contarLetrasMenoresQueK(c);
}

void exemplo0416()
{
    IO_clrscr();
    IO_printf("Exemplo0416");
    IO_printf("\nMostrar as letras maiusculas/minusculas e menores que K/k:\n\n");
    IO_printf("\nEntre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    getchar();
    mostrarLetrasMenoresQueK(c);
}

void exemplo0417()
{
    IO_clrscr();
    IO_printf("Exemplo0417");
    IO_printf("\nMostrar a quantidade de digitos pares em uma cadeia:\n\n");
    IO_printf("\nEntre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    getchar();
    contarDigitosPares(c);
}

void exemplo0418()
{
    IO_clrscr();
    IO_printf("Exemplo0418");
    IO_printf("\nMostrar todos os simbolos nao alfanumericos em uma cadeia:\n\n");
    IO_printf("\nEntre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    getchar();
    mostrarNaoAlfanumericos(c);
}

void exemplo0419()
{
    IO_clrscr();
    IO_printf("Exemplo0419");
    IO_printf("\nMostrar todos os simbolos alfanumericos em uma cadeia:\n\n");
    IO_printf("\nEntre com uma sequencia de caracteres do teclado:");
    char c[80] = "";
    IO_printf("\n->");
    scanf("%s", c);
    getchar();
    mostrarAlfanumericos(c);
}

void exemplo0420()
{
    IO_clrscr();
    IO_printf("Exemplo0420");
    IO_printf("\nMostrar e contar simbolos alfanumericos em 'n' cadeias de caracteres:\n\n");
    char c[160] = "";
    lerEConcatenarAlfanumericos();
    strcpy(c, charBuffer);
    cleanCharBuffer();
    IO_printf("%s", c);
    mostrarEContarAlfanumericosTuring(c);
}

void exemplo04E1()
{
    IO_clrscr();
    IO_printf("Exemplo04E1");
    IO_printf("\nMostrar a quantidade de simbolos alfanumericos em uma frase:\n\n");
    IO_printf("\nEntre com uma frase de caracteres do teclado:");
    char c[80] = "";
    IO_printf("\n->");
    gets(c);
    mostrarAlfanumericos(c);
    contarAlfanumericos2(c);
}

void exemplo04E2()
{
    IO_clrscr();
    IO_printf("Exemplo04E2");
    IO_printf("\nMostrar qual das suas sequencias tem menos digitos:\n\n");
    IO_printf("\nEntre com duas frases de caracteres do teclado:");
    char c[80] = "";
    char d[80] = "";
    IO_printf("\n->");
    gets(c);
    IO_printf("\n->");
    gets(d);
    mostrarMenorQuantidadeDeAlfanumericos(c, d);
}