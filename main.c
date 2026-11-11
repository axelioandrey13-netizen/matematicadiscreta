#include <stdio.h>

//Imprime o triângulo de pascal
void triangulopascal() {
    int i, j, linhas;
    unsigned long long coef = 1;

    printf("\n--- Triangulo de Pascal ---\n");
    printf("Digite a quantidade de linhas do triangulo: ");
    scanf("%d", &linhas);
    
    if (linhas <= 0) {
        printf("Erro: Digite um numero valido de linhas (maior que 0).\n");
        return; 
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
}

//Calcula o arranjo simples: A(n, p) = n! / (n - p)!
void calcularArranjo() {
    int n, p, i;
    unsigned long long arranjo = 1;

    printf("\n--- Calculo de Arranjo A(n, p) ---\n");
    printf("Digite o valor de n (total de elementos): ");
    scanf("%d", &n);
    printf("Digite o valor de p (elementos agrupados): ");
    scanf("%d", &p);

    if (n < 0 || p < 0) {
        printf("Erro: Os valores nao podem ser negativos.\n");
        return;
    }
    if (p > n) {
        printf("Erro: O valor de 'p' nao pode ser maior que 'n'.\n");
        return;
    }

    for (i = n; i > (n - p); i--) {
        arranjo *= i;
    }

    printf("Resultado: A(%d, %d) = %llu\n", n, p, arranjo);
}

//Calcula a permutacao simples: P(n) = n!
void calcularPermutacao() {
    int n, i;
    unsigned long long permutacao = 1;

    printf("\n--- Calculo de Permutacao P(n) ---\n");
    printf("Digite o valor de n (total de elementos): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: O valor de 'n' nao pode ser negativo.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        permutacao *= i;
    }

    printf("Resultado: P(%d) = %llu\n", n, permutacao);
}

//Calcula a combinacao simples: C(n, p) = n! / (p! * (n - p)!)
void calcularCombinacao() {
    int n, p, i;
    unsigned long long combinacao = 1;

    printf("\n--- Calculo de Combinacao C(n, p) ---\n");
    printf("Digite o valor de n (total de elementos): ");
    scanf("%d", &n);
    printf("Digite o valor de p (elementos escolhidos): ");
    scanf("%d", &p);

    if (n < 0 || p < 0) {
        printf("Erro: Os valores nao podem ser negativos.\n");
        return;
    }
    if (p > n) {
        printf("Erro: O valor de 'p' nao pode ser maior que 'n'.\n");
        return;
    }

    //Propridade das combinações: C(n, p) == C(n, n - p)
    //Reduz o numero de multiplicações necessárias
    if (p > n - p) {
        p = n - p;
    }

    //Cálculo iterativo para evitar estouro de memória com fatoiais grandes
    for (i = 1; i <= p; i++) {
        combinacao = combinacao * (n - i + 1) / i;
    }

    printf("Resultado: C(%d, %d) = %llu\n", n, p, combinacao);
}

int main() {
    int opcao;

    do {
        printf("\n==== Menu de Análise Combinatória ====\n");
        printf("1 - Triangulo de Pascal\n");
        printf("2 - Calcular Arranjo A(n, p)\n");
        printf("3 - Calcular Permutacao P(n)\n");
        printf("4 - Calcular Combinacao C(n, p)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                triangulopascal();
                break;
            case 2:
                calcularArranjo();
                break;
            case 3:
                calcularPermutacao();
                break;
            case 4:
                calcularCombinacao();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}