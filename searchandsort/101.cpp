// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

int bs(int *arr, int low, int high, int x)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return bs(arr, mid + 1, high, x);
        return bs(arr, low, mid - 1, x);
    }
    return -1;
}

int fn1(int *arr, int low, int high, int x) //find the first occurence
{
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1;
        } else if (x > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

int fn2(int *arr, int low, int high, int x)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1;
        } else if (x > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    int find = bs(arr, 0, n - 1, x);
    if (find == -1)
        return { -1, -1};
    int fs = fn1(arr, 0, n - 1, x);
    int ls = fn2(arr, 0, n - 1, x);
    return {fs, ls};
}