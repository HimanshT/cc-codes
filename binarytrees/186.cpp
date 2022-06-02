// Given a Binary Tree,
// find Right view of it. Right view of a Binary Tree is set of nodes
//  visible when tree is viewed from right side.

vector<int> rightView(Node *root)
{
	vector<int> sol;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0; i < n; i++)
		{
			Node* curr = q.front();
			q.pop();
			if (i == (n - 1))
				sol.push_back(curr->data);
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
	}
	return sol;
}