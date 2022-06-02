// Given a binary tree, find if it is height balanced or not.
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

bool ans = true;
int findHeight(Node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lheight = findHeight(root->left);
		int rheight = findHeight(root->right);
		if (abs(lheight - rheight) >= 2)
		{
			ans = false;
			return 0;
		}
		return (max(lheight, rheight) + 1);
	}
}

bool isBalanced(Node *root)
{
	//  Your Code here
	findHeight(root);
	return ans;
}