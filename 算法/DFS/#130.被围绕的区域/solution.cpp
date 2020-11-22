class Solution {
public:
    int n, m;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(vector<vector<char>> &board, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx == n || yy == m) continue;
            if (board[xx][yy] == 'O') {
                board[xx][yy] = '#';
                dfs(board, xx, yy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return ;
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && i < n - 1 && j > 0 && j < m - 1) continue;
                if (board[i][j] == 'O') {
                    board[i][j] = '#';
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
        return ;
    }
};
