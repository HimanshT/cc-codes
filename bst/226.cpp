// Given a BST and an integer K. Find the Kth Smallest element in the BST.

int ans = -1;
int count = 0;
void inorder(Node* root, int K)
{
	if (root->left)
		inorder(root->left, K);
	//main value
	count++;
	if (count == K)
	{
		ans = root->data;
		return;
	}
	if (root->right)
		inorder(root->right, K);
}
int KthSmallestElement(Node *root, int K) {
	inorder(root, K);
	return ans;
}