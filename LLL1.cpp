#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};


void traverse(struct node* head)
{
	int count=0;
	struct node* ptr=NULL;
	ptr=head;
	
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
		
	}
	printf("%d\n",count);
}


int main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=500;
	head->link=NULL;
	
	struct node *current=(struct node*)malloc(sizeof(struct node));
	current->data=600;
	current->link=NULL;
	head->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=700;
	current->link=NULL;
	head->link->link=NULL;
	
	traverse(head);
	

	return 0;
}
