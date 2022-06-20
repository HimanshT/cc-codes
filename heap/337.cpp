//Heap Sort
#include<bits/stdc++.h>
using namespace std;

void max_heapify(int *arr, int i, int n)
{
	int l = 2 * i + 1 ;
	int r = 2 * i + 2;
	int max = i;
	if (l < n && arr[l] > arr[max])
		max = l;
	if (r < n && arr[r] > arr[max])
		max = r;
	if (max != i) {
		swap(arr[max], arr[i]);
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

void heap_sort(int *arr, int n)
{
	for (int i = n - 1; i >= 1; --i)
	{
		swap(arr[0], arr[i]);
		build_maxHeap(arr, i);
	}
}

int main()
{
	int arr[10] = {4, 8, 10, 32, 6, 0, 4, 9, 10, 11};
	build_maxHeap(arr, 10);
	heap_sort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}