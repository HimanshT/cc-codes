//bishu and soldiers

#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int target)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == target) low = mid + 1;
		else if (arr[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
	return high;
}

int main()
{
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int rounds; cin >> rounds;
	int prefix[n]; prefix[0] = arr[0];
	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i - 1] + arr[i];
	while (rounds--)
	{
		int pow; cin >> pow;
		if (pow < arr[0])
			cout << 0 << " " << 0 << endl;
		else if (pow > arr[n - 1])
			cout << n << " " << prefix[n - 1] << endl;
		else
		{
			int idx = solve(arr, n, pow); //minimum element less than or equal to given number
			cout << idx + 1 << " " << prefix[idx] << endl;
		}
	}
	return 0;
}