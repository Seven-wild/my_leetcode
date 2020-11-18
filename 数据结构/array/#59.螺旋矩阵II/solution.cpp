class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int val = 1;
        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                ans[top][i] = val++;
            }
            for (int i = top; i < bottom; i++) {
                ans[i][right] = val++;
            }
            for (int i = right; i > left; i--) {
                ans[bottom][i] = val++;
            }
            for (int i = bottom; i > top; i--) {
                ans[i][left] = val++;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        if (n % 2 == 1) {
            ans[n / 2][n / 2] = n * n; 
        }
        return ans;
    }
};
