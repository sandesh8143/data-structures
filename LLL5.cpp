#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
	
};

//traversing nodes
void count(struct node *head)
{
	int count=0;
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
		
	}
	printf("%d\n",count);
	
}
//printing data;
void print(struct node *head)
{
	int count=0;
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr!=NULL)
	{
		count++;
		printf("Data present in %d Node: %d\n",count,ptr->data);
		ptr=ptr->link;
	}
}

//inserting node at end;

void addend(struct node *head,int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
	
}

//inserting node at certain position
void addpos(struct node *head,int data,int pos)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	
	ptr=head;
	
	while(pos!=3)
	{
		qtr=ptr;
		ptr=ptr->link;
		pos--;
	}
	qtr->link=temp;
	temp->link=ptr;
	
}

//deleting node at beg;
struct node *delbeg(struct node *head)
{
	struct node *ptr=NULL;
	ptr=head;
	ptr=head->link;
	
	free(head);
	head=ptr;
	return head;
}

//deleting node at end;
struct node *delend(struct node *head)
{
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	ptr=head;
	
	while(ptr->link!=NULL)
	{
		qtr=ptr;
		ptr=ptr->link;
	}
	qtr->link=NULL;
	free(ptr);
	ptr=NULL;
	return head;
}

//deleting at certain position 
struct node *delpos(struct node *head,int pos)
{
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	ptr=head;
	while(pos!=3)
	{
		qtr=ptr;
		ptr=ptr->link;
		pos--;
		
	}
	qtr->link=ptr->link;
	free(ptr);
	ptr=NULL;
	return head;
}


int main()
{
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head->data=600;
	head->link=NULL;
	
	struct node *current=(struct node*)malloc(sizeof(struct node));
	current->data=700;
	current->link=NULL;
	head->link=current;
	
	current=(struct node *)malloc(sizeof(struct node));
	current->data=800;
	current->link=NULL;
	head->link->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=900;
	current->link=NULL;
	head->link->link->link=current;
	
	current=(struct node *)malloc(sizeof(struct node));
	current->data=1000;
	current->link=NULL;
	head->link->link->link->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=1100;
	current->link=NULL;
	head->link->link->link->link->link=current;
	
	count(head);
//	addend(head,1200);
//	addpos(head,1300,5);
//	head=delbeg(head);
//	head=delend(head);
//	head=delpos(head,4);
	
	print(head);
	
	
	return 0;
}
