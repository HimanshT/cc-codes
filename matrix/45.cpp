// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// // The first integer of each row is greater than the last integer of the previous row.

// possible other approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(); int col = matrix[0].size();
        int r = 0, c = col - 1;
        while (r<row and c >= 0)
        {
            if (matrix[r][c] == target) return true;
            else if (target < matrix[r][c]) c--;
            else r++;
        }
        return false;
    }
};