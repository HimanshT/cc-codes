//eko - eko

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n, target; cin >> n >> target;
	ll arr[n];
	// ll n = 4, target = 7;
	// ll arr[] = {20, 15, 10, 17};
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	ll ans = -1;
	ll low = 0, high = INT_MAX;
	while (low <= high)
	{
		ll mid = (low + high) / 2;
		ll currwood = 0;
		for (ll i = n - 1; i >= 0; i--)
		{
			if (arr[i] <= mid)
				break;
			else
				currwood += arr[i] - mid;
			if (currwood >= target)
				break;
		}

		if (currwood >= target) {
			ans = mid;
			low = mid + 1;
		} else
			high = mid - 1;
	}
	cout << ans;
}