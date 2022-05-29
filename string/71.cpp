// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

bool ispar(string str)
{
	// Your code here
	stack<char> s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			s.push(str[i]);
		else
		{
			if (s.empty())
				return false;
			else if (str[i] == ']' && s.top() == '[')
				s.pop();
			else if (str[i] == '}' && s.top() == '{')
				s.pop();
			else if (str[i] == ')' && s.top() == '(')
				s.pop();
			else
				return false;
		}
	}
	if (s.empty())
		return true;
	return false;
}
