// Given a Binary Tree, print Left view of it.
//  Left view of a Binary Tree is set of nodes visible when
//  tree is visited from Left side. The task is to complete the function leftView(),
//  which accepts root of the tree as argument.

vector<int> leftView(Node *root)
{
	// Your code here
	queue<Node*> q;
	vector<int> sol;
	if (root == NULL)
		return sol;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0; i < n; i++)
		{
			Node* curr = q.front();
			q.pop();
			if (i == 0)
				sol.push_back(curr->data);
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
		}
	}
	return sol;
}