// nCr

int m = pow(10, 9) + 7;
int fn(int n, int r, vector<vector<int>>&arr)
{
	if (arr[n][r] != 0)
	{
		return arr[n][r];
	}

	if (r == 0)
	{
		arr[n][r] = 1;
		return arr[n][r];
	}
	else if (n == r)
	{
		arr[n][r] = 1;
		return arr[n][r];
	}
	else
	{
		int ans = fn(n - 1, r, arr) + fn(n - 1, r - 1, arr);
		ans = ans % m;
		arr[n][r] = ans;
		return ans;
	}

}

int nCr(int n, int r) {
	if (n < r)
		return 0;
	vector<vector<int>> arr;
	for (int i = 0; i <= n; i++)
	{
		vector<int> v;
		for (int j = 0; j <= n; j++)
		{
			v.push_back(0);
		}
		arr.push_back(v);
	}
	int ans = fn(n, r, arr);
	return ans;
}