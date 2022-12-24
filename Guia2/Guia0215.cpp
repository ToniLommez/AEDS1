/*
Guia0215 - v0.0. - 27 / 03 / 2022
Author: Marcos Antonio Lommez Candido Ribeiro - 77157
Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0215 ./Guia0215.cpp
No Windows: g++ -o Guia0215.exe Guia0215.cpp
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0215
No Windows: Guia0215
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp" // para entradas e saídas
// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    world->set(2, 3, VWALL);
    world->set(2, 4, VWALL);
    world->set(2, 5, VWALL);
    world->set(2, 6, VWALL);
    world->set(2, 7, VWALL);
    world->set(2, 8, VWALL);

    world->set(3, 3, VWALL);
    world->set(3, 4, VWALL);
    world->set(3, 5, VWALL);
    world->set(3, 6, VWALL);
    world->set(3, 7, VWALL);

    world->set(4, 3, VWALL);
    world->set(4, 4, VWALL);
    world->set(4, 5, VWALL);
    world->set(4, 6, VWALL);
    world->set(4, 7, VWALL);

    world->set(5, 3, VWALL);
    world->set(5, 4, VWALL);
    world->set(5, 5, VWALL);
    world->set(5, 6, VWALL);
    world->set(5, 7, VWALL);
    world->set(5, 8, VWALL);

    world->set(3, 2, HWALL);
    world->set(4, 2, HWALL);
    world->set(5, 2, HWALL);

    world->set(3, 8, HWALL);
    world->set(5, 8, HWALL);

    // colocar um marcador no mundo
    world->set(3, 3, BEEPER);
    world->set(3, 4, BEEPER);
    world->set(3, 4, BEEPER);
    world->set(3, 5, BEEPER);
    world->set(3, 5, BEEPER);
    world->set(3, 5, BEEPER);

    world->set(4, 3, BEEPER);
    world->set(4, 4, BEEPER);
    world->set(4, 4, BEEPER);

    world->set(5, 3, BEEPER);
    // salvar a configuracao atual do mundo
    world->save(fileName);
} // decorateWorld ( )
/**
Classe para definir robo particular (MyRobot),
a partir do modelo generico (Robot)
Nota: Todas as definicoes irao valer para qualquer outro robo
criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
public:
    /**
    turnRight - Procedimento para virar 'a direita.
    */
    void turnRight()
    {
        // definir dado local
        int step = 0;
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for (step = 1; step <= 3; step = step + 1)
            {
                turnLeft();
            } // end for
        }     // end if
    }         // end turnRight ( )

    int pickBeepers()
    {
        // definir dado local
        int n = 0;
        // repetir (com teste no inicio)
        // enquanto houver marcador proximo
        while (nextToABeeper())
        {
            // coletar um marcador
            pickBeeper();
            // contar mais um marcador coletado
            n = n + 1;
        } // end while
        // retornar a quantidade de marcadores coletados
        return (n);
    } // end pickBeepers( )

    /**
     * execute - Metodo para executar um comando.
     * @param action - comando a ser executado
     */
    void execute(int option)
    {
        // executar a opcao de comando
        switch (option)
        {
        case 0: // terminar
            // nao fazer nada
            break;
        case 1: // virar para a esquerda
            if (leftIsClear())
            {
                turnLeft();
            } // end if
            break;
        case 2: // virar para o sul
            while (!facingSouth())
            {
                turnLeft();
            } // end while
            break;
        case 3: // virar para a direita
            if (rightIsClear())
            {
                turnRight();
            } // end if
            break;
        case 4: // virar para o oeste
            while (!facingWest())
            {
                turnLeft();
            } // end while
            break;
        case 5: // mover
            if (frontIsClear())
            {
                move();
            } // end if
            break;
        case 6: // virar para o leste
            while (!facingEast())
            {
                turnLeft();
            } // end while
            break;
        case 7: // pegar marcador
            if (nextToABeeper())
            {
                pickBeeper();
            } // end if
            break;
        case 8: // virar para o norte
            while (!facingNorth())
            {
                turnLeft();
            } // end while
            break;
        case 9: // colocar marcador
            if (beepersInBag())
            {
                putBeeper();
            } // end if
            break;
        default: // nenhuma das alternativas anteriores
            // comando invalido
            show_Error("ERROR: Invalid command.");
        } // end switch
    }     // end execute( )
    /**
     * moveI - Metodo para mover o robot interativamente.
     * Lista de comandos disponiveis:
     * 0 - turnOff
     * 1 - turnLeft 2 - to South
     * 3 - turnRight 4 - to West
     * 5 - move 6 - to East
     * 7 - pickBeeper 8 - to North
     * 9 - putBeeper
     */
    void moveI()
    {
        // definir dados
        int action;
        // repetir (com testes no fim)
        // enquanto opcao diferente de zero
        do
        {
            // ler opcao
            action = IO_readint("Command? ");
            // executar acao dependente da opcao
            execute(action);
        } while (action != 0);
    } // end moveI( )

    void putBeepers()
    {
        if (areYouHere(8, 1))
        {
            do
            {
                putBeeper();
            } while (beepersInBag() >= 1);
        } // fim se
    }

    void gravarArquivo(int x)
    {
        std::ofstream archive("Tarefa0215.txt", std::ios::app);
        archive << x << std::endl;
        archive.close();
    }

    void criarArquivo()
    {
        std::ofstream archive("Tarefa0215.txt");
    }

    /**
     * moveI - Metodo para mover o robot interativamente.
     * Lista de comandos disponiveis:
     * 0 - turnOff
     * 1 - turnLeft 2 - to South
     * 3 - turnRight 4 - to West
     * 5 - move 6 - to East
     * 7 - pickBeeper 8 - to North
     * 9 - putBeeper
     */

    void gravarAcoes()
    {
        criarArquivo();
        gravarArquivo(5);
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(3);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(3);
        gravarArquivo(5);
        // posicao central
        gravarArquivo(3);
        gravarArquivo(5);
        gravarArquivo(1);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(7); // pick
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(6);
        gravarArquivo(5);
        gravarArquivo(2);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(7); // pick
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(6);
        gravarArquivo(5);
        gravarArquivo(2);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(7); // pick
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(4);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(2);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(7); // pick
        gravarArquivo(7); // pick
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(3);
        gravarArquivo(5);
        gravarArquivo(2);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(7); // pick
        gravarArquivo(7); // pick
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(1);
        gravarArquivo(5);
        gravarArquivo(2);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(7); // pick
        gravarArquivo(7); // pick
        gravarArquivo(7); // pick
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(3);
        gravarArquivo(5);
        gravarArquivo(8);
        gravarArquivo(5);
        gravarArquivo(3);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(3);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(6);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(9);
        gravarArquivo(4);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(5);
        gravarArquivo(6);
        gravarArquivo(0);
    }

    /**
playActions - metodo para receber comandos de arquivo.
@param fileName - nome do arquivo
*/
    void playActions()
    {
        // definir dados
        int action;
        // definir arquivos de onde ler dados
        std::ifstream archive("Tarefa0215.txt");
        // repetir enquanto houver dados
        archive >> action;     // tentar ler a primeira linha
        while (!archive.eof()) // testar se nao encontrado o fim
        {
            // mostrar mais um comando
            IO_print(IO_toString(action));
            delay(stepDelay);
            // executar mais um comando
            execute(action);
            // tentar ler a proxima linha
            archive >> action; // tentar ler a próxima linha
        }                      // end for
        // fechar o arquivo
        // RECOMENDAVEL para a leitura
        archive.close();
    } // end playActions ( )
};    // end class MyRobot

// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/
int main()
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0215.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0215.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(1);                // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");
    // // executar tarefa
    robot->gravarAcoes();
    robot->playActions();

    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
// ---------------------------------------------- testes
//
// Versao Teste
// 0.1 01. ( OK ) teste inicial
// 0.2 01. ( OK ) teste da repeticao para virar 'a direita
// 0.3 01. ( OK ) teste da repeticao para percorrer um quadrado
//
