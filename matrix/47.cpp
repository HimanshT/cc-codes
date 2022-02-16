// You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    int max1 = 0, row = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][m - 1] == 0)
            continue;
        else
        {
            int y = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    y = j;
                    break;
                }
            }
            int count = m - y;
            if (count > max1)
            {
                max1 = count;
                row = i;
            }
        }
    }
    if (max1 == 0)
        return -1;
    else
        return row;
}

// instead of traversal we could have used the binary search to find the first instance of one