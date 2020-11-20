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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
        int pos = find_root(inorder, postorder[postorder.size() - 1]);
        vector<int> left_in(inorder.begin(), inorder.begin() + pos);
        vector<int> right_in(inorder.begin() + pos + 1, inorder.end());
        vector<int> left_post(postorder.begin(), postorder.begin() + pos);
        vector<int> right_post(postorder.begin() + pos, postorder.end() - 1);
        root->left = buildTree(left_in, left_post);
        root->right = buildTree(right_in, right_post);
        return root;
    }
};
