// Given a string S consisting of only opening and closing curly brackets '{' and '}',
//find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

int countRev (string s)
{
	// your code here
	stack<char> st;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '{')
			st.push(s[i]);
		else
		{
			if (st.empty())
				st.push(s[i]);
			else if (st.top() == '{')
				st.pop();
			else
				st.push(s[i]);
		}
	}
	if (st.size() % 2 != 0)
		return -1;
	int ans = 0;
	while (!st.empty())
	{
		char c1 = st.top(); st.pop();
		char c2 = st.top(); st.pop();
		if (c1 != '}') ans++;
		if (c2 != '{') ans++;
	}
	return ans;
}