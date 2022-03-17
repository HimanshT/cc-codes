// How to implement a stack which will support following operations in O(1) time complexity? 
// 1) push() which adds an element to the top of stack. 
// 2) pop() which removes an element from top of stack. 
// 3) findMiddle() which will return middle element of the stack. 
// 4) deleteMiddle() which will delete the middle element. 

#include<bits/stdc++.h>
using namespace std;

struct node{
	struct node* next;
	struct node* pre;
	int data;
};

struct node *mid=NULL;
int n=0;

struct node *push(struct node *top,int value)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=value;
	if(top==NULL)
	{
		ptr->next=NULL;
		ptr->pre=NULL;
		n++;
		mid=ptr;
	}
	else
	{
		ptr->next=top;
		top->pre=ptr;
		ptr->pre=NULL;
		n++;
		if(n%2==0)
			mid=mid->pre;
	}
	return ptr;
}

struct node *pop(struct node *top)
{
	if(top==NULL)
	{
		cout<<"the stack is empty";
	}
	else
	{
		struct node *ptr=top;
		top=top->next;
		ptr->next=NULL;
		top->pre=NULL;
		cout<<"the element popped out is"<<ptr->data<<endl;
		free(ptr);
		n--;
		if(n%2!=0)
			mid=mid->next;
	}
	return top;
}

void removeMid(struct node *top)
{
	struct node *ptr1=mid->pre;
	struct node *ptr2=mid;
	struct node *ptr3=mid->next;
	n--;
	if(n%2==0)
			mid=mid->pre;
	else
		mid=mid->next;
	ptr1->next=ptr3;
	ptr3->pre=ptr1;
	ptr2->pre=NULL;
	ptr2->next=NULL;
	free(ptr2);
}

void display(struct node *top)
{
	struct node *ptr=top;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}

int main()
{
	struct node *top=NULL;
	top=push(top,4);
	top=push(top,5);
	top=push(top,6);
	top=push(top,7);
	top=push(top,6);
	top=push(top,8);
	top=pop(top);
	display(top);
	cout<<"the middle element is"<<mid->data<<endl;
	removeMid(top);
	display(top);
	return 0;
}
