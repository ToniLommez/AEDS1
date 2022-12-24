/*
 * -----------------------------------------------
 * Author: Marcos Antonio Lommez Candido Ribeiro
 * Matricula: 771157
 * Data: 17/06/2022
 * -----------------------------------------------
*/


// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_
// dependencias
#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
// outras dependencias
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )
#include "Erro.hpp"
// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar contatos, derivada da classe Erro.
 */
class Contato : public Erro
{
    /**
     * atributos privados.
     */
private:
    string nome;
    string fone[10];
    string enderecoResidencial;
    string enderecoProfissional;
    int quantosTelefones;

    void telefoneValido(string numero){
        if (numero[0] < 7 || !eDigito(numero[0]) || numero[5] != '-')
        {
            setErro(1); // valor invalido
        }
        else if (numero.length() != 10){
            setErro(3); // tamanho invalido
        }
        else if (!(eDigito(numero[1]) && eDigito(numero[2]) && eDigito(numero[3]) && eDigito(numero[4]) && eDigito(numero[6]) && eDigito(numero[7]) && eDigito(numero[8]) && eDigito(numero[9])))
        {
            setErro(1); // valor invalido
        }
        else{
            setErro(0);
        }
    }

    /**
     * definicoes publicas.
     */
public:
    ~Contato()
    {
    }
    
    Contato()
    {
        setErro(0); // nenhum erro, ainda
        // atribuir valores iniciais vazios
        nome = "";
        fone[0] = "";
        fone[1] = "";
        fone[2] = "";
        fone[3] = "";
        fone[4] = "";
        fone[5] = "";
        fone[6] = "";
        fone[7] = "";
        fone[8] = "";
        fone[9] = "";
        quantosTelefones = 0;
        enderecoResidencial = "";
        enderecoProfissional = "";
    } // fim construtor padrao

    // ----------------------------------- metodos para acesso
    void setNome(std::string nome)
    {
        if (nome.empty())
            setErro(1); // nome invalido
        else
            this->nome = nome;
    } // fim setNome ( )

    void setFone(std::string fone)
    {
        if (fone.empty())
            setErro(2); // fone invalido
        else
        {
            if (this->fone[0].empty())
            {
                quantosTelefones++;
            }
            this->fone[0] = fone;
        }
    } // fim setFone ( )

    void setFone2(std::string fone)
    {
        if (fone.empty())
            setErro(2); // fone invalido
        else
        {
            if (this->fone[0].empty())
            {
                setErro(3); // fone invalido
                cout << "fone 1 nao encontrado, cadastrando valor em fone 1" << endl;
                setFone(fone);
                return;
            }
            
            if (this->fone[1].empty())
            {
                quantosTelefones++;
            }
            this->fone[1] = fone;
        }
    } // fim setFone ( )

    void setFone(int x, std::string fone)
    {
        if (fone.empty())
            setErro(2); // fone invalido
        else
        {
            if (this->fone[x].empty())
            {
                quantosTelefones++;
            }
            this->fone[x] = fone;
        }
    } // fim setFone ( )

    void removeFone2()
    {
        if (this->fone[1].empty())
        {
            cout << "fone 2 nao existe" << endl;
            setErro(4); // operacao invalida
        }
        else
        {
            quantosTelefones--;
            fone[1].clear();
        }
    } // fim setFone ( )

    void setEnderecoResidencial(std::string endereco)
    {
        if (endereco.empty())
            setErro(1); // endereco invalido
        else
            this->enderecoResidencial = endereco;
    } // fim setEnderecoResidencial ( )

    void setEnderecoProfissional(std::string endereco)
    {
        if (endereco.empty())
            setErro(1); // endereco invalido
        else
            this->enderecoProfissional = endereco;
    } // fim setEnderecoProfissional ( )

    std::string getNome()
    {
        return (this->nome);
    } // fim getNome ( )

    std::string getFone(int n)
    {
        return (this->fone[n]);
    } // fim getFone ( )

    std::string getFone()
    {
        return (this->fone[0]);
    } // fim getFone ( )

    std::string getFone2()
    {
        return (this->fone[1]);
    } // fim getFone ( )

    std::string getEnderecoResidencial()
    {
        return (this->enderecoResidencial);
    } // fim getNome ( )

    std::string getEnderecoProfissional()
    {
        return (this->enderecoProfissional);
    } // fim getNome ( )

    int getQuantosTelefones()
    {
        return (this->quantosTelefones);
    } // fim getFone ( )

    std::string toString()
    {
        return ("{ " + getNome() + ", " + getFone(0) + ", " + getFone(1) + "}");
    } // fim toString ( )

    std::string toString2()
    {
        return ("{ " + getNome() + ", " + getFone(0) + ", " + getFone(1) + ", " + getFone(2) + ", " + getFone(3) + ", " + getFone(4) + ", " + getFone(5) + ", " + getFone(6) + ", " + getFone(7) + ", " + getFone(8) + ", " + getFone(9) + "}");
    } // fim toString ( )

    std::string toString3()
    {
        return ("{ " + getNome() + ", " + getFone(0) + ", " + getEnderecoResidencial() + ", " + getEnderecoProfissional() + "}");
    } // fim toString ( )

    Contato(std::string nome_inicial, std::string fone_inicial)
    {
        setErro(0); // nenhum erro, ainda
        // atribuir valores iniciais
        quantosTelefones = 0;
        setNome(nome_inicial); // nome = nome_inicial;
        setFone(fone_inicial); // fone = fone_inicial;
    }                          // fim construtor alternativo

