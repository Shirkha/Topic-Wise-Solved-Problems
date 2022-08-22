Populating Next Right Pointers in Each Node


class Solution {
public:
	// DFS    TC = O(n)    SC = O(h) = O(logn)

	void dfs(Node* root) {
		if (!root->left and !root->right)
			return;
		root->left->next = root->right;

		if (root->next)
			root->right->next = root->next->left;

		dfs(root->left);
		dfs(root->right);
	}

	Node* connect(Node* root) {
		if (!root or !root->left and !root->right)
			return root;

		// BFS
		// TC = O(n)   SC = O(n)
		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			int n = q.size();
			Node* rightNode = NULL;

			for (int i = 0; i < n; i++) {
				Node* node = q.front();
				q.pop();
				node->next = rightNode;
				rightNode = node;

				if (node->right)
					q.push(node->right);
				if (node->left)
					q.push(node->left);
			}
		}

		// BFS with SC = O(1)   using the next pointer to traverse in the level

		Node* node = root;
		while (node->left and node->right) {
			Node* curr = node;
			while (curr) {
				curr->left->next = curr->right;
				if (curr->next)
					curr->right->next = curr->next->left;
				curr = curr->next;
			}
			node = node->left;
		}


		// DFS
		// dfs(root);

		return root;
	}
};