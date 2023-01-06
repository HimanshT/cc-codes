// Given an array arr of n positive integers and a number k.
// One can apply a swap operation on the array any number of times,
// i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] .
// Find the minimum number of swaps required to bring all the numbers less than or equal to k together,
//  i.e. make them a contiguous subarray.


class Solution
{
public:
	int minSwap(int arr[], int n, int k) {
		// Complet the function
		int count = 0;
		for (int i = 0; i < n; i++)
			if (arr[i] <= k) count++;

		int ptr1 = 0, ptr2 = 0, currcount = 0;
		for (; ptr2 <= count - 1; ptr2++)
		{
			if (arr[ptr2] <= k) currcount++;
			if (ptr2 == count - 1)
				break;
		}

		int swaps = INT_MAX;
		while (ptr2 < n)
		{
			swaps = min(swaps, count - currcount);
			if (arr[ptr1] <= k) currcount--;
			ptr1++;
			ptr2++;
			if (ptr2 < n)
			{
				if (arr[ptr2] <= k) currcount++;
			}
		}
		return swaps == INT_MAX ? 0 : swaps;
	}
};