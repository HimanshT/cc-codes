// Given a string s and a dictionary of words dict of length n,
// add spaces in s to construct a sentence where each word is a
// valid dictionary word. Each dictionary word can be used more than once.
// Return all such possible sentences.

vector<string> fn(unordered_map<string, int> umap, string str, vector<string> &ans, string &curr)
{
	if (str.length() == 0)
	{
		ans.push_back(curr);
	}
	else
	{
		for (int i = 1; i <= str.length(); i++)
		{
			if (umap.count(str.substr(0, i)))
			{
				string prev = curr;
				curr += str.substr(0, i);
				if (str.substr(i).length() != 0)
					curr += " ";
				fn(umap, str.substr(i), ans, curr);
				curr = prev;
			}
		}
		curr = "";
	}
	return ans;
}
vector<string> wordBreak(int n, vector<string>& dict, string s)
{
	vector<string> ans;
	unordered_map<string, int> umap;
	string curr;
	for (int i = 0; i < n; i++)
	{
		umap[dict[i]]++;
	}

	return fn(umap, s, ans, curr);

}