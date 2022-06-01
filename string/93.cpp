// Given a string S delete the characters which are appearing more than once consecutively.

string ans(int k, string &str)
{
	if (k == (str.length() - 1))
		return str;
	else
	{
		ans(k + 1, str);
		if (str[k] == str[k + 1])
			str = str.substr(0, k) + str.substr(k + 1);
		return str;
	}
}

string removeConsecutiveCharacter(string S)
{
	return ans(0, S);
}