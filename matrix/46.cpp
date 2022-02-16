// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

int median(vector<vector<int>> &matrix, int r, int c)
{
    vector<int> v1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            v1.push_back(matrix[i][j]);
    }
    sort(v1.begin(), v1.end());
    int len = v1.size();
    if (len % 2 != 0)
        return v1[(len - 1) / 2];
    else
        return ((v1[(len / 2) - 1] + v1[len / 2]) / 2);
}

// better approach
// binary search
// concept: it must have  exactly n/2 minimum no.s form itself