// Power of 2

bool isPowerofTwo(long long n) {
	if (n == 0)
		return false;
	while (n >= 2)
	{
		if (n % 2 == 1)
			return false;
		n = n / 2;
	}
	return true;
}



/*
1. ceil(log2(n)) == floor(log2(n))
2.if set bit = 1;
3.n& (!n&(n-1)) =0
4.if ((n & (~(n - 1))) == n)
        return 1;

*/