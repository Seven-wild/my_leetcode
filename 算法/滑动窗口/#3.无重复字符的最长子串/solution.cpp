class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> occ;
        int ans = 0;
        int left = 0, right = 0;
        int length = 0;
        while (right < s.length()) {
            char temp = s[right];
            if (occ.find(temp) != occ.end() && occ[temp] >= left) {
                left = occ[temp] + 1;
                length = right - left;
            }
            occ[temp] = right;
            length++;
            right++;
            ans = max(ans, length);
        }
        return ans;
    }
};
