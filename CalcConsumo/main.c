#include <stdio.h>
#include <stdlib.h>

void cadastrar_acao(){
	
}
	
void listar_acoes(){
	
}
	
void pesquisar_acao(){
	
}
	
void resumo_geral(){
	
}


int main(int argc, char *argv[]) {
	int opcao = -1;
	
	while(opcao != 0) {
		printf("==============================\n");
		printf("	 PSE EM ACAO		  \n");
		printf("==============================\n\n");
		
		printf("1. Cadastrar Acao\n");
		printf("2. Listar Acoes\n");
		printf("3. Pesquisar Acao\n");
		printf("4. Relatorio Geral\n");
		printf("0. Sair\n");
		
		printf("Selecione uma opcao: ");
		scanf("%d", &opcao);

	}
	
	return 0;
}
