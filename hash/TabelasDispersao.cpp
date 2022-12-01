
#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>


#define N 100


struct aluno {
	int mat;
	char nome[81];
	char email[41];
	char turma;
};
typedef struct aluno Aluno;

typedef Aluno* Hash[N];


int hash (int mat){
	return (mat%100);
}


Aluno* busca (Hash tab, int mat){
	int h = hash(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat)
		return tab[h];
		h = (h+1) % N;
	}
	return NULL;
}


Aluno* insere (Hash tab, int mat, char* nome, char* email, char turma){
	int h = hash(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) //Se matricula Igual, atualiza os dados
			break;
		h = (h+1) % N;
	}
		if (tab[h]==NULL) { /* n�o encontrou o elemento */
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
	}
	/* atribui informa��o */
	strcpy(tab[h]->nome,nome);
	strcpy(tab[h]->email,email);
	tab[h]->turma = turma;
	return tab[h];
}

main(){
	Hash  dados;

	//Inicializando
	for(int i = 0; i < N; i++){
		dados[i] = NULL;
	}
	int mat= 0;
	char nome[80];
	char email[40];
	char turma;
	char opcao = 's';
	while (opcao =='s'){
		printf("\nInforme a Mat..[0 a 100]:");
		scanf("%d",&mat );
		fflush(stdin);
		
		printf("\nInforme o Nome..........:");
		scanf("%[ 0-9A-Za-z]s",nome );
		fflush(stdin); 
		
		printf("\nInforme o Email.........:");
		scanf("%[ 0-9A-Za-z@]s",email );
		fflush(stdin); 
		
		printf("\nInforme o Turma.........:");
		scanf("%c",&turma);
		fflush(stdin); 
		
		insere(dados, mat, nome, email, turma);  

		printf("\nDeseja Cadastrar outro? [s/n]:");
		scanf("%c",&opcao);
	}


	//Mostra
	for(int i = 0; i < N; i++){
		if (dados[i]!= NULL) {
			printf("\n------------------------");
			printf("\nIndice: %d", i);
			printf("\nMat...: %d", dados[i]->mat);
			printf("\nNome..: %s", dados[i]->nome);
			printf("\nemail.: %s", dados[i]->email);
			printf("\nTurma.: %c", dados[i]->turma);
		}
	}
}
