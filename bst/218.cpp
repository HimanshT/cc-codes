// Check for BST

bool fn(Node* root, int low, int high)
{
	if (root == NULL)
		return true;
	else if (root->data > low && root->data < high)
		return (fn(root->left, low, root->data) && fn(root->right, root->data, high));
	else
		return false;
}

bool isBST(Node* root)
{
	int low = INT_MIN;
	int high = INT_MAX;
	return fn(root, low, high);
}