// Given an array Arr of N positive integers. Your task is to find the elements whose value is equal to that of its index value ( Consider 1-based indexing ).

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == (i + 1))
            v.push_back(arr[i]);
    }
    return v;
}