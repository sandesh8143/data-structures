#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
	
};

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
void print(struct node *head)
{
	int count=0;
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr!=NULL)
	{
		count++;
		printf("Data stored in %d Node: %d\n",count,ptr->data);
		ptr=ptr->link;
	}
}

void addend(struct node *head)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=1100;
	temp->link=NULL;
	
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
}

void addpos(struct node* head,int pos)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=1000000000;
	temp->link=NULL;
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	ptr=head;
	qtr=ptr->link;
	
	while(pos>=4)
	{
		ptr=qtr;
		qtr=ptr->link;
		pos--;
	}
	ptr->link=temp;
	temp->link=qtr;
}

struct node *delbeg(struct node *head)
{
	struct node *ptr=NULL;
	ptr=head;
	
	ptr=head->link;
	free(head);
	head=ptr;
	return head;
}

struct node *delend(struct node *head)
{
	struct node* ptr=NULL;
	struct node* qtr=NULL;
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
	qtr=ptr->link;
	
	while(pos>=4)
	{
		ptr=qtr;
		qtr=ptr->link;
		pos--;
	}
	ptr->link=qtr->link;
	free(qtr);
	qtr=NULL;
	return head;
}

int main()
{
	
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=500;
	head->link=NULL;
	
	struct node *next=(struct node*)malloc(sizeof(struct node));
	next->data=600;
	next->link=NULL;
	head->link=next;
	
	next=(struct node*)malloc(sizeof(struct node));
	next->data=700;
	next->link=NULL;
	head->link->link=next;
	
	next=(struct node*)malloc(sizeof(struct node));
	next->data=800;
	next->link=NULL;
	head->link->link->link=next;
	
	next=(struct node*)malloc(sizeof(struct node));
	next->data=900;
	next->link=NULL;
	head->link->link->link->link=next;
	
	next=(struct node*)malloc(sizeof(struct node));
	next->data=1000;
	next->link=NULL;
	head->link->link->link->link->link=next;
	
	count(head);
	addend(head);
	addpos(head,5);
	head=delbeg(head);
	head=delend(head);
	head=delpos(head,5);
	print(head);
	
	return 0;
}
