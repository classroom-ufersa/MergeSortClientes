#include "cliente.h"

void ler_arquivo(FILE *arquivo_client, clientes **usuarios, int *total_de_Usuarios)
{
    while (fscanf(arquivo_client, "Nome: %19[^\n]\nEndereço: %19[^\n]\nCódigo de Cliente: %d\n", (*usuarios)[*total_de_Usuarios].nome, (*usuarios)[*total_de_Usuarios].endereco, &(*usuarios)[*total_de_Usuarios].codigo_de_cliente) != EOF)
    {
        (*total_de_Usuarios)++;
        *usuarios = (clientes *)realloc(*usuarios, (*total_de_Usuarios + 1) * sizeof(clientes));
        if (*usuarios == NULL)
        {
            printf("Erro ao realocar memória.\n");
            exit(1);
        }
    }
}

void limpabuffer() {
    fflush(stdin);
}

int ler_opcao(int menor_valor, int maior_valor) {
    int escolhaop;
    float entrada;

    do {
        printf("Escolha uma opção: ");
        scanf(" %f.30", &entrada);

        escolhaop = entrada; //[0] - '0'; // Convertendo o char para int

        if (escolhaop >= menor_valor && escolhaop <= maior_valor) {
            limpabuffer();
            return escolhaop; // Retornar a opção selecionada
        } else {
            printf("Opcao invalida. A opcao deve estar entre %d e %d. \n", menor_valor, maior_valor);
            limpabuffer();
        }
    } while (1);
}

void menu()
{
    printf("\nMenu de Opções:\n"
           "1. Cadastrar Usuarios\n"
           "2. Alterar Dados\n"
           "3. Ordenação dos Códigos\n"
           "4. Sair\n");
}

void realocar_Memoria(clientes **usuarios, int total_de_Usuarios)
{
    *usuarios = (clientes *)realloc(*usuarios, total_de_Usuarios * sizeof(clientes));
    if (*usuarios == NULL)
    {
        printf("Erro ao realocar memória");
        exit(1);
    }
}

void preencher_Dados(clientes *usuarios, int total_de_Usuarios, FILE *arquivo_client)
{
    printf("--------------------------\n");
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", usuarios[total_de_Usuarios].nome);
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]", usuarios[total_de_Usuarios].endereco);
    usuarios[total_de_Usuarios].codigo_de_cliente = rand() % 1000;

    fprintf(arquivo_client, "Nome: %s\n", usuarios[total_de_Usuarios].nome);
    fprintf(arquivo_client, "Endereço: %s\n", usuarios[total_de_Usuarios].endereco);
    fprintf(arquivo_client, "Código de Cliente: %d\n", usuarios[total_de_Usuarios].codigo_de_cliente);
    fprintf(arquivo_client, "\n");

    printf("---------------------------\n");
    printf("Dados cadastrados com sucesso!\n");
    printf("---------------------------\n");
}

void alterar_dados(clientes *usuarios, int total_de_Usuarios, FILE *arquivo_client)
{
    int codigo;

    printf("Digite o codigo do cliente que deseja alterar: ");
    scanf("%d", &codigo);
    fclose(arquivo_client);
    arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "w");
    bool valido = false;
    for (int i = 0; i < total_de_Usuarios; i++)
    {
        if (usuarios[i].codigo_de_cliente == codigo)
        {
            valido = true;
            printf("Digite o novo nome do cliente: ");
            scanf(" %[^\n]", usuarios[i].nome);
            printf("Digite o novo endereço do cliente: ");
            scanf(" %[^\n]", usuarios[i].endereco);

            fprintf(arquivo_client, "Nome: %s\n", usuarios[i].nome);
            fprintf(arquivo_client, "Endereço: %s\n", usuarios[i].endereco);
            fprintf(arquivo_client, "Código de Cliente: %d\n", usuarios[i].codigo_de_cliente);
            fprintf(arquivo_client, "\n");
            printf("---------------------------\n");
            printf("Dados alterados com sucesso!\n");
            printf("---------------------------\n");
        }
        else
        {
            fprintf(arquivo_client, "Nome: %s\n", usuarios[i].nome);
            fprintf(arquivo_client, "Endereço: %s\n", usuarios[i].endereco);
            fprintf(arquivo_client, "Código de Cliente: %d\n", usuarios[i].codigo_de_cliente);
            fprintf(arquivo_client, "\n");
        }
    }

    if (valido == false)
    {
        printf("---------------------------\n");
        printf("Codigo de cliente não encontrado!\n");
        printf("---------------------------\n");
    }
}

void imprimir_dados(clientes *usuarios, int total_de_Usuarios)
{
    for (int i = 0; i < total_de_Usuarios; i++)
    {
        printf("---------------------------\n Nome: %s\n Endereço: %s\n Código de Cliente: %d\n---------------------------\n",
               usuarios[i].nome, usuarios[i].endereco, usuarios[i].codigo_de_cliente);
    }
}

void merge(clientes *usuarios, int esquerda, int meio, int direita)
{
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    clientes Esquerda[n1], Direita[n2];

    for (i = 0; i < n1; i++)
        Esquerda[i] = usuarios[esquerda + i];
    for (j = 0; j < n2; j++)
        Direita[j] = usuarios[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;

    while (i < n1 && j < n2)
    {
        if (Esquerda[i].codigo_de_cliente <= Direita[j].codigo_de_cliente)
        {
            usuarios[k] = Esquerda[i];
            i++;
        }
        else
        {
            usuarios[k] = Direita[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        usuarios[k] = Esquerda[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        usuarios[k] = Direita[j];
        j++;
        k++;
    }
}

void mergeSort(clientes *usuarios, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(usuarios, esquerda, meio);
        mergeSort(usuarios, meio + 1, direita);

        merge(usuarios, esquerda, meio, direita);
    }
}

void alterar_dados_merge(clientes *usuarios, int total_de_Usuarios, FILE *arquivo_client)
{
    arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "w");
    for (int i = 0; i < total_de_Usuarios; i++)
    {
        fprintf(arquivo_client, "Nome: %s\n", usuarios[i].nome);
        fprintf(arquivo_client, "Endereço: %s\n", usuarios[i].endereco);
        fprintf(arquivo_client, "Código de Cliente: %d\n", usuarios[i].codigo_de_cliente);
        fprintf(arquivo_client, "\n");
    }
}