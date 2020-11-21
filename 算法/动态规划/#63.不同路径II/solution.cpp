class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*滚动数组优化
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    if (j - 1 >= 0 &&  obstacleGrid[i][j - 1] == 0) {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }
        return dp.back();
        */
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    if (!i && !j) continue;
                    if (i && j) {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    } else if (i) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
