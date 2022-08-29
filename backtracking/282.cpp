// Partition Equal Subset Sum


//brute force
bool fn(int N, vector<int>&v1, vector<int> &v2, int *arr, int ptr, int sum1, int sum2, int reqSum)
{
    if (ptr == N)
    {
        if (v1.empty() || v2.empty())
            return false;
        else
            return (sum1 == sum2);
    }
    bool one = false, two = false;
    if (sum1 + arr[ptr] <= reqSum)
    {
        v1.push_back(arr[ptr]);
        one = fn(N, v1, v2, arr, ptr + 1, sum1 + arr[ptr], sum2, reqSum);
        v1.pop_back();
    }

    if (sum2 + arr[ptr] <= reqSum)
    {
        v2.push_back(arr[ptr]);
        two = fn(N, v1, v2, arr, ptr + 1, sum1, sum2 + arr[ptr], reqSum);
        v2.pop_back();
    }

    return one or two;

}
int equalPartition(int N, int arr[])
{
    vector<int> v1, v2;
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return 0;
    int sum1 = 0, sum2 = 0;
    return fn(N, v1, v2, arr, 0, sum1, sum2, sum / 2);
}

//optimized

//find a subarray with given sum
int f1(int *arr, int i, int n, int sum, int currSum)
{
    if (i == n)
        return (sum == currSum ? 1 : 0);

    if (sum == currSum)
        return 1;
    else if (currSum > sum)
        return 0;
    else
        return (f1(arr, i + 1, n, sum, currSum + arr[i]) or f1(arr, i + 1, n, sum, currSum));

}
int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return 0;
    return f1(arr, 0, N, sum / 2, 0);
}