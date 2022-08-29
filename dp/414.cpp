#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int binomialCoefficient(int n, int k)
{
	int res = 1;
	// C(n,k)==C(n,n-k)
	if (k > n - k)
		k = n - k;
	for (int i = 0; i < k; i++)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

int fn(int n)
{
	int c = binomialCoefficient(2 * n, n);
	return c / (n + 1);
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		for (int i = 0; i < 10; i++)
			cout << fn(i) << endl;
	}
	return 0;
}