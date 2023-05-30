// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
//boyer-moore majority algorithm

class Solution {
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {

        //boyer moore majority voting algorithm
        int candidate = -1, votes = 0;
        for (int i = 0; i < size; i++)
        {
            if (!votes)
            {
                candidate = a[i], votes = 1; continue;
            } else if (a[i] == candidate) votes++;
            else votes--;
        }

        int freq = 0;
        for (int i = 0; i < size; i++) if (a[i] == candidate) freq++;
        if (freq > size / 2) return candidate;
        return -1;

    }
};