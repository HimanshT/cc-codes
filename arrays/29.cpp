// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// int findLongestConseqSubseq(int arr[], int N)
// {
//     sort(arr, arr + N);
//     int maxSub = 1;
//     int sub = 1;
//     for (int i = 0; i < (N - 1); i++)
//     {
//         if (arr[i + 1] == (arr[i] + 1))
//         {
//             sub += 1;
//             maxSub = max(sub, maxSub);
//         }
//         else if (arr[i + 1] == arr[i])
//             continue;
//         else
//             sub = 1;
//     }
//     return maxSub;
// }

class Solution {
public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int n = *max_element(arr, arr + N);
        vector<int> v(n + 1, 0);
        for (int i = 0; i < N; i++)
            v[arr[i]] = 1;
        int ans = 0;
        int ptr1 = 0;
        while (ptr1 <= n)
        {
            if (v[ptr1] == 1)
            {
                int count = 0;
                while (v[ptr1] != 0 and ptr1 <= n)
                {
                    count++;
                    ptr1++;
                }
                ans = max(ans, count);
            }
            else
                ptr1++;
        }
        return ans;
    }
};