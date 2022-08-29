// Given an array A[] of size N,
// find the longest subsequence such that difference between
// adjacent elements is one.

class Solution {
public:
    int longestSubsequence(int N, int A[])
    {
        int arr[N];
        arr[0] = 1;
        for (int i = 1; i < N; i++)
        {
            arr[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (abs(A[j] - A[i]) == 1)
                {
                    arr[i] = max(arr[i], arr[j] + 1);
                }
            }
        }

        int ans = *max_element(arr, arr + N);
        return ans;
    }
};