class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // 从后往前找第一个 [i, i + 1] 满足 nums[i] < nums[i + 1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        // 如果存在 nums[i] < nums[i + 1] 
        // 其中 nums[i + 1, n） 必然是降序排列 
        if (i >= 0) {
            // 从nums[i + 1, n)中往后寻找第一额 nums[j] > nums[i] 
            int j = nums.size() - 1;
            while (j > i && nums[i] >= nums[j]) {
                j--;
            }
            // 交换nums[i] 和 nums[j]
            swap(nums[i], nums[j]);
        }
        // 因为 nums[i + 1, n)是降序 翻转可使其最小
        // 如果 i == -1 说明原排列是最大排列 翻转可使其最小
        reverse(nums.begin() + i + 1, nums.end());
    }
};
