/* 
   Definição da estrutura Territorio:
   Armazena o nome, cor do exército e quantidade de tropas de um território.
*/
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Declara um vetor de 5 estruturas do tipo Territorio
    Territorio territorios[5];
    
    // Variável de controle para o loop
    int i;

    printf("=== Sistema de Cadastro de Territorios ===\n\n");

    // Entrada dos dados dos 5 territórios
    for (i = 0; i < 5; i++) {
        printf("Cadastro do territorio %d\n", i + 1);

        printf("Nome do territorio: ");
        scanf(" %s", territorios[i].nome);  // Lê string com espaços até \n

        printf("Cor do exercito: ");
        scanf(" %ss", territorios[i].cor);  // Lê string simples (sem espaços)

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("-------------------------------------\n");
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territorios Cadastrados ===\n\n");

    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do exercito: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n", territorios[i].tropas);
        printf("-------------------------------------\n");
    }

    printf("Exibicao concluida.\n");
    return 0;
}