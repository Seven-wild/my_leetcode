class Solution {
public:
    string smallestSubsequence(string s) {
        vector<char> remain(26, -1);
        for (auto ch : s) {
            remain[ch - 'a']++;
        }
        int n = 0;
        for (auto cnt : remain) {
            if (cnt != -1) {
                n++;
            }
        }
        vector<char> stack(n);
        vector<int> flag(26, 0);
        int top = -1;
        for (auto ch : s) {
            if (flag[ch - 'a']) {
                remain[ch - 'a']--;
                continue;
            }
            while (top >= 0 && ch < stack[top] && remain[stack[top] - 'a'] > 0) {
                flag[stack[top] - 'a'] = 0;
                remain[stack[top] - 'a']--;
                top--;
            }
            stack[++top] = ch;
            flag[ch - 'a'] = 1;
        }
        string ans;
        for (auto ch : stack) {
            ans += ch;
        }
        return ans;
    }
};
