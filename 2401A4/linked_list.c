
/*
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list

 Revisions
 Doron Nussbaum 2019





 Copyright 2019 Doron Nussbaum

 */

/******************************************************************/
// INCLUDE

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// DEFINE



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
head - head of linked list
person - the data of the new person

output
head - head of linked list

return
A pointer to the node that was allocated.
NULL - if the operation was not successful

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL
2. person is not NULL

*/

ListNode *insertToList(ListNode **head, PersonInfo *person)
{

  ListNode *p = NULL; //New node to insert to list

  p = malloc(sizeof(ListNode));

  //Setting values for the new node
  p->person = *person;
  p->next = NULL;

  if(head != NULL){ //Sees if it's the first node or not
    p->next = *head;
    *head = p;
  } else {
    *head = p;
  }
	// add code
   //



}


/************************************************************************/
/*
Purpose: find the first node in the list with the input family name and insert a new node containing the
person data into the list.

If there is no node that matches that given family name then the operation is considered a failure.

Input
head - head of list
familyName - the family name that must be used to find the first matching recrod
person - the person record to insert into the list as new node


return
A pointer to the node that was allocated.

NULL - if the operation was not successful

Assumptions:
familyName is not NULL
person is not NULL

*/


ListNode *insertAfter(ListNode *head, char *familyName, PersonInfo *person)
{
  if(head == NULL){ //Checks if empty
    return NULL;

  } else {

    while(1)  //Loop to iterate through the list until the name is found or not

      if(head->person.familyName == familyName){ //Checks first node if it matches the name
        ListNode *newNode = NULL;
        newNode = malloc(sizeof(ListNode));
        newNode->person = *person;          //Creating the new node and putting it between the current node and the following node
        newNode->next = head->next;
        head->next = newNode;
        return head;
      }

      else { //Checks all the nodes after
        ListNode *ptr = head->next;
        while(1)
          if(ptr->person.familyName == familyName){ //Checks if the current node matches the family name
            ListNode *newNode;
            newNode = malloc(sizeof(ListNode));
            newNode->person = *person;         //Creating the new node and putting it between the current node and the following node
            newNode->next = ptr->next;
            return head;
          } else {                  //If the node does not match, it iterates to the next one
            if(ptr->next != NULL){
              ptr = ptr->next;
            } else {    //If the next node is null its reached the end of the list, breaks the loop which then returns NULL as there was no matching name
              break;
            }
          }
          return NULL;
      }
  }
	// add code



}


/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
person - person data that is stored in the list


return
0 if node was deleted
1 if node was not deleted or list is empty

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty
2. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteFromList(ListNode **head, PersonInfo *person)
{
    ListNode *new = NULL;

  if(*head == NULL){  //Checks if list is empty
    person = NULL;
    return 1;

  }

  else {
    new = *head;  //Temporary pointer to be later freed
    if(person != NULL)  //Checks if person is NULL to see whether there will be a person output
      *person = new->person;
    *head = new->next;
    free(new);  //Freeing the removed node
    return(0);
  }

	// add code

}


/************************************************************************/

/*
Purpose: delete the first node with the matching family name
Input
head - the head of the list
familyName - family name of person

output
head - the head of the list
person - data of the person in the node


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

Assumptions
1. familyName is not NULL
2. Function has to be robuse enough to handle cases where head is NULL or the list is empty
3. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteNodeByName(ListNode **head, char *familyName, PersonInfo *person)
{
  if(*head == NULL){ //Checks if head is null
    return 1;
  }

  else {
    //Placeholder pointer
    ListNode *new = NULL;
    new = *head;
    int check = 1; //Used to break or continue a future loop

    if(strcmp((*head)->person.familyName,familyName) == 0){ //Base case if the head of the list is to be removed
      ListNode *new = NULL;
      new = *head;
      *head = (*head)->next;
      free(new);
      return 0;
    }

    while(check == 1) //Iterates through the list until finds a matching name or reaches end of the list
      if(new->next != NULL){
        if(strcmp(new->next->person.familyName,familyName) == 0){ //Sees if matching name
          ListNode *skip = NULL;
          skip = new->next;       //Temp node for the removed node
          new->next = skip->next; //Pointing to the next node to "remove this node"
          free(skip);             //Freeing the skip value as this is the removed node
          return 0;
        } else {
          new = new->next;
        }

      } else { //Means the next value of the node is non existent which then breaks then returns 1
        check = 0;
        return 1;
      }
  }
	// add code


}
/************************************************************************/
/*
Purpose: deletes all nodes from the list

input
head - the head of the list

output
head - the head of the list

return
none

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/


void deleteList(ListNode **head)
{

  while(*head != NULL){ //Iterates through the list until it's empty
    ListNode *ptr = NULL;  //Temporary Node that will get freed
    ptr = *head;
    *head = (*head)->next; //Setting a new head to delete the head
    free(ptr);  //Frees the temp node
  }
	// add code


}



/************************************************************************/
/*
Purpose: search for the first node with the matching familyName
Input
head - the head of the list
familyName - family name of person

Output
person - a copy of the person record in the node

return
a pointer to the node that was found.
NULL - if no node was found or list empty


Assumptions
1. familyName is not NULL
2. person can be NULL.  If person is NULL then no coping of the person record is required.

*/


