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
#include "Erro.hpp"
#include <climits>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <fstream>
#include <typeinfo>
using std::ifstream;
using std::ofstream;

/*
 * ----------------------------------
 *         Objeto myString
 * ----------------------------------
 */

class MyString : public Erro
{
private:
    string s = "";
    int length = 0;
    int chaveDeCriptografia = 0;
public:
    void setString(string temp)
    {
        s = temp;
        length = temp.length();
    }

    string getString()
    {
        return (s);
    }

    /**
     * Funcao para converter conteudo para valor inteiro, se possivel.
     * @return valor inteiro equivalente, se valido;
     * (-1), caso contrario
    */
    int retornarInteiro()
    {
        setErro(0);
        long long resultado = 0; // sera convertido para int no final para evitar overflow
        int pontoDecimal = 0;
        int localPontoDecimal = length;
        bool ePositivo = true;
        long long casas = 1;

        try
        {
            if (length == 0)
            {
                throw(6);
            }
            if (s[0] == '-') // testar sinal de negativo
            {
                ePositivo = false;
            }
            for (int i = length - 1; ePositivo ? i-- : (i--) - 1;) // testar se string possui nao numeros
            {
                if (!eDigito(s[i]) && s[i] != '.')
                {
                    throw(1);
                }
            }
            for (int i = length; i--;) // testar pontos decimais
            {
                if (s[i] == '.')
                {
                    pontoDecimal++;
                    localPontoDecimal = i;
                    if (pontoDecimal > 1)
                    {
                        throw(2);
                    }
                }
            }
            for (int i = localPontoDecimal + 1; i < length; i++) // testar se string e valida
            {
                if (s[i] != '0')
                {
                    throw(3);
                }
            }
            for (int i = localPontoDecimal; i--;) // converter string
            {
                if (s[i] != '-')
                    resultado += (s[i] - '0') * casas;
                if (resultado > INT_MAX)
                    throw(4);
                if (!ePositivo && resultado > INT_MAX - 1)
                {
                    throw(4);
                }

                casas *= 10;
            }
            if (resultado < 0 && ePositivo)
            {
                throw(4);
            }
        }
        catch (int error)
        {
            setErro(error);
            return -1;
        }
        int resultadoInteiro = (int)resultado;
        if (!ePositivo) // se for negativo inverter
            resultadoInteiro *= -1;
        return resultadoInteiro;
    }

    /**
     * Funcao para converter conteudo para valor real, se possivel.
     * @return valor real equivalente, se valido;
     * (0.0), caso contrario
    */
    double retornarDouble()
    {
        setErro(0);
        unsigned long long resultadoInteiro = 0; // sera convertido para double no final para evitar overflow
        double resultadoDecimal = 0;             // sera convertido para double no final para evitar overflow
        double resultado = 0;                    // sera convertido para double no final para evitar overflow
        int pontoDecimal = 0;
        int localPontoDecimal = length;
        bool ePositivo = true;
        long long casas = 1;

        try
        {
            if (length == 0)
            {
                throw(6);
            }
            if (s[0] == '-') // testar sinal de negativo
            {
                ePositivo = false;
            }
            for (int i = length - 1; ePositivo ? i-- : (i--) - 1;) // testar se string possui nao numeros
            {
                if (!eDigito(s[i]) && s[i] != '.')
                {
                    throw(1);
                }
            }
            for (int i = length; i--;) // testar pontos decimais
            {
                if (s[i] == '.')
                {
                    pontoDecimal++;
                    localPontoDecimal = i;
                    if (pontoDecimal > 1)
                    {
                        throw(2);
                    }
                }
            }
            for (int i = localPontoDecimal; i--;) // somar parte inteira
            {
                if (s[i] != '-')
                    resultadoInteiro += (s[i] - '0') * casas;
                if (resultadoInteiro > LLONG_MAX)
                    throw(4);
                if (!ePositivo && resultadoInteiro > LLONG_MAX - 1)
                {
                    throw(4);
                }
                casas *= 10;
            }
            if (resultadoInteiro < 0 && ePositivo)
            {
                throw(4);
            }
            for (int i = localPontoDecimal + 1, casas = 10; i < s.length(); i++)
            { // somar parte decimal
                resultadoDecimal += ((s[i] - 48.0) / (double)casas);
                casas *= 10;
            }
        }
        catch (int error)
        {
            setErro(error);
            return -1;
        }
        resultado = (double)resultadoInteiro + resultadoDecimal;
        if (!ePositivo) // se for negativo inverter
            resultado *= -1;
        return resultado;
    }

