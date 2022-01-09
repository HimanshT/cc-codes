// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        int min = 1, max = k - 1;
        int arrCheck[k];
        for (int i = 0; i < k; i++)
            arrCheck[i] = 0;
        // logic

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= min && arr[i] <= max)
            {
                int value = k - arr[i];
                if (arrCheck[value] > 0)
                {
                    count += arrCheck[value];
                    arrCheck[arr[i]]++;
                }
                else
                {
                    arrCheck[arr[i]]++;
                }
            }
        }
        return count;
    }
};