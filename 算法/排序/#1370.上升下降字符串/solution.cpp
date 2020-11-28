class Solution {
public:
    string sortString(string s) {
        vector<int> nums(26);
        for (int i = 0; i < s.length(); i++) {
            nums[s[i] - 'a']++;
        }
        string ans;
        while (ans.length() < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (nums[i]) {
                    ans.push_back(i + 'a');
                    nums[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (nums[i]) {
                    ans.push_back(i + 'a');
                    nums[i]--;
                }
            }
        }
        return ans;
    }
};
