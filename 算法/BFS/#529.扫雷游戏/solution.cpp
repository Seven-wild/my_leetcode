class Solution {
public:
    struct node {
        int x, y;
    };
    int n, m;
    int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
    int mines(int x, int y, vector<vector<char>> &board) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx == n || yy == m) {
                continue;
            }
            cnt += (board[xx][yy] == 'M');
        }
        return cnt;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        n = board.size(), m = board[0].size();
        queue<node> que;
        if (mines(click[0], click[1], board)) {
            board[click[0]][click[1]] = mines(click[0], click[1], board) + '0';
            return board;
        } else {
            board[click[0]][click[1]] = 'B';
            que.push((node){click[0], click[1]});

        }
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            for (int i = 0; i < 8; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 0 || y < 0 || x == n || y == m || board[x][y] != 'E') {
                    continue;
                }
                int cnt_mine = mines(x, y, board);
                if (cnt_mine) {
                    board[x][y] = cnt_mine + '0';
                } else {
                    board[x][y] = 'B';
                    que.push((node){x, y});
                }
            }
        }
        return board;
    }
};
