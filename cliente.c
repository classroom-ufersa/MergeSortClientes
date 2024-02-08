#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

struct clientes
{
    char nome[20];
    char endereco[50];
    int codigo_de_cliente;
};

void preencher_dados(clientes **usuarios, int *total_de_usuarios, FILE *dados) {
    printf("----------------------------------\n");
    printf("Informe o nome: ");
    scanf(" %[^\n]", (*usuarios)[*total_de_usuarios].nome);

    printf("Informe o endereco: ");
    scanf(" %[^\n]", (*usuarios)[*total_de_usuarios].endereco);

    printf("Informe o codigo do Cliente: ");
    scanf("%d", &((*usuarios)[*total_de_usuarios].codigo_de_cliente));

    printf("----------------------------------\n");

    fprintf(dados, "-------------------------\n Nome: %s \n Endereço: %s \n Código de Cliente: %d \n",
            (*usuarios)[*total_de_usuarios].nome, (*usuarios)[*total_de_usuarios].endereco, (*usuarios)[*total_de_usuarios].codigo_de_cliente);

    *total_de_usuarios += 1;

    *usuarios = (clientes*)realloc(*usuarios, (*total_de_usuarios)*sizeof(clientes));
}
