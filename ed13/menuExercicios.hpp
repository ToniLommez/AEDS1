/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 
 * A disposicao dos exercicios neste arquivo esta feita da seguinte forma:
 * 1 - as construcao do enunciado que chamara as funcoes construidas
 * 2 - o print do enunciado
 * 
 * --------------------------------------------------------------------------------------------------------
*/

#include "io.hpp"
#include "marcos.hpp"
#include "Contato.hpp"
#include "Erro.hpp"

/*
 * ----------------------------------
 *         Chamada dos metodos
 * ----------------------------------
*/

void exemplo1311a()
{
    Contato pessoa1;
    pessoa1.readNome();
    cout << "pessoa1 - " << pessoa1.toString() << endl;
}

void exemplo1312a()
{
    Contato pessoa1;
    pessoa1.readFone();
    cout << "pessoa1 - " << pessoa1.toString() << endl;
}

void exemplo1313a()
{
    Contato pessoa1;
    pessoa1.readFoneApenasValido();
    cout << "pessoa1 - " << pessoa1.toString() << endl;
}

void exemplo1314a()
{
    cout << ">> O metodo a seguir le a primeira linha do arquivo como o seu tamanho maximo <<" << endl;
    Contato pessoa1;
    pessoa1.fromFile("Pessoa1.txt");
    cout << "pessoa1 - " << pessoa1.toString() << endl;
}

void exemplo1315a()
{
    Contato pessoa1;
    pessoa1.readNome();
    pessoa1.readFoneValido();
    pessoa1.toFile("Pessoa1.txt");
}

void exemplo1316a()
{
    Contato pessoa1( "nome1", "1111-1111", "2222-2222" );
    cout << "pessoa1 - " << pessoa1.toString() << endl;
}

void exemplo1317a()
{
    Contato pessoa1( "John", "", "" );
    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << pessoa1.getNome() << " possui " << pessoa1.getQuantosTelefones() << " telefones" << endl;

    Contato pessoa2( "Paul", "11111-1111", "" );
    cout << "\npessoa2 - " << pessoa2.toString() << endl;
    cout << pessoa2.getNome() << " possui " << pessoa2.getQuantosTelefones() << " telefones" << endl;

    Contato pessoa3( "Lissa", "11111-1111", "22222-2222" );
    cout << "\npessoa3 - " << pessoa3.toString() << endl;
    cout << pessoa3.getNome() << " possui " << pessoa3.getQuantosTelefones() << " telefones" << endl;
}

void exemplo1318a()
{
    Contato pessoa1;
    pessoa1.readNome();
    pessoa1.readFoneValido();
    cout << "pessoa1 - " << pessoa1.toString() << endl;
}

void exemplo1319a()
{
    Contato pessoa1;
    pessoa1.setFone2("3333-3333");
    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << "pessoa1 erro = (" << pessoa1.getErro() << ")" << endl << endl;

    Contato pessoa2;
    pessoa2.setFone("2222-2222");
    pessoa2.setFone2("3333-3333");
    cout << "pessoa2 - " << pessoa2.toString() << endl;
    cout << "pessoa2 erro = (" << pessoa2.getErro() << ")" << endl;
}

void exemplo1320a()
{
    Contato pessoa1;
    pessoa1.setFone("2222-2222");
    pessoa1.setFone2("3333-3333");
    cout << "pessoa1 - " << pessoa1.toString() << endl;
    pessoa1.removeFone2();
    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << "pessoa1 erro = (" << pessoa1.getErro() << ")" << endl << endl;

    Contato pessoa2;
    pessoa2.setFone("4444-4444");
    cout << "pessoa2 - " << pessoa2.toString() << endl;
    pessoa2.removeFone2();
    cout << "pessoa2 - " << pessoa2.toString() << endl;
    cout << "pessoa2 erro = (" << pessoa2.getErro() << ")" << endl << endl;
}

void exemplo13E1a()
{
    Contato pessoa1;
    pessoa1.setNome("John Smith");
    pessoa1.variosTelefones();
    cout << "\npessoa1 - " << pessoa1.toString2() << endl;
    cout << pessoa1.getNome() << " possui " << pessoa1.getQuantosTelefones() << " telefones" << endl;
}

void exemplo13E2a()
{
    Contato pessoa1;
    pessoa1.setNome("John Smith");
    pessoa1.setFone("98765-4321");
    pessoa1.setEnderecoResidencial("Alameda Lorem Ipsum n320");
    pessoa1.setEnderecoProfissional("Avenida Lorem Ipsum n1240");
    cout << "\npessoa1 - " << pessoa1.toString3() << endl;
}

/*
 * ----------------------------------
 *             Enunciados
 * ----------------------------------
*/

