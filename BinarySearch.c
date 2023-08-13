/***
 * Name:Subhrajit Das   Stream: MCS
 * Program details: Binary Search implemented in two versions
 *       (a): Recursive
 *		 (b): Non-Recursive
 ***/

#include<stdio.h>
#include<stdlib.h>

//Recursive binary search function, returns the index position of the 
// searching element if found otherwise -1; it takes argument low,high,searching element and the array(pointer)
int binarySearch(int, int, int *,int);

//function for taking input values of the array from the user.
//returns the array and takes the number of elements n as the argument
int* getInput(int);

//function for displaying the message if the searching element is found or not
//it takes the position returned by the binary search functions
void showResult(int);

//Non-Recursive binary search function, returns the index position of the 
// searching element if found otherwise -1; it takes argument low,high,searching element and the array(pointer)
int binarySearchNonRecursion(int low, int high, int *arr,int element);

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
	printf("\nPress the number in the brackets to perform respective operation\n");
	printf("\nRecursive Binary Search:\t(1)\tNon Recursive Binary Search:\t(2):\t");
	scanf("\n%d",&choice);
	printf("\nEnter searching element:\t");
	scanf("\n%d",&element);
	switch(choice) {
		case 1:
			printf("\nBinary Search Recursive Version");
			i=binarySearch(0,n,arr,element);
			showResult(i);
			break;
		case 2:
			printf("\nBinary Search Non Recursive Version");
			i=binarySearchNonRecursion(0,n,arr,element);
			showResult(i);
			break;
		default:
			printf("\nInvalid Choice...");
		}
	printf("\nExiting...\n");
	return 0;
}

int* getInput(int n) {
	int *arr,i;
	arr=(int *)malloc(n*(sizeof(int)));
	printf("\nPlease Enter Sorted(Non-Decreasing order) Data Set: Otherwise it will not work properly!");
	for(i=0;i<n;i++) {
		printf("\nEnter value for [%d]:\t",i);
		scanf("\n%d",&arr[i]);
	}
	printf("\nInput successful! ");
	return arr;
}

int binarySearch(int low, int high,int *arr,int element){ 
	int mid;
	if(low>high)
		return -1;
	mid=(low+high)/2;
	if(arr[mid]==element)
		return mid;
	if(element<arr[mid])
		return binarySearch(low,mid-1,arr,element);
	else
		return binarySearch(mid+1,high,arr,element);
}

void showResult(int i){
	if(i<0)
		printf("\nElement not found! \n");
	else
		printf("\nElement found! at index [%d] \n",i);
}

int binarySearchNonRecursion(int low, int high, int *arr,int element) {
	int mid,pos=-1;
	while(low<=high) {
		mid=(low+high)/2;
		if(arr[mid]==element) {
			pos=mid;
			return pos;
		}
		else {
			if(element<arr[mid]) {
				high=mid-1;
			}else {
				low=mid+1;
			}
		}
	}
	return pos;
}