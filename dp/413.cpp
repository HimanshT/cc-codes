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

//write the recursive formula
// p(n,r)=p(n-1,r) + r*p(n-1,r-1);