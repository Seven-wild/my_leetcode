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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 1;
        while (!que.empty()) {
            int qsize = que.size();
            while (qsize--) {
                TreeNode *temp = que.front();
                que.pop();
                if (!temp->left && !temp->right) {
                    return ans;
                }
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            ans++;
        }
        return ans;
    }
};
