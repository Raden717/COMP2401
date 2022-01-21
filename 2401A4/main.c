// FILE IS main.c
/*
Description:

This is an exmaple of a test program that you should write to test your code.
The testing is not complete because it checks only a subset of the required functionality
and not all aspects of it.

The file includes a function to populate the struct personInfo with with either student or employee information.  The function is used to create data required for testing linked list insertion function.
The function name is populatePerson()

This code will not be used by the TAs to test your code.


Revisions:
Doron Nussbaum 2019
Copyright Doron Nussbaum 2019

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "linked_list.h"
#include "person.h"

#define CONTINUE {printf("hit <cr> to continue \n"); getchar();}

void populatePerson(PersonInfo *person);


int main(int argc, char* argv[])
{
	PersonInfo person;
	ListNode *head = NULL;
	ListNode *newListHead = NULL;
	ListNode *p = NULL, *q = NULL;
    char familyName[64];
	int i;
    int rc = 0;

	for (i = 0; i < 20; i++) {
	// add code for testing
		populatePerson(&person);
		p = insertToList(&head,  &person);
	}


	printList(head);

	printf("\n\n test insert after \n");

	if (p != NULL) {
		for (i = 0; i < 4; i++) {
			populatePerson(&person);
			p = insertAfter(head, p->person.familyName, &person);
		}
	}

	printList(head);
    CONTINUE;

    // test delete after
	printf("\n\nPrinting how many nodes are in the original list before deletion : ");
	printf("%u\n", listSize(head));
	CONTINUE;

	rc = deleteNodeByName(&head, "Bronson", &person);
    printf("deleteAfter rc = %d \n",rc);
	printList(head);
    CONTINUE;


	p = searchByName(head, "Bronson", &person);
	if (p != NULL) {
		printf("\n found name to delete \n");
		printEmployee(&p->person);
		strncpy(familyName, p->person.familyName, NAME_LENGTH-1);
        familyName[NAME_LENGTH-1] = '\0';
		deleteNodeByName(&head, familyName, &person);
	}

	printf("\n\nPrinting how many nodes are in the original list after deletion : ");
	printf("%u\n", listSize(head));
	CONTINUE;

	printList(head);
	CONTINUE;

	printf("\n\n duplicate list \n\n");

	printList(head);
	copyList(head, &newListHead);
	printf("Duplicated List BELOW ------------ Original ABOVE\n");
	printList(newListHead);
	CONTINUE;


	printf("\n\n print students \n\n");
	printStudents(newListHead);

	printf("\n\n print employees \n\n");
	printEmployees(newListHead);
	CONTINUE;

	printf("\n\n remove students \n\n  ");
	removeStudents(&newListHead);
	printList(newListHead);
	CONTINUE;

	printf("Using generalTraverse on ORIGINAL LIST that has not removed students \n\n");
	generalTraverse(head,printStudentPtr);
	CONTINUE;

	printf("\n\nNow deleting lists \n\n\n");
	deleteList(&head);
	deleteList(&newListHead);
	//	getchar();


	return 0;
}




/***************************************************************************/
/* purpose: the function populate the person info

input/output
struct personInfo *p - allocated memory to the struct pointer which the function assigns values.




*/

void populatePerson(PersonInfo *person)
{
	static int initRand = 0;
	int j;
	char *first[10] = { "John", "Don", "Edna", "Bev", "Miya", "Oliver", "James", "Liam", "Emily", "Alice"  };
	char *family[10] = { "Broker", "Smith", "Tower", "Little", "Bronson", "Brown", "Tayloy", "King", "Green", "Baker"   };

	if (!initRand) {
		srand(1557);
		initRand ++;
	}
	// populate the first  name using a random i ndex to the first name array
	j = rand() % 10;
	// copy the first name to the structure pointed by p using strcpy
	strncpy(person->firstName, first[j], NAME_LENGTH);

	// populate the first  name using a random i ndex to the first name array
	j = rand() % 10;
	// copy the family name to the structure pointed by p using strcpy
	strncpy(person->familyName, family[j], NAME_LENGTH);

	// populate the student id using the random numnber in the range of 0-4096
	person->id = rand() % 150;

	// populate either the student field of the employee field
	if (rand() % 100 < 20) {
		// employee record
		person->emp.salary = rand() % 50000 + 50000;
		person->emp.yearsOService = rand() % 41;
		person->empOrStudent = EMPLOYEE_TYPE;
	}
	else {
		// student record
		person->stu.gpa = rand() % 9 + 4;
		person->stu.numCompletedCourses = rand() % 31 + 10;
		person->stu.numRequiredCourses = 40;
		person->empOrStudent = STUDENT_TYPE;

	}

}
