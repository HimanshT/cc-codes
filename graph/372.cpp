// Alien Dictionary

class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		//whenever you are given to find order,or arrows,look for graph algo then
		vector<vector<int>> graph(K);
		vector<int> indegree(K, 0);
		vector<int> visited(K, false);
		for (int i = 0; i < N - 1; i++)
		{
			string s1 = dict[i];
			string s2 = dict[i + 1];
			for (int j = 0; j < min(s1.length(), s2.length()); j++)
			{
				if (s1[j] != s2[j])
				{
					graph[s1[j] - 'a'].push_back(s2[j] - 'a');
					indegree[s2[j] - 'a']++;
					break;
				}
			}
		}
		//now use topological sort
		string ans = "";
		queue<int> q;
		for (int i = 0; i < K; i++)
			if (indegree[i] == 0)
				q.push(i);
		while (!q.empty())
		{
			int n = q.size();
			while (n--)
			{
				int t = q.front();
				q.pop();
				visited[t] = true;
				ans.push_back(t + 'a');
				for (auto& j : graph[t])
				{
					if (!visited[j])
					{
						indegree[j]--;
						if (indegree[j] == 0)
							q.push(j);
					}
				}
			}
		}
		//   cout<<ans;
		return ans;
	}
};