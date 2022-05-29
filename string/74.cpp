// Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

// NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

int lps(string str) {
	// Your code goes here
	int n = str.length();
	vector<int> v(n, 0);
	int i = 0, j = 1;
	while (j < n)
	{
		if (str[i] == str[j])
		{
			v[j] = i + 1;
			i++, j++;
		}
		else
		{
			if (i > 0)
			{
				i = v[i - 1];
			}
			else
			{
				j++;
			}
		}
	}
	return v[n - 1];
}