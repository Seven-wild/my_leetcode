class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int column[9][9] = {0};
        int block[3][3][9] = {0};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int now = board[i][j] - '1';
                    if (row[i][now] || column[j][now] || block[i / 3][j / 3][now]) {
                        return false;
                    } else {
                        row[i][now] = 1;
                        column[j][now] = 1;
                        block[i / 3][j / 3][now] = 1;
                    }
                }
            }
        }
        return true;
    }
};
