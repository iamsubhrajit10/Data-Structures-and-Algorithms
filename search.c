#include<stdio.h>
#include<stdlib.h>

int binarySearch(int, int, int *,int);
int* getInput(int);
void showResult(int);
int binarySearchNonRecursion(int low, int high, int *arr,int element);
int main()
{
	int n,*arr,element,i,choice;
	printf("\nEnter the number of elements:\t");
	scanf("\n%d",&n);
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