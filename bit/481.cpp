// Power Set

void fn(int i, string s, vector<string> &ans, string str)
{
	if (i == s.length() && str.size() >= 1)
		ans.push_back(str);
	else if (i == s.length())
		return;
	else
	{
		str.push_back(s[i]);
		fn(i + 1, s, ans, str);
		str.pop_back();
		fn(i + 1, s, ans, str);

	}
}
vector<string> AllPossibleStrings(string s) {
	vector<string> ans;
	fn(0, s, ans, "");
	sort(ans.begin(), ans.end());
	return ans;
}