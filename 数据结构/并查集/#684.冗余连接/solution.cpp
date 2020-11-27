class Solution {
public:
    int find(vector<int> &tree, int x) {
        return tree[x] < 0 ? x : tree[x] = find(tree, tree[x]);
    }

    void merge(vector<int> &tree, int a, int b) {
        int fa = find(tree, a);
        int fb = find(tree, b);
        if (tree[fa] < tree[fb]) {
            tree[fa] += tree[fb];
            tree[fb] = fa;
        } else {
            tree[fb] += tree[fa];
            tree[fa] = fb;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> tree(n + 1, -1);
        for (int i = 0; i < n; i++) {
            int fa = find(tree, edges[i][0]);
            int fb = find(tree, edges[i][1]);
            if (fa == fb) return {edges[i][0], edges[i][1]};
            else merge(tree, edges[i][0], edges[i][1]);
        }
        return {};
    }
};
