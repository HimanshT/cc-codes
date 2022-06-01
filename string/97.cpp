// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in str1 should map to the same character in str2

bool areIsomorphic(string str1, string str2)
{

	// Your code here
	int n = str1.length();
	if (n != str2.length())
		return false;
	vector<char> v1(256, '0');
	vector<bool> v2(256, false);
	for (int i = 0; i < n; i++)
	{
		char c1 = str1[i];
		char c2 = str2[i];
		if (v1[c1] == '0' && v2[c2] == false)
		{
			v1[c1] = c2;
			v2[c2] = true;
		}
		else if (v1[c1] == '0' && v2[c2] == true)
			return false;
		else if (v1[c1] != '0' && v1[c1] != c2)
			return false;
	}
	return true;
}