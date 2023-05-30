// Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements.

class Solution {
public:
    static int cmp(int a, int b)
    {
        int count1 = __builtin_popcount(a);
        int count2 = __builtin_popcount(b);

        // this takes care of the stability of
        // sorting algorithm too
        if (count1 <= count2)
            return false;
        return true;
    }

    // Function to sort according to bit count using
    // std::sort
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, cmp);
    }
};