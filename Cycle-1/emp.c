// Write a C program to create a structure Employee with fields EmpId, Name and
// Salary. Name should contain first name, middle name and last name. Store the details
// of n employees, dynamically allocating memory for the same. Write a function to
// implement Linear Search to search for a particular employee, given the EmpId.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char first[25];
	char middle[25];
	char last[25];
} Full_name;

typedef struct
{
	int EmpId;
	Full_name Name;
	float Salary;
} Employee;

void Input_details(Employee *, int);
void Linear_search(int, Employee *, int);

void main()
{
	Employee *ptr;
	int EID, n;
	char choice;
	printf("Employee List\n");
	printf("Enter the number of employees : ");
	scanf("%d", &n);
	ptr = (Employee *)malloc(n * sizeof(Employee));
	if (ptr == NULL)
	{
		printf("Error in dyanamic memory allocation\n");
		exit(0);
	}
	Input_details(ptr, n);
	do
	{
		printf("Search Employee\n");
		printf("Enter EmpId : ");
		scanf("%d", &EID);
		Linear_search(EID, ptr, n);
		printf("Do you want to continue searching (y/n) : ");
		scanf(" %c", &choice);
	} while (choice == 'y');
	printf("Thank you!!!\n");
	free(ptr);
}

void Input_details(Employee *p, int n)
{
	printf("Enter the details\n");
	printf("<EmpId> <First name> <Middle name> <Last name> <Salary>\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &(p + i)->EmpId);
		scanf("%s %s %s", (p + i)->Name.first, (p + i)->Name.middle, (p + i)->Name.last);
		scanf("%f", &(p + i)->Salary);
	}
	printf("Details added\n");
}
void Linear_search(int e, Employee *p, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (e == (p + i)->EmpId)
		{
			printf(">%d<   ", (p + i)->EmpId);
			printf(" >%s %s %s< ", (p + i)->Name.first, (p + i)->Name.middle, (p + i)->Name.last);
			printf(" >%.2f<\n", (p + i)->Salary);
			return;
		}
	}
	printf("EmpId not present\n");
}
