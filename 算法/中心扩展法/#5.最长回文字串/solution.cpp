class Solution {
public:
    pair<int, int> expand(const string &s, int left, int right) {
        int n = s.size();
        //不断向两边扩展
        while (left >= 0 && right < n &&  s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            //以s[i]为中心
            auto [left1, right1] = expand(s, i, i);
            //以s[i]和s[i+1]为中心
            auto [left2, right2] = expand(s, i, i + 1);
            //更新答案
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        string ans = s.substr(start, end - start + 1);
        return ans;
    }
};
