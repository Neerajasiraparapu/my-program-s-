#include<stdio.h>
int binary_search_re(int n,int arr[*],int beg,int end,int val);    //recursion function
int binary_search_non_re(int n,int arr[*],int beg,int end,int val);  //non-recursion function
void main()
{
	int val,i,n,pos;
	printf("enter the size of an array:");
	scanf("%d",&n);
	int arr[n];
	printf("\n enter the elements in ascending order:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n enter the value to search:");
	scanf("%d",&val);
	pos=binary_search_re(n,arr,0,n-1,val);
	if(pos!=0)
	  printf("\n elements %d is found at %dth position using recursion",val,pos+1);
	else
	  printf("\n %d not found in the array using recursion",val);
	binary_search_non_re(n,arr,0,n-1,val);    
}
int binary_search_re(int n,int arr[n],int beg,int end,int val)    //recursion function
{
	if(beg<=end)
	{
		int mid=(beg+end)/2;
		if(arr[mid]==val)
		  return mid;
		if(arr[mid]>val)
           return binary_search_re(n,arr,beg,mid-1,val);
        else
           return binary_search_re(n,arr,mid+1,end,val);
	}
	return -1;
}
int binary_search_non_re(int n,int arr[n],int beg,int end,int val)   //non-recursion function
{
	int mid,pos=-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==val)
		{
			pos=mid+1;
			printf("\n elements %d is found at position %d using non recursion",val,pos);
			break;
		}
		else if(arr[mid]>val)
		  end=mid-1;
		else 
		  beg=mid+1;  
	}
	if(pos==-1)
	   printf("\n element %d does not found in an array using non recursion",val);
}
