// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.

string isSubset(int a1[], int a2[], int n, int m)
{
    int arr1[100000] = {0};

    for (int i = 0; i < n; i++)
        arr1[a1[i]]++;

    int count = 0;

    for (int j = 0; j < m; j++)
    {
        if (arr1[a2[j]] > 0)
        {
            arr1[a2[j]]--;
            count++;
        }
    }
    string str1 = "Yes";
    string str2 = "No";
    if (count == m)
        return str1;
    else
        return str2;