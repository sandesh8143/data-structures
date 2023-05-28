#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
	
};

struct node *addempty(struct node *head,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	head=temp;
	return head;
}
struct node *addbeg(struct node *head,int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	head->next=temp;
	temp->prev=head;
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
	
	while(pos!=2)
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
	ptr=head;
	ptr=ptr->next;
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
	struct node *ptr=NULL;
	struct node *head=NULL;
	head=addempty(head,3);
	head=addbeg(head,1);
	head=addend(head,4);
	head=addpos(head,5,4);
	head=addpos(head,6,5);
//	head=delbeg(head);
//	head=delend(head);
//	head=delpos(head,5);
	
	ptr=head;
	int count=0;
	while(ptr!=NULL)
	{
		count++;
		printf("Data present in %d Node: %d \n",count ,ptr->data);
		ptr=ptr->next;
	}
	
	
	
	return 0;
}

