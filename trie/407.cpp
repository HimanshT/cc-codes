// Unique rows in boolean matrix

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
	unordered_map<string, int> umap;
	vector<vector<int>> ans;
	for (int i = 0; i < row; i++)
	{
		string str = "";
		vector<int> vi;
		for (int j = 0; j < col; j++)
		{
			string a = to_string(M[i][j]);
			str += a;
			vi.push_back(M[i][j]);
		}
		if (umap[str] == 0)
		{
			umap[str]++;
			ans.push_back(vi);
		}
	}

	return ans;
}


Create a Trie where rows can be stored.
Traverse through the matrix and insert the row into the Trie.
Trie cannot store duplicate entries so the duplicates will be removed
Traverse the Trie and print the rows.