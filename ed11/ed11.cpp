#include "menuExercicios.hpp"

// Marcos Antonio Lommez Candido Ribeiro
// 771157
// 05/06/2022

int opcoesMenu()
{
    IO_clrscr();
    std::cout<<"Escolha qual ed fazer digitando seu respectivo numero de 1 a 10\npara os exercicios extras: 11 e 12";
    std::cout<<"\n0 - sair";
    return (IO_readint("\n\nQual operacao deseja realizar?\n> "));
}
int menu(int opcao)
{
    switch (opcao)
    {
        case 0:
            return(0);
        case 1:
            exemplo1111();
            break;
        case 2:
            exemplo1112();
            break;
        case 3:
            exemplo1113();
            break;
        case 4:
            exemplo1114();
            break;
        case 5:
            exemplo1115();
            break;
        case 6:
            exemplo1116();
            break;
        case 7:
            exemplo1117();
            break;
        case 8:
            exemplo1118();
            break;
        case 9:
            exemplo1119();
            break;
        case 10:
            exemplo1120();
            break;
        case 11:
            exemplo11E1();
            break;
        case 12:
            exemplo11E2();
            break;
        default:
            std::cout<<"\nValor invalido!!!";
            IO_pause("\nAperte ENTER para recomecar.");
            menu(opcoesMenu());
            return(0);
    } // fim escolher
    IO_pause("\nAperte ENTER para voltar.");
    IO_clrscr();
    menu(opcoesMenu());
    return(0);
}

int main()
{
    IO_clrscr();
    int opcao = 0;
    std::cout<<"Autor: 771157 - Marcos Antonio Lommez Candido Ribeiro";
    std::cout<<"\nSeja bem vindo ao meu exercicio ed11 de aed :)\n";
    IO_pause("\nAperte ENTER para comecar.");
    menu(opcoesMenu());
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}