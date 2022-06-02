// The diameter of a tree (sometimes called the width) is the number
// of nodes on the longest path between two end nodes.
// The diagram below shows two trees each with diameter nine,
//  the leaves that form the ends of the longest path are shaded
//  (note that there is more than one path in each tree of length nine,
//   but no path longer than nine nodes).

int ans = 0;
int height(Node *root)
{
	if (root == NULL) return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	ans = max(ans, (lh + rh + 1));
	return (1 + max(lh, rh));
}

int diameter(Node* root) {
	// Your code here
	int h = height(root);
	return ans;
}