//build a min or max heap

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

void max_heap(int *arr, int i, int n)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		max_heap(arr, largest, n);
	}

}

void build_maxHeap(int *arr, int n) //0 based index
{
	for (int i = (n / 2) - 1; i >= 0; i--)
		max_heap(arr, i, n);
}

int main()
{
	int arr[10] = {4, 8, 10, 32, 6, 0, 4, 9, 10, 11};
	build_maxHeap(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}