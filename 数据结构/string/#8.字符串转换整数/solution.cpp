class Solution {
public:
    bool invalid(char ch) {
        if (ch == '+' || ch == '-' || (ch >= '0' && ch <= '9'))  return false;
        return true;
    }
    int myAtoi(string s) {
        int len = s.length();
        int start;
        for (start = 0; start < len; start++) {
            if (s[start] != ' ') break;
        }
        if (start == len || invalid(s[start])) return 0;
        int minus = s[start] == '-' ? 1 : 0;
        start += (s[start] == '-' || s[start] == '+') ? 1 : 0;
        int t = 0, ans = 0;
        for (int i = start; i < len; i++) {
            if (s[i] == '.') break;
            else if (s[i] < '0' || s[i] > '9') break;
            if (minus == 0) {
                if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && (s[i] - '0') > 7)
                    return INT_MAX;
            } else {
                if (ans < INT_MIN / 10 || ans == INT_MIN / 10 && (s[i] - '0') > 8)
                    return INT_MIN;
            }
            ans *= 10;
            minus ? ans -= (s[i] - '0') : ans += (s[i] - '0');
        }
        return ans;
    }
};
