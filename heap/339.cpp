// k largest elements

void max_heapify(int *arr, int i, int n)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;
	if (l < n && arr[l] > arr[max])
		max = l;
	if (r < n && arr[r] > arr[max])
		max = r;
	if (max != i)
	{
		swap(arr[i], arr[max]);
		max_heapify(arr, max, n);
	}
}

void build_maxHeap(int *arr, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		max_heapify(arr, i, n);
	}
}

void heap_sort(int *arr, int n, int k, vector<int>&ans)
{
	int t = k;
	for (int i = n - 1; i >= 1; i--)
	{
		ans.push_back(arr[0]);
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i);
		t--;
		if (t == 0)
			break;
	}
}

vector<int> kLargest(int arr[], int n, int k) {
	vector<int> ans;
	build_maxHeap(arr, n);
	heap_sort(arr, n, k, ans);
	return ans;
}



/*

1) Store the first k elements in a temporary array temp[0..k-1].
2) Find the smallest element in temp[], let the smallest element be min.
3-a) For each element x in arr[k] to arr[n-1]. O(n-k)
If x is greater than the min then remove min from temp[] and insert x.
3-b)Then, determine the new min from temp[]. O(k)
4) Print final k elements of temp[]





*/