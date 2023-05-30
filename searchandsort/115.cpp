// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

//the concepts of this topic is that if we calculate the sum and for every index,store the sum in an array. Then the no. of subarrays with sum =0
//will be equal no of times a sum in an array is repeated

// Maintain sum of elements encountered so far in a variable (say sum).
// If current sum is 0, we found a subarray starting from index 0 and ending at index current index
// Check if current sum exists in the hash table or not.
// If current sum already exists in the hash table then it indicates that this sum was the sum of some sub-array elements arr[0]...arr[i] and now the same sum is obtained for the current sub-array arr[0]...arr[j] which means that the sum of the sub-array arr[i+1]...arr[j] must be 0.
// Insert current sum into the hash table

class Solution {
public:
	//Function to count subarrays with sum equal to 0.
	long long int findSubarray(vector<long long int> &arr, int n ) {
		//code here
		unordered_map<long long int, int> umap;
		long long sum = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			if (sum == 0) ans++;
			if (umap[sum] > 0) ans += umap[sum];
			umap[sum]++;
		}
		return ans;
	}
};