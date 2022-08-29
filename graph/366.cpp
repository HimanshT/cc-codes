//word ladder

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//step1:inserting values;
		unordered_set<string> uset;
		bool present = false;
		for (auto& word : wordList)
		{
			if (word == endWord)
				present = true;
			uset.insert(word);
		}
		if (present == false)
			return 0;
		//bfs
		int depth = 0;
		queue<string> q;
		q.push(beginWord);
		while (!q.empty())
		{
			int n = q.size();
			depth++;
			while (n--)
			{
				string curr = q.front(); q.pop();
				for (int i = 0; i < curr.length(); i++)
				{
					string temp = curr;
					for (int j = 'a'; j <= 'z'; j++)
					{
						temp[i] = j;
						if (temp != curr && uset.find(temp) != uset.end())
						{
							if (temp == endWord)
								return depth + 1;
							q.push(temp);
							uset.erase(temp);
						}
					}
				}
			}
		}
		return 0;
	}
};