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

char ler_opcao(char menor_valor, char maior_valor) {
    char escolhaop;
    char entrada[100];

    do {
        scanf(" %[^\n]", entrada);

        escolhaop = entrada[0];

        if (escolhaop >= menor_valor && escolhaop <= maior_valor && strlen(entrada) == 1) {
            limpabuffer();
            return escolhaop; // Retornar a opção selecionada
        } else {
            printf("Opcao invalida. A opcao deve estar entre %c e %c: ", menor_valor, maior_valor);
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
    int i, j, k; //c1, 1 vez
    int tamanho_esquerda = meio - esquerda + 1;   //Armazenam o tamanho do subarray Esquerda, c2 1vez
    int tamanho_direita = direita - meio;         //Armazenam o tamanho do subarray Direita, c3 1 vez

    clientes Esquerda[tamanho_esquerda], Direita[tamanho_direita]; //c4 1 vez

    for (i = 0; i < tamanho_esquerda; i++) //c5 n vezes
        Esquerda[i] = usuarios[esquerda + i]; //c6 n vezes
    for (j = 0; j < tamanho_direita; j++)   //c7 n vezes
        Direita[j] = usuarios[meio + 1 + j]; //c8 n vezes

    i = 0; //c9 1 vez
    j = 0; //c10 1 vez
    k = esquerda; //c11 1 vez

    while (i < tamanho_esquerda && j < tamanho_direita) //c12 n vezes
    {
        if (Esquerda[i].codigo_de_cliente <= Direita[j].codigo_de_cliente) //c13 n vezes
        {
            usuarios[k] = Esquerda[i]; //c14 n vezes
            i++; //c15 n vezes
        }
        else //c16 n vezes
        {
            usuarios[k] = Direita[j]; //c17 n vezes
            j++; //c18 n vezes
        }
        k++; //c19 n vezes
    }

    while (i < tamanho_esquerda) //c20 n vezes
    {
        usuarios[k] = Esquerda[i]; //c21 n vezes
        i++; //c22 n vezes
        k++; //c23 n vezes
    }

    while (j < tamanho_direita) //c24 n vezes
    {
        usuarios[k] = Direita[j]; //c25 n vezes
        j++; //c26 n vezes
        k++; //c27 n vezes
    }
}

void mergeSort(clientes *usuarios, int esquerda, int direita)
{
    if (esquerda < direita) //c28 1 vez
    {
        int meio = esquerda + (direita - esquerda) / 2; //c29 1 vez

        mergeSort(usuarios, esquerda, meio);  //T(n/2) 1 vez
        mergeSort(usuarios, meio + 1, direita); //T(n/2) 1 vez

        merge(usuarios, esquerda, meio, direita);   //O(n) 1 vez
    }
}

// análise de tempo de execução = c1 + c2 + c3 + c4 + c5*n + c6*n + c7*n + c8*n + c9 + c10 + c11 + c12*n + c13*n + c14*n + c15*n + c16*n + c17*n + c18*n + c19*n + c20*n + c21*n + c22*n + c23*n + c24*n + c25*n + c26*n + c27*n + c28 + c29 + T(n/2) + T(n/2) + O(n)
//simplicando a equação = (c1 + c2 + c3 + c4 + c9 + c10 + c11 + c28 + c29) + (c5 + c6 + c7 + c8 + c12 + c13 + c14 + c15 + c16 + c17 + c18 + c19 + c20 + c21 + c22 + c23 + c24 + c25 + c26 + c27)*n + 2T(n/2) + O(n)
//O(n) = n*log(n)
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