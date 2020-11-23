class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void dfs(vector<int> &nums, int now) {
        if (current.size() <= nums.size()) {
            ans.push_back(current);
            if (current.size() == nums.size())
                return ;
        }
        for (int i = now; i < nums.size(); i++) {
            current.push_back(nums[i]);
            dfs(nums, i + 1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};
