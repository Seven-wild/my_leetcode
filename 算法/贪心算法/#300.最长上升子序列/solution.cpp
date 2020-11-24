class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /***********朴素DP*************
        if (nums.size() == 0) return 0;
        int ans = 1;
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        *******************************/
        // 贪心 + 二分
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans[ans.size() - 1]) {
                ans.push_back(nums[i]);
            } else {
                int l = 0, r = ans.size() - 1, mid;
                while (l < r) {
                    mid = (l + r) >> 1;
                    if (ans[mid] >= nums[i]) r = mid;
                    else l = mid + 1;
                }
                ans[l] = nums[i];

            }
        }
        return ans.size();
    }
};
