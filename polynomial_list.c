#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coefficient;
	int exponent;
	struct node* next;
};
struct node* start=NULL;
struct node* create_poly(struct node*);
void display_poly(struct node*);
void main()
{
     int option;
	 do
	 {
	 	printf("\n*****MAIN MENU*****");
	 	printf("\n enter 1 to create a polynomal list.");
	 	printf("\n enter 2 to display a polynomal list.");
	 	printf("\n enter 3 to exit.");
	 	printf("\nenter the option:");
	 	scanf("%d",&option);
	 	switch(option)
	 	{
	 		case 1:
	 			start=create_poly(start);
	 			printf("\n polynomial linked list id created.");
	 			break;
	 		case 2:
			    display_poly(start);
				break;	
		 }
		 }while(option != 3);	
}
struct node* create_poly(struct node*start)
{
	struct node* newnode,*ptr;
	int n,c,terms,i;
	printf("\n enter the number of terms of the polynomial:");
	scanf("%d",&terms);
	for(i=0;i<terms;i++)
	{
		printf("\n enter the coefficient number:");
		scanf("%d",&n);
		printf("\nenter its exponent:");
		scanf("%d",&c);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->coefficient=n;
		newnode->exponent=c;
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			 ptr=ptr->next;
			newnode->next=NULL;
			ptr->next=newnode; 
		
		}
	}
	return start;
}
void display_poly(struct node*start)
{
	struct node*ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d x^ %d\t ",ptr->coefficient,ptr->exponent);
		ptr=ptr->next;
	}
}
