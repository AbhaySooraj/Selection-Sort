/*To implement Selection sort*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0,struct timeval t1)
{
	return(t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void display(int n,int arr[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",arr[i]);
	}
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int x,n,i,j,temp,minpos;
	
	printf("\n Enter number of elements ");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
	}
	
	printf("\n The unsorted elements are :");
	display(n,arr);
	
	gettimeofday(&t0, NULL);
	
	for(i=0;i<n-1;i++)
	{
		minpos=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minpos])
			{
				minpos=j;
			}
		}
		temp=arr[minpos];
		arr[minpos]=arr[i];
		arr[i]=temp;
	}
	
	printf("\n The sorted elements are :");
	display(n,arr);
	
	gettimeofday(&t1, NULL);
	elapsed=timedifference_msec(t0,t1);
	printf("\nCode executed in %f milliseconds.\n", elapsed);
}

	
