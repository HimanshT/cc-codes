// Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

int countRev (string str)
{
	// your code here
	stack<char> st;
	int n = str.length();
	//removing the possibility of odd cases
	if (n % 2 != 0)
		return -1;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '{')
			st.push(str[i]);
		else
		{
			if (!st.empty())
			{
				if (st.top() == '{')
					st.pop();
				else
					st.push(str[i]);
			}
			else {
				st.push(str[i]);
			}
		}
	}
	//code for calculation of changes
	if (st.empty())
		return count;
	while (1)      //stack --- {--bracket1 {---bracket2
	{
		char bracket1, bracket2;
		bracket2 = st.top(); st.pop();
		if (bracket2 != '}')
			count++;
		bracket1 = st.top(); st.pop();
		if (bracket1 != '{')
			count++;
		if (st.empty())
			break;
	}
	return count;
}