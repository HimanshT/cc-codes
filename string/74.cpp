//kmp algorithm

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void kmp(string text, string pattern)
{
	//prefix table
	int t = text.length();
	int p = pattern.length();
	int index = -1;
	vector<int> prefix(p, 0);
	int i, j; i = 0, j = i + 1;
	for (; j < p; j++)
	{
		if (pattern[i] == pattern[j])
		{
			prefix[j] = i + 1;
		}
		else
		{
			i = prefix[i];
		}
	}

	for (int i = 0; i < p; i++)
		cout << prefix[i] << " ";
	cout << "\n";

	//checking the pattern
	int ptr1 = 0, ptr2 = 0; //ptr1---text,ptr2--pattern
	for (; ptr1 < t; ptr1++)
	{
		if (text[ptr1] == pattern[ptr2])
		{
			ptr2++;
			if (ptr2 == p)
			{
				index = ptr1 - ptr2 + 1;
			}
		}
		else
		{
			ptr2 == prefix[ptr2];
		}
	}
	cout << index;
}

int main()
{
	int test = 1;
	while (test--)
	{
		string text = "thisiskmp";
		string pattern = "is";
		kmp(text, pattern);
	}
	return 0;
}