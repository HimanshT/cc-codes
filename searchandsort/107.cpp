// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
class Solution {
public:
    int *findTwoElement(int *arr, int n) {
        int index;
        int repeated = -1;
        for (int i = 0; i < n; i++)
        {
            index = abs(arr[i]) - 1;
            if (arr[index] < 0)
            {
                repeated = abs(arr[i]);
            } else {
                arr[index] = arr[index] * -1;
            }
        }
        int missing = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                missing = i + 1; break;
            }
        }

        int *ans = new int[n];
        ans[0] = repeated, ans[1] = missing;
        return ans;
    }
};