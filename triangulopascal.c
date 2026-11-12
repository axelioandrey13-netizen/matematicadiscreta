#include <stdio.h>

int main()
{
    int i, j, linhas;
    unsigned long long coef = 1;

    printf("\n--- Triangulo de Pascal ---\n");
    printf("Digite a quantidade de linhas do triangulo: ");
    scanf("%d", &linhas);
    
    if (linhas <= 0) {
        printf("Erro: Digite um numero valido de linhas (maior que 0).\n");
    }
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < linhas - i; j++) {
            printf("  ");
        }
        
        coef = 1; 
        for (j = 0; j <= i; j++) {
            printf("%4llu", coef);
            coef = coef * (i - j) / (j + 1);
        }
        printf("\n");
    }


    return 0;
}