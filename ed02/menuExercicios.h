#include <stdio.h>
void exemplo0211()
{
    IO_clrscr();
    IO_printf("Entre com um numero e descubra se ele e par ou impar:");
    int numero = IO_readint("\nnumero = ");
    if (numero % 2 == 0 || numero == 0)
    {
        IO_printf("%d e par.", numero);
    }
    else
    {
        IO_printf("%d e impar.", numero);
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0212()
{
    IO_clrscr();
    IO_printf("Entre com um numero e descubra se ele e par e maior que -30 ou impar e menor que 30:");
    int numero = IO_readint("\nnumero = ");
    if ((numero % 2 == 0 || numero == 0) && (numero > -30))
    {
        IO_printf("%d e par e maior que -30", numero);
    }
    else
    {
        if ((numero % 2 != 0) && (numero < 30))
            IO_printf("%d e impar e menor que trinta", numero);
        else
            IO_printf("%d nao se encaixa nas condicoes", numero);
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0213()
{
    IO_clrscr();
    IO_printf("Entre com um numero e descubra se ele pertence ao intervalo aberto entre (25:40):");
    int numero = IO_readint("\nnumero = ");
    if ((numero > 25) && (numero < 40))
    {
        IO_printf("%d esta dentro do intervalo aberto entre (25:40)", numero);
    }
    else
    {
        IO_printf("%d nao esta dentro do intervalo aberto entre (25:40)", numero);
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0214()
{
    IO_clrscr();
    IO_printf("Entre com um numero e descubra se ele pertence ao intervalo fechado entre [15:45]:");
    int numero = IO_readint("\nnumero = ");
    if ((numero >= 15) && (numero <= 45))
    {
        IO_printf("%d esta dentro do intervalo fechado entre [15:45]", numero);
    }
    else
    {
        IO_printf("%d nao esta dentro do intervalo fechado entre [15:45]", numero);
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0215()
{
    IO_clrscr();
    IO_printf("Entre com um numero e descubra se ele pertence aos intervalos fechados [10:25] ou [20:40], ou a apenas a um deles:");
    int numero = IO_readint("\nnumero = ");
    if (((numero >= 10) && (numero <= 25)) && ((numero >= 20) && (numero <= 40)))
    {
        IO_printf("%d pertence aos 2 intervalores fechados [10:25] e [20:40]", numero);
    }
    else
    {
        if (((numero >= 10) && (numero <= 25)))
        {
            IO_printf("%d pertence apenas ao intervalo fechado [10:25]", numero);
        }
        else
        {
            if (((numero >= 20) && (numero <= 40)))
                IO_printf("%d pertence apenas ao intervalo fechado [20:40]", numero);
            else
                IO_printf("%d nao pertence a nenhum intervalo", numero);
        }
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0216()
{
    IO_clrscr();
    IO_printf("Entre com dois numeros e descubra se o primeiro e impar e o segundo e par:");
    int numero1 = IO_readint("\nnumero 1 = ");
    int numero2 = IO_readint("numero 2 = ");
    if ((numero1 % 2 != 0) && (numero2 % 2 == 0 || numero2 == 0))
    {
        IO_printf("\no numero 1: %d e impar e o numero 2: %d e par?\n>sim", numero1, numero2);
    }
    else
    {
        IO_printf("\no numero 1: %d e impar e o numero 2: %d e par?\n>nao", numero1, numero2);
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0217()
{
    IO_clrscr();
    IO_printf("Entre com dois numeros e descubra se o primeiro e par e negativo, e se o segundo e impar e positivo:");
    int numero1 = IO_readint("\nnumero 1 = ");
    int numero2 = IO_readint("numero 2 = ");
    if (((numero1 % 2 == 0 || numero1 == 0) && (numero1 < 0)) && ((numero2 % 2 != 0) && (numero2 >= 0)))
    {
        IO_printf("\no numero 1: %d e par e negativo e o numero 2: %d e impar e positivo?\n>sim", numero1, numero2);
    }
    else
    {
        IO_printf("\no numero 1: %d e par e negativo e o numero 2: %d e impar e positivo?\n>nao", numero1, numero2);
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0218()
{
    IO_clrscr();
    IO_printf("Entre com dois numeros e descubra se o segundo e igual, maior ou menor ao primeiro:");
    int numero1 = IO_readint("\nnumero 1 = ");
    int numero2 = IO_readint("numero 2 = ");
    if (numero2 == numero1)
    {
        IO_printf("\no numero 2: %d e igual ao numero 1: %d", numero2, numero1);
    }
    else
    {
        if (numero2 > numero1)
        {
            IO_printf("\no numero 2: %d e maior que o numero 1: %d", numero2, numero1);
        }
        else
        {
            IO_printf("\no numero 2: %d e menor que o numero 1: %d", numero2, numero1);
        }
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0219()
{
    IO_clrscr();
    IO_printf("Entre com tres numeros e descubra se o primeiro esta entre os outros dois quando esses forem diferentes entre si:");
    int numero1 = IO_readint("\nnumero 1 = ");
    int numero2 = IO_readint("numero 2 = ");
    int numero3 = IO_readint("numero 3 = ");
    if (numero2 == numero3)
    {
        IO_printf("\no numero 2: %d e igual ao numero 3: %d", numero2, numero3);
    }
    else
    {
        if ((numero1 < numero2 && numero1 > numero3) || (numero1 < numero3 && numero1 > numero2))
        {
            IO_printf("\no numero 1: %d esta entre o numero 2: %d e o numero 3: %d", numero1, numero2, numero3);
        }
        else
        {
            IO_printf("\no numero 1: %d nao esta entre o numero 2: %d e o numero 3: %d", numero1, numero2, numero3);
        }
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo0220()
{
    IO_clrscr();
    IO_printf("Entre com tres numeros e descubra se o primeiro nao esta entre os outros dois, quando todos forem diferentes entre si:");
    int numero1 = IO_readint("\nnumero 1 = ");
    int numero2 = IO_readint("numero 2 = ");
    int numero3 = IO_readint("numero 3 = ");
    if ((numero1 == numero2) || (numero1 == numero3) || (numero2 == numero3))
    {
        IO_printf("\nalgum dos numeros e igual entre si");
    }
    else
    {
        if ((numero1 < numero2 && numero1 > numero3) || (numero1 < numero3 && numero1 > numero2))
        {
            IO_printf("\no numero 1: %d esta entre o numero 2: %d e o numero 3: %d", numero1, numero2, numero3);
        }
        else
        {
            IO_printf("\ntodos os numeros sao diferentes entre si e:\no numero 1: %d nao esta entre o numero 2: %d e o numero 3: %d", numero1, numero2, numero3);
        }
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo02E1()
{
    IO_clrscr();
    IO_printf("Entre com tres caracteres e descubra se o primeiro valor lido esta entre os outros dois, ou se e igual a um deles:");
    char caractere1 = IO_readchar("\ncaractere 1 = ");
    char caractere2 = IO_readchar("caractere 2 = ");
    char caractere3 = IO_readchar("caractere 3 = ");
    if (caractere1 == caractere2)
    {
        IO_printf("\nO primeiro caractere: %c e igual ao segundo caractere: %c", caractere1, caractere2);
    }
    else
    {
        if (caractere1 == caractere3)
        {
            IO_printf("\nO primeiro caractere: %c e igual ao terceiro caractere: %c", caractere1, caractere2);
        }
        else
        {
            if ((caractere1 < caractere2 && caractere1 > caractere3) || (caractere1 < caractere3 && caractere1 > caractere2))
            {
                IO_printf("\nO primeiro caractere: %c esta entre os outros dois caracteres: %c, %c", caractere1, caractere2, caractere3);
            }
            else
            {
                IO_printf("\nO primeiro caractere: %c nao esta entre os outros dois caracteres: %c, %c", caractere1, caractere2, caractere3);
            }
        }
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}

void exemplo02E2()
{
    IO_clrscr();
    IO_printf("Entre com tres caracteres e descubra se o primeiro valor lido está fora do intervalo definido pelos outros dois, se esses forem diferentes entre si:");
    char caractere1 = IO_readchar("\ncaractere 1 = ");
    char caractere2 = IO_readchar("caractere 2 = ");
    char caractere3 = IO_readchar("caractere 3 = ");
    if ((caractere1 == caractere2) || (caractere1 == caractere3) || (caractere2 == caractere3))
    {
        IO_printf("\nalgum dos caracteres e igual entre si");
    }
    else
    {
        if ((caractere1 < caractere2 && caractere1 < caractere3) || (caractere1 > caractere2 && caractere1 > caractere3))
        {
            IO_printf("\nO primeiro caractere: %c esta fora do intervalo dos dois caracteres: %c, %c", caractere1, caractere2, caractere3);
        }
        else
        {
            IO_printf("\nO primeiro caractere: %c nao esta fora do intervalo dos dois caracteress: %c, %c", caractere1, caractere2, caractere3);
        }
    }
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
}