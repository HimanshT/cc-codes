// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

class Solution
{
public:
	//Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
		// Code here
		int ans = 0;
		vector<int>copy = nums;
		sort(copy.begin(), copy.end());
		unordered_map<int, int> umap;
		for (int i = 0; i < nums.size(); i++)
		{
			umap[nums[i]] = copy[i];
		}
		unordered_map<int, int> visited;
		for (auto &x : umap)
		{
			if (visited[x.first] > 0) continue;
			int count = 0;
			int first = x.first;
			int y1 = first, y2 = x.second;
			while (first != y2)
			{
				visited[y1] = 1;
				y1 = y2;
				y2 = umap[y1];
				count++;
			}
			visited[y1] = 1;
			ans += count;
		}
		return ans;
	}
};