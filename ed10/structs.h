/*
 * --------------------------------------------------------------------------------------------------------
 * 771157- Marcos Antonio Lommez Candido Ribeiro
 * 16/06/2022
 * 
 * Esta biblioteca foi criada a partir dos exemplos citados no guia 2022-1_aed1_ed10
 * mais melhorias feitas a partir da necessidade gerada pelos metodos
 * exemplo:
 * somar(), decrescente(), multiplicarMatriz(), somarMatriz(), identidadeMatriz() ...
 * 
 * --------------------------------------------------------------------------------------------------------
*/

#include "io.h" // para definicoes proprias

/**
 Definicao de tipo arranjo com inteiros
 baseado em estrutura
*/
typedef struct s_int_Array
{
    int length;
    ints data;
    int ix;
} int_Array;
/**
 Definicao de referencia para arranjo com inteiros
 baseado em estrutura
*/
typedef int_Array *ref_int_Array;

/**
 Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/
typedef struct s_int_Matrix
{
    int rows;
    int columns;
    ints *data;
    int ix, iy;
} int_Matrix;

/**
 Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
*/
typedef int_Matrix *ref_int_Matrix;

/**
 new_int_Array - Reservar espaco para arranjo com inteiros
 @return referencia para arranjo com inteiros
 @param n - quantidade de datos
*/
ref_int_Array new_int_Array(int size)
{
    // reserva de espaco
    ref_int_Array tmpArray = (ref_int_Array)malloc(sizeof(int_Array));
    // estabelecer valores padroes
    if (tmpArray == NULL)
    {
        IO_printf("\nERRO: Falta espaco.\n");
    }
    else
    {
        tmpArray->length = 0;
        tmpArray->data = NULL;
        tmpArray->ix = -1;
        if (size > 0)
        {
            // guardar a quantidade de dados
            tmpArray->length = size;
            // reservar espaco para os dados
            tmpArray->data = (ints)malloc(size * sizeof(int));
            // definir indicador do primeiro elemento
            tmpArray->ix = 0;
        } // fim se
    }     // fim se
          // retornar referencia para espaco reservado
    return (tmpArray);
} // fim

/**
 free_int_Array - Dispensar espaco para arranjo com inteiros
 @param tmpArray - referencia para grupo de valores inteiros
*/
void free_int_Array(ref_int_Array tmpArray)
{
    // testar se ha' dados, antes de reciclar o espaco
    if (tmpArray != NULL)
    {
        if (tmpArray->data != NULL)
        {
            free(tmpArray->data);
        } // fim se
        free(tmpArray);
    } // fim se
} // fim free_int_Array ( )

/**
 printIntArray - Mostrar arranjo com valores inteiros.
 @param array - grupo de valores inteiros
*/
void printIntArray(int_Array array)
{
    // mostrar valores no arranjo
    if (array.data)
    {
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // mostrar valor
            printf("%2d: %d\n", array.ix, array.data[array.ix]);
        } // fim repetir
    }     // fim se
} // printIntArray ( )

/**
 IO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com valores lidos
*/
int_Array IO_readintArray()
{
    // definir dados locais
    chars text = IO_new_chars(STR_SIZE);
    static int_Array array;
    // ler a quantidade de dados
    do
    {
        array.length = IO_readint("\nlength = ");
    } while (array.length <= 0);
    // reservar espaco para armazenar
    array.data = IO_new_ints(array.length);
    // testar se ha' espaco
    if (array.data == NULL)
    {
        array.length = 0; // nao ha' espaco
    }
    else
    {
        // ler e guardar valores em arranjo
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // ler valor
            strcpy(text, STR_EMPTY);
            array.data[array.ix] = IO_readint(IO_concat(
                IO_concat(text, IO_toString_d(array.ix)), " : "));
        } // fim repetir
    }     // fim se
          // retornar arranjo
    return (array);
} // IO_readintArray ( )

