class Solution {
public:
    int n, m, fresh;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    queue<pair<int, int>> que;
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0;
        int step = 0;
        while (!que.empty()) {
            int qsize = que.size();
            while (qsize--) {
                auto temp = que.front();
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int x = temp.first + dir[i][0];
                    int y = temp.second + dir[i][1];
                    if (x < 0 || y < 0 || x == n || y == m || grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    fresh--;
                    if (fresh == 0) return step + 1;
                    que.push({x, y});
                }
            }
            step++;
        }
        return -1;
    }
};
