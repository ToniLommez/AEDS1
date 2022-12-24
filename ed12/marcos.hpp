#include "io.hpp"
#include <iostream>

bool eMaiuscula(char x)           { return (x >= 'A' && x <= 'Z'); }
bool eMinuscula(char x)           { return (x >= 'a' && x <= 'z'); }
bool eDigito(char x)              { return (x >= '0' && x <= '9'); }
bool eLetra(char x)               { return (eMaiuscula(x) || eMinuscula(x)); }
bool eAlfanumerico(char x)        { return (eLetra(x) || eDigito(x)); }
bool ePar(double x)               { return ((int)x%2==0); }
bool eLogico(char x)              { return (x == '&' || x == '|' || x == '!'); }
bool eAritmetico(char x)          { return (x == '+' || x == '-' || x == '*' || x == '/' || x == '%'); }
bool eRelacional(char x)          { return (x == '>' || x == '<' || x == '='); }
bool eSeparador(char x)           { return (x == ' ' || x == '.' || x == ',' || x == ';' || x == ':' || x == '_'); }
bool eOperador(char x)            { return (eLogico(x) || eAritmetico(x) || eRelacional(x)); }
bool eSimbolo(char x)             { return (!(eOperador(x) || eSeparador(x) || eAlfanumerico(x))); }

void flush(){
    while(getchar()!='\n');
}

int readIntNat(){
    int x;
    std::cin>>x;
    flush();
    if(x<=0){
        std::cout<<"\nDigite um numero maior que zero!";
        x=readIntNat();
    }
    return x;
}

int readIntNat(std::string s){
    int x;
    std::cout<<s;
    std::cin>>x;
    flush();
    if(x<=0){
        std::cout<<"\nDigite um numero maior que zero!";
        x=readIntNat();
    }
    return x;
}