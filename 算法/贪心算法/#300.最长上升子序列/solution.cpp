class Solution {
public:
    vector<vector<int>> weights;
    void init_weights(vector<string> &strs) {
        for (int i = 0; i < strs.size(); i++) {
            int one = 0, zero = 0;
            for (int j = 0; j < strs[i].length(); j++) {
                if (strs[i][j] == '0') zero++;
                else one++;
            }
            weights.push_back({zero, one});
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        init_weights(strs);
        /***************滚动数组优化**************
        for (int i = 1; i <= strs.size(); i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= weights[i - 1][0] && k >= weights[i - 1][1]) {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - weights[i - 1][0]][k - weights[i - 1][1]] + 1);
                    }
                }
            }
        }
        return dp[strs.size()][m][n];        
        ***********************************/
        vector<vector<int>> dp(m + 1, vector<int>(n +  1));
        for (int i = 0; i < strs.size(); i++) {
            for (int j = m; j >= weights[i][0]; j--) {
                for (int k = n; k >= weights[i][1]; k--) {
                    dp[j][k] = max(1 + dp[j - weights[i][0]][k - weights[i][1]], dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};
