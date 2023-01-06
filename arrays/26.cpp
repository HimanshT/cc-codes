// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

class Solution {
public:
	//Complete this function
	//Function to check whether there is a subarray present with 0-sum or not.
	bool subArrayExists(int arr[], int n)
	{
		int sum = 0;
		unordered_map<int, int> umap;
		umap[sum]++;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0) return true;
			sum += arr[i];
			if (umap[sum])return true;
			umap[sum]++;
		}
		return false;
	}
};