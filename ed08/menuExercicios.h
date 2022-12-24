#include "io.h"
#include "minhaBiblioteca.h"

// Funcoes de uso geral do exercicio
int gerarAleatorio(int inicio, int fim){
    return (inicio + (rand() % ((fim-inicio)+1)));
}
void criarRandomTxt(){
    IO_printf("\nPara realizar esta questao sera criado um arquivo random.txt que ira conter valores aleatorios\n\n");
    int n = readArraySize("Digite o tamanho do array no txt\n->");
    int z[n];
    srand(time(0));
    IO_printf("\nEscolha o intervalo de numeros que o array ira abranger [inicio, fim]\n");
    int inicio = IO_readint("inicio -> ");
    int fim = IO_readint("fim -> ");
    for (int i = 0; i < n; i++){
        z[i] = gerarAleatorio(inicio, fim);
    }
    IO_printf("\nGerando arquivo random.txt com valores aleatorios...");
    intArray_fprint("random.txt", n, z);
    IO_printf("\nArquivo gerado com sucesso\n\n");
}

// Exercicio01
void exemplo0811a(){
    int n = readArraySize("n -> ");

    int x[n];
    for (int i = 0; i < n; i++){
        x[i] = IO_readint("x -> ");
        while (!(ePar(x[i])) || x[i] < 0){
            x[i] = IO_readint("Valor invalido, digite novamente\nx -> ");
        }        
    }
    IO_printf("\n\nValores armazenados:\n");
    intArray_print(n, x);
}

// Exercicio02
void exemplo0812a(char filename[], int length, int array[]){
    int k = 0;
    int x = 0;
    int n = 0;
    int i = 0;
    int temp = 0;
    FILE *arquivo = fopen (filename, "rt");
    fscanf(arquivo, "%d", &n);
    while (!feof(arquivo) && k < n){
        fscanf(arquivo, "%d", &temp);
        if (ePar(temp) && temp >= 0){
            array[i] = temp;
            i++;
        }
        k++;
    }
    fclose(arquivo);

    intArray_fprint("exemplo0812.txt", length, array); // guardar tamanho e elementos em arquivo
    IO_printf("Valores gravados em novo arquivo exemplo0812.txt\n");
}

// Exercicio03
void exemplo0813a(){
    srand(time(0));
    int inicio = IO_readint("inicio -> ");
    int fim = IO_readint("fim -> ");
    int length = IO_readint("length -> ");
    int array[length];
    for (int i = 0; i < length; i++){
        array[i] = gerarAleatorio(inicio, fim);
    }
    intArray_fprint("DADOS.txt", length, array);
    IO_printf("\nDADOS.txt gerado com sucesso\n\n");
}

// Exercicio04
int acharMenor(char filename[])
{
    int temp = 0;
    int menor = 0;
    int n = 0;
    if (!(fileExists(filename))){ // testar se arquivo existe
        return 0;
    }
    FILE *arquivo = fopen (filename, "rt");
    fscanf(arquivo, "%d", &n);
    if (n > 0)
        fscanf(arquivo, "%d", &menor);
    for (int i = 0; (!feof(arquivo) && i < n); i++){
        fscanf(arquivo, "%d", &temp);
        if (menor > temp){
            menor = temp;
        }
    }
    fclose(arquivo);
    return (menor);
}
void exemplo0814a(){
    criarRandomTxt();
    IO_printf("\nEste e o menor valor do array: %d", acharMenor("random.txt"));
}

// Exercicio05
int acharMaior(char filename[])
{
    int temp = 0;
    int maior = 0;
    int n = 0;
    if (!(fileExists(filename))){ // testar se arquivo existe
        return 0;
    }
    FILE *arquivo = fopen (filename, "rt");
    fscanf(arquivo, "%d", &n);
    if (n > 0)
        fscanf(arquivo, "%d", &maior);
    for (int i = 0; (!feof(arquivo) && i < n); i++){
        fscanf(arquivo, "%d", &temp);
        if (maior < temp){
            maior = temp;
        }
    }
    fclose(arquivo);
    return (maior);
}
void exemplo0815a(){
    criarRandomTxt();
    IO_printf("\nEste e o maior valor do array: %d", acharMaior("random.txt"));
}

