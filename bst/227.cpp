// Brothers From Different Roots

void traverse(Node* root, unordered_map<int, int> &umap)
{
	if (root == NULL)
		return;
	traverse(root->left, umap);
	umap[root->data]++;
	traverse(root->right, umap);
}

int count = 0;

void countpair(Node* root, unordered_map<int, int>&umap, int x)
{
	if (root == NULL) return;
	countpair(root->left, umap, x);
	int diff = x - root->data;
	if (diff > 0)
	{
		if (umap[diff] == 1) count++;
	}
	countpair(root->right, umap, x);
}

int countPairs(Node* root1, Node* root2, int x)
{
	unordered_map<int, int> umap;
	traverse(root1, umap);
	countpair(root2, umap, x);
	return count;
}