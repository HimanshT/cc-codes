// Count BST nodes that lie in a given range

int count = 0;
void fn(Node* root, int low, int high)
{
	if (root == NULL)
		return;
	if (root->data > low && root->data < high) count++;
	fn(root->left, low, high);
	fn(root->right, low, high);
}

int getCount(Node *root, int l, int h)
{
	fn(root, l - 1, h + 1);
	return count;
}