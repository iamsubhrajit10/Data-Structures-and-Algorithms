/***
 * Name:Subhrajit Das   Stream: MCS
 * Program details: Linear Search
 ***/

#include<stdio.h>
#include<stdlib.h>

//Linear search function, returns the index position of the 
// searching element if found otherwise -1; it takes searching element,no of element n and the array(pointer)
int linearSearch(int, int, int *);

//function for taking input values of the array from the user.
//returns the array and takes the number of elements n as the argument
int* getInput(int);


int main()
{
	int n,*arr,element,i,choice;
	printf("\nEnter the number of elements:\t");
	scanf("\n%d",&n);
	if(n<1){
		printf("\nError: Invalid array length\n");
		return -1;
	}
	arr=getInput(n);
	printf("\nEnter searching element:\t");
	scanf("\n%d",&element);
	i=linearSearch(element,n,arr);
	if(i<0)
		printf("\nElement not found!");
	else
		printf("\nElement found! at index [%d] \n",i);
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

int linearSearch(int element,int n,int *arr){ 
	int i;
	for(i=0;i<n;i++) {
		if(arr[i]==element)
			return i;
	}
	return -1;
}