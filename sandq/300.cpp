// How to efficiently implement k stacks in a single array?

// m1:divide into slots

#include<bits/stdc++.h>
using namespace std;

class kStacks
{
	int *arr;//size n to store actual content of stack;
	int *top;//size k to store top elements
	int *next;//size n to store next entry in all stacks;
	int n,k;
	int free; //beginning of index;
public:
	kStacks(int k,int n);
	bool isFull() { return (free==-1);}
	void push(int item,int sn);
	int pop(int sn);
	bool isEmpty(int sn){return (top[sn]==-1);}
};

kStacks::kStacks(int k1,int n1)
{
	k=k1,n=n1;
	arr=new int[n];
	top=new int[n];
	next=new int[n];
	for(int i=0;i<k;i++)
		top[i]=-1;
	free=0;
	for(int i=0;i<n-1;i++)
		next[i]=i+1;
	next[n-1]=-1;
}

void kStacks::push(int item,int sn)
{
	if (isFull())
	{
		cout<<"the stack is full"<<endl;
		return ;
	}

	int i=free;
	free=next[i];
	next[i]=top[sn];
	top[sn]=i;
	arr[i]=item;

}

int kStacks::pop(int sn)
{
	if(isEmpty(sn))
	{
		cout<<"empty";
		return INT_MAX;
	}

	int i=top[sn];
	top[sn]=next[i];
	next[i]=free;
	free=i;
	return arr[i];
}

int main()
{
	int k=3,n=10;
	kStacks ks(k,n);
	//2
	ks.push(15,2);
	ks.push(45,2);
	//1
	ks.push(17,1);
	ks.push(67,1);
	ks.push(89,1);
	//0
	ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);


    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    return 0;
}