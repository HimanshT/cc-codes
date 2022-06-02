// Given a Binary Tree, check if all leaves are at same level or not.

bool checkUtil(struct Node *root,
               int level, int *leafLevel)
{
	// Base case
	if (root == NULL) return true;

	// If a leaf node is encountered
	if (root->left == NULL &&
	        root->right == NULL)
	{
		// When a leaf node is found
		// first time
		if (*leafLevel == 0)
		{
			*leafLevel = level; // Set first found leaf's level
			return true;
		}

		// If this is not first leaf node, compare
		// its level with first leaf's level
		return (level == *leafLevel);
	}

	// If this node is not leaf, recursively
	// check left and right subtrees
	return checkUtil(root->left, level + 1, leafLevel) &&
	       checkUtil(root->right, level + 1, leafLevel);
}
bool check(Node *root)
{
	int level = 0, leafLevel = 0;
	return checkUtil(root, level, &leafLevel);
}