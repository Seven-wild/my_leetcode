class Solution {
public:
    int n, m;
    int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
    queue<pair<int, int>> que;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        if (n == 1 && m == 1) return 1;        
        que.push({0, 0});
        grid[0][0] = 1;
        int step = 1;
        while (!que.empty()) {
            int qsize = que.size();
            while (qsize--) {
                auto temp = que.front();
                que.pop();
                for (int i = 0; i < 8; i++) {
                    int x = temp.first + dir[i][0];
                    int y = temp.second + dir[i][1];
                    if (x < 0 || y < 0 || x == n || y == m || grid[x][y] == 1) continue;
                    if (x == n - 1 && y == m - 1) return step + 1;
                    que.push({x, y});
                    grid[x][y] = 1;
                }
            }
            step++;
        }
        return -1;
    }
};
