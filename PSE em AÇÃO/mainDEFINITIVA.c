#include <stdio.h>
#include <stdlib.h>

/* Cada campo da acao fica em um vetor; a acao i usa a posicao i de todos */
int codigos[100];
char escolas[100][50];
char temas[100][50];
char datas[100][15];
char publicos[100][50];
char responsaveis[100][50];
int previstos[100];
int situacoes[100];   /* 1 = planejada, 2 = realizada, 3 = cancelada */
int efetivos[100];
int total = 0;

void cadastrar_acao(){
	int i, codigo, repetido;
	
	if(total == 100){
		printf("Limite de acoes atingido.\n");
		return;
	}
	
	do{
		repetido = 0;
		printf("Codigo da acao: ");
		scanf("%d", &codigo);
		for(i = 0; i < total; i++){
			if(codigos[i] == codigo){
				repetido = 1;
			}
		}
		if(repetido == 1){
			printf("Erro: codigo ja cadastrado.\n");
		}
	}while(repetido == 1);
	codigos[total] = codigo;
	
	printf("Escola: ");
	scanf(" %49[^\n]", escolas[total]);
	printf("Tema: ");
	scanf(" %49[^\n]", temas[total]);
	printf("Data prevista: ");
	scanf(" %14[^\n]", datas[total]);
	printf("Publico-alvo: ");
	scanf(" %49[^\n]", publicos[total]);
	printf("Responsavel: ");
	scanf(" %49[^\n]", responsaveis[total]);
	
	do{
		printf("Quantidade prevista de participantes: ");
		scanf("%d", &previstos[total]);
		if(previstos[total] < 0){
			printf("Erro: a quantidade nao pode ser negativa.\n");
		}
	}while(previstos[total] < 0);
	
	do{
		printf("Situacao inicial (1-Planejada 2-Realizada 3-Cancelada): ");
		scanf("%d", &situacoes[total]);
		if(situacoes[total] < 1 || situacoes[total] > 3){
			printf("Erro: situacao invalida.\n");
		}
	}while(situacoes[total] < 1 || situacoes[total] > 3);
	
	efetivos[total] = 0;
	if(situacoes[total] == 2){
		do{
			printf("Quantidade efetiva de participantes: ");
			scanf("%d", &efetivos[total]);
			if(efetivos[total] < 0){
				printf("Erro: a quantidade nao pode ser negativa.\n");
			}
		}while(efetivos[total] < 0);
	}
	
	total++;
	printf("Acao cadastrada com sucesso!\n");
}

void listar_acoes(){
	int i;
	
	if(total == 0){
		printf("Nenhuma acao cadastrada.\n");
	}
	for(i = 0; i < total; i++){
		printf("------------------------------\n");
		printf("Codigo: %d\n", codigos[i]);
		printf("Escola: %s\n", escolas[i]);
		printf("Tema: %s\n", temas[i]);
		printf("Data prevista: %s\n", datas[i]);
		printf("Publico-alvo: %s\n", publicos[i]);
		printf("Responsavel: %s\n", responsaveis[i]);
		printf("Participantes previstos: %d\n", previstos[i]);
		if(situacoes[i] == 1){
			printf("Situacao: Planejada\n");
		}else if(situacoes[i] == 2){
			printf("Situacao: Realizada\n");
			printf("Participantes efetivos: %d\n", efetivos[i]);
		}else{
			printf("Situacao: Cancelada\n");
		}
	}
}

