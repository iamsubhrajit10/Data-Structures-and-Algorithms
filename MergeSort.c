#include<stdio.h>
#include<stdlib.h>

void mergeSort(int, int, int *);
void merge(int, int, int, int *);
int* getInput();
int n;
void display(int *,int);
int main()
{
	int *arr,element,i;
	printf("\nEnter the number of elements:\t");
	scanf("\n%d",&n);
	arr=getInput();
	mergeSort(0,n-1,arr);
	display(arr,n);
	return 0;
}

int* getInput() {
	int *arr,i;
	arr=(int *)malloc(n*(sizeof(int)));
	for(i=0;i<n;i++) {
		printf("\nEnter value for [%d]:\t",i);
		scanf("\n%d",&arr[i]);
	}
	printf("\nInput successful! ");
	return arr;
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
	temp=(int *)malloc(sizeof(int)*high);
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

void display(int *arr, int n) {
	int i;
	printf("\nArray Content:\t");
	for(i=0;i<n;i++) {
		printf("%d   ",arr[i]);
	}
	printf("\n");
	
}