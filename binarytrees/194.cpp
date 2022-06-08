// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Node *head = NULL;
Node *prev = NULL;
void findDll(Node *root)
{
	if (root == NULL)
		return ;
	findDll(root->left);
	//root

	if (prev == NULL) head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	findDll(root->right);
}

Node * bToDLL(Node *root)
{
	findDll(root);
	return head;
}