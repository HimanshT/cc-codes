// Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

vector<int> reverseLevelOrder(Node *root)
{
	// code here
	stack<Node*> st;
	queue<Node*> q;
	vector<int> sol;
	q.push(root);
	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			Node* curr = q.front();
			q.pop();
			if (curr->right != NULL)
				q.push(curr->right);
			if (curr->left != NULL)
				q.push(curr->left);
			st.push(curr);
		}
	}

	while (!st.empty())
	{
		Node* curr = st.top();
		st.pop();
		sol.push_back(curr->data);
	}
	return sol;
}