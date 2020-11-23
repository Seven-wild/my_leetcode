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
    bool exsit(TreeNode *root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode *node = root;
        while (node && bits) {
            if (bits & k) node = node->right;
            else node = node->left;
            bits >>= 1;
        } 
        return node != NULL;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int level = 0;
        TreeNode *node = root;
        while (node->left) {
            node = node->left;
            level++;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            if (exsit(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
