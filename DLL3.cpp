//creating DLL;
//inserting node at beginning & at end & at certain position ;  
//deleting node at beginning & at end & at certain position ;


#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* addatempty(struct node* head,int data)
{
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	head=temp;
	return head;
}

struct node* insertbeg(struct node* head,int data)
{
	struct node* temp =(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
}

struct node* insertend(struct node* head,int data)
{
	struct node* tp=NULL;
	struct node* temp =(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	tp=head;
	
	while(tp->next!=NULL)
	{
		tp=tp->next;
		
	}
	tp->next=temp;
	temp->prev=tp;
	return head;
	
}

struct node* insertpos(struct node *head,int data, int pos)
{
	struct node *p1,*p2;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	p1=head;
	p2=p1->next;
	
	while(pos!=2)
	{
		p1=p1->next;
		p2=p1->next;
		pos--;
	}
	p1->next=temp;
	temp->prev=p1;
	temp->next=p2;
	p2->prev=temp;
	
	return head;
}

struct node* delfirst(struct node* head)
{
	struct node* ptr=NULL;
	ptr=head->next;
	
	ptr->prev=NULL;
	head->next=NULL;
	free(head);
	head=NULL;
	head=ptr;
	
	return head;
}

struct node* delend(struct node* head)
{
	struct node *ptr,*qtr;
	ptr=head;
	qtr=ptr->next;
	
	while(qtr->next!=NULL)
	{
		ptr=ptr->next;
		qtr=ptr->next;
	}
	ptr->next=NULL;
	qtr->prev=NULL;
	free(qtr);
	qtr=NULL;
	
	return head;
}

struct node* delpos(struct node* head,int pos)
{
	
	struct node* ptr,*qtr;
	ptr=head;
	qtr=head->next;
	
	
	while(pos>2)
	{
		ptr=ptr->next;
		qtr=ptr->next;
		pos--;
	}
	ptr->next=qtr->next;
	qtr->next->prev=ptr;
	free(qtr);
	qtr=NULL;
	
	return head;
}

int main()
{
	struct node* ptr=NULL;
	struct node *head =NULL;
	head=addatempty(head,1);
	head=insertbeg(head,2);
	head=insertend(head,3);
	head=insertpos(head,4,3);
//	head=delfirst(head);
//	head=delend(head);
//	head=delpos(head,3);
	
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	
	return 0;
}
