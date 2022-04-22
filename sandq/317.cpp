// Stack Permutations (Check if an array is stack permutation of other)

// A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in push and pop functions.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> out;
    queue<int> entry;
    stack<int> store;
    out.push(1);out.push(2);out.push(3);
    entry.push(3);entry.push(1);entry.push(2);
//code
    while(!out.empty())
    {
    	if(store.empty())
    	{
    		store.push(out.front());
    		out.pop();
    	}
    	else
    	{
    		if(entry.front()==store.top())
    		{
    			store.pop();entry.pop();
    		}
    		else
    		{
    			store.push(out.front());
                out.pop();
    		}
    	}
    }

    while((!store.empty()) && (!entry.empty()) && (store.top()==entry.front()))
    {
        store.pop();entry.pop();
    }

    if(store.empty())
    	cout<<"yes";
    else
    	cout<<"no";
	return 0;
}