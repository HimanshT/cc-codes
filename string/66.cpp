// Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

class Solution
{
public:
	set<string> st;
	void fn(int low, int high, string S)
	{
		if (low == high)
			st.insert(S);
		for (int ptr = low; ptr <= high; ptr++)
		{
			swap(S[ptr], S[low]);
			fn(low + 1, high, S);
			swap(S[ptr], S[low]);
		}
	}
	vector<string>find_permutation(string S)
	{
		fn(0, S.length() - 1, S);
		vector<string> ans;
		set<string>::iterator it;
		for (it = st.begin(); it != st.end(); ++it)
			ans.push_back(*it);
		return ans;
	}
};
