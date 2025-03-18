#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
	}
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
	 selectionsort(a,n);
	 end=clock();
	 time_taken[i]=((double)(end-start))/CLOCKS_PER_SEC;
	 free(a);
	}
	 printf("set of numbers\tTime taken in seconds\n");
	 for(int i=0;i<num;i++)
	 {
	   printf("%d\t\t%f\n",set[i],time_taken[i]);
	 }
}
