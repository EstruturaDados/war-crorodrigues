#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constatntes globais ---//
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

// --- Definição das estruturas ---//
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para sim, 0 para não.
};

// Nova struct para armazenar informações do emprétimo.
struct Emprestimo{
    int indicelivro; // Para saber qual livro do array 'biblioteca' foi emprestao.
    char nomeUsuario[TAM_STRING];
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal (main) ---
int main() {
    //1. Alocação dinâmica de memória
    // Agora em vez de arrays estaticos, usamos ponteiros.
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    //usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
    //Vantagem: inicializa toda a memoria com zeros. Isso significa que 'disponivel já começa 
    biblioteca = (struct Livro*) calloc(MAX_LIVROS, sizeof(struct Livro));
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS, sizeof(struct Emprestimo));

    // Verificação: É crucial verificar se a alocação da memória deu certo.
    if (biblioteca == NULL && emprestimos == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
        return 1;
    };

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

do {
    printf("======================================================\n");
    printf("    BIBLIOTECA - PARTE 2 \n");
    printf("======================================================\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar emprestimo\n");
    printf("4 - Listar emprestimos\n");
    printf("0 - Sair\n");
    printf("------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBufferEntrada();

    switch (opcao)
    {
    case 1:
        printf("--- Cadastro de novo livro---\n\n");
        if (totalLivros < MAX_LIVROS){
            printf("Digite o nome do livro: ");
            fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
            printf("Digite o autor: ");
            fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
            printf("Digite a editora: ");
            fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
            
            printf("Digite a edicao: ");
            scanf("%d", &biblioteca[totalLivros].edicao);
            limparBufferEntrada();

            totalLivros++;

            printf("\nLivro cadastrado com sucesso!\n");

        } else {
            printf("\nBiblioteca cheia! Nao e possivel cadastrar mais livros.\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        break;
    case 2:
        printf("--- Lista de livros cadastrados ---\n\n");
        
        if (totalLivros == 0) {
            printf("Nenhum livro cadastrado ainda.\n");
        } else {
            for (int i = 0; i < totalLivros; i++) {
                printf("------------------------------------------------\n");
                printf("Livro %d\n", i + 1);
                printf("Nome:%s\n", biblioteca[i].nome);
                printf("Nome:%s\n", biblioteca[i].autor);
                printf("Nome:%s\n", biblioteca[i].editora);
                printf("Nome:%d\n", biblioteca[i].edicao);

            }
            printf("------------------------------------------\n");

        }
        printf("\nPressione Enter para continuar...");
        getchar();
        break;
    
    case 0:
        printf("\nSaindo do sistema...\n");
        break;

    default:
        printf("\nOpcao invalida! Tente novamente.\n");   
        printf("\nPressione Enter para continuar...");
        getchar();
        break; 
    }
} while (opcao != 0);

return 0;
