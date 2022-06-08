// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

Node* lca(Node* root , int n1 , int n2 )
{
	if (root->data == n1 || root->data == n2)
		return root;
	if (root->right == NULL && root->left == NULL)
		return NULL;
	Node* left = NULL; Node* right = NULL;
	if (root->left)
		left = lca(root->left, n1, n2);
	if (root->right)
		right = lca(root->right, n1, n2);
	if (left && right)
		return root;
	return left == NULL ? right : left;
}