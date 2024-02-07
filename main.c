#include <stdio.h>
#include <stdlib.h>
#include "cliente.c"



int main(void){
    
    int total_de_Usuarios;

    FILE *arquivo_client = fopen("arquivo_dados_dos_clientes.txt", "a+");

    if(arquivo_client == NULL){
        printf("ERRO DE CRIAR O ARQUIVO\n");
        exit(1);
    }

    printf("Digite o total de pessoa para cadastrar no sistema: ");

    scanf("%d",&total_de_Usuarios);

    clientes *Usuarios[total_de_Usuarios];

    for(int i = 0; i < total_de_Usuarios; i++){

         Usuarios[i] = prenchendo_dados();

         fprintf(arquivo_client,"-------------------------\n Nome: %s \n Endereço: %s \n Código de Cliente: %d \n",Usuarios[i]->nome, Usuarios[i]->endereco, Usuarios[i]->codigo_de_cliente);

    }
    
    
    free(Usuarios);
    
    fclose(arquivo_client);



    return 0; 
}