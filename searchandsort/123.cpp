// Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int num = n + m;
    int arr[num];
    int ptr1 = 0, ptr2 = 0;
    for (int i = 0; i < num; i++)
    {
        if (ptr1 < n && ptr2 < m)
        {
            if (arr1[ptr1] <= arr2[ptr2])
            {
                arr[i] = arr1[ptr1];
                ptr1++;
            }
            else
            {
                arr[i] = arr2[ptr2];
                ptr2++;
            }
        }
        else if (ptr1 >= n)
        {
            arr[i] = arr2[ptr2];
            ptr2++;
        }
        else
        {
            arr[i] = arr1[ptr1];
            ptr1++;
        }
    }
    return arr[k - 1];

}

//using searching and sorting

class Solution {
public:
    int ans(int *arr1, int l1, int h1, int *arr2, int l2, int h2, int k)
    {
        if (l1 == h1)
            return arr2[k];
        if (l2 == h2)
            return arr1[k];
        int mid1 = (h1 - l1) / 2;
        int mid2 = (h2 - l2) / 2;
        if (mid1 + mid2 < k)
        {
            if (arr1[mid1] > arr2[mid2])
            {
                return ans(arr1, l1, h1, arr2, mid2 + 1, h2, k - mid2 - 1);
            } else {
                return ans(arr1, mid1 + 1, h1, arr2, l2, h2, k - mid1 - 1);
            }
        } else {
            if (arr1[mid1] > arr2[mid2])
            {
                return ans(arr1, l1, mid1, arr2, l2, h2, k);
            }
            else {
                return ans(arr1, l1, h1, arr2, l2, mid2, k);
            }
        }
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //compare both arrays,and traverse k times
        //divide and conquer
        return ans(arr1, 0, n, arr2, 0, m, k - 1);
    }
};