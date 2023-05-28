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
		ptr=ptr->link;
		count++;
	}
	printf("No.of Nodes: %d\n",count);
}

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

void addpos(struct node *head,int data, int pos)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	ptr=head;
	qtr=ptr;
	while(pos!=3)
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
	
	head=ptr->link;
	free(ptr);
	ptr=NULL;
	
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
void print(struct node *head)
{
	int count=0;
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr!=NULL)
	{
		count++;
		printf("Data present in %d is %d\n",count,ptr->data);
		ptr=ptr->link;
	}
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
	head->link->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=800;
	current->link=NULL;
	head->link->link->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=900;
	current->link=NULL;
	head->link->link->link->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=1000;
	current->link=NULL;
	head->link->link->link->link->link=current;
	
	count(head);
//	addend(head,1100);
//	addpos(head,1200,5);
//	head=delbeg(head);
//	head=delend(head);
//	head=delpos(head,4);
	print(head);
	
	return 0;
}
