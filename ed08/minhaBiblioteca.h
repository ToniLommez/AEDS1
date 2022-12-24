#include "io.h"
#include <sys/stat.h>

const int MAX_SIZE = 100;

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

int readArraySize ( chars text ){
    int x = 0;
    IO_printf ( text );
    IO_scanf  ( "%d", &x );
    getchar   ( );
    while (x <= 0 || x > MAX_SIZE)
    {
        IO_printf ("Valor invalido, digite novamente\n");
        IO_printf ( text );
        IO_scanf  ( "%d", &x );
        getchar   ( );
    }
    return    ( x );
}


// Descobrir tamanho de um array pelo primeiro valor no arquivo
// 
// Parametros:
// 1 - Nome do arquivo
// 2 - O Array
int readArrayfSize (char filename[]){
    int n = 0;
    FILE *arquivo = fopen (filename, "rt");
    fscanf(arquivo, "%d", &n);
    fclose(arquivo);
    return (n);
}



// Inicializar
// 
// Parametros:
// 1 - Opcao (1 -crescente; 2 - decrescente; 3 - aleatorio)
// 2 - Tamanho do array
// 3 - O array
void intArray_init (int option, int length, int array[]){
    srand(time(0));
	for(int k=0; k<length; k++){
        switch (option){
        case 1:
            array[k] = k;
            break;
        case 2:
            array[k] = length - k;
            break;
        case 3:
            array[k] = (rand() % 100);
            break;
        
        default:
            array[k] = 0;
            break;
        }
	}
}   


// Mostrar
// 
// Parametros:
// 1 - Tamanho do array
// 2 - O array
void intArray_print (int length, int array[]){
	for(int k=0; k<length; k++){
        printf("%d: %d\n", k, array[k]);
	}
}

// Testar se um arquivo existe
//
// Parametros:
// 1 - Nome do arquivo
//
// Funcao encontrada em: https://under-linux.org/showthread.php?t=65045
// por jweyrich
int fileExists(char *cpfileName)
{
    struct stat stStat;
    int errcode = stat (cpfileName, &stStat);
    if (errcode == ENOENT)
        return 0; /* nao existe */
    return 1; /* existe */
}


// Gravar
// 
// Parametros:
// 1 - Nome do arquivo
// 2 - Tamanho do array
// 3 - O array
void intArray_fprint (char filename[], int length, int array[]){
    FILE *arquivo = NULL;
    if (strlen(filename) <= 0){
        printf("\n[intarray] ERRO: Nome de arquivo invalido. \n");
    }
    else{
        FILE *arquivo = fopen (filename, "wt");
        fprintf(arquivo, "%d\n", length);
        for (int k = 0; k < length; k++)
        {
            fprintf(arquivo, "%d\n", array[k]);
        }
        fclose(arquivo);
    }
}


// Ler do arquivo
// 
// Parametros:
// 1 - Nome do arquivo
// 2 - Tamanho do array
// 3 - O array
void intArray_fscan (char filename[], int length, int array[]){
    int k = 0;
    int x = 0;
    int n = 0;
    FILE *arquivo = fopen (filename, "rt");
    fscanf(arquivo, "%d", &n);
    if (length >= n){
        while (!feof(arquivo) && k < length){
            fscanf(arquivo, "%d", &array[k]);
            k++;
        }
    }
    fclose(arquivo);
}


// Ler do arquivo
// 
// Parametros:
// 1 - Nome do arquivo
// 2 - Tamanho do array
// 3 - O array
void charArray_fscan (char filename[], int length, char array[][80]){
    int k = 0;
    int x = 0;
    int n = 0;
    FILE *arquivo = fopen (filename, "rt");
    fscanf(arquivo, "%d", &n);
    if (length >= n){
        while (!feof(arquivo) && k < length){
            fscanf(arquivo, "%c", &array[k]);
            k++;
        }
    }
    fclose(arquivo);
}


// Ler do teclado
// 
// Parametros:
// 1 - Tamanho do array
// 2 - O array
void intArray_scan (int length, int array[]){
    int x = 0;
	for(int k=0; k<length; k++){
        printf("-> ");
        scanf ("%d", &x);
        array[k] = x;
        getchar();
	}
}