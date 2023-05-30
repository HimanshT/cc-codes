// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

int bs(int *arr, int low, int high, int target)
{
    if (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return bs(arr, low, mid - 1, target);
        return bs(arr, mid + 1, high, target);
    }
    return -1;
}

bool findPair(int arr[], int size, int n) {
    //code
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        int idx = bs(arr, i + 1, size - 1, arr[i] + n);
        if ( idx != -1) return true;
    }
    return false;
}

//two pointer approach

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int i = 0;
    int j = 1;

    while (i < size && j < size)
    {
        if (i != j && arr[j] - arr[i] == n)
        {
            return true;
        }
        else if (arr[j] - arr[i] < n)
            j++;
        else
            i++;
    }

    return false;
}