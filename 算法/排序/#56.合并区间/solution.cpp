class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0], right = intervals[i][1];
            if (ans.empty() || ans.back()[1] < left) {
                ans.push_back({left, right});
            } else {
                ans.back()[1] = max(ans.back()[1], right);
            }
        }
        return ans;
    }
};