/**
 fprintIntArray - Gravar arranjo com valores inteiros.
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
void fprintIntArray(chars fileName, int_Array array)
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    // gravar quantidade de dados
    fprintf(arquivo, "%d\n", array.length);
    // gravar valores no arquivo, se existirem
    if (array.data)
    {
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // gravar valor
            fprintf(arquivo, "%d\n", array.data[array.ix]);
        } // fim repetir
    }     // fim se

    // fechar arquivo
    fclose(arquivo);
} // fprintIntArray ( )

/**
 freadArraySize - Ler tamanho do arranjo com valores inteiros.
 @return quantidade de valores lidos
 @param fileName - nome do arquivo
*/
int freadArraySize(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // testar a existencia
    if (arquivo)
    {
        // ler a quantidade de dados
        fscanf(arquivo, "%d", &n);
        if (n <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
            n = 0;
        } // fim se
        fclose(arquivo);
    } // fim se
      // retornar dados lidos
    return (n);
} // freadArraySize ( )

/**
 fIO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com os valores lidos
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
int_Array fIO_readintArray(chars fileName)
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");
    static int_Array array;
    // testar a existencia
    if (arquivo)
    {
        // ler a quantidade de dados
        fscanf(arquivo, "%d", &array.length);
        // testar se ha' dados
        if (array.length <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
            array.length = 0; // nao ha' dados
        }
        else
        {
            // reservar espaco
            array.data = IO_new_ints(array.length);
            // testar a existência
            if (array.data)
            {
                // ler e guardar valores em arranjo
                array.ix = 0;
                while (!feof(arquivo) &&
                       array.ix < array.length)
                {
                    // ler valor
                    fscanf(arquivo, "%d", &(array.data[array.ix]));
                    // passar ao proximo
                    array.ix = array.ix + 1;
                } // fim repetir
            }     // fim se
        }         // fim se
    }             // fim se
                  // retornar dados lidos
    return (array);
} // fIO_readintArray ( )

/**
 copyIntArray - Copiar arranjo com valores inteiros.
 @return referencia para copia do arranjo
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
ref_int_Array copyIntArray(int_Array array)
{
    // definir dados locais
    int x = 0;
    int y = 0;
    ref_int_Array copy;
    if (array.length <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
        array.length = 0;
    }
    else
    {
        // reservar area
        copy = new_int_Array(array.length);
        // testar se ha' descritor
        if (copy)
        {
            copy->length = array.length;
            copy->data = IO_new_ints(copy->length);
            // testar se ha' espaco e dados
            if (copy->data == NULL || array.data == NULL)
            {
                printf("\nERRO: Falta espaco ou dados.");
            }
            else
            {
                // ler e copiar valores
                for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
                {
                    // copiar valor
                    copy->data[array.ix] = array.data[array.ix];
                } // fim repetir
            }     // fim se
        }         // fim se
    }             // fim se
                  // retornar dados lidos
    return (copy);
} // copyIntArray ( )

/**
 new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
 @return referencia para arranjo com inteiros
 @param rows - quantidade de dados
 @param columns - quantidade de dados
*/
ref_int_Matrix new_int_Matrix(int rows, int columns)
{
    // reserva de espaco
    ref_int_Matrix tmpMatrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    // estabelecer valores padroes
    if (tmpMatrix != NULL)
    {
        tmpMatrix->rows = 0;
        tmpMatrix->columns = 0;
        tmpMatrix->data = NULL;
        // reservar espaco
        if (rows > 0 && columns > 0)
        {
            tmpMatrix->rows = rows;
            tmpMatrix->columns = columns;
            tmpMatrix->data=malloc(rows * sizeof(ints));
            if (tmpMatrix->data)
            {
                for (tmpMatrix->ix = 0;
                     tmpMatrix->ix < tmpMatrix->rows;
                     tmpMatrix->ix = tmpMatrix->ix + 1)
                {
                    tmpMatrix->data[tmpMatrix->ix] = (ints)malloc(columns * sizeof(int));
                } // fim repetir
            }     // fim se
        }         // fim se
        tmpMatrix->ix = 0;
        tmpMatrix->iy = 0;
    } // fim se
    return (tmpMatrix);
} // fim new_int_Matrix ( )

/**
 free_int_Matrix - Dispensar espaco para arranjo com inteiros
 @param tmpMatrix - referencia para grupo de valores inteiros
*/
void free_int_Matrix(ref_int_Matrix matrix)
{
    // testar se ha' dados
    if (matrix != NULL)
    {
        if (matrix->data != NULL)
        {
            for (matrix->ix = 0;
                 matrix->ix < matrix->rows;
                 matrix->ix = matrix->ix + 1)
            {
                free(matrix->data[matrix->ix]);
            } // fim repetir
            free(matrix->data);
        } // fim se
        free(matrix);
    } // fim se
} // fim free_int_Matrix ( )

