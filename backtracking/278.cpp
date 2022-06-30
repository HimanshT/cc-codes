// Given a string s that contains parentheses and letters,
//  remove the minimum number of invalid parentheses to make the input string valid.

int fn(string s)
{
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push('(');
		else if (s[i] == ')')
		{
			if (!st.empty() && st.top() == '(')
				st.pop();
			else
				st.push(')');
		}
	}
	return st.size();
}


void solve(string s, vector<string> &ans, int removal, unordered_map<string, bool>&umap)
{
	if (umap[s]) return;

	umap[s] = true;

	if (removal == 0)
	{
		if (fn(s) == 0)
		{
			ans.push_back(s);
		}
		return;
	}

	for (int i = 0; i < s.length(); i++)
	{
		string temp = s.substr(0, i) + s.substr(i + 1);
		solve(temp, ans, removal - 1, umap);
	}

}

vector<string> removeInvalidParentheses(string s) {
	int x = fn(s);
	unordered_map<string, bool> umap;
	vector<string> ans;
	solve(s, ans, x, umap);
	return ans;
}