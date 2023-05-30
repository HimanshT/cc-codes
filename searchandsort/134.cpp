//Prata - Roti Prata

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findParathasIntime(ll *arr, ll n, ll givenTime)
{
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll temp = sqrt((givenTime * 2) / arr[i]);
		if (pow(temp, 2) + temp <= givenTime)
			ans += temp;
		else
			ans += temp - 1;
	}
	return ans;
}

ll fn(ll *arr, ll n, ll target)
{
	ll low = 0, high = INT_MAX;
	ll ans = INT_MAX;
	while (low <= high)
	{
		ll mid = (low + high) / 2;
		ll count = findParathasIntime(arr, n, mid);
		if (count == target)
		{
			ans = min(ans, mid); high = mid - 1;
		}
		else if (count < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return ans;
}

int main()
{
	ll test; cin >> test;
	while (test--)
	{
		ll x; cin >> x;
		ll n; cin >> n;
		ll arr[n];
		for (ll i = 0; i < n; i++) cin >> arr[i];
		cout << fn(arr, n, x) << endl;
	}
	return 0;
}