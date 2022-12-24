#include "io.hpp"
#include "myArray.hpp"
#include "marcos.hpp"

void exemplo1111a()
{
    int n = readIntNat("\nn -> ");
    Array<int> intArray(n, 0);
    srand(time(0));
    intArray.random();
    intArray.fprint("dados.txt");
    intArray.free();
}
void exemplo1112a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");
    std::cout << "\nArray: \n";
    intArray.print();
    int maior = intArray.findLargest();
    std::cout << "\nMaior: " << maior;
    intArray.free();
    flush();
}
void exemplo1113a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");
    std::cout << "\nArray: \n";
    intArray.print();
    int menor = intArray.findLowest();
    std::cout << "\nMenor: " << menor;
    intArray.free();
    flush();
}
void exemplo1114a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");
    std::cout << "\nArray: \n";
    intArray.print();
    int soma = intArray.sumValues();
    std::cout << "\nSoma: " << soma;
    intArray.free();
    flush();
}
void exemplo1115a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");
    std::cout << "\nArray: \n";
    intArray.print();
    int media = intArray.findMean();
    std::cout << "\nMedia: " << media;
    intArray.free();
    flush();
}
void exemplo1116a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");
    std::cout << "\nArray: \n";
    intArray.print();
    bool teste = intArray.allZeros();
    std::cout << "\nO array " << (teste ? "possui" : "nao possui") << " apenas zeros";
    intArray.free();
    flush();
}
void exemplo1117a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");
    std::cout << "\nArray: \n";
    intArray.print();
    bool teste = intArray.decrescent();
    std::cout << "\nO array " << (teste ? "esta ordenado" : "nao esta ordenado");
    intArray.free();
    flush();
}
void exemplo1118a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");
    int x = IO_readint("\nx -> ");
    int inferior = IO_readint("Inferior -> ");
    int superior = IO_readint("Superior -> ");
    int posicao = intArray.findValue(x, inferior, superior);
    std::cout << "\nArray: \n";
    intArray.print();
    if (posicao == -1)
        std::cout << x << " nao esta na entre as posicoes informadas";
    else
        std::cout << x << " esta na posicao [" << posicao << "]";

    intArray.free();
    flush();
}
void exemplo1119a()
{
    Array<int> intArray1;
    intArray1.fread("dados.txt");
    Array<int> intArray2(intArray1);
    intArray2.scale(IO_readint("\nConstante -> "));

    std::cout << "\nArray: \n";
    intArray1.print();
    std::cout << "\nArray escalado por constante: \n";
    intArray2.print();

    intArray1.free();
    intArray2.free();
    flush();
}
void exemplo1120a()
{
    Array<int> intArray;
    intArray.fread("dados.txt");

    std::cout << "\nArray:\n";
    intArray.print();
    intArray.ordenDecrescent();
    std::cout << "\nArray decrescente:\n";
    intArray.print();

    intArray.free();
    flush();
}
void exemplo11E1a()
{
    Array<int> intArray1;
    Array<int> intArray2;
    intArray1.fread("dados.txt");
    intArray2.fread("dados.txt");

    std::cout << "\nArray 1:\n";
    intArray1.print();
    std::cout << "Array 2:\n";
    intArray2.print();

    if (intArray1 != intArray2)
        std::cout << "\nOs arrays sao diferentes";
    else
        std::cout << "\nOs arrays sao iguais";

    int length = intArray1.arrayLength();
    Array<int> intArray3(length, 0);
    intArray3.random();

    std::cout << "\n\nArray 1:\n";
    intArray1.print();
    std::cout << "Array 3:\n";
    intArray3.print();

    if (intArray1 != intArray3)
        std::cout << "\nOs arrays sao diferentes";
    else
        std::cout << "\nOs arrays sao iguais";

    intArray1.free();
    intArray2.free();
    intArray3.free();
    flush();
}
void exemplo11E2a()
{
    Array<int> intArray1;
    intArray1.fread("dados.txt");
    int length = intArray1.arrayLength();
    Array<int> intArray2(length, 0);
    intArray2.random();
    Array<int> intArray3;
    intArray3 = intArray1 - intArray2;

    std::cout << "\nArray 1:\n";
    intArray1.print();
    std::cout << "Array 2:\n";
    intArray2.print();
    std::cout << "Diferenca:\n";
    intArray3.print();

    intArray1.free();
    intArray2.free();
    intArray3.free();
    flush();
}

