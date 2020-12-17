class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        int ans = nums[0];
        vector<int> maxF(nums);
        vector<int> minF(nums);
        for (int i = 1; i < nums.size(); i++) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
            ans = max(ans, max(maxF[i], minF[i]));
        }
        return ans;
        */
        int ans = nums[0], maxF = nums[0], minF = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = maxF;
            maxF = max(maxF * nums[i], max(nums[i], minF * nums[i]));
            minF = min(minF * nums[i], min(nums[i], temp * nums[i]));
            ans = max(ans, max(maxF, minF));
        }
        return ans;
    }
};
