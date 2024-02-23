#include "cliente.c"

int main(void)
{
    srand(time(NULL));
    clock_t inicio, fim;
    float tempo;
    char escolhaop;
    int total_de_Usuarios = 0;

    FILE *arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "a+");

    if (arquivo_client == NULL)
    {
        printf("erro ao criar o arquivo\n");
        exit(1);
    }

    clientes *Usuarios = (clientes *)malloc(1 * sizeof(clientes));
    if (Usuarios == NULL)
    {
        printf("erro ao alocar memória");
        exit(1);
    }

    ler_arquivo(arquivo_client, &Usuarios, &total_de_Usuarios);

    do {
        menu();
        printf("Escolha uma opção: ");
        escolhaop = ler_opcao('1', '4'); // Obter a opção do usuário

        switch (escolhaop) {
            case '1':
                do {
                realocar_Memoria(&Usuarios, total_de_Usuarios + 1);
                preencher_Dados(Usuarios, total_de_Usuarios, arquivo_client);
                total_de_Usuarios++;
                printf("Deseja cadastrar mais um usuário? (1 - Sim / 2 - Não): ");
                escolhaop = ler_opcao('1', '2');
                } while (escolhaop != '2');
                break;
            case '2':
            imprimir_dados(Usuarios, total_de_Usuarios);
            alterar_dados(Usuarios, total_de_Usuarios, arquivo_client);
            break;
            case '3':
            inicio = clock();
            mergeSort(Usuarios, 0, total_de_Usuarios - 1);
            alterar_dados_merge(Usuarios, total_de_Usuarios, arquivo_client);
            fim = clock();
            tempo = (fim - inicio) * 100000000000000;
            printf("Tempo de execução: %.f segundos\n", tempo);
            printf("Ordenação realizada com sucesso! \n");
            break;
            case '4':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (escolhaop != '4');

    free(Usuarios);

    fclose(arquivo_client);

    return 0;
}