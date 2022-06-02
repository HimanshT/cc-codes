// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

vector <int> zigZagTraversal(Node* root)
{
	// Code here
	stack<Node*> currLevel;
	stack<Node*> nextLevel;
	vector<int> ans;
	bool leftToRight = true;
	currLevel.push(root);
	while (!currLevel.empty())
	{
		Node* curr = currLevel.top(); currLevel.pop();
		if (curr)
		{
			ans.push_back(curr->data);
			if (leftToRight)
			{
				if (curr->left) nextLevel.push(curr->left);
				if (curr->right) nextLevel.push(curr->right);
			}
			else
			{
				if (curr->right) nextLevel.push(curr->right);
				if (curr->left) nextLevel.push(curr->left);
			}
		}

		if (currLevel.empty())
		{
			swap(currLevel, nextLevel);
			leftToRight = !leftToRight;
		}

	}
	return ans;
}