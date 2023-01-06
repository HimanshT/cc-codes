// Given an array of integers. Find the Inversion Count in the array.
// merged sort
// sol note done 1.2sec!!! don't is nlogn but asks to optimize more

class Solution {
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long ans = 0;
    void merge(long long *arr, long long low, long long mid, long long high)
    {
        long long n = high - low + 1;
        long long temp[n];
        long long ptr1 = low, ptr2 = mid + 1;
        for (long long i = 0; i < n; i++)
        {
            if (ptr1 <= mid and ptr2 <= high)
            {
                if (arr[ptr1] <= arr[ptr2])//made a mistake here last time
                {

                    temp[i] = arr[ptr1];
                    ptr1++;
                }
                else
                {
                    ans += mid - ptr1 + 1;
                    temp[i] = arr[ptr2];
                    ptr2++;
                }
            } else if (ptr1 > mid)
            {

                temp[i] = arr[ptr2];
                ptr2++;
            }
            else if (ptr2 > high)
            {
                temp[i] = arr[ptr1];
                ptr1++;
            }
        }
        //copy those same elements to our prev array
        int j = 0;
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[j];
            j++;
        }

    }
    void mergeSort(long long *arr, long long low, long long high)
    {
        if (low < high)
        {
            long long mid = (high + low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr, 0, N - 1);
        return ans;
    }

};