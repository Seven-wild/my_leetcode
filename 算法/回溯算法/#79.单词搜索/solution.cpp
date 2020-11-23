class Solution {
public:
    bool flag;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int n, m;
    void dfs(vector<vector<char>> &board, int x, int y, const string &word, int now) {
        if (now == word.length()) {
            flag = true;
            return ;
        }
        if (flag) return ;
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx == n || yy == m || board[xx][yy] == '#') continue;
            if (board[xx][yy] == word[now]) {
                board[xx][yy] = '#';
                dfs(board, xx, yy, word, now + 1);
                board[xx][yy] = word[now];
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        flag = false;
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    dfs(board, i, j, word, 1);
                    board[i][j] = word[0];
                }
                if (flag) {
                    break;
                }
            }
        }
        return flag;
    }
};
