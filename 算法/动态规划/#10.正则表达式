class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int> > match(m + 1, vector<int>(n + 1, 0)); //match[i][j] 表示 
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (j == 0) {
                    if (i == 0) { // 都为空串 匹配
                        match[i][j] = 1;
                    } 
                } else {
                    if (p[j - 1] != '*') {
                        if (i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                            match[i][j] = match[i - 1][j - 1];
                        }
                    } else {
                        //重复0次
                        if (j >= 2) { 
                            match[i][j] |= match[i][j - 2];
                        }
                        //重复n次
                        if (j >= 2 && i >= 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                            match[i][j] |= match[i - 1][j];
                        } 
                    }
                }
            }
        }
        return match[m][n];
    }
};
