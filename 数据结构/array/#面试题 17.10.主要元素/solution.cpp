class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        int major = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                major = nums[i];
            }
            if (nums[i] == major) {
                cnt++;
            } else {
                cnt--;
            }
        }
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == major) count++;
            if (count > nums.size()/2) return major;
        }
        return -1;
    }
};
