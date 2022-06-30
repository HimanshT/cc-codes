// Choose and Swap

string chooseandswap(string a) {
	vector<int> arr(26, -1);
	int n = a.length();
	for (int i = 0; i < n; i++)
	{
		if (arr[a[i] - 'a'] == -1)
			arr[a[i] - 'a'] = i;
	}

	int i, j;
	for (i = 0; i < n; i++)
	{
		bool flag = false;
		for (j = 0; j < (a[i] - 'a'); j++)
		{
			if (arr[j] > arr[a[i] - 'a'])
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
			break;
	}
	if (i < n) {
		char ch1 = a[i];
		char ch2 = char(j + 'a');
		for (i = 0; i < n; i++)
		{
			if (a[i] == ch1)
				a[i] = ch2;
			else if (a[i] == ch2)
				a[i] = ch1;
		}
	}

	return a;

}