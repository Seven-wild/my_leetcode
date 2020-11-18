class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        unordered_set<int> dia1, dia2, column;
        vector<int> queen(n, -1);
        backtrack(ans, n, 0, queen, dia1, dia2, column); 
        return ans;
    }
    void backtrack(vector<vector<string>> &ans, int n, int row, vector<int> &queen, unordered_set<int> &dia1, unordered_set<int> &dia2, unordered_set<int> &column) {
        if (row == n) {
           ans.push_back(func(queen, n));
           return; 
        }
        for (int i = 0; i < n; i++) {
            if (column.find(i) != column.end()) continue;
            int _dia1 = row - i;
            if (dia1.find(_dia1) != dia1.end()) continue;
            int _dia2 = row + i;
            if (dia2.find(_dia2) != dia2.end()) continue;
            queen[row] = i;
            column.insert(i);
            dia1.insert(_dia1);
            dia2.insert(_dia2);
            backtrack(ans, n, row + 1, queen, dia1, dia2, column);
            queen[row] = -1;
            column.erase(i);
            dia1.erase(_dia1);
            dia2.erase(_dia2);
        }
    }
    vector<string> func(vector<int> &queen, int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queen[i]] = 'Q';
            temp.push_back(row);
        }
        return temp;
    }
};
