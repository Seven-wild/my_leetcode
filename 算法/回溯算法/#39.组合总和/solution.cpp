class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return ans;
    }

    void backtrack(vector<int>& candidates, int target, int begin) {
        //结束条件
        if (target == 0) {
            ans.push_back(current);
            return ;
        }
        //剪枝
        if (target < 0) return ;

        for (int i = begin; i < candidates.size(); i++) {
            current.push_back(candidates[i]);//操作
            backtrack(candidates, target - candidates[i], i);
            current.pop_back();//撤销操作
        }
    }
};
