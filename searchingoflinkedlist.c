#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
struct node * start=NULL;
struct node * createll(struct node*);
void display(struct node*);
void search(struct node*,int);
void main()
{
	int option,val;
	do
    {
    	printf("\n\n****MAIN MENU****");
    	printf("enter 1 ,to create list.");
    	printf(" \nenter 2 ,to display a list.");
    	printf("\n enter 3 ,to searching a value in list");
    	printf("\nenter 4 ,to exit.");
    	printf("\nenter the option :");
    	scanf("%d",&option);
    	switch(option)
    	{
    		case 1:
    			start=createll(start);
    			printf("\n linked list is created");
    			break;
    	    case 2:
			    display(start);
			    break;
			case 3:
				printf("\n enter a value to search in a list: ");
				scanf("%d",&val);
				search(start, val);
				break;    
		}
	}while(option != 4);
	
}
struct node * createll(struct node*start)
{
	struct node*newnode,*ptr;
	int num;
	printf("enter the data or -1 to end :");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
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
		   ptr->next=newnode;
		   newnode->next=NULL;
		}
		printf("\n enter the data:");
		scanf("%d",&num);
	}
	return start;
}
 void display(struct node*start)
{
	struct node*ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}

}
void search(struct node *start, int val) 
	{
		int flag=0;
		struct node* ptr=start;
    while (ptr != NULL) {
        if (ptr->data == val){
            printf("\n%d Found in list at %d address\n", val,ptr);
            flag++;
			      break;
	    break;
        }
        ptr = ptr->next;
    }
    if(flag==0)
    printf("\n%d Not Found in list \n", val);
}

    	  
	
