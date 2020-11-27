class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sset;
        for (auto &i : nums) {
            sset.insert(i);
        }
        int ans = 0;
        for (auto &i : sset) {
            if (!sset.count(i - 1)) {
                int current_num = i;
                int current_len = 1;
                while (sset.count(current_num + 1)) {
                    current_num++;
                    current_len++;
                }
                ans = max(ans, current_len);
            }
        }
        return ans;

    }
};
