// Partition Equal Subset Sum

int findSubsetSum(int n, int *arr, int target, int currSum)
{
	if (target == currSum)
		return 1;
	else if (target < currSum)
		return 0;
	if (n == 0)
		return 0;
	return (findSubsetSum(n - 1, arr, target, currSum + arr[n - 1]) or findSubsetSum(n - 1, arr, target, currSum));
}
int equalPartition(int N, int arr[])
{
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return 0;
	int x = findSubsetSum(N, arr, sum / 2, 0);
	return x;
}
};