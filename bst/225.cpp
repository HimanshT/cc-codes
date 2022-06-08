// Kth largest element in BST

int ans = 0;
int count = 0;
void reverseInorder(Node* root, int K)
{
	if (root->right)
		reverseInorder(root->right, K);
	//main value
	count++;
	if (count == K)
	{
		ans = root->data;
		return;
	}
	if (root->left)
		reverseInorder(root->left, K);
}

int kthLargest(Node *root, int K)
{
	reverseInorder(root, K);
	return ans;
}