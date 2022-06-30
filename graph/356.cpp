// Creating and Printing

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
	vector<vector<int>> adjl(n);
	for (int i = 0; i < n; i++)
		adjl[i].push_back(i);
	for (int i = 0; i < m; i++)
	{
		adjl[edges[i][0]].push_back(edges[i][1]);
		adjl[edges[i][1]].push_back(edges[i][0]);
	}

	return adjl;
}