// Delete Node in a BST

TreeNode* inorderSuccessor(TreeNode* root)
{
	root = root->right;
	while (root && root->left)
	{
		root = root->left;
	}
	return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == NULL)
		return root;
	if (key > root->val)
		root->right = deleteNode(root->right, key);
	else if (key < root->val)
		root->left = deleteNode(root->left, key);
	else
	{
		if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			delete root;
			return temp;
		}
		else if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			delete root;
			return temp;
		}
		else
		{
			TreeNode* succ = inorderSuccessor(root);
			root->val = succ->val;
			root->right = deleteNode(root->right, succ->val);
		}
		return root;
	}
	return root;
}