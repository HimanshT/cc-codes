// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

vector<int> diagonal(Node *root)
{
	// your code here
	vector<int> ans;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node *curr = q.front(); q.pop();
		while (curr)
		{
			ans.push_back(curr->data);
			if (curr->left)
				q.push(curr->left);
			curr = curr->right;
		}
	}
	return ans;
}