// Phone directory

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

void func(TrieNode *head, string &t, vector<string>&ans)
{
    if (head->isEnd) ans.push_back(t);
    for (int i = 0; i < 26; i++)
    {
        if (head->child[i])
        {
            t.push_back('a' + i);
            func(head->child[i], t, ans);
            t.pop_back();
        }
    }
}

vector<string> fn1(TrieNode* root, string &key)
{
    TrieNode *head = root;
    for (int i = 0; i < key.size(); i++)
    {
        int idx = key[i] - 'a';
        if (!head->child[idx])
            head->child[idx] = new TrieNode();
        head = head->child[idx];
    }
    vector<string> ans;
    func(head, key, ans);
    if (ans.empty()) ans.push_back("0");
    return ans;
}

vector<vector<string>> fn(TrieNode *root, string s)
{
    vector<vector<string>> ans;
    string p;
    for (auto i : s)
    {
        p.push_back(i);
        ans.push_back(fn1(root, p));
    }
    return ans;
}

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            string key = contact[i];
            insert(root, key);
        }

        return fn(root, s);

    }
};