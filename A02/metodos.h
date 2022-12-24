/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 17/06/2022
 * 
 * A disposicao dos exercicios neste arquivo esta feita da seguinte forma:
 * 1 - os construtores de arquivos DADOS.txt
 * 2 - as construcao do enunciado que chamara as funcoes construidas
 * 3 - o print do enunciado
 * 
 * Os metodos e funcoes pedidas para nos enunciados foram colocadas dentro do arquivo structs.c
 * exemplo:
 * somar(), decrescente(), multiplicarMatriz(), somarMatriz(), identidadeMatriz() ...
 * --------------------------------------------------------------------------------------------------------
*/

#include "io.h"
#include "marcos.h"
#include "structs.h"

void createDados1(){
    srand(time(0));
    FILE *file;
    if (file = fopen("DADOS1.txt", "r")) 
    {
        fclose(file);
    }
    else
    {
        printf("\"DADOS1.txt\" nao encontrado\n");
        if (IO_readbool("Gostaria de criar um arquivo DADOS1.txt aleatoriamente?\n[0] - nao\n[1] - sim\n->"))
        {
            int_Array temp;
            new_int_Array(20);
            temp = limitedRandomArray(0, 20, 20);
            fprintIntArray("DADOS1.txt", temp);
            printf("\nArray salvo em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
        }
        else
        {
            IO_pause("programa pausado esperando pela implementacao de \"DADOS1.txt\"\nAperte enter para continuar");
            createDados1();
        }
    }
}

void createDados2(){
    srand(time(0));
    FILE *file;
    if (file = fopen("DADOS2.txt", "r")) 
    {
        fclose(file);
    }
    else
    {
        printf("\"DADOS2.txt\" nao encontrado\n");
        bool tempBool = IO_readbool("Gostaria de criar um arquivo DADOS2.txt identico a DADOS1 ou aleatorio?\n[0] - aleatorio\n[1] - identico\n->");
        printf("%d", tempBool);
        if (tempBool)
        {
            int_Array temp;
            temp = fIO_readintArray("DADOS1.txt");
            fprintIntArray("DADOS2.txt", temp);
            printf("\nArray identico salvo em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
        }
        else
        {
            int_Array temp;
            new_int_Array(20);
            temp = limitedRandomArray(0, 20, 20);
            fprintIntArray("DADOS2.txt", temp);
            printf("\nArray aleatorio salvo em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
        }
    }
}

void createBinarios1(){
    srand(time(0));
    FILE *file;
    if (file = fopen("BINARIOS1.txt", "r")) 
    {
        fclose(file);
    }
    else
    {
        printf("\"BINARIOS1.txt\" nao encontrado\n");
        if (IO_readbool("Gostaria de criar um arquivo BINARIOS1.txt aleatoriamente?\n[0] - nao\n[1] - sim\n->"))
        {
            int_Array temp;
            new_int_Array(20);
            temp = limitedRandomArray(0, 2, 30);
            fprintIntArray("BINARIOS1.txt", temp);
            printf("\nArray salvo em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
        }
        else
        {
            IO_pause("programa pausado esperando pela implementacao de \"BINARIOS1.txt\"\nAperte enter para continuar");
            createBinarios1();
        }
    }
}

void createMatriz1(){
    srand(time(0));
    FILE *file;
    if (file = fopen("DADOS3.txt", "r")) 
    {
        fclose(file);
    }
    else
    {
        printf("Para nao ocorrer erro de compatibilidade este programa ira usar DADOS3.txt\n\n");
        printf("\"DADOS3.txt\" nao encontrado\n");
        if (IO_readbool("Gostaria de criar um arquivo DADOS3.txt aleatoriamente?\n[0] - nao\n[1] - sim\n->"))
        {
            ref_int_Matrix temp;
            new_int_Matrix(5, 5);
            temp = limitedRandomMatrix(0, 20, 5, 5);
            fprintIntMatrix("DADOS3.txt", temp);
            printf("\nMatrix salvo em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
        }
        else
        {
            IO_pause("programa pausado esperando pela implementacao de \"DADOS3.txt\"\nAperte enter para continuar");
            createMatriz1();
        }
    }
}

/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler arquivo DADOS1.txt
 * 2 - Determinar se os valores estao decrescentes
 * 3 - Se nao estiverem colocar em decrescente
 * 4 - Regravar valores em DECRESCENTE.txt com a quantidade na primeira linha
*/
void metodo1()
{
    createDados1();
    int_Array array1;
    array1 = fIO_readintArray("DADOS1.txt");
    int movimentacoes = 0;
    if (!(decrescente(array1)))
    {
        movimentacoes = decrescenteTransformar(array1);
    }
    printf("Foram usadas %d movimentacoes para ordenar o array", movimentacoes);
    fprintIntArray("DECRESCENTE.txt", array1);
    printf("\nArray decrescente salvo em DECRESCENTE.txt", movimentacoes);
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler arquivo DECRESCENTE.txt
 * 2 - Inverter a ordem dos valores do arquivo
 * 3 - Regravar valores em INVERTIDO.txt com a quantidade na primeira linha
*/
void metodo2()
{
    int_Array array1;
    array1 = fIO_readintArray("DECRESCENTE.txt");
    int movimentacoes = 0;
    movimentacoes = inverterArray(array1);
    printf("Foram usadas %d movimentacoes para ordenar o array", movimentacoes);
    fprintIntArray("INVERTIDO.txt", array1);
    printf("\nArray invertido salvo em INVERTIDO.txt", movimentacoes);
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler arquivo DADOS1.txt
 * 2 - Criar metodo que recebe um arranjo e um inteiro (N)
 * 3 - Achar o menor valor que nao ultrapasse 'N'
 * 4 - Receber e mostrar o segundo menor valor
*/
void metodo3()
{
    createDados1();
    int_Array array1;
    array1 = fIO_readintArray("DADOS1.txt");
    int segundoMenor = segundoMenorDeTodos(array1, menorDeTodos(array1));

    printf("segundo menor = %d", segundoMenor);
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler arquivo DADOS1.txt
 * 2 - Ler arquivo DADOS2.txt
 * 3 - salvar elementos em comum
 * 4 - salvar valores em FILTRADOS.txt
*/
void metodo4()
{
    createDados1();
    createDados2();
    int_Array array1;
    int_Array array2;
    array1 = fIO_readintArray("DADOS1.txt");
    array2 = fIO_readintArray("DADOS2.txt");

    fprintIntArray("FILTRADOS.txt", valoresComuns(array1, array2));
    printf("\nArray filtrado salvo em FILTRADOS.txt");
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler arquivo BINARIOS1.txt
 * 2 - Armazenar apenas os valores iguais a 0|1
 * 3 - converter e armazer em um arranjo de INT
 * 4 - usar uma funcao para converter em decimal
*/
void metodo5()
{
    createBinarios1();
    int_Array array1;
    array1 = fIO_readBitArray("BINARIOS1.txt");
    int x = paraDecimal(array1);
    printf("\ndecimal = %d", x);
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler um valor N para criar uma matriz quadrada
 * 2 - montar, mostrar e gravar em MATRIX2.txt uma tridiagonal crescente
*/
void metodo6()
{
    ref_int_Matrix matriz1;
    int n = IO_readint("Escolha o tamanho da matriz:\n-> ");
    matriz1 = tridiagonalCrescente(n);

    printf("\nTrigiagonal Crescente:\n");
    printIntMatrix(matriz1);
    printf("\n");
    fprintIntMatrix("MATRIX2.txt", matriz1);
    printf("\nValores salvos com sucesso em MATRIX2.txt\n");
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler um valor N para criar uma matriz quadrada
 * 2 - montar, mostrar e gravar em MATRIX2.txt uma tridiagonal decrescente
*/
void metodo7()
{
    ref_int_Matrix matriz1;
    int n = IO_readint("Escolha o tamanho da matriz:\n-> ");
    matriz1 = tridiagonalDecrescente(n);

    IO_printf("\nTrigiagonal Decrescente:\n");
    printIntMatrix(matriz1);
    IO_printf("\n");
    fprintIntMatrix("MATRIX2.txt", matriz1);
    IO_printf("\nValores salvos com sucesso em MATRIX2.txt\n");
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler arquivo MATRIX3.txt
 * 2 - Verificar se a matriz possui potencia por linhas
*/
void metodo8()
{
    ref_int_Matrix matriz1;
    IO_printf("Lendo MATRIX3.txt...\n");
    matriz1 = freadintMatrix("MATRIX3.txt");
    printIntMatrix(matriz1);
    IO_printf("%s", potenciaPorLinhas(matriz1)?"\n\nA Matriz possui potencia por linhas":"\n\nA Matriz nao possui potencia por linhas");
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 1 - Ler arquivo MATRIX3.txt
 * 2 - Verificar se a matriz possui potencia por colunas
*/
void metodo9()
{
    ref_int_Matrix matriz1;
    IO_printf("Lendo MATRIX4.txt...\n");
    matriz1 = freadintMatrix("MATRIX4.txt");
    printIntMatrix(matriz1);
    IO_printf("%s", potenciaPorColunas(matriz1)?"\n\nA Matriz possui potencia por colunas":"\n\nA Matriz nao possui potencia por colunas");
}


/* 771157- Marcos Antonio Lommez Candido Ribeiro
 * Metodo para:
 * 
 * 
*/
void metodo10()
{

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
    IO_printf("Exercicio 1\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nDefinir uma funcao para determinar se os valores");
    IO_printf("\nno arranjo estao em ordem decrescente;");
    IO_printf("\nLer arranjo do arquivo DADOS1.TXT;");
    IO_printf("\nSe nao estiverem, coloca-los em ordem decrescente,");
    IO_printf("\nantes de regravar os dados no arquivo DECRESCENTE.TXT,");
    IO_printf("\ncolocando a quantidade de elementos na primeira linha do arquivo.");
    IO_printf("\n\n");
    metodo1();
}
void exercicio2()
{
    IO_clrscr();
    IO_printf("Exercicio 2\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nDefinir uma funcao para receber o arranjo como");
    IO_printf("\nparametro e inverter a ordem de seus elementos;");
    IO_printf("\nLer arranjo do arquivo DECRESCENTE.TXT;");
    IO_printf("\nGravar o arranjo invertido no arquivo INVERTIDOS.TXT,");
    IO_printf("\ncolocando a quantidade de dados elementos na primeira linha");
    IO_printf("\n\n");
    metodo2();
}
void exercicio3()
{
    IO_clrscr();
    IO_printf("Exercicio 3\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nDefinir uma funcao para receber um arranjo e um valor inteiro");
    IO_printf("\ncomo parametros, e achar o menor valor que nao ultrapasse o segundo parametro;");
    IO_printf("\nLer arranjo do arquivo DADOS1.TXT;");
    IO_printf("\nReceber e mostrar o segundo menor valor usando a funcao definida;");
    IO_printf("\n\n");
    metodo3();
}
void exercicio4()
{
    IO_clrscr();
    IO_printf("Exercicio 4\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nLer um arranjo do arquivo DADOS1.TXT;");
    IO_printf("\nLer outro arranjo do arquivo DADOS2.TXT;");
    IO_printf("\nFiltrar e mostrar os elementos comuns aos dois arranjos,");
    IO_printf("\nsem repeticoes;");
    IO_printf("\nGravar o resultado no arquivo FILTRADOS.TXT,");
    IO_printf("\nColocando a quantidade de dados unicos na primeira linha.");
    IO_printf("\n\n");
    metodo4();
}
void exercicio5()
{
    IO_clrscr();
    IO_printf("Exercicio 5\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nLer cadeias de caracteres do arquivo BINARIOS1.TXT;");
    IO_printf("\nConsiderar validos apenas os valores iguais a zero ou a um;");
    IO_printf("\nConverter e armazenar em um arranjo de inteiros (int);");
    IO_printf("\nSupondo serem digitos de um numero binario,");
    IO_printf("\nconverte-los para decimal mediante o uso de uma funcao.");
    IO_printf("\n\n");
    metodo5();
}
void exercicio6()
{
    IO_clrscr();
    IO_printf("Exercicio 6\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nLer dados para matrizes do arquivo MATRIZ1.TXT;");
    IO_printf("\nLer um numero inteiro ( N ) para indicar");
    IO_printf("\na quantidade de linhas e colunas de uma matriz quadrada;");
    IO_printf("\nMontar, mostrar e gravar no arquivo MATRIZ2.TXT");
    IO_printf("\numa matriz com a caracteristica abaixo (tridiagonal crescente).");
    IO_printf("\n\n");
    metodo6();
}
void exercicio7()
{
    IO_clrscr();
    IO_printf("Exercicio 7\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nLer dados para matrizes do arquivo MATRIZ1.TXT;");
    IO_printf("\nLer um numero inteiro ( N ) para indicar");
    IO_printf("\na quantidade de linhas e colunas de uma matriz quadrada;");
    IO_printf("\nMontar, mostrar e gravar no arquivo MATRIZ2.TXT");
    IO_printf("\numa matriz com a caracteristica abaixo (tridiagonal decrescente).");
    IO_printf("\n\n");
    metodo7();
}
void exercicio8()
{
    IO_clrscr();
    IO_printf("Exercicio 8\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nLer matriz do arquivo MATRIZ3.TXT;");
    IO_printf("\nDefinir uma funcao logica para verificar");
    IO_printf("\nse a matriz lida apresenta a caracteristica abaixo (potencias por linha)");
    IO_printf("\n\n");
    metodo8();
}
void exercicio9()
{
    IO_clrscr();
    IO_printf("Exercicio 9\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nLer matriz do arquivo MATRIZ4.TXT;");
    IO_printf("\nDefinir uma funcao logica para verificar");
    IO_printf("\nse a matriz lida apresenta a caracteristica abaixo (potencias por coluna).");
    IO_printf("\n\n");
    metodo9();
}
void exercicio10()
{
    IO_clrscr();
    IO_printf("Exercicio 10\n");
    IO_printf("\nFAZER um programa para:");
    IO_printf("\nLer do arquivo DADOS3.TXT:");
    IO_printf("\nUm numero inteiro ( N ) para indicar");
    IO_printf("\na quantidade de supermercados cujos precos de produtos serao avaliados;");
    IO_printf("\nO nome e o codigo (int) de cada supermercado;");
    IO_printf("\nLer o preco de um produto de cada supermercado;");
    IO_printf("\nCalcular o preco medio desse produto;");
    IO_printf("\nInformar pelo menos dois supermercados com precos");
    IO_printf("\ninferiores a media.");
    IO_printf("\n\n");
    metodo10();
}



/* Exercicio 1:
 * 
 * 
*/


/* Exercicio 2:
 * 
 * 
*/


/* Exercicio 3:
 * 
 * 
*/


/* Exercicio 4:
 * 
 * 
*/


/* Exercicio 5:
 * 
 * 
*/


/* Exercicio 6:
 * 
 * 
*/


/* Exercicio 7:
 * 
 * 
*/


/* Exercicio 8:
 * 
 * 
*/


/* Exercicio 9:
 * 
 * 
*/


/* Exercicio 10:
 * 
 * 
*/
