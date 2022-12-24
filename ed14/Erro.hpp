

/**
 * Classe para tratar erro.
 */
#ifndef _ERRO_H_
#define _ERRO_H_
class Erro
{
    /*
    * tratamento de erro.
    Codigos de erro:
    0. Nao ha' erro.
    */
    /**
     * atributos privados.
     */
private:
    int erro;

protected:
    // ------------------------------------------- metodos para acesso restrito
    /**
    * Metodo para estabelecer novo codigo de erro.
    @param codigo de erro a ser guardado
    */
    void setErro(int codigo)
    {
        erro = codigo;
    } // end setErro ( )
    /**
     * definicoes publicas.
     */
public:
    /**
     * Destrutor.
     */
    ~Erro()
    {
    }
    /**
     * Construtor padrao.
     */
    Erro()
    {
        // atribuir valor inicial
        erro = 0;
    } // fim construtor padrao
    // ------------------------------------------- metodos para acesso
    /**
    * Funcao para obter o codigo de erro.
    @return codigo de erro guardado
    */
    int getErro()
    {
        return (erro);
    } // end getErro ( )
    virtual std::string getErroMsg()
    {
        switch (getErro())
        {
        case 0:
            return ("");
        case 1:
            return ("Erro: valor nao e numero");
        case 2:
            return ("Erro: sintaxe incorreta");
        case 3:
            return ("Erro: conversao com perda de precisao");
        case 4:
            return ("Erro: overflow");
        case 5:
            return ("Erro: valor nao e booleano");
        case 6:
            return ("Erro: teste em string vazia");
        case 7:
            return ("Erro: parametro invalido");
        case 8:
            return ("Erro: tamanho incompativel");
        case 9:
            return ("Erro: sem valor para converter");
        case 10:
            return ("Erro: valor nao encontrado");
        case 11:
            return ("Erro: array de tamanho insuficiente");
        case 12:
            return ("Erro: sem chave de criptografia cadastrada");
        default:
            return ("Erro Desconhecido ");
        }
    } // end getErroMsg ( )
};    // fim da classe Erro
#endif