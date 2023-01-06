// Given an array arr[] of N non-negative integers representing the height of blocks.
//If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

class Solution {

	// Function to find the trapped water between the blocks.
public:
	long long trappingWater(int arr[], int n) {
		// code here
		int left[n];
		int right[n];
		//find out the max value on the left side of the element
		left[0] = arr[0];
		for (int i = 1; i < n; i++)
			left[i] = max(arr[i], left[i - 1]);
		//find out the max vlaue on the right side of the element
		right[n - 1] = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
			right[i] = max(arr[i], right[i + 1]);
		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += (long long)(min(left[i], right[i]) - arr[i]);
		return ans;
	}
};
