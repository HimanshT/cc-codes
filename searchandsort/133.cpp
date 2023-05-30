// Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000),
// determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

#include<bits/stdc++.h>
using namespace std;

long long fn(long long *arr, int n, long long a, long long b)
{

}

int main()
{
	int n;
	long long a, b;
	cin >> n >> a >> b;
	long long arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << fn(arr, n, a, b) << endl;
	return 0;
}