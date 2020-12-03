class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        vector<char> stack(n - k);
        int top = -1;
        int remain = k;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && num[i] < stack[top] && remain > 0) {
                top--;
                remain--;
            }
            if (top < n - k - 1) {
                stack[++top] = num[i];
            } else {
                remain--;
            }
        }
        string ans;
        for (int i = 0; i < n - k; i++) {
            if (ans == "" && stack[i] == '0') continue;
            ans += stack[i];
        }
        if (ans == "") ans = "0";
        return ans;
    }
};
