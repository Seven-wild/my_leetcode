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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto ans = vector<vector<int>>();
        if (!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int qsize = que.size();
            auto current = vector<int>();
            while (qsize--) {
                TreeNode *temp = que.front();
                que.pop();
                current.push_back(temp->val);
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            ans.push_back(current);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
