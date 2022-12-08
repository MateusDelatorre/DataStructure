#ifndef BinaryTree
#define BinaryTree

#include <stdio.h>
#include <stdlib.h>
#include "generic.h"

//struct that represent a treeNode
struct branch {
	GenericData * data;
	struct branch * right_branch;//The right branch will be the direction when the user says no
	struct branch * left_branch;//The left branch will be direction when the user says yes
};

typedef struct branch TreeBranch;

struct Root{
    struct branch * first;
	int size;
};

typedef struct Root TreeRoot;

//check if the node has a left branch
int hasLeftBranch(struct branch * branch){
    if(branch->left_branch != NULL) return 1;
	return 0;
}

//check if the node has a right branch
int hasRigthBranch(struct branch * branch){
    if(branch->right_branch != NULL) return 1;
	return 0;
}

//check if the tree is empty
int isEmpty(TreeRoot * list) {
	return (list->first == NULL);
}

//check if the tree is full
int isFull(TreeRoot * list) {
	return (list->size < 30);
}

//Create a new tree
TreeRoot * newTree () {
	TreeRoot * new_root;
	new_root = (TreeRoot *) malloc(sizeof(TreeRoot));
	new_root->first = NULL;
	new_root->size = 0;
	return new_root;
}

struct branch* newBranch(size_t size){
	struct branch * new_branch;
	new_branch = (struct branch*) malloc(sizeof(struct branch));
	new_branch->left_branch = NULL;
	new_branch->right_branch = NULL;
	return new_branch;
}

struct branch* addSort(struct branch * tree_branch, GenericData ** new_data, int (*compare)(void *, void *)){
	if(tree_branch == NULL){
		//printf("BinaryTree.h:65\n");
		struct branch * new_branch;
		new_branch = (struct branch*) malloc(sizeof(struct branch));
		new_branch->data = newGenericData((*new_data)->size);
		new_branch->data = *new_data;
		new_branch->left_branch = NULL;
		new_branch->right_branch = NULL;
		return new_branch;
	}else{
		//printf("BinaryTree.h:74\n");
		//printf("compare: %d\n", (*compare)(tree_branch->data->data, (*new_data)->data));
		if ((*compare)(tree_branch->data->data, (*new_data)->data) > 0){
			tree_branch->left_branch = addSort(tree_branch->left_branch, new_data, compare);
		}else if ((*compare)(tree_branch->data->data, (*new_data)->data) < 0){
			tree_branch->right_branch = addSort(tree_branch->right_branch, new_data, compare);
		}else{
			printf("duplicated\n");
		}
	}
}

void addToTreeSort(TreeRoot ** tree_root, GenericData ** new_data, int (*compare)(void *, void *)){
	if((*tree_root)->first == NULL){
		struct branch * new_branch;
		new_branch = (struct branch*) malloc(sizeof(struct branch));
		new_branch->data = newGenericData((*new_data)->size);
		new_branch->data = *new_data;
		new_branch->left_branch = NULL;
		new_branch->right_branch = NULL;
		(*tree_root)->first = new_branch;
	}else{
		printf("compare: %d\n", (*compare)((*tree_root)->first->data->data, (*new_data)->data));
		if ((*compare)((*tree_root)->first->data->data, (*new_data)->data) > 0){
			(*tree_root)->first->left_branch = addSort((*tree_root)->first->left_branch, new_data, compare);
		}else if ((*compare)((*tree_root)->first->data->data, (*new_data)->data) < 0){
			(*tree_root)->first->right_branch = addSort((*tree_root)->first->right_branch, new_data, compare);
		}else{
			printf("duplicated\n");
		}
	}
	return;
}

// struct branch* addSortBranchs(struct branch * tree_branch, struct branch * new_branch){
// 	if(tree_branch == NULL){
// 		return new_branch;
// 	}else{
// 		if (tree_branch->student->enroll > new_branch->student->enroll)
// 		{
// 			tree_branch->left_branch = addSortBranchs(tree_branch->left_branch, new_branch);
// 		}else if (tree_branch->student->enroll < new_branch->student->enroll)
// 		{
// 			tree_branch->right_branch = addSortBranchs(tree_branch->right_branch, new_branch);
// 		}else{
// 			printf("duplicated\n");
// 		}
// 	}
// }

void goThroughBranchs(TreeRoot * root, TreeBranch * tree_branch, struct branch* (*f)(struct branch * tree_branch, struct branch * new_branch)){//
	if(tree_branch != NULL){
		goThroughBranchs(root, tree_branch->left_branch, f);
		goThroughBranchs(root, tree_branch->right_branch, f);
		(*f)(tree_branch, root->first);
	}
}

void TreeSize(TreeRoot * root){
	root->size += 1;
}

// void printBranch(TreeBranch * tree_branch){
// 	printStudent(tree_branch->student);
// }

//Go to the lowest branch and start to trigger a function call for all branches.
void goThroughTree(TreeBranch * tree_branch, void (*f)(TreeBranch * tree_branch)){//
	if(tree_branch != NULL){
		goThroughTree(tree_branch->left_branch, f);
		(*f)(tree_branch);
		goThroughTree(tree_branch->right_branch, f);
	}
}

struct branch* find(TreeBranch * tree_branch, void * query, int (*compare)(void *, void *)){
	if(tree_branch == NULL){
		printf("Can't find your data\n");
		return NULL;
	}else{
		if ((*compare)(tree_branch->data->data, query) > 0)
		{
			find(tree_branch->left_branch, query, compare);
		}else if ((*compare)(tree_branch->data->data, query) < 0)
		{
			find(tree_branch->right_branch, query, compare);
		}else{
			return tree_branch;
		}
	}
}

// int deleteBranch(TreeRoot * root, int enroll){
// 	TreeBranch * tree_branch = find(root->first, enroll);
// 	if (tree_branch == NULL)
// 	{
// 		return 0;
// 	}

// 	struct branch * new_branch;
// 	new_branch = (struct branch*) malloc(sizeof(struct branch));
// 	new_branch->left_branch = tree_branch->left_branch;
// 	new_branch->right_branch = tree_branch->right_branch;
	
// 	// free(tree_branch->student);
// 	// free(tree_branch);
// 	tree_branch = NULL;
	
// 	goThroughBranchs(root, new_branch->left_branch, addSortBranchs);
// 	goThroughBranchs(root, new_branch->right_branch, addSortBranchs);
	
// 	free(new_branch);
// 	return 1;
// }

#endif