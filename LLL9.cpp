#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};


struct node *addempty(struct node *head,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	head=temp;
	return head;
}

struct node *addbeg(struct node *head,int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	temp->link=head;
	head=temp;
	return head;
	
}

struct node *addend(struct node *head,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
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
	int n=pos-1;
	
	while(pos!=n)
	{
		qtr=ptr;
		ptr=ptr->link;
		pos--;
		
	}
	qtr->link=temp;
	temp->link=ptr;
	return head;
}

int main()
{
	struct node *head;
	struct node *ptr=NULL;
	
	head=addempty(head,5);
	head=addbeg(head,4);
	head=addend(head,6);
	head=addend(head,7);
	head=addpos(head,3,5);
	
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	return 0;
}
