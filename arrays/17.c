// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

class Solution {
public:
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i, j, gap = n + m;
        for (gap = nextGap(gap);
                gap > 0; gap = nextGap(gap))
        {
            // comparing elements in the first array.
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);

            // comparing elements in both arrays.
            for (j = 0;
                    i < n && j < m;
                    i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);

            if (j < m) {
                // comparing elements in the second array.
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            }
        }
    }
};

///THe same logic can be used for sorting a array that is Kth distance from getting sorted