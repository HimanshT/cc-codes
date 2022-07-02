// Divide two integers without using multiplication, division and mod operator

// Divide two integers without using multiplication, division and mod operator

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// bool fn(int a, int b)
// {
// 	if ((a > 0 && b > 0) || (a < 0 && b < 0))
// 		return true;
// 	return false;
// }
// int main()
// {
// 	int a, b;
// 	cin >> a >> b;
// 	int temp = b; int div = 0;
// 	while (abs(b) <= abs(a))
// 	{
// 		div++;
// 		b += temp;
// 	}
// 	if (fn(a, b))
// 		cout << div;
// 	else
// 		cout << (0 - div);
// }

//other approach

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int divide(long long dividend, long long divisor) {
	int sign = ((dividend < 0) ^
	            (divisor < 0)) ? -1 : 1;

	dividend = abs(dividend);
	divisor = abs(divisor);

	long long quotient = 0, temp = 0;

	// test down from the highest bit and
	// accumulate the tentative value for
	// valid bit
	for (int i = 31; i >= 0; --i) {

		if (temp + (divisor << i) <= dividend) {
			temp += divisor << i;
			quotient |= 1LL << i;
		}
	}

	if (sign == -1) quotient = -quotient;

	return quotient;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << divide(a, b);
	return 0;
}