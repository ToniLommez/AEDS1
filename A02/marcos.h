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