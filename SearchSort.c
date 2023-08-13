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
void display(int *,int);
//function for displaying the message if the searching element is found or not
//it takes the position returned by the binary search functions
void showResult(int);

//Non-Recursive binary search function, returns the index position of the 
// searching element if found otherwise -1; it takes argument low,high,searching element and the array(pointer)
int binarySearchNonRecursion(int low, int high, int *arr,int element);
//Linear search function, returns the index position of the 
// searching element if found otherwise -1; it takes searching element,no of element n and the array(pointer)
int linearSearch(int, int, int *);
void insertionSort(int n,int *arr);
void bubbleSort(int n,int *arr);
void selectionSort(int n,int *arr);
void quickSort(int, int, int *);
int split(int, int,int *);
void mergeSort(int, int, int *);
void merge(int, int, int, int *);
void swap(int *,int *);

int main()
{
	int n,*arr,element,i,choice1,choice2,choice3,flag1,flag2,flag3;
	system("clear");
	printf("\nEnter the number of elements:\t");
	scanf("\n%d",&n);
	if(n<1){
		printf("\nError: Invalid array length\n");
		return -1;
	}
	arr=getInput(n);
	flag1=0;
	while(!flag1){
		system("clear");
		printf("\nPress the number in the brackets to perform respective operation\n");
		printf("\nSearching:\t(1)\tSorting:\t(2)\tCreate New Array:\t(3)\tExit:\t(9)");
		printf("\nEnter your choice:\t");
		scanf("\n%d",&choice1);
		
		switch(choice1) {
			case 1:
				flag2=0;
				system("clear");
				while(!flag2) {
					display(arr,n);
					printf("\nBinary Search:\t(1)\tLinear Search:\t(2)\tGo back to previous menu:\t(9)");
					printf("\nEnter your choice:\t");
					scanf("\n%d",&choice2);
					switch(choice2) {
						case 1:
							flag3=0;
							system("clear");
							while(!flag3){
								display(arr,n);
								printf("\nRecursive Binary Search:\t(1)\tNon Recursive Binary Search:\t(2):\tPrevious Menu:\t(9)");
								printf("\nEnter your choice:\t");
								scanf("\n%d",&choice3);
								switch(choice3) {
									case 1:
										printf("\nBinary Search Recursive Version");
										printf("\nEnter searching element:\t");
										scanf("\n%d",&element);
										i=binarySearch(0,n,arr,element);
										showResult(i);
										break;
									case 2:
										printf("\nBinary Search Non Recursive Version");
										printf("\nEnter searching element:\t");
										scanf("\n%d",&element);
										i=binarySearchNonRecursion(0,n,arr,element);
										showResult(i);
										break;
									case 9:
										flag3=9;
										break;
									default:
										printf("\nInvalid Choice...");
								}
							}
							break;
						case 2:
							system("clear");
							display(arr,n);
							printf("\n--- Linear Search ---\n");
							printf("\nEnter searching element:\t");
							scanf("\n%d",&element);
							i=linearSearch(element,n,arr);
							showResult(i);
							break;
						case 9:
							flag2=9;
							break;
						default:
							printf("\nInvalid choice!");
					}
				}
				break;
			case 2:
				flag2=0;
				system("clear");
				display(arr,n);
				while(!flag2){
					printf("\nSelection Sort:\t(1)\tInsertion Sort:\t(2)\tMerge Sort:\t(3)");
					printf("\nBubble Sort:\t(4)\tQuick Sort:\t(5)\tGo back to previous menu:\t(9)");
					printf("\nEnter your choice:\t");
					scanf("\n%d",&choice2);
					switch(choice2) {
						case 1:
							system("clear");
							display(arr,n);
							printf("\n--- Selection Sort ---\n");
							selectionSort(n,arr);
							display(arr,n);
							break;
						case 2:
							system("clear");
							display(arr,n);
							printf("\n--- Insertion Sort ---\n");
							insertionSort(n,arr);
							display(arr,n);
							break;
						case 3:
							system("clear");
							display(arr,n);
							printf("\n--- Merge Sort ---\n");
							mergeSort(0,n-1,arr);
							display(arr,n);
							break;
						case 4:
							system("clear");
							display(arr,n);
							printf("\n--- Bubble Sort ---\n");
							bubbleSort(n,arr);
							display(arr,n);
							break;
						case 5:
							system("clear");
							display(arr,n);
							printf("\n--- Quick Sort ---\n");
							quickSort(0,n-1,arr);
							display(arr,n);
							break;
						case 9:
							flag2=9;
							break;
						default:
							printf("\nInvalid Choice!");
					}
				}
				break;
			case 3:
				system("clear");
				printf("\nCreating new array...");
				free(arr);
				printf("\nEnter the number of elements:\t");
				scanf("\n%d",&n);
				if(n<1){
					printf("\nError: Invalid array length\n");
				}
				arr=getInput(n);
				break;
			case 9:
				flag1=9;
				break;
			default:
				printf("\nInvalid Choice!");
		}
		
	}
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
		if(arr[i]==element){
			printf("\nNumber of comparisions:\t%d",i+1);
			return i;
		}
	}
	printf("\nNumber of comparisions:\t%d",i);
	return -1;
}

