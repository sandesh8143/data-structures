#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *addempty(struct node *head, int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	head=temp;
	return head;
}

struct node *addbeg(struct node *head,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	
	struct node *ptr=NULL;
	ptr=head;
	head=temp;
	temp->link=ptr;
	return head;
}

struct node *addend(struct node *head, int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node ));
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
	
	while(pos!=2)
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
	
	while(pos!=2)
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
	struct node *head;
	head=addempty(head,500);
	head=addbeg(head,600);
	head=addend(head,700);
	head=addpos(head,800,4);
//	head=delbeg(head);
//	head=delend(head); 
	head=delpos(head,3);
	
	
	
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	return 0;
}
