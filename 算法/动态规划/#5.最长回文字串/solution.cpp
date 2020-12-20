class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        //定义状态 dp[i][j] == 0 表示s[i..j]不是回文字串
        vector<vector<int>> dp(n, vector<int>(n));
        //l为当前判断的子串长度
        for (int l = 0; l < n; l++) {
            //i为当前子串起始位置
            for (int i = 0; i + l < n; i++) {
                //j为当前子串结束位置
                int j = i + l;
                //状态转移
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                //更新答案
                if (dp[i][j] && j - i + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
