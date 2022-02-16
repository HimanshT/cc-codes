// Given an NxN matrix Mat. Sort all elements of the matrix.

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        // code here
        int row = Mat.size();
        int col = Mat[0].size();
        vector<int> copy;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                copy.push_back(Mat[i][j]);
            }
        }

        int t = 0;
        sort(copy.begin(), copy.end());
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Mat[i][j] = copy[t];
                t++;
            }
        }

        return Mat;
    }
};