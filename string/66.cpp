// Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

void permute(string S, int l, int r, vector<string> &ans)
{
	if (l == r)
	{
		ans.push_back(S);
		return;
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(S[i], S[l]);
			permute(S, l + 1, r, ans);
			swap(S[i], S[l]);
		}
	}
}

vector<string>find_permutation(string S)
{
	// Code here there
	vector<string> ans;
	permute(S, 0, S.length() - 1, ans);
	sort(ans.begin(), ans.end());
	return ans;
}