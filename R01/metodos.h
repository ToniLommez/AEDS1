/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 
 * A disposicao dos exercicios esta feita da seguinte forma:
 * Primeiro sao os metodos que irao receber parametros e mostrar os resultados
 * Segundo sao as funcoes cujo qual dira o enunciado e chamara o metodo
 * 
 * Por fim e importante dizer que uso uma biblioteca propria chamada tipos.h que
 * retorna valores booleanos relacionados a caracteristicas da variavel, exemplo:
 * eMaiuscula, eMinuscula, eDigito, eLetra, eAlfanumerico, ePar
 * cujo quais recebem a variavel e retornam um valor booleano se sao ou nao aquilo que foi perguntado
 * --------------------------------------------------------------------------------------------------------
*/

#include "io.h"
#include "tipos.h"


double maiorEntreTres(double x, double y, double z) // retornar o maior numero entre tres valores
{
    if (x < y)
        x = y;
    if (x < z)
        x = z;
    return(x);
}
double menorEntreTres(double x, double y, double z) // retornar o menor numero entre tres valores
{
    if (x > y)
        x = y;
    if (x > z)
        x = z;
    return(x);
}
bool estaCrescente(int x, int y, int z) // retornar se a sequencia de tres valores esta crescente
{
    bool esta = true;
    if (x >= y)
        esta = false;
    if (y >= z)
        esta = false;
    return(esta);
}
bool estaDecrescente(int x, int y, int z) // retornar se a sequencia de tres valores esta decrescente
{
    bool esta = true;
    if (x <= y)
        esta = false;
    if (y <= z)
        esta = false;
    return(esta);
}
bool estaEmNenhuma(int x, int y, int z) // retornar se a sequencia de tres valores nao esta crescente e nem decrescente
{
    bool esta = true;
    if (estaCrescente(x, y, z))
        esta = false;
    else if (estaDecrescente(x, y, z))
        esta = false;
    return(esta);
}
bool estaCrescenteStr(char* x, char* y, char* z) // retornar se a sequencia de tres strings esta crescente
{
    bool esta = true;
    if (strcmp ( x, y ) >= 0)
        esta = false;
    if (strcmp ( y, z ) >= 0)
        esta = false;
    return(esta);
}
bool estaDecrescenteStr(char* x, char* y, char* z) // retornar se a sequencia de tres strings esta decrescente
{
    bool esta = true;
    if (strcmp ( x, y ) <= 0)
        esta = false;
    if (strcmp ( y, z ) <= 0)
        esta = false;
    return(esta);
}
void maiorEntreTresStr(char* x, char* y, char* z, char* maior) // armazenar em uma string a maior (alfabetica) entre tres strings
{
    strcpy(maior, x);
    if (strcmp ( maior, y ) <= 0)
        strcpy(maior, y);
    if (strcmp ( maior, z ) <= 0)
        strcpy(maior, z);
}
void menorEntreTresStr(char* x, char* y, char* z, char* menor) // armazenar em uma string a menor (alfabetica) entre tres strings
{
    strcpy(menor, x);
    if (strcmp ( menor, y ) >= 0)
        strcpy(menor, y);
    if (strcmp ( menor, z ) >= 0)
        strcpy(menor, z);
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler um valor inteiro (n) do teclado para indicar uma quantidade.
 * Ler outros tantos valores inteiros (x) do teclado, um por vez, ate atingir a quantidade.
 * Dizer para cada valor lido quais sao os seus divisores.
*/
void metodo1()
{
    int n = IO_readint("n -> ");
    int x[n];
    for (int i = 0; i < n; i++) // receber valores de x em i
    {
        x[i] = IO_readint("x -> ");
    }
    IO_printf("\nOs divisores sao:\n");
    for (int i = 0; i < n; i++) // i = endereco do valor armazenado
    {
        IO_printf("%d = ", x[i]);
        for (int y = 1; y <= x[i]/2; y++) // y = divisor a testar
        {
            if (x[i]%y==0)
            {
                IO_printf("%d ", y); 
            }
        }
        IO_printf("\n");
    }
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler um valor inteiro (n) do teclado para indicar uma quantidade.
 * Ler outros tantos valores inteiros (x) do teclado, um por vez, ate atingir a quantidade.
 * Dizer para cada valor lido e primo ou nao.
 *
 * Fiz uma pesquisa para entender se numeros negativos podem ser primos
 * segundo diversos graduados mas em especial: Waldeck Schutzer, Ph.D. Matemática & Álgebra, Universidade Rutgers (2004):
 *
 *"De maneira mais geral, em qualquer anel comutativo, um elemento p é primo se, ao dividir um produto arbitrário a⋅b,
 * p deve necessariamente dividir a ou b. Aplicada ao anel dos inteiros, esta definição é equivalente à que foi dada.
 * Veja, por exemplo, Prime element - Wikipedia ."
*/
void metodo2()
{
    int n = IO_readint("n -> ");
    int x[n];
    for (int i = 0; i < n; i++) // receber valores de x em i
    {
        x[i] = IO_readint("x -> ");
    }
    IO_printf("\n\n");
    for (int i = 0; i < n; i++) // i = endereco do valor armazenado
    {
        bool ePrimo = true;
        IO_printf("\n%d ", x[i]);
        if (x[i] < 0) // teste para primos negativos
        {
            for (int y = x[i]/2; y < -1; y++) // y = divisor a testar
            {
                if (x[i]%y==0)
                {
                    ePrimo = false;
                }
            }
        }
        else // teste para primos positivos
        {
            for (int y = x[i]/2; y > 1 ; y--) // y = divisor a testar
            {
                if (x[i]%y==0)
                {
                    ePrimo = false;
                }
            }
        }
        

        IO_printf("%s ", ePrimo ? "e primo" : "nao e primo");
    }
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler uma cadeia de caracteres do teclado.
 * Dizer se cada simbolo e um operador logico (&,|,!), aritmetico (+,-,*,/,%), relacional (>,<,=),
 * separadores (espaco, ponto, virgula, ponto-e-virgula, dois-pontos, sublinha)
 * ou outro simbolo qualquer.
 * 
 * E importante dizer que o metodo utiliza a biblioteca adicional tipos.h
*/
void metodo3()
{
    char a[80];
    IO_printf("-> ");
    gets(a);
    for (int i = 0; i < strlen(a); i++)
    {
        IO_printf("\n%c = ", a[i]);
        if (eLetra(a[i]))
        {
            IO_printf("e letra");
        }
        if (eDigito(a[i]))
        {
            IO_printf("e numero");
        }
        if (eLogico(a[i]))
        {
            IO_printf("e operador logico");
        }
        if (eAritmetico(a[i]))
        {
            IO_printf("e operador aritmetico");
        }
        if (eRelacional(a[i]))
        {
            IO_printf("e operador relacional");
        }
        if (eSeparador(a[i]))
        {
            IO_printf("e separador");
        }
        if (eSimbolo(a[i]))
        {
            IO_printf("e simbolo");
        }
    }
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler um cadeia de caracteres (s) do teclado.
 * Testar cada simbolo na cadeia, um por vez
 * e contar separadamente quantos desses sao letras maiusculas, minusculas, digitos e 
 * operadores (logicos, aritmeticos e relacionais) e separadores.
*/
void metodo4()
{
    int maiusculas = 0;
    int minusculas = 0;
    int digitos = 0;
    int operadores = 0;
    int separadores = 0;
    char a[80];
    IO_printf("-> ");
    gets(a);
    for (int i = 0; i < strlen(a); i++)
    {
        if (eMaiuscula(a[i]))
        {
            maiusculas++;
        }
        if (eMinuscula(a[i]))
        {
            minusculas++;
        }
        if (eDigito(a[i]))
        {
            digitos++;
        }
        if (eOperador(a[i]))
        {
            operadores++;
        }
        if (eSeparador(a[i]))
        {
            separadores++;
        }
    }
    IO_printf("\n");
    IO_printf("\nMaiusculas = %d", maiusculas);
    IO_printf("\nMinusculas = %d", minusculas);
    IO_printf("\nDigitos = %d", digitos);
    IO_printf("\nOperadores = %d", operadores);
    IO_printf("\nSeparadores = %d", separadores);
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler um valor inteiro (n) do teclado.
 * Ler outros (n) valores reais (x) do teclado, um por vez.
 * Calcular e mostrar a media dos valores menores que -23.75,
 * a media dos que estao entre -23.75 e 65.25, inclusive esses,
 * e a media dos maiores que 65.25. Dizer qual a maior media de todas.
*/
void metodo5()
{
    int n = IO_readint("n -> ");
    double x[n];
    int menores = 0;
    double total1 = 0;
    int entre = 0;
    double total2 = 0;
    int maiores = 0;
    double total3 = 0;
    double resultado1 = 0;
    double resultado2 = 0;
    double resultado3 = 0;
    for (int i = 0; i < n; i++) // receber valores de x em i
    {
        x[i] = IO_readdouble("x -> ");
        if (x[i] < -23.75)
        {
            menores++;
            total1 += x[i];
        }
        if (x[i] >= -23.75 && x[i] <= 65.25)
        {
            entre++;
            total2 += x[i];
        }
        if (x[i] > 65.25)
        {
            maiores++;
            total3 += x[i];
        }
    }
    if (total1 != 0)
        resultado1 = total1 / menores;
    if (total2 != 0)
        resultado2 = total2 / entre;
    if (total3 != 0)
        resultado3 = total3 / maiores;
    IO_printf("\n\nMedia dos menores que -23.75   = %lf", resultado1);
    IO_printf("\nMedia dos entre -23.75 e 65.25 = %lf", resultado2);
    IO_printf("\nMedia dos maiores que 65.25    = %lf", resultado3);
    IO_printf("\n\nA maior entre as tres medias e = %lf", maiorEntreTres(resultado1, resultado2, resultado3));
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler dois valores inteiros (a) e (b) do teclado,
 * Ler outros valores inteiros do teclado, um por vez, ate que o ultimo valor seja igual a (-1)
 * Para cada valor lido que estiver no intervalo aberto ]a:b[
 * calcular e mostrar a soma dos cubos dos inversos (1/x3) dos impares.
*/
void metodo6()
{
    int a;
    int b;
    int x;
    double fracao=0.0;
    double resultado=0.0;

    do{
        a = IO_readint("a -> ");
        b = IO_readint("b -> ");
        if (a>=b){
            IO_pause("\nValores incompativeis, aperte ENTER para refazer");
        }
    }while (a>=b);
    while (x != -1)
    {
        x = IO_readint("x -> ");
        if (!(ePar(x)) && (a<x && x<b))
        {
            fracao=1/pow(x, 3);
            resultado+=fracao;
        }
    }
    IO_printf("\n\nResultado da soma das fracoes: %lf", resultado);
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler dois valores reais (a) e (b) do teclado
 * Ler outros valores reais do teclado, um por vez ate que o ultimo valor seja igual a zero, e nao considerá-lo para os cálculos.
 * Contar quantos desses valores estao dentro ou fora do intervalo definido pelo intervalo aberto ]a:b[.
 * Para os valores fora do intervalo, calcular separadamente as porcentagens dos que estiverem acima e abaixo do intervalo, nessa ordem.
*/
void metodo7()
{
    double a;
    double b;
    double x = 1;
    int acima = 0;
    int abaixo = 0;
    int icount = -1;
    do{
        a = IO_readdouble("a -> ");
        b = IO_readdouble("b -> ");
        if (a>=b){
            IO_pause("\nValores incompativeis, aperte ENTER para refazer");
        }
    }while (a>=b);
    while (x != 0)
    {
        x = IO_readdouble("x -> ");
        icount++;
        if (x != 0 && (x<=a) )
        {
            abaixo++;
        }
        else if (x != 0 && (x>=b) )
        {
            acima++;
        }
    }
    IO_printf("\n\nNumeros acima: %.1f%%", ((float)acima / icount) * 100);
    IO_printf("\n\nNumeros abaixo: %.1f%%", ((float)abaixo / icount) * 100);
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler tres valores reais (x,y,z) do teclado, um por vez.
 * Dizer se esses valores estao em ordem crescente decrescente ou em nenhuma dessas ordens e, nesse caso, o menor e o maior.
*/
void metodo8()
{
    int x = IO_readint("x -> ");
    int y = IO_readint("y -> ");
    int z = IO_readint("z -> ");
    if (estaCrescente(x, y, z))
        IO_printf("\nEsta crescente");
    else if (estaDecrescente(x, y, z))
        IO_printf("\nEsta decrescente");
    else
        IO_printf("\nNao esta crescente e nem decrescente\nO maior e: %d\nO menor e: %d", (int)maiorEntreTres(x, y, z), (int)menorEntreTres(x, y, z));
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler tres caracteres (x,y,z) do teclado, um por vez
 * Dizer se esses valores estao em ordem crescente decrescente ou em nenhuma dessas ordens.
*/
void metodo9()
{
    char x = IO_readchar("x -> ");
    char y = IO_readchar("y -> ");
    char z = IO_readchar("z -> ");
    if (estaCrescente(x, y, z))
        IO_printf("\nEsta crescente");
    else if (estaDecrescente(x, y, z))
        IO_printf("\nEsta decrescente");
    else if (estaEmNenhuma(x, y, z))
        IO_printf("\nNao esta crescente e nem decrescente");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * Ler tres cadeias de caracteres (x,y,z) do teclado, uma por vez.
 * Dizer se essas cadeias estao em ordem alfabetica crescente,
 * decrescente ou em nenhuma dessas ordens e, nesse caso, a menor e a maior.
*/
void metodo10()
{
    char x[80], y[80], z[80], maior[80], menor[80];
    strcpy(x, IO_readln("x -> "));
    strcpy(y, IO_readln("y -> "));
    strcpy(z, IO_readln("z -> "));
    maiorEntreTresStr(x, y, z, maior);
    menorEntreTresStr(x, y, z, menor);
    if (estaCrescenteStr(x, y, z)) {IO_printf("\nEsta crescente");}
    else if (estaDecrescenteStr(x, y, z)) {IO_printf("\nEsta decrescente");}
    else {IO_printf("\nNao esta crescente e nem decrescente\nO maior e: %s\nO menor e: %s", maior, menor);}
}



/*
 * ---------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 
 * Lista dos exercicios que fara:
 * 1 - A apresentacao do enunciado da questao
 * 2 - Chamar o respectivo Metodo
 * ---------------------------------------------------------
*/
void exercicio1()
{
    IO_clrscr();
    IO_printf("Exercicio 1");
    IO_printf("\nLer um valor inteiro (n) do teclado para indicar uma quantidade.");
    IO_printf("\nLer outros tantos valores inteiros (x) do teclado, um por vez, ate atingir a quantidade.");
    IO_printf("\nDizer para cada valor lido quais sao os seus divisores.");
    IO_printf("\n\n");
    metodo1();
}
void exercicio2()
{
    IO_clrscr();
    IO_printf("Exercicio 2");
    IO_printf("\nLer um valor inteiro (n) do teclado para indicar uma quantidade.");
    IO_printf("\nLer outros tantos valores inteiros (x) do teclado, um por vez, ate atingir a quantidade.");
    IO_printf("\nDizer para cada valor lido e primo ou nao.");
    IO_printf("\n\n");
    metodo2();
}
void exercicio3()
{
    IO_clrscr();
    IO_printf("Exercicio 3");
    IO_printf("\nLer uma cadeia de caracteres do teclado.");
    IO_printf("\nDizer se cada simbolo e um operador logico (&,|,!), aritmetico (+,-,*,/,%c), relacional (>,<,=),", 37);
    IO_printf("\nseparadores (espaco, ponto, virgula, ponto-e-virgula, dois-pontos, sublinha)");
    IO_printf("\nou outro simbolo qualquer.");
    IO_printf("\n\n");
    metodo3();
}
void exercicio4()
{
    IO_clrscr();
    IO_printf("Exercicio 4");
    IO_printf("\nLer um cadeia de caracteres (s) do teclado.");
    IO_printf("\nTestar cada simbolo na cadeia, um por vez");
    IO_printf("\ne contar separadamente quantos desses sao letras maiusculas, minusculas, digitos e ");
    IO_printf("\noperadores (logicos, aritmeticos e relacionais) e separadores.");
    IO_printf("\n\n");
    metodo4();
}
void exercicio5()
{
    IO_clrscr();
    IO_printf("Exercicio 5");
    IO_printf("\nLer um valor inteiro (n) do teclado.");
    IO_printf("\nLer outros (n) valores reais (x) do teclado, um por vez.");
    IO_printf("\nCalcular e mostrar a media dos valores menores que -23.75,");
    IO_printf("\na media dos que estao entre -23.75 e 65.25, inclusive esses,");
    IO_printf("\ne a media dos maiores que 65.25. Dizer qual a maior media de todas.");
    IO_printf("\n\n");
    metodo5();
}
void exercicio6()
{
    IO_clrscr();
    IO_printf("Exercicio 6");
    IO_printf("\nLer dois valores inteiros (a) e (b) do teclado,");
    IO_printf("\nLer outros valores inteiros do teclado, um por vez, ate que o ultimo valor seja igual a (-1)");
    IO_printf("\nPara cada valor lido que estiver no intervalo aberto ]a:b[");
    IO_printf("\ncalcular e mostrar a soma dos cubos dos inversos (1/x3) dos impares.");
    IO_printf("\n\n");
    metodo6();
}
void exercicio7()
{
    IO_clrscr();
    IO_printf("Exercicio 7");
    IO_printf("\nLer dois valores reais (a) e (b) do teclado");
    IO_printf("\nLer outros valores reais do teclado, um por vez ate que o ultimo valor seja igual a zero, e nao considerá-lo para os cálculos.");
    IO_printf("\nContar quantos desses valores estao dentro ou fora do intervalo definido pelo intervalo aberto ]a:b[.");
    IO_printf("\nPara os valores fora do intervalo, calcular separadamente as porcentagens dos que estiverem acima e abaixo do intervalo, nessa ordem.");
    IO_printf("\n\n");
    metodo7();
}
void exercicio8()
{
    IO_clrscr();
    IO_printf("Exercicio 8");
    IO_printf("\nLer tres valores reais (x,y,z) do teclado, um por vez.");
    IO_printf("\nDizer se esses valores estao em ordem crescente decrescente ou em nenhuma dessas ordens e, nesse caso, o menor e o maior.");
    IO_printf("\n\n");
    metodo8();
}
void exercicio9()
{
    IO_clrscr();
    IO_printf("Exercicio 9");
    IO_printf("\nLer tres caracteres (x,y,z) do teclado, um por vez");
    IO_printf("\nDizer se esses valores estao em ordem crescente decrescente ou em nenhuma dessas ordens.");
    IO_printf("\n\n");
    metodo9();
}
void exercicio10()
{
    IO_clrscr();
    IO_printf("Exercicio 10");
    IO_printf("\nLer tres cadeias de caracteres (x,y,z) do teclado, uma por vez.");
    IO_printf("\nDizer se essas cadeias estao em ordem alfabetica crescente,");
    IO_printf("\ndecrescente ou em nenhuma dessas ordens e, nesse caso, a menor e a maior.");
    IO_printf("\n\n");
    metodo10();
}


/* Exercicio 1:
 * 
 * n -> 5
 * x -> 22
 * x -> 121
 * x -> 440
 * x -> 581
 * x -> 814
 * 
 * Os divisores sao:
 * 22 = 1 2 11 
 * 121 = 1 11 
 * 440 = 1 2 4 5 8 10 11 20 22 40 44 55 88 110 220 
 * 581 = 1 7 83 
 * 814 = 1 2 11 22 37 74 407 
*/

/* Exercicio 2:
 * 
 * n -> 5
 * x -> -293
 * x -> -107
 * x -> 153
 * x -> 199
 * x -> 811
 * 
 * 
 * 
 * -293 e primo 
 * -107 e primo 
 * 153 nao e primo 
 * 199 e primo 
 * 811 e primo 
*/

/* Exercicio 3:
 * -> &+>.☺a
 * 
 * & = e operador logico
 * + = e operador aritmetico
 * > = e operador relacional
 * . = e separador
 * ☺ = e simbolo
 * a = e letra
*/

/* Exercicio 4:
 * 
 * 
 * -> for(X=0;X<y&&y>=0;X=X+1)
 * 
 * 
 * Maiusculas = 4
 * Minusculas = 5
 * Digitos = 3
 * Operadores = 8
 * Separadores = 2
*/

/* Exercicio 5:
 * n -> 10
 * x -> -15.25 -12.50 0.0 6.75 20.50 50.0 70.25 85.25 92.50 98.75            
 * x -> x -> x -> x -> x -> x -> x -> x -> x -> 
 * 
 * Media dos menores que -23.75   = 0.000000
 * Media dos entre -23.75 e 65.25 = 8.250000
 * Media dos maiores que 65.25    = 86.687500
 * 
 * A maior entre as tres medias e = 86.687500
*/

/* Exercicio 6:
 * a -> 20
 * b -> 60
 * x -> -20 -11 0 1 10 21 36 51 70 80 -1
 * x -> x -> x -> x -> x -> x -> x -> x -> x -> x -> 
 * 
 * Resultado da soma das fracoes: 0.000116
*/

/* Exercicio 7:
 * a -> 20
 * b -> 60
 * x -> 20 -10 1 10 20 30 60 70 80 0           
 * x -> x -> x -> x -> x -> x -> x -> x -> x -> 
 * 
 * Numeros acima: 33.3%
 * 
 * Numeros abaixo: 55.6%
*/

/* Exercicio 8:
 * x -> 10
 * y -> 20
 * z -> 30
 * 
 * Esta crescente
 *  
 * 
 * x -> 30
 * y -> 20
 * z -> 10
 * 
 * Esta decrescente
 * 
 * 
 * x -> 10
 * y -> 10
 * z -> 10
 * 
 * Nao esta crescente e nem decrescente
 * O maior e: 10
 * O menor e: 10
*/

/* Exercicio 9:
 * x -> c
 * y -> b
 * z -> a
 * 
 * Esta decrescente
 * 
*/

/* Exercicio 10:
 * 
 * x -> 123
 * y -> ASD
 * z -> asd
 * 
 * Esta crescente
 * 
 * 
 * x -> asd
 * y -> ASD
 * z -> 123
 * 
 * Esta decrescente
 * 
 * 
 * x -> asd
 * y -> 123
 * z -> ASD
 * 
 * Nao esta crescente e nem decrescente
 * O maior e: asd
 * O menor e: 123
*/