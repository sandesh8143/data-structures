 //trvarsing,printing,inserting(beg,end,pos),deleting(beg,end,pos);

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
	printf(" Number of nodes in Linked List: %d \n",count);
}

void print(struct node *head)
{
	int count=0;
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr!=NULL)
	{
		count++;
		printf("Data present in %d Node is %d\n",count ,ptr->data);
		ptr=ptr->link;
	}
}

void insertend(struct node *head)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=1100;
	temp->link=NULL;
	
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
	printf("%d\n",temp->data);
	
}

void insertpos(struct node *head,int pos)
{
	
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=200;
	temp->link=NULL;
	struct node *ptr=NULL;
	struct node *qtr=NULL;
	ptr=head;
	qtr=ptr->link;
	
	
	while(pos!=3)
	{
		ptr=qtr;
		qtr=ptr->link;
		pos--;
	}
	ptr->link=temp;
	temp->link=qtr;
//	printf("%d",temp->data);
}

struct node *delbeg( struct node *head)
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
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=600;
	head->link=NULL;
	
	struct node *current=(struct node*)malloc(sizeof(struct node));
	current->data=700;
	current->link=NULL;
	head->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=800;
	current->link=NULL;
	head->link->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=900;
	current->link=NULL;
	head->link->link->link=current;
	
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=1000;
	current->link=NULL;
	head->link->link->link->link=current;
	
	
	count(head);
	insertend(head);
	insertpos(head,4);
	head = delbeg(head);
	head = delend(head);
	head = delpos(head,4);
	print(head);
	
	
	return 0;
}
