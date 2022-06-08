// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

int ans = 1;
int findSum(Node* root)
{
	if (root == NULL)
		return 0;
	else if (root->right == NULL && root->left == NULL)
		return root->data;
	else
	{
		int lsum = findSum(root->left);
		int rsum = findSum(root->right);
		if (lsum + rsum == root->data)
		{
			root->data = lsum + rsum + root->data;
			return root->data;
		}
		else
		{
			ans = 0;
			return 0;
		}
	}
}

bool isSumTree(Node* root)
{
	findSum(root);
	return ans;
}