// Print Anagrams Together

vector<vector<string> > Anagrams(vector<string>& string_list) {
	vector<vector<string>> ans;
	unordered_map<string, vector<string>> umap;
	for (int i = 0; i < string_list.size(); i++)
	{
		string str = string_list[i];
		sort(str.begin(), str.end());
		umap[str].push_back(string_list[i]);
	}

	for (auto it : umap)
		ans.push_back(it.second);

	return ans;

}