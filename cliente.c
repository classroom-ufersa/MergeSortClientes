#include "cliente.h"

void limpabuffer(void){
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin); // Lê uma linha inteira de entrada
}

void ler_opcao(int menor_valor, int maior_valor){
    int escolha;
    char entrada[50];

     do {
        printf("Escolha uma opção: ");
        scanf(" %[^\n]", entrada);

        escolha = entrada[0];

        if (escolha >= menor_valor && escolha <= maior_valor) {
            limpabuffer();
            break;
        } else {
            printf("Opcao invalida. A opcao deve estar entre %d e %d. \n", menor_valor, maior_valor);
            limpabuffer();
        }
    } while (escolha != 4);
}

void ler_arquivo(FILE *arquivo_client, clientes **usuarios, int *total_de_Usuarios) {
    while (fscanf(arquivo_client, "Nome: %19[^\n]\nEndereço: %19[^\n]\nCódigo de Cliente: %d\n", (*usuarios)[*total_de_Usuarios].nome, (*usuarios)[*total_de_Usuarios].endereco, &(*usuarios)[*total_de_Usuarios].codigo_de_cliente) != EOF) {
        (*total_de_Usuarios)++;
        *usuarios = (clientes *)realloc(*usuarios, (*total_de_Usuarios + 1) * sizeof(clientes));
        if (*usuarios == NULL) {
            printf("Erro ao realocar memória.\n");
            exit(1);
        }
    }
}

void menu()
{
    printf("\nMenu de Opções:\n"
           "1. Cadastrar Usuarios\n"
           "2. Alterar Dados\n"
           "3. Opção 3\n"
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
    do
    {
        printf("Digite o codigo do cliente que deseja alterar: ");
        scanf("%d", &codigo);
        if (codigo >= 0 && codigo <= 999)
        {
            fclose(arquivo_client);
            arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "w");
            for (int i = 0; i < total_de_Usuarios; i++)
            {
                if (usuarios[i].codigo_de_cliente == codigo)
                {
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
        }
        else
        {
            printf("---------------------------\n");
            printf("Codigo de cliente não encontrado!\n");
            printf("Digite novamente o codigo do cliente\n ");
            printf("---------------------------\n");
        }
    } while (codigo < 0 || codigo > 999);
}

void imprimir_dados(clientes *usuarios, int total_de_Usuarios)
{
    for (int i = 0; i < total_de_Usuarios; i++)
    {
        printf("---------------------------\n Nome: %s\n Endereço: %s\n Código de Cliente: %d\n---------------------------\n",
               usuarios[i].nome, usuarios[i].endereco, usuarios[i].codigo_de_cliente);
    }
}

void merge(clientes * usuarios, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    clientes L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = usuarios[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = usuarios[m + 1 + j]; 
  
    i = 0; 
    j = 0; 
  
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i].codigo_de_cliente <= R[j].codigo_de_cliente) { 
            usuarios[k] = L[i]; 
            i++; 
        } 
        else { 
            usuarios[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        usuarios[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        usuarios[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(clientes * usuarios, int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSort(usuarios, l, m); 
        mergeSort(usuarios, m + 1, r); 
  
        merge(usuarios, l, m, r); 
    } 
} 
  
void printArray(clientes *usuarios, int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", usuarios[i].codigo_de_cliente); 
    printf("\n"); 
}

void alterar_dados_merge(clientes *usuarios, int total_de_Usuarios, FILE *arquivo_client)
{
    arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "w");
            for (int i = 0; i < total_de_Usuarios; i++)
            {
                {
                    fprintf(arquivo_client, "Nome: %s\n", usuarios[i].nome);
                    fprintf(arquivo_client, "Endereço: %s\n", usuarios[i].endereco);
                    fprintf(arquivo_client, "Código de Cliente: %d\n", usuarios[i].codigo_de_cliente);
                    fprintf(arquivo_client, "\n");
                }
            }
        }