// You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.

class Solution {
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
		long long ans = arr[0];
		long long maxproduct = arr[0], minproduct = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] < 0)
				swap(maxproduct, minproduct);
			maxproduct = max((long long)arr[i], (long long)maxproduct * arr[i]);
			minproduct = min((long long)arr[i], (long long)minproduct * arr[i]);
			ans = max(ans, maxproduct);
		}
		return ans;
	}
};