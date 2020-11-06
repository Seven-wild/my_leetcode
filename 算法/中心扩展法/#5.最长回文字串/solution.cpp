class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        int begin;
        int maxlen = 1;
        for (int i = 0; i < n - 1; i++) {
            int len1 = juage(s, i, i);
            int len2 = juage(s, i, i + 1);
            int cur_max = max(len1, len2);
            if (cur_max > maxlen) {
                begin = i - (cur_max - 1) / 2;
                maxlen = cur_max;
            }
        }
        return s.substr(begin, maxlen  );
    }
    int juage(const string &s, int left, int right) {
        while (left >=0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; 
    }
};
