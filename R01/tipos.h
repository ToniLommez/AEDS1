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