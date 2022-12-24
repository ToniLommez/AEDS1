Ola theldo!

Para rodar o arquivo basta executar o programa ed04.c
os exercicios estao dentro da biblioteca menuExercicios.h


inclusive...

Eu acabei me empolgando bastante ao resolver o exercicio ed0420
e fiz algumas coisas alem do que foram pedidas nele, nao sei se voce ira ler o codigo alem de testar
mas caso voce leia vou deixar aqui a explicacao do que eu fiz

10.) Incluir um programa (Exemplo0420) um método para:
- ler certa quantidade de cadeias de caracteres do teclado;
- mostrar e contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra,
e calcular o total de todas as palavras, por meio de uma função.




nao soube como criar "n" strings, por isso tentei uma alternativa mais longa,
embora acabou sendo um processo bastante divertido no fim

andei estudando sobre a Maquina de Turing e tentei replicar algo parecido no algoritimo

eu criei uma variavel c[]
Ao escolher a quantidade de sequencia de caracteres para fazer o teste, eu armazenava em c[0]
a quantidade de palavras que seriam escritas

a partir dai, a cada vez que voce escreve uma palavra, voce adiciona em c[] essa palavra
ficando por exemplo assim:

>quantas palavras?
3
>quais palavras?
asd
ASDF
12345
>entao...
C[] = 3asdASDF12345

ao terminar de escrever uma palavra, é feito uma testagem para saber quantos digitos essa palavra tem
e no final do processo se adiciona no fim da string c[] 3 digitos que indicam onde na string cada palavra começa,
da seguinte forma:

asd comeca no digito 1
ASDF comeca no digito 4
12345 comeca no digito 8

entao neste exemplo c[] ficaria...
C[] = 3asdASDF12345001004008


a partir dai a funcao criada para a leitura das variaveis acaba e retorna a string c[]
entao é ativado outra funcao para mostrar os resultados pedidos na questão, e essa funcao recebe apenas a string c[]

quando essa funcao recebe a string c[], ela faz um processo de traducao da string
pega o primeiro digito e converte ele na quantidade de palavras a serem extraidas
sabendo a quantidade de palavras, o algoritimo agora sabe quantos digitos de endereco possuem no final da string,
neste exemplo sao 3 digitos de ponteiro, cada um com 3 caracteres: 001 004 008

entao ela faz a conversao das strings de 3 caracteres em um numero inteiro, 001 vira 1, 004 vira 4, 020 viraria 20
esses valores sao guardados num array de "ponteiro"

tendo entao o endereco de onde onde comeca cada palavra e quantas sao, o algoritimo cria um Buffer d[]
onde é armazenado a palavra a ser testada, entao o proprio Buffer é enviado para uma funcao que printa na tela
"mostrar e contar os alfanumericos na string"
em seguida o Buffer muda para o valor da proxima palavra, e entra novamente na funcao
sendo isto um loop for de iteracoes i(quantidade de palavras), k(tamanho da palavra)
d[k] = c[enderecoPalavra[i]+k];

por fim "C[] = 3asdASDF12345001004008" é convertido pelo algoritimo em:

Sequencia: asd
Caracteres alfanumericos: asd
Quantidade de alfanumericos: 3

Sequencia: ASDF
Caracteres alfanumericos: ASDF
Quantidade de alfanumericos: 4

Sequencia: 12345
Caracteres alfanumericos: 12345
Quantidade de alfanumericos: 5


alem disso tem a iteracao de calcular o total de alfanumerico que é feita paralelamente pela funcao
INT contarAlfanumericos2(), que vai somando dentro da propria variavel os valores retornados pelas funcoes que
retornam "Quantidade de alfanumericos: "



me desculpe se tudo isso soou confuso, fico muito feliz e grato caso tenha lido ate aqui, me esforcei muito
pra concluir e fazer este algoritimo, afinal, quero ser um cientista da computacao :)