// Exercicio06
double acharMedia(int n, int x[])
{
    int total = 0;
    double media = 0;
    for (int i = 0; i < n; i++){
        media += x[i];
        total++;
    }
    media = media/total;
    return (media);
}
void maioresQueAMedia(double media, int n, int x[]){
    FILE *arquivo = fopen ("DadosMaiores.txt", "wt");
    fprintf(arquivo, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        if (x[i] > media)
        {
            fprintf(arquivo, "%d\n", x[i]);
        }
    }
    fclose(arquivo);
}
void menoresQueAMedia(double media, int n, int x[]){
    FILE *arquivo = fopen ("DadosMenores.txt", "wt");
    fprintf(arquivo, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        if (x[i] < media)
        {
            fprintf(arquivo, "%d\n", x[i]);
        }
    }
    fclose(arquivo);
}
void exemplo0816a(){
    int n = readArrayfSize("DADOS.txt");
    IO_printf("%d", n);
    int x[n];
    intArray_fscan("DADOS.txt", n, x);
    double media = acharMedia(n, x);
    maioresQueAMedia(media, n, x);
    IO_printf("\nValores maiores que a media armazenados em DadosMaiores.txt");
    menoresQueAMedia(media, n, x);
    IO_printf("\nValores menores que a media armazenados em DadosMenores.txt");
}

// Exercicio07
bool estaDecrescente(int n, int x[]){
    bool estaDecrescente = true;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < x[i+1])
        {
            estaDecrescente = false;
        }
    }
    return(estaDecrescente);
}
void exemplo0817a(){
    IO_printf("Para testar esse metodo preciso que um array seja criado para testa-lo\n");
    int n = readArraySize("\nEscolha um tamanho para o array:\nn -> ");
    int x[n];
    IO_printf("\nEscolha os valores do array:\n");
    intArray_scan(n, x);
    IO_printf("\nO array %s", estaDecrescente(n, x) ? "esta decrescente" : "nao esta decrescente");
}

// Exercicio08
bool estaNoArray(int n, int inicial, int procurado, int x[]){
    for (int i = inicial; i < n; i++){
        if (x[i] == procurado)
            return(true);
    }
    return(false);
}
void exemplo0818a(){
    int n = readArrayfSize ("DADOS.txt");
    int x[n];
    intArray_fscan("DADOS.txt", n, x);
    int procurado = IO_readint("\nQual valor deve ser procurado?\n-> ");
    int inicial = IO_readint("\nProcurar a partir da posicao:\n-> ");
    while (inicial > n)
    {
        IO_printf("O valor inserido e maior do que o array a ser testado :(\nTente novamente:");
        inicial = IO_readint("\nProcurar a partir da posicao:\n-> ");
    }
    
    IO_printf("\nO valor %d %s", procurado, estaNoArray(n, inicial, procurado, x) ? "esta no array" : "nao esta no array");
}

// Exercicio09
void ondeEstaNoArray(int n, int inicial, int procurado, int x[]){
    bool naoEstaNoArray = true;
    for (int i = inicial; i < n; i++){
        if (x[i] == procurado){
            IO_printf("\nO valor %d esta na posicao [%d]", procurado, i);
            naoEstaNoArray = false;
        }
    }
    if (naoEstaNoArray)
    {
        IO_printf("\nO valor %d nao esta no array", procurado);
    }
}
void exemplo0819a(){
    int n = readArrayfSize ("DADOS.txt");
    int x[n];
    intArray_fscan("DADOS.txt", n, x);
    int procurado = IO_readint("\nQual valor deve ser procurado?\n-> ");
    int inicial = IO_readint("\nProcurar a partir da posicao:\n-> ");
    while (inicial > n)
    {
        IO_printf("O valor inserido e maior do que o array a ser testado :(\nTente novamente:");
        inicial = IO_readint("\nProcurar a partir da posicao:\n-> ");
    }
    ondeEstaNoArray(n, inicial, procurado, x);
}

// Exercicio10
int quantosEstaoNoArray(int n, int inicial, int procurado, int x[]){
    int quantos = 0;
    for (int i = inicial; i < n; i++){
        if (x[i] == procurado){
            IO_printf("\nO valor %d esta na posicao [%d]", procurado, i);
            quantos++;
        }
    }
    return(quantos);
}
void exemplo0820a(){
    int n = readArrayfSize ("DADOS.txt");
    int x[n];
    intArray_fscan("DADOS.txt", n, x);
    int procurado = IO_readint("\nQual valor deve ser procurado?\n-> ");
    int inicial = IO_readint("\nProcurar a partir da posicao:\n-> ");
    while (inicial > n)
    {
        IO_printf("O valor inserido e maior do que o array a ser testado :(\nTente novamente:");
        inicial = IO_readint("\nProcurar a partir da posicao:\n-> ");
    }
    IO_printf("\n\nO valor %d aparece %d vezes no array.", procurado, quantosEstaoNoArray(n, inicial, procurado, x));
}

