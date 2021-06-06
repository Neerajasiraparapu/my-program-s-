#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coefficient;
	int exponent;
	struct node* next;
};
struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* start3 = NULL;
struct node* create_poly(struct node *);
void display_poly(struct node *);
struct node* add_poly(struct node*,struct node*,struct node*);
struct node *add_node(struct node *,int,int);
void main()
{
     int option;
	 do
	 {
	 	printf("\n*****MAIN MENU*****");
	 	printf("\n 1.enter to frist polynomial.");
	 	printf("\n 2.display the frist polynomial.");
	 	printf("\n 3.enter the second polynomial.");
	 	printf("\n 4.display the second polynomial.");
	 	printf("\n 5.add the polynomials.");
	 	printf("\n 6.display the result.");
	 	printf("\n 7.exit.");
	 	printf("\n\n enter the option:");
	 	scanf("%d",&option);
	 	switch(option)
	 	{
	 		case 1:
	 			start1=create_poly(start1);
	 			break;
	 		case 2:
			    display_poly(start1);
				break;	
			case 3:
	 			start2=create_poly(start2);
	 			break;
	 		case 4:
			    display_poly(start2);
				break;	
			case 5:
	 			start3=add_poly(start1,start2,start3);
	 			break;
	 		case 6:
			    display_poly(start3);
				break;			
		 }
		 }while(option != 7);	
}
struct node *create_poly(struct node *start)
{
	struct node* new_node,*ptr;
	int n,c,terms,i;
	printf("\n enter the number of terms of the polynomial:");
	scanf("%d",&terms);
	for(i=0;i<terms;i++)
	{
		printf("\n enter the coefficient number:");
		scanf("%d",&n);
		printf("\nenter its exponent:");
		scanf("%d",&c);
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node -> coefficient = n;
		new_node -> exponent = c;
		if(start == NULL)
		{
			new_node -> next = NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr -> next != NULL)
			 ptr  =ptr -> next;
			new_node -> next = NULL;
			ptr -> next = new_node; 
		
		}
	}
	return start;
}
void display_poly(struct node*start)
{
	struct node*ptr;
	ptr=start;
	while(ptr != NULL)
	{
		printf("\n%d x^ %d\t ",ptr -> coefficient,ptr -> exponent);
		ptr = ptr -> next;
	}
}
struct node* add_poly(struct node*start1,struct node*start2,struct node*start3)
{
	struct node *p,*q;
	int sum;
	p = start1,q = start2;
	while(p != NULL&&q!=NULL)
	{
		if(p -> exponent == q -> exponent)
		{
			sum=p -> coefficient + q -> coefficient;
			start3=add_node(start3,sum,p -> exponent);
			p = p -> next;
			q = q -> next;
		}
		else if(p -> exponent < q -> exponent)
		{
			start3=add_node(start3,p -> coefficient,p -> exponent);
			p = p -> next;
		}
		else if(p -> exponent > q -> exponent)
		{
			start3=add_node(start3,q -> coefficient,q -> exponent);
			q = q -> next;
	    }
}
if(p == NULL)
{
	while(q != NULL)
	{
		start3=add_node(start3,q -> coefficient,q ->exponent);
		q = q -> next;
	}
}
if(q == NULL)
{
	while(p != NULL)
	{
		start3=add_node(start3,p -> coefficient,p ->exponent);
		p = p -> next;
	}
}
return start3;
}
struct node* add_node(struct node* start3,int n, int c)
{
	struct node*ptr,*new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> coefficient = n;
	new_node -> exponent = c;
	if(start3 == NULL)
	{
		new_node -> next = NULL;
		start3 = new_node;
	}
	else
	{
		ptr = start3;
		while(ptr -> next != NULL)
		 ptr = ptr -> next;
		 new_node -> next =NULL;
		 ptr -> next =new_node;
	}
	return start3;
}
