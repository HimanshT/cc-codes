// // A step array is an array of integers where each element has a difference of at most k with its neighbor.
//  Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={20, 40, 50, 70, 70, 60};
	int k=20;
	int x=60;
	for(int i=0;i<6;)
	{
		int diff=abs(x-arr[i]);
		if(diff==0)
		{
			cout<<i;
			break;
		}else
		{
			int n=diff/k;
			if(n==0)
			i++;
			else
			i=i+n;
		}
	}
	return 0;
}