// Given binary string str of length N. The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.


int maxSubStr(string str) {
	//Write your code here
	int n = str.length();
	int ans = 0;
	int currLen = 0;
	int zero = 0, one = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '0')
			zero++;
		if (str[i] == '1')
			one++;
		if (zero == one)
		{
			ans++;
			currLen += zero * 2;
			one = zero = 0;
		}
	}
	if (currLen != n)
		return -1;
	else
		return ans;
}