// ExercicioE1
int divisores(int aDividir, int n, int x[], int y[]){
    int divisores = 0;
    for (int i = 0; i < n; i++){
        if (x[i] != 0){
            if (aDividir%x[i]==0){
                y[divisores] = x[i];
                divisores++;
            }
        }
    }
    intArray_fprint ("divisores.txt", divisores, y);
    IO_printf("\nO arquivo divisores.txt foi criado com sucesso.\n");
    return(divisores);
}
void exemplo08E1a(){
    criarRandomTxt();
    int n = readArrayfSize ("random.txt");
    int x[n];
    intArray_fscan("random.txt", n, x);
    int aDividir = IO_readint("\nQual valor deve ser testado?\n-> ");
    int y[n];
    int divisores2 = divisores(aDividir, n, x, y);
    IO_printf("\n\nO valor %d possui %d divisores no array.\nEstes divisores sao:\n", aDividir, divisores2);
    intArray_fprint ("divisores.txt", divisores2, y);
    int z[divisores2];
    intArray_fscan ("divisores.txt", divisores2, z);
    for (int i = 0; i < divisores2; i++){
        IO_printf("\n%d", z[i]);
    }
}

// ExercicioE2
void criarPalavrasTxt(){
    IO_printf("\nPara realizar esta questao sera criado um arquivo Palavras.txt que ira conter palavras aleatorias\n\n");
    int n = readArraySize("Digite o tamanho do array no txt\n->");
    while (n < 15)
    {
        IO_printf("Valor muito pequeno, escolha algo maior\n");
        n = readArraySize("Digite o tamanho do array no txt\n->");
    }
    
    int x[n];
    IO_printf("\nGerando arquivo Palavras.txt com valores aleatorios...");
    FILE *arquivo = fopen ("Palavras.txt", "wt");
    fprintf(arquivo, "%d\n", n);
    srand(time(0));
    for (int i = 0; i < n; i++) // tamanho do array
    {
        for (int j = 0; j < gerarAleatorio(3, 13); j++) // tamanho da palavra
        {
            if (gerarAleatorio(0, 1)){ // decidir Letter Case
                fprintf(arquivo, "%c", gerarAleatorio(65, 90));
            }
            else{
                fprintf(arquivo, "%c", gerarAleatorio(97, 122));
            }
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    IO_printf("\nArquivo gerado com sucesso\n\n");
}
void palavrasSemA(int* i, char* strings[]){
    char line[50];
    int k = *(i);
    int n = 0;
    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");
    fscanf(arquivo, "%d", &n);
    while(!feof(arquivo) && k < 11){
        fgets(line, sizeof line, arquivo);
        if (!(line[0] == 'a' || line[0] == 'A'))
        {
            strings[k] = strdup(line);
            k++;
        }
    }
    *(i) = k;
    fclose(arquivo);
}
void exemplo08E2a(){
    criarPalavrasTxt();
    char* strings[50];
    int i = 0;
    palavrasSemA(&i, strings);
    IO_printf("\n\nAs seguintes palavras sem 'a' ou 'A' foram encontradas:\n");

    for (int j = 0; j < (11 - (11-i)); j++)
        printf("%s", strings[j]);

}





void exemplo0811()
{
    IO_clrscr();
    IO_printf("Exemplo0811");
    IO_printf("\nLer o tamanho de um arranjo para inteiros do teclado,");
    IO_printf("\nbem como todos os seus elementos, garantindo que so tenha valores positivos e pares.");
    IO_printf("\nVerificar se o tamanho (ou dimensao) nao e nulo ou negativo.");
    IO_printf("\n\n");

    exemplo0811a();
}
void exemplo0812()
{
    IO_clrscr();
    IO_printf("Exemplo0812");
    IO_printf("\nLer um arranjo com inteiros positivos de arquivo.");
    IO_printf("\nValores negativos e tambem os impares deverao ser descartados.");
    IO_printf("\nO arranjo e o nome do arquivo serao dados como parametros.");
    IO_printf("\nGuardar, em arquivo primeiro o tamanho, depois os elementos, um dado por linha.");
    IO_printf("\n\n");
    criarRandomTxt();
    int n = readArraySize("Digite o tamanho do novo array\n ->");
    int x[n];
    intArray_init(0, n, x);
    exemplo0812a("random.txt", n, x);
}
void exemplo0813()
{
    IO_clrscr();
    IO_printf("Exemplo0813");
    IO_printf("\ngerar um valor inteiro aleatoriamente dentro de um intervalo, cujos limites de inicio e de fim serao recebidos como parametros");
    IO_printf("\nPara testar, ler os limites do intervalo do teclado; ler a quantidade de elementos ( N ) a serem gerados");
    IO_printf("\nGerar essa quantidade ( N ) de valores aleatorios dentro do intervalo e armazena-los em arranjo;");
    IO_printf("\nGrava-los, um por linha, em um arquivo ('DADOS.TXT').");
    IO_printf("\nA primeira linha do arquivo devera informar a quantidade de numeros aleatorios ( N ) que serao gravados em seguida");
    IO_printf("\n\n");
    exemplo0813a();
}
void exemplo0814()
{
    IO_clrscr();
    IO_printf("Exemplo0814");
    IO_printf("\nProcurar o menor valor em um arranjo");
    IO_printf("\nPara testar, receber um nome de arquivo como parametro e aplicar a funcao sobre o arranjo com os valores lidos;");
    IO_printf("\n\n");
    exemplo0814a();
}
void exemplo0815()
{
    IO_clrscr();
    IO_printf("Exemplo0815");
    IO_printf("\nProcurar o maior valor em um arranjo.");
    IO_printf("\nPara testar, receber um nome de arquivo como parametro e aplicar a funcao sobre o arranjo com os valores lidos;");
    IO_printf("\n\n");
    exemplo0815a();
}
void exemplo0816()
{
    IO_clrscr();
    IO_printf("Exemplo0816");
    IO_printf("\nDeterminar a media valores em um arranjo.");
    IO_printf("\nPara testar, ler o arquivo ('DADOS.TXT') armazenar os dados em um arranjo;");
    IO_printf("\nSeparar em dois outros arquivos, os valores maiores ou iguais a media, e os menores que ela");
    IO_printf("\n\n");
    exemplo0816a();
}
void exemplo0817()
{
    IO_clrscr();
    IO_printf("Exemplo0817");
    IO_printf("\nReceber como parametro um arranjo e dizer se esta ordenado, ou nao, em ordem decrescente");
    IO_printf("\n\n");
    exemplo0817a();
}
void exemplo0818()
{
    IO_clrscr();
    IO_printf("Exemplo0818");
    IO_printf("\nprocurar por determinado valor em arranjo e dizer se esse valor pode ser nele encontrado");
    IO_printf("\nindicada a posicao inicial para se comecar a procura. Para testar, ler o arquivo ('DADOS.TXT'),");
    IO_printf("\ne armazenar os dados em arranjo; ler do teclado um valor inteiro para ser procurado;");
    IO_printf("\ndeterminar se o valor procurado existe no arranjo, a partir da posicao indicada");
    IO_printf("\n\n");
    exemplo0818a();
}
void exemplo0819()
{
    IO_clrscr();
    IO_printf("Exemplo0819");
    IO_printf("\nProcurar por determinado valor em arranjo e dizer onde se encontra esse valor,");
    IO_printf("\nindicada a posicao inicial para comecar a procura. Para testar, ler o arquivo ('DADOS.TXT'),");
    IO_printf("\ne armazenar os dados em arranjo; ler do teclado um valor inteiro para ser procurado;");
    IO_printf("\nDeterminar onde o valor procurado estiver no arranjo, se houver");
    IO_printf("\n\n");
    exemplo0819a();
}
void exemplo0820()
{
    IO_clrscr();
    IO_printf("Exemplo0820");
    IO_printf("\nProcurar por determinado valor em arranjo e dizer quantas vezes esse valor pode ser encontrado,");
    IO_printf("\nindicada a posicao inicial para comecar a procura. Para testar, ler o arquivo ('DADOS.TXT'),");
    IO_printf("\ne armazenar os dados em arranjo; ler do teclado um valor inteiro para ser procurado");
    IO_printf("\nDeterminar quantas vezes o valor procurado aparece no arranjo, se ocorrer.");
    IO_printf("\n\n");
    exemplo0820a();
}
void exemplo08E1()
{
    IO_clrscr();
    IO_printf("Exemplo08E1");
    IO_printf("\nLer um valor inteiro do teclado,");
    IO_printf("\ne mediante funcoes para calcular e retornar a quantidade");
    IO_printf("\ne seus divisores guardados em arranjo,");
    IO_printf("\no qual devera ser mostrado na tela apos o retorno,");
    IO_printf("\nbem como gravado em arquivo ( 'DIVISORES.TXT' ).");
    IO_printf("\n\n");
    exemplo08E1a();
}
void exemplo08E2()
{
    IO_clrscr();
    IO_printf("Exemplo08E2");
    IO_printf("\nLer um arquivo ( 'PALAVRAS.TXT' )");
    IO_printf("\ne mediante uma funcao retornar as dez primeiras palavras");
    IO_printf("\nque nao comecem pela letra 'a' (ou 'A'), se houver.");
    IO_printf("\nAs palavras encontradas deverao ser exibidas na tela, apos retorno");
    IO_printf("\n\n");
    exemplo08E2a();
}