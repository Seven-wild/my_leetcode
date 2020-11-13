class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0, j = matrix.size() - 1; i < matrix.size() / 2; i++, j--) {
            swap(matrix[i], matrix[j]);
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix[0].size(); j++) {
               swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
