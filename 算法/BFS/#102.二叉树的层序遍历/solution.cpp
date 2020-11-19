/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp.second == ans.size()) {
                ans.push_back({temp.first->val});
            } else {
                ans[temp.second].push_back(temp.first->val);
            }
            if (temp.first->left) {
                q.push(make_pair(temp.first->left, temp.second + 1));
            }
            if (temp.first->right) {
                q.push(make_pair(temp.first->right, temp.second + 1));
            }
        }
        return ans;
    }
};
