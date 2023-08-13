#include<stdio.h>
#include<stdlib.h>

void quickSort(int, int, int *);
int split(int, int,int *);
int* getInput(int);
void swap(int *, int *);
void display(int *,int);
int main()
{
	int *arr,element,i,n;
	printf("\nEnter the number of elements:\t");
	scanf("\n%d",&n);
	arr=getInput(n);
	quickSort(0,n-1,arr);
	printf("\nSorting done!\n");
	display(arr,n);
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

void quickSort(int low, int high,int *arr){ 
	int w;
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

void display(int *arr, int n) {
	int i;
	printf("\nArray Content:\t");
	for(i=0;i<n;i++) {
		printf("%d   ",arr[i]);
	}
	printf("\n");
	
}

void swap(int *p, int *q) {
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}