/**
 printIntMatrix - Mostrar matrix com valores inteiros.
 @param array - grupo de valores inteiros
*/
void printIntMatrix(ref_int_Matrix matrix)
{
    // testar a existencia
    if (matrix != NULL && matrix->data != NULL)
    {
        // mostrar valores na matriz
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
            {
                // mostrar valor
                printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
            } // fim repetir
            printf("\n");
        } // fim repetir
    }     // fim se
} // printIntArray ( )

/**
 IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix IO_readintMatrix()
{
    // definir dados locais
    int rows = 0;
    int columns = 0;
    chars text = IO_new_chars(STR_SIZE);
    // ler a quantidade de dados
    do
    {
        rows = IO_readint("\nrows = ");
    } while (rows <= 0);
    do
    {
        columns = IO_readint("\ncolumns = ");
    } while (columns <= 0);
    // reservar espaco para armazenar valores
    ref_int_Matrix matrix = new_int_Matrix(rows, columns);
    // testar se ha' espaco
    if (matrix != NULL)
    {
        if (matrix->data == NULL)
        {
            // nao ha' espaco
            matrix->rows = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            // ler e guardar valores na matriz
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    // ler e guardar valor
                    strcpy(text, STR_EMPTY);
                    matrix->data[matrix->ix][matrix->iy] = IO_readint(IO_concat(
                        IO_concat(IO_concat(text, IO_toString_d(matrix->ix)), ", "),
                        IO_concat(IO_concat(text, IO_toString_d(matrix->iy)), " : ")));
                } // fim repetir
                printf("\n");
            } // fim repetir
        }     // fim se
    }         // fim se
              // retornar dados lidos
    return (matrix);
} // IO_readintMatrix ( )

/**
 fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 @param fileName - nome do arquivo
 @param matrix - grupo de valores inteiros
*/
void fprintIntMatrix(chars fileName, ref_int_Matrix matrix)
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    // testar se ha' dados
    if (matrix == NULL)
    {
        printf("\nERRO: Nao ha' dados.");
    }
    else
    {
        // gravar quantidade de dados
        fprintf(arquivo, "%d\n", matrix->rows);
        fprintf(arquivo, "%d\n", matrix->columns);

        if (matrix->data != NULL)
        {
            // gravar valores no arquivo
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    // gravar valor
                    fprintf(arquivo, "%d\n", matrix->data[matrix->ix][matrix->iy]);
                } // fim repetir
            }     // fim repetir
        }         // fim se
        // fechar arquivo
        fclose(arquivo);
    } // fim se
} // fprintIntMatrix ( )

/**
 freadintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
 @param fileName - nome do arquivo
*/
ref_int_Matrix freadintMatrix(chars fileName)
{
    // definir dados locais
    ref_int_Matrix matrix = NULL;
    int rows = 0;
    int columns = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    fscanf(arquivo, "%d", &rows);
    fscanf(arquivo, "%d", &columns);
    if (rows <= 0 || columns <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // reservar espaco para armazenar
        matrix = new_int_Matrix(rows, columns);
        // testar se ha' espaco
        if (matrix != NULL && matrix->data == NULL)
        {
            // nao ha' espaco
            matrix->rows = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            // testar a existência
            if (matrix != NULL)
            {
                // ler e guardar valores na matriz
                matrix->ix = 0;
                while (!feof(arquivo) && matrix->ix < matrix->rows)
                {
                    matrix->iy = 0;
                    while (!feof(arquivo) && matrix->iy < matrix->columns)
                    {
                        // guardar valor
                        fscanf(arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]));
                        // passar ao proximo
                        matrix->iy = matrix->iy + 1;
                    } // fim repetir
                    // passar ao proximo
                    matrix->ix = matrix->ix + 1;
                } // fim repetir
                matrix->ix = 0;
                matrix->iy = 0;
            } // fim se
        }     // fim se
    }         // fim se
              // retornar matriz lida
    return (matrix);
} // fim freadintMatrix ( )