ListNode *searchByName(ListNode *head, char *familyName, PersonInfo *person)
{
  if(head == NULL){ //If empty
    return NULL;
  }
  //Temporary nodes
  ListNode *new = NULL;
  new = head;
  int check = 1;

  while(check == 1)
    if(strcmp(new->person.familyName,familyName) == 0){ //Sees if matching name
      check = 0;
      if(person != NULL){     //Sees if person input was null to see whether or not to copy the person record
        *person = new->person;
        return new;
      }
      return new;
    }

    else {
      if(new->next == NULL){ //Sees if it reaches the end of the list
        check = 0;
        return NULL;
      }
      new = new->next;      //Else continues to iterate
    }
	// add code



}



/************************************************************************/
/*
Purpose: prints all the records in the list according to their type a student or an employee

input
head - the head of the list
*/


void printList(ListNode *head)
{
  while(head != NULL){ //Iterates through the list
    if(head->person.empOrStudent == STUDENT_TYPE){ //Checks if student to then print student info
      printStudent(&head->person);
    } else {                                       //otherwise prints employee info since not a student
      printEmployee(&head->person);
    }
    head = head->next; //Goes to the next node
  }
	// add code


}

/************************************************************************/
/*
Purpose: prints all the students in the list

input
head - the head of the list

Output
None

Return
None
*/


void printStudents(ListNode *head)
{
  while(head != NULL){
    if(head->person.empOrStudent == STUDENT_TYPE){ //Checks if its a student
      printStudent(&head->person);
    }
    head = head->next;
  }
	// add code




}
/************************************************************************/
/*
Purpose: prints all the employees in the list

input
head - the head of the list

Output
None

Return
None
*/


void printEmployees(ListNode *head)
{

  while(head != NULL){
    if(head->person.empOrStudent == EMPLOYEE_TYPE){ //Checks if its an employee
      printEmployee(&head->person);
    }
    head = head->next;
  }
	// add code


}


/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return
the number of nodes in the list

*/


unsigned int listSize(ListNode *head)
{
  unsigned int count = 0;
  while(head != NULL){
    count++;
    head = head->next;
  }
  return count;
	// add code



}




/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL


*/
int copyList(ListNode *head, ListNode **newListHead)

{
  if(head == NULL){
    return 1;
  }
  ListNode *tail = NULL;     //Necessary to copy the list iteratively otherwise it will copy in reverse
  ListNode *start = NULL;
  while(head != NULL){  //Loops through entire list until it's empty
    if(*newListHead == NULL){ //Base case making the first and last pointers the same nodes
      start = malloc(sizeof(ListNode));
      start->person = head->person;
      start->next = NULL;
      start->next = *newListHead;
      *newListHead = start;
      tail = *newListHead;
    } else {
      tail->next = malloc(sizeof(ListNode));  //Adds the nodes to the end of the list
      tail = tail->next;
      tail->person = head->person;
      tail->next = NULL;
    }
    head = head->next;  //Iterating to the next node
  }
  return 0;


}
/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL

*/
int copyListRecursive(ListNode *head, ListNode **newListHead)
{
  if(head == NULL){
    return 1;
  } else {
    copyListRecursive(head->next,newListHead);
    ListNode *p = NULL;
    p = malloc(sizeof(ListNode));
    p->person = head->person;
    p->next = *newListHead;
    *newListHead = p;
  }
}

/************************************************************************/
/*
Purpose: removes all the nodes that have student data from the list
input
head - the head of the list

output
head the modified list

return
0 if successful
1 if failed

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/

int removeStudents(ListNode **head)

{
  if(*head == NULL){
    return 1;
  }
  int check = 1;
  while(check)
    if((*head)->person.empOrStudent == STUDENT_TYPE){
      ListNode *ptr2 = NULL;
      ptr2 = *head;
      *head = (*head)->next;
      free(ptr2);
    } else {
      check = 0;
    }

  ListNode *new = NULL;
  new = *head;
  while(1)
    if((new)->next != NULL){
      if(new->next->person.empOrStudent == STUDENT_TYPE){
        ListNode *ptr;
        ptr = new->next;
        new->next = ptr->next;
        free(ptr);
      } else {
        new = new->next;
      }
    } else {
      return 0;
    }


}

/************************************************************************/
/*
Purpose: Print out student information from the list using a function

head - the head of the list
fPtr - a function

output
Prints student information

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/

void generalTraverse(ListNode *head, void (*fPtr)(PersonInfo*)){
  while(head != NULL){
    fPtr(&head->person);  //Uses the function on the person from the ListNode
    head = head->next;
  }
}

/************************************************************************/
/*
Purpose: Print out student information

person - structure personInfo

output
Prints student information

*/

void printStudentPtr(struct personInfo* person)
{
  if(person->empOrStudent == STUDENT_TYPE){ //Checks if student
    printStudent(person);
  }

}
