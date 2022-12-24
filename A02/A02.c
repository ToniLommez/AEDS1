/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 17/06/2022
 * 
 * A disposicao dos programas e bibliotecas aqui usados estao feitos da seguinte forma:
 * R02.c            - Intro + Menu para escolha da questao
 * io.h             - Biblioteca IO original sem nenhuma alteracao
 * metodos.h        - Enunciado das questoes + construcao dos respectivos metodos
 * structs.h        - Criacao das structs e metodos de controle das structs
 * marcos.h         - Biblioteca pessoal
 * 
 * --------------------------------------------------------------------------------------------------------
*/

#include "io.h"
#include "metodos.h"
#include <stdio.h>


int opcoesMenu()
{
    IO_clrscr();
    IO_print("Escolha qual procedimento deseja fazer digitando seu respectivo numero de 1 a 10\n");
    IO_print("\n0 - sair");
    return (IO_readint("\n\nQual procedimento deseja realizar?\n> "));
}

int menu(int opcao)
{
    switch (opcao)
    {
        case 0:
            return(0);
        case 1:
            exercicio1();
            break;
        case 2:
            exercicio2();
            break;
        case 3:
            exercicio3();
            break;
        case 4:
            exercicio4();
            break;
        case 5:
            exercicio5();
            break;
        case 6:
            exercicio6();
            break;
        case 7:
            exercicio7();
            break;
        case 8:
            exercicio8();
            break;
        case 9:
            exercicio9();
            break;
        case 10:
            exercicio10();
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
    IO_printf("\nSeja bem vindo a minha Lista de Exercicios para Recuperacao 02 :)\n");
    IO_pause("\nAperte ENTER para comecar.");
    menu(opcoesMenu());
    IO_pause("\nAperte ENTER para terminar.");
    IO_clrscr();
    return (0);
}