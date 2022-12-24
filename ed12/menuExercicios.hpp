#include "io.hpp"
#include "myMatrix.hpp"
#include "marcos.hpp"

void exemplo1211a()
{
    int m = readIntNat("Linhas -> ");
    int n = readIntNat("Colunas -> ");
    Matrix<int> intMatrix(m, n, 0);
    srand(time(0));
    intMatrix.random();
    intMatrix.fprint("dados.txt");
    intMatrix.free();
}
void exemplo1212a()
{
    Matrix<int> intMatrix1;
    Matrix<int> intMatrix2;
    intMatrix1.fread("dados.txt");
    intMatrix2.fread("dados.txt");
    intMatrix2.scale(IO_readint("\nConstante -> "));

    std::cout << "\nMatrix: \n";
    intMatrix1.print();
    std::cout << "\nMatrix escalado por constante: \n";
    intMatrix2.print();

    intMatrix1.free();
    intMatrix2.free();
    flush();
}
void exemplo1213a()
{
    Matrix<int> intMatrix;
    intMatrix.fread("dados.txt");
    std::cout << "\nMatrix: \n";
    intMatrix.print();
    std::cout << "\nA matrix " << (intMatrix.identidade() ? "e identidade." : "nao e identidade.");
    flush();
}
void exemplo1214a()
{
    Matrix<int> intMatrix1;
    Matrix<int> intMatrix2;
    intMatrix1.fread("dados.txt");
    intMatrix2.fread("dados.txt");

    std::cout << "\nMatrix 1:\n";
    intMatrix1.print();
    std::cout << "Matrix 2:\n";
    intMatrix2.print();

    if (intMatrix1 == intMatrix2)
        std::cout << "As Matrizes sao iguais\n";
    else
        std::cout << "As Matrizes sao iguais\n";

    int rows = intMatrix1.matrixRows();
    int columns = intMatrix1.matrixColumns();
    Matrix<int> intMatrix3(rows, columns, 0);
    intMatrix3.random();

    std::cout << "\n\nMatrix 1:\n";
    intMatrix1.print();
    std::cout << "Matrix 3:\n";
    intMatrix3.print();

    if (intMatrix1 != intMatrix3)
        std::cout << "As Matrizes sao diferentes\n";
    else
        std::cout << "As Matrizes sao iguais\n";


    std::cout << "\nInfelizmente este exercicio esta fechando sozinho e nao sei o porque :(";
    std::cout << "\nPor favor abra o ed novamente pra continuar os proximos";
    intMatrix1.free();
    intMatrix2.free();
    intMatrix3.free();
    flush();
}
void exemplo1215a()
{
    Matrix<int> intMatrix1;
    intMatrix1.fread("dados.txt");
    int rows = intMatrix1.matrixRows();
    int columns = intMatrix1.matrixColumns();
    Matrix<int> intMatrix2(rows, columns, 0);
    intMatrix2.random();
    Matrix<int> intMatrix3;
    intMatrix3 = intMatrix1 + intMatrix2;

    std::cout << "\nMatrix 1:\n";
    intMatrix1.print();
    std::cout << "Matrix 2:\n";
    intMatrix2.print();
    std::cout << "Soma:\n";
    intMatrix3.print();

    std::cout << "\nInfelizmente este exercicio esta fechando sozinho e nao sei o porque :(";
    std::cout << "\nPor favor abra o ed novamente pra continuar os proximos";

    intMatrix1.free();
    intMatrix2.free();
    intMatrix3.free();
    flush();
}
void exemplo1216a() // nao fiz
{
    Matrix<int> intMatrix1;
    intMatrix1.fread("dados.txt");
    int row1;
    int row2;
    cout<<"\nMatrix:";
    intMatrix1.print();

    do{
        row1=readIntNat("Linha[1] -> ");
        row2=readIntNat("Linha[2] -> ");
        
        if(row1>=intMatrix1.getRows() || row2>=intMatrix1.getRows()){
            cout<<"\nValores invalido!"<< endl;
        }
    }while(row1>=intMatrix1.getRows() || row2>=intMatrix1.getRows());

    intMatrix1.somaLinhas(row1, row2, readIntNat("Constante ->"));
    cout<<"\nSoma:";
    intMatrix1.print();
    intMatrix1.free();
}
void exemplo1217a() // nao fiz
{
    srand(time(0));

    int column1;
    int column2;
    Matrix<int>matrix(4, 4, 0);
    matrix.random();

    cout<<"\nMatrix:";
    matrix.print();

    do{
        column1=readIntNat("Coluna[1] -> ");
        column2=readIntNat("Coluna[1] -> ");
        
        if(column1>=matrix.getColumns() || column2>=matrix.getColumns()){
            cout<<"\nValores invalido!"<<endl;
        }
    }while(column1>=matrix.getColumns() || column2>=matrix.getColumns());

    matrix.somaColunas(column1, column2, readIntNat("Constante ->"));
    cout<<"\nDiferenca:";
    matrix.print();
    matrix.free();
}
void exemplo1218a()
{
    Matrix<int> intMatrix;
    intMatrix.fread("dados.txt");
    std::cout << "\nMatrix: \n";
    intMatrix.print();
    int procurado = readIntNat("Procurado -> ");
    int teste = intMatrix.procurarLinhas(procurado);
    if (teste == -1)
    {
        std::cout << "\nValor nao encontrado!";
    }else {
        std::cout << "\nValor encontrado na linha = " << teste;
    }
    intMatrix.free();
}
void exemplo1219a()
{
    Matrix<int> intMatrix;
    intMatrix.fread("dados.txt");
    std::cout << "\nMatrix: \n";
    intMatrix.print();
    int procurado = readIntNat("Procurado -> ");
    int teste = intMatrix.procurarColunas(procurado);
    if (teste == -1)
    {
        std::cout << "\nValor nao encontrado!";
    }else {
        std::cout << "\nValor encontrado na coluna = " << teste;
    }
    intMatrix.free();
}
void exemplo1220a()
{
    Matrix<int> intMatrix1;
    intMatrix1.fread("dados.txt");

    int rows = intMatrix1.matrixRows();
    int columns = intMatrix1.matrixColumns();
    Matrix<int> intMatrix2(columns, rows, 0);
    intMatrix1.transposta(intMatrix2);

    std::cout << "\nMatrix 1:\n";
    intMatrix1.print();
    std::cout << "\nMatrix Transposta:\n";
    intMatrix2.print();
    std::cout << "\nInfelizmente este exercicio esta fechando sozinho e nao sei o porque :(";
    std::cout << "\nPor favor abra o ed novamente pra continuar os proximos";
    flush();
    intMatrix1.free();
    intMatrix2.free();
}
void exemplo12E1a()
{
    Matrix<int> intMatrix;
    intMatrix.fread("dados.txt");
    std::cout << "\nMatrix: \n";
    intMatrix.print();
    std::cout << "\nA matrix " << (intMatrix.sequencial() ? "possui " : "nao possui ") << "a sequencia determinada";


    intMatrix.free();
    flush();
}
void exemplo12E2a()
{
    Matrix<int> intMatrix;
    intMatrix.fread("dados.txt");
    std::cout << "\nMatrix: \n";
    intMatrix.print();
    std::cout << "\nA matrix " << (intMatrix.sequencial2() ? "possui " : "nao possui ") << "a sequencia determinada";


    intMatrix.free();
    flush();
}

