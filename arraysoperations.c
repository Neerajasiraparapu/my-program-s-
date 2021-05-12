#include<stdio.h>
void main()
{
	int n,i,j,temp,arr[n],count=0,position,values,option;
	printf("enter the size of an array:");
	scanf("%d",&n);
	printf("enter the %d elements of an array:",n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("enter the one option between 1 to 5:\n");
	printf("enter the 1 for inserting an elements\n");
    printf("enter the 2 for deleting an elements\n");
	printf("enter the 3 for searching an elements\n");
	printf("enter the 4 for sorting in ascending order\n");
	printf("enter the 5 for sorting in descending order\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			{
				printf("enter the elements to insert in an array:");
				scanf("%d",&values);
				printf("enter the position to insert an array:\n");
				scanf("%d",&position);
				for(i=n-1;i>=position;i--)
				arr[i+1]=arr[i];
				arr[position]=values;
				n++;
				printf("\n the number of an array after inserting new values:");
				for(i=0;i<n;i++)
				printf("%d\t",arr[i]);
				break;
			}
		case 2:
		    {
			printf("enter the position or index of an array to delete an element :");
			scanf("%d",&position);
			for(i=position;i<n-1;i++)
			arr[i]=arr[i+1];
			n--;
			printf("\n the elements of an array after deleting:");
			for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
			break;
			}
		case 3:	
		    {
		    printf("enter the elements to search:");
			scanf("%d",&values);
			for(i=0;i<n;i++)
			{
				if (arr[i]==values)
				{
					count++;
					printf("\n the %d values found at position %d .",values,i+1);
				}
			}
			if (count==0)
			printf("\n the %d element not found",values);
			break;
			}
		case 4:	
		    {
		    for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(arr[j]>arr[j+1])
					{
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}
			printf("\n sorting in ascending order in an array: ");
			for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
			break;	
			}
		case 5:	
		    {
		     for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(arr[j]<arr[j+1])
					{
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}
			printf("\n sorting in descending  order in an array: ");
			for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
			break;	
			}
			default:
			printf("\n enter the correct option");	
	}

}
