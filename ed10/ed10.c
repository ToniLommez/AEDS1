/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 16/06/2022
 * 
 * A disposicao dos programas e bibliotecas aqui usados estao feitos da seguinte forma:
 * ed10.c           - Switch para escolha da questao
 * io.h             - Biblioteca IO original sem nenhuma alteracao
 * menuExercicios.h - Enunciado das questoes + construcao dos respectivos metodos
 * structs.h        - criacao das structs e metodos de controle das structs
 * 
 * --------------------------------------------------------------------------------------------------------
*/

#include "io.h"
#include "menuExercicios.h"


int opcoesMenu()
{
    IO_clrscr();
    IO_print("Escolha qual ed fazer digitando seu respectivo numero de 1 a 10\npara os exercicios extras: 11 e 12");
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
            exemplo1011();
            break;
        case 2:
            exemplo1012();
            break;
        case 3:
            exemplo1013();
            break;
        case 4:
            exemplo1014();
            break;
        case 5:
            exemplo1015();
            break;
        case 6:
            exemplo1016();
            break;
        case 7:
            exemplo1017();
            break;
        case 8:
            exemplo1018();
            break;
        case 9:
            exemplo1019();
            break;
        case 10:
            exemplo1020();
            break;
        case 11:
            exemplo10E1();
            break;
        case 12:
            exemplo10E2();
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
    IO_printf("\nSeja bem vindo ao meu exercicio ed10 de aed :)\n");
    IO_pause("\nAperte ENTER para comecar.");
    menu(opcoesMenu());
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}