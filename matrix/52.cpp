// Given a N x N matrix, where every row and column is sorted in non-decreasing order.
//Find the kth smallest element in the matrix.

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int low = mat[0][0], high = mat[n - 1][n - 1];
  while (low <= high)
  {
    int midValue = (low + high) / 2;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      int low = 0, high = n - 1;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (mat[i][mid] >= midValue)
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


//min Heap solution

// Since each of the rows in matrix are already sorted, we can understand the problem as
// finding the kth smallest element from amongst M sorted rows.
// We start the pointers to point to the beginning of each rows,
// then we iterate k times, for each time ith, the top of the minHeap is the
//  ith smallest element in the matrix. We pop the top from the minHeap then
//  add the next element which has the same row with that top to the minHeap

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for (int i = 0; i < n; i++)
    pq.push({mat[i][0], i});

  vector<int> col(n, 1);

  int count = 1;
  if (k == 0 || k > (n * n))
    return -1;

  while (count < k)
  {
    while (col[pq.top().second] == n)
    {
      pq.pop();
      count++;
      if (count == k)
        break;
    }
    if (count == k)
      break;
    pair<int, int> p = pq.top(); pq.pop();
    pq.push({mat[p.second][col[p.second]], p.second});
    col[p.second]++;
    count++;
  }
  return pq.top().first;
}