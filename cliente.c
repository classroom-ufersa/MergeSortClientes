#include "cliente.h"

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
        printf("ERRO DE MEMORIA");
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
    fprintf(arquivo_client, "---------------------------\n Nome: %s\n Endereço: %s\n Código de Cliente: %d\n", usuarios[total_de_Usuarios].nome, usuarios[total_de_Usuarios].endereco, usuarios[total_de_Usuarios].codigo_de_cliente);

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
                    fprintf(arquivo_client, "---------------------------\n Nome: %s\n Endereço: %s\n Código de Cliente: %d\n", usuarios[i].nome, usuarios[i].endereco, usuarios[i].codigo_de_cliente);

                    printf("---------------------------\n");
                    printf("Dados alterados com sucesso!\n");
                    printf("---------------------------\n");
                }
                else
                {
                    fprintf(arquivo_client, "---------------------------\n Nome: %s\n Endereço: %s\n Código de Cliente: %d\n", usuarios[i].nome, usuarios[i].endereco, usuarios[i].codigo_de_cliente);
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