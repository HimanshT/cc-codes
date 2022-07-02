// Count total set bits

void solve(int n, int &count)
{
	if (n == 0)
		return;
	int x = floor(log2(n));
	count = count + (pow(2, x - 1) * x) + (n - pow(2, x) + 1);
	solve((n - pow(2, x)), count);
}
int countSetBits(int n)
{
	int count = 0;
	solve(n, count);
	return count;
}