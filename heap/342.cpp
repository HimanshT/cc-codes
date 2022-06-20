// Merge two binary Max heaps

void max_heapify(vector<int> &arr, int i, int n)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int maxi = i;
	if (l < n && arr[l] > arr[maxi]) maxi = l;
	if (r < n && arr[r] > arr[maxi]) maxi = r;
	if (maxi != i)
	{
		swap(arr[i], arr[maxi]);
		max_heapify(arr, maxi, n);
	}
}
void maxHeap(vector<int> &arr, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
		max_heapify(arr, i, n);
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
	vector<int> max_heap;
	for (int i = 0; i < n; i++)
		max_heap.push_back(a[i]);
	for (int j = 0; j < m; j++)
		max_heap.push_back(b[j]);
	//max _ heap
	maxHeap(max_heap, n + m);
	return max_heap;
}