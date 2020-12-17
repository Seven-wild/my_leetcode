class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (auto i : s) {
            int num = i - 'A' + 1;
            ans = ans * 26 + num;
        }
        return ans;
    }
};