void exemplo1311()
{
    IO_clrscr();
    std::cout << "Exemplo1311" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo publico a classe Contato" << endl;
    std::cout << "para ler do teclado e atribuir um valor ao nome (atributo de certo objeto)." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << "DICA: Testar se o nome nao esta vazio." << endl;
    std::cout << endl;
    exemplo1311a();
}

void exemplo1312()
{
    IO_clrscr();
    std::cout << "Exemplo1312" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo publico a classe Contato" << endl;
    std::cout << "para ler do teclado e atribuir um valor ao telefone (atributo de certo objeto)." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << "DICA: Testar se o telefone nao esta vazio." << endl;
    std::cout << endl;
    exemplo1312a();
}

void exemplo1313()
{
    IO_clrscr();
    std::cout << "Exemplo1313" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo privado a classe Contato" << endl;
    std::cout << "para testar se o valor de um telefone e valido, ou nao." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << "DICA: Testar se as posicoes contem apenas algarismos e o simbolo '-'." << endl;
    std::cout << endl;
    exemplo1313a();
}

void exemplo1314()
{
    IO_clrscr();
    std::cout << "Exemplo1314" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo publico a classe Contato" << endl;
    std::cout << "para ler dados de arquivo, dado o nome do mesmo, e armazenar em um objeto dessa classe." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << endl;
    exemplo1314a();
}

void exemplo1315()
{
    IO_clrscr();
    std::cout << "Exemplo1315" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo a classe Contato" << endl;
    std::cout << "para gravar dados de uma pessoa em arquivo, dado o nome do mesmo." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << "DICA: Gravar o tamanho tambem do arquivo, primeiro, antes dos outros dados." << endl;
    std::cout << endl;
    exemplo1315a();
}

void exemplo1316()
{
    IO_clrscr();
    std::cout << "Exemplo1316" << endl;
    std::cout << "Fazer um programa para acrescentar a classe Contato" << endl;
    std::cout << "um novo atributo para um segundo telefone e modificar os construtores para lidar com isso." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << endl;
    exemplo1316a();
}

void exemplo1317()
{
    IO_clrscr();
    std::cout << "Exemplo1317" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo publico a classe Contato" << endl;
    std::cout << "um novo atributo para indicar quantos telefones estao associados a cada objeto." << endl;
    std::cout << "Incluir um metodo para obter essa informacao." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << endl;
    exemplo1317a();
}

void exemplo1318()
{
    IO_clrscr();
    std::cout << "Exemplo1318" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo publico a classe Contato" << endl;
    std::cout << "para atribuir o valor do segundo telefone." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << "DICA: Se o contato so tiver um telefone, perguntar se quer acrescentar mais um numero," << endl;
    std::cout << "e mudar automaticamente a quantidade deles, se assim for desejado." << endl;
    std::cout << endl;
    exemplo1318a();
}

void exemplo1319()
{
    IO_clrscr();
    std::cout << "Exemplo1319" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo publico a classe Contato" << endl;
    std::cout << "para alterar o valor apenas do segundo telefone." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << "DICA: Se o contato nao tiver dois telefones, uma situacao de erro devera ser indicada." << endl;
    std::cout << endl;
    exemplo1319a();
}

void exemplo1320()
{
    IO_clrscr();
    std::cout << "Exemplo1320" << endl;
    std::cout << "Fazer um programa para acrescentar um metodo publico a classe Contato" << endl;
    std::cout << "para remover apenas o valor do segundo telefone." << endl;
    std::cout << "Incluir um metodo para testar essa nova caracteristica." << endl;
    std::cout << "DICA: Se o contato so tiver um telefone, uma situacao de erro devera ser indicada." << endl;
    std::cout << endl;
    exemplo1320a();
}

void exemplo13E1()
{
    IO_clrscr();
    std::cout << "Exemplo13E1" << endl;
    std::cout << "Fazer modificacoes na classe Contato" << endl;
    std::cout << "para lidar com qualquer quantidade de telefones, menor que 10." << endl;
    std::cout << "Incluir testes para essa nova caracteristica." << endl;
    std::cout << "DICA: Guardar a quantidade de telefones e, separadamente, os telefones em arranjo." << endl;
    std::cout << endl;
    exemplo13E1a();
}

void exemplo13E2()
{
    IO_clrscr();
    std::cout << "Exemplo13E2" << endl;
    std::cout << "Fazer modificacoes na classe Contato" << endl;
    std::cout << "para lidar tambem com enderecos (residencial e profissional)." << endl;
    std::cout << "Incluir testes para essa nova caracteristica." << endl;
    std::cout << "DICA: Guardar separadamente o endereco residencial e o profissional." << endl;
    std::cout << endl;
    exemplo13E2a();
}