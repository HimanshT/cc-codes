//subset sums

#include<bits/stdc++.h>
using namespace std;

int findsubsetsum(int *arr, int n, int x1, int x2)
{

}

int main()
{
	int n; cin >> n;
	int x1, x2; cin >> x1 >> x2;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << findsubsetsum(arr, n, x1, x2);
}