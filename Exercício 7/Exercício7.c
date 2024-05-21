#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex7.h"

int compararIdade(const void *a, const void *b) {
    const struct Funcionario *funcionarioA = a;
    const struct Funcionario *funcionarioB = b;
    return funcionarioA->idade - funcionarioB->idade;
}

int main() {
    int numFuncionarios = sizeof(funcionarios) / sizeof(funcionarios[0]);

    qsort(funcionarios, numFuncionarios, sizeof(struct Funcionario), compararIdade);

    printf("Funcionarios ordenados por idade:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }

    return 0;
}