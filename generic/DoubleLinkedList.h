#ifndef DoubleLinkedList
#define DoubleLinkedList

#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"


struct Node {
    Student * student;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

typedef struct {
    struct Node * first;//holds the first item in the list
	int size;//keep track of the size of the list
} LinkedList;

//See if the item has a next item. Returns 1 to true and 0 to false
int hasNext(struct Node * node){
    if(node->next != NULL) return 1;
	return 0;
}

//See if the List is empty. Returns 1 to true and 0 to false
int estahVazia(LinkedList * list) {
	return (list->first == NULL);
}

//Create a new list with size 0, and set the first item to NULL
void criarLista (LinkedList* list) {
    list->size = 0;
    list->first->next = NULL;
    list->first->prev = NULL;
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(LinkedList* list, Student * new_student){
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 2. put in the student  */
    new_node->student = new_student;

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = list->first;
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if (list->first != NULL)
        list->first->prev = new_node;

    /* 5. move the head to point to the new node */
    list->first = new_node;
}

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node* prev_node, Student * new_student)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 3. put in the student  */
    new_node->student = new_student;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(LinkedList* list, Student * new_student)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = list->first; /* used in step 5*/

	/* 2. put in the student */
	new_node->student = new_student;

	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (list->first == NULL) {
		new_node->prev = NULL;
		list->first = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}

int deleteNode(LinkedList* list, struct Node* del)
{
    /* base case */
    if (list->first == NULL || del == NULL)
        return 0;

    /* If node to be deleted is head node */
    if (list->first == del)
        list->first = del->next;

    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    freeStudentData(del->student);
    free(del->student);
    free(del);
    return 1;
}

/* Function to delete the node at the given position
   in the doubly linked list */
int deleteNodeAtGivenPos(LinkedList* list, int n)
{
    /* if list in NULL or invalid position is given */
    if (list->first == NULL || n <= 0)
        return 0;

    struct Node* current = list->first;

    /* traverse up to the node at position 'n' from
       the beginning */
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;

    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
        return 0;

    /* delete the node pointed to by 'current' */
    return deleteNode(list, current);
}

Student * getStudentAtGivenPos(LinkedList* list, int n){
    /* if list in NULL or invalid position is given */
    if (list->first == NULL || n <= 0)
        return;

    struct Node* current = list->first;

    /* traverse up to the node at position 'n' from
       the beginning */
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;

    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
        return;

    return current->student;
}

//search for the node with the given student name and returns its position
int searchNodeAtGivenName(LinkedList* list, char * name){
    /* if list in NULL or invalid position is given */
    if (list->first == NULL || name == NULL)
        return -1;

    struct Node* current = list->first;

    /* traverse up to the node at position 'n' from
       the beginning */
    for(int i = 1; current != NULL; i++){
        if (comparaString(current->student->name, name))
            return i;
        current = current->next;
    }

    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
        return -1;
}

// This function prints contents of linked list starting
// from the given node
int printList(LinkedList* list){

    if(estahVazia(list)){
		return -1;
	}

    struct Node* item_next;
    item_next = list->first;

    while (item_next != NULL) {
        printStudent(item_next->student);
        item_next = item_next->next;
    }
    return 1;
}

#endif