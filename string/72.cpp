//word break

int wordbreak(string str, set<string> s1)
{
	int size = str.size();
	if (size == 0)   return true;
	bool wb[size + 1];
	memset(wb, 0, sizeof(wb));
	for (int i = 1; i <= size; i++)
	{
		if (wb[i] == false && s1.count(( str.substr(0, i) )))
			wb[i] = true;

		if (wb[i] == true)
		{
			// If we reached the last prefix
			if (i == size)
				return true;

			for (int j = i + 1; j <= size; j++)
			{
				// Update wb[j] if it is false and can be updated
				// Note the parameter passed to dictionaryContains() is
				// substring starting from index 'i' and length 'j-i'
				if (wb[j] == false && s1.count(( str.substr(i, j - i) )))
					wb[j] = true;

				// If we reached the last character
				if (j == size && wb[j] == true)
					return true;
			}
		}
	}
	return false;
}

int wordBreak(string A, vector<string> &B) {
	//code here
	set<string> s1;
	for (auto i : B)
	{
		s1.insert(i);
	}
	return (wordbreak(A, s1));
}