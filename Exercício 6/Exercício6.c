#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex6.h"


void adicionarRegistro(FILE *arquivo) {
    struct Funcionario novoFuncionario;
    printf("Digite o nome do funcionário: ");
    scanf("%s", novoFuncionario.nome);
   
    printf("Digite a idade do funcionário: ");
    scanf("%d", &novoFuncionario.idade);
    
    printf("Digite o salário do funcionário: ");
    scanf("%f", &novoFuncionario.salario);
    
    fwrite(&novoFuncionario, sizeof(struct Funcionario), 1, arquivo);
    printf("Registro adicionado com sucesso.\n");
}

void listarRegistros(FILE *arquivo) {
    rewind(arquivo);
    
    struct Funcionario funcionario;
    
    printf("Listagem de Registros:\n");
    printf("Nome\t\tIdade\tSalário\n");
    
    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo) == 1) {
        printf("%s\t\t%d\t%.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
    }
}

void buscarPorNome(FILE *arquivo, char *nomeBusca) {
    rewind(arquivo);
    struct Funcionario funcionario;
    int encontrado = 0;
    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo) == 1) {
        
        if (strcmp(funcionario.nome, nomeBusca) == 0) { 
            printf("Registro encontrado:\n");
            printf("Nome: %s\n", funcionario.nome);
            printf("Idade: %d\n", funcionario.idade);
            printf("Salário: %.2f\n", funcionario.salario);
            
            encontrado = 1;
            
            break;
        }
    }
    if (!encontrado) {
        printf("Registro não encontrado para o nome %s.\n", nomeBusca);
    }
}

int main() {
    FILE *arquivo;
    arquivo = fopen("funcionarios.bin", "ab+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int opcao;
    char nomeBusca[50];
    
    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar novo registro\n");
        printf("2. Listar todos os registros\n");
        printf("3. Buscar registro por nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                adicionarRegistro(arquivo);
                break;
            case 2:
                listarRegistros(arquivo);
                break;
            case 3:
                printf("Digite o nome a ser buscado: ");
                scanf("%s", nomeBusca);
                buscarPorNome(arquivo, nomeBusca);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
    
    fclose(arquivo);
   
    return 0;
}
