class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int new_length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[new_length++] = nums[i];
            }
        }
        return new_length;
    }
};
