/***
 * Name:Subhrajit Das   Stream: MCS
 * Program details: Insertion Sort
 ***/
 
#include<stdio.h>
#include<stdlib.h>

void insertionSort(int n,int *arr);
int* getInput(int);
void swap(int *,int *);
void display(int *,int);
int main()
{
	int *arr,element,i,n;
	printf("\n---INSERTION SORT---");
	printf("\nEnter the number of elements:\t");
	scanf("\n%d",&n);
	if(n<1){
		printf("\nError: Invalid array length\n");
		return -1;
	}
	arr=getInput(n);
	printf("\nInput Data:");
	display(arr,n);
	insertionSort(n,arr);
	printf("\nSorting Done!!");
	display(arr,n);
	printf("\nExiting...\n");
	return 0;
}

int* getInput(int n) {
	int *arr,i;
	arr=(int *)malloc(n*(sizeof(int)));
	for(i=0;i<n;i++) {
		printf("\nEnter value for [%d]:\t",i);
		scanf("\n%d",&arr[i]);
	}
	printf("\nInput successful! ");
	return arr;
}

void insertionSort(int n,int *arr) {
	int i,j;
	for(i=1;i<n;i++) {
		for(j=i;j>0 && arr[j-1]>arr[j];j--) 
			swap(&arr[j],&arr[j-1]);
		printf("\nAfter pass number %d:",i);
		display(arr,n);
	}
	
}
void swap(int *p,int *q) {
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
void display(int *arr, int n) {
	int i;
	printf("\nArray Content:\t");
	for(i=0;i<n;i++) {
		printf("%d   ",arr[i]);
	}
	printf("\n");
	
}