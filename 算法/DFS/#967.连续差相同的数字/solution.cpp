class Solution {
public:
    vector<int> ans;
    void func(int now, int left, int k) {
        if (left == 0) {
            ans.push_back(now);
            return;
        }
        if (now % 10 + k < 10) {
            func(now * 10 + now % 10 + k, left - 1, k);
        }
        if (k != 0 && now % 10 - k >= 0) {
            func(now * 10 + now % 10 - k, left - 1, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            func(i, n - 1, k);
        }
        return ans;
    }
};