/**
 copyIntMatrix - Copiar matriz com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix copyIntMatrix(ref_int_Matrix matrix)
{
    // definir dados locais
    ref_int_Matrix copy = NULL;
    if (matrix == NULL || matrix->data == NULL)
    {
        IO_printf("\nERRO: Faltam dados.\n");
    }
    else
    {
        if (matrix->rows <= 0 || matrix->columns <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
        }
        else
        {
            // reservar espaco
            copy = new_int_Matrix(matrix->rows, matrix->columns);
            // testar se ha' espaco e dados
            if (copy == NULL || copy->data == NULL)
            {
                printf("\nERRO: Falta espaco.");
            }
            else
            {
                // copiar valores
                for (copy->ix = 0; copy->ix < copy->rows; copy->ix = copy->ix + 1)
                {
                    for (copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1)
                    {
                        // copiar valor
                        copy->data[copy->ix][copy->iy] = matrix->data[copy->ix][copy->iy];
                    } // fim repetir
                }     // fim repetir
            }         // fim se
        }             // fim se
    }                 // fim se

    // retornar copia
    return (copy);
} // copyIntMatrix ( )


/**
 limitedRandomArray
*/
int_Array limitedRandomArray(int start, int end, int lines)
{
    // definir dados locais
    chars text = IO_new_chars(STR_SIZE);
    static int_Array array;
    // ler a quantidade de dados
    array.length = lines;
    // reservar espaco para armazenar
    array.data = IO_new_ints(array.length);
    // testar se ha' espaco
    if (array.data == NULL)
    {
        array.length = 0; // nao ha' espaco
    }
    else
    {
        // ler e guardar valores em arranjo
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // ler valor
            strcpy(text, STR_EMPTY);
            array.data[array.ix] = (start+rand()%(end-start+1));
        } // fim repetir
    }     // fim se
          // retornar arranjo
    return (array);
} // IO_readintArray ( )



bool isPresent(int value, int_Array array){
    if (array.data)
    {
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            if (array.data[array.ix] == value)
            {
                return true;
            }
        } // fim repetir
    }     // fim se
    return false;
}

bool comparar(int_Array array1, int_Array array2){
    bool iguais = true;
    if (array1.length != array2.length)
    {
        iguais = false;
    }
    else if (array1.data)
    {
        for (array1.ix = 0; array1.ix < array1.length; array1.ix = array1.ix + 1)
        {
            if (array1.data[array1.ix] != array2.data[array1.ix])
            {
                iguais = false;
            }
        } // fim repetir
    }     // fim se
    return iguais;
}

int_Array somar(int_Array array1, int constante, int_Array array2){
    if (array1.length != array2.length)
    {
        printf("Tamanhos incompativeis, retornando array1");
        return array1;
    }
    else
    {
        // definir dados locais
        static int_Array soma;
        // ler a quantidade de dados
        soma.length = array1.length;
        // reservar espaco para armazenar
        soma.data = IO_new_ints(soma.length);
        // testar se ha' espaco
        if (soma.data == NULL)
        {
            soma.length = 0; // nao ha' espaco
        }
        else
        {
            // guardar valores em arranjo
            for (soma.ix = 0, array1.ix = 0, array2.ix = 0; soma.ix < soma.length; soma.ix++, array1.ix++, array2.ix++)
            {
                soma.data[soma.ix] = array1.data[array1.ix] + (array2.data[array2.ix] * constante);
            } // fim repetir
        }     // fim se
        // retornar arranjo
        return (soma);
    }// fim se
}

bool crescente(int_Array array){
    bool crescente = true;
    if (array.length <= 0)
    {
        printf("Array invalido");
        crescente = false;
    }
    else if (array.data)
    {
        for (array.ix = 0; array.ix < (array.length-1); array.ix = array.ix + 1)
        {
            if (array.data[array.ix] > array.data[array.ix+1]){
                crescente = false;
            }
        } // fim repetir
    }     // fim se
    return crescente;
}

/**
 limitedRandomMatrix
*/
ref_int_Matrix limitedRandomMatrix(int start, int end, int rows, int columns)
{
    // reservar espaco para armazenar valores
    ref_int_Matrix matrix = new_int_Matrix(rows, columns);
    // testar se ha' espaco
    if (matrix != NULL)
    {
        if (matrix->data == NULL)
        {
            // nao ha' espaco
            matrix->rows = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            // guardar valores na matriz
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    // guardar valor
                    matrix->data[matrix->ix][matrix->iy] = (start+rand()%(end-start+1));
                } // fim repetir
                printf("\n");
            } // fim repetir
        }     // fim se
    }         // fim se
              // retornar dados lidos
    return (matrix);
}

