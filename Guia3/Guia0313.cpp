/*
Guia0313 - v0.0. - 27 / 03 / 2022
Author: MARCOS ANTONIO LOMMEZ CANDIDO RIBEIRO 771157
Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0313 ./Guia0313.cpp
No Windows: g++ -o Guia0313.exe Guia0313.cpp
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0313
No Windows: Guia0313
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    world->set(2, 2, HWALL);
    world->set(3, 2, HWALL);
    world->set(4, 2, HWALL);
    world->set(5, 2, HWALL);
    world->set(6, 2, HWALL);
    world->set(7, 2, HWALL);

    world->set(5, 4, HWALL);
    world->set(6, 4, HWALL);
    world->set(4, 6, HWALL);
    world->set(6, 6, HWALL);

    world->set(3, 7, HWALL);
    world->set(4, 7, HWALL);
    world->set(5, 7, HWALL);
    world->set(6, 7, HWALL);
    world->set(7, 7, HWALL);

    world->set(2, 8, HWALL);
    world->set(3, 8, HWALL);
    world->set(4, 8, HWALL);
    world->set(5, 8, HWALL);
    world->set(6, 8, HWALL);
    world->set(7, 8, HWALL);

    world->set(1, 3, VWALL);
    world->set(1, 4, VWALL);
    world->set(1, 5, VWALL);
    world->set(1, 6, VWALL);
    world->set(1, 7, VWALL);
    world->set(1, 8, VWALL);

    world->set(2, 4, VWALL);
    world->set(2, 5, VWALL);
    world->set(2, 6, VWALL);
    world->set(2, 7, VWALL);

    world->set(3, 5, VWALL);
    world->set(3, 6, VWALL);

    world->set(4, 7, VWALL);
    world->set(5, 7, VWALL);

    world->set(6, 5, VWALL);
    world->set(6, 6, VWALL);

    world->set(7, 3, VWALL);
    world->set(7, 4, VWALL);
    world->set(7, 5, VWALL);
    world->set(7, 6, VWALL);
    world->set(7, 7, VWALL);

    // colocar um marcador no mundo
    world->set(4, 7, BEEPER);
    world->set(5, 7, BEEPER);
    world->set(5, 7, BEEPER);
    world->set(6, 7, BEEPER);
    world->set(6, 7, BEEPER);
    world->set(6, 7, BEEPER);

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
    /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
    void moveN(int steps)
    {
        // definir dado local
        int step = 0;
        // testar se a quantidade de passos e' maior que zero
        for (step = steps; step > 0; step = step - 1)
        {
            // dar um passo
            move();
        } // end if
    }     // end moveN( )
    /**
execute - Metodo para executar um comando.
@param action - comando a ser executado
*/
    int beeperNumber = 0;
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
            beeperNumber = 0;
            gravarArquivo(xAvenue());
            gravarArquivo(yStreet());
            while (nextToABeeper())
            {
                pickBeeper();
                beeperNumber = beeperNumber + 1;
            } // end while
            gravarArquivo(beeperNumber);
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
        case 10: // turnAround
            turnLeft();
            turnLeft();
            break;
        case 11: // turnAroundCornerLeft
            execute(6);
            execute(5);
            execute(1);
            execute(5);
            execute(1);
            execute(5);
            break;
        default: // nenhuma das alternativas anteriores
            // comando invalido
            show_Error("ERROR: Invalid command.");
        } // end switch
    }     // end execute( )

    void gravarArquivo(int x)
    {
        std::ofstream archive("Tarefa0313.txt", std::ios::app);
        archive << x << std::endl;
        archive.close();
    }

    void criarArquivo()
    {
        std::ofstream archive("Tarefa0313.txt");
    }
    /**
    metodo para executar comandos de arquivo.
    @param length - quantidade de comandos
    @param commands - grupo de comandos para executar
    */
    void doCommands()
    {
        criarArquivo();
        execute(6);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(1);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(1);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(1);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(1);
        execute(5);
        execute(1);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(7);
        execute(4);
        execute(5);
        execute(2);
        execute(5);
        execute(5);
        execute(5);
        execute(1);
        execute(5);
        execute(1);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(1);
        execute(5);
        execute(7);
        execute(10);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(1);
        execute(5);
        execute(1);
        execute(5);
        execute(5);
        execute(5);
        execute(1);
        execute(5);
        execute(5);
        execute(5);
        execute(1);
        execute(5);
        execute(7);
        execute(6);
        execute(5);
        execute(3);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(3);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(5);
        execute(6);
    } // end doCommands( )
    /**
readCommands - Metodo para receber comandos de arquivo.
@return grupo formado por todos os comandos
@param filename - nome do arquivo
*/
    int readCommands(int commands[], const char *fileName)
    {
        // definir dados
        int x = 0;
        int action = 0;
        int length = 0;
        std::ifstream archive(fileName);
        // obter a quantidade de comandos
        length = countCommands(fileName);
        // criar um armazenador para os comandos
        if (length < MAX_COMMANDS)
        {
            // repetir para a quantidade de comandos
            for (x = 0; x < length; x = x + 1)
            {
                // tentar ler a proxima linha
                archive >> action;
                // guardar um comando
                // na posicao (x) do armazenador
                commands[x] = action;
            } // end for
            // fechar o arquivo
            // INDISPENSAVEL para a gravacao
            archive.close();
        } // end for
        // retornar quantidade de comandos lidos
        return (length);
    } // end readCommands( )
    /**
countCommands - Funcao para contar comandos de arquivo.
@return quantidade de comandos
@param fileName - nome do arquivo
*/
    int countCommands(const char *fileName)
    {
        // definir dados
        int x = 0;
        int length = 0;
        std::ifstream archive(fileName);
        // repetir enquanto houver dados
        archive >> x; // tentar ler o primeiro
        while (!archive.eof())
        {
            // contar mais um comando
            length = length + 1;
            // tentar ler o proximo
            archive >> x;
        } // end while
        // fechar o arquivo
        archive.close();
        // retornar resultado
        return (length);
    } // end countCommands( )
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
    decorateWorld("Guia0313.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0313.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(1);                // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");
    // definir armazenador para comandos
    // executar tarefa
    robot->doCommands();
    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/