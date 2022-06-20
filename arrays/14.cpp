// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer.
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.


int getMinDiff(int arr[], int n, int k) {
	sort(arr, arr + n);
	int currMin = arr[0];
	int currMax = arr[n - 1];
	int ans = currMax - currMin;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - k < 0) continue;
		currMin = min(arr[0] + k, arr[i] - k);
		currMax = max(arr[i - 1] + k, arr[n - 1] - k);
		ans = min(ans, currMax - currMin);
	}
	return ans;
}