// Clone Graph

void dfs(Node *curr, Node* node, vector<Node*>&visited)
{
	visited[node->val] = node;
	for (auto u : curr->neighbors)
	{
		if (visited[u->val] == NULL)
		{
			Node* newNode = new Node(u->val);
			(node->neighbors).push_back(newNode);
			dfs(u, newNode, visited);
		}
		else
			(node->neighbors).push_back(visited[u->val]);
	}
}
Node* cloneGraph(Node* node) {
	if (node == NULL)
		return NULL;
	vector<Node*> visited(1000, NULL);
	Node* copy = new Node(node->val);
	visited[node->val] = copy;
	for (auto curr : node->neighbors)
	{
		if (visited[curr->val] == NULL)
		{
			Node* newNode = new Node(curr->val);
			(copy->neighbors).push_back(newNode);
			dfs(curr, newNode, visited);
		}
		else
			(copy->neighbors).push_back(visited[curr->val]);
	}
	return visited[1];
}