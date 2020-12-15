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
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                v.push_back(p);
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        for (int i = 1; i < v.size(); i++) {
            auto pre = v[i - 1], cur = v[i];
            pre->left = nullptr;
            pre->right = cur;
        }
        return ;
    }
};
