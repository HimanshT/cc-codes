// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

int findLongestConseqSubseq(int arr[], int N)
{
    sort(arr, arr + N);
    int maxSub = 1;
    int sub = 1;
    for (int i = 0; i < (N - 1); i++)
    {
        if (arr[i + 1] == (arr[i] + 1))
        {
            sub += 1;
            maxSub = max(sub, maxSub);
        }
        else if (arr[i + 1] == arr[i])
            continue;
        else
            sub = 1;
    }
    return maxSub;
}