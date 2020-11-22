class Solution {
public:
    int n, m;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

    void dfs(vector<vector<char>> &grid, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx == n || yy == m) continue;
            if (grid[xx][yy] == '1') {
                grid[xx][yy] = '0';
                dfs(grid, xx, yy);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
