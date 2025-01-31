#include <stdio.h>  
#include <stdlib.h>  
#include <locale.h>  
#include <string.h>  

#define MAX_STRING 40
#define MAX_CONTENT 200

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int abrirArquivo(FILE **file, const char *nome_arquivo, const char *modo) {
    *file = fopen(nome_arquivo, modo);
    if (*file == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
        return 1;
    }
    return 0;
}

int registro() {
    setlocale(LC_ALL, "Portuguese");
    char arquivo[MAX_STRING];
    char cpf[MAX_STRING], nome[MAX_STRING], senha[MAX_STRING], cargo[MAX_STRING];

    printf("Digite o CPF a ser cadastrado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0; // Remove a nova linha

    strcpy(arquivo, cpf);

    limparTela();

    FILE *file;
    if (abrirArquivo(&file, arquivo, "w") != 0) return 1;

    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    if (abrirArquivo(&file, arquivo, "a") != 0) return 1;
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o uma senha a ser cadastrada: ");
    fgets(senha, sizeof(senha), stdin);
    senha [strcspn(senha, "\n")] = 0;

    if (abrirArquivo(&file, arquivo, "a") != 0) return 2;
    fprintf(file, "%s,", senha);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = 0;

    if (abrirArquivo(&file, arquivo, "a") != 0) return 1;
    fprintf(file, "%s", cargo);
    fclose(file);

    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[MAX_STRING], conteudo[MAX_CONTENT];

    printf("Digite o CPF a ser consultado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *file;
    if (abrirArquivo(&file, cpf, "r") != 0) return 1;

    printf("\nEssas são as informações do usuário:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }

    fclose(file);
    system("pause");
    return 0;
}

int deletar() {
    char cpf[MAX_STRING];
    printf("Digite o CPF a ser deletado:\n");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o usuário.\n");
    }

    system("pause");
    return 0;
}

int main() {
    int opcao = 0;
    while (1) {
        limparTela();
        setlocale(LC_ALL, "Portuguese");

        printf("\tCartório da Ebac \n\n\n");
        printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair do sistema\n");
        printf("Opção: ");

        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        limparTela();
        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
            	printf("Obrigado por utilizar o Cartório Ebac\n\n");
            	return 0;
            	break;
            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }
    }
}
