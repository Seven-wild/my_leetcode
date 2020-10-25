class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>(2,-1);  
        int left = 0, right = nums.size();
        vector<int> ans;
        
        while (left < right) {
            int mid = (left + right) >> 1;

            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (left == nums.size() || nums[left] != target) left = -1;
        ans.push_back(left);
        left = 0, right = nums.size();
         while (left < right) {
            int mid = (left + right) >> 1;

            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        if (left != 0 && nums[left - 1] != target) left = 0;
        ans.push_back(left - 1);
        return ans;
    }
};
