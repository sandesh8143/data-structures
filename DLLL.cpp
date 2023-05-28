#include<stdio.h>
#include<Stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;
	
};
void print(struct node *head)
{
	struct node *ptr=NULL;
	ptr=head;
	
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->prev=NULL;
	head->data=500;
	head->next=NULL;
	
	struct node* current=(struct node*)malloc(sizeof(struct node));
	current->prev=head;
	current->data=600;
	current->next=NULL;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->prev=current;
	current->data=700;
	current->next=NULL;
	
	print(head);
	
	return 0;
}