void exemplo1111()
{
    IO_clrscr();
    std::cout << "Exemplo 1011\n"
              << endl;
    std::cout << "Ler a quantidade de elementos ( N ) a serem gerados" << endl;
    std::cout << "gerar essa quantidade ( N ) de valores aleatorios" << endl;
    std::cout << "entro do intervalo e armazena-los em arranjo" << endl;
    std::cout << "grava-los, um por linha, em um arquivo ('dados.txt')." << endl;
    std::cout << "A primeira linha do arquivo devera informar a quantidade" << endl;
    std::cout << "de numeros aleatorios ( N ) que serao gravados em seguida." << endl;
    std::cout << endl;

    exemplo1111a();
}
void exemplo1112()
{
    IO_clrscr();
    std::cout << "Exemplo 1112\n"
              << endl;
    std::cout << "Procurar o maior valor em um arranjo." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre o arranjo com os valores lidos." << endl;
    std::cout << endl;

    exemplo1112a();
}
void exemplo1113()
{
    IO_clrscr();
    std::cout << "Exemplo 1113\n"
              << endl;
    std::cout << "Procurar o menor valor em um arranjo." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre o arranjo com os valores lidos." << endl;
    std::cout << endl;

    exemplo1113a();
}
void exemplo1114()
{
    IO_clrscr();
    std::cout << "Exemplo 1114\n"
              << endl;
    std::cout << "Somar todos os valores em um arranjo." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre o arranjo com os valores lidos." << endl;
    std::cout << endl;

    exemplo1114a();
}
void exemplo1115()
{
    IO_clrscr();
    std::cout << "Exemplo 1115\n"
              << endl;
    std::cout << "Achar a media dos valores em um arranjo." << endl;
    std::cout << "Para testar, receber um nome de arquivo como parametro e" << endl;
    std::cout << "aplicar a funcao sobre o arranjo com os valores lidos." << endl;
    std::cout << endl;

    exemplo1115a();
}
void exemplo1116()
{
    IO_clrscr();
    std::cout << "Exemplo 1116\n"
              << endl;
    std::cout << "Verificar se todos os valores sao iguais a zero em um arranjo." << endl;
    std::cout << "Para testar, ler o arquivo ('dados.txt')" << endl;
    std::cout << "armazenar os dados em um arranjo." << endl;
    std::cout << endl;

    exemplo1116a();
}
void exemplo1117()
{
    IO_clrscr();
    std::cout << "Exemplo 1117\n"
              << endl;
    std::cout << "Dizer se esta ordenado, ou nao, em ordem decrescente." << endl;
    std::cout << endl;

    exemplo1117a();
}
void exemplo1118()
{
    IO_clrscr();
    std::cout << "Exemplo 1118\n"
              << endl;
    std::cout << "Dizer se determinado valor esta presente em arranjo," << endl;
    std::cout << "entre duas posicoes indicadas." << endl;
    std::cout << "Para testar, ler o arquivo ('dados.txt')," << endl;
    std::cout << "e armazenar os dados em arranjo." << endl;
    std::cout << "Ler do teclado um valor inteiro para ser procurado." << endl;
    std::cout << "Determinar se o valor procurado existe no arranjo." << endl;
    std::cout << endl;

    exemplo1118a();
}
void exemplo1119()
{
    IO_clrscr();
    std::cout << "Exemplo 1119\n"
              << endl;
    std::cout << "Escalar o arranjo, multiplicando cada valor por uma constante." << endl;
    std::cout << "Para testar, ler o arquivo ('dados.txt')," << endl;
    std::cout << "e armazenar os dados em arranjo." << endl;
    std::cout << "ler do teclado um valor inteiro para indicar a constante." << endl;
    std::cout << endl;

    exemplo1119a();
}
void exemplo1120()
{
    IO_clrscr();
    std::cout << "Exemplo 1120\n"
              << endl;
    std::cout << "Colocar valores em arranjo em ordem decrescente," << endl;
    std::cout << "mediante trocas de posicoes, ate ficar totalmente ordenado." << endl;
    std::cout << "Para testar, ler o arquivo ('dados.txt')," << endl;
    std::cout << "e armazenar os dados em arranjo." << endl;
    std::cout << endl;

    exemplo1120a();
}
void exemplo11E1()
{
    IO_clrscr();
    std::cout << "Exemplo 11E1\n"
              << endl;
    std::cout << "Um operador (!=) para" << endl;
    std::cout << "dizer se dois arranjos sao diferentes, pelo menos em uma posicao." << endl;
    std::cout << endl;

    exemplo11E1a();
}
void exemplo11E2()
{
    IO_clrscr();
    std::cout << "Exemplo 11E2\n"
              << endl;
    std::cout << "Um operador (-) para" << endl;
    std::cout << "calcular as diferencas entre dois arranjos, posicao por posicao." << endl;
    std::cout << endl;
    exemplo11E2a();
}