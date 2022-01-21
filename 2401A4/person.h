
/* 
File name is person.h
 Purpose: file contains the structures of persons  who are part of Carleton University community
 
 Revisions
 Doron Nussbaum October 2019

  Copyright 2019 Doron Nussbaum

 
 */


#ifndef PERSON_2401_HEADER
#define PERSON_2401_HEADER 1


/************************************************************************/
// DEFINE

#define NAME_LENGTH 16		// length of a name
#define STUDENT_TYPE  1	// type is a student
#define EMPLOYEE_TYPE  2	// type is an employee



/************************************************************************/

// STRUCTURES
// student information
typedef struct studentInfo {
	float gpa;			// the gpa of the student
	unsigned char numCompletedCourses;		// number of completed courses
	unsigned char numRequiredCourses;		// number of required courses
} StudentInfo;


// employee information
typedef struct employeeInfo {
	float salary;					// salary of employee
	unsigned char yearsOService;	// number of years at Carleton U. 
} EmployeeInfo;



typedef struct personInfo {
	unsigned int id;			// the id of the person
	union {
		StudentInfo	stu;		// student specific information
		EmployeeInfo emp;		// employee specific information 
	};
	char firstName[NAME_LENGTH];	// person's first name
	char familyName[NAME_LENGTH];	// person's family name
	char empOrStudent;				// a discriminator whether the struct is of a student or a person
									// if empOrStudent == STUDENT_TYPE then the information is of a student
									// if empOrStudent == EMPLOYEE_TYPE then the inforamtion is of an employee
} PersonInfo;

/************************************************************************/
// FUNCTION PROTOTYPES


// Insert Functions 
void printEmployee(PersonInfo *person);

void printStudent(PersonInfo *person);


#endif
