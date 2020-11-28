class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> countAB;
        for (auto u : A) {
            for (auto v : B) {
                ++countAB[u + v];
            }
        }
        int ans = 0;
        for (auto u : C) {
            for (auto v : D) {
                if (countAB.count(-u - v)) {
                    ans += countAB[-u - v];
                }
            }
        }
        return ans;
    }
};
