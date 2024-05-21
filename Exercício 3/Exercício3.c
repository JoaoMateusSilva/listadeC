#include <stdio.h>
#include "produto.h"

int main() {
    struct Produto produtos[100];
    int numProdutos = 0;

    while (1) {
        int opcao;
        printf("\n=== Menu ===\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir informações dos produtos\n");
        printf("3. Calcular valor total em estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nCadastro de Produto\n");
                printf("Nome: ");
                scanf(" %[^\n]s", produtos[numProdutos].nome);
                printf("Preço: ");
                scanf("%f", &produtos[numProdutos].preco);
                printf("Quantidade em estoque: ");
                scanf("%d", &produtos[numProdutos].quantidade);
                numProdutos++;
                break;
            case 2:
                printf("\nInformações dos Produtos\n");
                for (int i = 0; i < numProdutos; i++) {
                    printf("Produto %d\n", i + 1);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Preço: R$ %.2f\n", produtos[i].preco);
                    printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
                    printf("\n");
                }
                break;
            case 3:
                printf("\nValor Total em Estoque\n");
                float total = 0;
                for (int i = 0; i < numProdutos; i++) {
                    total += produtos[i].preco * produtos[i].quantidade;
                }
                printf("Valor total em estoque: R$ %.2f\n", total);
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                return 0;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    }

    return 0;
}