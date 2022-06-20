// Word Break (Trie)

class TrieNode {
public:
	bool isEnd;
	TrieNode *child[26];
	TrieNode() {
		isEnd = false;
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
	}
};

void insert(TrieNode *root, string &key)
{
	TrieNode *curr = root;
	for (int i = 0; i < key.size(); i++)
	{
		int idx = key[i] - 'a';
		if (curr->child[idx] == NULL)
			curr->child[idx] = new TrieNode();
		curr = curr->child[idx];
	}
	curr->isEnd = true;
}

bool search(TrieNode* root, string key)
{
	TrieNode *curr = root;
	for (int i = 0; i < key.size(); i++)
	{
		int idx = key[i] - 'a';
		if (curr->child[idx] == NULL)
			return false;
		curr = curr->child[idx];
	}
	if (curr->isEnd) return true;
	return false;
}

bool fn(TrieNode *root, string key)
{
	int n = key.size();
	if (n == 0)
		return true;
	for (int i = 1; i <= n; i++)
	{
		if (search(root, key.substr(0, i)) && fn(root, key.substr(i)))
			return true;
	}
	return false;
}

class Solution {
public:
	// A : given string to search
	// B : vector of available strings
	int wordBreak(string A, vector<string> &B) {
		TrieNode *root = new TrieNode();
		for (int i = 0; i < B.size(); i++)
		{
			string key = B[i];
			insert(root, key);
		}

		//solving
		return fn(root, A);
	}
};