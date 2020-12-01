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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *pcur = root, *plast = nullptr;
        vector<int> ans;
        while (pcur) {
            stk.push(pcur);
            pcur = pcur->left;
        }
        while (!stk.empty()) {
            pcur = stk.top();
            stk.pop();
            if (!pcur->right || pcur->right == plast) {
                ans.push_back(pcur->val);
                plast = pcur;
            } else {
                stk.push(pcur);
                pcur = pcur->right;
                while (pcur) {
                    stk.push(pcur);
                    pcur = pcur->left;
                }
            }
        }
        return ans;
    }
};
