//reverse a stack using recursion

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct stacks{
	int size;
	int top;
	int *arr;
};

int arr_store[10];
int i=0;

void push(struct stacks *s,int i)
{
	s->top++;
	s->arr[s->top]=i;
}

void display(struct stacks *s)
{
	for(int i=0;i<=(s->top);i++)
		cout<<s->arr[i]<<" ";
	cout<<endl;
}

void reverse(struct stacks *s)
{
	if(s->top==-1)
	{
		return;
	}
	else
	{
		arr_store[i]=s->arr[s->top];
		i++;
		s->top--;
		reverse(s);
		s->top++;
		s->arr[s->top]=arr_store[s->top];	
	}
}

int main()
{
    struct stacks *s = (struct stacks *)malloc(sizeof(struct stacks));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(sizeof(int)*(s->size));
    for(int i=0;i<9;i++)
    	push(s,i);
	display(s);
	reverse(s);
	display(s);
	return 0;
}