class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int new_length = 1;
        int pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (pre != nums[i]) {
                pre = nums[i];
                nums[new_length++] = nums[i];
            } 
        }
        return new_length;
    }
};
