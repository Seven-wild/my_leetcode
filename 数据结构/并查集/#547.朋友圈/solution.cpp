class Solution {
public:
    int find(vector<int> &fri, int x) {
        return fri[x] < 0 ? x : fri[x] = find(fri, fri[x]);
    }
    void merge(vector<int> &fri, int a, int b) {
        int fa = find(fri, a), fb = find(fri, b);
        if (fa != fb) {
            if (fri[fa] < fri[fb]) {
                fri[fb] += fri[fa];
                fri[fa] = fb; 
            } else {
                fri[fa] += fri[fb];
                fri[fb] = fa;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if (N == 0) return 0;
        vector<int> fri(N, -1);
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (M[i][j]) {
                    merge(fri, i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (fri[i] < 0) ans++;
        }
        return ans;
    }
};
