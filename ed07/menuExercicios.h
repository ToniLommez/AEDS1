#include "io.h"

bool eMaiuscula(char x)
{
    return (x >= 'A' && x <= 'Z');
}
bool eMinuscula(char x)
{
    return (x >= 'a' && x <= 'z');
}
bool eDigito(char x)
{
    return (x >= '0' && x <= '9');
}
bool eLetra(char x)
{
    return (eMaiuscula(x) || eMinuscula(x));
}
bool eAlfanumerico(char x)
{
    return (eLetra(x) || eDigito(x));
}
bool ePar(double x)
{
    return ((int)x%2==0);
}
int fibonacci(int n){
    int resposta=0;
    
    if (n==1 || n==2)
        resposta=1;
    else if (n>1)
        resposta=fibonacci(n-1)+fibonacci(n-2);
    return(resposta);
}

void exemplo0711a(char* filename, int n)
{
    FILE* arquivo = fopen(filename, "w");
    int x=0;
    for (int i=0; i<n; i++){
        if (x%3==0 && x%2!=0)
            fprintf(arquivo, "%d\n", x);
        else
            i--;
        x++;
    }
    fclose (arquivo);
}
void exemplo0712a(char* filename, int n)
{
    FILE* arquivo = fopen(filename, "w");
    int x=n*6;
    for (int i=0; i<n; i++){
        if (x%3==0 && x%2==0)
            fprintf(arquivo, "%d\n", x);
        else
            i--;
        x=x-3;
    }
    fclose (arquivo);
}
void exemplo0713a(char* filename, int n)
{
    FILE* arquivo = fopen(filename, "w");
    for (int i=0; i<n; i++)
        fprintf(arquivo, "%d\n", (int)pow(5, i));
    fclose (arquivo);
}
void exemplo0714a(char* filename, int n)
{
    int x = pow(3, n);
    FILE* arquivo = fopen(filename, "w");
    for (int i=0; i<n; i++)
    {
        fprintf(arquivo, "%lf\n", 1.0/x);
        x = x/3;
    }
    fclose (arquivo);
}
void exemplo0715a(char* filename, int n, double x)
{
    FILE* arquivo = fopen(filename, "w");
    fprintf(arquivo, "1\n");
    for (int i=1; i<n; i++)
    {
        fprintf(arquivo, "%lf\n", 1/pow(x, (i*2)-1));
    }
    fclose (arquivo);
}
void exemplo0716a(char* readFile, char* writeFile, int n)
{
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    double numero = 0;
    double resultado = 0;
    int i = 0;
    while (!feof (ler) && i<n){
        fscanf (ler, "%lf", &numero);
        resultado+=numero;
        i++;
    }
    fprintf (escrever, "%d numeros\nresultado: %lf\n", n, resultado);
    fclose (ler);
    fclose (escrever);
}
void exemplo0717a(char* readFile, char* writeFile, int n)
{
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    double numero = 0;
    double resultado = 0;
    int i = 0;
    while (!feof (ler) && i<n){
        fscanf (ler, "%lf", &numero);
        resultado+=numero;
        i++;
        fprintf (escrever, "%d %lf\n", i, resultado);
    }
    fclose (ler);
    fclose (escrever);
}
void exemplo0718a(char* writeFile, int n)
{
    FILE* escrever = fopen (writeFile, "w");
    for (int i = 0; i < n; i++)
    {
        int temp = fibonacci(i);
        if (ePar(temp))
            fprintf (escrever, "%d\n", temp);
        else
            n++;
    }
    fclose (escrever);
}
void escreverEmTxt(char* writeFile)
{
    FILE* escrever = fopen (writeFile, "w");
    IO_printf("\nDigite a cadeia de caracteres:\n");
    char a[80];
    gets(a);
    fputs (a, escrever);
    fclose (escrever);
}
void exemplo0719a(char* readFile, char* writeFile)
{
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    while (!feof (ler)){
        int maiusculas = 0;
        char a[80];
        fscanf (ler, "%s", a);
        for (int i=0; i<strlen(a); i++){
            if (eMaiuscula(a[i])){
                maiusculas++;
            }
        }
        fprintf (escrever, "Sequencia: %s\nMaiusculas: %d\n\n", a, maiusculas);
    }
    fclose (ler);
    fclose (escrever);
}
void exemplo0720a(char* readFile, char* writeFile)
{
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    while (!feof (ler)){
        int maiores = 0;
        char a[80];
        fscanf (ler, "%s", a);
        for (int i=0; i<strlen(a); i++){
            if (eDigito(a[i]) && a[i] >= '7'){
                maiores++;
            }
        }
        fprintf (escrever, "Sequencia: %s\nMaiores que 7: %d\n\n", a, maiores);
    }
    fclose (ler);
    fclose (escrever);
}
void exemplo07E1a(char* filename, int n)
{
    FILE* arquivo = fopen(filename, "w");
    for (int x=n/2; x>0; x--)
    {
        if (n%x==0)
        {
            fprintf(arquivo, "%d\n", x);
        }
    }
    fclose (arquivo);
}
void escreverEmTxtLinha(char* writeFile)
{
    FILE* escrever = fopen (writeFile, "w");
    IO_printf(" - Enter para proxima linha\n - 0 para parar\n\nDigite as sequencias de caracteres:\n");
    for (int i = 0; i < 1;)
    {
        char a[80];
        IO_printf("-> ");
        gets(a);
        if (a[0]=='0' && a[1]==null)
        {
            fclose (escrever);
            return;
        }
        fputs (a, escrever);
        fprintf (escrever, "\n");
    }
    fclose (escrever);
}
void exemplo07E2a(char* readFile, char* writeFile)
{
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    int iniciaEmA = 0;
    while (!feof (ler)){
        char a[80];
        fgets(a, 80, ler);
        if (a[0]=='a' || a[0]=='A')
        {
            iniciaEmA++;
        }
    }
    fprintf (escrever, "Palavras de um arquivo, uma por linha iniciadas em a:\n%d", iniciaEmA);
    fclose (ler);
    fclose (escrever);
}

