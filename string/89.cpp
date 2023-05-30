// Given an array of strings,
// return all groups of strings that are anagrams.
// The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

class Solution {
public:
	vector<vector<string> > Anagrams(vector<string>& string_list) {
		//code here
		map<string, vector<string>> umap;
		for (auto str : string_list)
		{
			string temp = str;
			sort(temp.begin(), temp.end());
			umap[temp].push_back(str);
		}
		vector<vector<string>> ans;
		for (auto &x : umap)
		{
			vector<string> temp = x.second;

			ans.push_back(temp);
		}
		return ans;
	}
};