#include<stdio.h>
int linear_search_re(int val,int n,int arr[*]);   //recursion function
int linear_search(int val,int n,int arr[*]);      //non-recursion function
void main()
{
	int val,i,n,pos;
	printf("enter the size of an array:");
	scanf("%d",&n);
	int arr[n];
	printf("\n enter the elments :");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("\n enter the values to search:");
	scanf("%d",&val);
    linear_search(val,n,arr);
	pos=linear_search_re(val,n,arr);
	if(pos!=0)
	printf("\nenter %d is found at %d th position using recursion function",val,pos);
	else
	printf("%d is not found using recursion function",val);
}
int linear_search_re(int val,int n,int arr[n])    //recursion function 
{
	if(n>0)
	{
		if(arr[n-1]==val)
		return n;
		else 
		return linear_search_re(val,n-1,arr);
	}
}
int linear_search(int val,int n,int arr[n])    //non-recursion function
{
	int i,pos=-1;
	for(i=0;i<n;i++)
	{
		if(arr[i]==val)
		{
			pos=i;
			printf("\n %d is found in array at position %d using non-recursion function",val,i+1);
			break;//without break
		}
	}
     if(pos==-1)
     printf("\n  %d does not found using non-recursion function",val);
     
}
