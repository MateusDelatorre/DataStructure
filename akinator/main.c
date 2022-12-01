#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BinaryTree.h"

void guessWho(TreeBranch ** tree_branch);
int askQuestion(char * question);
struct branch* createQuestion();

//Make the main menu
int main() {

    TreeRoot tree;
    newTree(&tree);
	tree.first = createQuestion();
	int i = 1;

	while (i){
		if(askQuestion("deseja continuar? ")){
			guessWho(&tree.first);
			continue;
		}else{
			break;
		}
	}
	

    return 0;
}

void guessWho(struct branch ** tree_branch){
	if(*tree_branch != NULL){
		char str [100];
		strcpy(str,"Eh um ");
		int i = 0;
		int tree_side = askQuestion((*tree_branch)->pergunta);
		if(tree_side){
			strcat(str, (*tree_branch)->positivo);
			i = askQuestion(str);
		}else{
			strcat(str, (*tree_branch)->negativo);
			i = askQuestion(str);
		}
		if(i){
			return;
		}else{
			if (tree_side){
				guessWho(&(*tree_branch)->right_branch);
			}else{
				guessWho(&(*tree_branch)->left_branch);
			}
		}
	}else{
		*tree_branch = createQuestion();
	}
}

int askQuestion(char * question){
	char answer;
	while(*question!='\0'){
		printf("%c",*question++);
	}
	printf(" y|n");
	printf("\n");
	scanf("%c", &answer);
	// char flush;
	// scanf("%c", &flush);
	fflush(stdin);//cleans the input file
	if (answer == 89 || answer == 121)
	{
		return 1;
	}else{
		return 0;
	}
}

struct branch* createQuestion(){
	printf("Acabou as pergunta ;-;\n");
	char question[256];
	char sim[100];
	char nao[100];
	printf("Qual eh a pergunta?\n");
	scanf("%[^\n]", question);
    fflush(stdin);//cleans the input file

	printf("Resposta sim: ");
	scanf("%[^\n]", sim);
    fflush(stdin);//cleans the input file

	printf("Resposta nao: ");
	scanf("%[^\n]", nao);
    fflush(stdin);//cleans the input file
	
	struct branch * new_branch = newBranch();
	strcpy(new_branch->pergunta, question);
	strcpy(new_branch->positivo, sim);
	strcpy(new_branch->negativo, nao);
	return new_branch;
}