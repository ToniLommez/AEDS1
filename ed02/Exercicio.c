#include "io.h"
#include "menuExercicios.h"
#include <stdio.h>

int opcoesMenu()
{
    IO_clrscr();
    IO_print("\nEscolha qual ed fazer:\n");
    IO_print("\n1  - par ou impar");
    IO_print("\n2  - par e maior que -30 ou impar e menor que 30");
    IO_print("\n3  - pertence ao intervalo aberto entre (25:40)");
    IO_print("\n4  - pertence ao intervalo fechado entre [15:45]");
    IO_print("\n5  - pertence aos intervalos fechados [10:25] ou [20:40], ou a apenas a um deles");
    IO_print("\n6  - o primeiro e impar e o segundo e par");
    IO_print("\n7  - o primeiro e par e negativo, e se o segundo e impar e positivo");
    IO_print("\n8  - o segundo e igual, maior ou menor ao primeiro");
    IO_print("\n9  - o primeiro esta entre os outros dois quando esses forem diferentes entre si");
    IO_print("\n10 - o primeiro nao esta entre os outros dois, quando todos forem diferentes entre si");
    IO_print("\n11 - o primeiro valor lido esta entre os outros dois, ou se e igual a um deles");
    IO_print("\n12 - o primeiro valor lido esta fora do intervalo definido pelos outros dois, se esses forem diferentes entre si");
    IO_print("\n13 - sair");
    return (IO_readint("\n\nQual operacao deseja realizar?\n> "));
}

int menu(int opcao)
{
    switch (opcao)
    {
        case 1:
            exemplo0211();
            break;
        case 2:
            exemplo0212();
            break;
        case 3:
            exemplo0213();
            break;
        case 4:
            exemplo0214();
            break;
        case 5:
            exemplo0215();
            break;
        case 6:
            exemplo0216();
            break;
        case 7:
            exemplo0217();
            break;
        case 8:
            exemplo0218();
            break;
        case 9:
            exemplo0219();
            break;
        case 10:
            exemplo0220();
            break;
        case 11:
            exemplo02E1();
            break;
        case 12:
            exemplo02E2();
            break;
        case 13:
            return(0);
        default:
            IO_print("\nValor invalido!!!");
            IO_pause("\nAperte ENTER para recomecar.");
            break;
    } // fim escolher
    menu(opcoesMenu());
}

int main()
{
    IO_clrscr();
    int opcao = 0;
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("\nSeja bem vindo ao meu exercicio ed02 de aed :)\n");
    IO_pause("\nAperte ENTER para comecar.");
    menu(opcoesMenu());
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}