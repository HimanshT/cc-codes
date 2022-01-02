// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
void mergeArray(int *array1, int n1, int *array2, int n2)
{
    int len = n1 + n2;
    int newArray[len];
    int l1, l2;
    l1 = l2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (l1 <= n1 && l2 <= n2)
        {
            if (array1[l1] > array2[l2])
            {
                newArray[i] = array1[l1];
                l1++;
            }
            else
            {
                newArray[i] = array2[l2];
            }
        }
        else if (l1 > n1)
        {
            newArray[i] = array2[l2];
        }
        else
        {
            newArray[i] = array1[l1];
        }
    }
}