#include <stdio.h>
#include <stdlib.h>

int* inverterArray(int *array, int tamanho) {
    int *arrayInvertido = (int *)malloc(tamanho * sizeof(int));
    if (arrayInvertido == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        
        exit(EXIT_FAILURE);
    }

    int *ptrInvertido = arrayInvertido;

    for (int i = tamanho - 1; i >= 0; i--) {
        *ptrInvertido = array[i];
        ptrInvertido++;
    }

    return arrayInvertido;
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

    int *arrayInvertido = inverterArray(array, tamanho);

    printf("Array invertido:\n");
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");

    free(array);
    free(arrayInvertido);

    return 0;
}
