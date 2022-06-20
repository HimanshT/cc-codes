// Permutation Coefficient

int P(int n, int k) {
	// Write your code here.
	if (n < k)
		return 0;
	int m = 1000000007;
	long long int ans = 1;
	for (long long int i = n; i > (n - k); i--)
		ans = (ans * i) % m;
	return ans;
}