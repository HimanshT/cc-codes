// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int x, y;
	cin >> x >> y;
	int l, r;
	cin >> l >> r;

	for (int k = l - 1; k < r; k++)
	{
		int bit1 = y & (1 << k);
		x = x | bit1;
	}
	cout << x;
	return 0;
}