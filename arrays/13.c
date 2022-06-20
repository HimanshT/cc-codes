// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
long long maxSubarraySum(int arr[], int n)
{

    int max_sum = INT_MIN;
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
        max_sum = max(max_sum, sum);
        if (sum < 0)
            sum = 0;
    }
    return max_sum;
}