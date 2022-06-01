// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.

vector<int> levelOrder(Node* node)
{
	//Your code here
	queue<Node*> q;
	vector<int> v;
	q.push(node);
	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			Node *curr = q.front();
			q.pop();
			v.push_back(curr->data);
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
	}
	return v;
}