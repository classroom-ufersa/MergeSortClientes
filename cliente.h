#include <stdio.h>
#include <stdlib.h>
/*Definição de novo tipo: clientes*/
typedef struct clientes clientes;

/*função que aloca memoria para 
struct clientes, recebe os dados via teclado e retorna
um ponteiro para cliente*/

void preencher_dados(clientes **usuarios, int *total_de_usuarios, FILE *dados);
void ler_arquivo(clientes *usuario, char *caminho, int *total_de_usuarios);
