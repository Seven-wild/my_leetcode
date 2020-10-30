class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int newl = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[newl]) {
                nums[++newl] = nums[i];
            }
        }
        return newl + 1;
    }
};