void pesquisar_acao(){
	int i, j, opcao, codigo, achou = 0, igual;
	char texto[50];
	
	do{
		printf("Pesquisar por (1-Codigo 2-Escola 3-Tema): ");
		scanf("%d", &opcao);
		if(opcao < 1 || opcao > 3){
			printf("Erro: opcao invalida.\n");
		}
	}while(opcao < 1 || opcao > 3);
	
	if(opcao == 1){
		printf("Codigo: ");
		scanf("%d", &codigo);
	}else{
		printf("Digite o nome: ");
		scanf(" %49[^\n]", texto);
	}
	
	for(i = 0; i < total; i++){
		igual = 0;
		if(opcao == 1){
			if(codigos[i] == codigo){
				igual = 1;
			}
		}else{
			/* compara o texto digitado com a escola (opcao 2) ou o tema (opcao 3) */
			j = 0;
			if(opcao == 2){
				while(texto[j] != '\0' && texto[j] == escolas[i][j]){
					j++;
				}
				if(texto[j] == escolas[i][j]){
					igual = 1;
				}
			}else{
				while(texto[j] != '\0' && texto[j] == temas[i][j]){
					j++;
				}
				if(texto[j] == temas[i][j]){
					igual = 1;
				}
			}
		}
		
		if(igual == 1){
			achou = 1;
			printf("------------------------------\n");
			printf("Codigo: %d\n", codigos[i]);
			printf("Escola: %s\n", escolas[i]);
			printf("Tema: %s\n", temas[i]);
			printf("Data prevista: %s\n", datas[i]);
			printf("Publico-alvo: %s\n", publicos[i]);
			printf("Responsavel: %s\n", responsaveis[i]);
			printf("Participantes previstos: %d\n", previstos[i]);
			if(situacoes[i] == 1){
				printf("Situacao: Planejada\n");
			}else if(situacoes[i] == 2){
				printf("Situacao: Realizada\n");
				printf("Participantes efetivos: %d\n", efetivos[i]);
			}else{
				printf("Situacao: Cancelada\n");
			}
		}
	}
	
	if(achou == 0){
		printf("Nenhuma acao encontrada.\n");
	}
}

void atualizar_situacao(){
	int i, codigo, posicao = -1;
	
	printf("Codigo da acao: ");
	scanf("%d", &codigo);
	for(i = 0; i < total; i++){
		if(codigos[i] == codigo){
			posicao = i;
		}
	}
	if(posicao == -1){
		printf("Nenhuma acao encontrada.\n");
		return;
	}
	
	do{
		printf("Nova situacao (1-Planejada 2-Realizada 3-Cancelada): ");
		scanf("%d", &situacoes[posicao]);
		if(situacoes[posicao] < 1 || situacoes[posicao] > 3){
			printf("Erro: situacao invalida.\n");
		}
	}while(situacoes[posicao] < 1 || situacoes[posicao] > 3);
	
	efetivos[posicao] = 0;
	if(situacoes[posicao] == 2){
		do{
			printf("Quantidade efetiva de participantes: ");
			scanf("%d", &efetivos[posicao]);
			if(efetivos[posicao] < 0){
				printf("Erro: a quantidade nao pode ser negativa.\n");
			}
		}while(efetivos[posicao] < 0);
	}
	printf("Situacao atualizada com sucesso!\n");
}

void resumo_geral(){
	int i, planejadas = 0, realizadas = 0, canceladas = 0;
	int totalEfetivos = 0, previstosRealizadas = 0;
	
	for(i = 0; i < total; i++){
		if(situacoes[i] == 1){
			planejadas++;
		}else if(situacoes[i] == 2){
			realizadas++;
			totalEfetivos += efetivos[i];
			previstosRealizadas += previstos[i];
		}else{
			canceladas++;
		}
	}
	
	printf("Acoes planejadas: %d\n", planejadas);
	printf("Acoes realizadas: %d\n", realizadas);
	printf("Acoes canceladas: %d\n", canceladas);
	printf("Total de participantes: %d\n", totalEfetivos);
	if(previstosRealizadas > 0){
		printf("Percentual de participacao: %.1f%%\n", 100.0 * totalEfetivos / previstosRealizadas);
	}else{
		printf("Percentual de participacao: 0%%\n");
	}
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
		printf("5. Atualizar Situacao\n");
		printf("0. Sair\n");
		
		printf("Selecione uma opcao: ");
		scanf("%d", &opcao);
		
		if(opcao == 1){
			cadastrar_acao();
		}else if(opcao == 2){
			listar_acoes();
		}else if(opcao == 3){
			pesquisar_acao();
		}else if(opcao == 4){
			resumo_geral();
		}else if(opcao == 5){
			atualizar_situacao();
		}else if(opcao != 0){
			printf("Erro: opcao invalida.\n");
		}
		printf("\n");
	}
	
	return 0;
}
