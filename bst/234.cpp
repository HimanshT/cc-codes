// Largest BST

class info {
public:
	int maxi;
	int mini;
	bool isBst;
	int size;
};

info solve(Node* root, int &maxSize)
{
	if (root == NULL)
	{
		// info f1;
		// f1.maxi=0,f1.mini=0,isBst=true;size=0;
		// return f1;//It can be returned like this also
		return {INT_MIN, INT_MAX, true, 0};
	}
	info left = solve(root->left, maxSize);
	info right = solve(root->right, maxSize);
	info currNode;
	currNode.size = left.size + right.size + 1;
	currNode.maxi = max(root->data, right.maxi);
	currNode.mini = min(root->data, left.mini);
	if (left.isBst && right.isBst && (left.maxi < root->data && right.mini > root->data))
	{
		currNode.isBst = true;
	}
	else
	{
		currNode.isBst = false;
	}

	if (currNode.isBst) {
		maxSize = max(maxSize, currNode.size);
	}
	return currNode;
}

class Solution {
public:

	int largestBst(Node *root)
	{
		int maxSize = 0;
		info temp = solve(root, maxSize);
		return maxSize;
	}
};