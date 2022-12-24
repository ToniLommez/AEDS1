/*
Exemplo0319 - v0.0. - 04/04/2022 Author: Vitória de Lourdes
*/

#include <stdio.h>
#include <string.h>
int main()
{
    double a = 0, b = 0;
    int contador = 0, c = 0, d = 0, f = 0;
    double n = 0;

    printf("%s\n", "Autor: Vitória de Lourdes");
    printf("\n"); // mudar de linha

    // ler o valor no teclado
    printf("Digite o primeiro numero do intervalo ");
    scanf("%lf", &a);

    printf("Digite o segundo do intervalo ");
    scanf("%lf", &b);

    printf("Digite a quantidade de numeros ");
    scanf("%lf", &n);

    double num[d];
    c = n;
    while (contador < n)
    {
        printf("Digite o numero (%d): ", d);
        scanf("%lf", &num[d]);
        contador = contador + 1;
        c = c - 1;
        d = d + 1;
    }

    d = 0;
    contador = 0;

    while (contador < n)
    {
        if (a < num[d] && b > num[d])
        {
            printf("%d-\t", contador);
            printf("O numero %lf pertence ao intervalo de [%lf : %lf]\n", num[d], a, b);

            if ((int)num[d] % 2 != 0.0)
            {
                printf("%d-\t", contador);
                printf("O numero %lf \n", num[d]);
            }

            printf("\n");
            contador = contador + 1;
            d = d + 1;
        }

        printf("\n");
        contador = contador + 1;
        d = d + 1;
    }

    printf("\nAperta ENTER para terminar.\n");
    getchar(); // aguarda o Enter
    return (0);
}

/*
-- Teste OK

*/