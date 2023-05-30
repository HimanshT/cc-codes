// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.
//this problem is equivalent to find the median of n sorted matrices
//this problem is basically find the xth smallest element in the matrix

class Solution {
public:
    int median(vector<vector<int>> &matrix, int R, int C) {
        // code here
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            low = min(matrix[i][0], low);
            high = max(matrix[i][C - 1], high);
        }
        int k = (R * C + 1) / 2;
        while (low <= high)
        {
            int midValue = (low + high) / 2;
            int count = 0;
            for (int i = 0; i < R ; i++)
            {
                int low = 0, high = C - 1;
                while (low <= high)
                {
                    int mid = (low + high) / 2;
                    if (matrix[i][mid] >= midValue)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                count += low;
            }
            if (count >= k)
                high = midValue - 1;
            else
                low = midValue + 1;
        }
        return high;

    }
};