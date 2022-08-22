Binary Tree Zigzag traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> q;
		bool leftToRight = true;
		q.push(root);
		while (!q.empty()) {
			//For 2 level at a time count = 2 and iterte while loop count-- > 0 and !q.empty()
			int n = q.size();
			vector<int> level(n);
			for (int i = 0; i < n; i++) {
				TreeNode* node = q.front();
				q.pop();

				int index = (leftToRight ? i : n - 1 - i);
				level[index] = node->val;

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			res.push_back(level);
			leftToRight = !leftToRight;
		}
		return res;
	}



	// 2 level at a time

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*>q;
		q.push(root);
		bool leftToRight = true;

		while (!q.empty()) {
			int count = 2;
			while (count-- > 0 and !q.empty()) {
				int n = q.size();
				vector<int> currLevel(n);
				for (int i = 0; i < n; i++) {
					TreeNode* node = q.front();
					q.pop();

					if (leftToRight)
						currLevel[i] = node->val;
					else
						currLevel[n - 1 - i] = node->val;

					if (node->left)
						q.push(node->left);
					if (node->right)
						q.push(node->right);
				}
				res.push_back(currLevel);
			}
			leftToRight = !leftToRight;
		}
		return res;
	};