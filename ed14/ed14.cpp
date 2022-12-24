/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 24/06/2022
 * 
 * A disposicao dos programas e bibliotecas aqui usados estao feitos da seguinte forma:
 * ed14.cpp           - Switch para escolha da questao
 * io.hpp             - Biblioteca IO original sem nenhuma alteracao
 * menuExercicios.hpp - Enunciado das questoes + construcao dos respectivos metodos
 * 
 * --------------------------------------------------------------------------------------------------------
*/

#include "menuExercicios.hpp"

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
            exemplo1411();
            break;
        case 2:
            exemplo1412();
            break;
        case 3:
            exemplo1413();
            break;
        case 4:
            exemplo1414();
            break;
        case 5:
            exemplo1415();
            break;
        case 6:
            exemplo1416();
            break;
        case 7:
            exemplo1417();
            break;
        case 8:
            exemplo1418();
            break;
        case 9:
            exemplo1419();
            break;
        case 10:
            exemplo1420();
            break;
        case 11:
            exemplo14E1();
            break;
        case 12:
            exemplo14E2();
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
    std::cout<<"\nSeja bem vindo ao meu exercicio ed14 de aed :)\n";
    IO_pause("\nAperte ENTER para comecar.");
    menu(opcoesMenu());
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}