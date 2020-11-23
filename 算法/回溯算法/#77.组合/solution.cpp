class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void dfs(int n, int now, int k) {
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }
        if (current.size() + (n - now + 1) < k) {
            return;
        }
        for (int i = now; i <=n ;i++) {
            current.push_back(i);
            dfs(n, i + 1, k);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, 1, k);
        return ans;
    }
};
