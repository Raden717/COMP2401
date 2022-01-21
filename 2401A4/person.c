
/* 
File name is person.c
 Purpose: file contains functions for manipulating person record
 
 Revisions
 Doron Nussbaum 2019

  Copyright 2019 Doron Nussbaum

 
 */


 /************************************************************************/
 // INCLUDE

#include "stdio.h"
#include "person.h"


/************************************************************************/
/*
Purpose: prints the person record as a student  

input
person - the student information
*/



void printEmployee(PersonInfo *person)
{
	printf("%-16s %-16s %8d %4d %7.2f \n", person->firstName, person->familyName, person->id,
		person->emp.yearsOService, person->emp.salary);
}



/************************************************************************/
/*
Purpose: prints the person record as an employee  

input
person - the employee information
*/



void printStudent(PersonInfo *person)	
{
	printf("%-16s %-16s %8d %5.2f %3d %3d \n", person->firstName, person->familyName, person->id,
	person->stu.gpa, person->stu.numCompletedCourses, person->stu.numRequiredCourses);
}


/************************************************************************/



