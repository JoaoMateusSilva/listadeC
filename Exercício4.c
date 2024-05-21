#include <stdio.h>
#include <stdlib.h>

float **alocarMatriz(int linhas, int colunas) {
    float **matriz = (float **)malloc(linhas * sizeof(float *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (float *)malloc(colunas * sizeof(float));
    }
    return matriz;
}

void liberarMatriz(float **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

float **multiplicarMatrizes(float **matriz1, int linhas1, int colunas1,
                             float **matriz2, int linhas2, int colunas2) {
    if (colunas1 != linhas2) {
        return NULL;
    }

    float **resultado = alocarMatriz(linhas1, colunas2);

    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

float **transporMatriz(float **matriz, int linhas, int colunas) {
    float **transposta = alocarMatriz(colunas, linhas);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    return transposta;
}

void exibirMatriz(float **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas1 = 2, colunas1 = 3;
    
    float **matriz1 = alocarMatriz(linhas1, colunas1);
    
    matriz1[0][0] = 1; matriz1[0][1] = 2; matriz1[0][2] = 3;
    matriz1[1][0] = 4; matriz1[1][1] = 5; matriz1[1][2] = 6;

    int linhas2 = 3, colunas2 = 2;
    
    float **matriz2 = alocarMatriz(linhas2, colunas2);
    
    matriz2[0][0] = 1; matriz2[0][1] = 2;
    matriz2[1][0] = 3; matriz2[1][1] = 4;
    matriz2[2][0] = 5; matriz2[2][1] = 6;

    float **resultadoMultiplicacao = multiplicarMatrizes(matriz1, linhas1, colunas1, matriz2, linhas2, colunas2);
    
    printf("Resultado da multiplicação:\n");
    
    exibirMatriz(resultadoMultiplicacao, linhas1, colunas2);
    liberarMatriz(resultadoMultiplicacao, linhas1);

    float **transposta = transporMatriz(matriz1, linhas1, colunas1);
    
    printf("\nMatriz transposta:\n");
    
    exibirMatriz(transposta, colunas1, linhas1);
    liberarMatriz(transposta, colunas1);

    liberarMatriz(matriz1, linhas1);
    liberarMatriz(matriz2, linhas2);

    return 0;
}