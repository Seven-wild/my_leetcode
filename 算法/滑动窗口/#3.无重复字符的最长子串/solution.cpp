class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  = s.size();
        int ans = 0, end = -1;
        unordered_set<char> sset;
        for (int i = 0; i < n; i++) {
            //删除最左边字符 保证字串以s[i]开头
            if (i) {
                sset.erase(s[i - 1]);
            }
            //不断向右枚举end
            while (end + 1 < n && sset.count(s[end + 1]) == 0) {
                sset.insert(s[end + 1]);
                end++;
            }
            //更新答案
            ans = max(ans, end - i + 1);
        }
        return ans;
    }
};
