// the double helix spoj

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bs(ll *arr, ll low, ll high, ll target)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == target) return mid;
		else if (target > arr[mid]) return bs(arr, mid + 1, high, target);
		return bs(arr, low, mid - 1, target);
	}
	return -1;
}

ll solve(ll n1, ll n2, ll *a, ll *b)
{
	queue<pair<ll, ll>> q;
	for (ll i = 0; i < n1; ++i)
	{
		ll idx = bs(b, 0, n2 - 1, a[i]);
		if (idx != -1)
			q.push({i, idx});
	}

	ll ptr1 = 0, ptr2 = 0;
	ll ans = 0;
	while (!q.empty())
	{
		ll sum1 = 0, sum2 = 0;
		for (; ptr1 <= q.front().first; ptr1++)
			sum1 += a[ptr1];
		for (; ptr2 <= q.front().second; ptr2++)
			sum2 += b[ptr2];
		q.pop();
		ans += max(sum1, sum2);
	}
	ll sum1 = 0, sum2 = 0;
	for (; ptr1 < n1; ptr1++) sum1 += a[ptr1];
	for (; ptr2 < n2; ptr2++) sum2 += b[ptr2];
	ans += max(sum1, sum2);
	return ans;
}

int main()
{
	while (1)
	{
		ll n1, n2;
		cin >> n1;
		if (n1 == 0)
			break;
		ll a[n1];
		for (ll i = 0; i < n1; ++i)
		{
			cin >> a[i];
		}
		cin >> n2; ll b[n2];
		for (ll i = 0; i < n2; ++i)
		{
			cin >> b[i];
		}
		cout << solve(n1, n2, a, b) << endl;
	}
	return 0;
}