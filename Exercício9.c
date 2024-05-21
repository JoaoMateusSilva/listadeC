#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calcularMediana(int array[], int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);
    return (tamanho % 2 == 0) ? (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0 : array[tamanho / 2];
}

int calcularModa(int array[], int tamanho) {
    int moda = array[0], contagem = 1, maxContagem = 1;

    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i - 1]) {
            contagem++;
        } else {
            if (contagem > maxContagem) {
                maxContagem = contagem;
                moda = array[i - 1];
            }
            contagem = 1;
        }
    }

    return contagem > maxContagem ? array[tamanho - 1] : moda;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return EXIT_FAILURE;
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    float media = 0;
    for (int i = 0; i < tamanho; i++) {
        media += array[i];
    }
    media /= tamanho;

    float mediana = calcularMediana(array, tamanho);
    int moda = calcularModa(array, tamanho);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    free(array);

    return 0;
}
