// Trie | (Insert and Search)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class TrieNode {
public:
	bool isEnd;
	TrieNode *child[26];
	TrieNode()
	{
		isEnd = false;
		for (int i = 0; i < 26; ++i)
		{
			child[i] = NULL;
		}
	}
};

bool search(TrieNode *root, string &key)
{
	TrieNode *curr = root;
	for (int i = 0; i < key.length(); ++i)
	{
		int idx = key[i] - 'a';
		if (curr->child[idx] == NULL)
		{
			return false;
		}
		curr = curr->child[idx];
	}
	if (curr->isEnd) return true;
	else return false;
}

void insert(TrieNode *root, string &key)
{
	TrieNode *curr = root;
	for (int i = 0; i < key.length(); ++i)
	{
		int index = key[i] - 'a';
		if (curr->child[index] == NULL)
		{
			curr->child[index] = new TrieNode();
		}
		curr = curr->child[index];
	}
	curr->isEnd = true;
}

int main()
{
	vector<string> v = {"apple", "boiler", "catering", "diversion", "nothing"};
	TrieNode *root = new TrieNode();
	for (int i = 0; i < v.size(); ++i)
	{
		insert(root, v[i]);
	}
	string key = "appl";
	cout << search(root, key);
	return 0;
}