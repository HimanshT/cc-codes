// Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

string secFrequent (string arr[], int n)
{
	//code here.
	map<string, int> m1;
	for (int i = 0; i < n; i++)
	{
		m1[arr[i]]++;
	}

	int max = 0;
	for (auto it : m1)
	{
		if (it.second > max)
			max = it.second;
	}

	int sMax = 0;
	string ans;
	for (auto it : m1)
	{
		if (it.second > sMax && it.second < max)
		{
			sMax = it.second;
			ans = it.first;
		}
	}
	return ans;
}

//other way