    /**
     * Funcao para converter conteudo para valor lógico, se possivel.
     * Nota: Considerar válidos: { true, false, T, F, 0, 1 }
     * @return valor logico equivalente, se valido;
     * false, caso contrario
    */
    bool retornarBoolean()
    {
        setErro(0);
        try
        {
            if (length == 0)
            {
                throw(6);
            }
            bool resultado = false;
            if (s == "true" || s == "T" || s == "t" || s == "1")
            {
                return true;
            }
            else if (s == "false" || s == "F" || s == "f" || s == "0")
            {
                return false;
            }
            else
            {
                throw(5);
            }
        }
        catch(int error)
        {
            setErro(error);
            return false;
        }
    }

    /**
     * Funcao para verificar se o parametro esta’ contido no conteudo.
     * @return true , se contiver (em qualquer posicao);
     * false, caso contrario
    */
    bool contains (string texto)
    {
        setErro(0);
        try
        {
            if (length == 0)
            {
                throw(6);
            }
            if (texto.length() == 0)
            {
                throw(7);
            }
            if (texto.length() > length)
            {
                throw(8);
            }
            

            if(length > 0 && texto.length() <= length){
                for(int i = 0, j = 0; i < length; i++){
                    if(s[i] == texto[j]){
                        j++;
                        
                        if(j == texto.length()){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        catch(int error)
        {
            setErro(error);
            return false;
        }
    }

    /**
    Funcao para converter letras para maiusculas.
    @return valor equivalente em maiusculas, se houver;
    o proprio valor, caso contrario
    */
    string retornarMaiuscula()
    {
        string s1 = s;
       
        try
        {
        if (length == 0)
        {
            throw(6);
        }
        
        int contador = 0;
        for (int i = 0; i < length; i++)
        {
            if (s1[i] >=  97 && s1[i] <= 122)
            {
                contador++;
                s1[i] -= 32;
            }
        }
        if (contador == 0)
        {
            throw(9);
        }
        }
        catch(int error)
        {
            setErro(error);
        }
        return s1;
    }

    /**
    Funcao para converter letras para minusculas.
    @return valor equivalente em minusculas, se houver;
    o proprio valor, caso contrario
    */
    string retornarMinuscula()
    {
        string s1 = s;
       
        try
        {
        if (length == 0)
        {
            throw(6);
        }
        
        int contador = 0;
        for (int i = 0; i < length; i++)
        {
            if (s1[i] >=  65 && s1[i] <= 90)
            {
                contador++;
                s1[i] += 32;
            }
        }
        if (contador == 0)
        {
            throw(9);
        }
        }
        catch(int error)
        {
            setErro(error);
        }
        return s1;
    }

    /**
    Funcao para trocar todas as ocorrencias de certo caractere por outro novo.
    @return valor com substituicoes, se houver;
    o proprio valor, caso contrario
    */
    string replace (char original, char novo)
    {
        string s1 = s;
       
        try
        {
        if (length == 0)
        {
            throw(6);
        }
        
        int contador = 0;
        for (int i = 0; i < length; i++)
        {
            if (s1[i] ==  original)
            {
                contador++;
                s1[i] = novo;
            }
        }
        if (contador == 0)
        {
            throw(10);
        }
        }
        catch(int error)
        {
            setErro(error);
        }
        return s1;
    }

    /**
    Funcao para separar todas as sequencias de caracteres separadas por espaços em branco.
    @param sequencia - arranjo para armazenar possiveis cadeias de caracteres identificadas
    @return quantidade de sequencias de caracteres identificadas, se houver;
    zero, caso contrario
    */
    int split (string sequencia[], int size)
    {
        setErro(0);
        int palavra = 0;
        int espacos = 0;
        try
        {
            if (length == 0)
            {
                throw(6);
            }
            int inicio;
            for (inicio = 0; s[inicio] == ' '; inicio++){}

            for (int i = inicio, j = 0; i < length; i++, j++)
            {
                if ((palavra + 1) > size)
                {
                    espacos--;
                    throw(11);
                }
                if (s[i] == ' ')
                {
                    palavra++;
                    espacos++;
                    // for (; i < length && s[i] == ' '; i++){}
                    j = -1;
                    continue;
                }
                sequencia[palavra] += s[i];
            }
        }
        catch(int error)
        {
            setErro(error);
            return 0;
        }
        return palavra+1;
    }
    
    /**
    Funcao para codificar o conteudo segundo a cifra de César (pesquisar).
    @return valor equivalente codificado, se houver;
    o proprio valor, caso contrario
    */
    string encrypt(){
        int x;
        string criptografia;
        try
        {
            if (length == 0)
            {
                throw(6);
            }
            cout << "Escolha um valor para ser a chave de criptografia" << endl;
            MyString temp;
            string temp2;
            cin >> temp2;
            temp.setString(temp2);
            chaveDeCriptografia = temp.retornarInteiro();
            for (int i = 0; i < length; i++)
            {
                if (eMaiuscula(s[i]))
                {
                    x = s[i] + chaveDeCriptografia;
                    while (x > 'Z')
                    {
                        x -= 26;
                    }
                    while (x < 'A')
                    {
                        x += 26;
                    }
                    criptografia += x;
                }
                else if (eMinuscula(s[i]))
                {
                    x = s[i] + chaveDeCriptografia;
                    while (x > 'z')
                    {
                        x -= 26;
                    }
                    while (x < 'a')
                    {
                        x += 26;
                    }
                    criptografia += x;
                }
                else if (eDigito(s[i]))
                {
                    x = s[i] + chaveDeCriptografia;
                    while (x > '9')
                    {
                        x -= 10;
                    }
                    while (x < '0')
                    {
                        x += 10;
                    }
                    criptografia += x;
                }
                else
                {
                    criptografia += s[i];
                }

            }
            s = criptografia;
        }
        catch(int error)
        {
            setErro(error);
            return s;
        }
        return criptografia;
    }

    /**
    Funcao para decodificar o conteudo previamente cifrado pela funcao acima.
    @return valor equivalente decodificado, se houver;
    o proprio valor, caso contrario
    */
    string decrypt(){
        int x;
        string decriptografia;
        try
        {
            if (length == 0)
            {
                throw(6);
            }
            if (chaveDeCriptografia == 0)
            {
                throw(12);
            }
            for (int i = 0; i < length; i++)
            {
                if (eMaiuscula(s[i]))
                {
                    x = s[i] - chaveDeCriptografia;
                    while (x > 'Z')
                    {
                        x -= 26;
                    }
                    while (x < 'A')
                    {
                        x += 26;
                    }
                    decriptografia += x;
                }
                else if (eMinuscula(s[i]))
                {
                    x = s[i] - chaveDeCriptografia;
                    while (x > 'z')
                    {
                        x -= 26;
                    }
                    while (x < 'a')
                    {
                        x += 26;
                    }
                    decriptografia += x;
                }
                else if (eDigito(s[i]))
                {
                    x = s[i] - chaveDeCriptografia;
                    while (x > '9')
                    {
                        x -= 10;
                    }
                    while (x < '0')
                    {
                        x += 10;
                    }
                    decriptografia += x;
                }
                else
                {
                    decriptografia += s[i];
                }

            }
            s = decriptografia;
        }
        catch(int error)
        {
            setErro(error);
            return s;
        }
        return decriptografia;
    }

    int splitPersonalizado (string sequencia[], int size, char delimitador)
    {
        setErro(0);
        int palavra = 0;
        int espacos = 0;
        try
        {
            if (length == 0)
            {
                throw(6);
            }
            int inicio;
            for (inicio = 0; s[inicio] == delimitador; inicio++){}

            for (int i = inicio, j = 0; i < length; i++, j++)
            {
                if ((palavra + 1) > size)
                {
                    espacos--;
                    throw(11);
                }
                if (s[i] == delimitador)
                {
                    palavra++;
                    espacos++;
                    // for (; i < length && s[i] == delimitador; i++){}
                    j = -1;
                    continue;
                }
                sequencia[palavra] += s[i];
            }
        }
        catch(int error)
        {
            setErro(error);
            return 0;
        }
        return palavra+1;
    }

    string invert(){
        string resultado = s;
        try
        {
            for (int i = 0, j = length-1; i <= j; i++,j--)
            {
                resultado[i] = resultado[j];
                resultado[j] = s[i];
            }
        }
        catch(int error)
        {
            setErro(error);
            return s;
        }
        return resultado;
    }


}; // fim classe MyString

/*
 * ----------------------------------
 *   Chamada dos metodos para teste
 * ----------------------------------
 */

void exemplo1411a()
{
    MyString s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
    s1.setString("1.0");
    s2.setString("-2.0");
    s3.setString("3.1");
    s4.setString("-4.1");
    s5.setString("2147483648");
    s6.setString("-2147483647");
    s7.setString("-abc");
    s8.setString("abc");
    s9.setString("1.1.2");
    cout << "String: " << s1.getString() << "            Inteiro: " << s1.retornarInteiro() << " " << s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "           Inteiro: " << s2.retornarInteiro() << " " << s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "            Inteiro: " << s3.retornarInteiro() << " " << s3.getErroMsg() << endl;
    cout << "String: " << s4.getString() << "           Inteiro: " << s4.retornarInteiro() << " " << s4.getErroMsg() << endl;
    cout << "String: " << s5.getString() << "     Inteiro: " << s5.retornarInteiro() << " " << s5.getErroMsg() << endl;
    cout << "String: " << s6.getString() << "    Inteiro: " << s6.retornarInteiro() << " " << s6.getErroMsg() << endl;
    cout << "String: " << s7.getString() << "           Inteiro: " << s7.retornarInteiro() << " " << s7.getErroMsg() << endl;
    cout << "String: " << s8.getString() << "            Inteiro: " << s8.retornarInteiro() << " " << s8.getErroMsg() << endl;
    cout << "String: " << s9.getString() << "          Inteiro: " << s9.retornarInteiro() << " " << s9.getErroMsg() << endl;
    cout << "String: " << s10.getString() << "               Inteiro: " << s10.retornarInteiro() << " " << s10.getErroMsg() << endl;
}

void exemplo1412a()
{
    MyString s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
    s1.setString("1.0");
    s2.setString("-2.0");
    s3.setString("3.1");
    s4.setString("-4.1");
    s5.setString("9223372036854775807");
    s6.setString("9223372036854775810");
    s7.setString("-9223372036854775808");
    s8.setString("-abc");
    s9.setString("abc");
    s10.setString("1.1.2");
    cout << "String: " << s1.getString() << "                     Double: " << s1.retornarDouble() << " " << s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "                    Double: " << s2.retornarDouble() << " " << s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "                     Double: " << s3.retornarDouble() << " " << s3.getErroMsg() << endl;
    cout << "String: " << s4.getString() << "                    Double: " << s4.retornarDouble() << " " << s4.getErroMsg() << endl;
    cout << "String: " << s5.getString() << "     Double: " << s5.retornarDouble() << " " << s5.getErroMsg() << endl;
    cout << "String: " << s6.getString() << "     Double: " << s6.retornarDouble() << " " << s6.getErroMsg() << endl;
    cout << "String: " << s7.getString() << "    Double: " << s7.retornarDouble() << " " << s7.getErroMsg() << endl;
    cout << "String: " << s8.getString() << "                    Double: " << s8.retornarDouble() << " " << s8.getErroMsg() << endl;
    cout << "String: " << s9.getString() << "                     Double: " << s9.retornarDouble() << " " << s9.getErroMsg() << endl;
    cout << "String: " << s10.getString() << "                   Double: " << s10.retornarDouble() << " " << s10.getErroMsg() << endl;
    cout << "String: " << s11.getString() << "                        Double: " << s11.retornarDouble() << " " << s11.getErroMsg() << endl;
}

void exemplo1413a()
{
    MyString s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
    s1.setString("true");
    s2.setString("false");
    s3.setString("T");
    s4.setString("F");
    s5.setString("t");
    s6.setString("f");
    s7.setString("1");
    s8.setString("0");
    s9.setString("abc");
    s10.setString("-1");
    cout << "String: " << s1.getString() << "     Boolean: " << s1.retornarBoolean() << " " << s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "    Boolean: " << s2.retornarBoolean() << " " << s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "        Boolean: " << s3.retornarBoolean() << " " << s3.getErroMsg() << endl;
    cout << "String: " << s4.getString() << "        Boolean: " << s4.retornarBoolean() << " " << s4.getErroMsg() << endl;
    cout << "String: " << s5.getString() << "        Boolean: " << s5.retornarBoolean() << " " << s5.getErroMsg() << endl;
    cout << "String: " << s6.getString() << "        Boolean: " << s6.retornarBoolean() << " " << s6.getErroMsg() << endl;
    cout << "String: " << s7.getString() << "        Boolean: " << s7.retornarBoolean() << " " << s7.getErroMsg() << endl;
    cout << "String: " << s8.getString() << "        Boolean: " << s8.retornarBoolean() << " " << s8.getErroMsg() << endl;
    cout << "String: " << s9.getString() << "      Boolean: " << s9.retornarBoolean() << " " << s9.getErroMsg() << endl;
    cout << "String: " << s10.getString() << "       Boolean: " << s10.retornarBoolean() << " " << s10.getErroMsg() << endl;
    cout << "String: " << s11.getString() << "         Boolean: " << s11.retornarBoolean() << " " << s11.getErroMsg() << endl;
}

void exemplo1414a()
{
    MyString s1;
    s1.setString("lorem ipsum dolor sit amet");
    cout << "String: " << s1.getString() << endl << endl;
    cout << "Procurando: dolor" << "       Possui: " << std::boolalpha << (s1.contains("dolor")?"Sim":"Nao") << " " << s1.getErroMsg() << endl;
    cout << "Procurando: sit amet" << "    Possui: " << std::boolalpha << (s1.contains("sit amet")?"Sim":"Nao") << " " << s1.getErroMsg() << endl;
    cout << "Procurando: teste" << "       Possui: " << std::boolalpha << (s1.contains("teste")?"Sim":"Nao") << " " << s1.getErroMsg() << endl;
    cout << "Procurando: " << "            Possui: " << std::boolalpha << (s1.contains("")?"Sim":"Nao") << " " << s1.getErroMsg() << endl;
}

void exemplo1415a()
{
    MyString s1, s2, s3, s4, s5;
    s1.setString("lorem ipsum");
    s2.setString("LoReM iPsUm");
    s3.setString("LOREM IPSUM");
    s4.setString("12345678abc");
    s5.setString("");
    cout << "String: " << s1.getString() << "        Maiuscula: " << s1.retornarMaiuscula() << " " << s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "        Maiuscula: " << s2.retornarMaiuscula() << " " << s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "        Maiuscula: " << s3.retornarMaiuscula() << " " << s3.getErroMsg() << endl;
    cout << "String: " << s4.getString() << "        Maiuscula: " << s4.retornarMaiuscula() << " " << s4.getErroMsg() << endl;
    cout << "String: " << s5.getString() << "                   Maiuscula:" << s5.retornarMaiuscula() << " " << s5.getErroMsg() << endl;
}

void exemplo1416a()
{
    MyString s1, s2, s3, s4, s5;
    s1.setString("lorem ipsum");
    s2.setString("LoReM iPsUm");
    s3.setString("LOREM IPSUM");
    s4.setString("12345678ABC");
    s5.setString("");
    cout << "String: " << s1.getString() << "        Minuscula: " << s1.retornarMinuscula() << " " << s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "        Minuscula: " << s2.retornarMinuscula() << " " << s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "        Minuscula: " << s3.retornarMinuscula() << " " << s3.getErroMsg() << endl;
    cout << "String: " << s4.getString() << "        Minuscula: " << s4.retornarMinuscula() << " " << s4.getErroMsg() << endl;
    cout << "String: " << s5.getString() << "                   Minuscula:" << s5.retornarMinuscula() << " " << s5.getErroMsg() << endl;
}

void exemplo1417a()
{
    MyString s1, s2, s3;
    s1.setString("aaaa cccc dddd");
    s2.setString("ffff cccc dddd");
    s3.setString("");
    cout << "String: " << s1.getString() << "     substituindo a por b: " << s1.replace('a', 'b') << " " << s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "     substituindo a por b: " << s2.replace('a', 'b') << " " << s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "                   substituindo a por b:" << s3.replace('a', 'b') << " " << s3.getErroMsg() << endl;
}

void exemplo1418a()
{
    MyString s1, s2, s3, s4;
    s1.setString("aaaa bbbb cccc");
    s2.setString("  dddd eeee ffff");
    s3.setString("gggg hhhh iiii");
    s4.setString("");
    string a1[3];
    string a2[3];
    string a3[2];
    string a4[2];
    cout << "String: " << s1.getString() << "         palavras: " <<               s1.split(a1, 3) << " {" << a1[0] << ", " << a1[1] << ", "<< a1[2] << "}"<< s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "       palavras: " <<                 s2.split(a2, 3) << " {" << a2[0] << ", " << a2[1] << ", "<< a2[2] << "}"<< s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "         palavras: " <<               s3.split(a3, 2) << " " << s3.getErroMsg() << endl;
    cout << "String: " << s4.getString() << "                       palavras: " << s4.split(a4, 2) << " " << s4.getErroMsg() << endl;
}

void exemplo1419a()
{
    MyString s1;
    s1.setString("Lorem Ipsum 1289");
    cout << "String: " << s1.getString() << endl;
    string criptografia = s1.encrypt();
    cout << "Criptografado: " << s1.getString() << endl;
    flush();
}

void exemplo1420a()
{
    MyString s1;
    s1.setString("Lorem Ipsum 1289");
    cout << "String: " << s1.getString() << endl;
    s1.encrypt();
    cout << "Criptografado: " << s1.getString() << endl;
    flush();
    s1.decrypt();
    cout << "Descriptografado: " << s1.getString() << endl;
}

void exemplo14E1a()
{
    MyString s1, s2, s3, s4;
    s1.setString("aaaa;bbbb;cccc");
    s2.setString("  dddd{eeee{ffff");
    s3.setString("gggg}hhhh}iiii");
    s4.setString("");
    string a1[3];
    string a2[3];
    string a3[2];
    string a4[2];
    cout << "String: " << s1.getString() << "         delimitador: ;" <<               "    palavras: " <<s1.splitPersonalizado(a1, 3, ';') << " {" << a1[0] << ", " << a1[1] << ", "<< a1[2] << "}"<< s1.getErroMsg() << endl;
    cout << "String: " << s2.getString() << "       delimitador: {" <<                 "    palavras: " <<s2.splitPersonalizado(a2, 3, '{') << " {" << a2[0] << ", " << a2[1] << ", "<< a2[2] << "}"<< s2.getErroMsg() << endl;
    cout << "String: " << s3.getString() << "         delimitador: }" <<               "    palavras: " <<s3.splitPersonalizado(a3, 2, '}') << " " << s3.getErroMsg() << endl;
    cout << "String: " << s4.getString() << "                       delimitador: ." << "    palavras: " <<s4.splitPersonalizado(a4, 2, '.') << " " << s4.getErroMsg() << endl;
}

void exemplo14E2a()
{
    MyString s1;
    s1.setString("abcd1234");
    cout << "String: " << s1.getString() << "    invertida:" << s1.invert() << " " << s1.getErroMsg() << endl;
}

/*
 * ----------------------------------
 *             Enunciados
 * ----------------------------------
 */

void exemplo1411()
{
    IO_clrscr();
    std::cout << "Exemplo1411" << endl;
    std::cout << "Funcao para converter conteudo para valor inteiro, se possivel." << endl;
    std::cout << "@return valor inteiro equivalente, se valido;" << endl;
    std::cout << "(-1), caso contrario" << endl;
    std::cout << endl;
    exemplo1411a();
}

void exemplo1412()
{
    IO_clrscr();
    std::cout << "Exemplo1412" << endl;
    std::cout << "Funcao para converter conteudo para valor real, se possivel." << endl;
    std::cout << "@return valor real equivalente, se valido;" << endl;
    std::cout << "(0.0), caso contrario" << endl;
    std::cout << endl;
    exemplo1412a();
}

void exemplo1413()
{
    IO_clrscr();
    std::cout << "Exemplo1413" << endl;
    std::cout << "Funcao para converter conteudo para valor logico, se possivel." << endl;
    std::cout << "Nota: Considerar válidos: { true, false, T, F, 0, 1 }" << endl;
    std::cout << "@return valor logico equivalente, se valido;" << endl;
    std::cout << "false, caso contrario" << endl;
    std::cout << endl;
    exemplo1413a();
}

void exemplo1414()
{
    IO_clrscr();
    std::cout << "Exemplo1414" << endl;
    std::cout << "Funcao para verificar se o parametro esta' contido no conteudo." << endl;
    std::cout << "@return true , se contiver (em qualquer posicao);" << endl;
    std::cout << "false, caso contrario" << endl;
    std::cout << endl;
    exemplo1414a();
}

void exemplo1415()
{
    IO_clrscr();
    std::cout << "Exemplo1415" << endl;
    std::cout << "Funcao para converter letras para maiusculas." << endl;
    std::cout << "@return valor equivalente em maiusculas, se houver;" << endl;
    std::cout << "o proprio valor, caso contrario" << endl;
    std::cout << endl;
    exemplo1415a();
}

void exemplo1416()
{
    IO_clrscr();
    std::cout << "Exemplo1416" << endl;
    std::cout << "Funcao para converter letras para minusculas." << endl;
    std::cout << "@return valor equivalente em minusculas, se houver;" << endl;
    std::cout << "o proprio valor, caso contrario" << endl;
    std::cout << "" << endl;
    std::cout << endl;
    exemplo1416a();
}

void exemplo1417()
{
    IO_clrscr();
    std::cout << "Exemplo1417" << endl;
    std::cout << "Funcao para trocar todas as ocorrencias de certo caractere por outro novo." << endl;
    std::cout << "@return valor com substituicoes, se houver;" << endl;
    std::cout << "o proprio valor, caso contrario" << endl;
    std::cout << endl;
    exemplo1417a();
}

void exemplo1418()
{
    IO_clrscr();
    std::cout << "Exemplo1418" << endl;
    std::cout << "Funcao para separar todas as sequencias de caracteres separadas por espacos em branco." << endl;
    std::cout << "@param sequencia - arranjo para armazenar possiveis cadeias de caracteres identificadas" << endl;
    std::cout << "@return quantidade de sequencias de caracteres identificadas, se houver;" << endl;
    std::cout << "zero, caso contrario" << endl;
    std::cout << endl;
    exemplo1418a();
}

void exemplo1419()
{
    IO_clrscr();
    std::cout << "Exemplo1419" << endl;
    std::cout << "Funcao para codificar o conteudo segundo a cifra de Cesar (pesquisar)." << endl;
    std::cout << "@return valor equivalente codificado, se houver;" << endl;
    std::cout << "o proprio valor, caso contrario" << endl;
    std::cout << endl;
    exemplo1419a();
}

void exemplo1420()
{
    IO_clrscr();
    std::cout << "Exemplo1420" << endl;
    std::cout << "Funcao para decodificar o conteudo previamente cifrado pela funcao acima." << endl;
    std::cout << "@return valor equivalente decodificado, se houver;" << endl;
    std::cout << "o proprio valor, caso contrario" << endl;
    std::cout << endl;
    exemplo1420a();
}

void exemplo14E1()
{
    IO_clrscr();
    std::cout << "Exemplo14E1" << endl;
    std::cout << "Acrescentar um metodo (e testes) para fragmentar o conteudo" << endl;
    std::cout << "usando um delimitador a escolha, diferente de espaco em branco." << endl;
    std::cout << endl;
    exemplo14E1a();
}

void exemplo14E2()
{
    IO_clrscr();
    std::cout << "Exemplo14E2" << endl;
    std::cout << "Acrescentar um metodo (e testes) para inverter a ordem dos simbolos na cadeia de caracteres." << endl;
    std::cout << endl;
    exemplo14E2a();
}
