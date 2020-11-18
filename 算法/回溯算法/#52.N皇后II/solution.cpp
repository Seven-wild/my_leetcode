class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> column, dia1, dia2;
        return backtrack(n, 0, column, dia1, dia2);
    }
    int backtrack(int n, int row, unordered_set<int> column, unordered_set<int>dia1, unordered_set<int> dia2) {
        if (row == n) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (column.find(i) != column.end()) continue;
            int _dia1 = row - i;
            if (dia1.find(_dia1) != dia1.end()) continue;
            int _dia2 = row + i;
            if (dia2.find(_dia2) != dia2.end()) continue;
            
            column.insert(i);
            dia1.insert(_dia1);
            dia2.insert(_dia2);
            count += backtrack(n, row + 1, column, dia1, dia2);
            column.erase(i);
            dia1.erase(_dia1);
            dia2.erase(_dia2);
        }
        return count;
        
    }
};
