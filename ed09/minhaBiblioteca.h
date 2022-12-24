#include "io.h"
#include <sys/stat.h>
#include <stdio.h>     // para entradas e saidas
#include <stddef.h>    // para definicoes basicas
#include <stdlib.h>    // para a biblioteca padrao
#include <string.h>    // para cadeias de caracteres
#include <stdarg.h>    // para tratar argumentos
#include <stdbool.h>   // para definicoes logicas
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo
#include <wchar.h>     // para 16-bit characters

const int MAX_SIZE = 100;

bool eMaiuscula(char x)           { return (x >= 'A' && x <= 'Z'); }
bool eMinuscula(char x)           { return (x >= 'a' && x <= 'z'); }
bool eDigito(char x)              { return (x >= '0' && x <= '9'); }
bool eLetra(char x)               { return (eMaiuscula(x) || eMinuscula(x)); }
bool eAlfanumerico(char x)        { return (eLetra(x) || eDigito(x)); }
bool ePar(double x)               { return ((int)x%2==0); }
bool eLogico(char x)              { return (x == '&' || x == '|' || x == '!'); }
bool eAritmetico(char x)          { return (x == '+' || x == '-' || x == '*' || x == '/' || x == '%'); }
bool eRelacional(char x)          { return (x == '>' || x == '<' || x == '='); }
bool eSeparador(char x)           { return (x == ' ' || x == '.' || x == ',' || x == ';' || x == ':' || x == '_'); }
bool eOperador(char x)            { return (eLogico(x) || eAritmetico(x) || eRelacional(x)); }
bool eSimbolo(char x)             { return (!(eOperador(x) || eSeparador(x) || eAlfanumerico(x))); }


int readMatrixFlines (char* filename){
    int n;
    FILE *ptr = fopen (filename, "r");
    fscanf(ptr, "%d", &n);
    fclose(ptr);
    return n;
}

int readMatrixFcolumns (char* filename){
    int n;
    FILE *ptr = fopen (filename, "r");
    fscanf(ptr, "%d", &n);
    fscanf(ptr, "%d", &n);
    fclose(ptr);
    return n;
}

void intBuildMatrix (int option, int lines, int columns, int matrix[][columns]){
    int total=columns*lines;
    int posicao=0;
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++){
            switch (option){
                case 1: 
                    matrix[i][j]=posicao;
                    posicao++; 
                    break;
                case 2:
                    matrix[i][j]=total;
                    total--; 
                    break;
                case 3: matrix[i][j]=rand(); break;
                default: matrix[i][j]=0; break;
            }
        }
	}
}

void doubleBuildMatrix (int option, int lines, int columns, double matrix[][columns]){
    int total=columns*lines;
    int posicao=0;
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++){
            switch (option){
                case 1: 
                    matrix[i][j]=posicao;
                    posicao++; 
                    break;
                case 2:
                    matrix[i][j]=total;
                    total--; 
                    break;
                case 3: matrix[i][j]=rand()/4.654; break;
                case 88:
                    matrix[j][i]=total;
                    total--; 
                    break;
                default: matrix[i][j]=0; break;
            }
        }
	}
}

void doubleReadMatrix(int x, int y, double matrix[][y]){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            IO_printf("[%d][%d] ", i, j);
            matrix[i][j] = IO_readdouble(("->"));
            while (matrix[i][j] < 0){
                IO_printf("Valor invalido, insira novamente!\n[%d][%d] ", i, j);
                matrix[i][j] = IO_readdouble(("->"));
            }
        }
    }
}

void doublePrintMatrix (int lines, int columns ,double matrix[][columns]){
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++)
            printf("\n[%d][%d]: %.2f", i, j, matrix[i][j]);
    }
}

void doubleFprintfMatrix (char filename[], int lines, int columns, double matrix[][columns]){
    if (strlen(filename)<=0){
        printf("\nERRO: Nome de arquivo invalido. \n");
    }else{
        FILE *arquivo = fopen (filename, "w");
        
        fprintf(arquivo, "%d\n", lines);
        fprintf(arquivo, "%d\n", columns);
        for (int i=0; i<lines; i++){
            for (int j=0; j<columns; j++){
                fprintf(arquivo, "%lf\n", matrix[i][j]);
            }
        }
        fclose(arquivo);
    }
    printf ("\nNumeros foram gravados no arquivo \"%s\"\n", filename);
}

void doubleFscanfMatrix (char filename[], int lines, int columns, double matrix[][columns]){
    int n=0;
    FILE *arquivo = fopen (filename, "r");

    fscanf(arquivo, "%d", &n);
    if (lines>=n){
        fscanf(arquivo, "%d", &n);
        if (columns>=n){
            for (int i=0; (!feof(arquivo) && i<lines) ; i++){
                for (int j=0; (!feof(arquivo) && j<columns) ; j++){
                    fscanf(arquivo, "%lf", &matrix[i][j]);
                }
            }
        }
    }
    fclose(arquivo);
}

void intFscanfMatrix (char filename[], int lines, int columns, int matrix[][columns]){
    int n=0;
    FILE *arquivo = fopen (filename, "r");
    IO_printf("\n%s", filename);
    fscanf(arquivo, "%d", &n);
    if (lines>=n){
        fscanf(arquivo, "%d", &n);
        if (columns>=n){
            for (int i=0; (!feof(arquivo) && i<lines) ; i++){
                for (int j=0; (!feof(arquivo) && j<columns) ; j++)
                    fscanf(arquivo, "%d", &matrix[i][j]);
            }
        }
    }
    fclose(arquivo);
}

void intPrintMatrix (int lines, int columns ,int matrix[][columns]){
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++)
            printf("\n[%d][%d]: %d", i, j, matrix[i][j]);
    }
}

void intFprintfMatrix (char filename[], int lines, int columns, int matrix[][columns]){
    FILE *arquivo=NULL;

    if (strlen(filename)<=0){
        printf("\nERRO: Nome de arquivo invalido. \n");
    }else{
        FILE *arquivo = fopen (filename, "w");
        
        fprintf(arquivo, "%d\n", lines);
        fprintf(arquivo, "%d\n", columns);
        for (int i=0; i<lines; i++){
            for (int j=0; j<columns; j++){
                fprintf(arquivo, "%d\n", matrix[i][j]);
            }
        }
        fclose(arquivo);
    }
}



void intScanMatrix (int lines, int columns, int matrix[][columns]){
	for(int i=0; i<lines; i++){
        for(int j=0; j<lines; j++){
            printf("matrix[%d][%d]: ", i, j);
            scanf ("%d", &matrix[i][j]);
            getchar();
        }
	}
}