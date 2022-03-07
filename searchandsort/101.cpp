// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

int binarySearch(int *arr, int low, int high, int x)
{
    if (low <= high)
    {
        int mid = high + low / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, 0, mid - 1, x);
        else
            return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}

vector<int> find(int arr[], int n, int x)
{
    // code here
    vector<int> store;
    int index = binarySearch(arr, 0, n - 1, x);
    if (index == -1)
    {
        store.push_back(-1);
        store.push_back(-1);
        return store;
    }
    else
    {
        int ptr1, ptr2;
        ptr1 = index, ptr2 = index;
        while (ptr1 - 1 >= 0 && arr[ptr1 - 1] == x)
            ptr1--;
        while (ptr2 + 1 < n && arr[ptr2 + 1] == x)
            ptr2++;
        store.push_back(ptr1);
        store.push_back(ptr2);
        return store;
    }
}