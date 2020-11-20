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
    int find_root(vector<int>& inorder, int root) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size(), n = inorder.size();
        if (m == 0 || n == 0) return NULL;
        TreeNode *node = new TreeNode(preorder[0]);
        int pos = find_root(inorder, preorder[0]);
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + pos + 1);
        vector<int> right_pre(preorder.begin() + pos + 1, preorder.end());
        vector<int> left_in(inorder.begin(), inorder.begin() + pos);
        vector<int> right_in(inorder.begin() + pos + 1, inorder.end());
        node->left = buildTree(left_pre, left_in);
        node->right = buildTree(right_pre, right_in);
        return node;
    }
};
