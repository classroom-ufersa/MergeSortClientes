#include "cliente.c"

int main(void)
{
    int escolha = 0;
    int total_de_Usuarios = 0;

    FILE *arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "a+");

    if (arquivo_client == NULL)
    {
        printf("ERRO DE CRIAR O ARQUIVO\n");
        exit(1);
    }

    clientes *Usuarios = (clientes *)malloc(total_de_Usuarios * sizeof(clientes));
    if (Usuarios == NULL)
    {
        printf("ERRO DE MEMORIA");
        exit(1);
    }




    do
    {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar Usuarios\n");
        printf("2. Opção 2\n");
        printf("3. Opção 3\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha); //colocar como uma função para ler, para não quebrar o codigo -> Erick

        switch (escolha)
        {
        case 1:
            preencher_dados(&Usuarios, &total_de_Usuarios, arquivo_client);
            printf("Cadastrado com Sucesso!!!");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (escolha != 6);

    free(Usuarios);

    fclose(arquivo_client);

    return 0;
}