    Contato(std::string nome_inicial, std::string fone_inicial, std::string fone2_inicial)
    {
        setErro(0); // nenhum erro, ainda
        // atribuir valores iniciais
        quantosTelefones = 0;
        setNome(nome_inicial); // nome = nome_inicial;
        setFone(fone_inicial); // fone = fone_inicial;
        setFone2(fone2_inicial); // fone2 = fone2_inicial;
    }                          // fim construtor alternativo

    bool hasErro()
    {
        return (getErro() != 0);
    } // end hasErro ( )

    Contato(Contato const &another)
    {
        // atribuir valores iniciais por copia
        setErro(0);            // copiar erro
        setNome(another.nome); // copiar nome
        setFone(another.fone[0]); // copiar fone
    }                          // fim construtor alternativo

    void readNome()
    {
        string temp = IO_readstring("Digite o nome:\n->");
        if (temp.empty())
            setErro(1); // nome invalido
        else
            {
            this->nome = temp;
            cout << "\nNome cadastrado com sucesso!\n" << endl;
            }
        if (getErro())
        {
            readNome();
        }
    }

    void readFone()
    {
        string temp = IO_readstring("Digite o telefone:\n->");
        if (temp.empty())
            setErro(1); // fone invalido
        else
            if (!getErro())
            {
                setFone(temp);
                cout << "\nNumero cadastrado com sucesso!\n" << endl;
            }
        if (getErro() == 1)
        {
            cout << "\nTelefone invalido!" << endl;
            readFone();
        }
    }

    void readFoneApenasValido()
    {
        string temp = IO_readstring("Digite o telefone (xxxxx-xxxx):\n->");
        telefoneValido(temp);
        if (temp.empty())
            setErro(1); // fone invalido
        else
            if (!getErro())
            {
                this->fone[0] = temp;
                cout << "\nNumero cadastrado com sucesso!\n" << endl;
            }
        if (getErro() == 1)
        {
            cout << "\nTelefone invalido!" << endl;
            readFoneValido();
        }
    }

    void readFoneValido()
    {
        string temp = IO_readstring("Digite o telefone (xxxxx-xxxx):\n->");
        telefoneValido(temp);
        if (temp.empty())
            setErro(1); // fone invalido
        else
            if (!getErro())
            {
                this->fone[0] = temp;
                cout << "\nNumero cadastrado com sucesso!\n" << endl;
                cout << "\nGostaria de cadastrar um segundo numero?\n" << endl;
                if (IO_readbool("[0] - nao\n[1] - sim\n-> "))
                {
                    readFone2Valido();
                }
            }
        if (getErro() == 1)
        {
            cout << "\nTelefone invalido!" << endl;
            readFoneValido();
        }
    }

    void readFone2Valido()
    {
        if (fone[0].empty())
        {
            readFoneValido();
            return;
        }
        string temp = IO_readstring("Digite o telefone (xxxxx-xxxx):\n->");
        telefoneValido(temp);
        if (temp.empty())
            setErro(1); // fone invalido
        else
            if (!getErro())
            {
                this->fone[1] = temp;
                cout << "\nSegundo numero cadastrado com sucesso!\n" << endl;
            }
        if (getErro() == 1)
        {
            cout << "\nTelefone invalido!" << endl;
            readFoneValido();
        }
    }

    int fromFile (string temp)
    {
        char *filename = &temp[0];
        FILE *file;
        if (file = fopen(filename, "r")) 
        {
            fclose(file);
            FILE *arquivo = fopen(filename, "r");
            char lixo[5];
            char nometemp[80];
            char fonetemp[11];
            char fone2temp[11];
            if (!feof(arquivo))
            {
                fscanf (arquivo, "%s", lixo); // jogando primeira linha fora
            }
            if (!feof(arquivo))
            {
                fscanf (arquivo, "%s", nometemp);
            }
            if (!feof(arquivo))
            {
                fscanf (arquivo, "%s", fonetemp);
            }
            if (!feof(arquivo))
            {
                fscanf (arquivo, "%s", fone2temp);
            }
            this->nome = nometemp;
            this->fone[0] = fonetemp;
            this->fone[1] = fone2temp;
            cout << "\nDados de 'Pessoa1.txt' cadastrados com sucesso!\n" << endl;
            fclose(arquivo);
        }
        else
        {
            cout << "Arquivo 'Pessoa1.txt' nao encontrado " << endl;
            setErro(1);
        }
        return getErro();
    }

    int toFile (string temp)
    {
        char *filename = &temp[0];
        FILE *arquivo = fopen(filename, "w");



        fprintf(arquivo, "3\n");
        fprintf(arquivo, "%s\n", nome.c_str());
        fprintf(arquivo, "%s\n", fone[0].c_str());
        fprintf(arquivo, "%s\n", fone[1].c_str());

        cout << "\nDados salvos com sucesso em 'Pessoa1.txt'!\n" << endl;
        fclose(arquivo);

        return getErro();
    }

    void variosTelefones(){
        int x;
        do
        {
            x = IO_readint("Quantos telefones quer cadastrar? (max = 10)\n->");
        } while (x < 1 || x > 10);
        string temp;
        for (int i = 0; i < x; i++)
        {
            temp = IO_readstring("Digite o telefone:\n->");
            if (temp.empty())
                setErro(1); // fone invalido
            else if (!getErro())
            {
                setFone(i, temp);
                cout << "Numero cadastrado com sucesso!\n" << endl;
            }
        }
    }
};                             // fim da classe Contato
using ref_Contato = Contato *; // similar a typedef Contato* ref_Contato;
#endif