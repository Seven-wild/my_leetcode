class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2) return false;
        vector<int> need(26), has(26);
        for (int i = 0; i < len1; i++) {
            need[s1[i] - 'a']++;
            has[s2[i] - 'a']++;
        }
        for (int i = 0; i + len1 - 1 < len2; i++) {
            if (need == has) return true;
            if (i < len2 - len1) {
                has[s2[i]-'a']--;
                has[s2[i + len1] - 'a']++;
            }
        }
        return false;
    }
};
