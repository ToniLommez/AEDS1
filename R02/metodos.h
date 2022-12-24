/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 
 * A disposicao dos exercicios esta feita da seguinte forma:
 * Primeiro sao os metodos que irao receber parametros e mostrar os resultados
 * Segundo sao as funcoes cujo qual dira o enunciado e chamara o metodo
 * --------------------------------------------------------------------------------------------------------
*/

#include "io.h"


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 01:
*/
void metodo1()
{
    printf("method_01:\n\n");

    int array [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 0, y = 0, z = 0;
    for (x = 3; x < 7; x = x + 1)
    {   z = array [x];
        for (y = x; y < 10; y = y + 1)
        {   array [y] = array[y+1];   }
        array [y-1] = z;
    }
    for (x = 0; x < 10; x = x + 1)
    {   printf("%d ", array [x]);  }
    printf("\n");   

    printf("\n\nLogo a resposta correta do exercicio e:\n");
    printf("\n\nQual a saida esperada?");
    printf("\na.) 0 1 2 4 6 8 3 5 7 9");
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 02:
*/
void metodo2()
{
    printf("method_02:\n\n");

    int array[][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
    int x = 0, y = 0, z = 0;
    for ( x = 0; x < 3; x = x + 1)
    {  z = array [2-x][2-x];
       for ( y = 2; y>=0; y = y - 1)
       {  array[y][x] = array [x][y];
          if ( x == y) { array [x][y] = z; } }  }
    for ( x = 0; x < 3; x = x + 1)
    {  for ( y = 0; y < 3; y = y + 1)
       {  printf ("%d\t", array [x][y] ); }
       printf ("\n");                           }

    printf("\n\nLogo a resposta correta do exercicio e:\n");
    printf("\n\nQual a saida equivalente?");
    printf("\nc.) { {8, 1, 2}, {1, 4, 5}, {2, 5, 8} }");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 03:
*/
char* substring(int start, int end, char *source){
    char *destiny = NULL;
    int x= 0, y = 0;
    destiny = malloc( strlen(source)*sizeof(char));
    destiny[y] = '\0';
    for (x = start; x < end; x++)
    { destiny [y] = source[x]; y++; }
    return (destiny);    
}
void metodo3()
{
    printf("substring:\n\n");

    printf(substring(1, 4, "abcde"));
    printf("\n");
    printf(substring(4, 6, "abcde"));
    printf("\n");
    printf(substring(0, 3, "abcde"));
    printf("\n");
    printf(substring(3, 5, "abcde"));
    printf("\n");

    printf("\n\nLogo a resposta correta do exercicio e:\n");
    printf("\n\nQual chamada tera resultado CORRETO?");
    printf("\nb.) \"e\"     = substring(4,6,\"abcde\")");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 04:
*/
int f04 ( int x, char *s )
{
    int result = 0;
    if ( 0<=x && x<strlen(s) )
    { result = (s[x]== '0' || s[x]=='1') && f04 (x+1, s); }
    else
    { result = 1; }
    return ( result );
}
void metodo4()
{
    printf("f04:\n\n");

    printf("%d", f04(3, "01lO"));
    printf("\n");
    printf("%d", f04(2, "0l10"));
    printf("\n");
    printf("%d", f04(1, "O101"));
    printf("\n");
    printf("%d", f04(0, "0101"));
    printf("\n");

    printf("\n\nLogo a resposta correta do exercicio e:\n");
    printf("\n\nQual chamada tera resultado FALSO(0)");
    printf("\na.) f04 (3, \"01lO\")");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 05:
*/
int f05 (char *s1, char *s2 )
{
    int result = 0;
    int x = 0, y = 0, z = 0;
    for ( x = 0; x < strlen(s1); x = x + 1)
    {  for ( y = 1; y < strlen(s2); y = y + 1 )
       { if ( s1 [x] == s2 [y] ) { z=z+1; y=strlen(s2); }
       }
    }
    result = (z == strlen(s1) );
    return ( result );
}
void metodo5()
{
    printf("f05:\n\n");

    printf("%d", f05("alice", "celia"));
    printf("\n");
    printf("%d", f05("aroma", "amora"));
    printf("\n");
    printf("%d", f05("pato", "apto"));
    printf("\n");
    printf("%d", f05("alegria", "galeria"));
    printf("\n");

    printf("\n\nLogo a resposta correta do exercicio e:\n");
    printf("\n\nQual chamada tera resultado VERDADEIRO(1)");
    printf("\nb.)f05 (\"aroma\", \"amora\")");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 06:
*/
struct s_ac {int a; char c;};
void metodo6()
{
    printf("method_06:\n\n");

    struct s_ac s[5]; int x = 0, y = 0;
    for ( x=0; x<5; x=x+1 )
    { s[x].a=x; s[x].c=(char)('A'+x); }
    while(x>0)
    { y=5;
      while(y>0)
      { if (x-1==s[y-1].a)
        { printf ("%d%c", s[y-1].a, s[y-1].c ); y=0; }
        y = y-2; }
      x=x-1;     }

    printf("\n");
    printf("\n\nLogo a resposta correta do exercicio e:\n");
    printf("\n\nQual a saida esperada?");
    printf("\nc.) 4E2C0A");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 07:
*/
int f07 ( char *s )
{
    int achar = 0;  int x = 0, y = 0, z = 0;
    for ( x = 0; x < strlen(s); x = x + 1 )
    { if ( s[x] == '-' )
      { if ( 0<=x && x<strlen(s) &&
        ((s[x-1] == s[x+1] && s[x+1] == 'r') ||
         (s[x-1] == 'i')) )
          achar = 1;      }
    }
    return ( achar );
}
void metodo7()
{
    printf("f07:\n\n");

    printf("%d", f07("anti-horario"));
    printf("\n");
    printf("%d", f07("inter-relacao"));
    printf("\n");
    printf("%d", f07("super-homem"));
    printf("\n");
    printf("%d", f07("anti-inflamatorio"));
    printf("\n");

    printf("\n\nLogo a resposta correta do exercicio e:\n");
    printf("\n\nQual a saida tera resultado FALSO(0)");
    printf("\nc.)f07 (\"super-homem\")");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 08:
 * Fazer um procedimento para receber o nome de um arquivo e,
 * se esse tiver uma quantidade impar de dados reais,
 * acrescentar a media aritmetica entre o primeiro,
 * o que estiver no meio e o ultimo dado.
*/
void questao8 (char *filename) {
    FILE *arquivo = fopen(filename, "r");
    int quant = 0;
    double temp;
    for (; !feof(arquivo); quant++){
        fscanf(arquivo, "%lf", &temp);
    }
    fclose(arquivo);
    if (!(quant%2==0))
    {
        FILE *arquivo2 = fopen(filename, "r");
        double array[quant];
        for (int j = 0; !feof(arquivo2) || j < quant; j++)
        {
            fscanf(arquivo2, "%lf", &array[j]);
        }
        double inicio = array[0];
        double meio = array[(quant/2)];
        double fim = array[quant-1];
        double media = (inicio+meio+fim)/3.0;
        fclose(arquivo2);
        FILE *arquivo3 = fopen(filename, "a");
        fprintf(arquivo3, "\n%lf", media);
        fclose(arquivo3);
    }
}
void metodo8()
{
    questao8("arquivo.txt");
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 09:
 * Fazer uma funcao para receber uma matriz (inteira) e suas dimensoes,
 * e retornar a razao entre a soma dos termos abaixo da diagonal secundaria
 * e a soma dos acima da diagonal principal menos um
*/
double questao9(int rows, int columns, int matrix[][columns]){
    if (rows != columns){
        printf("\nA matriz precisa ser quadrada\nRetornando -1.");
        return (-1);
    }
    double razao;
    double somaAbaixo = 0;
    double somaAcima = 0;
    for (int i = 0; i < rows; i++){ // abaixo secundaria
        for (int j = 0; j < (rows-i); j++){
            somaAbaixo += matrix[i][j]; 
        }
    }
    for (int i = 0; i < rows; i++){ // acima principal
        for (int j = 0; j <= i; j++){
            somaAcima += matrix[i][j];
        }
    }
    if (somaAcima == 0)
    {
        printf("\nDivisao por 0 encontrada, favor modificar a matriz.\nRetornando -1.");
        return (-1);
    }
    razao = somaAbaixo/somaAcima;
    return (razao);
}
void metodo9()
{
    double razao;
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("\n\nteste com matriz quadrada sequencial:");
    razao = questao9(3, 3, matrix1);
    printf("\n%lf", razao);

    int matrix2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    printf("\n\nteste com matriz nao quadrada sequencial:");
    razao = questao9(3, 2, matrix2);
    printf("\n%lf", razao);

    int matrix3[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    printf("\n\nteste com matriz quadrada zerada:");
    razao = questao9(3, 3, matrix3);
    printf("\n%lf", razao);
}



/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Questao 10:
 * Definir um procedimento para receber dois parametros inteiros passados por referencia e,
 * se o primeiro for maior que o segundo, 
 * trocar os dois de variaveis.
*/
void trocar(int *x, int *y){
    if (*x > *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}
void metodo10()
{
    int x = 3;
    int y = 2;
    printf("\n\nAntes da troca\nx = %d\ny = %d", x, y);
    trocar(&x, &y);
    printf("\n\nDepois da troca\nx = %d\ny = %d", x, y);
    
    int a = 5;
    int b = 7;
    printf("\n\nAntes da troca\nx = %d\ny = %d", a, b);
    trocar(&a, &b);
    printf("\n\nDepois da troca\nx = %d\ny = %d", a, b);
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
    IO_printf("\n\n");
    metodo1();
}
void exercicio2()
{
    IO_clrscr();
    IO_printf("Exercicio 2");
    IO_printf("\n\n");
    metodo2();
}
void exercicio3()
{
    IO_clrscr();
    IO_printf("Exercicio 3");
    IO_printf("\n\n");
    metodo3();
}
void exercicio4()
{
    IO_clrscr();
    IO_printf("Exercicio 4");
    IO_printf("\n\n");
    metodo4();
}
void exercicio5()
{
    IO_clrscr();
    IO_printf("Exercicio 5");
    IO_printf("\n\n");
    metodo5();
}
void exercicio6()
{
    IO_clrscr();
    IO_printf("Exercicio 6");
    IO_printf("\n\n");
    metodo6();
}
void exercicio7()
{
    IO_clrscr();
    IO_printf("Exercicio 7");
    IO_printf("\n\n");
    metodo7();
}
void exercicio8()
{
    IO_clrscr();
    IO_printf("Exercicio 8");
    IO_printf("\nFazer um procedimento para receber o nome de um arquivo e,");
    IO_printf("\nse esse tiver uma quantidade impar de dados reais,");
    IO_printf("\nacrescentar a media aritmetica entre o primeiro,");
    IO_printf("\no que estiver no meio e o ultimo dado.");
    IO_printf("\n\n");
    metodo8();
}
void exercicio9()
{
    IO_clrscr();
    IO_printf("Exercicio 9");
    IO_printf("\nFazer uma funcao para receber uma matriz (inteira) e suas dimensoes,");
    IO_printf("\ne retornar a razao entre a soma dos termos abaixo da diagonal secundaria");
    IO_printf("\ne a soma dos acima da diagonal principal menos um");
    IO_printf("\n\n");
    metodo9();
}
void exercicio10()
{
    IO_clrscr();
    IO_printf("Exercicio 10");
    IO_printf("\nDefinir um procedimento para receber dois parametros inteiros passados por referencia e,");
    IO_printf("\nse o primeiro for maior que o segundo, ");
    IO_printf("\ntrocar os dois de variaveis.");
    IO_printf("\n\n");
    metodo10();
}


/* Exercicio 1:
 * 
 * method_01:
 * 
 * 0 1 2 4 6 8 3 5 7 9
 * 
 * 
 * Logo a resposta correta do exercicio e:
 * 
 * 
 * Qual a saida esperada?
 * a.) 0 1 2 4 6 8 3 5 7 9
 */


/* Exercicio 2:
 * 
 * method_02:
 * 
 * 8       1       2
 * 1       4       5
 * 2       5       8
 * 
 * 
 * Logo a resposta correta do exercicio e:
 * 
 * 
 * Qual a saida equivalente?
 * c.) { {8, 1, 2}, {1, 4, 5}, {2, 5, 8} }
 */


/* Exercicio 3:
 * 
 * substring:
 * 
 * bcd\K☻
 * e
 * abc\K☻
 * deâ\K☻
 * 
 * 
 * Logo a resposta correta do exercicio e:
 * 
 * 
 * Qual chamada tera resultado CORRETO?
 * b.) "e"     = substring(4,6,"abcde")
 */


/* Exercicio 4:
 * 
 * f04:
 * 
 * 0
 * 1
 * 1
 * 1
 * 
 * 
 * Logo a resposta correta do exercicio e:
 * 
 * 
 * Qual chamada tera resultado FALSO(0)
 * a.) f04 (3, "01lO")
 */


/* Exercicio 5:
 * 
 * f05:
 * 
 * 0
 * 1
 * 0
 * 0
 * 
 * 
 * Logo a resposta correta do exercicio e:
 * 
 * 
 * Qual chamada tera resultado VERDADEIRO(1)
 * b.)f05 ("aroma", "amora")
 */


/* Exercicio 6:
 * 
 * method_06:
 * 
 * 4E2C0A
 * 
 * 
 * Logo a resposta correta do exercicio e:
 * 
 * 
 * Qual a saida esperada?
 * c.) 4E2C0A
 */


/* Exercicio 7:
 * 
 * f07:
 * 
 * 1
 * 1
 * 0
 * 1
 * 
 * 
 * Logo a resposta correta do exercicio e:
 * 
 * 
 * Qual a saida tera resultado FALSO(0)
 * c.)f07 ("super-homem")
 */


/* Exercicio 8:
 * 
 * 5.0
 * 6.7
 * 15.0
 * 76.0
 * 100.0
 * 40.000000
 */


/* Exercicio 9:
 * 
 * teste com matriz quadrada sequencial:
 * 0.647059
 * 
 * teste com matriz nao quadrada sequencial:
 * A matriz precisa ser quadrada
 * Retornando -1.
 * -1.000000
 * 
 * teste com matriz quadrada zerada:
 * Divisao por 0 encontrada, favor modificar a matriz.
 * Retornando -1.
 * -1.000000
 */


/* Exercicio 10:
 * 
 * Antes da troca
 * x = 3
 * y = 2
 * 
 * Depois da troca
 * x = 2
 * y = 3
 * 
 * Antes da troca
 * x = 5
 * y = 7
 * 
 * Depois da troca
 * x = 5
 * y = 7
 */