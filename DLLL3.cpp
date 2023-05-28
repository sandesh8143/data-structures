#include<stdio.h>
#include<stdlib.h>


struct node{
	struct node *prev;
	int data;
	struct node *next;
	
};

struct node *addempty(struct node *head, int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	head=temp;
	return head;
}

struct node *addbeg(struct node *head,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	head->prev=temp;
	temp->next=head;
	head=temp;
	
	return head;
}

struct node *addend(struct node *head,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;	
	}
	ptr->next=temp;
	temp->prev=ptr;
	return head;
	
}

struct node *addpos(struct node *head,int data,int pos)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	ptr=head;
	
	while(pos!=3)
	{
		qtr=ptr;
		ptr=ptr->next;
		pos--;
	}
	qtr->next=temp;
	temp->prev=qtr;
	
	ptr->prev=temp;
	temp->next=ptr;
	
	return head;	
}

struct node *delbeg(struct node *head)
{
	struct node *ptr=NULL;
	ptr=head->next;
	
	ptr->prev=NULL;
	free(head);
	head=ptr;
	return head;
}

struct node *delend(struct node *head)
{
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	ptr=head;
	while(ptr->next!=NULL)
	{
		qtr=ptr;
		ptr=ptr->next;
		
	}
	qtr->next=NULL;
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
		ptr=ptr->next;
		pos--;
	}
	qtr->next=ptr->next;
	ptr->next->prev=qtr;
	return head;
	
}


int main()
{
	struct node *head=NULL; 
	head=addempty(head,600);
	head=addbeg(head,700);
	head=addbeg(head,800);
	head=addend(head,500);
	head=addend(head,400);
//	head=delbeg(head);
//	head=delend(head);
	head=delpos(head,4);
//	head=addpos(head,300,5);
	
	struct node *ptr=NULL;
	ptr=head;
	int count=0;
	while(ptr!=NULL)
	{
		count++;
		printf("Data present in %d Node: %d\n",count,ptr->data);
		ptr=ptr->next;
	}
	return 0; 
}