ref_int_Matrix transpostaMatriz(ref_int_Matrix matrix)
{
    ref_int_Matrix transposta = NULL;
    if (matrix == NULL || matrix->data == NULL)
    {
        IO_printf("\nERRO: Faltam dados.\n");
    }
    else
    {
        if (matrix->rows <= 0 || matrix->columns <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
        }
        else
        {
            // reservar espaco
            transposta = new_int_Matrix(matrix->rows, matrix->columns);
            // testar se ha' espaco e dados
            if (transposta == NULL || transposta->data == NULL)
            {
                printf("\nERRO: Falta espaco.");
            }
            else
            {
                // transpor valores
                for (transposta->ix = 0; transposta->ix < transposta->rows; transposta->ix = transposta->ix + 1)
                {
                    for (transposta->iy = 0; transposta->iy < transposta->columns; transposta->iy = transposta->iy + 1)
                    {
                        // transpor valor
                        transposta->data[transposta->iy][transposta->ix] = matrix->data[transposta->ix][transposta->iy];
                    } // fim repetir
                }     // fim repetir
            }         // fim se
        }             // fim se
    }                 // fim se

    // retornar copia
    return (transposta);
}

ref_int_Matrix matrixOnlyZero()
{
    int rows = 3;
    int columns = 3;
    // reservar espaco para armazenar valores
    ref_int_Matrix matrix = new_int_Matrix(rows, columns);
    // testar se ha' espaco
    if (matrix != NULL)
    {
        if (matrix->data == NULL)
        {
            // nao ha' espaco
            matrix->rows = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            // guardar valores na matriz
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    // guardar valor
                    matrix->data[matrix->ix][matrix->iy] = 0;
                } // fim repetir
                printf("\n");
            } // fim repetir
        }     // fim se
    }         // fim se
              // retornar dados lidos
    return (matrix);
} // IO_readintMatrix ( )

bool zeroMatriz(ref_int_Matrix matrix){
    bool zeros = true;
    if (matrix->rows <= 0 || matrix->columns <= 0)
    {
        printf("matriz invalida");
        zeros = false;
    }
    else if (matrix->data)
    {
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
            {
                if (matrix->data[matrix->ix][matrix->iy] != 0)
                {
                    zeros = false;
                }
            } // fim repetir
        }     // fim repetir
    }     // fim se
    return zeros;
}

bool compararMatriz(ref_int_Matrix matrix1, ref_int_Matrix matrix2){
    bool iguais = true;
    if ((matrix1->rows != matrix2->rows) || (matrix1->columns != matrix2->columns))
    {
        iguais = false;
    }
    else if (matrix1->data)
    {
        for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix = matrix1->ix + 1)
        {
            for (matrix1->iy = 0; matrix1->iy < matrix1->columns; matrix1->iy = matrix1->iy + 1)
            {
                if (matrix1->data[matrix1->ix][matrix1->iy] != matrix2->data[matrix1->ix][matrix1->iy])
                {
                    iguais = false;
                }
            } // fim repetir
        }     // fim repetir
    }     // fim se
    return iguais;
}

ref_int_Matrix somarMatriz(ref_int_Matrix matrix1, int constante, ref_int_Matrix matrix2){
    if ((matrix1->rows != matrix2->rows) || (matrix1->columns != matrix2->columns))
    {
        printf("Tamanhos incompativeis, retornando matrix1");
        return matrix1;
    }
    else
    {
        int rows = matrix1->rows;
        int columns = matrix1->columns;
        // reservar espaco para armazenar valores
        ref_int_Matrix soma = new_int_Matrix(rows, columns);
        // testar se ha' espaco
        if (soma != NULL)
        {
            if (soma->data == NULL)
            {
                // nao ha' espaco
                soma->rows = 0;
                soma->columns = 0;
                soma->ix = 0;
                soma->iy = 0;
            }
            else
            {
                // guardar valores na matriz
                for (soma->ix = 0, matrix1->ix = 0, matrix2->ix =0; soma->ix < soma->rows; soma->ix++, matrix1->ix++, matrix2->ix++)
                {
                    for (soma->iy = 0, matrix1->iy = 0, matrix2->iy =0; soma->iy < soma->columns; soma->iy++, matrix1->iy++, matrix2->iy++)
                    {
                        // guardar valor
                        soma->data[soma->ix][soma->iy] = matrix1->data[matrix1->ix][matrix1->iy] + (matrix2->data[matrix2->ix][matrix2->iy] * constante);
                    } // fim repetir
                    printf("\n");
                } // fim repetir
            }     // fim se
        }         // fim se
                // retornar dados lidos
        return (soma);
    }// fim se
}

