//book allocation problem

class Solution
{

public:
	bool fn(int *arr, int n, int m, int target)
	{
		//starting the count with 1 because we are calculating the count from starting
		int count = 1;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > target) return false;
			if (arr[i] + sum > target)
			{
				count++; sum = arr[i];
			}
			else
				sum += arr[i];
		}
		if (count > m) return false;
		return true;
	}
	//Function to find minimum number of pages.
	int findPages(int A[], int N, int M)
	{
		if (M > N)
			return -1;
		//code here
		int low = 0;
		int high = 0;
		for (int i = 0; i < N; i++) high += A[i];
		int ans = 0;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			//can mid be a high value
			if (fn(A, N, M, mid))
			{
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return ans;
	}
};