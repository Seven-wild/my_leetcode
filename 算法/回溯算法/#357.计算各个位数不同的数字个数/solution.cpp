class Solution {
public:
    int ans;
    vector<int> used;
    void backtrack(int n, int now, int cnt) {
        if (cnt <= n) {
            ans++;
        } else {
            return ;
        }
        int count = 0;
        for (int i = 0; i <= 9; i++) {
                if (now == 0 && i == 0) continue;
                if (used[i]) continue;
                int temp = now;
                now = now * 10 + i;
                used[i] = 1;
                backtrack(n, now, cnt + 1);
                now = temp;
                used[i] = 0;
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        used.resize(10);
        backtrack(n, 0, 0);
        return ans;
    }
};
