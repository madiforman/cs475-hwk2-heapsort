/*  Heapsort - CS 475  */
/*  Author: Madison Sanchez-Forman | Version: 2.4.22  */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"
#define MAX_EMPLOYEES 3 						/*max number of employees to be input*/
/**
 * handles getting and returning user response to menu options
 * @return	C char response
 */
char get_menu_option()
{
	char c;
	printf("Enter another user (y/n)? ");
	c = getchar();
	printf("\n");	
	getchar(); 									/*i was having problems with unwanted chars in my output because of unflushed stdin, i was researching it and found that for simple situations, this can work however there are definitely better ways of doing it*/
	return c;	
}
/**
 * Gets name and pay of each index of employee list
 * @param e employee to update information
 * @return e employee with updated information
 */
struct Employee get_info(struct Employee e) 
{
	struct Employee *e_ptr = &e; 			/*create a pointer to the employee*/
	char id[MAX_NAME_LEN];					/*holds employee name*/
	char buffer[10000];						/*buffer for converting string to int*/
	int pay, i, len;
	printf("Name: ");
	if(fgets(id, sizeof(id), stdin)){
	len = strlen(id);
	}
	id[strcspn(id, "\n")]=0; 				/*remove new line char from name*/
	printf("Salary: ");
	if(fgets(buffer, sizeof(buffer), stdin)){
	if(sscanf(buffer, "%d",&i)==1){			/*ensure string is able to be cast to int*/
		buffer[strcspn(buffer, "\n")]=0;	/*remove new line*/
	} 
	}
	pay = atoi(buffer);					    /*cast string to int*/
	e_ptr->salary=pay;						/*use pointer to set pay*/
	memcpy(e.name,id,len);					/*copy input name into e name*/
	return e;
}

int main()
{   struct Employee all_employees[MAX_EMPLOYEES]; /*list of employees*/
	int index , flag = 0;						  /*flag will be used for menu error handling*/
	char c;
	do{ 
		if(flag == 0)    										/*basically if users input was valid*/
		{
		all_employees[index] = get_info(all_employees[index]); /*create new employee at current indx*/
		index++;
		if(index == MAX_EMPLOYEES){							/*if no space left in array sort and break loop*/
			heapSort(all_employees, index);
			 break;
			  } 
		} else{ 							/*else if flag!=0 the user had made a mistake, and we only want to reshow menu*/
		flag=0;
		}
	c = get_menu_option(); 
	switch(c){
		case 'y': 							/*if user wants to continue, break and continue!*/
		break;
		case 'n':							/*else if user wants to quit, sort and break*/
		heapSort(all_employees, index);
		break;
		default:							/*else invalid input*/
		printf("Uknown option %c. Try again.", c);
		printf("\n");
		index--;							/*make sure to decrement indx and reset flag*/
		flag = 1;
		break;
	}
  }while(c!= 'n');
  printList(all_employees, index); 			/*finally print list and return cleanly*/
  return 0;
}
