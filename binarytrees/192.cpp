// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.



void left(Node* root, vector<Node*>&uset)
{
	if (root == NULL || (root->right == NULL & root->left == NULL))
		return;
	uset.push_back(root);
	if (root->left)
		left(root->left, uset);
	else
		left(root->right, uset);

}
void bottom(Node* root, vector<Node*>&uset)
{
	if (root == NULL)
		return ;
	if (root->right == NULL && root->left == NULL)
	{
		uset.push_back(root);
		return;
	}
	bottom(root->left, uset); bottom(root->right, uset);
}

void right(Node* root, vector<Node*>&uset)
{
	if (root == NULL || (root->right == NULL & root->left == NULL))
		return;
	if (root->right)
		right(root->right, uset);
	else
		right(root->left, uset);
	uset.push_back(root);
}

vector <int> boundary(Node *root)
{
	//Your code here
	vector<Node*> uset;
	//complete left side;
	uset.push_back(root);
	left(root->left, uset);
	if (root->right != NULL || root->left != NULL)
		bottom(root, uset);
	right(root->right, uset);
	//copying data
	vector<int> ans;
	for (auto it : uset)
	{
		ans.push_back(it->data);
	}
	return ans;
}