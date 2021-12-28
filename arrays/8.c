// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct

int kthSmallest(int arr[], int l, int r, int k)
{
    int brr[100000] = {0};
    for (int i = 0; i <= r; i++)
    {
        brr[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (brr[i] > 0)
            count++;
        if (count == k)
            return (i);
    }
}