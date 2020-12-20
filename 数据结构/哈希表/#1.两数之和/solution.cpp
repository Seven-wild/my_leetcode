class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mmap;
        vector<int> ans(2);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            //先搜索再保存 保证nums[i]不和自己匹配
            if (mmap.count(target - nums[i])) {
                ans[0] = mmap[target - nums[i]];
                ans[1] = i;
                break;
            }
            mmap[nums[i]] = i;
        }
        return ans;
    }
};
