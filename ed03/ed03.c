#include "io.h"
#include "menuExercicios.h"
#include <stdio.h>

int opcoesMenu()
{
    IO_clrscr();
    IO_print("\nEscolha qual ed fazer digitando seu respectivo numero de 1 a 10\npara os exercicios extras: 11 e 12");
    IO_print("\n0 - sair");
    return (IO_readint("\n\nQual operacao deseja realizar?\n> "));
}

int menu(int opcao)
{
    switch (opcao)
    {
        case 0:
            return(0);
        case 1:
            exemplo0311();
            break;
        case 2:
            exemplo0312();
            break;
        case 3:
            exemplo0313();
            break;
        case 4:
            exemplo0314();
            break;
        case 5:
            exemplo0315();
            break;
        case 6:
            exemplo0316();
            break;
        case 7:
            exemplo0317();
            break;
        case 8:
            exemplo0318();
            break;
        case 9:
            exemplo0319();
            break;
        case 10:
            exemplo0320();
            break;
        case 11:
            exemplo03E1();
            break;
        case 12:
            exemplo03E2();
            break;
        default:
            IO_print("\nValor invalido!!!");
            IO_pause("\nAperte ENTER para recomecar.");
            menu(opcoesMenu());
            return(0);
    } // fim escolher
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
    menu(opcoesMenu());
}

int main()
{
    IO_clrscr();
    int opcao = 0;
    IO_printf("%s\n", "Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro");
    IO_printf("\nSeja bem vindo ao meu exercicio ed03 de aed :)\n");
    IO_pause("\nAperte ENTER para comecar.");
    menu(opcoesMenu());
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}