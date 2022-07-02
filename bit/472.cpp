// Number of 1 Bits

int setBits(int N) {
	int count = 0;
	while (N > 0)
	{
		count++;
		N = N & (N - 1);
	}
	return count;
}


//int setBits(int N)
{
	int n = __builtin_popcount(N);
	return n;
}