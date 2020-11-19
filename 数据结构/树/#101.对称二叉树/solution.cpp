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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            if (p->val == q->val) {
                return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
            } else {
                return false;
            }
        } else if (!p && !q) {
            return true;
        } else {
            return false;
        }

    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSameTree(root->left, root->right);
    }
};
