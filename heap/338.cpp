// Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	int n = 9;
	int k = 3;
	//sliding window
	deque<int> dq;
	for (int i = 0; i < k; ++i)
	{
		if (dq.empty())dq.push_back(i);
		else
		{
			while (arr[dq.front()] < arr[i] && !dq.empty())
				dq.pop_back();
			dq.push_back(i);
		}
	}

	vector<int> ans;
	ans.push_back(arr[dq.front()]);
	if (dq.front() == 0)dq.pop_front();
	for (int i = k; i < n; ++i)
	{
		if (dq.empty())dq.push_back(i);
		else
		{
			while (arr[dq.front()] < arr[i] && !dq.empty())
				dq.pop_back();
			dq.push_back(i);
		}
		ans.push_back(arr[dq.front()]);
		if (dq.front() == (i - k))dq.pop_front();
	}

	for (auto it : ans)
		cout << it << " ";

	return 0;
}