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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root) return ans;
        stack<TreeNode *> stk;
        queue<TreeNode *> que;
        stk.push(root);
        int flag = 0;
        while (!stk.empty()) {
            int n = stk.size();
            vector<int> current;
            for (int i = 0; i < n; i++) {
                TreeNode *temp = stk.top();
                current.push_back(temp->val);
                stk.pop();
                que.push(temp);
            }
            while (!que.empty()) {
                TreeNode *temp = que.front();
                que.pop();
                if (!flag) {
                    if (temp->left) stk.push(temp->left);
                    if (temp->right) stk.push(temp->right);
                } else {
                    if (temp->right) stk.push(temp->right);
                    if (temp->left) stk.push(temp->left);
                }
            }

            ans.push_back(current);
            flag = !flag;
        }
        return ans;
    }
};
