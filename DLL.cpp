//creating DLL;
//inserting node at beginning & at end & at certain position;  


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



int main()
{
	struct node* ptr=NULL;
	struct node *head =NULL;
	head=addatempty(head,1);
	head=insertbeg(head,2);
	head=insertend(head,3);
	head=insertpos(head,4,3);
	
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	
	return 0;
}
