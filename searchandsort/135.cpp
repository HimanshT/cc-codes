// In-Place Merge Sort

#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int h)
{
	int ptr1 = l, ptr2 = mid + 1;
	while (ptr1 < ptr2 and ptr2 <= h)
	{
		if (arr[ptr1] <= arr[ptr2])
			ptr1++;
		else
		{
			int x = arr[ptr2];
			for (int i = ptr2; i > ptr1; i--)
				arr[i] = arr[i - 1];
			arr[ptr1] = x;
			ptr1++, ptr2++;
		}
	}
}

void mergesort(int *arr, int l, int h)
{
	if (l < h)
	{
		int mid = (l + h) / 2;
		mergesort(arr, 0, mid);
		mergesort(arr, mid + 1, h);
		merge(arr, l, mid, h);
	}
}

int main()
{
	int arr[] = {3, 6, 1, 9, 10, 2, 3};
	int n = 7;
	mergesort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}