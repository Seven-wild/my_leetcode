class Solution {
public:
    int find(vector<int> &ancestor, int x) {
        return ancestor[x] < 0 ? x : ancestor[x] = find(ancestor, ancestor[x]);
    }
    void  merge(vector<int> &ancestor, int a, int b) {
        int fa = find(ancestor, a);
        int fb = find(ancestor, b);
        if (ancestor[fa] < ancestor[fb]) {
            ancestor[fa] += ancestor[fb];
            ancestor[fb] = fa;
        } else {
            ancestor[fb] += ancestor[fa];
            ancestor[fa] = fb;
        }        
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        auto ancestor = vector<int>(n + 1, -1);
        auto parent = vector<int>(n + 1, -1);
        int conflict = -1;
        int cycle = -1;
        for (int i = 0; i < n; i++) {
            int node1 = edges[i][0], node2 = edges[i][1];
            if (parent[node2] != -1) {
                conflict = i;
            } else {
                parent[node2] = node1;
                if (find(ancestor, node1) == find(ancestor, node2)) {
                    cycle = i;
                } else {
                    merge(ancestor, node1, node2);
                }
            }
        }
        if (conflict < 0) {
            auto redundant = vector<int> {edges[cycle][0], edges[cycle][1]};
            return redundant;
        } else {
            auto conflictEdge = edges[conflict];
            if (cycle >= 0) {
                auto redundant = vector<int> {parent[conflictEdge[1]], conflictEdge[1]};
                return redundant;
            } else {
                auto redundant = vector<int> {conflictEdge[0], conflictEdge[1]};
                return redundant;
            }
        }
    }
};
