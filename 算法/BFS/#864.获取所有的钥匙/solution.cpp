class Solution {
public:
    struct node {
        int x, y, status, step;
    };
    int n, m, check[30][30][64], key_cnt = 0, end_status;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int bit2[10] = {1, 2, 4, 8, 16, 32, 64};
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size(), m = grid[0].size();
        queue<node> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    que.push((node){i, j, 0, 0});
                    check[i][j][0] = 1;
                    grid[i][j] = '.';
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    key_cnt++;
                }
            }
        }
        end_status = bit2[key_cnt] - 1;
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            if (temp.status == end_status) {
                return temp.step;
            }
            for (int i = 0; i < 4; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 0 || y < 0 || x == n || y == m || check[x][y][temp.status] == 1) {
                    continue;
                }
                if (grid[x][y] == '.') {
                    check[x][y][temp.status] = 1;
                    que.push((node){x, y, temp.status, temp.step + 1});
                } else if (grid[x][y] >= 'a' && grid[x][y] <= 'f') { 
                    check[x][y][temp.status] = 1;
                    check[x][y][temp.status | bit2[grid[x][y] - 'a']] = 1;
                    que.push((node){x, y, temp.status | bit2[grid[x][y] - 'a'], temp.step + 1}); 
                } else if (grid[x][y] >= 'A' && grid[x][y] <= 'F' && (temp.status & bit2[grid[x][y] -  'A'])) {
                    check[x][y][temp.status] = 1;
                    que.push((node){x, y, temp.status, temp.step + 1});
                }
            }
        }
        return -1;
    }
};
