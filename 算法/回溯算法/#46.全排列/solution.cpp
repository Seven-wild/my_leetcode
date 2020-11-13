class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return ans;
    }
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
                if (used[i] == true) continue;
                used[i] = true;
                current.push_back(nums[i]);
                backtrack(nums, used);
                used[i] = false;
                current.pop_back();
        }
    }
};