ref_int_Matrix multiplicarMatriz(ref_int_Matrix matrix1, ref_int_Matrix matrix2){
    if ((matrix1->rows != matrix2->rows) || (matrix1->columns != matrix2->columns))
    {
        printf("Tamanhos incompativeis, retornando matrix1");
        return matrix1;
    }
    else
    {
        int rows = matrix1->rows;
        int columns = matrix1->columns;
        // reservar espaco para armazenar valores
        ref_int_Matrix soma = new_int_Matrix(rows, columns);
        // testar se ha' espaco
        if (soma != NULL)
        {
            if (soma->data == NULL)
            {
                // nao ha' espaco
                soma->rows = 0;
                soma->columns = 0;
                soma->ix = 0;
                soma->iy = 0;
            }
            else
            {
                // guardar valores na matriz
                for (soma->ix = 0, matrix1->ix = 0, matrix2->ix =0; soma->ix < soma->rows; soma->ix++, matrix1->ix++, matrix2->ix++)
                {
                    for (soma->iy = 0, matrix1->iy = 0, matrix2->iy =0; soma->iy < soma->columns; soma->iy++, matrix1->iy++, matrix2->iy++)
                    {
                        // guardar valor
                        soma->data[soma->ix][soma->iy] = matrix1->data[matrix1->ix][matrix1->iy] * matrix2->data[matrix2->ix][matrix2->iy];
                    } // fim repetir
                    printf("\n");
                } // fim repetir
            }     // fim se
        }         // fim se
                // retornar dados lidos
        return (soma);
    }// fim se
}

int_Array decrescente(int_Array array1){
    if (array1.length <= 0)
    {
        printf("Tamanhos incompativeis, retornando array1");
        return array1;
    }
    else
    {
        // definir dados locais
        static ref_int_Array temp;
        temp = copyIntArray(array1);
        static int_Array descend;
        descend = *temp;

        // testar se ha' espaco
        if (descend.data == NULL)
        {
            descend.length = 0; // nao ha' espaco
        }
        else
        {
            int temp = 0;
            for (descend.ix = 0; descend.ix < descend.length; descend.ix++){
                for(int j = descend.ix+1; j < descend.length; j++){
                    if (descend.data[descend.ix] < descend.data[j]){
                        temp = descend.data[descend.ix];
                        descend.data[descend.ix] = descend.data[j];
                        descend.data[j] = temp;
                    }
                }
            }

        }     // fim se
        // retornar arranjo
        return (descend);
    }// fim se
}

bool identidadeMatriz(ref_int_Matrix matrix){
    bool ehIdentidade = true;
    if (matrix->rows <= 0 || matrix->columns <= 0)
    {
        printf("matriz invalida");
        ehIdentidade = false;
    }
    else if (matrix->data)
    {
        for (matrix->ix = 0, matrix->iy = 0; matrix->ix < matrix->rows; matrix->ix++, matrix->iy++) // diagonal principal
        {
            if (matrix->data[matrix->ix][matrix->iy] != 1)
            {
                ehIdentidade = false;
            }
        }     // fim repetir

        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1) // abaixo principal
        {
            for (matrix->iy = 0; matrix->iy < matrix->ix; matrix->iy = matrix->iy + 1)
            {
                if (matrix->data[matrix->ix][matrix->iy] != 0)
                {
                    ehIdentidade = false;
                }
            } // fim repetir
        }     // fim repetir

        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1) // abaixo principal
        {
            for (matrix->iy = (matrix->ix+1); matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
            {
                if (matrix->data[matrix->ix][matrix->iy] != 0)
                {
                    ehIdentidade = false;
                }
            } // fim repetir
        }     // fim repetir

    }     // fim se
    return ehIdentidade;
}