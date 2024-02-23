#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include<string.h>

/*Estrutura que armazena os dados dos clientes */
typedef struct Clientes{
    char nome[20];
    char endereco[50];
    int codigo_de_cliente;
}clientes;

/*função que exibe o menu*/
void menu();

/*Essa função realoca a memória para o vetor de clientes e verifica se a alocação foi bem sucedida,
 recebendo como parâmetro o endereço do vetor de clientes e o total de usuários cadastrados.*/
void realocar_Memoria(clientes **usuarios, int total_de_Usuarios);

/*Essa função preenche os dados dos clientes e os armazena em um arquivo e no vetor, recebendo como parâmetro o vetor de clientes,
 o total de usuários cadastrados e o arquivo onde os dados serão armazenados.*/
void preencher_Dados(clientes *usuarios, int total_de_Usuarios, FILE *arquivo_client);

/*Essa função altera os dados dos clientes e os armazena em um arquivo e no vetor, recebendo como parâmetro o vetor de clientes,
o total de usuários cadastrados e o arquivo onde os dados serão armazenados.*/
void alterar_dados(clientes *usuarios, int total_de_Usuarios, FILE *arquivo_client);

/*Essa função imprime os dados dos clientes cadastrados,
recebendo como parâmetro o vetor de clientes e o total de usuários cadastrados.*/
void imprimir_dados(clientes *usuarios, int total_de_Usuarios);

/*Essa função lê os dados dos clientes armazenados em um arquivo e os armazena em um vetor,
recebendo como parâmetro o arquivo onde os dados estão armazenados, o vetor de clientes e o total de usuários cadastrados.*/
void ler_arquivo(FILE *arquivo_client, clientes **usuarios, int *total_de_Usuarios);

/*Essa função ordena os dados dos clientes em ordem pelo codigo de cliente, utilizando o algoritmo de ordenação merge sort
recebendo como parâmetro o vetor de clientes, a posição inicial e a posição final do vetor.*/
void merge(clientes * usuarios, int esquerda, int meio, int direita);

/*Essa função ordena os dados dos clientes em ordem pelo codigo de cliente, utilizando o algoritmo de ordenação merge sort
recebendo como parâmetro o vetor de clientes, a posição inicial e a posição final do vetor.*/
void mergeSort(clientes * usuarios, int esquerda, int direita);

/*Essa função altera os dados dos clientes e os armazena em um arquivo e no vetor, recebendo como parâmetro o vetor de clientes,
o total de usuários cadastrados e o arquivo onde os dados serão armazenados.*/
void alterar_dados_merge(clientes *usuarios, int total_de_Usuarios, FILE *arquivo_client);

/*Essa função lê a opção escolhida pelo usuário e verifica se a opção é válida,
recebendo como parâmetro o menor valor e o maior valor que a opção pode ter.*/
char ler_opcao(char menor_valor, char maior_valor);

/*Essa função limpa o buffer do teclado para evitar que lixo de memória seja lido.
e evita que o programa entre em loop infinito.*/
void limpabuffer();