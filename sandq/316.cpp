//implement stack and queue using dequeue

#include<bits/stdc++.h>
using namespace std;

struct Stack{
	int data;
	struct Stack *prev;
	struct Stack *next;
};

struct Stack *insert(struct Stack *head,int value)
{
	struct Stack *ptr=(struct Stack*)malloc(sizeof(struct Stack));
	ptr->data=value;
	if(head==NULL)
	{
		ptr->next==NULL;
		ptr->prev=NULL;
		return ptr;
	}
	else
	{
		struct Stack *iter=head;
		while(iter->next!=NULL)
			iter=iter->next;
		ptr->next=iter->next;
		iter->next=ptr;
		ptr->prev=iter;
		return head;
	}
}

void display(struct Stack *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main()
{
    struct Stack *head=NULL;
    head=insert(head,4);
    head=insert(head,5);
    head=insert(head,6);
    head=insert(head,7);
    display(head);
	return 0;
}


// To implement stack
/*
1. Insert at front and delete at front-->head=stack->top
________________________________________________________

To implement queue

Insert at the back and delete from the head;

*/