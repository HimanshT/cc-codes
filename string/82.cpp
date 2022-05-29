// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	string common = "";
	if (n == 1)
		return strs[0];
	//comparing for 1 and 2
	int n1 = strs[0].length();
	int n2 = strs[1].length();
	int i = 0;
	while (i < n1 && i < n2)
	{
		if (strs[0][i] == strs[1][i])
			common += strs[0][i];
		else
			break;
		i++;
	}
	//checking for other strings
	for (int j = 2; j < n; j++)
	{
		int len = common.length();
		int bpoint = 0;
		if (len == 0)
			break;
		for (int i = 0; i < len; i++)
		{
			if (strs[j][i] == common[i])
			{
				bpoint++;
			}
			else
			{
				break;
			}
		}
		common = common.substr(0, bpoint);
	}
	return common;

}