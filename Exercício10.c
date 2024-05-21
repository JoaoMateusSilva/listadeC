#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio = clock();

    for (int i = 0; i < 1000000; i++) {
        int resultado = i * i;
    }

    clock_t fim = clock();

    double tempoDecorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %.6f segundos\n", tempoDecorrido);

    return 0;
}
