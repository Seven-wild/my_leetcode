class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[top][i]);
            }
            for (int i = top; i < bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            for (int i = right; i > left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            for (int i = bottom; i > top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        if (left == right) {
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            } 
        } else if (top == bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
        }
        return ans;
    }
};