void exemplo0711()
{
    IO_clrscr();
    IO_printf("Exemplo0711");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado e gravar essa quantidade em multiplos de 3, impares, em ordem crescente, comecando em 3.\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo0711a("Exemplo0711.txt", n);
    IO_printf("\nValores gravados\n");
}
void exemplo0712()
{
    IO_clrscr();
    IO_printf("Exemplo0712");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado e gravar essa quantidade em multiplos de 3, pares, em ordem decrescente encerrando em 6.\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo0712a("Exemplo0712.txt", n);
    IO_printf("\nValores gravados\n");
}
void exemplo0713()
{
    IO_clrscr();
    IO_printf("Exemplo0713");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado e gravar essa quantidade em valores da sequencia: 1 5 25 125 625 ...\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo0713a("Exemplo0713.txt", n);
    IO_printf("\nValores gravados\n");
}
void exemplo0714()
{
    IO_clrscr();
    IO_printf("Exemplo0714");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado e gravar essa quantidade em valores decrescentes da sequencia: ... 1/81 1/27 1/9 1/3 1.\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo0714a("Exemplo0714.txt", n);
    IO_printf("\nValores gravados\n");
}
void exemplo0715()
{
    IO_clrscr();
    IO_printf("Exemplo0715");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado (n) e outro valor real (x), gravar essa quantidade (n) em valores reais da sequencia: 1 1/x^1 1/x^3 1/x^5...\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    double x = IO_readdouble("x -> ");
    exemplo0715a("Exemplo0715.txt", n, x);
    IO_printf("\nValores gravados\n");
}
void exemplo0716()
{
    IO_clrscr();
    IO_printf("Exemplo0716");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado para representar certa quantidade de valores a serem somados dentre os primeiros gravados no exercicio anterior.");
    IO_printf("\nTestar essa funcao para quantidades diferentes. Gravar em outro arquivo ('RESULTADO06.TXT') cada quantidade e seu resultado.\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo0716a("Exemplo0715.txt", "Resultado06.txt", n);
    IO_printf("\nValores gravados\n");
}
void exemplo0717()
{
    IO_clrscr();
    IO_printf("Exemplo0717");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado, e ate essa quantidade, um valor por vez, calcular a soma dos inversos das potencias do exercicio 04.");
    IO_printf("\nGravar em outro arquivo ('RESULTADO07.TXT') cada quantidade e seu resultado.\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo0717a("Exemplo0714.txt", "Resultado07.txt", n);
    IO_printf("\nValores gravados\n");
}
void exemplo0718()
{
    IO_clrscr();
    IO_printf("Exemplo0718");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado, e ate atingir essa quantidade, um valor por vez, gravar o valor correspondente aos primeiros termos pares da serie de Fibonacci.");
    IO_printf("\nGravar em outro arquivo ('RESULTADO08.TXT') cada quantidade e seu resultado.\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo0718a("Resultado08.txt", n);
    IO_printf("\nValores gravados\n");
}
void exemplo0719()
{
    IO_clrscr();
    IO_printf("Exemplo0719");
    IO_printf("\n\n");
    IO_printf("\nCalcular a quantidade de maiusculas em cadeia de caracteres de um arquivo texto.");
    IO_printf("\nGravar em outro arquivo ('RESULTADO09.TXT') cada cadeia de caracteres e seus resultados.\n");
    escreverEmTxt("exemplo0719.txt");
    exemplo0719a("exemplo0719.txt", "Resultado09.txt");
    IO_printf("\nValores gravados\n");
}
void exemplo0720()
{
    IO_clrscr();
    IO_printf("Exemplo0720");
    IO_printf("\n\n");
    IO_printf("\nContar digitos maiores ou iguais a 7 em uma cadeia de caracteres.");
    IO_printf("\nGravar em outro arquivo ('RESULTADO10.TXT') cada cadeia de caracteres e seu resultado.\n");
    escreverEmTxt("exemplo0720.txt");
    exemplo0720a("exemplo0720.txt", "Resultado10.txt");
    IO_printf("\nValores gravados\n");
}

void exemplo07E1()
{
    IO_clrscr();
    IO_printf("Exemplo07E1");
    IO_printf("\n\n");
    IO_printf("\nLer um valor inteiro do teclado, e gravar em arquivo os seus divisores em ordem decrescente.\n");
    IO_printf("\nDigite o numero:\n");
    int n = IO_readint("n -> ");
    exemplo07E1a("ResultadoE1.txt", n);
    IO_printf("\nValores gravados\n");
}

void exemplo07E2()
{
    IO_clrscr();
    IO_printf("Exemplo07E2");
    IO_printf("\nLer palavras de um arquivo, uma por linha, e contar quantas comecam com a letra 'a' (ou 'A').\n");
    IO_printf("\n\n");
    escreverEmTxtLinha("exemplo07E2.txt");
    exemplo07E2a("exemplo07E2.txt", "ResultadoE2.txt");
    IO_printf("\nValores gravados\n");
}