#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int[],int,int);
void swap(int*,int*);
void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int s=partition(arr,low,high);
		quicksort(arr,low,s-1);
		quicksort(arr,s+1,high);
	}
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void generaterandomarray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=rand();
	}
}
void main()
{
	int set[]={5000,10000,15000,20000};
	int num=sizeof(set)/sizeof(set[0]);
	double time_taken[num];
	clock_t start,end;
	for(int i=0;i<num;i++)
	{
		int n=set[i];
		int* a=(int*)malloc(n*sizeof(int));
		generaterandomarray(a,n);
		start=clock();
		quicksort(a,0,n-1);
		end=clock();
		time_taken[i]=((double)(end-start))/CLOCKS_PER_SEC;
		free(a);
	}
	printf("Set of numbers\t Time taken in seconds:\n");
	for(int i=0;i<num;i++)
	{
		printf("%d\t\t%f\n",set[i],time_taken[i]);
		
	}
	
}
