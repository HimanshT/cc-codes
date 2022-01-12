// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

// array A[] which sums up to X.
bool find3Numbers(int A[], int n, int X)
{
    for (int i = 0; i < n; i++)
    {
        int a = A[i];
        int sum = X - A[i];
        // finding if there is a pair;
        int arr[100001] = {0};
        for (int j = i + 1; j < n; j++)
        {
            int value = sum - A[j];
            if (value > 0)
            {
                if (arr[value] > 0)
                {
                    return true;
                }
            }

            arr[A[j]]++;
        }
    }
    return false;
}