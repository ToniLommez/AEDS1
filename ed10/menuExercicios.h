/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
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
#include "structs.h"

/*
 * ----------------------------------
 *      Construtores de arquivos
 * ----------------------------------
*/

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
            new_int_Array(5);
            temp = limitedRandomArray(0, 20, 5);
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
            new_int_Array(5);
            temp = limitedRandomArray(0, 20, 5);
            fprintIntArray("DADOS2.txt", temp);
            printf("\nArray aleatorio salvo em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
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

void createMatriz2(){
    srand(time(0));
    FILE *file;
    if (file = fopen("DADOS4.txt", "r")) 
    {
        fclose(file);
    }
    else
    {
        printf("Para nao ocorrer erro de compatibilidade este programa ira usar DADOS4.txt\n\n");
        printf("\"DADOS4.txt\" nao encontrado\n");
        bool tempBool = IO_readbool("Gostaria de criar um arquivo DADOS4.txt identico a DADOS3 ou aleatorio?\n[0] - aleatorio\n[1] - identico\n->");
        printf("%d", tempBool);
        if (tempBool)
        {
            ref_int_Matrix temp;
            temp = freadintMatrix("DADOS3.txt");
            fprintIntMatrix("DADOS4.txt", temp);
            printf("\nMatriz identica salva em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
        }
        else
        {
            ref_int_Matrix temp;
            new_int_Matrix(5, 5);
            temp = limitedRandomMatrix(0, 20, 5, 5);
            fprintIntMatrix("DADOS4.txt", temp);
            printf("\nMatriz salva em arquivo, o exercicio continuara com a leitura do mesmo");
            printf("\n\n");
        }
    }
}

/*
 * ----------------------------------
 *         Chamada dos metodos
 * ----------------------------------
*/

void exemplo1011a(){
    int start = IO_readint("inicio ->");
    int end = IO_readint("fim ->");
    int lines = IO_readint("n ->");

    int_Array array;
    array = limitedRandomArray(start, end, lines);
    fprintIntArray("DADOS1.txt", array);
}

void exemplo1012a(){
    createDados1();
    int_Array array;
    array = fIO_readintArray("DADOS1.txt");
    printIntArray(array);
    printf("\n");
    int value = IO_readint("Valor a ser procurado\n-> ");
    IO_printf("\n\nO valor %s presente no array", isPresent(value, array)?"esta":"nao esta");
}

void exemplo1013a(){
    createDados1();
    createDados2();
    int_Array array1;
    int_Array array2;
    array1 = fIO_readintArray("DADOS1.txt");
    array2 = fIO_readintArray("DADOS2.txt");

    printf("\nArray 1:\n");
    printIntArray(array1);
    printf("\nArray 2:\n");
    printIntArray(array2);
    printf("\n");
    IO_printf("\n%s", comparar(array1, array2)?"Os dois arrays sao identicos":"Os dois arrays sao diferentes");
}

void exemplo1014a(){
    createDados1();
    createDados2();
    int_Array array1;
    int_Array array2;
    array1 = fIO_readintArray("DADOS1.txt");
    array2 = fIO_readintArray("DADOS2.txt");

    int_Array soma;
    int constante = IO_readint("\nEscolha a constante\n-> ");
    soma = somar(array1, constante, array2);
    
    printf("\nArray 1:\n");
    printIntArray(array1);
    printf("\nArray 2:\n");
    printIntArray(array2);
    printf("\nSoma:\n");
    printIntArray(soma);
}

void exemplo1015a(){
    createDados1();
    int_Array array1;
    array1 = fIO_readintArray("DADOS1.txt");
    printf("\nArray 1:\n");
    printIntArray(array1);
    printf("\n");
    IO_printf("\n%s", crescente(array1)?"O array esta crescente":"O array nao esta crescente");
}

void exemplo1016a(){
    createMatriz1();
    ref_int_Matrix matriz1;
    matriz1 = freadintMatrix("DADOS3.txt");
    ref_int_Matrix matriz2;
    matriz2 = transpostaMatriz(matriz1);

    printf("\nMatriz 1:\n");
    printIntMatrix(matriz1);
    printf("\ntransposta:\n");
    printIntMatrix(matriz2);
    printf("\n");
}

void exemplo1017a(){
    createMatriz1();
    ref_int_Matrix matriz1;
    matriz1 = freadintMatrix("DADOS3.txt");

    printf("\nMatriz 1:\n");
    printIntMatrix(matriz1);
    printf("\n");

    IO_printf("%s", zeroMatriz(matriz1)?"\nA matriz possui apenas zeros\n\n":"\nA matriz nao possui apenas zeros\n\n");

    IO_pause("Agora sera feito um teste da funcao com uma matriz zerada:\nAperte ENTER para continuar");

    ref_int_Matrix matriz2;
    matriz2 = matrixOnlyZero();

    printf("\nMatriz 2:\n");
    printIntMatrix(matriz2);
    printf("\n");

    IO_printf("%s", zeroMatriz(matriz2)?"\nA matriz possui apenas zeros\n\n":"\nA matriz nao possui apenas zeros\n\n");
}

void exemplo1018a(){
    createMatriz1();
    createMatriz2();
    ref_int_Matrix matriz1;
    ref_int_Matrix matriz2;
    matriz1 = freadintMatrix("DADOS3.txt");
    matriz2 = freadintMatrix("DADOS4.txt");

    printf("\nMatriz 1:\n");
    printIntMatrix(matriz1);
    printf("\nMatriz 2:\n");
    printIntMatrix(matriz2);
    printf("\n");
    IO_printf("\n%s", compararMatriz(matriz1, matriz2)?"As duas matrizes sao identicas":"As duas matrizes sao diferentes");
}

void exemplo1019a(){
    createMatriz1();
    createMatriz2();
    ref_int_Matrix matriz1;
    ref_int_Matrix matriz2;
    matriz1 = freadintMatrix("DADOS3.txt");
    matriz2 = freadintMatrix("DADOS4.txt");

    ref_int_Matrix soma;
    int constante = IO_readint("\nescolha a constante\n-> ");
    soma = somarMatriz(matriz1, constante, matriz2);

    printf("\nMatriz 1:\n");
    printIntMatrix(matriz1);
    printf("\nMatriz 2:\n");
    printIntMatrix(matriz2);
    printf("\nSoma:\n");
    printIntMatrix(soma);
    printf("\n");
}

void exemplo1020a(){
    createMatriz1();
    createMatriz2();
    ref_int_Matrix matriz1;
    ref_int_Matrix matriz2;
    matriz1 = freadintMatrix("DADOS3.txt");
    matriz2 = freadintMatrix("DADOS4.txt");

    ref_int_Matrix produto;
    produto = multiplicarMatriz(matriz1, matriz2);

    printf("\nMatriz 1:\n");
    printIntMatrix(matriz1);
    printf("\nMatriz 2:\n");
    printIntMatrix(matriz2);
    printf("\nProduto:\n");
    printIntMatrix(produto);
    printf("\n");
}

void exemplo10E1a(){
    createDados1();
    int_Array array1;
    array1 = fIO_readintArray("DADOS1.txt");
    int_Array ordenado;
    ordenado = decrescente(array1);
    
    printf("\nArray 1:\n");
    printIntArray(array1);
    printf("\nDecrescente:\n");
    printIntArray(ordenado);
}

void exemplo10E2a(){
    createMatriz1();
    createMatriz2();
    ref_int_Matrix matriz1;
    ref_int_Matrix matriz2;
    matriz1 = freadintMatrix("DADOS3.txt");
    matriz2 = freadintMatrix("DADOS4.txt");

    ref_int_Matrix produto;
    produto = multiplicarMatriz(matriz1, matriz2);

    printf("\nMatriz 1:\n");
    printIntMatrix(matriz1);
    printf("\nMatriz 2:\n");
    printIntMatrix(matriz2);
    printf("\nProduto:\n");
    printIntMatrix(produto);
    printf("\n");

    IO_printf("%s", identidadeMatriz(produto)?"\n\nA multiplicacoes das matrizez e identidade":"\n\nA multiplicacoes das matrizes nao e identidade");
}

/*
 * ----------------------------------
 *             Enunciados
 * ----------------------------------
*/

void exemplo1011(){
    IO_clrscr();
    IO_printf("Exemplo1011\n");
    IO_printf("\nGerar um valor inteiro aleatoriamente dentro de um intervalo.");
    IO_printf("\nArmazenar estes valores dentro de um arquivo 'DADOS.txt' com N tamanho.");
    IO_printf("\nA primeira linha deve conter a quantidade de dados no arquivo.");
    IO_printf("\n\n");

    exemplo1011a();
}

void exemplo1012(){
    IO_clrscr();
    IO_printf("Exemplo1012\n");
    IO_printf("\nIncluir uma funcao para procurar um valor inteiro em um arranjo.");
    IO_printf("\nReceber o nome de um arquivo como parametro e aplicar a funcao sobre o arranjo.");
    IO_printf("\n\n");

    exemplo1012a();
}

void exemplo1013(){
    IO_clrscr();
    IO_printf("Exemplo1013\n");
    IO_printf("\nIncluir uma funcao para comparar dois arranjos.");
    IO_printf("\n\n");

    exemplo1013a();
}

void exemplo1014(){
    IO_clrscr();
    IO_printf("Exemplo1014\n");
    IO_printf("\nIncluir uma funcao para operar a soma de dois arranjos");
    IO_printf("\ncom o segundo escalado por uma constante.");
    IO_printf("\n\n");

    exemplo1014a();
}

void exemplo1015(){
    IO_clrscr();
    IO_printf("Exemplo1015\n");
    IO_printf("\nIncluir uma funcao para dizer se um arranjo esta em ordem crescente.");
    IO_printf("\n\n");

    exemplo1015a();
}

void exemplo1016(){
    IO_clrscr();
    IO_printf("Exemplo1016\n");
    IO_printf("\nIncluir uma funcao para obter a transposta de uma matriz.");
    IO_printf("\n\n");

    exemplo1016a();
}

void exemplo1017(){
    IO_clrscr();
    IO_printf("Exemplo1017\n");
    IO_printf("\nIncluir uma funcao para testar se uma matriz so contem valores iguais a zero.");
    IO_printf("\n\n");

    exemplo1017a();
}

void exemplo1018(){
    IO_clrscr();
    IO_printf("Exemplo1018\n");
    IO_printf("\nIncluir uma funcao para testar a igualdade de duas matrizes.");
    IO_printf("\n\n");

    exemplo1018a();
}

void exemplo1019(){
    IO_clrscr();
    IO_printf("Exemplo1019\n");
    IO_printf("\nIncluir uma funcao para operar a soma de duas matrizes");
    IO_printf("\ncom a segunda escalado por uma constante.");
    IO_printf("\n\n");

    exemplo1019a();
}

void exemplo1020(){
    IO_clrscr();
    IO_printf("Exemplo1020\n");
    IO_printf("\nIncluir uma funcao para obter o produto de duas matrizes.");
    IO_printf("\n\n");

    exemplo1020a();
}

void exemplo10E1(){
    IO_clrscr();
    IO_printf("Exemplo10E1\n");
    IO_printf("\nIncluir uma funcao para colocar um arranjo em ordem decrescente");
    IO_printf("\npelo metodo de trocas de posicao.");
    IO_printf("\n\n");

    exemplo10E1a();
}

void exemplo10E2(){
    IO_clrscr();
    IO_printf("Exemplo10E2\n");
    IO_printf("\nIncluir uma funcao para testar se o produto de duas matrizes");
    IO_printf("\ne igual a matriz identidade.");
    IO_printf("\n\n");

    exemplo10E2a();
}