// INICIO ENUNCIADOS

void exemplo1211()
{
    IO_clrscr();
    std::cout << "Exemplo 1211\n" << endl;
    std::cout << "Ler a quantidade de elementos ( MxN ) a serem gerados;" << endl;
    std::cout << "gerar essa quantidade ( MxN ) de valores aleatorios" << endl;
    std::cout << "dentro do intervalo e armazena-los em matriz;" << endl;
    std::cout << "grava-los, um por linha, em um arquivo (\"DADOS.TXT\")." << endl;
    std::cout << "A primeira linha do arquivo devera informar a quantidade" << endl;
    std::cout << "de numeros aleatorios ( N ) que serao gravados em seguida." << endl;
    std::cout << "DICA: Usar a funcao rand( ), mas tentar limitar valores muito grandes." << endl;
    std::cout << endl;
    exemplo1211a();
}
void exemplo1212()
{
    IO_clrscr();
    std::cout << "Exemplo 1212\n" << endl;
    std::cout << "Escalar uma matriz, multiplicando todos os seus valores por uma constante." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre a matriz com os valores lidos." << endl;
    std::cout << endl;
    exemplo1212a();
}
void exemplo1213()
{
    IO_clrscr();
    std::cout << "Exemplo 1213\n" << endl;
    std::cout << "Testar se uma matriz e a identidade." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre a matriz com os valores lidos." << endl;
    std::cout << endl;
    exemplo1213a();
}
void exemplo1214()
{
    IO_clrscr();
    std::cout << "Exemplo 1214\n" << endl;
    std::cout << "Um operador para testar a igualdade de duas matrizes." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre o arranjo com os valores lidos." << endl;
    std::cout << endl;
    exemplo1214a();
}
void exemplo1215()
{
    IO_clrscr();
    std::cout << "Exemplo 1215\n" << endl;
    std::cout << "Um operador para somar duas matrizes." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre o arranjo com os valores lidos." << endl;
    std::cout << endl;
    exemplo1215a();
}
void exemplo1216()
{
    IO_clrscr();
    std::cout << "Exemplo 1216\n" << endl;
    std::cout << "Operar duas linhas da matriz, guardando no lugar da primeira," << endl;
    std::cout << "as somas de cada elemento da primeira com o respectivo da segunda" << endl;
    std::cout << "multiplicados por uma constante." << endl;
    std::cout << endl;
    exemplo1216a();
}
void exemplo1217()
{
    IO_clrscr();
    std::cout << "Exemplo 1217\n" << endl;
    std::cout << "Operar duas colunas da matriz, guardando no lugar da primeira," << endl;
    std::cout << "as diferencas de cada elemento da primeira com o respectivo da segunda" << endl;
    std::cout << "multiplicado por uma constante." << endl;
    std::cout << endl;
    exemplo1217a();
}
void exemplo1218()
{
    IO_clrscr();
    std::cout << "Exemplo 1218\n" << endl;
    std::cout << "Dizer em qual linha da matriz se encontra certo valor, se houver." << endl;
    std::cout << endl;
    exemplo1218a();
}
void exemplo1219()
{
    IO_clrscr();
    std::cout << "Exemplo 1219\n" << endl;
    std::cout << "Dizer em qual coluna da matriz se encontra certo valor, se houver." << endl;
    std::cout << endl;
    exemplo1219a();
}
void exemplo1220()
{
    IO_clrscr();
    std::cout << "Exemplo 1220\n" << endl;
    std::cout << "Transpor os dados em uma matriz." << endl;
    std::cout << endl;
    exemplo1220a();
}
void exemplo12E1()
{
    IO_clrscr();
    std::cout << "Exemplo 12E1\n" << endl;
    std::cout << "Dizer se uma matriz apresenta a caracteristica abaixo." << endl;
    std::cout << endl;
    exemplo12E1a();
}
void exemplo12E2()
{
    IO_clrscr();
    std::cout << "Exemplo 12E2\n" << endl;
    std::cout << "Montar uma matriz com a caracteristica abaixo." << endl;
    std::cout << endl;
    exemplo12E2a();
}