/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *leftnode = q.front(); q.pop();
            TreeNode *rightnode = q.front(); q.pop();
            if (!leftnode && !rightnode) continue;
            if (!leftnode && rightnode || leftnode && !rightnode || leftnode->val != rightnode->val) {
                return false;
            }
            q.push(leftnode->left);
            q.push(rightnode->right);
            q.push(leftnode->right);
            q.push(rightnode->left);
        }
        return true;
    }
};
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
