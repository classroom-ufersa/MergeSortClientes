#include "cliente.c"

int main(void)
{
    srand(time(NULL));
    int escolha = 0, op = 0;
    int total_de_Usuarios = 0;

    FILE *arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "r+");

    if (arquivo_client == NULL)
    {
        printf("ERRO DE CRIAR O ARQUIVO\n");
        exit(1);
    }

    clientes *Usuarios = (clientes *)malloc(1 * sizeof(clientes));
    if (Usuarios == NULL)
    {
        printf("ERRO DE MEMORIA");
        exit(1);
    }

    ler_arquivo(arquivo_client, &Usuarios, &total_de_Usuarios);

    do
    {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            do
            {
                realocar_Memoria(&Usuarios, total_de_Usuarios + 1);
                preencher_Dados(Usuarios, total_de_Usuarios, arquivo_client);
                total_de_Usuarios++;
                printf("Deseja cadastrar mais um usuário? (1 - Sim / 2 - Não): ");
                scanf("%d", &op);
            } while (op != 2);
            break;
        case 2:
            imprimir_dados(Usuarios, total_de_Usuarios);
            alterar_dados(Usuarios, total_de_Usuarios, arquivo_client);
            break;
        case 3:  
            mergeSort(Usuarios, 0, total_de_Usuarios - 1);
            alterar_dados_merge(Usuarios, total_de_Usuarios, arquivo_client);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
        
    } while (escolha != 4);

    free(Usuarios);

    fclose(arquivo_client);

    return 0;
}