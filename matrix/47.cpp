// You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

// instead of traversal we could have used the binary search to find the first instance of one

class Solution {
public:
    int bs(vector<int> a, int low, int high, int target)
    {
        if (a[high] == 0)
            return INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] <= 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code here
        int idx = INT_MAX, row = -1;
        for (int i = 0; i < n; i++)
        {
            int index = bs(arr[i], 0, m - 1, 0);
            if (index < idx)
            {
                idx = index, row = i;
            }
        }
        return row;
    }

};


// to find the first occurence of any no in binarysearch

int first(bool arr[], int low, int high)
{
    if (high >= low)
    {
        // Get the middle index
        int mid = low + (high - low) / 2;

        // Check if the element at middle index is first 1
        if ( ( mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
            return mid;

        // If the element is 0, recur for right side
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);

        // If element is not first 1, recur for left side
        else
            return first(arr, low, (mid - 1));
    }
    return -1;
}

//much better approach

class Solution {
public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code here
        int ans = -1, count = 0;
        int currcol = m, currrow = 0;
        while (currrow < n)
        {
            while (arr[currrow][currcol - 1] == 1 and currcol >= 1)
                currcol--;

            if (m - currcol > count)
            {
                ans = currrow;
                count = m - currcol;
            }

            if (currcol == 0)
                break;

            currrow++;
        }
        return ans;
    }

};