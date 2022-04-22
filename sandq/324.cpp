// Interleave the first half of the queue with second half

//Input : 11 12 13 14 15 16 17 18 19 20
//Output : 11 16 12 17 13 18 14 19 15 20

#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    for(int i=11;i<=20;i++)
    	q.push(i);
    //code
    stack<int> s1,s2;
    int n=10;
    for(int i=1;i<=(n/2);i++)
    {
    	s1.push(q.front());
    	q.pop();
    }
    //reverse stack
    while(!s1.empty())
    {
    	s2.push(s1.top());
    	s1.pop();
    }

    while(!s2.empty())
    {
    	q.push(s2.top());s2.pop();
    	q.push(q.front());q.pop();
    }

    while(!q.empty())
    {
    	cout<<q.front()<<" ";
    	q.pop();
    }
	return 0;
}