int binarySearch(int low, int high,int *arr,int element){ 
	int mid;
	static int count=0;
	if(low>high){
		count=0;
		return -1;
	}
	count++;
	mid=(low+high)/2;
	if(arr[mid]==element){
		printf("\nNumber of recursions:\t%d",count);
		count=0;
		return mid;
	}
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
	int mid,pos=-1,count=0;
	while(low<=high) {
		count++;
		mid=(low+high)/2;
		if(arr[mid]==element) {
			pos=mid;
			printf("\nNumber of comparisions:\t%d",count);
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

void insertionSort(int n,int *arr) {
	int i,j,count=0;
	for(i=1;i<n;i++) {
		for(j=i;j>0 && arr[j-1]>arr[j];j--){
			count++;
			swap(&arr[j],&arr[j-1]);
		}
		if((arr[j-1]<=arr[j]) && j>0)
			++count;
		printf("\nAfter pass number %d:",i);
		display(arr,n);
	}
	printf("\nNumber of comparisions:\t%d",count);
	
}
void selectionSort(int n,int *arr) {
	int i,j,min_index,count=0;
	for(i=0;i<n-1;i++) {
		min_index=i;
		for(j=i+1;j<n;j++) {
			count++;
			if(arr[j]<arr[min_index]){
				min_index=j;
			}
		}
		swap(&arr[min_index],&arr[i]);
		printf("\nAfter pass number %d:",i+1);
		display(arr,n);
	}
	printf("\nNumber of comparisions:\t%d",count);
}
void bubbleSort(int n,int *arr) {
	int i,j,swapped,count=0;
	for(i=0;i<n-1;i++) {
		swapped=0;
		for(j=0;j<n-i-1;j++) {
			++count;
			if(arr[j+1]<arr[j]){
				swap(&arr[j],&arr[j+1]);
				swapped=1;
			}
		}
		printf("\nAfter pass number %d:",i+1);
		display(arr,n);
		if(swapped==0)
			break;
	}
	printf("\nNumber of comparisions:\t%d",count);
}

void quickSort(int low, int high,int *arr){ 
	int w;
	static int count=0;
	if(low<high) {
		w=split(low,high,arr);
		quickSort(low,w-1,arr);
		quickSort(w+1,high,arr);
	}
}

int split(int low, int high, int *arr) {
	int i,x,w,j;
	i=low;
	x=arr[low];
	for(j=low+1;j<=high;j++) {
		if(arr[j]<=x) {
			i++;
			if(i!=j)
				swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[low],&arr[i]);
	w=i;
	return w;
}
void mergeSort(int low, int high,int *arr){ 
	int mid;
	if(low>=high)
		return;
	mid=(low+high)/2;
	mergeSort(low,mid,arr);
	mergeSort(mid+1,high,arr);
	merge(low,mid,high,arr);
}

void merge(int low, int mid, int high, int *arr) {
	printf("\nInside Merge, low=%d mid=%d high=%d ",low,mid,high);
	int *temp,i,j,k;
	temp=(int *)malloc(sizeof(int)*(high+1));
	i=low;
	j=mid+1;
	k=low;
	
	while( (i<=mid) && (j<=high) ) {
		if(arr[i]<=arr[j]) {
			temp[k]=arr[i];
			i++;
		}
		else {
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid) {
		temp[k]=arr[i];
		i++;k++;
	}
	while(j<=high) {
		temp[k]=arr[j];
		k++;
		j++;
	}
	for(i=low;i<=high;i++)
		arr[i]=temp[i];
	free(temp);
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