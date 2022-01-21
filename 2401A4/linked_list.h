
/*
File name is linked_list.h
 Purpose: file contains functions for manipulating singly linked list

 Revisions
 Doron Nussbaum 2019

  Copyright 2019 Doron Nussbaum


 */


#ifndef LINKED_LIST_2401_HEADER
#define LINKED_LIST_2401_HEADER 1


 /************************************************************************/
 // INCLUDE
#include "person.h"		// person information



 /************************************************************************/
 // DEFINE




/************************************************************************/

// STRUCTURES


typedef struct listNode {
	struct listNode *next;
	PersonInfo	person;		// person information
} ListNode;

/************************************************************************/
// FUNCTION PROTOTYPES


// Insert Functions
ListNode *insertToList(ListNode **head, PersonInfo *person);

ListNode *insertAfter(ListNode *node, char *familyName, PersonInfo *person);



// Delete Functions
int deleteFromList(ListNode **head, PersonInfo *person);

int deleteNodeByName(ListNode **head, char *familyName, PersonInfo *person);

void deleteList(ListNode **head);


// Traversal Functions
// Search Functions
ListNode *searchByName(ListNode *head, char *familyName, PersonInfo *person);

// print functions
void printList(ListNode *head);
void printStudents(ListNode *head);
void printEmployees(ListNode *head);


// Counting Functions
unsigned int listSize(ListNode *head);

// Miscellaneous Functions
int copyList(ListNode *head, ListNode **newListHead);
int copyListRecursive(ListNode *head, ListNode **newListHead);
int removeStudents(ListNode **head);

//Travers functions
void generalTraverse(ListNode *head, void (*fPtr)(PersonInfo*));
void printStudentPtr(struct personInfo* person);

#endif
