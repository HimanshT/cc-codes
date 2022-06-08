// Construct Binary Tree from String with bracket representation

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int findIndex(string str, int low, int high)
{
	stack<char> st;
	int index = -1;
	for (int i = low; i <= high; i++)
	{
		if (str[i] == '(')
			st.push('(');
		else if (str[i] == ')')
		{
			st.pop();
			if (st.empty())
			{
				index = i; break;
			}
		}
	}
	return index;
}

Node *findTree(string str, int low, int high)
{
	if (low > high)
		return NULL;
	Node* root = new Node(str[low] - '0');

	int index = -1;

	if (str[low + 1] == '(' && (low + 1) <= high)
		index = findIndex(str, low + 1, high);

	if (index != -1)
	{
		root->left = findTree(str, low + 2, index - 1);
		root->right = findTree(str, index + 2, high - 1);
	}

	return root;
}

int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* head = findTree(str, 0, str.length() - 1);
	preOrder(head);
	return 0;
}