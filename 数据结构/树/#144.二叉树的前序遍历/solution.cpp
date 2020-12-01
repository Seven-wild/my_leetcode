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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *p = root;
        vector<int> ans;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                ans.push_back(p->val);
                p = p->left;
            }
            if (!stk.empty()) {
                p = stk.top();
                stk.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
