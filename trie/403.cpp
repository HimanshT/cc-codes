// Find shortest unique prefix for every word in a given list

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class TrieNode {
public:
	bool isEnd;
	TrieNode *child[26];
	int count;
	TrieNode()
	{
		isEnd = false;
		for (int i = 0; i < 26; ++i)
		{
			child[i] = NULL;
		}
		count = 0;
	}
};


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
		curr->count++;
		curr = curr->child[index];
	}
	curr->count++;
	curr->isEnd = true;
}

string prefix(TrieNode *root, string &key)
{
	TrieNode *curr = root;
	for (int i = 0; i < key.length(); ++i)
	{
		int idx = key[i] - 'a';
		TrieNode *front = curr->child[idx];
		cout << front->count << " ";
		if (front->count == 1 || (front->isEnd == true && i == key.length() - 1))
			return (key.substr(0, i + 1));
		curr = front;
	}
}

int main()
{
	vector<string> v = {"zebra", "dog", "duck", "dove"};
	TrieNode *root = new TrieNode();
	for (int i = 0; i < v.size(); ++i)
	{
		insert(root, v[i]);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << prefix(root, v[i]) << endl;
	}

	return 0;
}