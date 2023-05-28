#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

void print(struct node *head)
{
	struct node *ptr=NULL;
	ptr=head;
	int count=0;
	while(ptr!=NULL)
	{
		count++;
		printf("Data present in %d Node: %d\n",count,ptr->data);
		ptr=ptr->link;		
	}
	
}
struct node *addend(struct node *head,int data)
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
	return head;
}

struct node *addpos(struct node *head,int data,int pos)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
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
	return head;
}

struct node *delbeg(struct node *head)
{
	struct node *ptr=NULL;
	ptr=head->link;
	
	free(head);
	head=ptr;
	return head;
}

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
	head->data=500;
	head->link=NULL;
	
	struct node *next=(struct node *)malloc(sizeof(struct node ));
	next->data=600;
	next->link=NULL;
	head->link=next;
	
	next=(struct node*)malloc(sizeof(struct node));
	next->data=700;
	next->link=NULL;
	head->link->link=next;
		
	head=addend(head,800);
//	head=addpos(head,10000,4);
//	head=delbeg(head);
//	head=delend(head);
//	head=delpos(head,5);
print(head);
	
	return 0;
}
