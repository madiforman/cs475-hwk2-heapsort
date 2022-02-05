/*
 * heapsort.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	buildHeap(A, n); 	
    for(int i = n - 1; i >= 0; i--){ 
        swap(&A[0], &A[i]);
        heapify(A, 0, i);
    }
}
/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	for(int i = n / 2 - 1; i >= 0; i--){  /*heapify from A[n/2] to A[0]*/
		heapify(A,i,n);
	}
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{

	int smaller = i; 
	int left_child = (2*i+1);
	int right_child = (2*i+2);

	if(left_child < n && A[left_child].salary < A[smaller].salary){
		smaller = left_child;
	}
	if(right_child < n && A[right_child].salary < A[smaller].salary){
		smaller = right_child;
	}
	if(A[smaller].salary != A[i].salary){ 
		swap(&A[i], &A[smaller]);
		heapify(A, n, smaller);
	}
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{ 
	struct Employee *e_ptr = &A[n];
	return e_ptr; 					/*the employee with the smallest salary will be at end of list*/
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	struct Employee tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	for(int i = 0; i < n; i++){
		if(i == n-1){ 			/*if its the last element in the list dont print trailing comma*/
		printf("[id=%s sal=%d]\n", A[i].name, A[i].salary);
		} else {
		printf("[id=%s sal=%d], ", A[i].name, A[i].salary);	
		}
	}
}
