// Print all k-sum paths in a binary tree

void findPath(BinaryTreeNode<int> *root, vector<int> &path, int k, vector<vector<int>>&ans)
{
	if (!root)
		return;
	path.push_back(root->data);
	findPath(root->left, path, k, ans);
	findPath(root->right, path, k, ans);

	int sum = 0;
	for (int j = path.size() - 1; j >= 0; j--)
	{
		sum += path[j];
		if (sum == k)
		{
			vector<int> currPath;
			for (int i = j; i < (path.size()); i++)
				currPath.push_back(path[i]);
			ans.push_back(currPath);
		}
	}
	path.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
	// Write your code here.
	vector<vector<int>> ans;
	vector<int> path;
	findPath(root, path, k, ans);
	return ans;
}