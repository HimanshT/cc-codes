// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int row=n,col=n;
  int low=mat[0][0];
  int high=mat[row-1][col-1];
  while(low<=high)
  {
      int mid=(high+low)/2;
      int ans=0;
      for(int i=0;i<row;i++)
      {
          int rowLow=0;
          int rowHigh=col-1;
          while(rowLow<=rowHigh)
          {
              int rowMid=(rowLow+rowHigh)/2;
              if(mat[i][rowMid]<=mid)
              rowLow=rowMid+1;
              else
              rowHigh=rowMid-1;
          }
          ans=ans+rowLow;
      }
      if(ans<k)
      low=mid+1;
      else
      high=mid-1;
  }
  return low;
}

