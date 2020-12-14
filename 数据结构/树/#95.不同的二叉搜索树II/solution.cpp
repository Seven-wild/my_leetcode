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
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_tree = generateTrees(start, i - 1);
            vector<TreeNode*> right_tree = generateTrees(i + 1, end);
            for (auto &left : left_tree) {
                for (auto &right : right_tree) {
                    TreeNode *cur_tree = new TreeNode(i);
                    cur_tree->left = left;
                    cur_tree->right = right;
                    ans.push_back(cur_tree);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }
};
