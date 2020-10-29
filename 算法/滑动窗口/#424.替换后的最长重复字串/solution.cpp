class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0, right = 0;
        int maxCount = 0;
        int ans = 0;
        while (right < s.size()) {
            char temp = s[right];
            count[temp - 'A'] ++;
            maxCount = max(maxCount, count[temp - 'A']);
            if (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
