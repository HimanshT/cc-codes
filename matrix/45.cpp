// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// // The first integer of each row is greater than the last integer of the previous row.

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int i, j;
    for (i = row - 1; i >= 0; i--)
    {
        if (matrix[i][0] > target)
            continue;
        else if (matrix[i][0] == target)
            return true;
        else if (target > matrix[i][0])
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
    }
    return false;
}

// possible other approach
while (l <= r)
{

    int mid = l + (r - l) / 2;

    if (matrix[mid / col][mid % col] < target)
    {
        l = mid + 1;
    }
    else if (matrix[mid / col][mid % col] > target)
    {
        r = mid - 1;
    }
    else
    {
        return true;
    }
}