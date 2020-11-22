class Solution {
public:
    struct node {
        int x, y, step;
    };
    int n, m;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    queue<node> que;
    void func(int x, int y, vector<vector<int>> &mmap) {
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx == n || yy == m ) {
                continue;
            }
            if (mmap[xx][yy] == 1) {
                mmap[xx][yy] = 2;
                que.push((node){xx, yy, 0});
                func(xx, yy, mmap);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        n = A.size(), m = A[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    A[i][j] = 2;
                    que.push((node){i, j, 0});
                    func(i, j, A);
                    break;
                }
            }
            if (!que.empty()) {
                break;
            }            
        }
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 0 || y < 0 || x == n || y == m) {
                    continue;
                }
                if (A[x][y] == 1) {
                    return temp.step;
                }
                if (A[x][y] == 0) {
                    A[x][y] = 2;
                    que.push((node){x, y, temp.step + 1});
                }
            }
        }
        return -1;
    }
};
