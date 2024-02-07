#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

struct clientes{
    char nome[20];
    char endereco[50];
    int codigo_de_cliente;
};


clientes * prenchendo_dados(void){

    clientes *usuarios = (clientes*)malloc(sizeof(struct clientes));

    if (usuarios == NULL) {
        printf("SEM MEMORIA!!");
        exit(1);
    }
    printf("----------------------------------\n");
    printf("Informe o nome: ");
    scanf(" %[^\n]", usuarios->nome);

    printf("Informe o endereco: ");
    scanf(" %[^\n]", usuarios->endereco);

    printf("Informe o codigo do Cliente: ");
    scanf("%d", &usuarios->codigo_de_cliente);

    printf("----------------------------------\n");

    return usuarios;

}

