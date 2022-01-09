// Given an array of integers. Find the Inversion Count in the array.
// merged sort
// sol note done 1.2sec!!! don't is nlogn but asks to optimize more
#include <stdio.h>
int shift = 0;
int merge(int *arr, int lb, int mid, int up)
{
    int n = up - lb + 1;
    int newArr[n];
    int p1 = lb, p2 = mid + 1;
    for (int i = 0; i < n; i++)
    {
        if (p1 <= mid && p2 <= up)
        {
            if (arr[p1] < arr[p2])
            {
                newArr[i] = arr[p1];
                p1++;
            }
            else
            {
                newArr[i] = arr[p2];
                p2++;
                shift = shift + mid - p1 + 1;
            }
        }
        else if (p1 > mid)
        {
            newArr[i] = arr[p2];
            p2++;
        }
        else
        {
            newArr[i] = arr[p1];
            p1++;
        }
    }

    int j = 0;
    for (int i = lb; i <= up; i++)
    {
        arr[i] = newArr[j];
        j++;
    }
    return shift;
}

int mergesort(int *arr, int lb, int up)
{
    int value;
    if (lb < up)
    {
        int mid = (lb + up) / 2;
        mergesort(arr, 0, mid);
        mergesort(arr, mid + 1, up);
        value = merge(arr, lb, mid, up);
    }
    return value;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int ans;
    ans = mergesort(arr, 0, 4);
    for (int k = 0; k < 5; k++)
        printf("%d ", arr[k]);
    printf("\n%d", ans);
    return 0;
}