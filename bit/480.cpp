// Calculate square of a number without using *, / and pow()

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int square(int n)
{
	if (n == 0) return 0;
	if (n < 0) n = -n;

	int x = n >> 1; //floor value of (n/2);
	if (n & 1)
		return ((square(x) << 2) + (x << 2) + 1);
	else
		return (square(x) << 2);
}

int main()
{
	int a;
	cin >> a ;
	cout << square(a);
	return 0;
}