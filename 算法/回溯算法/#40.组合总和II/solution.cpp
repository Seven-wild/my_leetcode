class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
    void backtrack(vector<int>& candidates, int target, int ind) {
        if (target < 0) return ;
        if (target == 0) {
            ans.push_back(current);
            return ;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1);
            current.pop_back();
        }
    }
};
