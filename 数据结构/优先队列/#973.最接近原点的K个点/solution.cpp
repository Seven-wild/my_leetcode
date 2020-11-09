class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int> > q;
        for (int i = 0; i < K; i++) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        for (int i = K; i < points.size(); i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dis < q.top().first) {
                q.pop();
                q.emplace(dis, i);
            }
        }
        vector<vector<int> > ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};
