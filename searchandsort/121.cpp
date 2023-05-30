//kth smallest number again

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> mergeIntervals(vector<vector<ll>> &arr)
{
	sort(arr.begin(), arr.end());
	vector<vector<ll>> ans;
	for (int i = 0; i < arr.size(); i++)
	{
		if (!ans.size()) ans.push_back(arr[i]);
		else {
			int n = ans.size();
			if (arr[i][0] >= ans[n - 1][0] and arr[i][0] <= ans[n - 1][1])
				ans[n - 1][1] = arr[i][1];
			else
				ans.push_back(arr[i]);
		}
	}
	return ans;
}

void findSum(vector<vector<ll>> &a, vector<ll> &sum)
{
	sum[0] = a[0][1] - a[0][0] + 1;
	for (int i = 1; i < a.size(); i++)
	{
		sum[i] = sum[i - 1] + a[i][1] - a[i][0] + 1;
	}
}


int bs(vector<ll> &sum, int low, int high, int target)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (sum[mid] == target)
			return mid;
		else if (sum[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

ll ans(int idx,  vector<vector<ll>> arr, int target, vector<ll> sum)
{
	if (idx == 0)
		return (arr[idx][0] + target - 1);
	return arr[idx][0] + target - sum[idx - 1] - 1;
}


int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		ll n, q;
		cin >> n >> q;
		vector<vector<ll>> arr(n, vector<ll>(2));
		for (ll i = 0; i < n; i++)
			cin >> arr[i][0] >> arr[i][1];
		//merge intervals
		vector<vector<ll>> a = mergeIntervals(arr);
		for (int i = 0; i < a.size(); i++)
			cout << a[i][0] << " " << a[i][1] << endl;
		//sum to find the respective Index
		vector<ll> sum(a.size());
		findSum(a, sum);
		ll x = sum.size();
		//finding the index
		while (q--)
		{
			int idx; cin >> idx;
			if (idx == 0 or idx > sum[x - 1])
				cout << -1 << endl;
			else {
				int indexInSum = bs(sum, 0, x - 1, idx);
				cout << ans(indexInSum, a, idx, sum) << endl;
			}
		}
	}
	return 0;
}