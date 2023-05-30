// // Given an array arr[] of distinct integers of size N and a value sum,
// the task is to find the count of triplets (i, j, k),
//  having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.
// //the concept is that while moving pointer,if the value is greater end--,but if smaller,
//  the total values having sum less will be (end-start)


class Solution {
public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
		sort(arr, arr + n);
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			int j = i + 1, k = n - 1;
			while (j < k)
			{
				if (arr[i] + arr[j] + arr[k] < sum)
				{
					ans += k - j;
					j++;
				} else k--;
			}
		}
		return ans;
	}
};