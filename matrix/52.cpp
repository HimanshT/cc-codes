// Given a N x N matrix, where every row and column is sorted in non-decreasing order.
//Find the kth smallest element in the matrix.

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int row = n, col = n;
  int low = mat[0][0];
  int high = mat[row - 1][col - 1];
  while (low <= high)
  {
    int mid = (high + low) / 2;
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
      int rowLow = 0;
      int rowHigh = col - 1;
      while (rowLow <= rowHigh)
      {
        int rowMid = (rowLow + rowHigh) / 2;
        if (mat[i][rowMid] <= mid)
          rowLow = rowMid + 1;
        else
          rowHigh = rowMid - 1;
      }
      ans = ans + rowLow;
    }
    if (ans < k)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}



//min Heap solution

// Since each of the rows in matrix are already sorted, we can understand the problem as finding the kth smallest element from amongst M sorted rows.
// We start the pointers to point to the beginning of each rows,
// then we iterate k times, for each time ith, the top of the minHeap is the
//  ith smallest element in the matrix. We pop the top from the minHeap then
//  add the next element which has the same row with that top to the minHeap