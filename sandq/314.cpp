//find redundant brackets

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ans(string str)
{
	stack<char> store;
	int len=str.length();
	for(int i=0;i<len;)
	{
		if(str[i]=='(' || str[i]==')')
			store.push(str[i]);
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
		{
			if((store.top()>=97 || store.top()<=122) && (str[i+1]>=97 || str[i+1]<=122))
			{
				store.pop();
				store.push('a');
				i+=2;
				continue;
			}
			else
			{
				store.push(str[i]);
			}
		}
		else
		{
			store.push(str[i]);
		}
		i++;
	}
	vector<char> v1;
	while(!store.empty())
	{
		char value=store.top();
		v1.insert(v1.begin(),value);
		store.pop();
	}

	int n = v1.size();
	int ptr1=0,ptr2=1;
	while(ptr2<n)
	{
		if(v1[ptr1]=='(' && v1[ptr2]==')')
			return true;
		ptr1++,ptr2++;
	}

	ptr1=0,ptr2=2;
	while(ptr2<n)
	{
		if(v1[ptr1]=='(' && v1[ptr2]==')')
			return true;
		ptr1++,ptr2++;
	}

	return false;
}

int main()
{
    string str;
    cin>>str;
    cout<<ans(str);
	return 0;
}

//other approach is to travers through the array and
// then if you hit closing bracket then there is a condition 
//else you need to push to the stack
//pop the characters from the stack till matching characters are found

// Now for redundancy two condition will arise while popping- 
 

// If immediate pop hits an open parenthesis ‘(‘, then we have found a duplicate parenthesis. 
// 	For example, (((a+b))+c) has duplicate brackets around a+b. When we reach the second “)” after a+b, 
// we have “((” in the stack. Since the top of stack is an opening bracket, we conclude that there are duplicate brackets. 
 
// If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) 
// then it indicates the presence of unwanted brackets surrounded by expression.
//  For instance, (a)+b contain unwanted () around a thus it is redundant. 